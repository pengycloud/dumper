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
#### The way it works is that chromium based browsers encrypt and save passwords locally in a file called "Login Data" and to in order to decrypt the passwords a file called "Local State" is used. And Firefox uses logins.json and key4.db for the same puprose.
#### So the tool will search for these files names and send them to the specified telegram bot user with the caption of the whole path of the file so that one can know which "login.json" file is related to which "key4.db" file via their path.

ℹ️ Unrelated "key4.db","login.json","Local Data","Local State" files could be send along too since the tool searchs for any file with these names!

#### The dump can be used as:
- **Firefox**: Store the "login.json" with along with its "key4.db" in a directory and then run
          `firefox -profile <dir>`
          firefox will open up and opening passwords in there will show all the saved passwords.
- **Chromium-based**: copy your own "Login Data" and "Local State" files for the browser specified in the caption(path of the file) to a safe directory and then replace your the "Login Data" and "Local State" with the dumped ones.‼️IF YOU DON'T SAVE YOUR OWN "Login Data" and "Local State" FILES FIRST, YOU COULD **LOSE** YOUR SAVED PASSWORDS‼️
