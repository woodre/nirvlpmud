/*
 *      File:                   /players/earwax/area/fields/mon/squid.c
 *      Function:               
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2004 Earwax/David Halek
 *                                      All Rights Reserved.
 *      Source:                 06/27/06
 *      Notes:                  This mob guards the exit to the room that contains
 *                              the mini-quest mob that can grant the velcro gloves.
 *                              It's an extremely high-damage mob that's immune to
 *                              water, 50% resistant to poison damage, can deal up to
 *                              about 300 damage in a round consistantly, averaging 
 *                              around 49 per round.  It has standard ac/wc/hp and
 *                              regens avg 20 hp per hb.  It also blocks the exits,
 *                              is in a no-teleport room, can't be calmed, and will
 *                              move corpses of those it kills to the room it guards.
 *                              In short, it's a very dangerous mob that doesn't drop
 *                              anything whatsoever, it's just the only mob that
 *                              technically has to always be killed in order to complete
 *                              the velcro-gloves mini-quest.
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

#define RPATH "/players/earwax/area/fields/room/"
#define MYHOME "/players/earwax/area/fields/room/moat1"
#define HIDEOUT  "/players/earwax/area/fields/room/moat_cave"
#define INKCLOUD "/players/earwax/area/fields/obj/inkcloud.c"

inherit "/obj/monster.c";

status id(string arg)
{
  return (arg == "monster" || arg == "squid" || arg == "moat-monster"
       || arg == "moat monster");
}

string query_name() { return YEL+"Moat-Monster"+NORM; }

void stop_fight()
{
  if (!this_player() && (int)this_player()->query_level() < 20)
    write("The "+name+" can't be calmed!\n");
  else
    ::stop_fight();
}

void reset(status arg)
{
  ::reset(arg);
  set_name(YEL+"Moat-Monster"+NORM);
  set_race("squid");
  set_level(30);
  set_al(0);
  /* 2000 to 3000 hps, average of 2500 */
/* randomize it when my calibrating is finished 
  set_hp(2000+random(201)+random(201)+random(201)+random(201)+random(201));
*/
  set_hp(2500);
  set_wc(60); /* Consistent with monster-guide */
  set_ac(30); /* Consistent with monster-guide */
  set_short("A hideous "+YEL+"Moat-Monster"+NORM);
  set_long("\
The moat-monster closely resembles a gigantic squid.  Its tentacles\n\
are covered in barbs and end in sharp spikes and its dark brown color\n\
allows it to blend in with the moat-bottom, allowing it to ambush unwary\n\
prey.  The squid also has an enormous, razor-sharp beak below a tiny pair\n\
of jet-black eyes.\n");
  message_hit = ({
    HIR+"reduces"+NORM, HIR+" to a bloody pulp"+NORM,
    HIR+"rips a chunk of flesh out of"+NORM, " with its razor-sharp beak",
    RED+"savagely bites"+NORM, " with its razor-sharp beak",
    RED+"bites"+NORM, " HARD",
    RED+"bites"+NORM, " hard",
    "bites", " with its beak",
    "strikes", " with a glancing blow"
  });
  set_dead_ob(this_object()); /* On death, ink the room (stun) and dest corpse */
  
  set_armor_params("other|water", 100, 100, 0); /* Immune to water damage  */
  set_armor_params("other|poison", 0, 50, 0);   /* 50% resistant to poison */
  set_armor_params("other|light", 0, -25, 0);   /* Extra damage from light */
  set_armor_params("other|fire", 0, -50, 0);    /* Extra damage from heat  */
  
  /* I arrived at the following bonuses by the following average stats
   * with the poison damage granting 3/2 bonus over physical:
   * 5 tentacle attacks, averaging 4 damage physical, 2 damage poison = 23 wc bonus
   * I'm cutting the bonus in half since it's low physical damage and does less damage.
   * avg 5 additional tentacle attacks at same average = 23 wc bonus altogether
   * avg 5 tentacle defenses, at 4 hp avg regen each per hb at 2 bonus per = 40 ac bonus
   */
  set_wc_bonus(23);
  set_ac_bonus(40);
  
  /* Three spells in place, each have a 15% chance of going off each will do up to 
   * 100 physical damage, one will hit just the non-players, and the other will hit just
   * the players.
   */
  add_spell("area_effect", 
            "#MN#"+HIR+" goes into a frenzy and flails wildly with its tentacles!\n"+NORM,
            "#MN#"+HIR+" goes into a frenzy and flails wildly with its tentacles!\n"+NORM,
            15, "10d10", 0, 1);
  add_spell("pet_killer",
            0,
            "#MN#"+HIC+" goes into a frenzy and flails wildly with its tentacles!\n"+NORM,
            15, 100, 0, 4, 0);
  add_spell("just_the_players",
            "#MN#"+HIG+" goes into a frenzy and flails wildly with its tentacles!\n"+NORM,
            "#MN#"+HIG+" goes into a frenzy and flails wildly with its tentacles!\n"+NORM,
            15, 100, 0, 3, 0);
} 

status corpse_check(object ob)
{
  object corpse;
  
  corpse = present("corpse", ob);
  
  if (!corpse)
    return 0;
    
  tell_room(ob, HIK+"\n\n\nThe squid glories in its kill!\n\
It grabs a corpse with a few tentacles and starts to turn around...\n\
The squid releases a cloud of ink and you can't see a thing.\n"+NORM);
  move_object(clone_object(INKCLOUD), ob);
      
  while (corpse)
  {
    move_object(corpse, HIDEOUT);
    corpse = present("corpse", ob);
  }
      
  move_object(this_object(), HIDEOUT);
  call_out("return_to_room", 10);
  return 1;
}

void heart_beat()
{
  int i, rnum, tdam, tpdam;
  object here, att, corpse;
  string attname;
  
  ::heart_beat();
  here = environment(this_object());
  
  if (find_object(MYHOME) != here) return;
  
  if (corpse_check(here)) return;
  
  /* Make sure everyone in the room is attacked */
  if (!attacker_ob)
  {
    object ob;
    
    ob = first_inventory(here);
  
    while(ob)
    {
      if (ob != this_object() && living(ob) 
      && (int)ob->is_wizard() < 1 && (status)ob->query_ghost() < 1)
      {
        att = ob;
        attacked_by(ob);
        ob->attacked_by(this_object());
      }
      
      ob = next_inventory(ob);
    }
  }
  else
  {
    att = attacker_ob;
  }
  
  if (!att) /* Turn off heartbeat if no victims are around */
  {
    set_heart_beat(0);
    return;
  }
  
  attname = (string)att->query_name();
  tdam = tpdam = 0;
  rnum = 11 + random(11);
  
  if (random(100) < 5) /* 1/20 chance of an extra attack() */
    attack(); 
  
  for (i = 0; i < rnum; i++)
  {
    if (i < 5 || !random(2)) /* Tentacle attacks */
    {
      int dmg, pdmg;
      string c;

      tdam += random(3) + random(3);  /* 0-8 damage, avg 4 */
      dmg   = random(3) + random(3);
      pdmg  = random(3) + random(3);  /* 0-4 poison damage, avg 2 */
      c = (pdmg ? GRN : "");
      
      switch(dmg)
      {
        case 0:    say(name+" misses with a swinging tentacle.\n");
                   break;
        case 1:    tell_room(here, name+c+" hits "+attname+" weakly with a tentacle.\n"+NORM, ({ att }));
                   tell_object(att, name+c+" hits you weakly with a tentacle.\n"+NORM);
                   break;
        case 2..3: tell_room(here, name+c+" hits "+attname+" with a tentacle.\n"+NORM, ({ att }));
                   tell_object(att, name+c+" hits you with a tentacle.\n"+NORM);
                   break;
        case 4:    tell_room(here, name+c+" hits "+attname+" hard with a tentacle.\n"+NORM, ({ att }));
                   tell_object(att, name+c+" hits you hard with a tentacle.\n"+NORM);
                   break;
      }
      
      if (dmg)
        att->hit_player(dmg);
        
      tpdam += pdmg;
      
      if ((int)att->query_hp() <= 0 && corpse_check(here))
        return; /* To make sure the hit_player() didn't kill them */
    }
    else
    {
      say(name+" uses its tentacles to defend itself.\n");
      heal_self(random(5)+random(5));
    }
    
  }
  
  if (tdam)
    att->hit_player(tdam);
    
  if (att && (int)att->query_hp() <= 0)
    corpse_check(here);
  else if (tpdam) 
    att->hit_player(tpdam, "other|poison");
}

void return_to_room()
{
  object myroom, ob;
  
  myroom = find_object(MYHOME);
  tell_room(myroom, "The "+name+" suddenly jumps out from the darkness!\n");
  move_object(this_object(), myroom);
  ob = present(PLAYER_ID, myroom);
  
  while(ob)
  {
    if ((int)ob->query_level() < 20 && (status)ob->query_ghost() < 1)
      ob->attacked_by(this_object());
      
    ob = next_inventory(ob);
  }
}

void init()
{
  ::init();
  set_heart_beat(1);
}

void ink_cloud()
{
  object here;
  
  here = environment(this_object());
  tell_room(here, HIK+"\nThe squid releases a massive cloud of some type of black substance!\n"+NORM);
  move_object(clone_object(INKCLOUD), here);
}

/* 
 * Ugh, I died.  Cause an overall stun, then disintigrate the corpse.  
 * Purely thematic, no other reason for this, just need a justification for 
 * leaving no corpse heh :)
 */
int monster_died()
{
  object corpse;
  
  environment()->add_exit(RPATH+"moat_cave", "enter");
  corpse = present("corpse", environment());
  destruct(corpse);
  tell_room(environment(), "The squid disintigrates as it dies.\n");
  ink_cloud();
  return 1;
}