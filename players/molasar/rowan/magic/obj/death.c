

/*
 * DEATH (1/24/94)
 * Cloned from deck.c Will follow player around and attack until
 * one or the other is killed or player quits.
 */

inherit "players/molasar/rowan/obj/monster";

reset(arg) {
   if(arg) return;
   set_name("death");
   set_short("A minor death");
   set_long("A minor diety from the lower planes of the abyss sent to "+
            "punish a mortal.\n");
   set_level(20);
   set_hp(500);
   set_wc(25);
   set_ac(10);
   set_heal(3,60);
   set_al(-1000);
   set_ep(0);
   set_aggressive(0);
   set_single_chance(35);  /* all chances must add up to 100 */
   set_single_dam(20);
   set_single_mess1("The minor death makes a swipe with his scythe.\n");
   set_single_mess2("You are hit by the scythe!\n");
   set_number_of_attacks(2);
   set_multiple_chance(35);
   set_multiple_dam(30);
   set_multiple_mess1("Death casts a spell.\n");
   set_multiple_mess2("Your blood runs cold as evil overwhelms you.\n");
   set_regular_chance(30);
   ::reset();
}

int target;

set_target(t) { target = t; }

heart_beat() {
   if(!find_player(target)) {
     destruct(this_object());
     return 1;
   }
   if(find_player(target)->query_ghost()) {
     destruct(this_object());
     return 1;
   }
   if(!present(find_player(target), environment(this_object()))) {
     move_object(this_object(), environment(find_player(target)));
     return 1;
   }
   ::heart_beat();
}

