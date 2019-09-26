# Textractor

![How it looks](screenshot.png)

[Español](README_ES.md) ● [简体中文](README_SC.md) ● [日本語](README_JP.md) ● [Русский](README_RU.md) ● [Bahasa](README_ID.md) ● [Português](README_PT.md) ● [Polski](README_PL.md) ●

**Textractor** (a.k.a. NextHooker) is an open-source x86/x64 video game text hooker for Windows/Wine based off of [ITHVNR](http://www.hongfire.com/forum/showthread.php/438331-ITHVNR-ITH-with-the-VNR-engine).<br>
Watch the [tutorial video](https://tinyurl.com/textractor-tutorial) for a quick rundown on using it.

[![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=akashmozumdar%40gmail.com&item_name=Textractor%20development&currency_code=USD)

## Download

Releases of Textractor can be found [here](https://github.com/Artikash/Textractor/releases).<br>
The last release of ITHVNR can be found [here](https://drive.google.com/open?id=13aHF4uIXWn-3YML_k2YCDWhtGgn5-tnO).<br>
Try running vcredist if you get an error when starting Textractor.

## Features

- Highly extensible and customizable
- Auto hook many game engines (including some not supported by VNR!)
- Hook text using /H "hook" codes (most AGTH codes supported)
- Directly extract text using /R "read" codes

## Support

Please let me know of any bugs, games that Textractor has trouble hooking, feature requests, or other suggestions.<br>
If you have trouble hooking a game please email me a place where I can freely download it, or gift it to me on [Steam](https://steamcommunity.com/profiles/76561198097566313/).

## Extensions

See my [Example Extension project](https://github.com/Artikash/ExampleExtension) to see how to build an extension.<br>
See the extensions folder for examples of what extensions can do. 

## Contributing

All contributions are appreciated! Please email (no, I'm not busy!) me at akashmozumdar@gmail.com if you have any questions about the codebase.<br>
You should use the standard process of making a pull request (fork, branch, commit changes, make PR from your branch to my master).<br>
Contributing a translation is easy: just translate the strings in text.cpp as well as this README.

## Compiling

Before compiling *Textractor*, you should get Visual Studio with CMake support, as well as Qt version 5.11<br>
You should then be able to simply open the folder in Visual Studio, and build. Run Textractor.exe.

## Project Architecture

The host (see GUI/host folder) injects texthook.dll (created from the texthook folder) into the target process and connects to it via 2 pipe files.<br>
Host writes to hostPipe, texthook writes to hookPipe.<br>
texthook waits for the pipe to be connected, then injects a few instructions into any text outputting functions (e.g. TextOut, GetGlyphOutline) that cause their input to be sent through the pipe.<br>
Additional information about hooks is exchanged via shared memory.<br>
The text that the host receives through the pipe is then processed a little before being dispatched back to the GUI.<br>
Finally, the GUI dispatches the text to extensions before displaying it.

## Developers

If you're on this list and want your link changed let me know.
- Textractor mainly made by [Me](https://github.com/Artikash) with the help of
  - [DoumanAsh](https://github.com/DoumanAsh)
  - [Niakr1s](https://github.com/Niakr1s)
  - [tinyAdapter](https://github.com/tinyAdapter)
- Spanish translation by [scese250](https://github.com/scese250)
- Turkish translation by niisokusu
- Simplified Chinese translation by [tinyAdapter](https://github.com/tinyAdapter)
- Russian translation by [TokcDK](https://github.com/TokcDK)
- Indonesian translation by [Hawxone](https://github.com/Hawxone)
- Portuguese translation by [TsumiHokiro](https://github.com/TsumiHokiro)
- ITHVNR updated by [mireado](https://github.com/mireado), [Eguni](https://github.com/Eguni), and [IJEMIN](https://github.com/IJEMIN)
- ITHVNR originally made by [Stomp](http://www.hongfire.com/forum/member/325894-stomp)
- VNR engine made by [jichi](https://archive.is/prJwr)
- ITH updated by [Andys](https://github.com/AndyScull)
- ITH originally made by [kaosu](http://www.hongfire.com/forum/member/562651-kaosu)
- Locale Emulator library made by [xupefei](https://github.com/xupefei)
- MinHook library made by [TsudaKageyu](https://github.com/TsudaKageyu)

## Special Thanks

- Everybody adding issues!
