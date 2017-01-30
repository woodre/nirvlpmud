#include "/players/vertebraker/define.h"
inherit ITEM;
int worn;
reset(arg) {
   if(arg) return;
   set_id("ring");
   set_alias("diamond ring");
   set_short("A "+HIC+"diamond"+NORM+" ring");
   set_long(
      "A nice looking diamond ring.  You can wear this\n"+
      "in combination with your other armor.  It looks valuable.\n");
   set_value(1000+random(100));
   set_weight(1); }

init() {
   ::init();
   add_action("wear","wear");
   add_action("remove","remove"); }

drop() { remove("diamond ring"); }

wear(str) {
   object *inv; int x;
   if(id(str)) {
      if(USER != TP) return;
      if(worn) return;
      inv = all_inventory(TP);
      for(x = 0; x < sizeof(inv); x++)
      if(inv[x]->is_wearing_v_ring()) {
         write("You are already wearing a diamond ring.\n");
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

is_wearing_v_ring() { return worn; }

query_type() { return "ring"; }
