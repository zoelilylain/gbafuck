# gbafuck
WIP Brainfuck Interpreter for Game Boy Advance using DevKitPro

## Building
You will need DevKitPro installed. Specifically, the gba-dev package they provide.  
After that, just run make. You should get a .gba file for use on flashcarts or emulators.

## Keybinds
A adds, B subtracts, Select clears, L and R for navigating Cells, Start shows the current cell's value.  
Dpad will be for executing up to four user-provided programs.

## How to add programs to the dpad binds
in main.c, down at the end of the file are four commented out if statements.  
These are to be used for user-provided brainfuck programs.  
This feature is not implemented yet, so I would suggest you leave them alone for right now.

## Warning!
This is a WIP! There are only 100 memory cells at the moment! A couple commands are missing!

## Thanks
The DevKitPro team, for providing example code and, well, the devkit.
