/*
 *     bunny.c             
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(500) + 500);
    move_object(gold,this_object());

     set_name("A bunny");
     set_alias("bunny");
     set_short("A bunny");
     set_race("bunny");
     set_long("\
   A cute fuzzy brown bunny with a bushy tail, \n\
long floppy ears, and an adorable brown nose.\n");
     set_gender("female");
     set_level(10);
     set_ac(8 + random(5));
     set_wc(14 + random(5));
     set_hp(500 + random(100));
     set_al(200);
     set_wander(2, 0, ({}));
     enable_commands();
   }
}
