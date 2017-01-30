#include "/players/feldegast/closed/shortcut.h"
#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";

int energy;
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("soulthief");
  set_alias("longsword");
  set_short(HIM+"Soul"+BLK+"thief"+NORM+" the longsword");
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
  int W, dam, bonus;
  W=random(9);
  switch(W) {
    case 0:
      tell_room(environment(environment()),
        "Soulthief flashes brightly as twisting "+HIM+"tendrils of soul energy"+NORM+" are\n"+
        "             torn away from "+attacker->QN+"!\n");
      dam=random(5);
      attacker->heal_self(-dam);
      energy+=dam;
      bonus+=1;
      if(random(TP->query_attrib("wil")) < 17) break;
    case 1:
      tell_room(environment(environment()),
        "\nSoulthief keens loudly as "+environment()->QN+" swings it in a blurring arc.\n\n");
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
  "           Soulthief shines with an eary glow as it is bathed\n"+
  "                     in the "+HIM+"life essence"+NORM+" of its foe.\n");
      bonus+=3;
      if(random(TP->query_attrib("wil")) < 17) break;
    case 4: case 5:
      write("You feel weaker as Soulthief drains you for energy.\n");
      TP->add_spell_point(-random(6));
      break;
    case 6:
      write("Soulthief glows with an otherworldly aura as it snatches a piece\n"+
            "of your soul.\n");
      TP->add_exp(-random(50));
      break;
  }
  if(!random(3) && energy > 10)
    tell_room(environment(attacker),"\n"+HIM+"Soul"+NORM+"thief crackles with energy.\n\n");
  if(!random(3) && environment()->query_hp()< (environment()->query_mhp() - 30) && energy>5) {
    tell_object(environment(),
"Soulthief gifts you with some of its hoarded soul energy.\n");
    environment()->add_hit_point(5);
    energy-=5;
    return 1;
  }
  return 0;
}
