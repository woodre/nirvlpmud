/*
 *    File: /players/chip/items/apartment/cigarette.c
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
   set_id("cigarette");
   set_alias("cig");
   set_short("A cigarette");
   set_long("Camel Menthol Wides are the best tasting\n"+
            "cigarette available on the market. Who\n"+
            "ever had this, has good taste in smokes.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
