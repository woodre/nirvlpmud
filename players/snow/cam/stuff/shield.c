/*
Found on White Knight, this shield will protect its wear by adding
one (1) hp vs evil monsters of wc > 20 if random(40) is less than
wearer's piety.
*/
inherit "obj/armor";
#include "/players/snow/color.h"
reset(arg){
if(arg) return;
::reset();
  set_name("blessed shield");
  set_alias("shield");
  set_short(BLUE+BOLD+"Blessed Shield"+OFF+OFF);
  set_long(
"This shield of glowing blue will protect its wearer from\n"+
"evil in most any form.\n");
  set_ac(2);
  set_type("shield");
  set_weight(2);
  set_light(2);
  set_value(2000);
}

do_special(owner) {
  object att;
  if(!owner || !owner->query_attack()) return 1;
  if(!owner->is_player()) return 1;
  att = owner->query_attack();
  if(att->query_alignment() > 10) {
    if(!random(10)) {
      tell_object(owner,BLUE+BOLD+"Your Blessed Shield shatters!\n");
      command("drop blessed shield", owner);
      destruct(this_object());
      } return -4; }
  if(att->query_wc() > 20 && att->query_alignment() < 0 &&
    owner->query_attrib("pie") > random(80)) {
  tell_object(owner,BLUE+BOLD+"Your shield glows bright!\n"+OFF+OFF);
  owner->add_hit_point(1); return 1; }
  return 0; }
