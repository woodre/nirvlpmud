#define prompt say("->> ")
#include "living.h"

object you;

short() { return "Anthrax the archwizard"; }

get() { return 0; }

long() {
     write("He stands proudly before you, his eyes considering your mortal" +
           " frame.\n");
}

reset(arg) {
     object ob;
     if(arg) return;
     name="anthrax";
     cap_name="Anthrax";
     level=10000;
     max_hp=8950;
     hit_point=8950;
     spell_points=8950;
     alignment=-100000;
     is_npc=1;
     experience=3000000;
     weapon_class=WEAPON_CLASS_OF_HANDS;
     armor_class=1000;
     msgout="leaves";
     msgin="enters";
     mmsgout="disappears in a puff of smoke";
     mmsgin="arrives in a puff of smoke";
     enable_commands();
     ob=clone_object("obj/soul");
     move_object(ob, this_object());
}

id(str) { return (str=="man" || str=="anthrax"); }

init() {
     add_action("out", "out");
}

out() {
     write("A strong magical force prevents you from leaving.\n");
     return 1;
}

quest_done() {
     say("\nAnthrax says: Allow me to introduce myself. I am Anthrax of\n"+
         "the Black League.\n");
     prompt;
     say("\nAnthrax says: Thanks to your stupidity I am now freed.\n");
     prompt;
     call_out("reward", 5);
}

reward() {
     say("\nAnthrax says: Ah yes...Did I promise you a reward?\n");
     prompt;
     say("\nAnthrax makes a small gesture.\n");
     prompt;
     call_out("summon_demon", 5);
}

summon_demon() {
   object ob,you,find;
   say("\nAnthrax says: Enjoy a swift death!\n");
   prompt;
   say("\nA demon appears out of a sulfurous cloud!\n");
   prompt;
   ob=clone_object("players/bastion/monster/demon6");
   move_object(ob, environment(this_object()));
   call_out("exit_msg", 5);
}

exit_msg() {
     object ob;
     say("\nAnthrax says: See you in hell!\n");
     prompt;
     say("\nAnthrax disappears in a puff of smoke.\n");
     prompt;
     ob=present("quest_ob", environment(this_object()));
     call_other(ob, "call_set_quest_string");
     move_object(this_object(), "room/void");
     call_out("self_destruct", 2);
}

self_destruct() {
     destruct(this_object());
}