#include "../define.h"
inherit ARMOUR;

reset(arg) {
   if(arg) return;
   set_short("A "+YEL+"gold"+NORM+" ring");
   set_long(
      "  A golden ring that sparkles when you look at it.\n"+
      "There is a small indentation in the side, that you\n"+
      "might be able to peer closer at.\n");
   set_weight(1);
   set_value(500+random(100));
   set_ac(2);
   set_type("ring");
   set_id("gold ring");
   set_alias("v_gold_ring");
}


init() {
   ::init();
   add_action("peer","peer"); }

peer(str) {
   if(id(str) || str == "indentation") {
      write("You peer at the indentation....\n"+
         "\nYou see tiny letters that read 'S.rd.a.. J.w...y'\n"+
         " and you cannot make out the rest.\n");
      return 1; }
}

