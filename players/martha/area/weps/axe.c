#include "/players/martha/define.h"
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("axe");
   set_alias("axe");
   set_type("axe");
      set_short("A Large Candy Cane Axe");
   set_long
   ("This axe has a nice and sharp blade.  It has been used\n"+
    "to cut down many peppermint trees and it may help you\n"+
    "in your search for the King.\n");
   set_class(10);
   set_weight(1);
   set_value(100);
   set_hit_func(this_object());
}

init()
{
  add_action("wield_axe", "wield");
  set_hit_func(this_object());
}

wield_axe(str)
{
  if (str == "axe" && this_player()->query_exp() > 6000)
  {
    notify_fail("You are too experienced to wield this.\n");
    return 0;
  }
  write("Woot!\n");
  ::wield(str);
  return 1;
}

weapon_hit(attacker){
   
   int W;
   W = random(12);
   if(W > 9)  {
      
      say("The axe slices an arm like a lumberjack slicing a tree!\n");
      write("The axe shakes in your hand as you hack deeply into your enemy!\n");
      return 5;
      
   }
   return 0;
}
