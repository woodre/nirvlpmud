inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: mirror_new.c
 * Path: /players/nightshade/misc/
 * Type: Treasure
 * Created: September 2014 by Karash
 *
 * Purpose: A mage component called a platinum mirror used to cast mirror images.
 * 
 * History:
 *          
 ******************************************************************************/

object ob;
reset(arg) {
if (arg) return;

set_short("A Platinum Mirror");
SetMultipleIds(({"mirror", "platinum mirror", "platinum_mirror"}));
set_long("A tiny sheet of platinum.\nIt is shiny enough to be a mirror.\n");
set_weight(1);
set_value(5000);
set_save_flag(0);

}


