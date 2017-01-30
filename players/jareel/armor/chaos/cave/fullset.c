/*
*      File:                   /players/jareel/armor/mondar_death_SET
*      Function:               The forged full set of mondar armor
*      Author(s):              Earwax@Nirvana
*      Copyright:              Copyright (c) 2005 Earwax
*                                      All Rights Reserved.
*      Source:                 11/10/05
*      Approved by:
*      Notes:                  Requires the following 7 pieces to forge:
*                                mondar_amulet.c
*                                mondar_armor.c
*                                mondar_boots.c
*                                mondar_gauntlets.c
*                                mondar_helmet.c
*                                mondar_misc.c
*                                mondar_shield.c
*      Change History:
*/

/*
* Function name:
* Description:
* Arguments:
* Returns:
*/

/*
* EDITS
* Mokri - 04 May 2007. Added check if(ATT) to most functions in do_special()
   *                      to fix bugs called from hit_player() in living.c while
*                      player not in combat (or any time its triggered without
   *                      an attacker)
*/

#include "/players/jareel/define.h"
#define ATT USER->query_attack()
#define USER environment(this_object())

inherit "/obj/armor.c";

void reset(status arg)
{
   ::reset(arg);
   
   set_name("death set");
   set_ac(17);
   set_value(15800);
   set_weight(15);
   set_types( ({"armor", "amulet", "boots", "gloves", "helmet", "chest", "shield" }) );
   set_short("Iron "+BOLD+BLK+"fullplate"+NORM+" of death ("+HIG+"Complete Death Set"+NORM+")");
   set_long("\
      "+HIG+"Death Set"+NORM+"       \n\
      The deathplate is finely crafted grey steel plate.  It's a very rare\n\
      and powerful armor that requires the accumulation of its components\n\
      and then having them forged into one set.  Few ever see this armor,\n\
      far fewer possess it.\n");
}

status id(string arg)
{
   return ( ::id(arg) || arg == "fullplate"
      || arg == "plate"
      || arg == "fullset"
      || arg == "iron plate"
      || arg == "iron plate of death"
      || arg == "death set"
      || arg == "set of death"
      || arg == "iron fullplate of death");
}

int query_save_flag() { return 0; }

/* Running through all the specials in individual components of armor */
int do_special(object owner)
{
   int i, siz, ret;
   string ack, ugh, *msgs;
   object room;
   
   ret = 0;
   ack = (string)owner->query_name();
   if(ATT)
      ugh = capitalize((string)ATT->query_name());
   room = environment(owner);
   msgs = ({ });
   
   /* All the special effects vs NPC only */
   if (ATT && ATT->is_npc())
      {
      /* Body Armor */
      if (random(1000) < 100)
         {
         ATT->heal_self(-(random(5)));
         msgs += ({ " Fury washes over "+ack+"'s body " }) ;
       }
      /* Boots */
      if (random(1000) < 50)
         {
         owner->add_hit_point(random(5));
         msgs += ({ " Health washes over "+ack+"'s body " });
         ret += random(2);
       }
      /* Gauntlets */
      if (random(1000) < 50)
         {
         ATT->heal_self(-(random(4)));
         msgs += ({ " Health washes over "+ack+"'s body " });
         ret += random(2);
       }
      /* Gauntlets */
      if (random(1000) < 50)
         {
         ATT->hit_self(-(random(4)));
         msgs += ({ " "+ugh+" is smashed with a spinning backhand." });
         msgs += ({ " "+ugh+"'s "+RED+"blood"+NORM+" spurts everywhere." });
         ret += random(2);
       }
      /* Chest */
      if (random(1000) < 50)
         {
         ATT->heal_self(-(random(3)));
         msgs += ({ " The death rune glows on "+ack+"'s fullplate." });
         ret += random(2);
       }
      /* Shield */
      if (random(1000) < 10)
         {
         ATT->heal_self(-(random(4)));
         msgs += ({ " A black aura washes over "+ack+"'s shield." });
         ret += random(2);
       }
   }
   else
      {
      /* Body Armor */
      if (random(1000) < 100 && ATT)
         {
         ATT->hit_player(random(5), "other|evil");
         msgs += ({ " Fury washes over "+ack+"'s body." });
      }
      /* Boots */
      if (random(1000) < 50)
         {
         owner->add_hit_point(3+random(5));
         msgs += ({ " Health washes over "+ack+"'s body " });
         ret += random(2);
      }
      /* Gauntlets */
      if (random(1000) < 50 && ATT)
         {
         ATT->hit_player(random(4), "other|evil");
         msgs += ({ " "+ugh+" is smashed with a spinning backhand." });
         msgs += ({ " "+ugh+"'s "+RED+"blood"+NORM+" spurts everywhere." });
         ret += random(2);
      }
      /* Chest */
      if (random(1000) < 50 && ATT)
         {
         ATT->hit_player(random(4), "other|evil");
         msgs += ({ " The death rune glows on "+ack+"'s fullplate." });
         ret += random(2);
      }
      /* Shield */
      if (random(1000) < 10 && ATT)
         {
         ATT->add_spell_point(-(random(5)));
         msgs += ({ " A black aura washes over "+ack+"'s shield." });
         ret += random(2);
      }
   }
   
   /* Give the messages and return */
   siz = sizeof(msgs);
   /* for testing
   tell_room(room, HIR+"SIZE: "+siz+"\nRETURNS: "+ret+"\n"+NORM);
   */
   for (i = 0; i < siz; i++)
   {
      tell_room(room,
         ""+BOLD+" <"+RED+"<>"+NORM+BOLD+">"+HIK
         + msgs[i]
         + NORM+BOLD+" <"+RED+"<>"+NORM+BOLD+">\n"+NORM);
   }
   
   return ret;
}
