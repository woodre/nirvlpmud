/*                                                                    *
 *    File:             /players/angel/area/nox/obj/boots.c           *
 *    Function:         silent_move_object                            *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           07/01/08                                      *
 *    Notes:            Used on NPC's in Nox Homeworld                *
 *                      It prevents move_obj working on               *
 *                      the NPC wearing it                            *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "/obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_id("silent_move_object");/*This item is designed to prevent the*/
   set_alias("boots");          /*room move_obj from showing the mob*/
   set_short("Boots");          /* moving out of the room*/
   set_long("This is pair of Nox boots.\n");
   set_ac(0);
   set_type("boots");
   set_weight(0);
   set_value(0);
}

short() { return 0; }/*this makes the item invis*/

get() { return 1; }/*this will keep the boots out of players hands*/
drop() {
  destruct(this_object());
    write("The item disapears before yor eyes...\n"); return 1; }