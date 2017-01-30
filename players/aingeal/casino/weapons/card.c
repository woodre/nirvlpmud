/* Penn Jillette's Playing Card */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "obj/weapon.c";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("card");
  set_alias("playing card");
  set_short("Playing Card");
  set_long("The playing card has a stylized picture of Las Vegas with a\n\
Penn & Teller' logo on one side, and shows the 3-of-clubs on\n\
the other.  Although it has clearly been used many times, one\n\
edge of the card remains razor-sharp.\n");
  set_class(10);
  set_weight(1);
  set_value(500);
  set_type("card");
  set_hit_func(this_object());
}

weapon_hit(attacker)
{
  if(random(20)>16)
  {
    write("\n\t" + RED + "You SLASH your foe across the face!\n" + "\n\tBlood "
      + WHT + "SPLATTERS" + RED + " everywhere!" + NORM + "\n");
    attacker->hit_player(10);
    return 1;
  }
  return 1;
}
