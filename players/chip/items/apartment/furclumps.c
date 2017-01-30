/*
 *    File: /players/chip/items/apartment/furclumps.c
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
   set_id("fur clumps");
   set_alias("fur");
   set_alias("clumps");
   set_short("A handful of fur clumps");
   set_long("As the previous owner died, these clumps\n"+
            "of fur caked right off into your clenched\n"+
            "fist.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
