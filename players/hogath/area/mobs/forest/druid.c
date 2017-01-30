/*
 *      File:                   druid.c
 *      Function:               npc
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 06/22/2004
 *      Notes:                  
 *                              
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "/players/vertebraker/closed/std/monster.c";

int x;
string *bad_guilds;

id(str){return (::id(str) || str == "druid" || str == "Nature mage" || str == "nature mage");} 

reset(arg) {
  ::reset(arg);
  if(arg) return;
  if (!present("club"));
   get_weapon();
  set_name("Jahira");
  set_alt_name("jahira");
  set_alias("Druid");
  set_short(BOLD+"Jahira"+NORM+" ]"+YEL+"Druid"+NORM+"[");
  set_long("Tall and statuesque with slightly elven featurs.  Clad in\n"+
           "greens and browns of the forest.  She opposes all who would\n"+
           "endanger the balance of the forest.\n");
  set_gender("female");
  set_race("human");
  set_level(21);
  set_wc(20);
  set_ac(23);
  set_hp(1500);
  set_al(0);
  set_chat_chance(1);
  load_chat(BOLD+"Jahira"+NORM+" says:  'The forest is over run by evil.'\n");
  load_chat(BOLD+"Jahira"+NORM+" says:  'Gems are valuable in my magic.'\n");
  load_chat(BOLD+"Jahira"+NORM+" says:  'I have sealed the forest exits to those who would harm the balance.'\n");
  set_a_chat_chance(1);
  set_ac_bonus(x);
  add_money(2000+(random(1500)));
  add_spell("wood spear",
            "Jahira throws a chunk of"+HIK+" Hemitite"+NORM+"...\n\n"+
            ""+YEL+BLINK+"W O O D  S P E A R S"+NORM+" strike at you!\n\n",
            "Jahira hurls  "+HIK+"Hemitite"+NORM+"...\n\n"+
            ""+YEL+""+BLINK+"W O O D  S P E A R S"+NORM+" strike #CTN#.\n\n",
            15,({20,20,20}),({"other|earth","other|earth","other|earth"}));
  add_spell("call lightning",
            HIC+"A blue quartz crystal"+NORM+" flashes in "+BOLD+"Jahira's"+NORM+" hand..\n\n"+
                "A bolt of "+HIY+BLINK+"L I G H T I N G"+NORM+" fries you!\n"+NORM,
            HIC+"A blue quartz crystal"+NORM+" dances in "+BOLD+"Jahira's"+NORM+" hand..\n\n"+
        HIY+BLINK+"L I G H T N I N G"+NORM+" strikes #CTN#\n",
            15,100,"other|lightning");
  add_spell("call wave",
        BOLD+"Jahira"+NORM+" crushes a piece of "+HIC+"Aquamarine"+NORM+"\n"+
         HIC+"A wave crashes into you!\n\n"+NORM,
        BOLD+"Jahira "+NORM+"crushes a piece of "+HIC+"Aquamarine"+NORM+"\n"+
         HIC+"A wave crashes into #CTN#!\n\n",
             15,({35,35}),({"other|water","other|water"}));
  add_spell("call fire",
       BOLD+"Jahira "+NORM+"tosses up a "+HIR+"Garnet"+NORM+"..\n\n"+
  HIR+BLINK+"F L A M E S"+NORM+" whip out at you!\n",
       BOLD+"Jahira "+NORM+"tosses up a "+HIR+"Garnet"+NORM+"..\n\n"+
  HIR+BLINK+"F L A M E S"+NORM+" whip into #CTN#!\n\n",
            15,({15,15,15,15}),({"other|fire","other|fire","other|fire","other|fire"}));
x = 0;
}

heart_beat(){
  object attacker;
  attacker = this_object()->query_attack();
  ::heart_beat();
  if(!attacker) return;
  if(random(4) == 4){
    tell_room(environment(this_player()),BOLD+"Jahira calls upon nature's healing power.\n"+NORM);
    heal_self(50);
    x+=50;
   }
}
  



get_weapon(){
  move_object(clone_object("/players/hogath/area/items/weapons/uclub.c"));
  init_command("wield club");
}


/*void init() {
  ::init();
  if(this_player() && this_player()->is_player() && !attacker_ob && if (present(this_player(),"implants")))
  {
    tell_room(environment(),"Jahira looks at "+tpn+".\n"+
                            "Jahira says: "+BOLD+"E V I L "+HIR+"YOU WILL DIE"+NORM+".\n"+
                            "Jahira calls upon holy power and attacks!\n");
    kill_ob=this_player(); 
  }
}
*/


