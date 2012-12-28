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
Paměťová složitost mnimaxu není příliš velká, neboť v zásobníku rekurzivního propočtu je v danou chvíli pouze jedna varianta. Kdyby se tedy minmaxu opravdu podařilo nalézt variantu dlouhou 12 700 půltahů a jedna instance minimaxu zabrala 1 kB, vešli bychom se i s volajícím kódem pohodlně do 13 MB. Na propočet stromu tak bohaté hry, jakou šachy bezesporu jsou, nám tedy stačí pouze pár megabajtů operační paměti. Bohužel časová složitost minimaxu je exponenciální v^h, kde v je větvící faktor a h hloubka propočtu. Předpokládejme, že z pozice můžeme vygenerovat 20 tahů (například z výchozího postavení 16 tahů pěšci, 4 tahy jezdci) a že dokážeme spočítat milion ohodnocovacích funckí za sekundu. Propočet do hloubky 2 pak potrvá 0,008 sekundy, propočet do hloubky 5 3.2 sekundy, propočet do hloubky 10 zhruba 118 a půl dne. Při hloubce 12 700 by to pak bylo 3,81 * 10^16509 let, konce výpočtu by se tedy nejspíš nedočkala ani naše galaxie.
Časovou složitost můžeme zlepšit. Potřebujeme-li zmenšit výsledek vzorce v^h, můžeme zmenšovat h, což je hloubka propočtu a na kvalitu hry má zásadní vliv. Druhou možností je zmenšit v, což je větvící faktor a některé varianty vůbec nepočítat. I přesto se můžeme dostat ke správnému výsledku.

V pozici na diagramu je na tahu bílý, jedná se o známou pozici ze zahájení jménem španělská hra (1. e4 e5 2. Jf3 Jc6 3. Sb5), kde se černý brání obvyklým tahem 3. ...a6. Napadl tedy bílému střelce a ten musí hrozbu nějak pokrýt. Běžné tahy jsou nyní 4. Sa4 a Sxc6, hrát by se dalo i Sc4 a snad ještě hodně defétistické Se2, všechny ostatní tahy jsou již vyloženě špatné. Z této pozice dáme programu za úkol provést propočet do hloubky 2 půltahy. Vygeneruje tahy a zkouší jeden po druhém zahrát. Generátor tahů je lehce modifikovaný, tak aby vracel braní před ostatními tahy. Program tedy nejprve propočítá 4. Sxc6, projde všechny odpovědi černého a zjistí, že po nejlepším 4. ...dxc6 je pozice přibližně vyrovnaná. Bílý sice ztratil výhodu dvojice střelců, ale zase černému znehodnotil pěšcovou strukturu. Ohodnocení prvního tahu zatím proběhlo tak, jako v algoritmu minimax. Rozdíl nastane až u druhého tahu bílého 4. Sxa6. Jedná se o zjevnou chybu, kterou bílý odevzdává střelce za pouhého pěšce, ale minimax by musel projít všechny odpovědi, aby si to uvědomil. Tedy poctivě počítat a ohodnocovat nejen 4. ...bxa6 a Vxa6, ale i zcela nesmyslné tahy jako 4. ...Jh6 nebo g5. Modifikovanému algoritmu stačí jediná: 4. ...Vxa6 nebo bxa6. Navíc generátor tahů, který preferuje braní, vrátí jeden z uvedených tahů hned jako první. Jak program pozná, že může propočet odpovědí na 4. Sxa6 přerušit a prohlásit tah za neperspektivní? Z propočtu 4. Sxc6 si zapamatoval hodnotu nejlepší odpovědi 4. ...dxc6, tedy zhruba 0 tj. vyrovnanou pozici. Při propočtu dalších tahů (4. Sxa6) uvedenou hodnotu použijeme jako práh. Pokud jej jakákoli odpověď (4. ...bxa6 nebo Vxa6) přesáhne, propočet tahu (4. Sxa6) ukončíme, neboť již víme, že je špatný. Jinými slovy: pokud víme, že tah je špatný (= horší než nějaký jiný - zde 4. Sxc6), nemá smysl dále zkoumat, jestli není náhodou ještě o něco horší, než jsme zatím zjistili. 
Pokud počítáme do hloubky 3 a více, dojde při prořezávání na oba hráče a jsou zde proto meze pro obě strany. DOlní se říká alfa, horní beta, odtud také název algoritmu alfabeta metoda (nebo alfabeta ořezávání). Pokud během propočtu narazíme na variantu, která je horší než alfa, můžeme ji zahodit. Vyjde-li nám varianta lepší než beta, může se jí zase vyhnout soupeř a zahrát tah, který je lepší pro něj. Časová složitost alfabety silně závisí na pořadí tahů, což ovlivňuje, jak rychle se nám podaří sevřít meze alfa a beta. Časová složitost optimální alfabety je v^h/2, můžeme se s ní tedy za stejný čas dostat dvakrát hlouběji než s minimaxem. Je tedy žádoucí aby nejnadějnější varianty počítal algoritmus jako první. Existuje několik heuristik, jak odhadnout už v generátoru tahů, které varianty by mohly být nejlepší.

Sežer co můžeš

Způsobí-li tah změnu materiálu, posuneme ho na více dopředu. Preferovat můžeme rovněž braní nižší figurou.

Historická heuristika

Je založena na myšlence, že pokud byl tah dobrý v jedné variantě, nejspíš bude dobrý i v jiné. Tři typy této metody mohou být:

Globální tabulka tahů

Program si musí nějak pamatovat tahy. Informace odkud a kam se táhne, případně typ nové figury po proměně pěšce se při troše snahy vejde do 16 bitů. Vytvoříme si tedy pole velikosti 216, pro každý možný tah jeden byte. Na počátku propočtu pole obsahuje samé nuly. Když se nějaký tah ukáže jako dobrý (větší než aktuální hodnota alfa). Zvětším hodnotu jeho políčka v poli. Když potom po vygenerování třídíme tahy, uvažujeme ještě také hodnotu této heuristiky. Jak přesně se mají zvětšovat hodnoty v tabulce je složitá otázka. Je zřejmé, že dobré tahy z pozic vzdálenějších od kořene mají menší význam než dobré tahy z pozic blízkých kořeni. Je to tím, že průměrná pozice z propočtu je bližší kořeni než nějakému listu ze vzdálené větve.

Nejlepší tahy pro danou hloubku

Pro každou hloubku zanoření v propočtu si zapamatujeme poslední dva zlepšující tahy. Tyto tahy dostanou při propočtu v tomto zanoření speciální bonus. Oproti globální tabulce má metoda tu výhodu, že se více týká aktuální pozice a příslušné hloubky, chová se tedy lokálně. Tím pádem většinou preferuje zlepšující tahy z blízkých uzlů a u nich je opravdu dost velká pravděpodobnost, že budou dobré i v počítané pozici. Nevýhodou je, že ohodnocuje jen relativně málo tahů (přesně 2).

Hlavní varianta

Program si uchovává v tabulce dosavadní hlavní variantu, tedy větev výpočtu při optimální hře (optimální ve smyslu ohodnoceni listů) obou hráčů. Tah, který přísluší k hlavní variantě bude zřejmě dobrý i v celé řadě jiných variant, a proto získává bonus. Varianty se ukládají do matice, využívá se ale jen horní trojúhelník. V jednom políčku matice je jeden tah. Jsme-li při propočtu v nějakém uzlu, počítáme v tomto okamžiku vlastně hodnotu všech pozic na cestě z kořene do našeho uzlu. V i-tém řádku (od diagonály dál) si uchováváme nejlepší dosavadní variantu z i-té pozice na cestě od kořene. Dejme tomu, že v hloubce i došlo k nalezení zlepšujícího tahu. V řádku i máme původní nejlepší variantu (od naší pozice dál) a v řádku i+1 je zlepšující varianta.. Za této situace musíme zkopírovat i+1-ní řádek na pozici i-tého (z něj zůstane jen první tah na diagonále). 

Nevýhodou alfabety je její pevná hloubka. Jsme-li v zahájení nebo střední hře, bude tahů k ohodnocení velmi mnoho. Hloubka výpočtu v této části hry by tedy neměla být příliš vysoká, jinak se k výsledku nedopočítáme v rozumném čase. Naopak v koncovce, kdy je pouze pár přípustných tahů lze hloubku propočtu zvýšit.
Tento problém řeší kaskádová metoda. Jedná se vlastně o alfabeta metodu, která postupně počítá do hloubky 1,2,3,...,n. Na první pohled se může zdát zbytečné počítat pokaždé znovu, nicméně kaskádová metoda má několik výhod:

Zpomalení je malé

Protože je složitost alfabety exponenciální, zpomalí kaskádová metoda program cca jeden a půlkrát. Dejme tomu, že průměrný větvící faktor šachu je 38, při dobrém alfabeta ořezávání se dostaneme na větvicí faktor zhruba odmocnina z 38, dejme tomu 7. !7^n-1 je zhruba o řád menší než 7^n.

Lepší časová kontrola

V praxi obvykle nezní zadání "dej mi nejlepší tah do hloubky 5", ale "dej mi nejlepší tah, máš na to 5 sekund". Potom je velmi obtížné stanovit hloubku propočtu, které dosáhneme v daném čase. U kaskádové metody prostě provádíme iterace tak dlouho, dokud máme čas. To nám právě umožní v koncovce (případně kdykoliv, kdyže je množina možných tahů dostatečně malá) počítat do větší hloubky.

Třídění tahů

Kaskádová metoda poskytuje lepší možnosti třídění tahů. Propočet do hloubky 1 začneme s tahy setříděnými podle jednoduchých heuristik v generátoru tahů. Nejlepší tah poté přemístíme na začátek, pokračujeme propočtem do hloubky 2, nejlepší taj z hloubky 2 opět přemístíme na začátek a tak dále. Tím se nám podaří velmi rychle sevřít interval alfa a beta okolo nejnadějnějších tahů, což kaskádovou metodu ještě dále zrychlí. Případů, kdy zahájíme propočet několika špatnými tahy bude velmi málo - obvykle se jedná o pozice s možností složité oběti nebo komplikovaného tahu.

Metoda okénka

Alfabeta metoda svírá interval alfa a beta velmi defenzivně - tak aby se vždy dopočítala ke správnému výsledku. Celý výpočet můžeme zrychlit tím, že meze alfa a beta ještě více sevřeme - vytvoříme interval alfa2 a beta2, který bude podmonžinou původního alfa a beta. Pokud jsme měli pravdu, ušetřili jsme na výpočtu nějaký čas, pokud ne, interval prostě přeteče a v následující iteraci kaskádové metody se počítá interval s již opravenými mezemi.

Prohlubování






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

