inherit "obj/armor";
#include "/players/snow/color.h"
reset(arg){
if(arg) return;
 ::reset();
  set_name("steel plate");
  set_alias("plate");
  set_short(BLUE+BOLD+"Blessed Plate Armor"+OFF+OFF);
  set_long("An exceedingly strong suit of Steel Plate Armor.\n"+
           "It glows with a soft blue aura.\n");
  set_ac(5);
  /* powerful armor should be powerful against magic too - Ill May 05 */
  set_params("magical",5,0,0);
  set_type("armor");
  set_weight(5);
  set_light(2);
  set_value(4000);
}

do_special(owner) {
  object att;
  if(!owner || !owner->query_attack()) return 1;
  if(!owner->is_player()) return 1;
  att = owner->query_attack();
  if(att->query_alignment() < 10) return -6;
  if(att->query_wc() > 20 && owner->query_alignment() > 200 &&
    owner->query_attrib("pie") > random(70)) {
  tell_object(owner, BLUE+BOLD+"Your plate armor glows brightly!\n"+OFF+OFF);
  owner->add_hit_point(2); return 1; }
  return 0; }
