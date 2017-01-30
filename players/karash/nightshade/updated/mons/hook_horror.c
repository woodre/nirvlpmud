inherit "obj/monster";
#include <ansi.h>

#define TO this_object() 
#define ENV environment

/******************************************************************************
 * Program: hook_horror.c
 * Path: /players/nightshade/mons/
 * Type: Mob
 * Updated: September 2014 by Karash
 *
 * Purpose: An update to the Nightshade mob named hook_horror.  The stats were 
 *          increased and additional spells added.
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg) 
{
  object arm;
  ::reset(arg);
  if(arg) return;
  set_name("horror");
  set_short("Hook Horror");
  set_long("This huge beast is about 9 feet tall with huge hooks at the end of each\n\
arm in place of hands. His chest is as tough as any platemail and the\n\
beak he has for a mouth is as sharp as any blade. You best think again\n\
about attacking him.\n");

  set_level(22);
  set_hp(800+random(200));
  set_wc(40);
  set_ac(25);
  set_al(-100);
  set_aggressive(1);
  
  set_heal(5,1);
  
  arm=clone_object("players/nightshade/armor/hook_plate");
  move_object(arm, this_object());
  
  add_money(random(4000)+2000);
  
  
  add_spell("left_hook",
  "The #MN# attacks in a frenzy with both appendages $HR$GASHING$N$ you\n\
with the left hook.\n",
  "The #MN# attacks #TN# in a frenzy with both appendages\n\
$HR$GASHING$N$ #TO# with the left hook.\n",
  40,"25-50","physical",0);

  add_spell("right_hook",
  "The #MN# attacks in a frenzy with both appendages $HR$RIPPING$N$\n\
$HC$through your armor$N$ with the right hook.\n",
  "The #MN# attacks #TN# in a frenzy with both appendages\n\
$HR$RIPPING$N$ $HC$through #MP# armor$N$ with the right hook.\n",
  40,"25-50","physical",0);

  add_spell("bite_attack",
  "The #MN# successfully $HC$GRABS$N$ you with $HM$both hooks$N$ and pulls\n\
you closer for a $HR$VICIOUS BITE$N$.\n",
  "The #MN# successfully $HC$GRABS$N$ #TN# with $HM$both hooks$N$ and pulls #TO#\n\
closer for a $HR$VICIOUS BITE$N$.\n",
  20,"75-150","physical",0);
  
  
}


move_player(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

move_object(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

run_away(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to run but is compelled to stay...\n");}

movement(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

  