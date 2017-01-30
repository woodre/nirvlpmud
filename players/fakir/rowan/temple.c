

#include "/room/clean.c"
#define HL_COST 4000        /* Heals player */
#define ENTRY "/players/sandman/paladin/entry"

#define SPEAK(x) write("The Temple Priest says: "+x);

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object priest;
   if(!present("priest")) {
     priest = clone_object("/obj/monster");
     priest->set_name("priest");
    priest->set_al(500);
     priest->set_alias("temple priest");
     priest->set_level(15);
     priest->set_wc(14);
     priest->set_ac(4);
     priest->set_spell_chance(50);
     priest->set_spell_mess1("The priest extends both hands.\n");
     priest->set_spell_mess2("A wave of heat washes over you!\n");
     priest->set_spell_dam(30);
     move_object(priest, this_object());
   }
}

id(str) { return str == "sign"; }

short() { return "The Guild Temple of the Paladins  [s]"; }

long(str) {
   if(str == "sign") {
     sign();
     return 1;
   }
   write("The Guild Temple of the Paladins.\n");
   write("You may pray here to restore yourself to a material form.\n");
   write("There is also information about the Paladins available.\n");
   write("A sign is here listing spells known by the temple priest.\n");
   write("Commands:  info, join\n");
   write("     There is one obvious exit:  south\n");
}

sign() {
   write("\n");
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   write("The temple priest knows the following spells:   \n");
   write("\n");
   write("lay hands                          "+HL_COST+" gp\n");
   write("\n");
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

init() {
  add_action("read","read");
  add_action("south","south");
  add_action("lay","lay");
  add_action("pray","pray");
  add_action("info","info");
  add_action("join","join");
}

lay(str) {
   if(str != "hands")
     return;
   if(!present("priest")) {
     write("The priest is not here at the moment. Try again later.\n");
     return 1;
   }
   if(this_player()->query_money() < HL_COST) {
     write("You do not have enough money.\n");
     return 1;
   }
   this_player()->heal_self(500);
   this_player()->add_money(-HL_COST);
   return 1;
}

read(str) {
   if(str == "sign") {
     sign();
     return 1;
   }
   return;
}

join() {  ENTRY->join(); return 1; }

info(str) {  ENTRY->info(str); return 1; }

south() {
   this_player()->move_player("south#players/molasar/rowan/w_twn_sq");
   return 1;
}

pray() {
   if(!present("priest")) {
     write("The priest is not here.  Come back later.\n");
     return 1;
   }
   if(!this_player()->query_ghost()) {
     SPEAK("You are not dead!\n");
     return 1;
   }
   write("The priest waves his hands and speaks an incantation.\n");
   this_player()->remove_ghost(0);
   return 1;
}

