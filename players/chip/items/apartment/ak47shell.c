/*
 *    File: /players/chip/items/apartment/ak47shell.c
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
   set_id("ak47 shell");
   set_alias("shell");
   set_short("An AK47 shell");
   set_long("The AK47 high powered assault rifle used\n"+
            "these rounds to shred their target with-\n"+
            "out remorse.\n");
   set_value(850+random(550));
   set_weight(1);
   set_dest_flag(1);
}
