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

reset(arg) {
   if(arg) return;
   set_id("broken shank");
   set_alias("shank");
   set_short("A broken shank");
   set_long("This was once a favorite of violent prison\n"+
            "inmates. They have been used in many murders\n"+
            "that occur on the inside.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
