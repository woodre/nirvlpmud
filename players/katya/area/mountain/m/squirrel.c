/*
 *     squirrel.c             
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

     set_name("A squirrel");
     set_alias("squirrel");
     set_short("A squirrel");
     set_race("squirrel");
     set_long("\
   A cute fluffy brown squirrel with a long shaggy tail, \n\
short pointy ears, and adorable little paws\n");
     set_gender("female");
     set_level(9);
     set_ac(6 + random(5));
     set_wc(10 + random(5));
     set_hp(500 + random(100));
     set_al(200);
     set_wander(2, 0, ({}));
     enable_commands();
   }
}
