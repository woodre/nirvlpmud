inherit "obj/armor";
#include "/players/jareel/ansi.h"
int charge;
reset() {
  set_name("shield");
  set_id("shield");
  set_short("Iron shield");
  set_long(
"This shield is dull grey in color.  A swirling blue\n"+
"crest placed in the centre of the shield.\n");
  set_ac(1);
  set_type("shield");
  set_weight(2);
  set_value(2000);
}
init(){
  ::init();
    add_action("shield_power","shield_power");
}
check_wear(){
  if(this_player()->query_shield() == this_object()){
    return 1;
}
else{
notify_fail("You are not wearing the shield.\n");
return 0;
}}
