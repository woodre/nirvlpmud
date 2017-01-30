inherit "/obj/treasure.c";
#pragma combine_strings
#include <ansi.h>
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define POS this_player()->query_possessive()
#define MOCO move_object(clone_object
#define TO this_object()
query_save_flag() { return 1; }
id(str) { return str == "cube" || str == "bazaar cube"; }
long() {
   write(
      "This is a strange cube, rumoured to have "+RED+"healing"+NORM+" properties.\n"+
      "Simply Turn the cube to unlock its potential.\n");
   return 1;
}
query_weight() { return 1; }
get() { return 1; }
value() { return 0; }
init() {
   add_action("turn_cube","turn");
}
int healnum;
reset(arg) {
   if(!arg) healnum = 3;
   set_short("Bazaar "+HIC+"cube"+NORM+"");
}
turn_cube(str) {
   if(!str){ notify_fail("turn what?\n"); return 0; }
   if(!id(str)) return (notify_fail("You may turn " + short_desc + ".\n"), 0);
   if(environment() != this_player()) return 0;
   write(
      "You turn the "+HIC+"cube"+NORM+", and "+HIY+"light"+NORM+" is absorbed into your body from the cube.\n");
   if(healnum == 3) {
      write("You can turn this cube "+RED+"two"+NORM+" more times.\n");
   }
   if(healnum == 2) {
      write("You can turn this cube "+RED+"one"+NORM+" more time.\n");
   }
   say(
      capitalize(this_player()->query_name())+" turns a cube and calls a healing "+HIY+"Light"+NORM+" to heal their wounds.\n");
   call_other(this_player(),"heal_self",100);
   healnum --;
   if(healnum < 1) {
      write("You just turned the "+HIC+"cube"+NORM+" for the last time, and it crumbles to dust.\n");
      destruct(this_object()); this_player()->recalc_carry();
      return 1;
   }
   return 1;
}