
#include "std.h"

reset(arg){
     if(!arg){
     set_light(1);
     extra_reset();
     }
}

object demo;
extra_reset(){
     demo = clone_object("obj/monster");
     demo->set_name("demogorgon");
     demo->set_level(20);
     demo->set_alias("demon");
     demo->set_short("Demogorgon, Demon of Misery");
     demo->set_long("Don't even think about trying to defeat him in combat\n"+
      "even-handedly.  You have been warned.\n");
     demo->set_wc(100);
     demo->set_ac(1001);
     demo->set_hp(2000);
     demo->set_chance(100);
     demo->set_spell_dam(5);
     demo->set_spell_mess1("Demogorgon lashes out with his tentacles.\n");
     demo->set_spell_mess2("Demogorgon makes one of your limbs with away!\n");
     demo->set_a_chat_chance(100);
     demo->load_a_chat("Demogorgon lets loose a demonic screech and you tremble.\n");
     demo->set_chat_chance(30);
     demo->load_chat("Demogorgon growls: Now you may deal with me, mortal!\n");
     demo->load_chat("Demogorgon scoffs: Don't even THINK about attacking me.\n");
     move_object(demo, this_object());
}

init(){
     add_action("east","east");
     add_action("west","west");
}

east(){
     call_other(this_player(), "move_player",
       "east#players/deathmonger/UNDERDARK/gate1");
     return 1;
}

west(){
     if(present("demogorgon")){
       write("Demogorgon's enormous mass fills the entire exit.\n");
       return 1;
     }
     call_other(this_player(), "move_player",
       "west#players/deathmonger/QUEST/portal");
     return 1;
}

short(){
     return "Demogorgon's Lair"; }

long(){
write("You enter a misty pseudo-reality that Demogorgon has created to\n");
write("support himself here in this plane.  He has situated his lair so as to block\n");
write("any attempts such as yours.\n");
write("Whatever you do, don't even think about attacking Demogorgon.\n");
write("There are two obvious exits: east and west.\n");
}
