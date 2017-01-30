/*
 *    File: /players/chip/items/apartment/lithium.c
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
   set_id("lithium");
   set_alias("tablet");
   set_short("A small tablet");
   set_long("This is one powerful mood stabilizer.\n"+
            "It is highly psychologically addictive\n"+
            "and could cost a small fortune.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
