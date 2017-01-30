
id(str){ return str == "tank" || str == "gas"; }
short(){ return "A magical tank of laughing gas (nitrous)"; }
get(){ return 1; }
query_value(){ return 150; }
long(){ 
    write("A magical tank of laughing gas, complete with hoses and mask.\n");
    write("It has an infinite number of doses.  To operate, the command is:\n");
    write("'dose <player>'.\n");
}

init(){
     add_action("dose", "dose");
}

dose(str){
     object dose;
     if(!str){ write("Usage: dose <player>\n"); return 1; }
     dose = clone_object("players/deathmonger/MISC/dose");
     if(!present(str, environment(this_player()))){
       write("That is not here.\n");
       return 1;
     }
if(present(str,environment(this_player()))->query_invis()) {
   write("That is not here.\n"); return 1; }
      if(present(str, environment(this_player()))->query_level() >= 21){
        write("A wizard wouldn't find that very funny.\n");
        return 1;
     }
     move_object(dose, present(str, environment(this_player())));
     write("You apply the mask to "+str+"'s face and administer \n");
     write("a dose of laughing gas.\n");
     say(capitalize(this_player()->query_name())+" gives "+str+" a dose of potent laughing gas.\n");
     tell_object(present(str, environment(this_player())),
     capitalize(this_player()->query_name())+" applies a mask to your "+
     "face, delivering a dose of laughing gas.\n");
     return 1;
}
