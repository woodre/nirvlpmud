/*
*      File:                   mana_orb.c
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
   set_name(MAG+"Breath"+HIW+" of"+NORM+MAG+" Souls"+NORM);
   set_alias("breath of souls");
   set_ac(0);
   set_short(query_name());
   /* orb id already exists in the inherit */
   set_long("This orb is shaped into a small square.  Upon further examination\n"+
      "you see a small creature, motionless and inprisoned forever in the\n"+
      "center of the orb.\n");
}
int do_special(object owner)
{
   if(!ATT){
      return 0;
   }
   else
      {
      if(!random(8)){
         USER->add_spell_point(2+random(3));
         tell_room(environment(USER),
            (USER->query_name())+" is surrounded by an "+HIM+"aura"+NORM+" of magic.\n", ({ USER }));
         tell_object(USER, "A "+HIM+"magical aura"+NORM+" spills from the Orb over your body.\n");
      }
   }
}
