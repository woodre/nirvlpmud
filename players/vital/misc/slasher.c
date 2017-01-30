/******************************************************************************
 *  
 *  File:           slasher.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 11/29/01.
 *  
 *  Notes:          
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/


#include "/players/vital/closed/headers/vital.h" /*universal header*/
#define SLASH HIW+"Tooth"+BLU+"Slasher"+NORM

inherit "obj/weapon.c";

int speed;
string *ids;

reset(arg) {
    speed = 0;
    ::reset(arg);
    if (arg) return;
    set_name("slasher");
    set_alias("tooth slasher");
    set_short(SWORD);
    set_long("\
  The combined strength of a dragon's hip bone and the silvery, \n\
sharp teeth of a basillisk make for a formidable weapon. The blue \n\
aura that swirls around the weapon comes from the manufacturing \n\
process, where the pieces are soaked in the blood of a birsh that \n\
decreases the relative drag by magically reducing the surface area \n\
of the mace.\n"
    );
    set_type("mace");
    set_id( ({
        name_of_weapon, alias_name, type, "weapon", "club", "Slasher", "bone", "hip bone", "aura", "teeth"
    }) );
    set_class(10+random(6));
    set_weight(3);
    set_value(500+random(800));
    set_hit_func(this_object());
    set_info("Faster warriors can make this weapon a formidable killing machine.\n");
}

weapon_hit(attacker) {
    if(!speed) speed = 1;
    return 0;
}

id(string str) {
    if(!ids) ids = ({ });
    if(member_array(str, ids)) return (member_array(str, ids) >= 0);
}

set_id(string *new_ids) {
    ids = new_ids;
}

long(str) {
    if(!str) return 0;
    if(str == "hilt" || str == "handle" || str == "material" || str == "bone" || "dragon bone") {
        write("The material in the hilt glows light blue and offsets the intense heat of the blade.\n"); 
        return;
    }
    if(str == "teeth") {
        write("These teeth were pulled from the dead carcass of a basilisk by blind men.\n");
        return;
    }
    if(str == "aura") {
        write("The faintest of blue auras swirls around the mace. It is most noticeable when you are not looking directly at the "+SLASHER);
        return;
    }
    if(member_array(str,ids)) write(long_desc);
    return;
}
