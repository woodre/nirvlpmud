#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";

int counter1, counter2;

reset(arg){
    if (arg) return;
  counter1=0;
  counter2=0;
}

long()  { write("This is the dead body of Professor.\n"); }
short() { write("corpse of Professor.\n");}  
id(str)    { return str=="corpse"; }

init() {
  ::init();
  add_action("search","search");
}

search(str){
  object ob;
  if(!str) { notify_fail("Search what?\n"); return 0;}
  if(str=="waistcoat"){
    if(counter1) 
     {
     write("You search in the waistcoat of the corpse to no avail.\n");
     return 1;
     }
     ob=(clone_object("/players/francesco/letters/items/watch.c"));
     move_object(ob,this_player());
     write("You search in the waistcoat of the corpse and find a precious golden watch.\n");
     counter1++;
     return 1;
     }
  if(str=="corpse"){
    if(counter2) 
     {
     write("You search in the corpse to no avail.\n");
     return 1;
     }
     ob=(clone_object("/players/francesco/letters/items/cane.c"));
     move_object(ob,this_player());
     write("You search in the corpse and you find a thin walking cane.\n");
     counter2++;
     return 1;
     }
  if(!str) { notify_fail("Search what?\n"); return 0;}
return 1;
}
    
get(str) {return 0;}



/*** 
     ugly comment
     i made a typo in this file:
     id() { return("corpse"); }
     well, when i typed: look at assistant, it showed this object's long description.
     *MEGA BOGGLE*
***/
