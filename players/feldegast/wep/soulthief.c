/*
After exhaustive testing, this weapon averaged 9 points of damage on
an armorless target.  Here's a list to put that in context:
        Air                15
	Deathmace          11
        Tsurugi            11
        Shurato            10
	Scimitars          10
        Sword of Spirits   10
        Soulthief           9
        Crystal Longsword   9
        Shadowstaff         8

This weapon is one of the prizes for the weekly tournament, so it's not
easy to get, either.
*/

#include "/players/feldegast/defines.h"
inherit "obj/weapon.c";

int energy;
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("soulthief");
  set_alias("longsword");
  set_short(HIM+"Soul"+BLK+"thief"+NORM);
  set_long(
"Soulthief is a longsword made from some alloy you are unfamiliar\n"+
"with.  Its grey blade is approximately a yard in length.  Its hilt\n"+
"is decorated with silver gilt and the name 'Soulthief' is etched on\n"+
"the crosspiece.  The pommelstone is a beautiful black pearl.\n"
  );
  set_type("sword");
  set_class(17);
  set_weight(5);
  set_value(1500);
  set_hit_func(this_object());
}
weapon_hit(attacker) {
  int W, dam, bonus;
  W=random(9);
  switch(W) {
    case 0:
      tell_room(environment(environment()),
        "\n\t\t"+HIM+"Soul"+BLK+"thief"+NORM+" flashes brightly as twisting\n"+
        "\t\ttendrils of "+HIM+"soul energy"+NORM+" are torn\n"+
        "\t\taway from "+attacker->QN+"!\n\n");
      dam=random(5);
      attacker->heal_self(-dam);
      energy+=dam;
      bonus+=1;
      if(random(TP->query_attrib("wil")) < 17) break;
    case 1:
      tell_room(environment(environment()),
        "\n"+HIM+"Soul"+BLK+"thief"+NORM+" keens loudly as "+environment()->QN+" swings it in a blurring arc.\n\n");
      dam=random(2);
      attacker->heal_self(-dam);
      energy+=dam;
      bonus+=4;
      break;
    case 2:
      write("You taste "+attacker->query_name()+"'s soul as you pierce their flesh.\n");
      TP->add_alignment(-random(5));
      bonus+=4;
      break;
    case 3:
      tell_room(environment(environment()),
  "           "+HIM+"Soul"+BLK+"thief"+NORM+" shines with a dark aura as it is bathed\n"+
  "                     in the "+HIM+"life essence"+NORM+" of its foe.\n");
      bonus+=3;
      if(random(TP->query_attrib("wil")) < 17) break;
    case 4: case 5:
      if(TP->query_sp() > 5) {
        write("You feel weaker as "+HIM+"Soul"+BLK+"thief"+NORM+" feeds on you.\n");
        energy+=5;
        TP->add_spell_point(-random(10));
      }
      break;
    case 6:
      write(HIM+"Soul"+BLK+"thief"+NORM+" snatches a piece of your soul.\n");
      TP->add_exp(-random(50));
      break;
  }
  if(!random(3) && energy > 10)
    tell_room(environment(attacker),"\n"+HIM+"Soul"+BLK+"thief"+NORM+" crackles with energy.\n\n");
  if(!random(3) && environment()->query_hp()< (environment()->query_mhp() - 30) && energy>5) {
    tell_object(environment(),
HIM+"Soul"+BLK+"thief"+NORM+" gifts you with some of its hoarded soul energy.\n");
    environment()->add_hit_point(5);
    energy-=5;
    return 1;
  }
  return bonus;
}
