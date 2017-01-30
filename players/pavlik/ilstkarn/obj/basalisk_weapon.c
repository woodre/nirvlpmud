#include "/players/pavlik/closed/colors.h"
inherit "obj/weapon.c";
#define IT capitalize(attacker->query_name())

/*
 * THIS WEAPON IS NOT USABLE BY PLAYERS!!!
 * This object is merely used by an NPC to add combat specials
 */

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("the Basalisk's Claws");
  set_alt_name("basalisk_weapon");
  set_short("the Weapon");
  set_long("the Weapon");
  set_type("sword");
  set_class(30);
  set_weight(0);
  set_value(0);
  set_save_flag(1);
  set_hit_func(this_object());
  message_hit = ({
  HIR+"raked"+NORM,         "",
  HIR+"slashed"+NORM,       "",
  HIR+"gashed"+NORM,        "",
  HIR+"sliced"+NORM,        "",
  HIR+"scratched"+NORM,     "",
  HIR+"wounded"+NORM,        "",
  HIR+"punctured"+NORM,     "",
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
long() { write("The Basalisk's Claws.\n"); return; }
drop(){ return 1; }

weapon_hit(attacker) {
  int i, x, dmg, total;
  string msg, which;
  object obj;

  /*
   * This is just the standard round-to-round emotes for the Basalisk
   */
  total = 0;
  for(i=0; i<3; i++) {

    dmg = random(5)+1;
    if(dmg == 5) msg = "raked";
    else if(dmg == 4) msg = "gashed";
    else if(dmg == 3) msg = "punctured";
    else if(dmg == 2) msg = "slashed";
    else if(dmg == 1) msg = "scratched";

    if(i == 0) {
      if(!random(2)) which = "with its left foreclaw";
      else which = "with its right hindclaw";
    }
    if(i == 1) {
      if(!random(2)) which = "with its right foreclaw";
      else which = "tail";
    }
    if(i == 2) {
      if(!random(2)) which = "with its left hindclaw";
      else which = "bite";
    }

    if(which == "bite") {
      tell_room(environment(attacker),
      "Basalisk "+HIR+"chomped"+NORM+" into "+capitalize(attacker->query_name())+"'s flesh with a mighty bite!\n");
    }
    else if(which == "tail") {
      tell_room(environment(attacker),
      "Basalisk "+HIR+"pummeled "+NORM+IT+" with a mighty swing of its tail!\n");
    }
    else {
      tell_room(environment(attacker),
      "Basalisk "+HIR+msg+NORM+" "+IT+" "+which+"!\n");
    }
    total += dmg;
  }

  /*
   * End of round-to-round emotes.
   * Begin some special functions.
   */

  i = random(12);

  if(i == 8) {
    tell_room(environment(attacker),
    "The Basalisk draws in a deep breath and then spits out a\n"+
    "blazing "+HIY+"bolt of lightning"+NORM+"!\n"+
    "The "+HIY+"lightning bolt"+NORM+" strikes "+IT+" in the chest!\n");
    attacker->hit_player(40+random(40));

    /* chance to hit anything else attacking */
    obj = all_inventory(environment(attacker));
    for(x=0; x<sizeof(obj); x++) {
      if(obj[x]->query_attack() == wielded_by && obj[x] != attacker) {
        if(random(3)) {
          tell_room(environment(attacker),
          "The bolt of lightning "+HIB+"forks"+NORM+" and strikes "+
          capitalize(obj[x]->query_name())+"!\n");
          obj[x]->hit_player(30+random(30));
        }
      }
    }
  }

  /*
   * really rip into our attacker.  kills NPCs outright or reduces
   * a PCs hit points by half.
   */
  if(i == 5) {
    tell_room(environment(attacker), "\n"+
    "The Basalisk "+HIR+"rips through "+IT+"'s frail body"+NORM+
    " with its deadly claws!!!\n\n");
    if(!attacker->is_player()) {
      attacker->hit_player(10000);
    }
    else {
      attacker->hit_player(attacker->query_hp()/2);
    }
  }

  /*
   * Chance to smash any statues present.  This outright kills a player.
   */
  if(i == 1) {
    obj = all_inventory(environment(attacker));
    for(x=0; x<sizeof(obj); x++) {
      if(obj[x]->id("stone_curse")) {
        obj[x]->do_smash(random(30));
      }
    }
  }

  /*
   * Steal 1/2 spell points from attacker
   */
  if(i == 11) {
    tell_room(environment(attacker), "\n"+
    "The Basalisk "+HIM+"lunges forward"+NORM+" and sinks its teeth into "+IT+"!\n");
    tell_object(attacker,
    "A "+HIY+"powerful surge of electricity"+NORM+" wracks your body!\n"+
    "You feel tired and drained.\n");
    attacker->add_spell_point(-(attacker->query_sp()/2));
  }

  return total;
}

