#include "/players/feldegast/closed/shortcut.h"
#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";

int energy;
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("soulthief");
  set_alias("longsword");
  set_short("Soulthief the longsword");
  set_long(
"Soulthief is a longsword made from some alloy you are unfamiliar\n"+
"with.  Its grey blade is approximately a yard in length.  Its hilt\n"+
"is decorated with silver gilt and the name 'Soulthief' is etched on\n"+
"the crosspiece.  The pommelstone is a beautiful black pearl.\n"
  );
  set_type("sword");
  set_class(16);
  set_weight(2);
  set_value(1500);
  set_hit_func(this_object());
}
weapon_hit(attacker) {
  int W, dam;
  W=random(9);
  if(!W) {
    tell_room(environment(environment()),
"Soulthief flashes brightly as twisting "+HIM+"tendrils"+NORM+" of soul energy are\n"+
"           torn away from "+attacker->QN+"!\n");
    dam=random(5);
    attacker->heal_self(-dam);
    energy+=dam;
    return 1;
  }
  if(W<2) {
    tell_room(environment(environment()),
"\nSoulthief keens loudly as "+environment()->QN+" swings it in a blurring arc.\n\n");
    dam=random(2);
    attacker->heal_self(-dam);
    energy+=dam;
    return 4;
  }
  if(W<4) {
    tell_room(environment(environment()),
"           Soulthief shines with an eary glow as it is bathed\n"+
"                     in the "+HIM+"life essence"+NORM+" of its foe.\n");
    return 3;
  }
  if(W<6 && environment()->query_hp()<200 && energy>5) {
    tell_object(environment(),
"Soulthief gifts you with some of its hoarded soul energy.\n");
    environment()->heal_self(5);
    energy-=5;
    return 1;
  }
  return 0;
}
