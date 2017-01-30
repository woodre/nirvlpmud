#include "/players/martha/define.h"
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("staff");
   set_alias("club");
   set_type("club");
      set_short("A Candy Staff");
   set_long
   ("This staff is filled with candy and coated with chocolate.\n"+
    "You don't want to eat it though, try wielding it instead.\n");
   set_class(10);
   set_weight(1);
   set_value(100);
   set_hit_func(this_object());
}

init()
{
  add_action("wield_staff", "wield");
  set_hit_func(this_object());
}

wield_staff(str)
{
  if (str == "staff" && this_player()->query_exp() > 6000)
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
      
      say("The staff releases a spray of candies!\n");
      write("The staff sprays your enemy with a spatter of candies!\n");
      return 5;
      
   }
   return 0;
}
