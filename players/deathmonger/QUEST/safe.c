
int unlocked, open, combo;
id(){ return "safe"; }
short(){
     if(open == 1){
       return "A safe (open)"; }
     return "A safe"; }
long(str){
     if(str == "panel") extra_long();
     if(open == 1 && str == "in safe") open_long();
     write("A largish safe.  There is a panel on the side.\n");
}

init(){
    add_action("open", "open");
    add_action("press", "press");
    add_action("press", "push");
}

extra_long(){ 
    write("There are four rows of numbered buttons on the safe:\n\n");
    write("	1	1	1	1\n");
    write("	2	2	2	2\n");
    write("	3	3	3	3\n");
    write("	4	4	4	4\n");
    write("	5	5	5	5\n");
    write("	6	6	6	6\n");
    write("	7	7	7	7\n");
    write("	8	8	8	8\n");
    write("	9	9	9	9\n");
    write("	0	0	0	0\n");
    write("\n");
    write("The Keeper of the Combination lives in a cave in the land\n");
    write("of Rabbit Bliss.\n");
    return 1;
}

open_long(){
     write("Arrrgh! There's another safe in here!\n");
     return 1;
     }
press(str){
     if(!str){
       write("Press what?\n");
       return 1;
     }
     if(str = present("combo", this_player())->query_combo()){
       write("The safe clicks loudly.\n");
       unlocked = 1;
       return 1;
     }
     else {
     write("Syntax: press <combination>\n");
     return 1;
     }
}

open(){
     if(unlocked == 1){
       write("You open the safe.\n");
       open = 1;
       return 1;
     }
     write("The safe is quite locked.\n");
     return 1;
}
