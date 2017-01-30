   /*                                       
    *  File:   /players/mosobp/areas/VEGEA/NPC/scout2.c
    *  Function:  mob                      
    *  Author(s):  Mosobp@Nirvana           
    *  Copyright: copyright (c) 2013 Mosobp 
    *             all rights reserved           
    *                                       
    *                                       
    *  Source:  6/23/13                     
    *  Notes:                               
    * 
    *                                      
    *  Change History:                      
    */

#include "/sys/lib.h"
   
#include <ansi.h>
   
   inherit "/obj/monster";
   
   reset(arg) 
   {
     object gold;
     ::reset(arg);
     if(arg) return;
     set_name("guard");
     set_short(HIR+"Saiyan "+HIB+" Royal "+HIR+" Guard"+NORM);
     set_race("saiyan");
     set_long(
     "This guard is out on patrol looking for Frezarian scouts,\n"+
     "and is attempting to defend planet vegeta from an invasion.\n"+
     "The Saiyan Royal Guard are not to be taken lightly.\n");
     set_level(20);
     set_hp(700+random(400));
     set_al(500);
     set_wc(30+random(10));
     set_ac(20);
	 move_object(clone_object("/players/mosobp/areas/VEGETA/OBJ/scouter2.c"), this_object());
	 init_command("wear scouter");
	 set_multi_cast(1);
	 add_spell("kiblast",
	 "The "+HIY+"Ki Blast"+NORM+" burns your stomach!\n",
	 "#MN# puts his hands in front of him and a"+HIY+" Ki Blast"+NORM+" shoots from\n"+
	 "his hands.\n",
	 20,"40-50","other|good");
	 add_spell("lightblast",
	 "The "+HIC+"Ki Blast"+NORM+" burns your stomach!\n",
	 "#MN# puts his hands in front of him and a"+HIC+" Ki Blast"+NORM+"shoots from\n"+
	 "his hands.\n",
	 20,"40-50","other|light");
	 add_spell("laserblast",
	 "The "+RED+"Ki Blast"+NORM+" burns your stomach!\n",
	 "#MN# puts his hands in front of him and a"+RED+" Ki Blast"+NORM+"shoots from\n"+
	 "his hands.\n",
	 20,"40-50","other|laser");
	 add_spell("fireblast",
	 "The "+HIR+"Ki Blast"+NORM+" burns your stomach!\n",
	 "#MN# puts his hands in front of him and a"+HIR+" Ki Blast"+NORM+"shoots from\n"+
	 "his hands.\n",
	 20,"40-50","other|fire");
	 add_spell("iceblast",
	 "The "+HIB+"Ki Blast"+NORM+" burns your stomach!\n",
	 "#MN# puts his hands in front of him and a"+HIB+" Ki Blast"+NORM+"shoots from\n"+
	 "his hands.\n",
	 20,"40-50","other|ice");
	 set_heart_beat(1);
     set_wander(1);
     set_wander_interval(6);
     set_wander_realm("/players/mosobp/areas/VEGETA/rooms/");
	 
	}
