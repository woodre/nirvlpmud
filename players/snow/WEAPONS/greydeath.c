/*
A powerful weapon wielded by /pl/s/MONSTERS/sir_garl.c
It is not storable.
*/

#include "/players/forbin/ansi.h"

#define TP this_player()
#define MEAT TP->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TPN capitalize(TP->query_name())

inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("greydeath");
    set_alias("Greydeath");
    set_short("Grey"+CYN+"death"+NORM);
   set_type("sword");
    set_type("sword");
/* set type added by boltar */
    set_long(
"As you look deep into the longsword called 'Greydeath', you see a swirling\n"+
"vortex trapped inside the mystic metal. You can feel an extreme extraplanar\n"+
"weight in the blade and it also seems a little metaphysically unstable.\n");
    set_class(20);
    set_weight(10);
    set_value(10000);
    set_hit_func(this_object());
}
weapon_hit(ob) {
int W;
    W = random(18);
  if(W > 9)  {
    if(environment()->query_level() > random(24)) {
  say(HBCYN+HIC+TPN+"'s longsword rips into "+MEATN+" with explosive force!\n"+NORM);
  write(HBCYN+HIC+"Greydeath's vortex rips "+MEATN+"'s flesh apart!\n"+NORM);
  ob->heal_self(-random(5)-4);
  return 4;
    }
    if(environment()->query_level() < random(21)) {
  write(BWHT+CYN+"Parts of your flesh are sucked into Greydeath's vortex!\n"+NORM);
  environment()->hit_player(random(10));
  return -1;
    }
   }
  if(W < 2) {
    write(HIC+"Greydeath's vortex shudders and becomes dangerously unstable!\n"+
          "With a massive mental effort you restore the magic wards.\n"+NORM);
   environment()->add_spell_point(-random(10));
   return -2;
  }
       return;
}

quest_ob() { return 1; }
