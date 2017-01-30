/* ac averages about just under 2.5, but high weight and move restrictions are big drawbacks. */
#include "/players/jenny/define.h"
inherit "/obj/armor.c";
id(str) { return str == "Goalie Pads" ||  str == "goalie pads" || str == "pads" || str == "leg pads"; } 
reset(arg) {
   ::reset(arg);
   set_name("goalie pads");
   set_ac(2);
   set_value(1200);
   set_weight(3);
   set_save_flag(1);
   set_type("misc");
   set_short("Goalie Pads");
   set_long(
      "This is a pair of big, bulky leg pads used by hockey goaltenders.  These\n"+
      "red and white pads cover from the foot to the waist.  They provide great\n"+
      "protection.  A person wearing them probably wouldn't even feel getting hit\n"+
      "in the legs, but they are cumbersome to move around in.\n");
}
init() {
   ::init();
   add_action("youtripped","north");
   add_action("youtripped","south");
   add_action("youtripped","west");
   add_action("youtripped","east");
   add_action("youtripped","enter");
   add_action("youtripped","out");
   add_action("youtripped","exit");
   add_action("wearing","wear");
}
youtripped() {
   if(worn) {
      write("You trip over your goalie pads.\n");
      return 1; }}

do_special(owner)
{
   if(random(2) == 1)
      {
      tell_object(owner,"\n"+
         "You hear a "+BOLD+"THUMP "+NORM+"against your goalie pads, but feel nothing.\n");
      return -40;}
   return 0;}
wearing(arg) {
   if(!arg) {return 0;}
if(arg == "goalie pads" || arg == "pads" || arg == "Goalie Pads" || arg == "leg pads") {
      write("You carefully strap on your leg pads.\n");
init();
      return 0; }}
