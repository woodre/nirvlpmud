/*
 *    File: /players/chip/items/apartment/cheeseburger.c
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
   set_id("cheeseburger");
   set_alias("burger");
   set_short("A half-eaten cheeseburger");
   set_long("Do not even bother attempting to eat this\n"+
            "moldy, disgusting-looking McDonald's burger.\n"+
            "Just the smell makes one want to vomit.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
