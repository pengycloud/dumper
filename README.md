# Browser Password Dumper
---
## ⚠️ Disclaimer
#### This tool is for educational purposes only! You are responsible for any misuse or damages caused! Use only on systems you own or have permission for, for the sole purpose of understanding what a simple infostealer could do.
#
> ### ℹ️ A dumb and stupidly easy browser password(locally saved) dumper that runs on linux.
#
### This is a demo of how one could try to steal passwords saved on:
- [x] **Chromium-based** browsers like ***Chrome***, ***Brave***, ***Microsoft Edge***, ***Opera***, etc and
- [x] **Firefox**
#
### Requirements:
- `Telegram Bot`
- `libcurl`

#### It requires a [Telegram API Token](https://core.telegram.org/bots/api) and [Chat ID](https://core.telegram.org/api/bots/ids#chat-ids) of the Bot user.

#### Getting libcurl:
- #### Ubuntu/Debian 
        sudo apt install libcurl4-openssl-dev
- #### Fedora / CentOS / RHEL:
        sudo dnf install libcurl-devel
- #### Arch Linux
        sudo pacman -S curl
### Compile:
      gcc dumper.c -o dumper -lcurl
#
> ### **Notice**:
>> ‼️ This tool will try to <mark>**self-destruct**</mark> as it finishes running and also <mark>**there won't be any output**</mark> from it.
#
### Usage:
- **chat_id** and **token** need to be assigned first. Then run it as:

      ./dumper
