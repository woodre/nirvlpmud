   /*                                       
    *  File:   /players/mosobp/areas/VEGEA/NPC/scout1.c
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
     set_name("scout");
     set_short(HIB+"Frozen Scout"+NORM);
     set_race("frozen");
     set_long(
     "This scout is from Frieza's home planet here to scout\n"+
     "defenses and troop positions on Planet Vegeta. Scouts\n"+
     "usually not someone to be taken lightly.\n");
     set_level(20);
     set_heart_beat(1);
     set_wander(1);
     set_wander_interval(6);
     set_wander_realm("/players/mosobp/areas/VEGETA/rooms/");
     set_hp(700+random(250));
     set_al(-100);
     set_wc(30+random(10));
     set_ac(30);
	 move_object(clone_object("/players/mosobp/areas/VEGETA/OBJ/scouter.c"), this_object());
	 init_command("wear scouter");
	 set_multi_cast(1);
	 add_spell("kiblast",
	 "The "+HIC+"Ki Blast"+NORM+" burns your stomach!\n",
	 "#MN# puts his hands in front of him and a"+HIY+" Ki Blast"+NORM+"shoots from\n"+
	 "his hands.\n",
	 45,"30-40","other|laser");
	 add_spell("kipunch",
	 "#MN# "+HIY+" P U N C H E S "+NORM+" you in the shoulder!!\n",
	 "#MN# "+HIY+" P U N C H E S "+NORM+" #TN# in the shoulder.\n",
	 40,30, "other|physical");
	 add_spell("excessive kipunch",
	 "#MN# "+HIY+" P U N C H E S "+NORM+" you in the shoulder!!\n"+
	 "#MN# "+HIR+" S W E E P S "+NORM+" you in the legs forcing you in the air!!\n"+
	 "#MN# "+HIB+" S L A M S "+NORM+" you down to the ground.\n",
	 "#MN# "+HIY+" P U N C H E S "+NORM+" #TN# in the shoulder.\n"+
	 "#MN# "+HIR+" S W E E P S "+NORM+" you in the legs forcing you in the air!!\n"+
	 "#MN# "+HIB+" S L A M S "+NORM+" you down to the ground.\n",
	 20,60, "other|physical");
	
	}
