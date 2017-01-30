/*
 *    File: /players/chip/items/apartment/crackpipe.c
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

reset(arg) {
   if(arg) return;
   set_id("stem");
   set_alias("crack stem");
   set_short("A small clear crack stem");
   set_long("The once clear glass tube now has a sort of\n"+
            "yellowish-white residue on the inside and what\n"+
            "looks to be a piece of a Chore-Boy.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
