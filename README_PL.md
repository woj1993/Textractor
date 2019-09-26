# Textractor

![Jak wygląda](screenshot.png)

[English](README.md) ●[Español](README_ES.md) ● [简体中文](README_SC.md) ● [日本語](README_JP.md) ● [Русский](README_RU.md) ● [Bahasa](README_ID.md) ● [Português](README_PT.md)

**Textractor** (także znany jako NextHooker) jest otwarto-zródłowym x86/x64 tłumaczem napisów z gier dla Windows/Wine bazowanym na [ITHVNR](http://www.hongfire.com/forum/showthread.php/438331-ITHVNR-ITH-with-the-VNR-engine).<br>
Oglądnij [wideo z tutorialem](https://tinyurl.com/textractor-tutorial) żeby dowiedzieć się jak go używać.

[![Darowizna](https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=akashmozumdar%40gmail.com&item_name=Textractor%20development&currency_code=USD)

## Ściąganie

Wydania Textractor można znaleźć [tutaj](https://github.com/Artikash/Textractor/releases).<br>
Ostatnie wydanie ITHVNR można znaleźć [tutaj](https://drive.google.com/open?id=13aHF4uIXWn-3YML_k2YCDWhtGgn5-tnO).<br>
Spróbuj zainstalować vcredist jeżeli dostajesz błędy podczas uruchamiania Textractor.

## Zalety

- Wysoce rozszerzalny i konfigurowalny
- Automatyczne podłączanie się pod wiele silników gier (włączając w to również niewspierane przez VNR!)
- Wydobycie tekstu z użyciem kodów /H "hook" (większość kodów AGTH obsługiwana)
- Bezpośrednie wydobycie tekstu używając kodów /R "read"

## Wsparcie

Proszę daj mi znać jeśli znajdziesz jakieś błędy, gry do których Textractor nie jest wstanie się podłączyć, sugestie rozwoju lub inne.<br>
Jeśli masz trudności z podłączeniem do gry proszę napisz emeila z informacją gdzie mogę ją ściągnąć za darmo, albo podaruj mi ją na [Steam](https://steamcommunity.com/profiles/76561198097566313/).

## Rozszerzenia

Zobacz mój [projekt przykładowego rozszerzenia](https://github.com/Artikash/ExampleExtension) żeby zrozumieć jak budować rozszerzenia.<br>
Zobacz folder z rozszerzeniami żeby zobaczyć co są w stanie zrobić. 

## Wkład w projekt

Każdy wkład jest doceniany! Email do mnie (nie, nie jestem zajęty!) akashmozumdar@gmail.com jeżeli masz jakieś pytania odnośnie kodu.<br>
Powinieneś użyć standardowego procesu pull requesta (sklonować, utworzyć gałąź, potwierdzić zmiany, utworzyć PR z twojej gałęzi do mojej głównej).<br>
Wkład w tłumaczenie jest łatwy: przetłumacz tylko napisy w text.cpp i w tym README.

## Kompilacja

Przed kompilacją *Textractor*, powinieneś zdobyć Visual Studio z wsparciem CMake oraz Qt w wersji 5.11<br>
Powinieneś być w stanie po prostu otworzyć folder w Visual Studio, zbudować i uruchomić Textractor.exe.

## Architektura projektu

Host (zobacz folder GUI/host) wszczepuje texthook.dll (stworzone z folderu texthook) w docelowy proces i łączy go przez 2 pliki kanałowe.<br>
Host pisze do hostPipe, texthook pisze do hookPipe.<br>
texthook czeka na połączenie ze swoim kanałem, wtedy "wbija" kilka instrukcji w każdą funkcje wypisującą tekst (e.g. TextOut, GetGlyphOutline) co sprawia że ich tekst jest przepuszczany przez kanał.<br>
Dodatkowe informacje o połączeniu są wymieniane pamięcią współdzieloną.<br>
Tekst który host dostaje poprzez kanał jest trochę obrabiany przed byciem wysłanym z powrotem do GUI.<br>
W końcu GUI wysyła tekst do rozszerzeń przed wyświetleniem go.

## Twórcy

Jeśli jesteś na tej liście i chcesz zmienić twój link to daj mi znać.
- Textractor stworzony głównie przeze [mnie](https://github.com/Artikash) z pomocą
  - [DoumanAsh](https://github.com/DoumanAsh)
  - [Niakr1s](https://github.com/Niakr1s)
  - [tinyAdapter](https://github.com/tinyAdapter)
- Hiszpańskie tłumaczenie stworzone przez [scese250](https://github.com/scese250)
- Tureckie tłumaczenie stworzone przez niisokusu
- Uporszczone Chińskie tłumaczenie stworzone przez [tinyAdapter](https://github.com/tinyAdapter)
- Rosyjskie tłumaczenie stworzone przez [TokcDK](https://github.com/TokcDK)
- Indonezyjskie tłumaczenie stworzone przez [Hawxone](https://github.com/Hawxone)
- Portugalskie tłumaczenie stworzone przez [TsumiHokiro](https://github.com/TsumiHokiro)
- Polskie tłumaczenie stworzone przez [woj1993](https://github.com/woj1993/)
- ITHVNR zaktualizowny przez [mireado](https://github.com/mireado), [Eguni](https://github.com/Eguni), and [IJEMIN](https://github.com/IJEMIN)
- ITHVNR stworzony orginalnie przez [Stomp](http://www.hongfire.com/forum/member/325894-stomp)
- Silnik VNR stworzony przez [jichi](https://archive.is/prJwr)
- ITH zaktualizowny przez [Andys](https://github.com/AndyScull)
- ITH stworzony orginalnie przez [kaosu](http://www.hongfire.com/forum/member/562651-kaosu)
- Biblioteki Locale Emulator stworzone przez [xupefei](https://github.com/xupefei)
- Biblioteki MinHook stworzone przez [TsudaKageyu](https://github.com/TsudaKageyu)

## Specjalne podziękowania

- Wszystkim zgłaszającym błędy!
