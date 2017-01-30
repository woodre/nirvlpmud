/*
File: orchero.c
Author: Feldegast
Date: 3/17/02
Description:
  An orcish hero from the orc encampment in Caladon.  He has a special
one-time attack.  He also holds a piece of rune armor.
*/

#include "defs.h"

inherit MONSTER;

int thrown;

int id(string str) { return ::id(str) || str=="hero" || str=="orcish hero"; }

void reset(int arg) 
{
  ::reset(arg);
  thrown = 0;
  if(arg) return;
  if(!random(2))
  {
    move_object(clone_object(ARM_PATH+"shield.c"), this_object());
    init_command("wear shield");
  }

  move_object(clone_object(ARM_PATH+"runeamulet.c"), this_object());
  init_command("wear amulet");

  move_object(clone_object(ARM_PATH+"chainmail.c"), this_object());
  init_command("wear mail");

  move_object(clone_object(WEP_PATH+"battleaxe.c"), this_object());
  init_command("wield axe");

  add_money(2000+random(1000));

  set_name("urg!");
  set_alt_name("urg");
  set_short("Urg! the Orcish Hero");
  set_long(
    "Orcs are hideous, humanoid creatures with thick, hairy hides, squat\n"+
    "bodies and teeth protruding from their mouths.  They are intelligent,\n"+
    "but only barely so, having a strong tribal system, and some basic\n"+
    "tool-working ability.\n"+
    "Urg! is a living legend among orcs, having led over a dozen raids\n"+
    "into human lands that've brought great honor and prosperity to his\n"+
    "tribe, the Goremonger orcs.  Urg! is a hulking brute, even by orcish\n"+
    "standards, and his successful raids have left him well-armed.\n"
  );
  set_gender("male");
  set_race("orc");
  set_level(20);
  set_wc(30);
  set_wc_bonus(2); /* Spell */
  set_ac(13);
  set_ac_bonus(4); /* Armor */
  set_hp(500);
  set_al(-500);
  set_chat_chance(3);
  load_chat("Urg! flexes his mighty muscles.\n");
  load_chat("Urg! bellows loudly as he beats his chest.\n");
  load_chat("Urg! snears at you contemptuously.\n");
  load_spell(30, 10, 0,
    BOLD+"\n\tUrg! swings his mighty battle-axe in an overhand\n"+
    "\tsweep, hitting you with a powerful blow!\n\n"+NORM,
    BOLD+"\n\tUrg! swings his mighty battle-axe in an overhand\n"+
    "\tsweep, hitting #ATT# with a powerful blow!\n\n"+NORM
  );

}

void heart_beat()
{
  ::heart_beat();
  if(attacker_ob && !random(4) && !thrown && !attacker_ob->query_ghost())
  {
    tell_object(attacker_ob, HIR+"\nUrg! throws his spear at you, goring you badly!\n\n"+NORM);
    tell_room(environment(), HIR+"\nUrg! throws his spear at "+(string)attacker_ob->query_name()+", goring "+(string)attacker_ob->query_objective()+" badly!\n"+NORM, ({ attacker_ob }));
    attacker_ob->hit_player(100);
    thrown = 1;
  }
}
