Zadání

Implementace jednoduchého šachového algoritmu, který umožňuje hru hráče proti počítači. Vstup a výstup bude probíhat na příkazové řádce.

Analýza úlohy

Nejprve je potřeba navrhnout základní datové struktury a rutiny, které musí obsahovat každý šachový program i takový, který neobsahuje žádný myslící algoritmus a umožňuje napřiklad jen hru dvou lidských hráčů po síti. Patří sem funkce pro
 - Nalezení všech legálních tahů z dané pozice
 - Kontrola šachu a matu
 - Funkce kontrolující dodržení pravidel při rošádě a braní mimochodem
 - Funkce, která zahraje samotný tah

Bude následovat umělá inteligence a chybět nesmí ani několik málo funkcí pro komunikaci s okolím, jako je zparsování tahu zadaného z klávesnice, vypsání tahu, upozornění na přemýšlení programu a podobně.

Umělá inteligence a teorie šachové hry

Šachy jsou čistě matematickou úlohou, k jejímuž vyřešení se dá v každém případě dopočítat. Za vyřešení úlohy můžeme považovat mat v případě vyhrané pozice, pat v případě remízové pozice nebo alespoň co největší oddalování porážky v případě prohrané pozice. Klíčovou funkcí je statická ohodnocovací funkce, která vrátí číselnou hodnotudané pozice. Nejednodušší algoritmus, který nehraje úplně náhodně, vygeneruje všechny tahy ze zadané pozice, každý z nich zahraje a vzniklou pozici ohodnotí statickou ohodnocovací funkcí. Pokud je hodnota pozice vyšší než dosud nejvyšší, uloží ji i tah, kterým jsme se na ni dostali. Poté zahraje tah zpět a tak dále, dokud nevyzkoušíme všechny tahy. Tento algoritmus je sice lepší než náhodné generování tahů, ale díru do světa rozhodně neudělá. Sebere klidně dámou krytého pěšce, nepokryje jednotahový mat a podobně.
Vylepšením je přidat rekurzi. Zahrajeme všechny tahy z dané pozice, na tyto tahy zahrajeme odpověď soupeře, pak zase naší odpověď a tak dále až do nějaké hloubky n, kde zavoláme statickou ohodnocovací funcki. Tento algoritmus se jmenuje minimax. Na šachovnici je v základním postavení 16 pěšců, každý z nich může táhnout nejvýše šestkrát, poté se promění v nějakou figuru. Když nepočítáme krále, které není možné sebrat, je na šachovnici 30 figur a každá z nich může být sebrána maximálně jednou. Pokud se během 50ti tahů (50 tahů bílého a 50 tahů černého, celkem 100 půltahů) netáhne pěšcem ani nesebere žádná figura, je partie považovaná za remízu. Díky tomu můžeme shora odhadnout hloubku šachové partie na (16 * 6 + 30 + 1) * 100 = 12700 půltahů. Algoritmus minimax s hloubkou propočtu 12700 bude teoreticky hrát šachy úplně dokonale, alespoň v tom smyslu, že žádnou remízovou pozici neprohraje, každou vyhranou pozici nejen vyhraje, ale dokonce tím nejrychlejším způsobem a při prohrané pozici bude porážku alespoň maximálně oddalovat.

Reprezentace pozice

Nejednoduší reprezentace šachovnice je dvourozměrné pole 8x8. To můžeme v případě potřeby rozvinout na jednorozměrné pole o 64 prvcích. Výhodou tohoto přístupu je snadnější čitelnost programu, nevýhodou je nutnost ošetřit možné přetečení pole. (Např. tah jezdce z okraje šachovnice mimo její okraj. Toto se dá řešit polem 10x12, potažmo jednorozměrným polem o 120 prvcích, což je vlastně klasická šachovnice 8x8 s mantinely.

Nejednodušší reprezentace šachových figur je celým číslem - kladným pro bílé, záporným pro černé. Prázdné pole je pak neutrální a má hodnotu 0, mantinely (jsou-li přítomny) mají nějakou konstatní hodnotu, která se neuvažuje pro výpočet.

Další možnou reprezentací šachovnice může být bitové pole. Nějaký jev na šachovici je pak reprezentován 64-bitovým číslem. Například výskyt bílých věží v základním postavení je pak reprezentován číslem 129 (00000000 00000000 00000000 00000000 00000000 00000000 00000000 10000001) Když budeme mít pro každý typ kamene jednu proměnnou, 12 proměnných může reprezentovat celou šachovnici. Výhodou tohoto přístupu jevelmi efektivní zpracování zejména na 64-bitové architektuře, kde je každá operace jedna velmi jednoduchá instrukce. Nevýhodou, je, že zejména pro začínající programátory může být tento přístup velmi matoucí a nečitelný.

Reprezentace pole tahů

Protože tahů bude v průběhu výpočtu generováno velmi mnoho, měl by být typ, reprezentující tah, velmi malý. Každopádně musí obsahovat minimálně položky odkud a kam. V případě reprezentace šachovnice dvourozměrným polem, budou položky odkud a kam reprezentovány dvouprvkovým polem - na indexu 0 bude sloupec, na indexu 1 řádek. V případě, že je šachovnice reprezentována jednorozměrným polem, položky odkud a kam jsou reprezentovány pouze celým číslem.

K uložení množiny tahů se běžně používá globální zásobník tahů, který může vypadat nějak takto:

Move moves[MANY]
int borders[DEPTH]
int index_in_stack

Tahz jsou uloženy v jediném globálním jednorozměrném poli, přičemž tahy z aktuálně propočítávané pozice mají index borders[index_in_stack] až borders[index_in_stack+1]-1. Konstanta DEPTH je nejvyšší možná hloubka zanoření rekurze. Na dnešních počítačích by mělo stačit 32. Velikost konstanty MANY pak půjde shora odhadnout jako součin maximálního počtu tahů z pozice * DEPTH. Program při tomto postupu sice může trochu plýtvat pamětí, ale achillovou patou šachových programů obvykle nebývá nedostatek paměti, nýbrž nedostatek času na dostatečně hluboký výpočet. Toto řešení ušetří cenné mikrosekundy, které by stálo dynamické přealokovávání pole v cyklu.

Ohodnocovací funkce

Šachový program provádí propočet do určité hloubky, na jehož konci zavolá ohodnocovací funkci, která vrátí cenu dané pozice. Nejednodušší a nejdůležitější je samozřejmě sečíst materiál. Cena jednotlivých figur se v různých programech liší. Pokud má pěšec cenu 1, bude cena jezdce a střelce přibližně 3, věže 5 a dámy 9. Někdy bývá hodnota střelce nepatrně vyšší než hodnota jezdce a podobně. Šachový program s ohodnocovací funkcí degenerovanou na prostý součet materiálu se pochopitelně bude chovat divně. Cesta i od velmi zjevné poziční chyby k matu je velmi dlouhá a přesahuje hloubku propočtu dnešních programů, takže prostý součet materiálu nestačí. Proto se přidává poziční složka.
Poziční složka bývá obyčejně velmi malá, jen zřídka v reálných partiích přesáhne v absolutní hodnotě cenu pěšce. Řada pozičních faktorů se dá ocenit statickou tabulkou pro jednotlivá políčka. Například poziční bonus pro figury blíže ke středu šachovnice (a tím i větším manévrovacím prostorem) bude vyšší než pro figury u kraje nebo v rohu šachovnice. Takovéto řešení poziční složky jistě nebude dokonalé, zato bude velmi rychlé. Poziční tabulku můžeme pro jednotlivé figury lehce upravit.
Pro pěšce existuje celá řada heuristik. Můžeme pozičně více ocenit pěšce, kteří jsou dále od výchozího postavení - to pěšce přiměje utíkat směrem k dámě. V základním postavení pak můžeme ocenit vyšší bonusem pěšce na vykročivší na středu. Dále můžeme ocenit je-li pěšec volný (žádná figura mu nebrání v běhu do dámy), či je-li krytý jiným pěšce. Rovněž mže dostat postih, je-li opožděný.
Jezdec stojí dobře v centru, v rohu se mu obvykle nedaří. Rovněž můžeme ocenit jezdce šikovně krytého pěšcem.
Pro střelce sice není poziční ohodnocení tak podstatné, přesto se o to můžeme pokusit. Dobře umístěný střelec by měl dostat bonus za soupeřovy pěšce na stejné barvě pole, které může napadat a naopak postih za pěšce, které napadat nemůže. Tím nám vyjde, že dva střelci budou mít spolu nepatrně vyšší hodnotu než je prostý součet jejich hodnot.
U věže nemá statická ohodnocovací tabulka smysl. Věž patří na volný sloupec, má tlačit na opožděné nebo nekryté pěšce a obě věže by se měly navzájem krýt.
U dámy je potřeba snad jen zabránit předčasnému vývinu - soupeř pak prostě napadá dámu s tempy běžnýc vývinových tahů lehčích figur.
U krále je v zahájení a střední hře důležitá především bezpečnost. Jde jednak o umístění, zachované právo rošády, pěšcový kryt krále a napadnutelnost polí v okolí. V koncovce se úloha krále radikálně mění a stává se z něj aktivně bojující figura, která musí opustit úkryt a bojovat o střed. V matové koncovce se pak král silnější strany snaží přiblížit soupeřovu  králi.
Ohodnocovací funkce napsaná pomocí statických tabulek je velmi rychlá, ale má jednu vážnou slabinu. Tabulky jsou napsány obecně, mohou tedy být dobré pro běžnou pozici, ale stačí několik netypických tahů a správné ohodnocení políček například pro jezdce může být úplně jiné. Řešením je místo samotného pole oceňovat pohyblivost figur, napadnutelná pole a tak podobně. To vše je ovšem za cenu vyšší časové náročnosti.

