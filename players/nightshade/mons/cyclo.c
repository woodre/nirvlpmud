inherit "obj/monster";
#include <ansi.h>


/******************************************************************************
 * Program: cyclo.c
 * Path: /players/nightshade/mons/
 * Type: Mob
 * Updated: September 2014 by Karash
 *
 * Purpose: An upgrade to the original Nightshade mob named cyclo.  This upgrade
 *          increases mob stats and upgraded the spell.
 
 * History:
 *          
 ******************************************************************************/

object gold;

reset(arg)
{
::reset(arg);
if(arg) return;
set_name("cyclo");
set_short("Cyclopentanoperhydrophenanthrene");
set_long("The big boss himself. A steroid!!!\n");
set_level(22);
set_hp(750);
set_wc(38);
set_ac(20);
set_heal(15,1);

add_spell("membrane_fluidity",
  "$M$Cyclopentanoperhydrophenanthrene decreases your membrane fluidity.$N$\n",
  "$M$Cyclopentanoperhydrophenanthrene decreases the membrane fluidity of #TN#.$N$\n",
  40,"40-60","physical",0);

set_dead_ob(this_object());  
  
}


monster_died(){
  tell_room(environment(),
    "As you search the fountain, you find many "+HIY+"coins"+NORM+" deposited here.\n");
  gold=clone_object("obj/money");
  gold->set_money(5500+random(3000));
  move_object(gold, environment());

}

