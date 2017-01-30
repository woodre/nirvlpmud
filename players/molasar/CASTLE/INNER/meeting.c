
#include "std.h"

int summoned, i;

reset(arg) {
   if(arg)
   return;
     set_light(1);
   extra_reset();
   summoned = 0;
}

object robe, flagg, staff;

extra_reset() {
   if(!present("flagg")) {
     flagg = clone_object("players/molasar/MONSTERS/advisor");
     robe = clone_object("players/molasar/ARMOR/robe2");
     transfer(robe, flagg);
     flagg->init_comflaggd("wear robe");
     move_object(flagg, this_object());
   }
}

short() { return "The meeting hall"; }

long() {
   write("You have entered the meeting hall of the castle.  Their is a large\n"+
          "table where open discussions are held.  A small room lies to the south"+
         "\nwhile the King's private audience chambers lie to the west.\n");
   write("   There are three obvious exits:  south, east, west\n");
}

init() { 
   add_action("south","south");
   add_action("east","east");
   add_action("west","west");
   add_action("summon","kill");
   add_action("summon","missile");
   add_action("summon","mi");
   add_action("summon","shock");
   add_action("summon","sh");
   add_action("summon","fireball");
   add_action("summon","fi");
}

summon(str) {
   object kguard, shield, armor, sword;
   if(str == "advisor" || str == "flagg") {
   if(summoned == 0) {
     i = 0;
     while(i<2) {
     i += 1;
     kguard = clone_object("players/molasar/MONSTERS/kguard");
     shield = clone_object("players/molasar/ARMOR/shield");
     armor = clone_object("players/molasar/ARMOR/leather_armor");
     sword = clone_object("players/molasar/WEAPONS/shortsword");
     transfer(shield, kguard);
     transfer(armor, kguard);
     transfer(sword, kguard);
     kguard->init_comflaggd("wield shortsword");
     kguard->init_comflaggd("wear shield");
     kguard->init_comflaggd("wear leather armor");
     move_object(kguard, this_object());
     kguard->attack_object(this_player());
     }
     summoned = 1;
     write("Two guards appear out of the room to the south.\n");
   }
   }
}

south() {
   this_player()->move_player("south#players/molasar/CASTLE/INNER/g_room");
   return 1;
}

east() {
   this_player()->move_player("east#players/molasar/CASTLE/INNER/lobby");
   return 1;
}

west() {
   if(present("advisor")) {
     write("The King's advisor says:  You have no business with the King.\n");
     return 1;
   }
   if(present("guard")) {
     write("The guard will not let you pass.\n");
     return 1;
   }
   this_player()->move_player("west#players/molasar/CASTLE/INNER/audience");
   return 1;
}

