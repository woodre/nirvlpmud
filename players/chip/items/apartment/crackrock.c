/*
 *    File: /players/chip/items/apartment/crackrock.c
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
   set_id("crack");
   set_alias("rock");
   set_short("A crack rock");
   set_long("This is one thing that definately ruins the\n"+
            "lives of millions every day. It is highly\n"+
            "addictive and costs a small fortune.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
