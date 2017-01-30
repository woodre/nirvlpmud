#include "/players/martha/define.h"
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("wand");
   set_alias("sword");
   set_type("sword");
      set_short("A Snowflake Magic Wand");
   set_long
   ("This wand could be wielded like a sword since it is\n"+
    "nice and pointy!\n");
   set_class(10);
   set_weight(1);
   set_value(100);
   set_hit_func(this_object());
}

init()
{
  add_action("wield_wand", "wield");
  set_hit_func(this_object());
}

wield_wand(str)
{
  if (str == "wand" && this_player()->query_exp() > 6000)
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
      
      say("A brilliant flash of light emerges from the wand!\n");
      write("The wand emits a brilliant flash of light, knocking your foe down!\n");
      return 5;
      
   }
   return 0;
}
