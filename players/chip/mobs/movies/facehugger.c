/*
 *    File: /players/chip/mobs/movies/facehugger.c
 *    Function: NPC
 *    Author(s): Chip@Nirvana
 *    Copyright: Copyright (c) 2009 Chip
 *               All Rights Reserved
 *    Source: 5/31/09
 *    Notes:
 *
 *
 *    Change History:
 */
#include <ansi.h>
#define CO clone_object


inherit "obj/monster";

static object Remembered;

object gold;
reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name(""+YEL+"a facehugger"+NORM+"");
      set_alias("facehugger");
      set_short(""+YEL+"a facehugger"+NORM+"");
      set_race("alien");
      set_long(
         "With 8 legs used to latch onto your face, this speedy little creature\n"+
         "looks like a spider and a scorpion got together...sort of. Its grip is\n"+
         "very powerful and it has a small tubelike mouth on its underside, which\n"+
         "it sticks in your mouth to plant an alien embryo in your body. It is one\n"+
         "strange looking creature, to say the least.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (5000) + 10000);
      move_object(gold, this_object());
      set_level(17);
      set_hp(1500);
      set_ac(90);
      set_wc(75);
      set_al(-1000);
      set_chance(40);
      set_spell_dam(random (70) + 35);
      set_spell_mess1("The "+YEL+"facehugger"+NORM+" tightens its grip on its enemy.\n");
      set_spell_mess2("You feel the "+YEL+"facehugger"+NORM+" squeezing ever harder on your head.\n");
      set_aggressive(1);
      set_chat_chance(10);
      load_chat("You hear a faint chittering noise.\n");
      load_chat("The "+YEL+"facehugger"+NORM+" twitches a bit.\n");
      if(!root()) call_out("aggro", 2);
      }
}

aggro()
{
  object *inv;
  int    x;
  int found;
  inv = all_inventory(environment());
  x = sizeof(inv);
  while(x-- && !found)
  {
    if(inv[x]->is_player())
    {
      attack_object(inv[x]);
      found = 1;
    }
  }
  call_out("aggro", 2);
}

heart_beat()
{
  ::heart_beat();
  if(attacker_ob && present(attacker_ob, environment()))
  {
    if(random(100) > 70) face_attack();
  }
}

face_attack()
{
  int z, dmg;
  z = attacker_ob->query_hp();
  dmg = (100 + random(200));
  tell_object(attacker_ob,
    RED+"\n\tYou wince as you feel the alien embryo entering your body through your mouth.\n"+NORM);
  if(z > dmg)
  {
    attacker_ob->hit_player(dmg, "other|evil");
  }
  else
  {
    attacker_ob->hit_player(10000); /* we want them dead */
    call_out("new_life", 2);
  }
}

new_life()
{
  object mob;
  mob = CO("/players/chip/mobs/movies/alien.c");
  move_object(mob, environment());
  mob->respawn();
  destruct(this_object());
  return 1;
}
