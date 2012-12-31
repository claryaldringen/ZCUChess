\documentclass[11pt]{article}
\usepackage[utf8]{inputenc}
\usepackage[czech]{babel}
\usepackage{a4wide}

\begin{document}

\section{Zadání}

Implementace jednoduchého šachového algoritmu, který umožňuje hru hráče proti počítači. Vstup a výstup bude probíhat na příkazové řádce.

\section{Analýza úlohy}

Nejprve je potřeba navrhnout základní datové struktury a rutiny, které musí obsahovat každý šachový program i takový, který neobsahuje žádný myslící algoritmus a umožňuje napřiklad jen hru dvou lidských hráčů po síti. Patří sem funkce pro
\begin{itmize}
	\item Nalezení všech legálních tahů z dané pozice
	\item Kontrola šachu a matu
	\item Funkce kontrolující dodržení pravidel při rošádě a braní mimochodem
	\item Funkce, která zahraje samotný tah
\end{itemize}
Bude následovat umělá inteligence a chybět nesmí ani několik málo funkcí pro komunikaci s okolím, jako je zparsování tahu zadaného z klávesnice, vypsání tahu, upozornění na přemýšlení programu a podobně.

\subsection{Umělá inteligence a teorie šachové hry}

\subsubsection{Od nejjednoduššího algoritmu ke kaskádové metodě}
Šachy jsou čistě matematickou úlohou, k jejímuž vyřešení se dá v každém případě dopočítat. Za vyřešení úlohy můžeme považovat mat v případě vyhrané pozice, pat v případě remízové pozice nebo alespoň co největší oddalování porážky v případě prohrané pozice. Klíčovou funkcí je statická ohodnocovací funkce, která vrátí číselnou hodnotudané pozice. Nejednodušší algoritmus, který nehraje úplně náhodně, vygeneruje všechny tahy ze zadané pozice, každý z nich zahraje a vzniklou pozici ohodnotí statickou ohodnocovací funkcí. Pokud je hodnota pozice vyšší než dosud nejvyšší, uloží ji i tah, kterým jsme se na ni dostali. Poté zahraje tah zpět a tak dále, dokud nevyzkoušíme všechny tahy. Tento algoritmus je sice lepší než náhodné generování tahů, ale díru do světa rozhodně neudělá. Sebere klidně dámou krytého pěšce, nepokryje jednotahový mat a podobně.

Vylepšením je přidat rekurzi. Zahrajeme všechny tahy z dané pozice, na tyto tahy zahrajeme odpověď soupeře, pak zase naší odpověď a tak dále až do nějaké hloubky n, kde zavoláme statickou ohodnocovací funcki. Tento algoritmus se jmenuje minimax. Na šachovnici je v základním postavení 16 pěšců, každý z nich může táhnout nejvýše šestkrát, poté se promění v nějakou figuru. Když nepočítáme krále, které není možné sebrat, je na šachovnici 30 figur a každá z nich může být sebrána maximálně jednou. Pokud se během 50ti tahů (50 tahů bílého a 50 tahů černého, celkem 100 půltahů) netáhne pěšcem ani nesebere žádná figura, je partie považovaná za remízu. Díky tomu můžeme shora odhadnout hloubku šachové partie na (16 * 6 + 30 + 1) * 100 = 12700 půltahů. Algoritmus minimax s hloubkou propočtu 12700 bude teoreticky hrát šachy úplně dokonale, alespoň v tom smyslu, že žádnou remízovou pozici neprohraje, každou vyhranou pozici nejen vyhraje, ale dokonce tím nejrychlejším způsobem a při prohrané pozici bude porážku alespoň maximálně oddalovat.

Paměťová složitost mnimaxu není příliš velká, neboť v zásobníku rekurzivního propočtu je v danou chvíli pouze jedna varianta. Kdyby se tedy minmaxu opravdu podařilo nalézt variantu dlouhou 12 700 půltahů a jedna instance minimaxu zabrala 1 kB, vešli bychom se i s volajícím kódem pohodlně do 13 MB. Na propočet stromu tak bohaté hry, jakou šachy bezesporu jsou, nám tedy stačí pouze pár megabajtů operační paměti. Bohužel časová složitost minimaxu je exponenciální v^h, kde v je větvící faktor a h hloubka propočtu. Předpokládejme, že z pozice můžeme vygenerovat 20 tahů (například z výchozího postavení 16 tahů pěšci, 4 tahy jezdci) a že dokážeme spočítat milion ohodnocovacích funckí za sekundu. Propočet do hloubky 2 pak potrvá 0,008 sekundy, propočet do hloubky 5 3.2 sekundy, propočet do hloubky 10 zhruba 118 a půl dne. Při hloubce 12 700 by to pak bylo 3,81 * 10^16509 let, konce výpočtu by se tedy nejspíš nedočkala ani naše galaxie.

Časovou složitost můžeme zlepšit. Potřebujeme-li zmenšit výsledek vzorce v^h, můžeme zmenšovat h, což je hloubka propočtu a na kvalitu hry má zásadní vliv. Druhou možností je zmenšit v, což je větvící faktor a některé varianty vůbec nepočítat. I přesto se můžeme dostat ke správnému výsledku.

V pozici na diagramu je na tahu bílý, jedná se o známou pozici ze zahájení jménem španělská hra (1. e4 e5 2. Jf3 Jc6 3. Sb5), kde se černý brání obvyklým tahem 3. ...a6. Napadl tedy bílému střelce a ten musí hrozbu nějak pokrýt. Běžné tahy jsou nyní 4. Sa4 a Sxc6, hrát by se dalo i Sc4 a snad ještě hodně defétistické Se2, všechny ostatní tahy jsou již vyloženě špatné. Z této pozice dáme programu za úkol provést propočet do hloubky 2 půltahy. Vygeneruje tahy a zkouší jeden po druhém zahrát. Generátor tahů je lehce modifikovaný, tak aby vracel braní před ostatními tahy. Program tedy nejprve propočítá 4. Sxc6, projde všechny odpovědi černého a zjistí, že po nejlepším 4. ...dxc6 je pozice přibližně vyrovnaná. Bílý sice ztratil výhodu dvojice střelců, ale zase černému znehodnotil pěšcovou strukturu. Ohodnocení prvního tahu zatím proběhlo tak, jako v algoritmu minimax. Rozdíl nastane až u druhého tahu bílého 4. Sxa6. Jedná se o zjevnou chybu, kterou bílý odevzdává střelce za pouhého pěšce, ale minimax by musel projít všechny odpovědi, aby si to uvědomil. Tedy poctivě počítat a ohodnocovat nejen 4. ...bxa6 a Vxa6, ale i zcela nesmyslné tahy jako 4. ...Jh6 nebo g5. Modifikovanému algoritmu stačí jediná: 4. ...Vxa6 nebo bxa6. Navíc generátor tahů, který preferuje braní, vrátí jeden z uvedených tahů hned jako první. Jak program pozná, že může propočet odpovědí na 4. Sxa6 přerušit a prohlásit tah za neperspektivní? Z propočtu 4. Sxc6 si zapamatoval hodnotu nejlepší odpovědi 4. ...dxc6, tedy zhruba 0 tj. vyrovnanou pozici. Při propočtu dalších tahů (4. Sxa6) uvedenou hodnotu použijeme jako práh. Pokud jej jakákoli odpověď (4. ...bxa6 nebo Vxa6) přesáhne, propočet tahu (4. Sxa6) ukončíme, neboť již víme, že je špatný. Jinými slovy: pokud víme, že tah je špatný (= horší než nějaký jiný - zde 4. Sxc6), nemá smysl dále zkoumat, jestli není náhodou ještě o něco horší, než jsme zatím zjistili. 
Pokud počítáme do hloubky 3 a více, dojde při prořezávání na oba hráče a jsou zde proto meze pro obě strany. Dolní se říká alfa, horní beta, odtud také název algoritmu alfabeta metoda (nebo alfabeta ořezávání). Pokud během propočtu narazíme na variantu, která je horší než alfa, můžeme ji zahodit. Vyjde-li nám varianta lepší než beta, může se jí zase vyhnout soupeř a zahrát tah, který je lepší pro něj. Časová složitost alfabety silně závisí na pořadí tahů, což ovlivňuje, jak rychle se nám podaří sevřít meze alfa a beta. Časová složitost optimální alfabety je v^h/2, můžeme se s ní tedy za stejný čas dostat dvakrát hlouběji než s minimaxem. Je tedy žádoucí aby nejnadějnější varianty počítal algoritmus jako první. Existuje několik heuristik, jak odhadnout už v generátoru tahů, které varianty by mohly být nejlepší:

 - Sežer co můžeš: Způsobí-li tah změnu materiálu, posuneme ho na více dopředu. Preferovat můžeme rovněž braní nižší figurou.
 - Historická heuristika je založena na myšlence, že pokud byl tah dobrý v jedné variantě, nejspíš bude dobrý i v jiné. Tři typy této metody mohou být:
 - Globální tabulka tahů: Program si musí nějak pamatovat tahy. Informace odkud a kam se táhne, případně typ nové figury po proměně pěšce se při troše snahy vejde do 16 bitů. Vytvoříme si tedy pole velikosti 216, pro každý možný tah jeden byte. Na počátku propočtu pole obsahuje samé nuly. Když se nějaký tah ukáže jako dobrý (větší než aktuální hodnota alfa). Zvětším hodnotu jeho políčka v poli. Když potom po vygenerování třídíme tahy, uvažujeme ještě také hodnotu této heuristiky. Jak přesně se mají zvětšovat hodnoty v tabulce je složitá otázka. Je zřejmé, že dobré tahy z pozic vzdálenějších od kořene mají menší význam než dobré tahy z pozic blízkých kořeni. Je to tím, že průměrná pozice z propočtu je bližší kořeni než nějakému listu ze vzdálené větve.
 - Nejlepší tahy pro danou hloubku: Pro každou hloubku zanoření v propočtu si zapamatujeme poslední dva zlepšující tahy. Tyto tahy dostanou při propočtu v tomto zanoření speciální bonus. Oproti globální tabulce má metoda tu výhodu, že se více týká aktuální pozice a příslušné hloubky, chová se tedy lokálně. Tím pádem většinou preferuje zlepšující tahy z blízkých uzlů a u nich je opravdu dost velká pravděpodobnost, že budou dobré i v počítané pozici. Nevýhodou je, že ohodnocuje jen relativně málo tahů (přesně 2).
 - Hlavní varianta: Program si uchovává v tabulce dosavadní hlavní variantu, tedy větev výpočtu při optimální hře (optimální ve smyslu ohodnoceni listů) obou hráčů. Tah, který přísluší k hlavní variantě bude zřejmě dobrý i v celé řadě jiných variant, a proto získává bonus. Varianty se ukládají do matice, využívá se ale jen horní trojúhelník. V jednom políčku matice je jeden tah. Jsme-li při propočtu v nějakém uzlu, počítáme v tomto okamžiku vlastně hodnotu všech pozic na cestě z kořene do našeho uzlu. V i-tém řádku (od diagonály dál) si uchováváme nejlepší dosavadní variantu z i-té pozice na cestě od kořene. Dejme tomu, že v hloubce i došlo k nalezení zlepšujícího tahu. V řádku i máme původní nejlepší variantu (od naší pozice dál) a v řádku i+1 je zlepšující varianta.. Za této situace musíme zkopírovat i+1-ní řádek na pozici i-tého (z něj zůstane jen první tah na diagonále). 

Nevýhodou alfabety je její pevná hloubka. Jsme-li v zahájení nebo střední hře, bude tahů k ohodnocení velmi mnoho. Hloubka výpočtu v této části hry by tedy neměla být příliš vysoká, jinak se k výsledku nedopočítáme v rozumném čase. Naopak v koncovce, kdy je pouze pár přípustných tahů lze hloubku propočtu zvýšit.
Tento problém řeší kaskádová metoda. Jedná se vlastně o alfabeta metodu, která postupně počítá do hloubky 1,2,3,...,n. Na první pohled se může zdát zbytečné počítat pokaždé znovu, nicméně kaskádová metoda má několik výhod:

\subsubsection{Zpomalení je malé}

Protože je složitost alfabety exponenciální, zpomalí kaskádová metoda program cca jeden a půlkrát. Dejme tomu, že průměrný větvící faktor šachu je 38, při dobrém alfabeta ořezávání se dostaneme na větvicí faktor zhruba odmocnina z 38, dejme tomu 7. !7^n-1 je zhruba o řád menší než 7^n.

\subsubsection{Lepší časová kontrola}

V praxi obvykle nezní zadání "dej mi nejlepší tah do hloubky 5", ale "dej mi nejlepší tah, máš na to 5 sekund". Potom je velmi obtížné stanovit hloubku propočtu, které dosáhneme v daném čase. U kaskádové metody prostě provádíme iterace tak dlouho, dokud máme čas. To nám právě umožní v koncovce (případně kdykoliv, kdyže je množina možných tahů dostatečně malá) počítat do větší hloubky.

\subsubsection{Třídění tahů}

Kaskádová metoda poskytuje lepší možnosti třídění tahů. Propočet do hloubky 1 začneme s tahy setříděnými podle jednoduchých heuristik v generátoru tahů. Nejlepší tah poté přemístíme na začátek, pokračujeme propočtem do hloubky 2, nejlepší taj z hloubky 2 opět přemístíme na začátek a tak dále. Tím se nám podaří velmi rychle sevřít interval alfa a beta okolo nejnadějnějších tahů, což kaskádovou metodu ještě dále zrychlí. Případů, kdy zahájíme propočet několika špatnými tahy bude velmi málo - obvykle se jedná o pozice s možností složité oběti nebo komplikovaného tahu.

\subsubsection{Metoda okénka}

Alfabeta metoda svírá interval alfa a beta velmi defenzivně - tak aby se vždy dopočítala ke správnému výsledku. Celý výpočet můžeme zrychlit tím, že meze alfa a beta ještě více sevřeme - vytvoříme interval alfa2 a beta2, který bude podmonžinou původního alfa a beta. Pokud jsme měli pravdu, ušetřili jsme na výpočtu nějaký čas, pokud ne, interval prostě přeteče a v následující iteraci kaskádové metody se počítá interval s již opravenými mezemi.

\subsubsection{Prohlubování}

Herní algoritmus počítá do nějaké hloubky, na jejímž konci ohodnotí pozici statickou ohodnocovací funckí. Tento postup dobře funguje v běžných pozicích, ale v taktických pozicích (jako je výměna těžkých figur, pozice tah před matem, kdy vítězná strana obětovala materiál, atp.) selhává. Přitom by zde stačila o něco málo větší houbka propočtu a program by hrozby včas viděl. Celkovou hloubku propočtu nemůžeme příliš zvyšovat - program by se nedopočítal. Řešením je tedy prouhloubení těch variant, které jsou obvzáště zajímavé. 

\subsubsection{Dopočet do tiché pozice}

Dopočet do tiché pozice patří v šachu k nejjednodušším a zároveň nejdůležitějším vylepšením alfabeta metody. Na úroveň hry programu má zcela zásadní vliv. Spočívá v tom, že pokud se v propočtu dostaneme do listu, neodhadujeme hodnotu pozice statickou ohodnocovací funkcí, ale jakousi modifikací alfabety, která se liší tím že bere v úvahu pouze braní a proměny pěšce. Vzhledem k tomu, že hráči odepíráme všechny ostatní tahy (tzv. tiché tahy), musíe mu umožnit nehrát, jinak bychom jej nutili i do nevýhodných braní. Funkce tedy vrací maximum z hodnoty pozice odhadnuté statickou ohodnocovací funkcí a rekurzivního dopočtu braní. Právě dopočet do tiché pozice řeší případy nedopočítaných výměn. Dopočet samozřejmě hodně zdržuje a sníží základní hloubku propočtu, ale pozitivní efekt je i tak obrovský. Dopočet do tiché pozice má navíc kladný vliv i na stabilitu výpočtu - již se nám nestane příliš často, že by zvýšení základní hloubky propočtu mělo nějaký zásadní vliv na hodnotu varianty.

\subsubsection{Prohlubování taktických variant}

Dopočet do tiché pozice je účinný, ale neřeší vše. Ve zvlášť nadějných variantách bývá dobré hloubku propočtu o jedničku zvýšit a nemusí se při tom nutně jednat o braní nebo proměny pěšce. K prohloubení také nemusí dojit jen v listu. Kdy přesně má smysl prohlubovat je složitá otázka. Za typické kandidáty na prohloubení můžeme označit tahy
 - Kdy je sebraná figura, která v minulém tahu sama brala (může se jednat o dokončení výměny)
 - Pokrytí šachu představením (může být jen oddálením matu skrývajícího se za horizntem propočtu)
 - Jakékoliv varianty s vynucenými tahy
 - Vidle pěšcem i jezdcem a podobné taktické údery
 - Varianty s tzv. Fisherovým střelcem
 - Taktické hrozby králi

Při prohlubování je potřeba postupovat velmi obezřetně, neboť prohloubení jedné varianty zkrátí výpočetní čas ostatních variant. 

\subsubsection{Haš tabulky}

Doteď jsme se snažili zrychlit výpočet pomocí ořezávání a svírali jsme interval alfa a beta jak to jen šlo, abychom odřízli co nejvyšší počet variant, které nemá cenu počítat. Existuje však ještě jeden druh variant, které rovněž nemusíme počítat. Jde o dvojce variant, které se od sebe liší pouhým prohozením tahů. Pokud program počítá do hloubky 5 půltahů ze základního postavení, nevynechá ani variantu bílý pěšec na e4, černý pěšec na c5 v prvním tahu, bílý jezdec na f3 v druhém tahu a z této pozice pozice počítá ještě do zbývající hloubky 2 půltahy. Ke stejnému výsledku se však dostane i z pozice, kdy v prvním tahu příjde bílý jezdec na f3 a černý pěšec na c5 a ve druhém tahu bílý pěšec na e4. Následující dva půltahy se budou počítat znovu. Je přitom zřejmé, že vzniklou pozici stačí zkoumat jen jednou.
V zahájení a střední hře s velkým počtem figur a malou hloubkou propočtu dochází k těmto duplicitám ještě poměrně zřídka. Mnohem horší je stuace v koncovce s malým počtem figur. Typickým příkladem je koncovka dvou králů, v níž mají obě strany už jen několik zablokovaných pěšců. Král se obvykle snaží vytlačit soupeřova monarchu (obvykle i s využitím nevýhody tahu), pobrat soupeřovy pěšce a prosadit ty své do dámy. Obě strany přitom mají na výběr jen několik málo přípustných tahů, a tak hloubka propočtu roste oproti střední hře i dvojnásobně. Při podobných hlubokých propočtech dochází k opakovanému vyhodnocování jedné varianty vzniklé jen přehozením tahů zcela běžně. Právě v podobných typech pozic přitom může mít počítač s lidským soupeřem problémy. Jednoduchý charakter pozice totiž umožní lépe oprostit plán výhry nebo obrany od detailního propočtu (případně lidský propočet degeneruje na jedinou, ale zato dlouhou variantu bez větvení) a umožní vidět mnohem dál i člověku.

Řešením je mít haš tabulku s výsledky jednotlivých výpočtů, do které se podíváme a pokud zde výsledek propočtu z naší pozice najdeme, okamžitě ho vrátíme. Je potřeba dát pozor na několik věcí:
 - Ukládat je potřeba i hloubku propočtu, neboť nelze nahradit propočet výsledkem předchozího propočtu do menší hloubky.
 - Alfabeta nedává jen mezivýsledky typu pozice má cenu = +3, ale i pozice má cenu <= +3 nebo pozice má cenu => +3. Tyto mezivýsledky je rovněž potřeba ukládat.
 - Musíme pracovat velmi rychle s velkým množstvím dat.
 - Program by neměl číst z disku - struktura se musí za každou cenu vejít do paměti.
 - Je lepší, když struktura zapomíná než aby swapovala
 - Pozice obsahuje 64 polí a stavovou informaci o tahu, právu na rošády a braní mimochodem, ale jeden záznam ve struktuře by měl mít en několik bytů, proto volíme haš tabulku.

V této haš tabulce nemusíme řešit kolize - nová nebo cennější hodnota prostě přepíše starou. Je to rychlejší a jednodušší než na jednotlivých prcích vytvářet spojové seznamy a zabývat se alokováním a uvolňováním paměti
 - Je lepší, když struktura zapomíná než aby swapovala
 - Pozice obsahuje 64 polí a stavovou informaci o tahu, právu na rošády a braní mimochodem, ale jeden záznam ve struktuře by měl mít en několik bytů, proto volíme haš tabulku.

V této haš tabulce nemusíme řešit kolize - nová nebo cennější hodnota prostě přepíše starou. Je to rychlejší a jednodušší než na jednotlivých prcích vytvářet spojové seznamy a zabývat se alokováním a uvolňováním paměti.

\subsubsection{Databáze zahájení a koncovek}

Každá šachová partie začíná vždy stejnou pozicí. Je celkem pochopitelné, že šachisté velmi pečlivě studují jednotlivé varianty vzniklé ze základního postavení již v klidu doma s počítačem nebo v klubu během tréninku a ne až v omezeném čase během partie. O konkrétních zahájeních byly napsány stovky knih, věnovali se jim ti nejlepší šachisté teoretici. Během zahájení běžně vznikají velmi komplikované pozice, ve kterých se nevyznají ani velmistři, a malá nenápadná a těžko odhalitelná chyba může vést k rychlé prohře nebo alespoň k výhodě soupeře. Rozmotat přímo za šachovnicí několik delších a trochu rozvětvených vynucených variant (které během desítek let vymysleli šachoví teoretici) bývá bez předchozí přípravy nad síly i těch nejlepších hráčů a dnešních programů, ale naučit se řešení nazpaměť a pochopit ho se dokáže při troše snahy i průměrný klubový šachista nebo třeba náš program.
Program naučíme zahájení tak, že někam uložíme pozice běžné v zahájení a/nebo jejich haš funkce a k nim sadu tahů, které od programu v uvedené pozici očekáváme. Každému tahu zároveň přiřadíme pravděpodobnost jeho zahrání. Například pro základní postavení může seznam vypadat takto:
 - 30% 1. e4
 - 30% 1. d4
 - 15% 1. c4
 - 13% 1. Jf3
 - 5% 1. f4
 - 2% 1. b3
 - 1% 1. b4
 - 1% 1. g3
 - 1% 1. e3
 - 1% 1. d3
 - 1% 1. Jc3

Největší pravděpodobnost budou mít dobré a obvykle hrané tahy, méně běžným a nepříliš ambiciózním tahům, které však pozici bílého nijak neohrožují dáme jen malou pravděpodobnost (hodí se občas k vyprovokování lidského soupeře) a tahy vyloženě špatné jako například 1.f3? nebo 1.h3? nebudeme uvádět vůbec, program je tedy nebude hrát.
Podobný seznam pravděpodobností ohodnocených tahů budeme mít pro každou naučenou pozici uložený v nějaké datové struktuře postavené nad hašovací funkcí pozice. Tahů z pozic je proměnlivé množství. Typická vyhledávací datová strukturaproto nebude obsahovat přímo tahy. Místo nich v ní budou indexy do pole tahů zakončené nulou. Ukážeme si to na příkladu se setříděným polem a hašovací funkcí která není na naší množině uložených pozic prostá. Obsahovat bude jen 3 pozice: základní postavení (haš = 368) se třemi tahy 1. e4 (40%), 1. d4 (40%) a 1. c4 (20%), pozici po 1. e4 (haš = 129) se dvěma tahy 1. ...c5 (50%) a 1. ... e5 (50%) a nakonec pozici po 1. e4 e5

haš129, index 0    haš 368, index 3    haš 368, index 5
pozice po 1. e4    pozice po 1. e4 e5  základní postavení

Takto by vypadala vyhledávací struktura. Pozice bychom si pamatovali nejspíš fyzicky odděleně, například na stejném indexu v jiném poli, zde je proto máme v druhém řádku. Dejme tomu, že hledáme tah ze základního postavení. Spočítáme si hašovací funkci 368. Nějakým algoritmem pro vyhledávání v setříděném poli s rovnoměrným rozdělením dat (logaritmicky půlením nebo ještě lépe dělením podle hodnoty haš funkcí) najdeme políčko se správnou hodnotou haš funkce, dejme tomu, že máme smůlu a bude to prostřední políčko. Zjistíme, že pozice není naše, neboť došlo ke kolizi haš funkcí. Koukneme se while cyklem doleva, tam už je jiná hodnota haš funkce. Tak tedy doprava na poslední políčko, zde odpovídá haš funkce a i pozice je správně, budeme tedy hledat tahy na indexu 5 v poli tahů. Tabulka tahů pak může vypadat nějak takto:

V poli od pozice 5 až k následující nule jsou tahy e4, d4 a c4, vygenerujeme tedy náhodné číslo z rozsahu 0 až 100, padne třeba 50 a program zahraje 1. d4.

S ubývajícím počtem figur a blížícím se koncem partie se pozice postupně zjednodušuje. Při propočtu ubývá možných variant, spousta z nich vede do stejné pozice, jiné zase brzy končí matem nebo remízou. Program by měl tudíž v jisté chvíli začít počítat dokonale. Pokud však zkusíme standardnímu prohledávacímu algoritmu předložit třeba nějakou pozici z koncovky střelce a jezdce proti samotnému králi, kKvalitní program koncovku sice zvládne - zatlačí soupeřova krále do rohu barvy střelce a tam mu nasadí mat, ale rozhodně nenajde ten nejrychlejší postup a maty třeba 20. tahem zdálky prostě neuvidí. V opravdu těžkých koncovkách typu dáma proti dvěma lehkým figurám pak běžný kvalitní myslící algoritmus již bude chybovat a některé vyhrané pozice vyhrát nedokáže. V omezeném čase není možné ani v poměrně jednoduché koncovce projít celý graf hry z kořene k listům, díky kolizím v hašovací funkci navíc budeme řadu variant počítat opakovaně, takže s dokonalou hrou nemůžeme počítat ani v elementární koncovce dámy proti samotnému králi.
Naštěstí je to s pozicemi z koncovek podobné, jako s těmi ze zahájení. Dají se naučit. Všech možných pozic několikafigurové koncovky je sice z lidského pohledu mnoho, ale počítač má posunutá měřítka. Jednoduchý horní odhad pro počet pozic n-figurové koncovky je 2 * 64^n, neboť každá figurka může být na jednom ze 64 polí a možnosti se násobí. Úvodní dvojka je tam kvůli právu tahu, buď hraje bílý nebo černý. Náš odhad bychom mohli i zpřesnit na 2 * 64 * 63 * 62 * ... * (64 - n + 1), protože dvě figurky nemohou být na stejném políčku, takže 1. figurka má 64 možností, druhá jen 63 atd. Mohli bychom také vyškrtat nepřípustné pozice, ztotožnit stejné figury atd., ale úvodní vzorec nám zároveň dává návod, jak velmi jednoduše a efektivně každé pozici zkoumané koncovky přidělit číslo od 0 do 2 * 64^n - 1 (její místo v tabulce příslušné koncovky) a naopak ke každému číslu z uvedeného intervalu přiřadit pozici.
Stanovíme si pořadí figur naší koncovky podle jejich barvy a materiální hodnoty. Například pro koncovku jezdce a střelce to může být pořadí bílý král, bílý střelec, bílý jezdec, černý král. Očíslujeme políčka šachovnice od 0 do 63, a1 bude 0, a2 1 atd., h8 bude 63. Máme-li n jednoznačně seřazených figur, označíme čísla políček, na nichž se nacházejí p0 až pn - 1. U koncovek s opakováním jednoho druhu kamene (například koncovka krále proti dvěma střelcům) budeme jako první uvažovat figuru s vyšším indexem políčka. Číslo pozice pak bude p0 + 64 * p1 + 64^2 * p2 + ... + 64^n - 1 * pn - 1 + (hraje bílý ? 64^n : 0).  

Na obrázku je příklad pozice z koncovky dvou střelců. Pořadí figur bude KSSk, tedy bílý král a oba střelci a nakonec černý král. Na tahu je bílý a na naší šachovnici hraje nahoru, střelci jsou tedy na d3 a e3, bílý král na f3 a černý na e5. V následující tabulce je výpočet čísla pozice v rámci dané koncovky. Výsledek je 26 293 525.

Opačný převod z čísla na pozici bude analogický, číslo rozložíme na cifry v 64-kové soustavě a to budou indexy políček jednotlivých kamenů.

Vlastní algoritmus vygenerování databáze n-figurové koncovky bude vypadat nějak takto:
 - Rekurzivně stejným algoritmem vygeneruj databáze koncovek, které z naší koncovky mohou vzniknout. (Například pro koncovku dámy proti věži vygeneruj nejprve koncovku se samotnou dámou a se samotnou věží.)
 - Naalokuj místo pro 2 * 64^n čísel a vyplň je nulami
 - Projdi přirozená čísla od 0 do 2 * 64^n - 1, ke každému vygeneruj pozici. Je-li nepřípustná (2 figury na sobě, šach nehrajícímu), vlož do pole čísel na daný index konstantu CHYBA, je-li černý v matu vlož 1, je-li bílý v matu, vlož -1.
 - Projdi přirozená čísla od 0 do 2 * 64^n - 1, přeskoč ty, kde je na daném indexu v poli jiné číslo než nula. Ke každému číslu vygeneruj pozici. Na náš index do pole vlož stručně řečeno hodnotu propočtu minimaxem do hloubky 1 s ohodnocením pomocí již spočítaných hodnot a nul v poli. Podrobně řečeno: Dejme tomu, že hraje bílý (pro černého budeme postupovat analogicky). Vygeneruj z pozice tahy, zahraj je. Pokud zahraným tahem přešla pozice do jiného druhu koncovky (proměna pěšce, braní), podívej se do tabulky pro tuto koncovku, kolikátým půltahem bílý dává nebo dostává mat, případně zda je pozice remízová. Pokud zůstal zachován typ koncovky, spočítej si index pozice a podívej se do pole, zda a jak již máme pozici ohodnocenou. 0 znamená, že zatím nevíme, kladné číslo, že je pozice vyhraná za bílého, záporné, že za černého. Je-li mezi čísly alespoň jedno kladné vlož do pole na náš index to nejmenší z těch kladných čísel zvětšené o 1. (Například z 0, 0, 0, 5, 3, -2, 0, 0, -2, -4 vyber 3 a do pole na náš index dej 3 + 1 = 4. Znamená o, že dáváme mat 2. tahem, neboť jsme o 3 půltahy od 1, což je mat.) Jsou-li všechna čísla záporná, je pozice za bílého prohraná, vyber z nich to nejmenší (s největší absolutní hodnotou) a do pole na náš index ho dej zmenšené o 1. (Například z -2, -4, -6, -6, -4 vyber -6 a do pole dej -7. To jsme na tahu a dostáváme mat 3. tahem.) Poslední možností je, že mezi čísli je alespoň jedna 0 a zbytek jsou buď nuly nebo záporná čísla. V tom případě ještě nemůžeme rozhodnout a v poli necháme nulu.
 - Pokud jsme zapsali do pole alespoň jednu nenulu, pokračuj bodem 4.
 - Ulož pole tak, jak je, do souboru.

Máme-li vygenerovanou tabulku, je již velmi jednoduché napsat optimální algoritmus hry. Jedná se o prostý minimax do hloubky 1. Místo běžné ohodnocovací funkce se budeme dívat do tabulky. 0 znamená, že žádná ze stran nemůže vyhrát, tedy remíza. Kladná čísla jsou pozice vyhrané za bílého, čím dál od jedničky, tím dál od matu. Totéž platí s černým pro záporná čísla. V remízových pozicích pak můžeme spustit i klasický myslící algoritmus omezený na tahy, které nevedou k naší prohře. Jde jen o to, aby v remízových pozicích, kde ovšem o remízu bojuje soupeř, program nerezignoval na teoreticky marnou, ale prakticky proti reálnému soupeři často nadějnou snahu o výhru a nezahrál prostě jakýkoli neprohrávající tah. Například v těžké (pro 2 jezdce), ale remízové koncovce dámy proti dvěma jezdcům by program asi neměl nastavit dámu. To sice objektivně není chyba, neboť i koncovka krále a dvou jezdců proti samotnému králi je remízová, ale subjektivně to jistě chyba je a uživatel by to asi programu neodpustil.

Buhužel tento algoritmus není na současných počítačích dostatečně rychlý - na počkání získáme jen třífigurové koncovky, přes noc pak čtyřfigurové. Jednou z nejjednodušších a zároveň velmi účinných metod, jak výpočet zrychlit a zmenšit i objem vygenerovaných dat je využití nejrůznějších symetrií. 50% ušetříme, pokud jednotlivé koncovky budeme generovat jen pro jednu stranu tj. nikoliv celkem dvakrát: jednou pro bílého a jednou pro černého. Dále můžeme ušetřit překlápěním šachovnice. Pokud vyloučíme rošády, můžeme pozici ztotožnit s jejím osově souměrným obrazem, kdy osa vede mezi sloupci d a e. Generovat tedy budeme jen pozice, na nichž je bílý král na sloupcích a až d a jejich dvojčata budeme pomocí osové souměrnosti transformovat. V bezpěšcových koncovkách můžeme podobně překlápět i podle vodorovné osy mezi 4. a 5. řadou a dokonce i podle na hlavní diagonály a1 - h8. Bílý král tak bude vždy v trojúhelníku a1-d1-d4. Místo 64 možných polí tak zbude bílému králi pouze 10 polí, lze tedy očekávat díky osovým souměrnostem zhruba 6,4-násobné zrychlení a úsporu paměti při generování i při uložení výsledků.
V tabulce jakékoli koncovky se poměrně často a relativně pravidelně opakují číselné hodnoty. Je zřejmé, že data půjde úspěšně komprimovat téměř jakoukoli rozumnou metodou. Vzhledem ke způsobu využití je nutné, aby pro přečtení hodnoty z komprimované tabulky stačilo dekomprimovat jen nějaké malé okolí a nikoli celou tabulku.

\subsection{Reprezentace pozice}

Nejednoduší reprezentace šachovnice je dvourozměrné pole 8x8. To můžeme v případě potřeby rozvinout na jednorozměrné pole o 64 prvcích. Výhodou tohoto přístupu je snadnější čitelnost programu, nevýhodou je nutnost ošetřit možné přetečení pole. (Např. tah jezdce z okraje šachovnice mimo její okraj. Toto se dá řešit polem 10x12, potažmo jednorozměrným polem o 120 prvcích, což je vlastně klasická šachovnice 8x8 s mantinely.

Nejednodušší reprezentace šachových figur je celým číslem - kladným pro bílé, záporným pro černé. Prázdné pole je pak neutrální a má hodnotu 0, mantinely (jsou-li přítomny) mají nějakou konstatní hodnotu, která se neuvažuje pro výpočet.

Další možnou reprezentací šachovnice může být bitové pole. Nějaký jev na šachovici je pak reprezentován 64-bitovým číslem. Například výskyt bílých věží v základním postavení je pak reprezentován číslem 129 (00000000 00000000 00000000 00000000 00000000 00000000 00000000 10000001) Když budeme mít pro každý typ kamene jednu proměnnou, 12 proměnných může reprezentovat celou šachovnici. Výhodou tohoto přístupu jevelmi efektivní zpracování zejména na 64-bitové architektuře, kde je každá operace jedna velmi jednoduchá instrukce. Nevýhodou, je, že zejména pro začínající programátory může být tento přístup velmi matoucí a nečitelný.

\subsection{Reprezentace pole tahů}

Protože tahů bude v průběhu výpočtu generováno velmi mnoho, měl by být typ, reprezentující tah, velmi malý. Každopádně musí obsahovat minimálně položky odkud a kam. V případě reprezentace šachovnice dvourozměrným polem, budou položky odkud a kam reprezentovány dvouprvkovým polem - na indexu 0 bude sloupec, na indexu 1 řádek. V případě, že je šachovnice reprezentována jednorozměrným polem, položky odkud a kam jsou reprezentovány pouze celým číslem.

K uložení množiny tahů se běžně používá globální zásobník tahů, který může vypadat nějak takto:

Move moves[MANY]
int borders[DEPTH]
int index_in_stack

Tahy jsou uloženy v jediném globálním jednorozměrném poli, přičemž tahy z aktuálně propočítávané pozice mají index borders[index_in_stack] až borders[index_in_stack+1]-1. Konstanta DEPTH je nejvyšší možná hloubka zanoření rekurze. Na dnešních počítačích by mělo stačit 32. Velikost konstanty MANY pak půjde shora odhadnout jako součin maximálního počtu tahů z pozice * DEPTH. Program při tomto postupu sice může trochu plýtvat pamětí, ale achillovou patou šachových programů obvykle nebývá nedostatek paměti, nýbrž nedostatek času na dostatečně hluboký výpočet. Toto řešení ušetří cenné mikrosekundy, které by stálo dynamické přealokovávání pole v cyklu.

\subsection{Ohodnocovací funkce}

Šachový program provádí propočet do určité hloubky, na jehož konci zavolá ohodnocovací funkci, která vrátí cenu dané pozice. Nejednodušší a nejdůležitější je samozřejmě sečíst materiál. Cena jednotlivých figur se v různých programech liší. Pokud má pěšec cenu 1, bude cena jezdce a střelce přibližně 3, věže 5 a dámy 9. Někdy bývá hodnota střelce nepatrně vyšší než hodnota jezdce a podobně. Šachový program s ohodnocovací funkcí degenerovanou na prostý součet materiálu se pochopitelně bude chovat divně. Cesta i od velmi zjevné poziční chyby k matu je velmi dlouhá a přesahuje hloubku propočtu dnešních programů, takže prostý součet materiálu nestačí. Proto se přidává poziční složka.
Poziční složka bývá obyčejně velmi malá, jen zřídka v reálných partiích přesáhne v absolutní hodnotě cenu pěšce. Řada pozičních faktorů se dá ocenit statickou tabulkou pro jednotlivá políčka. Například poziční bonus pro figury blíže ke středu šachovnice (a tím i větším manévrovacím prostorem) bude vyšší než pro figury u kraje nebo v rohu šachovnice. Takovéto řešení poziční složky jistě nebude dokonalé, zato bude velmi rychlé. Poziční tabulku můžeme pro jednotlivé figury lehce upravit.
Pro pěšce existuje celá řada heuristik. Můžeme pozičně více ocenit pěšce, kteří jsou dále od výchozího postavení - to pěšce přiměje utíkat směrem k dámě. V základním postavení pak můžeme ocenit vyšší bonusem pěšce na vykročivší na středu. Dále můžeme ocenit je-li pěšec volný (žádná figura mu nebrání v běhu do dámy), či je-li krytý jiným pěšce. Rovněž mže dostat postih, je-li opožděný.
Jezdec stojí dobře v centru, v rohu se mu obvykle nedaří. Rovněž můžeme ocenit jezdce šikovně krytého pěšcem.
Pro střelce sice není poziční ohodnocení tak podstatné, přesto se o to můžeme pokusit. Dobře umístěný střelec by měl dostat bonus za soupeřovy pěšce na stejné barvě pole, které může napadat a naopak postih za pěšce, které napadat nemůže. Tím nám vyjde, že dva střelci budou mít spolu nepatrně vyšší hodnotu než je prostý součet jejich hodnot.
U věže nemá statická ohodnocovací tabulka smysl. Věž patří na volný sloupec, má tlačit na opožděné nebo nekryté pěšce a obě věže by se měly navzájem krýt.
U dámy je potřeba snad jen zabránit předčasnému vývinu - soupeř pak prostě napadá dámu s tempy běžnýc vývinových tahů lehčích figur.
U krále je v zahájení a střední hře důležitá především bezpečnost. Jde jednak o umístění, zachované právo rošády, pěšcový kryt krále a napadnutelnost polí v okolí. V koncovce se úloha krále radikálně mění a stává se z něj aktivně bojující figura, která musí opustit úkryt a bojovat o střed. V matové koncovce se pak král silnější strany snaží přiblížit soupeřovu  králi.
Ohodnocovací funkce napsaná pomocí statických tabulek je velmi rychlá, ale má jednu vážnou slabinu. Tabulky jsou napsány obecně, mohou tedy být dobré pro běžnou pozici, ale stačí několik netypických tahů a správné ohodnocení políček například pro jezdce může být úplně jiné. Řešením je místo samotného pole oceňovat pohyblivost figur, napadnutelná pole a tak podobně. To vše je ovšem za cenu vyšší časové náročnosti.

\section{Popis implementace}

Program je rozdělen na 4 moduly:
 - main.c s hlavičkovým souborem zcuchess.h obsahuje hlavní funkci a pomocné funkce pro správu paměti.
 - io.c s hlavičkovým soubrem io.h funkce pro vstupní a výstupní operace
 - chess.c s hlavičkovým souborem chess.h základní rutiny umožňující šachovou hru
 - ai.c s hlavičkovým souborem ai.h obsahuje umělou "inteligenci"

\subsection{Globální datové struktury}
 - int chessboard[8][8] - reprezentace šachovnice potažmo pozice.
 - bool castlings[4] - pole s příznaky rošád, které ještě můžeme provést (malá bílá, velká bílá, malá černá, velká černá).
 - int en_passant[2] - Udržujea aktuální pozici pěšce, kterého můžeme sebrat mimochodem. Na indexu 0 je sloupec, na indexu 1 je řádek
 - bool human_move - přiznak, zda-li je na tahu člověk.
 - int position_bonus[8][8] - tabulka s pozičními bonusy pro statickou ohodnocvací funkci.

\subsection{Reprezentace šachovnice, pozice a hodnot figur}
Pro názornost byla za reprezentaci šachovnice, potažmo pozic, zvolena matice 8x8. Bílé figury jsou reprezentovány celým kladným číslem následovně:
 - 1 Pěšec (konstanta PAWN), hodnota 100 (konstanta PAWN_VALUE)
 - 2 Věž (konstanta ROOK), hodnota 400 (konstanta ROOK_VALUE)
 - 3 Jezdec (konstanta KNIGHT), hodnota 300 (konstanta KNIGHT_VALUE)
 - 4 Střelec (konstanta BISHOP), hodnota 350 (konstanta BISHOP_VALUE)
 - 5 Dáma (konstanta QUEEN), hodnota 750 (konstanta QUEEN_VALUE)
 - 6 Král (konstanta KING)
Černé figury jsou reprezentovány stejně, akorát s opačním znaménkem. Číslo 0 (konstanta EMPTY) pak reprezentuje prázdné pole.

\subsection{Reprezentace tahu a množiny tahů}

Tah je reprezentovan datovou strukturou Move:
typedef struct {
  int from[2];	//na indexu 0 je sloupec odkud se táhne, na indexu 1 je řádek odkud se táhne
  int to[2];	//na indexu 0 je sloupec kam se táhne, na indexu 1 je řádek kam se táhne
  bool status;	//příznak je-li tah validní
} Move;

V programu jsou pro indexy polí from a to připraveny konstanty COL (sloupec, index 0) a ROW (řádek, index 1). V celém programu se pak tyto souřadnice používají konzistentně, tzn. vždy je sloupec první a řádek druhý.

Množina tahů se ukládá do struktury Moves:
typedef struct {
  int count;	//Počet tahů v množině
  Move *move;	//Pole tahů
} Moves;

\subsection{Statická ohodnocovací funkce}
Provádí prostý součet hodnoty materiálu a připočítává poziční bonus. Poziční bonus je reprezentován maticí 8x8 typu int a je pro všechny figury stejný. Vychází z myšlenky, že každá figura je užitečnější blíže ke středu šachovnice. 

\subsection{Myslící algoritmus}
Jako myslící algoritmus byl postupně použit minimax, alfabeta a nakonec velmi prostá implementace kaskádové metody. Všechny tyto algoritmy jsou popsány v části o analýze.

\section{Uživatelská příručka}

\subsection{Instalace}

Program zkompilujete prostým zadáním příkazu make v kořenovém adresáři projektu.

\subsection{Ovládání}

Program je konzolový, ovládá se tedy z klávesnice. Spustíme ho klasicky příkazem ./zcuchess (zcuchess.exe na platformě Windows). Program při spuštění vypíše hlavičku, jejíž součástí je i nápověda a čeká na zadání prvního tahu. Tah se zapsuje ve formátu odkud mezera kam, tedy např e2 e3. Poté program chvíli přemýšlí, načež vypíše svůj tah. Automaticky se předpokládá, že člověk hraje za bílého. Nápovědu je možno kdykoliv vypsat vepsánímklíčového slova help namísto tahu. Stejně tak je možné program kdykoliv ukončit vepsáním slova exit namísto tahu. Pokud nastane mat, program se ukončí sám.

\section{Závěr}
Program hraje šachy dostatečně dobře na to aby v nich porazil svého tvůrce, zadání semestrální práce proto považuji za splněné, i když k dobré hře má program stále ještě velice daleko.

\subsection{Problémy v průběhu psaní programu}
Při běhu programu docházelo ke značným únikům paměti, které se nakonec podařilo najít a vyřešit za pomoci programu valgrind.

\subsection{Možná vylepšení}
Podle profileru tráví program až čtvrtinu času ve funcki add_move (přidání tahu do množiny tahů). Toto by se dalo vyřešit globálním zásobníkem tahů. Protože je globální zásobník tahů statický, nebylo by zároveň potřeba řešit úniky paměti.
Dalším vylepšením zlepšující hloubku propočtu by bylo nsazení nějakých heuristik do generátoru tahů a třídění tahů pro průběhu kaskádové metody. V podstatě nasazení jakýchkoli heuristik uvedených u kaskádové metody v analýze.
Hru programu by samozřejmě zlepšila také implementace databáze zahájení a koncovek.
Dalším drobným zrychlením by bylo rozvinutí pole 8x8, reprezentujícího šachovnici, na jednorozměrné pole o 64 prvcích. Vůbec nejzajímavější by bylo použít reprezentaci v podobě bitové mapy, ale to by si vyžádalo několik měsíců studia.
Z uživateslkého hlediska by se jistě hodila možnost dát uživateli na výběr barvu strany, za kterou chce hrát, či možnost partii uložit do souboru a opětovně načíst.

Postupný vývoj programu a jeho zdrojové kódy si lze prohlédnout na adrese https://github.com/ClaryAldringen/ZCUChess.
\end{document}