#include "/players/llew/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;

   set_name(BOLD+"Fear"+NORM);
   set_level(20);
   set_alt_name("fear");
   set_long("The Incarnate of Fear, is a beatiful woman, with smooth, pale skin, and deep,\n"+
            "red lips. She is covered only with a light shroud that leaves nothing to the\n"+
            "imagination. The mist swirls around her, but does little to cover her excellent\n"+
            "figure. She holds herself proudly, like one of royalty, and you know that she is\n"+
            "used to being obeyed.\n");
   set_gender("female");
   set_wc(35);
   set_ac(14);
   set_hp(400+random(50));
   set_al(-1000);
   set_aggressive(1);
   set_chat_chance(8);
   load_chat(BOLD+"Fear"+NORM+" says, \"I'm everything you've ever been afraid of embodied.\"\n");
   load_chat(BOLD+"Fear"+NORM+" says, \"To know my embrace, is to know Terror.\"\n");
   load_chat(BOLD+"Fear"+NORM+" licks her succulent "+HIR+"red"+NORM+" lips.\n");
   set_a_chat_chance(20); 
   load_a_chat(BOLD+"Fear"+NORM+" fills your mind with nightmares.\n");   
}

init() {
   ::init();
   add_action("embrace","embrace");
   add_action("block","true_name");
}

heart_beat() {
   ::heart_beat();
   if(attacker_ob && !random(10)) {
      heal_self(random(15));
      tell_room(environment(), name+" feeds off your Terror, she looks stronger.\n");
   }
   if(present("terror"))
      present("terror")->attack_object(attacker_ob);
}

embrace(str) {
   if(!str || str != "fear") {
      notify_fail("Embrace whom?\n");
      return 0;
   }
   if(str == "fear") {   
   write("As you embrace "+BOLD+"Fear"+NORM+", your mind is filled with many horrible images of many\n"+
         "terrible things. The embodiment of "+MAG+"TERROR"+NORM+" appears out of the mist, and rears up to tear you\n"+
         "limb from limb.\n");
   move_object(clone_object("/players/ulath/terror.c"), environment());
   return 1;
   }
}

block() {
   write("You can not grasp the True Name of "+BOLD+"Fear"+NORM+"\n");
   return 1;
}
