#include "/players/vertebraker/define.h"
inherit ITEM;
int worn;
reset(arg) {
   if(arg) return;
   set_id("necklace");
   set_alias("pearl necklace");
   set_short("A "+HIW+"pearl"+NORM+" necklace");
   set_long(
      "A beautiful strand of small white pearls attached to a\n"+
      "thin line.  It extends around the neck and can be worn\n"+
      "in addition to other armors.  It looks valuable.\n");
   set_value(400+random(100));
   set_weight(1); }

init() {
   ::init();
   add_action("wear","wear");
   add_action("remove","remove"); }

drop() { remove("pearl necklace"); }

wear(str) {
   object *inv; int x;
   if(id(str)) {
      if(USER != TP) return;
      if(worn) return;
      inv = all_inventory(TP);
      for(x = 0; x < sizeof(inv); x++)
      if(inv[x]->is_wearing_v_necklace()) {
         write("You are already wearing a pearl necklace.\n");
         return 1; }
      write("You wear "+short_desc+".\n");
      say(TPN+" wears "+short_desc+".\n");
      worn = 1; return 1; }
}

remove(str) {
   if(id(str)) {
      if(USER != TP) return;
      if(!worn) return;
      write("You remove "+short_desc+".\n");
      say(TPN+" removes "+short_desc+".\n");
      worn = 0; return 1; }
}

short() {
   if(!worn) return short_desc;
   else return short_desc+" (worn)"; }

is_wearing_v_necklace() { return worn; }

query_type() { return "necklace"; }
