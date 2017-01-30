
/*
 * PURPLE WORM LVL: 5 AC: 4 WC: 13 HP: 60 Special attack: poison
 */

inherit "players/molasar/rowan/obj/monster";

reset(arg) {
   if(arg) return;
   set_name("worm");
   set_alias("purple worm");
   set_alt_name("wand_monst");
   set_short("A purple worm");
   set_long("An eight foor long worm which travels by burrowing through\n"+
            "the ground.\n");
   set_hp(60);
   set_level(5);
   set_wc(13);
   set_ac(4);
   set_aggressive(1);
   set_spec_attack_chance(20);
   ::reset();
}

special_attack(attacker) {
   object poison;
   if(present("poison", attacker)) {
     attack();
     return 1;
   }
   poison = clone_object("players/molasar/rowan/monsters/poison");
   poison->set_max_damage(30);
   poison->set_damage(10);
   poison->set_owner(attacker->query_real_name());
   move_object(poison, attacker);
   tell_object(attacker, "\nThe purple worm stabs you with its "+
       "poisonous stinger.\n\n");
   return 1;
}

