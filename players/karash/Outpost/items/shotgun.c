
inherit "obj/weapon.c";
#include <ansi.h>

/******************************************************************************
 * Program: shotgun.c
 * Path: /players/karash/Outpost/items
 * Type: weapon
 * Created: July 2014 by Karash
 *
 * Purpose:  A standard assault shotgun
 *
 * History:
 *          
 ******************************************************************************/

 
 
 reset(arg) 
{
    ::reset(arg);
    if (arg) return;

    set_name("shotgun");
    set_alias("gun");
    set_short("A shotgun");
    set_long("A standard military assault shotgun with a pistol grip behind the\n\
  trigger and another under the barrel for ease of use during heavy\n\
  tactical combat.\n");

    set_class(10);
    set_weight(2);
    set_value(500);
    /* set_hit_func(this_object()); */
}
