#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("nail");
set_alias("ring");
set_short("Brontosaurus's toenail");
set_long(
   "This grey large toenail has a hole in the middle.  It is heavy\n"+
   "and smells bad.  It might be used as a ring even though its\n"+
   "dimensions and weight could impede some movements.\n");

set_ac(1);
set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(2);
set_value(200);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

query_save_flag() { return 1; } 

init() {
  add_action("trade","trade");
  add_action("smell","smell");
  return 1;
}

smell(str){
   if(str=="ring") {write("You smell the bad smelling of the toenail.\n"); 
   return 1;}
return 0;
}
trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="toenail"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 640 coins for this "+(str)+".\n");
      call_other(this_player(),"add_money",(640));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}


