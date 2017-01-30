#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("mane");
set_alias("helmet");
set_short("A lion's mane");
set_long(
   "Lion's mane is the most important mark of the king of the savannah.\n"+
   "Not only it does decent protection, yet it also fears the enemies.\n"+
   "It is of a dark brown color rather than blonde one, must be of an\n"+
   "ancient specie of lions, likely extinguished.\n");

set_ac(1);
set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(350);
set_arm_light(1);  /*  makes armor glow if it's > 0  */
}

init() {
  add_action("trade","trade");
  return 1;
}
trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="mane"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 750 coins for this "+(str)+".\n");
      call_other(this_player(),"add_money",(750));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}
