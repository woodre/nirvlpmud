#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("apeskin");
set_alias("shield");
set_short("Apeskin");
set_long(
   "The apeskin shows a black color and looks very light.\n"+
   "Not only it gives good protection, yet it also shields\n"+
   "your body without impeding your movements.\n");

set_ac(1);
set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(200);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

query_save_flag() { return 1; } 

init() {
  ::init();
  add_action("trade","trade");
}

trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="apeskin"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 1000 coins for this "+(str)+".\n");
      call_other(this_player(),"add_money",(1000));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}

