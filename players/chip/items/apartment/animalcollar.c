/*
 *    File: /players/chip/items/apartment/animalcollar.c
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
   set_id("animal collar");
   set_alias("collar");
   set_short("An animal's collar");
   set_long("This frayed collar smells of wet fur and\n"+
            "mange. There are no ID tags on it to know\n"+
            "where or who the animal came from.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
