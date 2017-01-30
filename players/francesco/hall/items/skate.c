#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("skates");
set_alias("boots");
set_short("Ice skates");
set_long(
   "These ice skates have been often used by Katarina Witt, during her shows,\n"+
   "namely the 'Divas on ice'.  Their blade is sharp, to better carve the ice \n"+
   "during the turns and the jumps.  Can be worn, like any other pair of shoes.\n"+
   "Something can be 'view'ed on their 'blade'.\n");
set_ac(1);
set_type("boots");  
set_weight(1);
set_value(350);
}

init() {
:: init();
  add_action("trade","return");
  add_action("read","read");
  add_action("view","view");
  return 1;
}

trade(str){
  if(!str) {
  notify_fail("What do you want to return?\n");
  return 0; }
    if(str=="skates" || str=="ice skates"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be returned in this room.\n");
       return 1;}
      write("The narrator replies:  'Thank you, thank you, I always\n"+
            "wanted to have a reminder of the great Katarina Witt and\n"+
            "now I am very happy that you brought these ice skates to\n"+
            "me.  Please, take these coins as a sincere mark of thanks.'\n");    
      call_other(this_player(),"add_money",(1550));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can return here.\n");
  return 0;
}

view(str) {       
if(environment() != this_player()) {notify_fail("You must get the ice skates first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to view?\n"); return 0; }
   if(str=="sole")  {write("On the blade there are some engravings to read.\n"); return 1;}
   notify_fail("What do you want to view?\n"); return 0; 
return 1;
}

read(str) {       
if(environment() != this_player()) {notify_fail("You must get the ice skates first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to read?\n"); return 0; }
   if(str=="engravings")  {write("'Return' them to Runi, the narrator.  \nHe will appreciate.\n\nSincerely, \nKatarina Witt\n"); return 1;}
   notify_fail("What do you want to read?\n"); return 0; 
return 1;
}
