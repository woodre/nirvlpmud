#define TPN capitalize(this_player()->query_name())
#define AN capitalize(attacker->query_name())
#include "/open/color.h"

inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("staff");
  set_alias("quarterstaff");
  set_short("Quarterstaff of Death and Destruction");
  set_long(
"This is a dark wooden staff, approximately two meters in\n"+
"length, cut from a tall sapling.  You think it could be used\n"+
"to injure something without actually killing them.\n"
  );
  set_type("polearm");
  set_class(0);
  set_weight(1);
  set_value(10000);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  int W, WC;
  WC=attacker->query_hp()-1;

    W=random(3);
    if (W==0) {
      write("You bash "+AN+" with your Quarterstaff!\n");
      say(TPN+" bashes "+AN+" with his Quarterstaff!\n");
    }
    if (W==1) {
      write("You strike "+AN+" with your Quarterstaff!\n");
      say(TPN+" strikes "+AN+" with his Quarterstaff!\n");
    }
    if (W==2) {
      write("You jab "+AN+" with your Quarterstaff!\n");
      say(TPN+" jabs "+AN+" with his Quarterstaff!\n");
    }
    if (W==3) {
      write("You thrash "+AN+" with your Quarterstaff!\n");
      say(TPN+" thrashes "+AN+" with his Quarterstaff!\n");
    }
  return WC;
}

