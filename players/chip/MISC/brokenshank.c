/*
 *    File: /players/chip/items/apartment/brokenshank.c
 *    Function: Sellable Item
 *    Author(s): Chip@Nirvana
 *    Copyright: Copyright (c) 2008 Chip
 *               All Rights Reserved
 *    Source: 5/31/08
 *    Notes: 
 *
 *
 *    Change History:
 */
 
inherit "obj/treasure";

reset(agr) {
   if(agr) return;
   set_id("broken shank");
   set_alias("shank");
   set_short("A badly broken shank");
   set_long("A simple piece of sheet metal, seemingly\n"+
            "sharpened against something rough. Don't\n"+
            "bother trying to repair it\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
