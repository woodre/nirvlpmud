#include "/players/jaraxle/define.h"
inherit "/obj/treasure.c";
query_save_flag() { return 1; }
id(str) { return str == "phoenix tear" || str == "tear"; }
long() {
   write(
      "This is a tear from a "+RED+"Phoenix"+NORM+".  Legend says\n"+
      "if you rub the tear into your wounds, they will heal.\n");
   return 1;
}
query_weight() { return 1; }
get() { return 1; }
value() { return 0; }
init() {
   add_action("rub_tear","rub");
}
int healnum;
reset(arg) {
   if(!arg) healnum = 3;
   set_short("A "+RED+"Phoenix"+NORM+" Tear");
}
rub_tear(str) {
   if(!str){ notify_fail("Rub what?\n"); return 0; }
   if(!id(str)) return (notify_fail("You may rub " + short_desc + ".\n"), 0);
   if(environment() != this_player()) return 0;
   write(
      "You rub the "+RED+"Phoenix"+NORM+" tear into your wounds.\n");
   if(healnum == 3) {
      write("You can rub this tear into your wounds two more times.\n");
   }
   if(healnum == 2) {
      write("You can rub this tear into your wounds one more time.\n");
   }
   say(
      capitalize(this_player()->query_name())+" rubs a "+RED+"Phoenix"+NORM+" tear into their wounds.\n");
   call_other(this_player(),"heal_self",100);
   healnum --;
   if(healnum < 1) {
      write("You just rubbed in the last bit of the "+RED+"Phoenix"+NORM+" tear.\n");
      destruct(this_object()); this_player()->recalc_carry();
      return 1;
   }
   return 1;
}

