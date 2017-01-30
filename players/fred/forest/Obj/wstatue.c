#include "/players/fred/ansi.h"
inherit "/obj/treasure.c";

reset (arg) {
	set_id("statue");
	set_short(BOLD+"A "+HIC+"large "+RED+"Statue"+NORM);
	set_long(
      "  A huge marble statue of a Woodchuck riding\n"+
      "a Zamboni.  The woodchuck seems to have a \n"+ 
      "smug grin on it's face.  This statue is for all\n"+
      "those little woodchucks that never got their chance.\n"+
      "A small bronze plaque sits at the base.\n");
}

init(){
  ::init();
     add_action("readem", "read");
     add_action("lookem", "l");   
  }

readem(str){
  if(!str) { write("What would you like to read?\n"); return 1; }
  if(str == "plaque"){
  write(BOLD+"\n\tWOODCHUCKS"+MAG+" ROX!\n"+NORM);
  return 1; }
  }

lookem(str){
  if(str == "at plaque"){
  write("Maybe you could 'read' it.\n");
  return 1; }
  } 

query_weight() {
	return 5000;
      } 

