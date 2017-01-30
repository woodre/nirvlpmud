#include "/players/vertebraker/define.h"
inherit ITEM;
int worn;
reset(arg) {
   if(arg) return;
   set_id("bracelet");
   set_alias("emerald bracelet");
   set_short("An "+HIG+"emerald"+NORM+" bracelet");
   set_long(
      "A glittering green emerald bracelet that you can\n"+
      "wear with your other armor. It is very fashionable.\n");
   set_value(500+random(100));
   set_weight(1); }

init() {
   ::init();
   add_action("wear","wear");
   add_action("remove","remove"); }

drop() { remove("emerald bracelet"); }

wear(str) {
   object *inv; int x;
   if(id(str)) {
      if(USER != TP) return;
      if(worn) return;
      inv = all_inventory(TP);
      for(x = 0; x < sizeof(inv); x++)
      if(inv[x]->is_wearing_v_bracelet()) {
         write("You are already wearing a emerald bracelet.\n");
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

is_wearing_v_bracelet() { return worn; }

query_type() { return "bracelet"; }
