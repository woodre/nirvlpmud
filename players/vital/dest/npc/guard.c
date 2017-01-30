/******************************************************************************
 *  
 *  File:           dtroops.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 5/11/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "/players/vital/closed/std/monster.c";

string ggender, grace;

reset(arg) {
    int x;
    x = 19+random(4);
    if(arg) return;
    ::reset(arg);
    set_name("guard");
    set_alt_name("milieu guard");
    set_short("Milieu Guard");
    set_race(get_race());
    set_long(
"This is one of the guards of the Milieu consortium. They are the \n\
last word in justice and law in the worlds of the Milieu. Their \n\
uniform is white and silver with the Milieu emblem on the pocket. \n\
The standard issue Power Lance is always at the ready in its holster.\n");
    set_level(x);
    set_gender(random(2) ? "male" : "female");
    set_al(666);
    set_chat_chance(2);
    set_a_chat_chance(12);
    load_chats( ({
        "The guard silently surveys the room.\n",
        "The "+C(TO->query_race())+" guard looks at you and smiles.\n",
        "The guard twirls "+TO->query_possessive()+" Power Lance around and then quickly slides it \n\into its holster.\n"
    }) );
    load_a_chats( ({
        "The Milieu Guard punches you in the gut.\n",
        "The lights flash quickly.\n"
    }) );
    set_chance(45);
    set_spell_mess1("The "+C(TO->query_race())+" guard floods your mind with pain.\n");
    set_spell_mess2("Your brain reels from the coercive pressure.\n");
    set_spell_dam(15+random(x));
    set_dead_ob(TO);
}

id(str) { return str == "trooper" || str == "light guard" || str == "mguard" || str == name || str == alias || str == race || str == alt_name; }

monster_died(){
    object corpse, treasure;
    corpse = present("corpse", environment());
    say("In a dying act, the guard uses the Power Lance to dissentegrate "+TO->query_objective()+"self.\n");
    if(ENV()) destruct(corpse);
    treasure = CO(DEST+"weapon/lance.c");
    MO(treasure,ENV(TP));
    treasure = CO("/obj/money.c");
    treasure->set_money(1500+(level*95));
    MO(treasure,ENV(TP));
    return 1;
}

get_race() {
    switch(random(5)) {
        case 0: grace = "human"; break;
        case 1: grace = "simbari"; break;
        case 2: grace = "krondaku"; break;
        case 3: grace = "poltroyan"; break;
        case 4: grace = "gi"; break;
    }
    return grace;
}

