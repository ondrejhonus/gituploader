# About
This is a program that makes it easier to make an update on git.
It allows you to run just 1 command to commit and push a change. 
Instead of ```git add . & git commit -m "[MESSAGE]" & git push```, 
you can just run ```gitup``` and then type your desired commit message.

# Instalation
```
git clone https://github.com/ondrejhonus/gituploader.git

cd gituploader

make gitup
```
### edit your rcfile 
```vim ~/.bashrc``` or ```vim ~/.zshrc``` (depending on your shell)

### add a new line: 
```
alias gitup='/path/to/gituploader/gitup'
```

#### Restart your terminal and you should be able to type ```gitup``` to commit and push an update of your current working repository to github.

# Usage
- Type ```gitup``` into your terminal while being in an initialized git repository
- Specify your commit message
