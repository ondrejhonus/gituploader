# About
This is a program that makes it easier to make an update on git.
It allows you to run just 1 command to commit and push a change. 
Instead of ```git add . & git commit -m "[MESSAGE]" & git push```, 
you can just run ```gitup``` and then type your desired commit message.

# Dependencies
- ### Readline and git
    - ##### Arch: 
        ```
        sudo pacman -S readline git
        ```
    - ##### Debian: 
        ```
        sudo apt-get install libreadline-dev libreadline8 git
        ```

# Instalation
```
git clone https://github.com/ondrejhonus/gituploader.git

cd gituploader

# You might get some errors on debian (tested on ubuntu server), but it should still work
sudo make install
```

# Usage
- Type ```gitup``` into your terminal while being in an initialized git repository
- Specify your commit message

I recommend using [github-cli](https://cli.github.com/) with this and when you want to make a new github repo type:
```
git init

gh repo create

gitup
```
It's super fast and you don't even have to leave your terminal!
