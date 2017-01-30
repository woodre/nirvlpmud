/*
*      File:                   armor_orb.c
*      Function:               
*      Author(s):              Jaraxle@Nirvana
*      Copyright:              Copyright (c) 2005 Jaraxle
*                                      All Rights Reserved.
*      Source:                 10/22/2005
*      Notes:                  Built with Vertebraker's love and help.
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
   set_name("Orb of "+BOLD+"Steel"+NORM);
   set_alias("orb of steel");
   set_short(query_name());
   set_ac(1);
   /* orb id already exists in the inherit */
   set_long("This looks like a very simple orb.  A high polished aluminum \n"+
      "sphere that reflects your face in a warped shape as you gaze\n"+
      "studiously into it.");
}


