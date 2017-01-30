#include <ansi.h> 
inherit "obj/weapon.c";
reset(arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("riding crop");
  set_alias("crop");
  set_short("A Riding Crop");
  set_long("A fine riding crop, with a center of steel.\n\
It would be very painful to be hit with this.\n");
  set_class(18);
  set_weight(3);
  set_value(2000);
  set_hit_func(this_object());
}

weapon_hit(attacker)
{
  int W;
  W = random(12);
  if(W > 9)
  {
    say("The crop slices through the enemy with it's steel core.\n"+
        RED+"               BLOOD"+NORM+" flows freely from the wound.\n");
    write("The crop slices through your enemy with it's steel core.\n"+
          RED+"               BLOOD"+NORM+" flows freely from the wound.\n");
    return 5;
  }
  return;
}
