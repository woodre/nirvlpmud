/*
 *    File: /players/chip/items/apartment/purpleheart.c
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
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_id("purple heart");
   set_alias("heart");
   set_short("A "+MAG+"Purple Heart"+NORM+"");
   set_long("The Purple Heart award is earned by those\n"+
            "great soldiers who were hurt badly in the\n"+
            "line of duty. It must be worth some money.\n");
   set_value(900+random(600));
   set_weight(1);
   set_dest_flag(1);
}
