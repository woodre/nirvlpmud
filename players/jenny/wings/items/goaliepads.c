#include "/players/jenny/define.h"
inherit "/obj/armor.c";
int num;
reset(arg) {
   ::reset(arg);
  if(arg) return;
   set_name("goalie pads");
  set_alias("pads");
   set_ac(2);
   set_value(1200);
   set_weight(3);
   set_type("pants");
   set_short("Goalie Pads");
   set_long(
      "This is a pair of big, bulky leg pads used by hockey goaltenders.  These\n"+
      "red and white pads cover from the foot to the waist.  They provide great\n"+
      "protection.  A person wearing them probably wouldn't even feel getting hit\n"+
      "in the legs, but they are cumbersome to move around in.\n");
}
init() {
   ::init();
   add_action("wearing","wear");
}
do_special(owner)
{
   num = random(60);
   if(num < 4)
      {
      tell_object(owner,"\n"+
         "You hear a "+BOLD+"THUMP "+NORM+"against your goalie pads, but feel nothing.\n");
      return 5;}
   if(num == 29) {
      tell_object(owner,"\n"+
         "You trip over your goalie pads.\n");
      return -4;}
   return 0;}
wearing(arg) {
   if(!arg) {return 0;}
   if(arg == "goalie pads" || arg == "pads" || arg == "Goalie Pads" || arg == "leg pads") {
      write("You carefully strap on your leg pads.\n");
      return 0; }}
