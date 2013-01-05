<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"  
  "http://www.w3.org/TR/html4/loose.dtd">  
<html xml:lang="cs" > 
<head><title></title> 
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-2"> 
<meta name="generator" content="TeX4ht (http://www.cse.ohio-state.edu/~gurari/TeX4ht/)"> 
<meta name="originator" content="TeX4ht (http://www.cse.ohio-state.edu/~gurari/TeX4ht/)"> 
<!-- html --> 
<meta name="src" content="README.tex"> 
<meta name="date" content="2013-01-05 12:42:00"> 
<link rel="stylesheet" type="text/css" href="README.css"> 
</head><body 
>
<!--l. 11--><p class="noindent" >

<div class="center" 
>
<!--l. 12--><p class="noindent" >
<!--l. 13--><p class="noindent" ><img 
src="README0x.png" alt="PIC" class="graphics" width="284.52756pt" height="111.74744pt" ><!--tex4ht:graphics  
name="README0x.png" src="zculogo.ps"  
-->
<!--l. 15--><p class="noindent" ><span 
class="cmbx-12x-x-172">Semestr</span><span 
class="cmbx-12x-x-172">�ln</span><span 
class="cmbx-12x-x-172">� pr</span><span 
class="cmbx-12x-x-172">�ce z PC a PT</span><br />
<span 
class="cmr-12">Martin Zadra</span><span 
class="cmr-12">&#382;il</span><br />
<span 
class="cmr-12">5.</span><span 
class="cmr-12">&#x00A0;ledna 2013</span></div>

   <h3 class="likesectionHead"><a 
 id="x1-1000"></a>Obsah</h3>
   <div class="tableofcontents">
   <span class="sectionToc" >1 <a 
href="#x1-20001" id="QQ2-1-2">Zad�n�</a></span>
<br />   <span class="sectionToc" >2 <a 
href="#x1-30002" id="QQ2-1-3">Anal&#x00FD;za �lohy</a></span>
<br />   &#x00A0;<span class="subsectionToc" >2.1 <a 
href="#x1-40002.1" id="QQ2-1-4">Um&#x011B;l� inteligence a teorie &#353;achov� hry</a></span>
<br />   &#x00A0;&#x00A0;<span class="subsubsectionToc" >2.1.1 <a 
href="#x1-50002.1.1" id="QQ2-1-5">Od nejjednodu&#353;&#353;�ho algoritmu ke kask�dov� metod&#x011B;</a></span>
<br />   &#x00A0;&#x00A0;<span class="subsubsectionToc" >2.1.2 <a 
href="#x1-60002.1.2" id="QQ2-1-6">Zpomalen� je mal�</a></span>
<br />   &#x00A0;&#x00A0;<span class="subsubsectionToc" >2.1.3 <a 
href="#x1-70002.1.3" id="QQ2-1-7">Lep&#353;� &#x010D;asov� kontrola</a></span>
<br />   &#x00A0;&#x00A0;<span class="subsubsectionToc" >2.1.4 <a 
href="#x1-80002.1.4" id="QQ2-1-8">T&#x0159;�d&#x011B;n� tah&#x016F;</a></span>
<br />   &#x00A0;&#x00A0;<span class="subsubsectionToc" >2.1.5 <a 
href="#x1-90002.1.5" id="QQ2-1-9">Metoda ok�nka</a></span>
<br />   &#x00A0;&#x00A0;<span class="subsubsectionToc" >2.1.6 <a 
href="#x1-100002.1.6" id="QQ2-1-10">Prohlubov�n�</a></span>
<br />   &#x00A0;&#x00A0;<span class="subsubsectionToc" >2.1.7 <a 
href="#x1-110002.1.7" id="QQ2-1-11">Dopo&#x010D;et do tich� pozice</a></span>
<br />   &#x00A0;&#x00A0;<span class="subsubsectionToc" >2.1.8 <a 
href="#x1-120002.1.8" id="QQ2-1-12">Prohlubov�n� taktick&#x00FD;ch variant</a></span>
<br />   &#x00A0;&#x00A0;<span class="subsubsectionToc" >2.1.9 <a 
href="#x1-130002.1.9" id="QQ2-1-13">Ha&#353; tabulky</a></span>
<br />   &#x00A0;&#x00A0;<span class="subsubsectionToc" >2.1.10 <a 
href="#x1-140002.1.10" id="QQ2-1-14">Datab�ze zah�jen� a koncovek</a></span>
<br />   &#x00A0;<span class="subsectionToc" >2.2 <a 
href="#x1-150002.2" id="QQ2-1-15">Reprezentace pozice</a></span>
<br />   &#x00A0;<span class="subsectionToc" >2.3 <a 
href="#x1-160002.3" id="QQ2-1-16">Reprezentace pole tah&#x016F;</a></span>
<br />   &#x00A0;<span class="subsectionToc" >2.4 <a 
href="#x1-170002.4" id="QQ2-1-17">Ohodnocovac� funkce</a></span>
<br />   <span class="sectionToc" >3 <a 
href="#x1-180003" id="QQ2-1-18">Popis implementace</a></span>
<br />   &#x00A0;<span class="subsectionToc" >3.1 <a 
href="#x1-190003.1" id="QQ2-1-19">Glob�ln� datov� struktury</a></span>
<br />   &#x00A0;<span class="subsectionToc" >3.2 <a 
href="#x1-200003.2" id="QQ2-1-20">Reprezentace &#353;achovnice, pozice a hodnot figur</a></span>
<br />   &#x00A0;<span class="subsectionToc" >3.3 <a 
href="#x1-210003.3" id="QQ2-1-21">Reprezentace tahu a mno&#382;iny tah&#x016F;</a></span>
<br />   &#x00A0;<span class="subsectionToc" >3.4 <a 
href="#x1-220003.4" id="QQ2-1-22">Statick� ohodnocovac� funkce</a></span>
<br />   &#x00A0;<span class="subsectionToc" >3.5 <a 
href="#x1-230003.5" id="QQ2-1-23">Mysl�c� algoritmus</a></span>
<br />   <span class="sectionToc" >4 <a 
href="#x1-240004" id="QQ2-1-24">U&#382;ivatelsk� p&#x0159;�ru&#x010D;ka</a></span>
<br />   &#x00A0;<span class="subsectionToc" >4.1 <a 
href="#x1-250004.1" id="QQ2-1-25">Instalace</a></span>
<br />   &#x00A0;<span class="subsectionToc" >4.2 <a 
href="#x1-260004.2" id="QQ2-1-26">Ovl�d�n�</a></span>
<br />   <span class="sectionToc" >5 <a 
href="#x1-270005" id="QQ2-1-27">Z�v&#x011B;r</a></span>
<br />   &#x00A0;<span class="subsectionToc" >5.1 <a 
href="#x1-280005.1" id="QQ2-1-28">Probl�my v pr&#x016F;b&#x011B;hu psan� programu</a></span>
<br />   &#x00A0;<span class="subsectionToc" >5.2 <a 
href="#x1-290005.2" id="QQ2-1-29">Mo&#382;n� vylep&#353;en�</a></span>
   </div>

   <h3 class="sectionHead"><span class="titlemark">1   </span> <a 
 id="x1-20001"></a>Zad�n�</h3>
<!--l. 27--><p class="noindent" >Implementace jednoduch�ho &#353;achov�ho algoritmu, kter&#x00FD; umo&#382;&#x0148;uje hru hr�&#x010D;e proti po&#x010D;�ta&#x010D;i. Vstup
a v&#x00FD;stup bude prob�hat na p&#x0159;�kazov� &#x0159;�dce.
<!--l. 29--><p class="noindent" >
   <h3 class="sectionHead"><span class="titlemark">2   </span> <a 
 id="x1-30002"></a>Anal&#x00FD;za �lohy</h3>
<!--l. 31--><p class="noindent" >Nejprve je pot&#x0159;eba navrhnout z�kladn� datov� struktury a rutiny, kter� mus� obsahovat ka&#382;d&#x00FD;
&#353;achov&#x00FD; program i takov&#x00FD;, kter&#x00FD; neobsahuje &#382;�dn&#x00FD; mysl�c� algoritmus a umo&#382;&#x0148;uje nap&#x0159;�klad jen
hru dvou lidsk&#x00FD;ch hr�&#x010D;&#x016F; po s�ti. Pat&#x0159;� sem funkce pro
     <ul class="itemize1">
     <li class="itemize">Nalezen� v&#353;ech leg�ln�ch tah&#x016F; z dan� pozice
     </li>
     <li class="itemize">Kontrola &#353;achu a matu
     </li>
     <li class="itemize">Funkce kontroluj�c� dodr&#382;en� pravidel p&#x0159;i ro&#353;�d&#x011B; a bran� mimochodem
     </li>
     <li class="itemize">Funkce, kter� zahraje samotn&#x00FD; tah</li></ul>
<!--l. 38--><p class="noindent" >Bude n�sledovat um&#x011B;l� inteligence a chyb&#x011B;t nesm� ani n&#x011B;kolik m�lo funkc� pro komunikaci s okol�m,
jako je zparsov�n� tahu zadan�ho z kl�vesnice, vyps�n� tahu, upozorn&#x011B;n� na p&#x0159;em&#x00FD;&#353;len�
programu a podobn&#x011B;.
<!--l. 40--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">2.1   </span> <a 
 id="x1-40002.1"></a>Um&#x011B;l� inteligence a teorie &#353;achov� hry</h4>
<!--l. 42--><p class="noindent" >
   <h5 class="subsubsectionHead"><span class="titlemark">2.1.1   </span> <a 
 id="x1-50002.1.1"></a>Od nejjednodu&#353;&#353;�ho algoritmu ke kask�dov� metod&#x011B;</h5>
<!--l. 43--><p class="noindent" >&#352;achy jsou &#x010D;ist&#x011B; matematickou �lohou, k jej�mu&#382; vy&#x0159;e&#353;en� se d� v ka&#382;d�m p&#x0159;�pad&#x011B;
dopo&#x010D;�tat. Za vy&#x0159;e&#353;en� �lohy m&#x016F;&#382;eme pova&#382;ovat mat v p&#x0159;�pad&#x011B; vyhran� pozice, pat v
p&#x0159;�pad&#x011B; rem�zov� pozice nebo alespo&#x0148; co nejv&#x011B;t&#353;� oddalov�n� por�&#382;ky v p&#x0159;�pad&#x011B;
prohran� pozice. Kl�&#x010D;ovou funkc� je statick� ohodnocovac� funkce, kter� vr�t� &#x010D;�selnou
hodnotu dan� pozice. Nejednodu&#353;&#353;� algoritmus, kter&#x00FD; nehraje �pln&#x011B; n�hodn&#x011B;, vygeneruje
v&#353;echny tahy ze zadan� pozice, ka&#382;d&#x00FD; z nich zahraje a vzniklou pozici ohodnot� statickou
ohodnocovac� funkc�. Pokud je hodnota pozice vy&#353;&#353;� ne&#382; dosud nejvy&#353;&#353;�, ulo&#382;� ji i tah, kter&#x00FD;m
jsme se na ni dostali. Pot� zahraje tah zp&#x011B;t a tak d�le, dokud nevyzkou&#353;�me v&#353;echny
tahy. Tento algoritmus je sice lep&#353;� ne&#382; n�hodn� generov�n� tah&#x016F;, ale d�ru do sv&#x011B;ta
rozhodn&#x011B; neud&#x011B;l�. Sebere klidn&#x011B; d�mou kryt�ho p&#x011B;&#353;ce, nepokryje jednotahov&#x00FD; mat a
podobn&#x011B;.

<!--l. 45--><p class="indent" >   Vylep&#353;en�m je p&#x0159;idat rekurzi. Zahrajeme v&#353;echny tahy z dan� pozice, na tyto tahy zahrajeme
odpov&#x011B;&#x010F; soupe&#x0159;e, pak zase na&#353;� odpov&#x011B;&#x010F; a tak d�le a&#382; do n&#x011B;jak� hloubky n, kde zavol�me
statickou ohodnocovac� funkci. Tento algoritmus se jmenuje minimax. Na &#353;achovnici je v
z�kladn�m postaven� 16 p&#x011B;&#353;c&#x016F;, ka&#382;d&#x00FD; z nich m&#x016F;&#382;e t�hnout nejv&#x00FD;&#353;e &#353;estkr�t, pot� se prom&#x011B;n� v
n&#x011B;jakou figuru. Kdy&#382; nepo&#x010D;�t�me kr�le, kter� nen� mo&#382;n� sebrat, je na &#353;achovnici 30 figur a ka&#382;d�
z nich m&#x016F;&#382;e b&#x00FD;t sebr�na maxim�ln&#x011B; jednou. Pokud se b&#x011B;hem 50ti tah&#x016F; (50 tah&#x016F; b�l�ho a
50 tah&#x016F; &#x010D;ern�ho, celkem 100 p&#x016F;ltah&#x016F;) net�hne p&#x011B;&#353;cem ani nesebere &#382;�dn� figura, je
partie pova&#382;ovan� za rem�zu. D�ky tomu m&#x016F;&#382;eme shora odhadnout hloubku &#353;achov�
partie na (16 * 6 + 30 + 1) * 100 = 12700 p&#x016F;ltah&#x016F;. Algoritmus minimax s hloubkou
propo&#x010D;tu 12700 bude teoreticky hr�t &#353;achy �pln&#x011B; dokonale, alespo&#x0148; v tom smyslu, &#382;e
&#382;�dnou rem�zovou pozici neprohraje, ka&#382;dou vyhranou pozici nejen vyhraje, ale dokonce
t�m nejrychlej&#353;�m zp&#x016F;sobem a p&#x0159;i prohran� pozici bude por�&#382;ku alespo&#x0148; maxim�ln&#x011B;
oddalovat.
<!--l. 47--><p class="indent" >   Pam&#x011B;&#x0165;ov� slo&#382;itost minimaxu nen� p&#x0159;�li&#353; velk�, nebo&#x0165; v z�sobn�ku rekurzivn�ho propo&#x010D;tu je
v danou chv�li pouze jedna varianta. Kdyby se tedy minimaxu opravdu poda&#x0159;ilo nal�zt variantu
dlouhou 12 700 p&#x016F;ltah&#x016F; a jedna instance minimaxu zabrala 1 kB, ve&#353;li bychom se i s volaj�c�m
k�dem pohodln&#x011B; do 13 MB. Na propo&#x010D;et stromu tak bohat� hry, jakou &#353;achy bezesporu jsou, n�m
tedy sta&#x010D;� pouze p�r megabajt&#x016F; opera&#x010D;n� pam&#x011B;ti. Bohu&#382;el &#x010D;asov� slo&#382;itost minimaxu je
exponenci�ln� <span 
class="cmmi-10x-x-109">v</span><sup><span 
class="cmmi-8">h</span></sup>
, kde v je v&#x011B;tv�c� faktor a h hloubka propo&#x010D;tu. P&#x0159;edpokl�dejme, &#382;e z pozice m&#x016F;&#382;eme vygenerovat
20 tah&#x016F; (nap&#x0159;�klad z v&#x00FD;choz�ho postaven� 16 tah&#x016F; p&#x011B;&#353;ci, 4 tahy jezdci) a &#382;e dok�&#382;eme spo&#x010D;�tat
milion ohodnocovac�ch funkc� za sekundu. Propo&#x010D;et do hloubky 2 pak potrv� 0,008 sekundy,
propo&#x010D;et do hloubky 5 3,2 sekundy, propo&#x010D;et do hloubky 10 zhruba 118 a p&#x016F;l dne. P&#x0159;i hloubce 12
700 by to pak bylo 3<span 
class="cmmi-10x-x-109">,</span>81 <span 
class="cmsy-10x-x-109">* </span>10<sup><span 
class="cmr-8">1</span></sup>6509
let, konce v&#x00FD;po&#x010D;tu by se tedy nejsp�&#353; nedo&#x010D;kala ani na&#353;e galaxie.
<!--l. 49--><p class="indent" >   &#x010C;asovou slo&#382;itost m&#x016F;&#382;eme zlep&#353;it. Pot&#x0159;ebujeme-li zmen&#353;it v&#x00FD;sledek vzorce <span 
class="cmmi-10x-x-109">v</span><sup><span 
class="cmmi-8">h</span></sup>
, m&#x016F;&#382;eme zmen&#353;ovat h, co&#382; je hloubka propo&#x010D;tu a na kvalitu hry m� z�sadn� vliv. Druhou
mo&#382;nost� je zmen&#353;it v, co&#382; je v&#x011B;tv�c� faktor a n&#x011B;kter� varianty v&#x016F;bec nepo&#x010D;�tat. I p&#x0159;esto se
m&#x016F;&#382;eme dostat ke spr�vn�mu v&#x00FD;sledku.
<div class="center" 
>
<!--l. 51--><p class="noindent" >

<!--l. 52--><p class="noindent" ><img 
src="README1x.png" alt="PIC" class="graphics" width="227.62447pt" height="227.61694pt" ><!--tex4ht:graphics  
name="README1x.png" src="diagram1.ps"  
--></div>
<!--l. 55--><p class="indent" >   V pozici na diagramu je na tahu b�l&#x00FD;, jedn� se o zn�mou pozici ze zah�jen� jm�nem &#353;pan&#x011B;lsk�
hra (1. e4 e5 2. Jf3 Jc6 3. Sb5), kde se &#x010D;ern&#x00FD; br�n� obvykl&#x00FD;m tahem 3. ...a6. Napadl
tedy b�l�mu st&#x0159;elce a ten mus� hrozbu n&#x011B;jak pokr&#x00FD;t. B&#x011B;&#382;n� tahy jsou nyn� 4. Sa4 a
Sxc6, hr�t by se dalo i Sc4 a snad je&#353;t&#x011B; hodn&#x011B; def�tistick� Se2, v&#353;echny ostatn� tahy
jsou ji&#382; vylo&#382;en&#x011B; &#353;patn�. Z t�to pozice d�me programu za �kol prov�st propo&#x010D;et do
hloubky 2 p&#x016F;ltahy. Vygeneruje tahy a zkou&#353;� jeden po druh�m zahr�t. Gener�tor tah&#x016F; je
lehce modifikovan&#x00FD;, tak aby vracel bran� p&#x0159;ed ostatn�mi tahy. Program tedy nejprve
propo&#x010D;�t� 4. Sxc6, projde v&#353;echny odpov&#x011B;di &#x010D;ern�ho a zjist�, &#382;e po nejlep&#353;�m 4. ...dxc6 je
pozice p&#x0159;ibli&#382;n&#x011B; vyrovnan�. B�l&#x00FD; sice ztratil v&#x00FD;hodu dvojice st&#x0159;elc&#x016F;, ale zase &#x010D;ern�mu
znehodnotil p&#x011B;&#353;covou strukturu. Ohodnocen� prvn�ho tahu zat�m prob&#x011B;hlo tak, jako
v algoritmu minimax. Rozd�l nastane a&#382; u druh�ho tahu b�l�ho 4. Sxa6. Jedn� se o
zjevnou chybu, kterou b�l&#x00FD; odevzd�v� st&#x0159;elce za pouh�ho p&#x011B;&#353;ce, ale minimax by musel
proj�t v&#353;echny odpov&#x011B;di, aby si to uv&#x011B;domil. Tedy poctiv&#x011B; po&#x010D;�tat a ohodnocovat nejen
4. ...bxa6 a Vxa6, ale i zcela nesmysln� tahy jako 4. ...Jh6 nebo g5. Modifikovan�mu
algoritmu sta&#x010D;� jedin�: 4. ...Vxa6 nebo bxa6. Nav�c gener�tor tah&#x016F;, kter&#x00FD; preferuje bran�,
vr�t� jeden z uveden&#x00FD;ch tah&#x016F; hned jako prvn�. Jak program pozn�, &#382;e m&#x016F;&#382;e propo&#x010D;et
odpov&#x011B;d� na 4. Sxa6 p&#x0159;eru&#353;it a prohl�sit tah za neperspektivn�? Z propo&#x010D;tu 4. Sxc6 si
zapamatoval hodnotu nejlep&#353;� odpov&#x011B;di 4. ...dxc6, tedy zhruba 0 tj. vyrovnanou pozici. P&#x0159;i
propo&#x010D;tu dal&#353;�ch tah&#x016F; (4. Sxa6) uvedenou hodnotu pou&#382;ijeme jako pr�h. Pokud jej jak�koli
odpov&#x011B;&#x010F; (4. ...bxa6 nebo Vxa6) p&#x0159;es�hne, propo&#x010D;et tahu (4. Sxa6) ukon&#x010D;�me, nebo&#x0165; ji&#382;
v�me, &#382;e je &#353;patn&#x00FD;. Jin&#x00FD;mi slovy: pokud v�me, &#382;e tah je &#353;patn&#x00FD; (= hor&#353;� ne&#382; n&#x011B;jak&#x00FD;
jin&#x00FD; - zde 4. Sxc6), nem� smysl d�le zkoumat, jestli nen� n�hodou je&#353;t&#x011B; o n&#x011B;co hor&#353;�,
ne&#382; jsme zat�m zjistili. Pokud po&#x010D;�t�me do hloubky 3 a v�ce, dojde p&#x0159;i pro&#x0159;ez�v�n�
na oba hr�&#x010D;e a jsou zde proto meze pro ob&#x011B; strany. Doln� se &#x0159;�k� alfa, horn� beta,
odtud tak� n�zev algoritmu alfabeta metoda (nebo alfabeta o&#x0159;ez�v�n�). Pokud b&#x011B;hem
propo&#x010D;tu naraz�me na variantu, kter� je hor&#353;� ne&#382; alfa, m&#x016F;&#382;eme ji zahodit. Vyjde-li
n�m varianta lep&#353;� ne&#382; beta, m&#x016F;&#382;e se j� zase vyhnout soupe&#x0159; a zahr�t tah, kter&#x00FD; je
lep&#353;� pro n&#x011B;j. &#x010C;asov� slo&#382;itost alfabety siln&#x011B; z�vis� na po&#x0159;ad� tah&#x016F;, co&#382; ovliv&#x0148;uje, jak
rychle se n�m poda&#x0159;� sev&#x0159;�t meze alfa a beta. &#x010C;asov� slo&#382;itost optim�ln� alfabety je

<span 
class="cmmi-10x-x-109">v</span><sup><span 
class="cmmi-8">h&#x2215;</span><span 
class="cmr-8">2</span></sup>
, m&#x016F;&#382;eme se s n� tedy za stejn&#x00FD; &#x010D;as dostat dvakr�t hloub&#x011B;ji ne&#382; s minimaxem. Je tedy &#382;�douc�
aby nejnad&#x011B;jn&#x011B;j&#353;� varianty po&#x010D;�tal algoritmus jako prvn�. Existuje n&#x011B;kolik heuristik, jak
odhadnout u&#382; v gener�toru tah&#x016F;, kter� varianty by mohly b&#x00FD;t nejlep&#353;�:
     <ul class="itemize1">
     <li class="itemize">Se&#382;er co m&#x016F;&#382;e&#353;: Zp&#x016F;sob�-li tah zm&#x011B;nu materi�lu, posuneme ho na v�ce dop&#x0159;edu.
     Preferovat m&#x016F;&#382;eme rovn&#x011B;&#382; bran� ni&#382;&#353;� figurou.
     </li>
     <li class="itemize">Historick� heuristika je zalo&#382;ena na my&#353;lence, &#382;e pokud byl tah dobr&#x00FD; v jedn� variant&#x011B;,
     nejsp�&#353; bude dobr&#x00FD; i v jin�. T&#x0159;i typy t�to metody mohou b&#x00FD;t:
     </li>
     <li class="itemize">Glob�ln� tabulka tah&#x016F;: Program si mus� n&#x011B;jak pamatovat tahy. Informace odkud a
     kam se t�hne, p&#x0159;�padn&#x011B; typ nov� figury po prom&#x011B;n&#x011B; p&#x011B;&#353;ce se p&#x0159;i tro&#353;e snahy vejde
     do 16 bit&#x016F;. Vytvo&#x0159;�me si tedy pole velikosti 216, pro ka&#382;d&#x00FD; mo&#382;n&#x00FD; tah jeden byte.
     Na po&#x010D;�tku propo&#x010D;tu pole obsahuje sam� nuly. Kdy&#382; se n&#x011B;jak&#x00FD; tah uk�&#382;e jako dobr&#x00FD;
     (v&#x011B;t&#353;� ne&#382; aktu�ln� hodnota alfa). Zv&#x011B;t&#353;�m hodnotu jeho pol�&#x010D;ka v poli. Kdy&#382; potom
     po vygenerov�n� t&#x0159;�d�me tahy, uva&#382;ujeme je&#353;t&#x011B; tak� hodnotu t�to heuristiky. Jak
     p&#x0159;esn&#x011B; se maj� zv&#x011B;t&#353;ovat hodnoty v tabulce je slo&#382;it� ot�zka. Je z&#x0159;ejm�, &#382;e dobr� tahy
     z pozic vzd�len&#x011B;j&#353;�ch od ko&#x0159;ene maj� men&#353;� v&#x00FD;znam ne&#382; dobr� tahy z pozic bl�zk&#x00FD;ch
     ko&#x0159;eni. Je to t�m, &#382;e pr&#x016F;m&#x011B;rn� pozice z propo&#x010D;tu je bli&#382;&#353;� ko&#x0159;eni ne&#382; n&#x011B;jak�mu listu
     ze vzd�len� v&#x011B;tve.
     </li>
     <li class="itemize">Nejlep&#353;�  tahy  pro  danou  hloubku:  Pro  ka&#382;dou  hloubku  zano&#x0159;en�  v  propo&#x010D;tu  si
     zapamatujeme  posledn�  dva  zlep&#353;uj�c�  tahy.  Tyto  tahy  dostanou  p&#x0159;i  propo&#x010D;tu  v
     tomto zano&#x0159;en� speci�ln� bonus. Oproti glob�ln� tabulce m� metoda tu v&#x00FD;hodu, &#382;e
     se v�ce t&#x00FD;k� aktu�ln� pozice a p&#x0159;�slu&#353;n� hloubky, chov� se tedy lok�ln&#x011B;. T�m p�dem
     v&#x011B;t&#353;inou preferuje zlep&#353;uj�c� tahy z bl�zk&#x00FD;ch uzl&#x016F; a u nich je opravdu dost velk�
     pravd&#x011B;podobnost, &#382;e budou dobr� i v po&#x010D;�tan� pozici. Nev&#x00FD;hodou je, &#382;e ohodnocuje
     jen relativn&#x011B; m�lo tah&#x016F; (p&#x0159;esn&#x011B; 2).
     </li>
     <li class="itemize">Hlavn� varianta: Program si uchov�v� v tabulce dosavadn� hlavn� variantu, tedy v&#x011B;tev
     v&#x00FD;po&#x010D;tu p&#x0159;i optim�ln� h&#x0159;e (optim�ln� ve smyslu ohodnoceni list&#x016F;) obou hr�&#x010D;&#x016F;. Tah,
     kter&#x00FD; p&#x0159;�slu&#353;� k hlavn� variant&#x011B; bude z&#x0159;ejm&#x011B; dobr&#x00FD; i v cel� &#x0159;ad&#x011B; jin&#x00FD;ch variant, a proto
     z�sk�v� bonus. Varianty se ukl�daj� do matice, vyu&#382;�v� se ale jen horn� troj�heln�k.
     V jednom pol�&#x010D;ku matice je jeden tah. Jsme-li p&#x0159;i propo&#x010D;tu v n&#x011B;jak�m uzlu, po&#x010D;�t�me
     v tomto okam&#382;iku vlastn&#x011B; hodnotu v&#353;ech pozic na cest&#x011B; z ko&#x0159;ene do na&#353;eho uzlu. V
     i-t�m &#x0159;�dku (od diagon�ly d�l) si uchov�v�me nejlep&#353;� dosavadn� variantu z i-t� pozice
     na cest&#x011B; od ko&#x0159;ene. Dejme tomu, &#382;e v hloubce i do&#353;lo k nalezen� zlep&#353;uj�c�ho tahu.
     V &#x0159;�dku i m�me p&#x016F;vodn� nejlep&#353;� variantu (od na&#353;� pozice d�l) a v &#x0159;�dku i+1 je
     zlep&#353;uj�c� varianta.. Za t�to situace mus�me zkop�rovat i+1-n� &#x0159;�dek na pozici i-t�ho
     (z n&#x011B;j z&#x016F;stane jen prvn� tah na diagon�le).</li></ul>
<!--l. 64--><p class="noindent" >Nev&#x00FD;hodou alfabety je jej� pevn� hloubka. Jsme-li v zah�jen� nebo st&#x0159;edn� h&#x0159;e, bude tah&#x016F; k
ohodnocen� velmi mnoho. Hloubka v&#x00FD;po&#x010D;tu v t�to &#x010D;�sti hry by tedy nem&#x011B;la b&#x00FD;t p&#x0159;�li&#353; vysok�,

jinak se k v&#x00FD;sledku nedopo&#x010D;�t�me v rozumn�m &#x010D;ase. Naopak v koncovce, kdy je pouze p�r
p&#x0159;�pustn&#x00FD;ch tah&#x016F; lze hloubku propo&#x010D;tu zv&#x00FD;&#353;it. Tento probl�m &#x0159;e&#353;� kask�dov� metoda. Jedn� se
vlastn&#x011B; o alfabeta metodu, kter� postupn&#x011B; po&#x010D;�t� do hloubky 1,2,3,...,n. Na prvn� pohled se
m&#x016F;&#382;e zd�t zbyte&#x010D;n� po&#x010D;�tat poka&#382;d� znovu, nicm�n&#x011B; kask�dov� metoda m� n&#x011B;kolik
v&#x00FD;hod:
<!--l. 67--><p class="noindent" >
   <h5 class="subsubsectionHead"><span class="titlemark">2.1.2   </span> <a 
 id="x1-60002.1.2"></a>Zpomalen� je mal�</h5>
<!--l. 69--><p class="noindent" >Proto&#382;e je slo&#382;itost alfabety exponenci�ln�, zpomal� kask�dov� metoda program cca
jeden a p&#x016F;l kr�t. Dejme tomu, &#382;e pr&#x016F;m&#x011B;rn&#x00FD; v&#x011B;tv�c� faktor &#353;achu je 38, p&#x0159;i dobr�m
alfabeta o&#x0159;ez�v�n� se dostaneme na v&#x011B;tv�c� faktor zhruba odmocnina z 38, dejme tomu 7.
!7<sup><span 
class="cmmi-8">n</span><span 
class="cmsy-8">-</span><span 
class="cmr-8">1</span></sup>
je zhruba o &#x0159;�d men&#353;� ne&#382; 7<sup><span 
class="cmmi-8">n</span></sup>
.
<!--l. 71--><p class="noindent" >
   <h5 class="subsubsectionHead"><span class="titlemark">2.1.3   </span> <a 
 id="x1-70002.1.3"></a>Lep&#353;� &#x010D;asov� kontrola</h5>
<!--l. 73--><p class="noindent" >V praxi obvykle nezn� zad�n� <sub>&#8221;</sub>=ldej mi nejlep&#353;� tah do hloubky 5&#8220;, ale <sub>&#8221;</sub>=ldej mi nejlep&#353;� tah,
m�&#353; na to 5 sekund&#8220;. Potom je velmi obt�&#382;n� stanovit hloubku propo&#x010D;tu, kter� dos�hneme v
dan�m &#x010D;ase. U kask�dov� metody prost&#x011B; prov�d�me iterace tak dlouho, dokud m�me &#x010D;as. To n�m
pr�v&#x011B; umo&#382;n� v koncovce (p&#x0159;�padn&#x011B; kdykoliv, kdy&#382; je mno&#382;ina mo&#382;n&#x00FD;ch tah&#x016F; dostate&#x010D;n&#x011B; mal�)
po&#x010D;�tat do v&#x011B;t&#353;� hloubky.
<!--l. 75--><p class="noindent" >
   <h5 class="subsubsectionHead"><span class="titlemark">2.1.4   </span> <a 
 id="x1-80002.1.4"></a>T&#x0159;�d&#x011B;n� tah&#x016F;</h5>
<!--l. 77--><p class="noindent" >Kask�dov� metoda poskytuje lep&#353;� mo&#382;nosti t&#x0159;�d&#x011B;n� tah&#x016F;. Propo&#x010D;et do hloubky 1 za&#x010D;neme s
tahy set&#x0159;�d&#x011B;n&#x00FD;mi podle jednoduch&#x00FD;ch heuristik v gener�toru tah&#x016F;. Nejlep&#353;� tah pot� p&#x0159;em�st�me
na za&#x010D;�tek, pokra&#x010D;ujeme propo&#x010D;tem do hloubky 2, nejlep&#353;� taj z hloubky 2 op&#x011B;t p&#x0159;em�st�me na
za&#x010D;�tek a tak d�le. T�m se n�m poda&#x0159;� velmi rychle sev&#x0159;�t interval alfa a beta okolo
nejnad&#x011B;jn&#x011B;j&#353;�ch tah&#x016F;, co&#382; kask�dovou metodu je&#353;t&#x011B; d�le zrychl�. P&#x0159;�pad&#x016F;, kdy zah�j�me
propo&#x010D;et n&#x011B;kolika &#353;patn&#x00FD;mi tahy bude velmi m�lo - obvykle se jedn� o pozice s mo&#382;nost� slo&#382;it�
ob&#x011B;ti nebo komplikovan�ho tahu.
<!--l. 79--><p class="noindent" >
   <h5 class="subsubsectionHead"><span class="titlemark">2.1.5   </span> <a 
 id="x1-90002.1.5"></a>Metoda ok�nka</h5>
<!--l. 81--><p class="noindent" >Alfabeta metoda sv�r� interval alfa a beta velmi defenzivn&#x011B; - tak aby se v&#382;dy dopo&#x010D;�tala ke
spr�vn�mu v&#x00FD;sledku. Cel&#x00FD; v&#x00FD;po&#x010D;et m&#x016F;&#382;eme zrychlit t�m, &#382;e meze alfa a beta je&#353;t&#x011B; v�ce sev&#x0159;eme -
vytvo&#x0159;�me interval alfa2 a beta2, kter&#x00FD; bude podmno&#382;inou p&#x016F;vodn�ho alfa a beta.
Pokud jsme m&#x011B;li pravdu, u&#353;et&#x0159;ili jsme na v&#x00FD;po&#x010D;tu n&#x011B;jak&#x00FD; &#x010D;as, pokud ne, interval prost&#x011B;
p&#x0159;ete&#x010D;e a v n�sleduj�c� iteraci kask�dov� metody se po&#x010D;�t� interval s ji&#382; opraven&#x00FD;mi
mezemi.

<!--l. 83--><p class="noindent" >
   <h5 class="subsubsectionHead"><span class="titlemark">2.1.6   </span> <a 
 id="x1-100002.1.6"></a>Prohlubov�n�</h5>
<!--l. 85--><p class="noindent" >Hern� algoritmus po&#x010D;�t� do n&#x011B;jak� hloubky, na jej�m&#382; konci ohodnot� pozici statickou
ohodnocovac� funkc�. Tento postup dob&#x0159;e funguje v b&#x011B;&#382;n&#x00FD;ch pozic�ch, ale v taktick&#x00FD;ch pozic�ch
(jako je v&#x00FD;m&#x011B;na t&#x011B;&#382;k&#x00FD;ch figur, pozice tah p&#x0159;ed matem, kdy v�t&#x011B;zn� strana ob&#x011B;tovala materi�l,
atp.) selh�v�. P&#x0159;itom by zde sta&#x010D;ila o n&#x011B;co m�lo v&#x011B;t&#353;� hloubka propo&#x010D;tu a program by
hrozby v&#x010D;as vid&#x011B;l. Celkovou hloubku propo&#x010D;tu nem&#x016F;&#382;eme p&#x0159;�li&#353; zvy&#353;ovat - program
by se nedopo&#x010D;�tal. &#x0158;e&#353;en�m je tedy prohlouben� t&#x011B;ch variant, kter� jsou obzvl�&#353;t&#x011B;
zaj�mav�.
<!--l. 87--><p class="noindent" >
   <h5 class="subsubsectionHead"><span class="titlemark">2.1.7   </span> <a 
 id="x1-110002.1.7"></a>Dopo&#x010D;et do tich� pozice</h5>
<!--l. 89--><p class="noindent" >Dopo&#x010D;et do tich� pozice pat&#x0159;� v &#353;achu k nejjednodu&#353;&#353;�m a z�rove&#x0148; nejd&#x016F;le&#382;it&#x011B;j&#353;�m vylep&#353;en�m
alfabeta metody. Na �rove&#x0148; hry programu m� zcela z�sadn� vliv. Spo&#x010D;�v� v tom, &#382;e pokud se v
propo&#x010D;tu dostaneme do listu, neodhadujeme hodnotu pozice statickou ohodnocovac� funkc�, ale
jakousi modifikac� alfabety, kter� se li&#353;� t�m &#382;e bere v �vahu pouze bran� a prom&#x011B;ny p&#x011B;&#353;ce.
Vzhledem k tomu, &#382;e hr�&#x010D;i odep�r�me v&#353;echny ostatn� tahy (tzv. tich� tahy), mus�me mu
umo&#382;nit nehr�t, jinak bychom jej nutili i do nev&#x00FD;hodn&#x00FD;ch bran�. Funkce tedy vrac� maximum z
hodnoty pozice odhadnut� statickou ohodnocovac� funkc� a rekurzivn�ho dopo&#x010D;tu bran�. Pr�v&#x011B;
dopo&#x010D;et do tich� pozice &#x0159;e&#353;� p&#x0159;�pady nedopo&#x010D;�tan&#x00FD;ch v&#x00FD;m&#x011B;n. Dopo&#x010D;et samoz&#x0159;ejm&#x011B; hodn&#x011B;
zdr&#382;uje a sn�&#382;� z�kladn� hloubku propo&#x010D;tu, ale pozitivn� efekt je i tak obrovsk&#x00FD;. Dopo&#x010D;et do
tich� pozice m� nav�c kladn&#x00FD; vliv i na stabilitu v&#x00FD;po&#x010D;tu - ji&#382; se n�m nestane p&#x0159;�li&#353;
&#x010D;asto, &#382;e by zv&#x00FD;&#353;en� z�kladn� hloubky propo&#x010D;tu m&#x011B;lo n&#x011B;jak&#x00FD; z�sadn� vliv na hodnotu
varianty.
<!--l. 91--><p class="noindent" >
   <h5 class="subsubsectionHead"><span class="titlemark">2.1.8   </span> <a 
 id="x1-120002.1.8"></a>Prohlubov�n� taktick&#x00FD;ch variant</h5>
<!--l. 93--><p class="noindent" >Dopo&#x010D;et do tich� pozice je �&#x010D;inn&#x00FD;, ale ne&#x0159;e&#353;� v&#353;e. Ve zvl�&#353;&#x0165; nad&#x011B;jn&#x00FD;ch variant�ch b&#x00FD;v� dobr�
hloubku propo&#x010D;tu o jedni&#x010D;ku zv&#x00FD;&#353;it a nemus� se p&#x0159;i tom nutn&#x011B; jednat o bran� nebo
prom&#x011B;ny p&#x011B;&#353;ce. K prohlouben� tak� nemus� dojit jen v listu. Kdy p&#x0159;esn&#x011B; m� smysl
prohlubovat je slo&#382;it� ot�zka. Za typick� kandid�ty na prohlouben� m&#x016F;&#382;eme ozna&#x010D;it
tahy
     <ul class="itemize1">
     <li class="itemize">Kdy je sebran� figura, kter� v minul�m tahu sama brala (m&#x016F;&#382;e se jednat o dokon&#x010D;en�
     v&#x00FD;m&#x011B;ny)
     </li>
     <li class="itemize">Pokryt�  &#353;achu  p&#x0159;edstaven�m  (m&#x016F;&#382;e  b&#x00FD;t  jen  odd�len�m  matu  skr&#x00FD;vaj�c�ho  se  za
     horizontem propo&#x010D;tu)
     </li>
     <li class="itemize">Jak�koliv varianty s vynucen&#x00FD;mi tahy
     </li>
     <li class="itemize">Vidle p&#x011B;&#353;cem i jezdcem a podobn� taktick� �dery

     </li>
     <li class="itemize">Varianty s tzv. Fisherov&#x00FD;m st&#x0159;elcem
     </li>
     <li class="itemize">Taktick� hrozby kr�li</li></ul>
<!--l. 102--><p class="noindent" >P&#x0159;i prohlubov�n� je pot&#x0159;eba postupovat velmi obez&#x0159;etn&#x011B;, nebo&#x0165; prohlouben� jedn� varianty zkr�t�
v&#x00FD;po&#x010D;etn� &#x010D;as ostatn�ch variant.
<!--l. 104--><p class="noindent" >
   <h5 class="subsubsectionHead"><span class="titlemark">2.1.9   </span> <a 
 id="x1-130002.1.9"></a>Ha&#353; tabulky</h5>
<!--l. 106--><p class="noindent" >Dote&#x010F; jsme se sna&#382;ili zrychlit v&#x00FD;po&#x010D;et pomoc� o&#x0159;ez�v�n� a sv�rali jsme interval alfa a beta jak to
jen &#353;lo, abychom od&#x0159;�zli co nejvy&#353;&#353;� po&#x010D;et variant, kter� nem� cenu po&#x010D;�tat. Existuje v&#353;ak je&#353;t&#x011B;
jeden druh variant, kter� rovn&#x011B;&#382; nemus�me po&#x010D;�tat. Jde o dvojce variant, kter� se od
sebe li&#353;� pouh&#x00FD;m prohozen�m tah&#x016F;. Pokud program po&#x010D;�t� do hloubky 5 p&#x016F;ltah&#x016F; ze
z�kladn�ho postaven�, nevynech� ani variantu b�l&#x00FD; p&#x011B;&#353;ec na e4, &#x010D;ern&#x00FD; p&#x011B;&#353;ec na c5 v prvn�m
tahu, b�l&#x00FD; jezdec na f3 v druh�m tahu a z t�to pozice pozice po&#x010D;�t� je&#353;t&#x011B; do zb&#x00FD;vaj�c�
hloubky 2 p&#x016F;ltahy. Ke stejn�mu v&#x00FD;sledku se v&#353;ak dostane i z pozice, kdy v prvn�m
tahu p&#x0159;ijde b�l&#x00FD; jezdec na f3 a &#x010D;ern&#x00FD; p&#x011B;&#353;ec na c5 a ve druh�m tahu b�l&#x00FD; p&#x011B;&#353;ec na e4.
N�sleduj�c� dva p&#x016F;ltahy se budou po&#x010D;�tat znovu. Je p&#x0159;itom z&#x0159;ejm�, &#382;e vzniklou pozici sta&#x010D;�
zkoumat jen jednou. V zah�jen� a st&#x0159;edn� h&#x0159;e s velk&#x00FD;m po&#x010D;tem figur a malou hloubkou
propo&#x010D;tu doch�z� k t&#x011B;mto duplicit�m je&#353;t&#x011B; pom&#x011B;rn&#x011B; z&#x0159;�dka. Mnohem hor&#353;� je situace v
koncovce s mal&#x00FD;m po&#x010D;tem figur. Typick&#x00FD;m p&#x0159;�kladem je koncovka dvou kr�l&#x016F;, v n�&#382;
maj� ob&#x011B; strany u&#382; jen n&#x011B;kolik zablokovan&#x00FD;ch p&#x011B;&#353;c&#x016F;. Kr�l se obvykle sna&#382;� vytla&#x010D;it
soupe&#x0159;ova monarchu (obvykle i s vyu&#382;it�m nev&#x00FD;hody tahu), pobrat soupe&#x0159;ovy p&#x011B;&#353;ce a
prosadit ty sv� do d�my. Ob&#x011B; strany p&#x0159;itom maj� na v&#x00FD;b&#x011B;r jen n&#x011B;kolik m�lo p&#x0159;�pustn&#x00FD;ch
tah&#x016F;, a tak hloubka propo&#x010D;tu roste oproti st&#x0159;edn� h&#x0159;e i dvojn�sobn&#x011B;. P&#x0159;i podobn&#x00FD;ch
hlubok&#x00FD;ch propo&#x010D;tech doch�z� k opakovan�mu vyhodnocov�n� jedn� varianty vznikl� jen
p&#x0159;ehozen�m tah&#x016F; zcela b&#x011B;&#382;n&#x011B;. Pr�v&#x011B; v podobn&#x00FD;ch typech pozic p&#x0159;itom m&#x016F;&#382;e m�t
po&#x010D;�ta&#x010D; s lidsk&#x00FD;m soupe&#x0159;em probl�my. Jednoduch&#x00FD; charakter pozice toti&#382; umo&#382;n� l�pe
oprostit pl�n v&#x00FD;hry nebo obrany od detailn�ho propo&#x010D;tu (p&#x0159;�padn&#x011B; lidsk&#x00FD; propo&#x010D;et
degeneruje na jedinou, ale zato dlouhou variantu bez v&#x011B;tven�) a umo&#382;n� vid&#x011B;t mnohem d�l i
&#x010D;lov&#x011B;ku.
<!--l. 109--><p class="indent" >   &#x0158;e&#353;en�m je m�t ha&#353; tabulku s v&#x00FD;sledky jednotliv&#x00FD;ch v&#x00FD;po&#x010D;t&#x016F;, do kter� se pod�v�me a pokud
zde v&#x00FD;sledek propo&#x010D;tu z na&#353;� pozice najdeme, okam&#382;it&#x011B; ho vr�t�me. Je pot&#x0159;eba d�t pozor na
n&#x011B;kolik v&#x011B;c�:
     <ul class="itemize1">
     <li class="itemize">Ukl�dat  je  pot&#x0159;eba  i  hloubku  propo&#x010D;tu,  nebo&#x0165;  nelze  nahradit  propo&#x010D;et  v&#x00FD;sledkem
     p&#x0159;edchoz�ho propo&#x010D;tu do men&#353;� hloubky.
     </li>
     <li class="itemize">Alfabeta ned�v� jen meziv&#x00FD;sledky typu pozice m� cenu = 3, ale i pozice m� cenu �= 3
     nebo pozice m� cenu =� 3. Tyto meziv&#x00FD;sledky je rovn&#x011B;&#382; pot&#x0159;eba ukl�dat.
     </li>
     <li class="itemize">Mus�me pracovat velmi rychle s velk&#x00FD;m mno&#382;stv�m dat.

     </li>
     <li class="itemize">Program by nem&#x011B;l &#x010D;�st z disku - struktura se mus� za ka&#382;dou cenu vej�t do pam&#x011B;ti.
     </li>
     <li class="itemize">Je lep&#353;�, kdy&#382; struktura zapom�n� ne&#382; aby swapovala
     </li>
     <li class="itemize">Pozice  obsahuje  64  pol�  a  stavovou  informaci  o  tahu,  pr�vu  na  ro&#353;�dy  a  bran�
     mimochodem, ale jeden z�znam ve struktu&#x0159;e by m&#x011B;l m�t Jen n&#x011B;kolik byt&#x016F;, proto
     vol�me ha&#353; tabulku.</li></ul>
<!--l. 119--><p class="indent" >   V t�to ha&#353; tabulce nemus�me &#x0159;e&#353;it kolize - nov� nebo cenn&#x011B;j&#353;� hodnota prost&#x011B; p&#x0159;ep�&#353;e starou.
Je to rychlej&#353;� a jednodu&#353;&#353;� ne&#382; na jednotliv&#x00FD;ch prvc�ch vytv�&#x0159;et spojov� seznamy a zab&#x00FD;vat se
alokov�n�m a uvol&#x0148;ov�n�m pam&#x011B;ti
     <ul class="itemize1">
     <li class="itemize">Je lep&#353;�, kdy&#382; struktura zapom�n� ne&#382; aby swapovala
     </li>
     <li class="itemize">Pozice  obsahuje  64  pol�  a  stavovou  informaci  o  tahu,  pr�vu  na  ro&#353;�dy  a  bran�
     mimochodem, ale jeden z�znam ve struktu&#x0159;e by m&#x011B;l m�t jen n&#x011B;kolik byt&#x016F;, proto vol�me
     ha&#353; tabulku.</li></ul>
<!--l. 125--><p class="indent" >   V t�to ha&#353; tabulce nemus�me &#x0159;e&#353;it kolize - nov� nebo cenn&#x011B;j&#353;� hodnota prost&#x011B; p&#x0159;ep�&#353;e starou.
Je to rychlej&#353;� a jednodu&#353;&#353;� ne&#382; na jednotliv&#x00FD;ch prvc�ch vytv�&#x0159;et spojov� seznamy a zab&#x00FD;vat se
alokov�n�m a uvol&#x0148;ov�n�m pam&#x011B;ti.
<!--l. 127--><p class="noindent" >
   <h5 class="subsubsectionHead"><span class="titlemark">2.1.10   </span> <a 
 id="x1-140002.1.10"></a>Datab�ze zah�jen� a koncovek</h5>
<!--l. 129--><p class="noindent" >Ka&#382;d� &#353;achov� partie za&#x010D;�n� v&#382;dy stejnou pozic�. Je celkem pochopiteln�, &#382;e &#353;achist� velmi
pe&#x010D;liv&#x011B; studuj� jednotliv� varianty vznikl� ze z�kladn�ho postaven� ji&#382; v klidu doma s
po&#x010D;�ta&#x010D;em nebo v klubu b&#x011B;hem tr�ninku a ne a&#382; v omezen�m &#x010D;ase b&#x011B;hem partie. O
konkr�tn�ch zah�jen�ch byly naps�ny stovky knih, v&#x011B;novali se jim ti nejlep&#353;� &#353;achist�
teoretici. B&#x011B;hem zah�jen� b&#x011B;&#382;n&#x011B; vznikaj� velmi komplikovan� pozice, ve kter&#x00FD;ch se
nevyznaj� ani velmist&#x0159;i, a mal� nen�padn� a t&#x011B;&#382;ko odhaliteln� chyba m&#x016F;&#382;e v�st k rychl�
proh&#x0159;e nebo alespo&#x0148; k v&#x00FD;hod&#x011B; soupe&#x0159;e. Rozmotat p&#x0159;�mo za &#353;achovnic� n&#x011B;kolik del&#353;�ch a
trochu rozv&#x011B;tven&#x00FD;ch vynucen&#x00FD;ch variant (kter� b&#x011B;hem des�tek let vymysleli &#353;achov�
teoretici) b&#x00FD;v� bez p&#x0159;edchoz� p&#x0159;�pravy nad s�ly i t&#x011B;ch nejlep&#353;�ch hr�&#x010D;&#x016F; a dne&#353;n�ch
program&#x016F;, ale nau&#x010D;it se &#x0159;e&#353;en� nazpam&#x011B;&#x0165; a pochopit ho se dok�&#382;e p&#x0159;i tro&#353;e snahy i
pr&#x016F;m&#x011B;rn&#x00FD; klubov&#x00FD; &#353;achista nebo t&#x0159;eba n�&#353; program. Program nau&#x010D;�me zah�jen� tak, &#382;e
n&#x011B;kam ulo&#382;�me pozice b&#x011B;&#382;n� v zah�jen� a/nebo jejich ha&#353; funkce a k nim sadu tah&#x016F;,
kter� od programu v uveden� pozici o&#x010D;ek�v�me. Ka&#382;d�mu tahu z�rove&#x0148; p&#x0159;i&#x0159;ad�me
pravd&#x011B;podobnost jeho zahr�n�. Nap&#x0159;�klad pro z�kladn� postaven� m&#x016F;&#382;e seznam vypadat
takto:
     <ul class="itemize1">
     <li class="itemize">30% 1. e4

     </li>
     <li class="itemize">30% 1. d4
     </li>
     <li class="itemize">15% 1. c4
     </li>
     <li class="itemize">13% 1. Jf3
     </li>
     <li class="itemize">5% 1. f4
     </li>
     <li class="itemize">2% 1. b3
     </li>
     <li class="itemize">1% 1. b4
     </li>
     <li class="itemize">1% 1. g3
     </li>
     <li class="itemize">1% 1. e3
     </li>
     <li class="itemize">1% 1. d3
     </li>
     <li class="itemize">1% 1. Jc3</li></ul>
<!--l. 145--><p class="indent" >   Nejv&#x011B;t&#353;� pravd&#x011B;podobnost budou m�t dobr� a obvykle hran� tahy, m�n&#x011B; b&#x011B;&#382;n&#x00FD;m a nep&#x0159;�li&#353;
ambici�zn�m tah&#x016F;m, kter� v&#353;ak pozici b�l�ho nijak neohro&#382;uj� d�me jen malou pravd&#x011B;podobnost
(hod� se ob&#x010D;as k vyprovokov�n� lidsk�ho soupe&#x0159;e) a tahy vylo&#382;en&#x011B; &#353;patn� jako nap&#x0159;�klad 1.f3?
nebo 1.h3? nebudeme uv�d&#x011B;t v&#x016F;bec, program je tedy nebude hr�t. Podobn&#x00FD; seznam
pravd&#x011B;podobnost� ohodnocen&#x00FD;ch tah&#x016F; budeme m�t pro ka&#382;dou nau&#x010D;enou pozici ulo&#382;en&#x00FD; v n&#x011B;jak�
datov� struktu&#x0159;e postaven� nad ha&#353;ovac� funkc� pozice. Tah&#x016F; z pozic je prom&#x011B;nliv�
mno&#382;stv�. Typick� vyhled�vac� datov� struktura proto nebude obsahovat p&#x0159;�mo tahy. M�sto
nich v n� budou indexy do pole tah&#x016F; zakon&#x010D;en� nulou. Uk�&#382;eme si to na p&#x0159;�kladu se
set&#x0159;�d&#x011B;n&#x00FD;m polem a ha&#353;ovac� funkc� kter� nen� na na&#353;� mno&#382;in&#x011B; ulo&#382;en&#x00FD;ch pozic
prost�. Obsahovat bude jen 3 pozice: z�kladn� postaven� (ha&#353; = 368) se t&#x0159;emi tahy 1. e4
(40
<!--l. 149--><p class="noindent" ><!--tex4ht:inline--><div class="tabular"> <table id="TBL-1" class="tabular" 
cellspacing="0" cellpadding="0" rules="groups" 
><colgroup id="TBL-1-1g"><col 
id="TBL-1-1"></colgroup><colgroup id="TBL-1-2g"><col 
id="TBL-1-2"></colgroup><colgroup id="TBL-1-3g"><col 
id="TBL-1-3"></colgroup><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-1-1-"><td  style="white-space:nowrap; text-align:left;" id="TBL-1-1-1"  
class="td11">ha&#353; 129, index 0</td><td  style="white-space:nowrap; text-align:left;" id="TBL-1-1-2"  
class="td11">ha&#353; 368, index 3  </td><td  style="white-space:nowrap; text-align:left;" id="TBL-1-1-3"  
class="td11">ha&#353; 368, index 5    </td>
</tr><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-1-2-"><td  style="white-space:nowrap; text-align:left;" id="TBL-1-2-1"  
class="td11">pozice po 1. e4   </td><td  style="white-space:nowrap; text-align:left;" id="TBL-1-2-2"  
class="td11">pozice po 1. e4 e5</td><td  style="white-space:nowrap; text-align:left;" id="TBL-1-2-3"  
class="td11">z�kladn� postaven�</td>
</tr><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-1-3-"><td  style="white-space:nowrap; text-align:left;" id="TBL-1-3-1"  
class="td11">              </td></tr></table>
</div>
<!--l. 159--><p class="indent" >   Takto by vypadala vyhled�vac� struktura. Pozice bychom si pamatovali nejsp�&#353; fyzicky
odd&#x011B;len&#x011B;, nap&#x0159;�klad na stejn�m indexu v jin�m poli, zde je proto m�me v druh�m &#x0159;�dku. Dejme
tomu, &#382;e hled�me tah ze z�kladn�ho postaven�. Spo&#x010D;�t�me si ha&#353;ovac� funkci 368. N&#x011B;jak&#x00FD;m
algoritmem pro vyhled�v�n� v set&#x0159;�d&#x011B;n�m poli s rovnom&#x011B;rn&#x00FD;m rozd&#x011B;len�m dat (logaritmicky
p&#x016F;len�m nebo je&#353;t&#x011B; l�pe d&#x011B;len�m podle hodnoty ha&#353; funkc�) najdeme pol�&#x010D;ko se spr�vnou

hodnotou ha&#353; funkce, dejme tomu, &#382;e m�me sm&#x016F;lu a bude to prost&#x0159;edn� pol�&#x010D;ko. Zjist�me, &#382;e
pozice nen� na&#353;e, nebo&#x0165; do&#353;lo ke kolizi ha&#353; funkc�. Koukneme se while cyklem doleva, tam u&#382; je
jin� hodnota ha&#353; funkce. Tak tedy doprava na posledn� pol�&#x010D;ko, zde odpov�d� ha&#353; funkce a i
pozice je spr�vn&#x011B;, budeme tedy hledat tahy na indexu 5 v poli tah&#x016F;. Tabulka tah&#x016F; pak m&#x016F;&#382;e
vypadat n&#x011B;jak takto:
<!--l. 161--><p class="indent" >   V poli od pozice 5 a&#382; k n�sleduj�c� nule jsou tahy e4, d4 a c4, vygenerujeme tedy n�hodn�
&#x010D;�slo z rozsahu 0 a&#382; 100, padne t&#x0159;eba 50 a program zahraje 1. d4.
<!--l. 163--><p class="indent" >   S ub&#x00FD;vaj�c�m po&#x010D;tem figur a bl�&#382;�c�m se koncem partie se pozice postupn&#x011B; zjednodu&#353;uje. P&#x0159;i
propo&#x010D;tu ub&#x00FD;v� mo&#382;n&#x00FD;ch variant, spousta z nich vede do stejn� pozice, jin� zase brzy kon&#x010D;� matem
nebo rem�zou. Program by m&#x011B;l tud�&#382; v jist� chv�li za&#x010D;�t po&#x010D;�tat dokonale. Pokud v&#353;ak zkus�me
standardn�mu prohled�vac�mu algoritmu p&#x0159;edlo&#382;it t&#x0159;eba n&#x011B;jakou pozici z koncovky st&#x0159;elce a
jezdce proti samotn�mu kr�li, kvalitn� program koncovku sice zvl�dne - zatla&#x010D;� soupe&#x0159;ova kr�le do
rohu barvy st&#x0159;elce a tam mu nasad� mat, ale rozhodn&#x011B; nenajde ten nejrychlej&#353;� postup
a maty t&#x0159;eba 20. tahem zd�lky prost&#x011B; neuvid�. V opravdu t&#x011B;&#382;k&#x00FD;ch koncovk�ch typu
d�ma proti dv&#x011B;ma lehk&#x00FD;m figur�m pak b&#x011B;&#382;n&#x00FD; kvalitn� mysl�c� algoritmus ji&#382; bude
chybovat a n&#x011B;kter� vyhran� pozice vyhr�t nedok�&#382;e. V omezen�m &#x010D;ase nen� mo&#382;n� ani v
pom&#x011B;rn&#x011B; jednoduch� koncovce proj�t cel&#x00FD; graf hry z ko&#x0159;ene k list&#x016F;m, d�ky koliz�m v
ha&#353;ovac� funkci nav�c budeme &#x0159;adu variant po&#x010D;�tat opakovan&#x011B;, tak&#382;e s dokonalou hrou
nem&#x016F;&#382;eme po&#x010D;�tat ani v element�rn� koncovce d�my proti samotn�mu kr�li. Na&#353;t&#x011B;st�
je to s pozicemi z koncovek podobn�, jako s t&#x011B;mi ze zah�jen�. Daj� se nau&#x010D;it. V&#353;ech
mo&#382;n&#x00FD;ch pozic n&#x011B;kolikafigurov� koncovky je sice z lidsk�ho pohledu mnoho, ale po&#x010D;�ta&#x010D; m�
posunut� m&#x011B;&#x0159;�tka. Jednoduch&#x00FD; horn� odhad pro po&#x010D;et pozic n-figurov� koncovky je
2 <span 
class="cmsy-10x-x-109">* </span>64<sup><span 
class="cmmi-8">n</span></sup>
, nebo&#x0165; ka&#382;d� figurka m&#x016F;&#382;e b&#x00FD;t na jednom ze 64 pol� a mo&#382;nosti se n�sob�. �vodn� dvojka je tam
kv&#x016F;li pr�vu tahu, bu&#x010F; hraje b�l&#x00FD; nebo &#x010D;ern&#x00FD;. N�&#353; odhad bychom mohli i zp&#x0159;esnit na 2 * 64 * 63 *
62 * ... * (64 - n + 1), proto&#382;e dv&#x011B; figurky nemohou b&#x00FD;t na stejn�m pol�&#x010D;ku, tak&#382;e 1.
figurka m� 64 mo&#382;nost�, druh� jen 63 atd. Mohli bychom tak� vy&#353;krtat nep&#x0159;�pustn�
pozice, ztoto&#382;nit stejn� figury atd., ale �vodn� vzorec n�m z�rove&#x0148; d�v� n�vod, jak
velmi jednodu&#353;e a efektivn&#x011B; ka&#382;d� pozici zkouman� koncovky p&#x0159;id&#x011B;lit &#x010D;�slo od 0 do
2 <span 
class="cmsy-10x-x-109">* </span>64<sup><span 
class="cmmi-8">n</span><span 
class="cmsy-8">-</span><span 
class="cmr-8">1</span></sup>
(jej� m�sto v tabulce p&#x0159;�slu&#353;n� koncovky) a naopak ke ka&#382;d�mu &#x010D;�slu z uveden�ho intervalu
p&#x0159;i&#x0159;adit pozici. Stanov�me si po&#x0159;ad� figur na&#353;� koncovky podle jejich barvy a materi�ln� hodnoty.
Nap&#x0159;�klad pro koncovku jezdce a st&#x0159;elce to m&#x016F;&#382;e b&#x00FD;t po&#x0159;ad� b�l&#x00FD; kr�l, b�l&#x00FD; st&#x0159;elec, b�l&#x00FD; jezdec,
&#x010D;ern&#x00FD; kr�l. O&#x010D;�slujeme pol�&#x010D;ka &#353;achovnice od 0 do 63, a1 bude 0, a2 1 atd., h8 bude 63.
M�me-li n jednozna&#x010D;n&#x011B; se&#x0159;azen&#x00FD;ch figur, ozna&#x010D;�me &#x010D;�sla pol�&#x010D;ek, na nich&#382; se nach�zej�
<span 
class="cmmi-10x-x-109">p</span><sub><span 
class="cmr-8">0</span></sub>
a&#382; <span 
class="cmmi-10x-x-109">p</span><sub><span 
class="cmmi-8">n</span><span 
class="cmsy-8">-</span><span 
class="cmr-8">1</span></sub>
. U koncovek s opakov�n�m jednoho druhu kamene (nap&#x0159;�klad koncovka kr�le proti dv&#x011B;ma
st&#x0159;elc&#x016F;m) budeme jako prvn� uva&#382;ovat figuru s vy&#353;&#353;�m indexem pol�&#x010D;ka. &#x010C;�slo pozice pak bude
<span 
class="cmmi-10x-x-109">p</span><sub><span 
class="cmr-8">0</span></sub> + 64 <span 
class="cmsy-10x-x-109">* </span><span 
class="cmmi-10x-x-109">p</span><sub><span 
class="cmr-8">1</span></sub> + 64<sup><span 
class="cmr-8">2</span></sup> <span 
class="cmsy-10x-x-109">* </span><span 
class="cmmi-10x-x-109">p</span><sub><span 
class="cmr-8">2</span></sub> + <span 
class="cmmi-10x-x-109">... </span>+ 64<sup><span 
class="cmmi-8">n</span><span 
class="cmsy-8">-</span><span 
class="cmr-8">1</span></sup> <span 
class="cmsy-10x-x-109">* </span><span 
class="cmmi-10x-x-109">p</span><sub><span 
class="cmmi-8">n</span><span 
class="cmsy-8">-</span><span 
class="cmr-8">1</span></sub> + (
hraje b�l&#x00FD; ? 64<sup><span 
class="cmmi-8">n</span></sup> : 0)
.
<div class="center" 
>
<!--l. 167--><p class="noindent" >

<!--l. 168--><p class="noindent" ><img 
src="README2x.png" alt="PIC" class="graphics" width="227.61694pt" height="227.61694pt" ><!--tex4ht:graphics  
name="README2x.png" src="diagram2.ps"  
--></div>
<!--l. 171--><p class="indent" >   Na obr�zku je p&#x0159;�klad pozice z koncovky dvou st&#x0159;elc&#x016F;. Po&#x0159;ad� figur bude KSSk, tedy b�l&#x00FD; kr�l
a oba st&#x0159;elci a nakonec &#x010D;ern&#x00FD; kr�l. Na tahu je b�l&#x00FD; a na na&#353;� &#353;achovnici hraje nahoru, st&#x0159;elci jsou
tedy na d3 a e3, b�l&#x00FD; kr�l na f3 a &#x010D;ern&#x00FD; na e5. V n�sleduj�c� tabulce je v&#x00FD;po&#x010D;et &#x010D;�sla pozice v
r�mci dan� koncovky. V&#x00FD;sledek je 26 293 525.
<!--l. 174--><p class="noindent" ><!--tex4ht:inline--><div class="tabular"> <table id="TBL-2" class="tabular" 
cellspacing="0" cellpadding="0" rules="groups" 
><colgroup id="TBL-2-1g"><col 
id="TBL-2-1"></colgroup><colgroup id="TBL-2-2g"><col 
id="TBL-2-2"></colgroup><colgroup id="TBL-2-3g"><col 
id="TBL-2-3"></colgroup><colgroup id="TBL-2-4g"><col 
id="TBL-2-4"></colgroup><colgroup id="TBL-2-5g"><col 
id="TBL-2-5"></colgroup><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-2-1-"><td  style="white-space:nowrap; text-align:left;" id="TBL-2-1-1"  
class="td11"><span 
class="cmbx-10x-x-109">Figurka           </span></td><td  style="white-space:nowrap; text-align:center;" id="TBL-2-1-2"  
class="td11"><span 
class="cmbx-10x-x-109">Pole</span></td><td  style="white-space:nowrap; text-align:center;" id="TBL-2-1-3"  
class="td11"><span 
class="cmbx-10x-x-109">Index</span></td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-1-4"  
class="td11"><span 
class="cmbx-10x-x-109">Hodnota</span></td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-1-5"  
class="td11"><span 
class="cmbx-10x-x-109">V</span><span 
class="cmbx-10x-x-109">&#x00FD;sledek</span></td>
</tr><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-2-2-"><td  style="white-space:nowrap; text-align:left;" id="TBL-2-2-1"  
class="td11">B�l&#x00FD; kr�l             </td><td  style="white-space:nowrap; text-align:center;" id="TBL-2-2-2"  
class="td11"> f3  </td><td  style="white-space:nowrap; text-align:center;" id="TBL-2-2-3"  
class="td11">  21   </td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-2-4"  
class="td11">      21</td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-2-5"  
class="td11">       21</td></tr><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-2-3-"><td  style="white-space:nowrap; text-align:left;" id="TBL-2-3-1"  
class="td11">Prvn� b�l&#x00FD; st&#x0159;elec</td><td  style="white-space:nowrap; text-align:center;" id="TBL-2-3-2"  
class="td11"> e3 </td><td  style="white-space:nowrap; text-align:center;" id="TBL-2-3-3"  
class="td11"> 20 </td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-3-4"  
class="td11">20 <span 
class="cmsy-10x-x-109">* </span>64 </td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-3-5"  
class="td11"> 1 280</td>
</tr><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-2-4-"><td  style="white-space:nowrap; text-align:left;" id="TBL-2-4-1"  
class="td11">Druh&#x00FD; b�l&#x00FD; st&#x0159;elec</td><td  style="white-space:nowrap; text-align:center;" id="TBL-2-4-2"  
class="td11"> d3  </td><td  style="white-space:nowrap; text-align:center;" id="TBL-2-4-3"  
class="td11">  19   </td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-4-4"  
class="td11">219 <span 
class="cmsy-10x-x-109">* </span>64<sup><span 
class="cmr-8">2</span></sup>  </td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-4-5"  
class="td11">   77 824</td>
</tr><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-2-5-"><td  style="white-space:nowrap; text-align:left;" id="TBL-2-5-1"  
class="td11">&#x010C;ern&#x00FD; kr�l           </td><td  style="white-space:nowrap; text-align:center;" id="TBL-2-5-2"  
class="td11"> e5  </td><td  style="white-space:nowrap; text-align:center;" id="TBL-2-5-3"  
class="td11">  36   </td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-5-4"  
class="td11">36 * 264<sup><span 
class="cmr-8">3</span></sup> </td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-5-5"  
class="td11"> 9 437 184</td>
</tr><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-2-6-"><td colspan="3" style="white-space:nowrap; text-align:left;" id="TBL-2-6-1"  
class="td11"><div class="multicolumn"  style="white-space:nowrap; text-align:left;">B�l&#x00FD; na tahu</div>                    </td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-6-4"  
class="td11">264<sup><span 
class="cmr-8">4</span></sup>         </td><td  style="white-space:nowrap; text-align:right;" id="TBL-2-6-5"  
class="td11">16 777 216</td>
</tr><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-2-7-"><td colspan="3" style="white-space:nowrap; text-align:left;" id="TBL-2-7-1"  
class="td11"></td><div class="multicolumn"  style="white-space:nowrap; text-align:left;">Suma</div>                                      <td  style="white-space:nowrap; text-align:right;" id="TBL-2-7-5"  
class="td11">26 293 525</td>
</tr><tr 
class="hline"><td><hr></td><td><hr></td><td><hr></td><td><hr></td><td><hr></td></tr><tr  
 style="vertical-align:baseline;" id="TBL-2-8-"><td  style="white-space:nowrap; text-align:left;" id="TBL-2-8-1"  
class="td11">                </td></tr></table></div>
<!--l. 194--><p class="indent" >   Opa&#x010D;n&#x00FD; p&#x0159;evod z &#x010D;�sla na pozici bude analogick&#x00FD;, &#x010D;�slo rozlo&#382;�me na cifry v 64-kov� soustav&#x011B; a
to budou indexy pol�&#x010D;ek jednotliv&#x00FD;ch kamen&#x016F;.
<!--l. 196--><p class="indent" >   Vlastn� algoritmus vygenerov�n� datab�ze n-figurov� koncovky bude vypadat n&#x011B;jak
takto:
     <ul class="itemize1">
     <li class="itemize">Rekurzivn&#x011B; stejn&#x00FD;m algoritmem vygeneruj datab�ze koncovek, kter� z na&#353;� koncovky
     mohou  vzniknout.  (Nap&#x0159;�klad  pro  koncovku  d�my  proti  v&#x011B;&#382;i  vygeneruj  nejprve
     koncovku se samotnou d�mou a se samotnou v&#x011B;&#382;�.)
     </li>
     <li class="itemize">Naalokuj m�sto pro 2 <span 
class="cmsy-10x-x-109">* </span>64<sup><span 
class="cmmi-8">n</span></sup>
     &#x010D;�sel a vypl&#x0148; je nulami
     </li>
     <li class="itemize">Projdi p&#x0159;irozen� &#x010D;�sla od 0 do 2 <span 
class="cmsy-10x-x-109">* </span>64<sup><span 
class="cmmi-8">n</span></sup> <span 
class="cmsy-10x-x-109">- </span>1
     , ke ka&#382;d�mu vygeneruj pozici. Je-li nep&#x0159;�pustn� (2 figury na sob&#x011B;, &#353;ach nehraj�c�mu), vlo&#382;
     do pole &#x010D;�sel na dan&#x00FD; index konstantu CHYBA, je-li &#x010D;ern&#x00FD; v matu vlo&#382; 1, je-li b�l&#x00FD; v matu,
     vlo&#382; -1.

     </li>
     <li class="itemize">Projdi p&#x0159;irozen� &#x010D;�sla od 0 do 2 <span 
class="cmsy-10x-x-109">* </span>64<sup><span 
class="cmmi-8">n</span></sup> <span 
class="cmsy-10x-x-109">- </span>1
     , p&#x0159;esko&#x010D; ty, kde je na dan�m indexu v poli jin� &#x010D;�slo ne&#382; nula. Ke ka&#382;d�mu &#x010D;�slu vygeneruj
     pozici. Na n�&#353; index do pole vlo&#382; stru&#x010D;n&#x011B; &#x0159;e&#x010D;eno hodnotu propo&#x010D;tu minimaxem do hloubky 1
     s ohodnocen�m pomoc� ji&#382; spo&#x010D;�tan&#x00FD;ch hodnot a nul v poli. Podrobn&#x011B; &#x0159;e&#x010D;eno: Dejme tomu,
     &#382;e hraje b�l&#x00FD; (pro &#x010D;ern�ho budeme postupovat analogicky). Vygeneruj z pozice tahy, zahraj
     je. Pokud zahran&#x00FD;m tahem p&#x0159;e&#353;la pozice do jin�ho druhu koncovky (prom&#x011B;na p&#x011B;&#353;ce,
     bran�), pod�vej se do tabulky pro tuto koncovku, kolik�t&#x00FD;m p&#x016F;ltahem b�l&#x00FD; d�v�
     nebo dost�v� mat, p&#x0159;�padn&#x011B; zda je pozice rem�zov�. Pokud z&#x016F;stal zachov�n typ
     koncovky, spo&#x010D;�tej si index pozice a pod�vej se do pole, zda a jak ji&#382; m�me pozici
     ohodnocenou. 0 znamen�, &#382;e zat�m nev�me, kladn� &#x010D;�slo, &#382;e je pozice vyhran� za b�l�ho,
     z�porn�, &#382;e za &#x010D;ern�ho. Je-li mezi &#x010D;�sly alespo&#x0148; jedno kladn� vlo&#382; do pole na n�&#353;
     index to nejmen&#353;� z t&#x011B;ch kladn&#x00FD;ch &#x010D;�sel zv&#x011B;t&#353;en� o 1. (Nap&#x0159;�klad z 0, 0, 0, 5,
     3, -2, 0, 0, -2, -4 vyber 3 a do pole na n�&#353; index dej 3 + 1 = 4. Znamen� o, &#382;e
     d�v�me mat 2. tahem, nebo&#x0165; jsme o 3 p&#x016F;ltahy od 1, co&#382; je mat.) Jsou-li v&#353;echna
     &#x010D;�sla z�porn�, je pozice za b�l�ho prohran�, vyber z nich to nejmen&#353;� (s nejv&#x011B;t&#353;�
     absolutn� hodnotou) a do pole na n�&#353; index ho dej zmen&#353;en� o 1. (Nap&#x0159;�klad z -2, -4,
     -6, -6, -4 vyber -6 a do pole dej -7. To jsme na tahu a dost�v�me mat 3. tahem.)
     Posledn� mo&#382;nost� je, &#382;e mezi &#x010D;�sly je alespo&#x0148; jedna 0 a zbytek jsou bu&#x010F; nuly nebo
     z�porn� &#x010D;�sla. V tom p&#x0159;�pad&#x011B; je&#353;t&#x011B; nem&#x016F;&#382;eme rozhodnout a v poli nech�me
     nulu.
     </li>
     <li class="itemize">Pokud jsme zapsali do pole alespo&#x0148; jednu nenulu, pokra&#x010D;uj bodem 4.
     </li>
     <li class="itemize">Ulo&#382; pole tak, jak je, do souboru.</li></ul>
<!--l. 205--><p class="noindent" >M�me-li vygenerovanou tabulku, je ji&#382; velmi jednoduch� napsat optim�ln� algoritmus hry. Jedn� se o
prost&#x00FD; minimax do hloubky 1. M�sto b&#x011B;&#382;n� ohodnocovac� funkce se budeme d�vat do tabulky. 0
znamen�, &#382;e &#382;�dn� ze stran nem&#x016F;&#382;e vyhr�t, tedy rem�za. Kladn� &#x010D;�sla jsou pozice vyhran� za
b�l�ho, &#x010D;�m d�l od jedni&#x010D;ky, t�m d�l od matu. Tot�&#382; plat� s &#x010D;ern&#x00FD;m pro z�porn� &#x010D;�sla. V
rem�zov&#x00FD;ch pozic�ch pak m&#x016F;&#382;eme spustit i klasick&#x00FD; mysl�c� algoritmus omezen&#x00FD; na tahy, kter�
nevedou k na&#353;� proh&#x0159;e. Jde jen o to, aby v rem�zov&#x00FD;ch pozic�ch, kde ov&#353;em o rem�zu bojuje
soupe&#x0159;, program nerezignoval na teoreticky marnou, ale prakticky proti re�ln�mu soupe&#x0159;i &#x010D;asto
nad&#x011B;jnou snahu o v&#x00FD;hru a nezahr�l prost&#x011B; jak&#x00FD;koli neprohr�vaj�c� tah. Nap&#x0159;�klad v t&#x011B;&#382;k� (pro
2 jezdce), ale rem�zov� koncovce d�my proti dv&#x011B;ma jezdc&#x016F;m by program asi nem&#x011B;l
nastavit d�mu. To sice objektivn&#x011B; nen� chyba, nebo&#x0165; i koncovka kr�le a dvou jezdc&#x016F; proti
samotn�mu kr�li je rem�zov�, ale subjektivn&#x011B; to jist&#x011B; chyba je a u&#382;ivatel by to asi programu
neodpustil.
<!--l. 207--><p class="indent" >   Bohu&#382;el tento algoritmus nen� na sou&#x010D;asn&#x00FD;ch po&#x010D;�ta&#x010D;�ch dostate&#x010D;n&#x011B; rychl&#x00FD; - na po&#x010D;k�n�
z�sk�me jen t&#x0159;�figurov� koncovky, p&#x0159;es noc pak &#x010D;ty&#x0159;figurov�. Jednou z nejjednodu&#353;&#353;�ch a z�rove&#x0148;
velmi �&#x010D;inn&#x00FD;ch metod, jak v&#x00FD;po&#x010D;et zrychlit a zmen&#353;it i objem vygenerovan&#x00FD;ch dat je vyu&#382;it�
nejr&#x016F;zn&#x011B;j&#353;�ch symetri�. 50V tabulce jak�koli koncovky se pom&#x011B;rn&#x011B; &#x010D;asto a relativn&#x011B; pravideln&#x011B;
opakuj� &#x010D;�seln� hodnoty. Je z&#x0159;ejm�, &#382;e data p&#x016F;jde �sp&#x011B;&#353;n&#x011B; komprimovat t�m&#x011B;&#x0159; jakoukoli
rozumnou metodou. Vzhledem ke zp&#x016F;sobu vyu&#382;it� je nutn�, aby pro p&#x0159;e&#x010D;ten� hodnoty
z komprimovan� tabulky sta&#x010D;ilo dekomprimovat jen n&#x011B;jak� mal� okol� a nikoli celou
tabulku.

<!--l. 210--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">2.2   </span> <a 
 id="x1-150002.2"></a>Reprezentace pozice</h4>
<!--l. 212--><p class="noindent" >Nejednodu&#353;� reprezentace &#353;achovnice je dvourozm&#x011B;rn� pole 8x8. To m&#x016F;&#382;eme v p&#x0159;�pad&#x011B;
pot&#x0159;eby rozvinout na jednorozm&#x011B;rn� pole o 64 prvc�ch. V&#x00FD;hodou tohoto p&#x0159;�stupu je
snadn&#x011B;j&#353;� &#x010D;itelnost programu, nev&#x00FD;hodou je nutnost o&#353;et&#x0159;it mo&#382;n� p&#x0159;ete&#x010D;en� pole.
(Nap&#x0159;. tah jezdce z okraje &#353;achovnice mimo jej� okraj. Toto se d� &#x0159;e&#353;it polem 10x12,
pota&#382;mo jednorozm&#x011B;rn&#x00FD;m polem o 120 prvc�ch, co&#382; je vlastn&#x011B; klasick� &#353;achovnice 8x8 s
mantinely.
<!--l. 214--><p class="indent" >   Nejednodu&#353;&#353;� reprezentace &#353;achov&#x00FD;ch figur je cel&#x00FD;m &#x010D;�slem - kladn&#x00FD;m pro b�l�, z�porn&#x00FD;m pro
&#x010D;ern�. Pr�zdn� pole je pak neutr�ln� a m� hodnotu 0, mantinely (jsou-li p&#x0159;�tomny) maj� n&#x011B;jakou
konstantn� hodnotu, kter� se neuva&#382;uje pro v&#x00FD;po&#x010D;et.
<!--l. 216--><p class="indent" >   Dal&#353;� mo&#382;nou reprezentac� &#353;achovnice m&#x016F;&#382;e b&#x00FD;t bitov� pole. N&#x011B;jak&#x00FD; jev na &#353;achovnici je pak
reprezentov�n 64-bitov&#x00FD;m &#x010D;�slem. Nap&#x0159;�klad v&#x00FD;skyt b�l&#x00FD;ch v&#x011B;&#382;� v z�kladn�m postaven� je pak
reprezentov�n &#x010D;�slem 129 (00000000 00000000 00000000 00000000 00000000 00000000 00000000
10000001) Kdy&#382; budeme m�t pro ka&#382;d&#x00FD; typ kamene jednu prom&#x011B;nnou, 12 prom&#x011B;nn&#x00FD;ch m&#x016F;&#382;e
reprezentovat celou &#353;achovnici. V&#x00FD;hodou tohoto p&#x0159;�stupu je velmi efektivn� zpracov�n� zejm�na
na 64-bitov� architektu&#x0159;e, kde je ka&#382;d� operace jedna velmi jednoduch� instrukce. Nev&#x00FD;hodou, je,
&#382;e zejm�na pro za&#x010D;�naj�c� program�tory m&#x016F;&#382;e b&#x00FD;t tento p&#x0159;�stup velmi matouc� a
ne&#x010D;iteln&#x00FD;.
<!--l. 218--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">2.3   </span> <a 
 id="x1-160002.3"></a>Reprezentace pole tah&#x016F;</h4>
<!--l. 220--><p class="noindent" >Proto&#382;e tah&#x016F; bude v pr&#x016F;b&#x011B;hu v&#x00FD;po&#x010D;tu generov�no velmi mnoho, m&#x011B;l by b&#x00FD;t typ, reprezentuj�c�
tah, velmi mal&#x00FD;. Ka&#382;dop�dn&#x011B; mus� obsahovat minim�ln&#x011B; polo&#382;ky odkud a kam. V p&#x0159;�pad&#x011B;
reprezentace &#353;achovnice dvourozm&#x011B;rn&#x00FD;m polem, budou polo&#382;ky odkud a kam reprezentov�ny
dvouprvkov&#x00FD;m polem - na indexu 0 bude sloupec, na indexu 1 &#x0159;�dek. V p&#x0159;�pad&#x011B;, &#382;e je &#353;achovnice
reprezentov�na jednorozm&#x011B;rn&#x00FD;m polem, polo&#382;ky odkud a kam jsou reprezentov�ny pouze cel&#x00FD;m
&#x010D;�slem.
<!--l. 222--><p class="indent" >   K ulo&#382;en� mno&#382;iny tah&#x016F; se b&#x011B;&#382;n&#x011B; pou&#382;�v� glob�ln� z�sobn�k tah&#x016F;, kter&#x00FD; m&#x016F;&#382;e vypadat
n&#x011B;jak takto:

   <div class="verbatim" id="verbatim-1">
Move&#x00A0;moves[MANY]
&#x00A0;<br />int&#x00A0;borders[DEPTH]
&#x00A0;<br />int&#x00A0;index_in_stack
</div>
<!--l. 227--><p class="nopar" >
<!--l. 229--><p class="indent" >   Tahy jsou ulo&#382;eny v jedin�m glob�ln�m jednorozm&#x011B;rn�m poli, p&#x0159;i&#x010D;em&#382; tahy z aktu�ln&#x011B;
propo&#x010D;�t�van� pozice maj� index borders[index_in_stack] a&#382; borders[index_in_stack+1]-1.
Konstanta DEPTH je nejvy&#353;&#353;� mo&#382;n� hloubka zano&#x0159;en� rekurze. Na dne&#353;n�ch po&#x010D;�ta&#x010D;�ch by
m&#x011B;lo sta&#x010D;it 32. Velikost konstanty MANY pak p&#x016F;jde shora odhadnout jako sou&#x010D;in maxim�ln�ho
po&#x010D;tu tah&#x016F; z pozice * DEPTH. Program p&#x0159;i tomto postupu sice m&#x016F;&#382;e trochu pl&#x00FD;tvat pam&#x011B;t�, ale
achillovou patou &#353;achov&#x00FD;ch program&#x016F; obvykle neb&#x00FD;v� nedostatek pam&#x011B;ti, n&#x00FD;br&#382; nedostatek &#x010D;asu
na dostate&#x010D;n&#x011B; hlubok&#x00FD; v&#x00FD;po&#x010D;et. Toto &#x0159;e&#353;en� u&#353;et&#x0159;� cenn� mikrosekundy, kter� by st�lo
dynamick� p&#x0159;ealokov�v�n� pole v cyklu.
<!--l. 231--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">2.4   </span> <a 
 id="x1-170002.4"></a>Ohodnocovac� funkce</h4>
<!--l. 233--><p class="noindent" >&#352;achov&#x00FD; program prov�d� propo&#x010D;et do ur&#x010D;it� hloubky, na jeho&#382; konci zavol� ohodnocovac�
funkci, kter� vr�t� cenu dan� pozice. Nejednodu&#353;&#353;� a nejd&#x016F;le&#382;it&#x011B;j&#353;� je samoz&#x0159;ejm&#x011B;
se&#x010D;�st materi�l. Cena jednotliv&#x00FD;ch figur se v r&#x016F;zn&#x00FD;ch programech li&#353;�. Pokud m� p&#x011B;&#353;ec
cenu 1, bude cena jezdce a st&#x0159;elce p&#x0159;ibli&#382;n&#x011B; 3, v&#x011B;&#382;e 5 a d�my 9. N&#x011B;kdy b&#x00FD;v� hodnota
st&#x0159;elce nepatrn&#x011B; vy&#353;&#353;� ne&#382; hodnota jezdce a podobn&#x011B;. &#352;achov&#x00FD; program s ohodnocovac�
funkc� degenerovanou na prost&#x00FD; sou&#x010D;et materi�lu se pochopiteln&#x011B; bude chovat divn&#x011B;.
Cesta i od velmi zjevn� pozi&#x010D;n� chyby k matu je velmi dlouh� a p&#x0159;esahuje hloubku
propo&#x010D;tu dne&#353;n�ch program&#x016F;, tak&#382;e prost&#x00FD; sou&#x010D;et materi�lu nesta&#x010D;�. Proto se p&#x0159;id�v�
pozi&#x010D;n� slo&#382;ka. Pozi&#x010D;n� slo&#382;ka b&#x00FD;v� oby&#x010D;ejn&#x011B; velmi mal�, jen z&#x0159;�dka v re�ln&#x00FD;ch parti�ch
p&#x0159;es�hne v absolutn� hodnot&#x011B; cenu p&#x011B;&#353;ce. &#x0158;ada pozi&#x010D;n�ch faktor&#x016F; se d� ocenit statickou
tabulkou pro jednotliv� pol�&#x010D;ka. Nap&#x0159;�klad pozi&#x010D;n� bonus pro figury bl�&#382;e ke st&#x0159;edu
&#353;achovnice (a t�m i v&#x011B;t&#353;�m man�vrovac�m prostorem) bude vy&#353;&#353;� ne&#382; pro figury u
kraje nebo v rohu &#353;achovnice. Takov�to &#x0159;e&#353;en� pozi&#x010D;n� slo&#382;ky jist&#x011B; nebude dokonal�,
zato bude velmi rychl�. Pozi&#x010D;n� tabulku m&#x016F;&#382;eme pro jednotliv� figury lehce upravit.
Pro p&#x011B;&#353;ce existuje cel� &#x0159;ada heuristik. M&#x016F;&#382;eme pozi&#x010D;n&#x011B; v�ce ocenit p&#x011B;&#353;ce, kte&#x0159;� jsou
d�le od v&#x00FD;choz�ho postaven� - to p&#x011B;&#353;ce p&#x0159;im&#x011B;je ut�kat sm&#x011B;rem k d�m&#x011B;. V z�kladn�m
postaven� pak m&#x016F;&#382;eme ocenit vy&#353;&#353;� bonusem p&#x011B;&#353;ce na vykro&#x010D;iv&#353;� na st&#x0159;edu. D�le
m&#x016F;&#382;eme ocenit je-li p&#x011B;&#353;ec voln&#x00FD; (&#382;�dn� figura mu nebr�n� v b&#x011B;hu do d�my), &#x010D;i je-li
kryt&#x00FD; jin&#x00FD;m p&#x011B;&#353;ce. Rovn&#x011B;&#382; m&#382;e dostat postih, je-li opo&#382;d&#x011B;n&#x00FD;. Jezdec stoj� dob&#x0159;e v
centru, v rohu se mu obvykle neda&#x0159;�. Rovn&#x011B;&#382; m&#x016F;&#382;eme ocenit jezdce &#353;ikovn&#x011B; kryt�ho
p&#x011B;&#353;cem. Pro st&#x0159;elce sice nen� pozi&#x010D;n� ohodnocen� tak podstatn�, p&#x0159;esto se o to m&#x016F;&#382;eme
pokusit. Dob&#x0159;e um�st&#x011B;n&#x00FD; st&#x0159;elec by m&#x011B;l dostat bonus za soupe&#x0159;ovy p&#x011B;&#353;ce na stejn�
barv&#x011B; pole, kter� m&#x016F;&#382;e napadat a naopak postih za p&#x011B;&#353;ce, kter� napadat nem&#x016F;&#382;e.
T�m n�m vyjde, &#382;e dva st&#x0159;elci budou m�t spolu nepatrn&#x011B; vy&#353;&#353;� hodnotu ne&#382; je prost&#x00FD;
sou&#x010D;et jejich hodnot. U v&#x011B;&#382;e nem� statick� ohodnocovac� tabulka smysl. V&#x011B;&#382; pat&#x0159;�
na voln&#x00FD; sloupec, m� tla&#x010D;it na opo&#382;d&#x011B;n� nebo nekryt� p&#x011B;&#353;ce a ob&#x011B; v&#x011B;&#382;e by se m&#x011B;ly

navz�jem kr&#x00FD;t. U d�my je pot&#x0159;eba snad jen zabr�nit p&#x0159;ed&#x010D;asn�mu v&#x00FD;vinu - soupe&#x0159;
pak prost&#x011B; napad� d�mu s tempy b&#x011B;&#382;n&#x00FD;ch v&#x00FD;vinov&#x00FD;ch tah&#x016F; leh&#x010D;�ch figur. U kr�le je
v zah�jen� a st&#x0159;edn� h&#x0159;e d&#x016F;le&#382;it� p&#x0159;edev&#353;�m bezpe&#x010D;nost. Jde jednak o um�st&#x011B;n�,
zachovan� pr�vo ro&#353;�dy, p&#x011B;&#353;cov&#x00FD; kryt kr�le a napadnutelnost pol� v okol�. V koncovce se
�loha kr�le radik�ln&#x011B; m&#x011B;n� a st�v� se z n&#x011B;j aktivn&#x011B; bojuj�c� figura, kter� mus� opustit
�kryt a bojovat o st&#x0159;ed. V matov� koncovce se pak kr�l siln&#x011B;j&#353;� strany sna&#382;� p&#x0159;ibl�&#382;it
soupe&#x0159;ovu kr�li. Ohodnocovac� funkce napsan� pomoc� statick&#x00FD;ch tabulek je velmi rychl�,
ale m� jednu v�&#382;nou slabinu. Tabulky jsou naps�ny obecn&#x011B;, mohou tedy b&#x00FD;t dobr�
pro b&#x011B;&#382;nou pozici, ale sta&#x010D;� n&#x011B;kolik netypick&#x00FD;ch tah&#x016F; a spr�vn� ohodnocen� pol�&#x010D;ek
nap&#x0159;�klad pro jezdce m&#x016F;&#382;e b&#x00FD;t �pln&#x011B; jin�. &#x0158;e&#353;en�m je m�sto samotn�ho pole oce&#x0148;ovat
pohyblivost figur, napadnuteln� pole a tak podobn&#x011B;. To v&#353;e je ov&#353;em za cenu vy&#353;&#353;� &#x010D;asov�
n�ro&#x010D;nosti.
<!--l. 243--><p class="noindent" >
   <h3 class="sectionHead"><span class="titlemark">3   </span> <a 
 id="x1-180003"></a>Popis implementace</h3>
<!--l. 245--><p class="noindent" >Program je rozd&#x011B;len na 4 moduly:
     <ul class="itemize1">
     <li class="itemize">main.c s hlavi&#x010D;kov&#x00FD;m souborem zcuchess.h obsahuje hlavn� funkci a pomocn� funkce
     pro spr�vu pam&#x011B;ti.
     </li>
     <li class="itemize">io.c s hlavi&#x010D;kov&#x00FD;m souborem io.h funkce pro vstupn� a v&#x00FD;stupn� operace
     </li>
     <li class="itemize">chess.c s hlavi&#x010D;kov&#x00FD;m souborem chess.h z�kladn� rutiny umo&#382;&#x0148;uj�c� &#353;achovou hru
     </li>
     <li class="itemize">ai.c s hlavi&#x010D;kov&#x00FD;m souborem ai.h obsahuje um&#x011B;lou &#8221;inteligenci&#8221;</li></ul>
<!--l. 253--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">3.1   </span> <a 
 id="x1-190003.1"></a>Glob�ln� datov� struktury</h4>
     <ul class="itemize1">
     <li class="itemize">int chessboard[8][8]
     </li>
     <li class="itemize">reprezentace &#353;achovnice pota&#382;mo pozice.
     </li>
     <li class="itemize">bool castlings[4]
     </li>
     <li class="itemize">pole s p&#x0159;�znaky ro&#353;�d, kter� je&#353;t&#x011B; m&#x016F;&#382;eme prov�st (mal� b�l�, velk� b�l�, mal� &#x010D;ern�,
     velk� &#x010D;ern�).

     </li>
     <li class="itemize">int en_passant[2]
     </li>
     <li class="itemize">Udr&#382;uje aktu�ln� pozici p&#x011B;&#353;ce, kter�ho m&#x016F;&#382;eme sebrat mimochodem. Na indexu 0 je
     sloupec, na indexu 1 je &#x0159;�dek
     </li>
     <li class="itemize">bool human_move
     </li>
     <li class="itemize">p&#x0159;�znak, zda-li je na tahu &#x010D;lov&#x011B;k.
     </li>
     <li class="itemize">int position_bonus[8][8]
     </li>
     <li class="itemize">tabulka s pozi&#x010D;n�mi bonusy pro statickou ohodnocovac� funkci.</li></ul>
<!--l. 262--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">3.2   </span> <a 
 id="x1-200003.2"></a>Reprezentace &#353;achovnice, pozice a hodnot figur</h4>
<!--l. 263--><p class="noindent" >Pro n�zornost byla za reprezentaci &#353;achovnice, pota&#382;mo pozic, zvolena matice 8x8. B�l� figury jsou
reprezentov�ny cel&#x00FD;m kladn&#x00FD;m &#x010D;�slem n�sledovn&#x011B;:
     <ul class="itemize1">
     <li class="itemize">1 P&#x011B;&#353;ec (konstanta PAWN), hodnota 100 (konstanta PAWN_VALUE)
     </li>
     <li class="itemize">2 V&#x011B;&#382; (konstanta ROOK), hodnota 400 (konstanta ROOK_VALUE)
     </li>
     <li class="itemize">3 Jezdec (konstanta KNIGHT), hodnota 300 (konstanta KNIGHT_VALUE)
     </li>
     <li class="itemize">4 St&#x0159;elec (konstanta BISHOP), hodnota 350 (konstanta BISHOP_VALUE)
     </li>
     <li class="itemize">5 D�ma (konstanta QUEEN), hodnota 750 (konstanta QUEEN_VALUE)
     </li>
     <li class="itemize">6 Kr�l (konstanta KING)</li></ul>

<!--l. 272--><p class="noindent" >&#x010C;ern� figury jsou reprezentov�ny stejn&#x011B;, akor�t s opa&#x010D;n&#x00FD;m znam�nkem. &#x010C;�slo 0 (konstanta EMPTY)
pak reprezentuje pr�zdn� pole.
<!--l. 274--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">3.3   </span> <a 
 id="x1-210003.3"></a>Reprezentace tahu a mno&#382;iny tah&#x016F;</h4>
<!--l. 276--><p class="noindent" >Tah je reprezentov�n datovou strukturou Move:

   <div class="verbatim" id="verbatim-2">
typedef&#x00A0;struct&#x00A0;{
&#x00A0;<br />&#x00A0;&#x00A0;int&#x00A0;from[2];
//na&#x00A0;indexu&#x00A0;0&#x00A0;je&#x00A0;sloupec&#x00A0;odkud&#x00A0;se&#x00A0;t�hne,&#x00A0;na&#x00A0;indexu&#x00A0;1&#x00A0;je&#x00A0;&#x0159;�dek&#x00A0;odkud&#x00A0;se&#x00A0;t�hne
&#x00A0;<br />&#x00A0;&#x00A0;int&#x00A0;to[2];
//na&#x00A0;indexu&#x00A0;0&#x00A0;je&#x00A0;sloupec&#x00A0;kam&#x00A0;se&#x00A0;t�hne,&#x00A0;na&#x00A0;indexu&#x00A0;1&#x00A0;je&#x00A0;&#x0159;�dek&#x00A0;kam&#x00A0;se&#x00A0;t�hne
&#x00A0;<br />&#x00A0;&#x00A0;bool&#x00A0;status; //p&#x0159;�znak&#x00A0;je-li&#x00A0;tah&#x00A0;validn�
&#x00A0;<br />}&#x00A0;Move;
</div>
<!--l. 283--><p class="nopar" >
<!--l. 285--><p class="indent" >   V programu jsou pro indexy pol� <span 
class="cmti-10x-x-109">from </span>a <span 
class="cmti-10x-x-109">to </span>p&#x0159;ipraveny konstanty <span 
class="cmti-10x-x-109">COL </span>(sloupec, index 0) a
<span 
class="cmti-10x-x-109">ROW </span>(&#x0159;�dek, index 1). V cel�m programu se pak tyto sou&#x0159;adnice pou&#382;�vaj� konzistentn&#x011B;, tzn.
v&#382;dy je sloupec prvn� a &#x0159;�dek druh&#x00FD;.
<!--l. 287--><p class="indent" >   Mno&#382;ina tah&#x016F; se ukl�d� do struktury Moves:

   <div class="verbatim" id="verbatim-3">
typedef&#x00A0;struct&#x00A0;{
&#x00A0;<br />&#x00A0;&#x00A0;int&#x00A0;count; //Po&#x010D;et&#x00A0;tah&#x016F;&#x00A0;v&#x00A0;mno&#382;in&#x011B;
&#x00A0;<br />&#x00A0;&#x00A0;Move&#x00A0;*move; //Pole&#x00A0;tah&#x016F;
&#x00A0;<br />}&#x00A0;Moves;
</div>
<!--l. 293--><p class="nopar" >
<!--l. 295--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">3.4   </span> <a 
 id="x1-220003.4"></a>Statick� ohodnocovac� funkce</h4>
<!--l. 296--><p class="noindent" >Prov�d� prost&#x00FD; sou&#x010D;et hodnoty materi�lu a p&#x0159;ipo&#x010D;�t�v� pozi&#x010D;n� bonus. Pozi&#x010D;n� bonus je
reprezentov�n matic� 8x8 typu int a je pro v&#353;echny figury stejn&#x00FD;. Vych�z� z my&#353;lenky, &#382;e ka&#382;d�
figura je u&#382;ite&#x010D;n&#x011B;j&#353;� bl�&#382;e ke st&#x0159;edu &#353;achovnice.
<!--l. 298--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">3.5   </span> <a 
 id="x1-230003.5"></a>Mysl�c� algoritmus</h4>
<!--l. 299--><p class="noindent" >Jako mysl�c� algoritmus byl postupn&#x011B; pou&#382;it minimax, alfabeta a nakonec velmi prost�
implementace kask�dov� metody. V&#353;echny tyto algoritmy jsou pops�ny v &#x010D;�sti o anal&#x00FD;ze.
<!--l. 301--><p class="noindent" >
   <h3 class="sectionHead"><span class="titlemark">4   </span> <a 
 id="x1-240004"></a>U&#382;ivatelsk� p&#x0159;�ru&#x010D;ka</h3>
<!--l. 303--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">4.1   </span> <a 
 id="x1-250004.1"></a>Instalace</h4>
<!--l. 305--><p class="noindent" >Pokud jste u&#382;ivatli Linuxu:
     <ul class="itemize1">
     <li class="itemize">V ko&#x0159;enov�m adres�&#x0159;i projektu napi&#353;te do konzole p&#x0159;�kaz <span 
class="cmti-10x-x-109">make</span>.</li></ul>
<!--l. 309--><p class="noindent" >Pokud jste u&#382;ivateli Windows 7:
     <ul class="itemize1">
     <li class="itemize">St�hn&#x011B;te a nainstalujte n&#x011B;jak&#x00FD; C p&#x0159;eklada&#x010D; zalo&#382;en&#x00FD; na gcc (nap&#x0159;. MinGW).
     </li>
     <li class="itemize">Klikn&#x011B;te na tla&#x010D;�tko  <span 
class="cmbx-10x-x-109">Start </span>a vyberte polo&#382;ku  <span 
class="cmbx-10x-x-109">Tento po</span><span 
class="cmbx-10x-x-109">&#x010D;</span><span 
class="cmbx-10x-x-109">�ta</span><span 
class="cmbx-10x-x-109">&#x010D;</span>.
     </li>
     <li class="itemize">Klikn&#x011B;te prav&#x00FD;m tla&#x010D;�tkem my&#353;i do okna, kter� se v�m zobrazilo, a z menu vyberte
     <span 
class="cmbx-10x-x-109">Vlastnosti</span>.

     </li>
     <li class="itemize">V n�sleduj�c�m okn&#x011B; vyberte vpravo polo&#382;ku  <span 
class="cmbx-10x-x-109">Up</span><span 
class="cmbx-10x-x-109">&#x0159;esnit nastaven</span><span 
class="cmbx-10x-x-109">� syst</span><span 
class="cmbx-10x-x-109">�mu</span>, otev&#x0159;e
     se dal&#353;� dialogov� okno.
     </li>
     <li class="itemize">V tom klikn&#x011B;te na tla&#x010D;�tko  <span 
class="cmbx-10x-x-109">Prom</span><span 
class="cmbx-10x-x-109">&#x011B;nn</span><span 
class="cmbx-10x-x-109">� prost</span><span 
class="cmbx-10x-x-109">&#x0159;ed</span><span 
class="cmbx-10x-x-109">�... </span>vpravo dole. Zobraz� se okno,
     v n&#x011B;m&#382; je mo&#382;n� nastavit prom&#x011B;nn� syst�mu.
     </li>
     <li class="itemize">Najd&#x011B;te prom&#x011B;nnou  <span 
class="cmti-10x-x-109">PATH </span>a klikn&#x011B;te na upravit. Na konec t�to prom&#x011B;nn� napi&#353;te za
     st&#x0159;edn�k cestu k adres�&#x0159;i obsahuj�c�mu soubor gcc.exe (Tedy nap&#x0159;.: ;C:<span 
class="cmsy-10x-x-109">\</span>MinGW<span 
class="cmsy-10x-x-109">\</span>bin<span 
class="cmsy-10x-x-109">\</span>)
     </li>
     <li class="itemize">Pokud prom&#x011B;nn�  <span 
class="cmti-10x-x-109">PATH </span>neexistuje, vytvo&#x0159;te ji.
     </li>
     <li class="itemize">Pozav�rejte v&#353;echna okna.
     </li>
     <li class="itemize">Znovu klikn&#x011B;te na tla&#x010D;�tko  <span 
class="cmbx-10x-x-109">Start</span>, vyberte  <span 
class="cmbx-10x-x-109">P</span><span 
class="cmbx-10x-x-109">&#x0159;</span><span 
class="cmbx-10x-x-109">�slu</span><span 
class="cmbx-10x-x-109">&#353;enstv</span><span 
class="cmbx-10x-x-109">� </span>a  <span 
class="cmbx-10x-x-109">P</span><span 
class="cmbx-10x-x-109">&#x0159;</span><span 
class="cmbx-10x-x-109">�kazov</span><span 
class="cmbx-10x-x-109">&#x00FD; </span><span 
class="cmbx-10x-x-109">&#x0159;</span><span 
class="cmbx-10x-x-109">�dek</span>.
     </li>
     <li class="itemize">V p&#x0159;�kazov�m &#x0159;�dku p&#x0159;ejd&#x011B;te do slo&#382;ky projektu a napi&#353;te  <span 
class="cmtt-10x-x-109">mingw32-make</span>.</li></ul>
<!--l. 323--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">4.2   </span> <a 
 id="x1-260004.2"></a>Ovl�d�n�</h4>
<!--l. 325--><p class="noindent" >Program je konzolov&#x00FD;, ovl�d� se tedy z kl�vesnice. Spust�me ho klasicky p&#x0159;�kazem ./zcuchess
(zcuchess.exe na platform&#x011B; Windows). Program p&#x0159;i spu&#353;t&#x011B;n� vyp�&#353;e hlavi&#x010D;ku, jej�&#382;
sou&#x010D;�st� je i n�pov&#x011B;da a &#x010D;ek� na zad�n� prvn�ho tahu. Tah se zapisuje ve form�tu odkud
mezera kam, tedy nap&#x0159; e2 e3. Pot� program chv�li p&#x0159;em&#x00FD;&#353;l�, na&#x010D;e&#382; vyp�&#353;e sv&#x016F;j tah.
Automaticky se p&#x0159;edpokl�d�, &#382;e &#x010D;lov&#x011B;k hraje za b�l�ho. N�pov&#x011B;du je mo&#382;no kdykoliv vypsat
veps�n�m kl�&#x010D;ov�ho slova help nam�sto tahu. Stejn&#x011B; tak je mo&#382;n� program kdykoliv
ukon&#x010D;it veps�n�m slova exit nam�sto tahu. Pokud nastane mat, program se ukon&#x010D;�
s�m.
<!--l. 327--><p class="noindent" >
   <h3 class="sectionHead"><span class="titlemark">5   </span> <a 
 id="x1-270005"></a>Z�v&#x011B;r</h3>
<!--l. 328--><p class="noindent" >Program hraje &#353;achy dostate&#x010D;n&#x011B; dob&#x0159;e na to aby v nich porazil sv�ho tv&#x016F;rce, zad�n�
semestr�ln� pr�ce proto pova&#382;uji za spln&#x011B;n�, i kdy&#382; k dobr� h&#x0159;e m� program st�le je&#353;t&#x011B; velice
daleko.

<!--l. 330--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">5.1   </span> <a 
 id="x1-280005.1"></a>Probl�my v pr&#x016F;b&#x011B;hu psan� programu</h4>
<!--l. 331--><p class="noindent" >P&#x0159;i b&#x011B;hu programu doch�zelo ke zna&#x010D;n&#x00FD;m �nik&#x016F;m pam&#x011B;ti, kter� se nakonec poda&#x0159;ilo naj�t a
vy&#x0159;e&#353;it za pomoci programu  <span 
class="cmti-10x-x-109">Valgrind</span>. V&#x011B;t&#353;� probl�my nastaly p&#x0159;i pokusech p&#x0159;elo&#382;it program na
syst�mu Windows a to zejm�na:
     <ul class="itemize1">
     <li class="itemize">Bylo  pot&#x0159;eba  si  opat&#x0159;it  po&#x010D;�ta&#x010D;  vybaven&#x00FD;  t�mto  syst�mem.  Nakonec  jsem  pou&#382;il
     virtu�ln� server s Windows, kter&#x00FD; m�me k dispozici v pr�ci.
     </li>
     <li class="itemize">Nastaven�  prom&#x011B;nn�  prost&#x0159;ed�   <span 
class="cmti-10x-x-109">PATH</span>.  Zde  bych  cht&#x011B;l  pod&#x011B;kovat  kolegovi  Karlu
     Vl&#x010D;kovi za trp&#x011B;livost.
     </li>
     <li class="itemize">Samotn� pr�ce s p&#x0159;�kazov&#x00FD;m &#x0159;�dkem ve Windows.
     </li>
     <li class="itemize">Po p&#x0159;ekladu jsem zjistil, &#382;e je rozbit� &#x010D;e&#353;tina (to mi mohlo doj�t hned), tak jsem
     program upravil tak aby pou&#382;�val  <span 
class="cmti-10x-x-109">cestinu</span>.
     </li>
     <li class="itemize">Funkce   <span 
class="cmtt-10x-x-109">clock() </span>nevracela ve Windows spr�vn� v&#x00FD;sledky, zm&#x011B;nil jsem ji na funkci
     <span 
class="cmtt-10x-x-109">time()</span>.</li></ul>
<!--l. 340--><p class="noindent" >Na posledn� chv�li jsem p&#x0159;i h&#x0159;e sv�ho programu proti programu GNU Chess 4 objevil chybu v
ro&#353;�d&#x011B; - program sice kontroloval, zda-li nebylo t�hnuto kr�lem &#x010D;i v&#x011B;&#382;� a zda-li nen� kr�l
p&#x0159;ed, po a b&#x011B;hem ro&#353;�dy v &#353;achu, ale u&#382; nekontroloval, jestli je v&#x011B;&#382; je&#353;t&#x011B; na sv�m
m�st&#x011B;.
<!--l. 342--><p class="noindent" >
   <h4 class="subsectionHead"><span class="titlemark">5.2   </span> <a 
 id="x1-290005.2"></a>Mo&#382;n� vylep&#353;en�</h4>
<!--l. 343--><p class="noindent" >Podle profileru tr�v� program a&#382; &#x010D;tvrtinu &#x010D;asu ve funkci <span 
class="cmtt-10x-x-109">add</span><span 
class="cmtt-10x-x-109">_move </span>(p&#x0159;id�n� tahu do
mno&#382;iny tah&#x016F;). Toto by se dalo vy&#x0159;e&#353;it glob�ln�m z�sobn�kem tah&#x016F;. Proto&#382;e je glob�ln�
z�sobn�k tah&#x016F; statick&#x00FD;, nebylo by z�rove&#x0148; pot&#x0159;eba &#x0159;e&#353;it �niky pam&#x011B;ti. Dal&#353;�m vylep&#353;en�m
zlep&#353;uj�c� hloubku propo&#x010D;tu by bylo nasazen� n&#x011B;jak&#x00FD;ch heuristik do gener�toru tah&#x016F; a
t&#x0159;�d&#x011B;n� tah&#x016F; pro pr&#x016F;b&#x011B;hu kask�dov� metody. V podstat&#x011B; nasazen� jak&#x00FD;chkoli heuristik
uveden&#x00FD;ch u kask�dov� metody v anal&#x00FD;ze. Hru programu by samoz&#x0159;ejm&#x011B; zlep&#353;ila tak�
implementace datab�ze zah�jen� a koncovek. Dal&#353;�m drobn&#x00FD;m zrychlen�m by bylo rozvinut�
pole 8x8, reprezentuj�c�ho &#353;achovnici, na jednorozm&#x011B;rn� pole o 64 prvc�ch. V&#x016F;bec
nejzaj�mav&#x011B;j&#353;� by bylo pou&#382;�t reprezentaci v podob&#x011B; bitov� mapy, ale to by si vy&#382;�dalo n&#x011B;kolik
m&#x011B;s�c&#x016F; studia. Z u&#382;ivatelsk�ho hlediska by se jist&#x011B; hodila mo&#382;nost d�t u&#382;ivateli na
v&#x00FD;b&#x011B;r barvu strany, za kterou chce hr�t, &#x010D;i mo&#382;nost partii ulo&#382;it do souboru a op&#x011B;tovn&#x011B;
na&#x010D;�st.
<!--l. 349--><p class="indent" >   Program byl vyv�jen v integrovan�m v&#x00FD;vojov�m prost&#x0159;ed� NetBeans IDE 7.2.1 na platform&#x011B;
Xubuntu Linux. Mezi dal&#353;� n�stroje pou&#382;it� p&#x0159;i v&#x00FD;voji pat&#x0159;� Valgrind, verzovac� syst�m GIT a
editor VIM. Postupn&#x00FD; v&#x00FD;voj programu a jeho zdrojov� k�dy si lze prohl�dnout na adrese
<span 
class="cmti-10x-x-109">https://github.com/ClaryAldringen/ZCUChess</span>.  
</body></html> 



