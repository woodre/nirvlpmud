#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

reset(arg){
   if(arg) return;
   
   set_id("clue");
   set_weight(1);
   
   set_short("A "+HIB+"CLUE"+NORM+" from "+HIW+"Vanna"+NORM);
   set_long("One of her most famous Clues!!!\n"+
            "     Someone felt you needed this!!!\n"+
            "      \n"+ 
      MAG+"                    Another creation from Dreamspeakr\n"+NORM);
}
