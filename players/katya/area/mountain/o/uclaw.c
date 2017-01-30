/*
 *     uclaw.c             
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */


#include <ansi.h>
 inherit "obj/weapon.c";
 

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("Uruloki's Claw");
    set_alias("claw");
    set_short("Uruloki's Claw");
    set_long("Uruloki's claw is massive with huge nails \n");
    set_class(19);
    set_weight(2);
   set_type("club");
    set_value(2000);
    set_hit_func(this_object());

}
weapon_hit(attacker){
if(!random(4)) 
{ 
  write("Uruloki's claw "+RED+"SLASHES"+NORM+" through "+attacker->query_name()+"'s flesh!\n");
  say("Urulok's claw "+RED+"SLASHES"+NORM+" through "+attacker->query_name()+"'s flesh!\n");

  attacker->hit_player(30,"physical");
}
}
