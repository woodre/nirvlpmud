/*
*      File:                   hate.c
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
   set_name("Orb of "+BLK+BOLD+"Hate"+NORM);
   set_alias("orb of hate");
   set_ac(0);
   set_short(query_name());
   /* orb id already exists in the inherit */
   set_params("other|evil", 2, 30, "do_evil_special");
   set_long("A small onyx orb with an evil, red and forboding glow around it.\n");
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
            case 0: cast = ""+BLK+BOLD+"diabolical blow"+NORM+"";
            break;
            case 1: cast = ""+BOLD+"hellish ball of hate"+NORM+"";
            break;
            case 2: cast = ""+BLK+BOLD+"will of evil"+NORM+"";
            break;
            case 3: cast = ""+BOLD+"strike of evil"+NORM+"";
            break;
            case 4: cast = ""+BLK+BOLD+"force of darkness"+NORM+"";
            break;
         }
         ATT->hit_player(random(2)+1, "other|evil");
         if(ATT)
            tell_room(environment(USER),
            (USER->query_name())+" torments "+(ATT->query_name())+" with a "+cast+".\n", ({ USER }));
         if(ATT)
            tell_object(USER, "You hit "+(ATT->query_name())+" with a "+cast+".\n");
      }
   }
}


int do_evil_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         The Orb of Evil glows a dark red as it absorbs some of the\n"+
         "\tevil damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
