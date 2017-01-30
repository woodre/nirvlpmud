/*
 *    File: /players/chip/items/apartment/frenchfries.c
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
   set_id("french fry");
   set_alias("fry");
   set_short("A McD's French Fry");
   set_long("An old, molding french fry. It is growing\n"+
            "a very small patch of fuzz on it. It might\n"+
            "still be edible, though it is not recommended.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
