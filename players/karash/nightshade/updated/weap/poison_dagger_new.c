inherit "obj/weapon.c";
#include <ansi.h>

/******************************************************************************
 * Program: poison_dagger_new.c
 * Path: /players/nightshade/weap/
 * Type: Weapon
 * Created: October 2014 by Karash
 *
 * Purpose: A dagger with a weapon_hit for poison damage.
 * 
 * History:
 *          
 ******************************************************************************/




 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("dagger");
    set_alias("poison dagger");
    set_short("A poisonous dagger");
    set_long("A handy dagger with a light green ooze coated on the extremely sharp tip.\n");

    set_class(15);
    set_weight(1);
    set_value(500);
	
    /* Poison Damage */
    set_params("other|poison",5,0);
	
}

