/* my lib.  it is necessary for this file to work, but not YOUR files */
#include "/players/vertebraker/define.h"
    /* cheap alias thing to inherit from /obj/monster */
inherit MONSTER
reset(arg)  {
    ::reset(arg);
    if(arg) return;
    /* the name shown when it sez '<blah> hits you hard' or whatnot */
    set_name("alacorn");
   /* secondary name you can use for attacking */
    set_alias("wing horn");
    /* 'nother name you can use for attacking */
    set_alt_name("beast");
    /* obligatory race thing.. put human for human, creature for creature... allows for another name you can attack with */
    set_race("creature");
   /* what the player sees in the room */
    set_short("A screaming alacorn");
   /* what the player sees when he looks at it */
    set_long(
    "Swooping down upon you like a giant hawk is something that\n"+
    "looks like a black-furred unicorn with huge, black-pinioned\n"+
    "wings.  Its single horn, as long as a human's forearm and sharp\n"+
    "as a needle, is blood-red.  This beast radiates an aura of sheer\n"+
    "bloody-minded violence.\n");
    /* gender of the creature :) - male, female, etc.! */
    set_gender("male");
    /* level of the mob.  lookat /doc/build/rules/monster or whatever for what this does */
    set_level(19);
    /* armor class.  using same one from /doc/build/rules thing */
    set_ac(16);
    /* weapon class.  how hard the guy hits */
    set_wc(28);
    /* how many hit points the guy has */
    set_hp(475);
    /* this sets the alignment.  -50 = bad.  50 = good :) */
    set_al(-50);
    /* aggro rating.  if he attacks the player randomly, hit 1 here.  otherwise makeit 0 or leave this out. */
    set_aggressive(1);
    /* chat chance.. not sure how this works out.  read the docs.. */
    set_chat_chance(9);
    /* attack chat chance (fake spells) */
    set_a_chat_chance(8);
    /* you can put as many load_chats as you want. determined by chat_chance which one gets called */
    load_chat("The alacorn SCREECHES at you!\n");
    load_chat("The alacorn swoops in.\n");
    /* same thing as reg chat, only these are only called when the guy is attacking */
    load_a_chat("The alacorn gazes at you madly...\n");
    load_a_chat("The alacorn rakes at you with its sharp talons!\n");
    /* refers back to the monster_died() thing later.. you need this here for the monster_died thing, TO represents this_object btw :) */
    set_dead_ob(TO); 
    enable_commands();
    }
    
    monster_died() {
   /* okay, the monsters dead!  not only will they get the 'Alacorn died.' msg, but also... */
    tell_room(ENV(TO),
    "\n"+
    "      The alacorn screeches in unholy terror and drops dead.\n"+
    "\n");
    /* the alacorn screeched and stuff!  adds mood the work. */
    /* MOCO = move_object(clone_object =>  its cloning the horn obj into the room after the mob dies */
    MOCO("/players/vertebraker/enclave/obj/horn.c"),ENV(TO));
   /* return 0; prevents the bastard from comin back after death :) */
    return 0; } 
