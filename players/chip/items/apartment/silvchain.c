/*
 *    File: /players/chip/items/apartment/silvchain.c
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
   set_id("silver chain");
   set_alias("chain");
   set_short("A silver chain");
   set_long("More than likely, no one is going to take\n"+
            "the chain other than a regular store. It\n"+
            "does not appear to be very attractive.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
