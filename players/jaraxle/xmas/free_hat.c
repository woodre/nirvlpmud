#include "/players/jaraxle/define.h"
inherit "obj/armor";

void
set_type(string str) {
   type = str;
}
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("ears");
   set_alias("bunny ears");
   set_id("ears");
   set_long(
      "This is a pair of "+HIW+"fuzzy white"+NORM+" rabbit ears, with "+HIM+"pink"+NORM+" centers.\n");
   
   set_ac(0);
   set_type("easter");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(0);
}
short(){ return ""+HIW+"Bunny Ears"+NORM+""+(worn_by?" "+HIW+"("+NORM+"worn on head"+HIW+")"+NORM+"":""); }

do_special(owner) {
   if(!random(6)) {
      tell_object(owner, "\tYou wiggle your ears.\n");
      return 1; }
}
query_save_flag(){ return 1; }
