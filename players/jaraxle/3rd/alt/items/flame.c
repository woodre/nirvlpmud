/*
*      File:                   flame.c
*      Function:               
*      Author(s):              Vertebraker@Nirvana
*      Copyright:              Copyright (c) 2005 Vertebraker
*                                      All Rights Reserved.
*      Source:                 10/21/2005
*      Notes:                
*      Change History:
*/

#include <ansi.h>
#include <security.h>

#define USER environment()
#define ATT ((object)USER->query_attack())

inherit "/players/jaraxle/3rd/alt/items/orb-lib";

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("Orb of "+RED+"Flame"+NORM);
   set_alias("orb of flame");
   set_ac(0);
   set_short(query_name());
   /* orb id already exists in the inherit */
   set_params("other|fire", 2, 30, "do_fire_special");
   set_long("A small red orb with a flickering flame in the center.\n");
}

int do_special(object owner)
{
   if(!ATT)
      {
      return 0;
   }
   else
      {
      if(!random(8))
         {
         string cast;
         
         switch(random(5))
         {
            case 0: cast = RED + "whip of fire" + NORM;
            break;
            case 1: cast = HIR + "lick of flame" + NORM;
            break;
            case 2: cast = RED + "spark of fire" + NORM;
            break;
            case 3: cast = YEL + "spit of flame" + NORM;
            break;
            case 4: cast = HIY + "ball of fire" + NORM;
            break;
         }
         
         tell_room(environment(USER),
            (string)USER->query_name()+
            "'s "+query_name()+" burns "+
            (string)ATT->query_name()+
            " with a "+cast+".\n",
            ({ USER, ATT }));
         tell_object(USER, "Your "+query_name()+" burns " +
            (string)ATT->query_name() + " with a " + cast + ".\n");
         tell_object(ATT,
            (string)USER->query_name()+
            "'s "+query_name()+" burns YOU with a "+cast+".\n");
         
         ATT->hit_player(random(2) + 1, "other|fire");
      }
   }
}


int do_fire_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         The "+query_name()+" glows a bright red as it absorbs some of the\n\
         fire damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost
      */
   }
}
