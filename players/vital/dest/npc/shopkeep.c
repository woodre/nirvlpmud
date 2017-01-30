/******************************************************************************
 *  
 *  File:           shopkeeper
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 7/29/01.
 *  
 *  Notes:			
 *  
 *  Change History: 8/20/01,
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "/players/vital/closed/std/monster.c";

string grace;

reset(arg) {
    ::reset(arg);
    set_name("shopkeeper");
    set_alt_name("Tom");
    set_short("Shopkeeper Tom");
    set_race("human");
    set_long("\
  This is the stout little shopkeeper who runs the store. He looks \n\
like he has been working hard to keep the store clean. His shirt is \n\
rumbled and the knees of his pants are dirty. His large floppy hat \n\
has slid off to the side of his head.\n");
    set_level(17);
    set_gender("male");
    set_race(get_race());
    set_al(775);
    set_wimpy(20,65,0,"Tom leaves screaming in fear.\n");
    set_ac_bonus(3);
    set_chat_chance(10);
    set_a_chat_chance(1);
    load_chat("The shopkeeper straightens the wares on the shelves.\n");
    load_chat("Tom chuckles and looks at the shelves.\n");
    load_chat("The shopkeeper is busy cleaning the store.\n");
    load_a_chat("The shopkeeper screams in pain.\n");
    load_a_chat("Tom screams, \"I will kill you, "+CTPN+".\n");
    equip_me();
    command("wear hat");
    command("wear shirt");
    command("wear pants");
    set_dead_ob(TO);
}

id(str) { return str == "tom" || str == "shopkeep" || str == "shopkeeper tom" || str == name || str == alt_name || str == race || str == alias; }

equip_me() {
    object shirt, pants, hat;
    shirt = CO("/obj/armor.c");
    shirt->set_name("shirt");
    shirt->set_short("A rumpled shirt");
    shirt->set_long("\
  This is the rumpled shirt that was pulled from the dead body of the \n\
shopkeeper on Acadie. It is slightly torn, but looks like it would \n\
still provide some protection.\n");
    shirt->set_value(600+random(200));
    shirt->set_weight(1);
    shirt->set_ac(1);
    shirt->set_type("misc");
    shirt->set_info("This shirt was mass-produced on Acadie.\n");
    MO(shirt,TO);
    pants = CO("/obj/armor.c");
    pants->set_name("pants");
    pants->set_alias("pair");
    pants->set_short("A pair of pants");
    pants->set_long("\
  This is a pair of pants stolen from the corpse of a shopkeeper on \n\
Acadie. They are a bit dirty, but otherwise in good shape.\n");
    pants->set_value(700+random(100));
    pants->set_weight(1);
    pants->set_ac(1);
    pants->set_type("boots");
    pants->set_info("These pants made of 100% bio-engineered wool.\n");
    MO(pants,TO);
    hat = CO("/obj/armor.c");
    hat->set_name("hat");
    hat->set_alias("cap");
    hat->set_short("A floppy hat");
    hat->set_long("\
  This is the hat that was pulled from the head of a shopkeeper who \n\
was murdered. It has a wide brim to keep off the rain, sun and wind.\n");
    hat->set_value(650+random(150));
    hat->set_weight(1);
    hat->set_ac(1);
    hat->set_type("helmet");
    hat->set_info("Injected molded sole, man-made and leather upper. Do not wash.\n");
    MO(hat,TO);
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
