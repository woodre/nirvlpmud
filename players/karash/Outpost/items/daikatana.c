
inherit "obj/weapon.c";
#include <ansi.h>

/******************************************************************************
 * Program: daikatana.c
 * Path: /players/karash/Outpost/items
 * Type: weapon
 * Created: July 2014 by Karash
 *
 * Purpose: John Romero's weapon - normalized
 *			(When the weapon is empowered, it will take on new qualities)
 *
 * History:
 *          
 ******************************************************************************/

 
 
 reset(arg) 
{
    ::reset(arg);
    if (arg) return;

    set_name("daikatana");
    SetMultipleIds( ({ "daikatana", "sword", "katana" }) );
    set_short(GRY+"Daikatana"+NORM);
    set_long("A long, curved, single-edged sword that is a little longer than a normal\n\
katana.  Initially, it appears there is nothing special about it, but\n\
after you grip it for a moment, you sense a very faint resonation coming\n\
from it.  There seems to be more to this sword than you know.\n");

    set_class(15);
    set_params("other|fire",5,0);
    set_weight(2);
    set_value(1200);
	set_save_flag(1);
	
    /* set_hit_func(this_object()); */
}


/** To keep sword permanently sharpened **/
query_wear() {
   int wear;
   wear = 0;
  return wear;
}