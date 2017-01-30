#include "../define.h"
inherit WEAPON;

reset(arg) {
   if(arg) return;
   set_name("staff");
   set_alias("old staff");
   set_type("club");
   set_short("An old staff");
   set_value(50+random(10));
   set_long(
      "This is an old wooden staff, hewn\n"
      +"from a tired old hickory branch.\n");
   set_weight(2);
   set_hit_func(TO);
   set_class(10); }

weapon_hit(attacker) {
   if(!random(3)) {
      write("You whack the staff against "+attacker->QN+"'s head!\n");
      say(TPN+" whacks the staff against "+attacker->QN+"'s head!\n",attacker);
      tell_object(attacker,TPN+" whacks the staff against your head!\n");
      return 1; } }
