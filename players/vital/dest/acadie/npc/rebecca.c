/******************************************************************************
 *  
 *  File:           rebecca.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:         Started 5/11/01.
 *  
 *  Notes:			
 *  
 *  Change History: 10/3/01
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/dest.h"

inherit "/players/vital/closed/std/monster.c";

string grace;

reset(arg) {
    object sash;
    if(arg) return;
    ::reset(arg);
    set_name("becky");
    set_alt_name("rebecca");
    set_short("Rebecca");
    set_race(get_race());
    set_long(
"This is the owner of the house. She is happy to welcome nearly every \n\
stranger and offers sanctuary to those who seek it. There is nothing \n\
about her that is threatening.\n");
    set_level(19+random(2));
    set_gender("female");
    set_al(999);
    set_chat_chance(10);
    set_a_chat_chance(12);
    load_chats( ({
        "Rebecca smiles sweetly.\n",
        "The "+grace+" woman gently sweeps the room.\n",
        "Becky says, \"It is good to have guests.\"\n"
    }) );
    load_a_chats( ({
        "Rebecca screams loudly!\n",
        "Becky yells, \"Why do you do this to me?\"\n"
    }) );
    set_chance(15+random(60));
    set_spell_mess1("The "+grace+" swings her broom wildly around her.\n");
    set_spell_mess2("Your ears ring from the blow of Rebecca's broom to your head.\n");
    set_spell_dam(10+random(20));
    add_money(3000+random(1500));
    if(!present("sash",TO)) {
        MO(CO(ACADIE+"obj/sash.c"),TO);
        command("wear sash");
    }
}

id(str) { return str == "Rebecca" || str == "Becky" || str == "woman" || str == name || str == alias || str == race || str == alt_name; }

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
