/*
*      File:                   nature_orb.c
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
   set_name(HIW+"Nature's "+HIG+"Blessing"+NORM);
   set_alias("natures blessing");
   set_ac(0);
   set_short(query_name());
   /* orb id already exists in the inherit */
   set_params("other|fire", 2, 30, "do_fire_special");
   set_long(HIW+"Nature's "+HIG+"Blessing"+NORM+" is a powerful orb shaped from the essence of nature.\n");
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
         string cast, damage, element_damage;
         
         switch(random(5))
         {
            case 0: cast = ""+HIB+"splash of water"+NORM+"";
            damage = ""+HIB+"drowned"+NORM+"";
            element_damage = "other|water";
            break;
            case 1: cast = ""+HIR+"lick of flame"+NORM+"";
            damage = ""+HIR+"burned"+NORM+"";
            element_damage = "other|fire";
            break;
            case 2: cast = ""+BLK+BOLD+"giant boulder"+NORM+"";
            damage = ""+YEL+"smashed"+NORM+"";
            element_damage = "other|earth";
            break;
            case 3: cast = ""+CYN+"gust of wind"+NORM+"";
            damage = ""+HIC+"suffocated"+NORM+"";
            element_damage = "other|wind";
            break;
            case 4: cast = ""+HIY+"jolt of "+HIW+"lightning"+NORM+"";
            damage = ""+HIY+"zapped"+NORM+"";
            element_damage = "other|lightning";
            break;
         }
         
         if(ATT) {
            tell_room(environment(USER),
               (ATT->query_name())+" is "+damage+" with a "+cast+" from "+HIW+"Nature's "+HIG+"Blessing"+NORM+"!\n");
            if(ATT) ATT->hit_player(1+random(4), element_damage);
         }
      }
   }
   
}
