/*
 *  Master Sword
 *  Cloud 2010
 *	players/cloud/Nintendo/Zelda/obj/sword.c
 *  Rare Drop
 *  Need 19+5 to wield
 *  Heavy Weight
 *
 *  
*/

#include "/obj/ansi.h"
 inherit "obj/weapon.c";

 reset(arg) 
 {
    ::reset(arg);
    if (arg) return;
    
    message_hit = 
    ({
        HIW+" DESTROYED "+NORM," blood gushes everywhere",
  		HIW+" SLASHED "+NORM," extremely hard",
        HIW+" SLICED "+NORM," viciously",
        HIW+" minced "+NORM,", with precision",
        HIW+" choped "+NORM," drawing a little blood",
        HIW+" cut "+NORM," lightly",
        HIW+" nicked "+NORM," very lightly"
    });


    set_name(""+HIB+"Master "+HIW+"Sword"+NORM+"");
    set_alias("sword");
    set_short(""+HIB+"Master "+HIW+"Sword"+NORM+"");
    set_long("A blue, winged hilt opens into a bright, white edge that makes\n" +
    		 "up this sword. It's blade is very sharp.\n");
    set_class(20);
    set_weight(3);
    set_value(3000);
    set_min_xlevel(5);
    set_min_xlevel_message("You are not experienced enough to wield the "+HIB+"Master "+HIW+"Sword"+NORM+".\n");
    set_hit_func(this_object());
}




	
    
	
