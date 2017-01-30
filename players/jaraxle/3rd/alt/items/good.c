/*
*      File:                   good.c
*      Function:               
*      Author(s):              Jaraxle@Nirvana
*      Copyright:              Copyright (c) 2005 Jaraxle
*                                      All Rights Reserved.
*      Source:                 10/22/2005
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
   set_name("Orb of "+WHT+BOLD+"Honor"+NORM);
   set_alias("orb of honor");
   set_ac(0);
   set_short(query_name());
   /* orb id already exists in the inherit */
   set_params("other|good", 2, 30, "do_good_special");
   set_long("A small diamond shaped orb with a holy glow around it.\n");
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
            case 0: cast = ""+WHT+BOLD+"beam of faith"+NORM+"";
            break;
            case 1: cast = ""+BOLD+"divine ball of good"+NORM+"";
            break;
            case 2: cast = ""+WHT+BOLD+"will of good"+NORM+"";
            break;
            case 3: cast = ""+BOLD+"strike of good"+NORM+"";
            break;
            case 4: cast = ""+WHT+BOLD+"force of righteousness"+NORM+"";
            break;
         }
         tell_room(environment(USER),
            (USER->query_name())+" blesses "+(ATT->query_name())+" with a "+cast+".\n", ({ USER }));
         tell_object(USER, "You bless "+(ATT->query_name())+" with a "+cast+".\n");
         ATT->hit_player(random(2) + 1, "other|good");
      }
   }
}


int do_good_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         The Orb of Good glows a bright white as it absorbs some of the\n"+
         "\tgood damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
