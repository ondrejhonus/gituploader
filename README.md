# About
This is a program that makes it easier to make an update on git.
It makes 3 git commands into one. instead of ```git add . & git commit -m "[MESSAGE]" & git push```, 
you can just type ```gitup``` and then type the commit message.

# Instalation
```
git clone https://github.com/ondrejhonus/gituploader.git

cd gituploader

make
```
### edit your rcfile 
```vim ~/.bashrc``` or ```vim ~/.zshrc``` (depending on your shell)

### add a new line: 
```
alias gitup='/home/qwerti/Documents/GitHub/gituploader/gitup'
```

#### Restart your terminal and you should be able to type ```gitup``` to push a commit of your current working repository.

# Usage
- Type ```gitup``` into your terminal while being in an initialized git repository
- Specify your commit message