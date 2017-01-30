
id(str){ return str == "handcuffs"; }
short(){ return "Inquisition handcuffs (worn)"; }
long(){
     write("Inescapable Inquisition handcuffs. Designed by Deathmonger \n");
     write("himself\n");
}

init(){
     add_action("not","not");
     add_action("not","dest");
     add_action("not","quit");
     add_action("not","clone");
     add_action("not","fc");
     add_action("not","home");
     add_action("not","goto");
}

drop(){ return 0; }
get(){ return 1; }
not(){
     write("You rattle your chains\n");
     say(this_player()->query_real_name()+" rattles his chains.\n");
     return 0;
}

