/*
File: orcmage.c
Author: Feldegast
Date: 3/17/02
Description:
  An orcish mage from the orc encampment in Caladon.
*/

#include "defs.h"

inherit MONSTER;

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;
  set_name("kagatu");
  set_alt_name("shaman");
  set_short(GRN+"Kagatu"+NORM+" the Orcish Shaman");
  set_long(
    "Orcs are hideous, humanoid creatures with thick, hairy hides, squat\n"+
    "bodies and teeth protruding from their mouths.  They are intelligent,\n"+
    "but only barely so, having a strong tribal system, and some basic\n"+
    "tool-working ability.  Kagatu is extremely old by orcish standards,\n"+
    "bearing countless scars from both enemies, and his own hands.  He has\n"+
    "smeared his face with paint to make himself appear demonic, a kindred\n"+
    "spirit to the voracious creatures from beyond this world.\n"
  );
  set_gender("male");
  set_race("orc");
  set_level(23);
  set_wc(40);
  set_ac(21);
  set_hp(800);
  set_al(-800);
  set_chat_chance(3);
  load_chat("Kagatu bellows orcish obscenities at you.\n");
  load_chat("Kagatu dances about chaotically.\n");
  load_chat("Kagatu shakes his fetishes at you.\n");
  load_spell(50, 30, 0,
    HIM+"\n\tKagatu blasts you with crackling energy!\n\n"+NORM,
    BOLD+"\n\tKagatu blasts #ATT# with crackling energy!\n\n"+NORM
  );
  set_ac_bonus(4); /* Bonuses for blindness spell and armor. */
  set_wc_bonus(5);
  move_object(clone_object(ARM_PATH+"talismanf.c"), this_object());
  init_command("wear talisman");
  add_money(7000+random(2000));
}

object find_lowest()
{
  object lowest;
  object ob;
  int low;
  low=5000;
  ob=first_inventory(environment());
  while(ob)
  {
    if(living(ob) && (object)ob->query_attack() == this_object()  && (int)ob->query_hp() < low)
    {
      low=(int)ob->query_hp();
      lowest=ob;
    }
    ob=next_inventory(ob);
  }
  return lowest;
}

      
void heart_beat()
{
  object ob;
  ::heart_beat();
  if(attacker_ob && !random(20) && !present("blind_token", attacker_ob) && !attacker_ob->query_ghost())
  {
    tell_room(environment(), HBWHT+BLK+"Kagatu throws a sparkling white powder which ignites in a flash before your eyes!\n"+NORM);
    attacker_ob->hit_player(50);
    ob = clone_object("/players/feldegast/obj/blind_token.c");
    ob->start(attacker_ob);
    move_object(ob, attacker_ob);
  } 

  if(attacker_ob && !random(10))
  {
    ob = find_lowest();
    if(ob && ob!=this_object() && ob != attacker_ob)
    {
      tell_room(environment(), BOLD+"\nThe cunning orcish shaman attacks his weakest opponent, "+(string)ob->query_name()+"!\n\n");
      alt_attacker_ob = attacker_ob;
      attacker_ob = ob;
    }
  }

}

