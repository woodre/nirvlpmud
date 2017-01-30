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
string grace;


reset(arg) {
    int x;
    x = 17+random(4);
    if(arg) return;
    ::reset(arg);
    set_name("trooper");
    set_alt_name("dark trooper");
    set_short(0);
    set_race(get_race());
    set_long(
"This is one of the elite Dark Troopers that provides law enforcement \n\
and peace-keeping presence through out the universe. They are highly \n\
trained at killing. Their training has made killing almost mechanical.\n");
    set_level(x);
    set_gender(random(2) ? "male" : "female");
    set_al(-666);
    set_chat_chance(2);
    set_a_chat_chance(12);
    load_chat("A darkness decends upon the room.\n");
    load_chat("Something dark makes you feel queasy.\n");
    load_chat("The silence is deafening.\n");
    load_a_chat("The Dark Trooper attacks you without passion or care.\n");
    load_a_chat("Darkness Floods the room.\n");
    set_chance(45);
    set_spell_mess1("The Dark Trooper sheds darkness on you.\n");
    set_spell_mess2("Your brain reels from the dark pressure.\n");
    set_spell_dam(10+random(x));
    set_dead_ob(TO);
}

id(str) { return str == "trooper" || str == "dark trooper" || str == "troopers" || str == name || str == alias || str == race || str == alt_name; }

monster_died(){
    object corpse, blaster;
    corpse = present("corpse", environment());
    say("The Dark Troop "+RED+"medics"+NORM+" run in and remove the corpse of their fallen comrade.\n");
    if(ENV()) destruct(corpse);
    blaster = CO(DEST+"weapon/darkblast.c");
    MO(blaster,ENV(TP));
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
