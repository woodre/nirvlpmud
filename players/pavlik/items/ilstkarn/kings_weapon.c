#include "/players/pavlik/closed/colors.h"
inherit "obj/weapon.c";
#define IT capitalize(attacker->query_name())
#define ME capitalize(this_player()->query_name())

/*
 * THIS WEAPON IS NOT USABLE BY PLAYERS!!!
 * This object is merely used by an NPC to add combat specials
 */

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("the Kings Weapon");
  set_alt_name("kings_weapon");
  set_short("the Weapon");
  set_long("the Weapon");
  set_type("sword");
  set_class(30);
  set_weight(0);
  set_value(0);
  set_save_flag(1);
  set_hit_func(this_object());
  message_hit = ({
  HIR+"destroys"+NORM,      " with a massive blow",
  MAG+"reaches into"+NORM,  " and "+MAG+"steals"+NORM+" part of his soul",
  RED+"gashes"+NORM,        " with a "+RED+"spell of wounding"+NORM,
  BLU+"scratches deep wounds"+NORM+" into", "",
  GRN+"chokes"+NORM,        " in a "+GRN+"deathly grasp"+NORM,
  HIW+"shrieks"+NORM+" at", " in an "+HIW+"inhuman"+NORM+" voice",
  "grazes",                 " with a sharp claws",
  });
}

init() {
 ::init();
 if(living(environment()) && environment()->is_player()) {
   destruct(this_object());
   return 1;
 }
}

short() { return; }
long() { write("The kings weapon.\n"); return; }
drop(){ return 1; }

weapon_hit(attacker) {
  int i, dam;

  i = random(9);

  if(!attacker->is_player() && !random(5)) {
    tell_room(environment(attacker), BLU+
    "King Secezeran reaches into "+IT+"'s chest and pulls out its heart!\n"+NORM);
    dam = attacker->query_hp() + 100;
    return dam;
  }

  if(i == 0) {
    tell_room(environment(attacker),
    ME+" casts a spell of "+GRN+"decay"+NORM+" on "+IT+".\n"+
    IT+" looks tired and weak.\n");
    tell_object(attacker,
    "You feel very tired.\n");
    attacker->add_spell_point(-random(30));
  }
  else if(i == 2) {
    tell_room(environment(attacker),
    "The King's Ghost reaches into "+IT+"'s soul!\n");
    tell_object(attacker,
    "A "+MAG+"sliver of Pain"+NORM+" stabs deep into your chest!\n");
    return 10;
  }
  else if(i == 4) {
    tell_room(environment(attacker),
    "The King's Ghost summons a "+HIY+"massive"+NORM+" bolt of energy!\n"+
    ME+HIY+" BLASTS "+NORM+IT+" into the far wall!\n");
    tell_object(attacker,
    "You are hurled clear across the room!\n");
    dam = 10+random(10);
    return dam;
  }
  else if(i == 6) {
    tell_room(environment(attacker),
    ME+" rips desperately at "+IT+"'s throat!\n");
    return 7;
  }
  else if(i == 8) {
    tell_room(environment(attacker),
    "The King's Ghost "+HIM+"feeds"+NORM+" off of "+IT+".\n");
    this_player()->heal_self(10+random(30));
    return 5;
  }
  dam = random(10);
  return dam;
}

