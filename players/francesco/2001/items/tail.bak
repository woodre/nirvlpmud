#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("tail");
set_alias("bracers");
set_short("Brontosaurus's tail");
set_long(
   "This big and heavy tail could be used as a good defense\n"+
   "when wrapped around your left arm.  Of course, its high\n"+
   "weight could be a drawback since it could limit the agility.\n");

set_ac(2);
set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(3);
set_value(200);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

query_save_flag() { return 1; } 


init() {
  add_action("trade","trade");
  return 1;
}

trade(str){
  if(!str) return 0;
   if (present(str)==this_object()) {
    if(!present("narrator",environment(this_player()))) return 0;
     write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 700 coins for this tail.\n");
     call_other(this_player(),"add_money",(700));
     destruct(this_object());
     return 1;}
return 0;}

