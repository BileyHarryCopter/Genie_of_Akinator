# Genie of Akinator #

## Short description ##

**Akinator game** is a project from 1sr year of **ILab** course lead by [Ilya Dedinsky](https://github.com/ded32?tab=following).  
This game is self-studying program what asked user to make a with something and try to guess it.

## Principle of recording, gaming and studying ##

Magical knowledge of Akinator is a result of accomplishment following points:

1. The data is loaded with text input in appropriate form in file `sources/data/input.txt`:


![Page of recording tree](https://github.com/BileyHarryCopter/Genie_of_Akinator/blob/main/sources/examples/example_input.png)

2. The program read this text and create an array of lexems ([about lexems read here](http://cs.mipt.ru/wp/wp-content/uploads/2018/09/05a-enumerate.pdf))

3. The program parce a binary tree by the array of lexems.

4. Whole magic of the game is just appropriate bypass of the tree: **NLR bypass** in which we firstly come in central node of and subtree, after this we come in left node of subtree and after successful accomplishment we come in right node of subtree.

## How to install ##

1. Firstly, check your **git version**. If you still haven't git system on your OS, please, be patient to follow all of the instruction points from this site: <https://habr.com/ru/post/588801/>. For checking your own git version write down in command line:

        git --version

2. Now clone the repository with:

        git clone git@github.com:BileyHarryCopter/Genie_of_Akinator.git

## How to make ##

1. Just enter in the directory with clonned repository and launch make:

        cd Akinator   
        make

2. After this you receive file **./start** with Akinator Game. For launching the game you need write down this:

        ./start
