/*
 *      File:                   thead.c
 *      Function:               NPC
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 11/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include "/players/hogath/tools/def.h"

inherit "obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
 
  set_name("thornhead");
  set_race("demon");
  set_short("Thornhead Demon");
  set_long("A large demon of the forest stands here.  As you take in\n"+
           "his form you note the two large horns and what appear to\n"+
           "to be snake like appendges on it's head writhing around \n"+
           "a set of very large protrudeing horns.\n"+
           HIK+"He is surronded by a dark aura.\n"+NORM);
  set_level(20);
  set_hp(700);
  set_al(-1000);
  set_ac(20);
  set_wc(33);
  set_heal(1,2);
  set_aggressive(0);
  set_chat_chance(2);
  load_chat("Demon growls.\n");
  load_chat("Demon stalks around the room.\n");
  set_a_chat_chance(5);
  load_a_chat("Demon "+BOLD+"R O A R S"+NORM+".\n");
  set_armor_params("other|good", -5,-10, "aura_holy");
  set_armor_params("other|evil", 10,30, "aura_evil");
  add_spell("snake attack",
            "Demon "+YEL+"S N A K E S"+NORM+" strike!\n"+NORM,
            "Demon "+YEL+"S N A K E S"+NORM+" strike at "+BOLD+"#CTN#!\n"+NORM,
            5,20,"other|poison");
 
  add_spell("demon_punch",
            "\nThe Demon "+BOLD+" R U S H E S"+NORM+" forward\n"+
            HIR+"\n\tS L A M S"+NORM+" you into the wall!\n\n"+
            "You stumble back from the blow as "+HIM+" P A I N"+NORM+" racks your body!\n",
            "\n#CMN# "+BOLD+" R U S H E S"+NORM+" forward!\n"+
            HIR+"\n\tS L A M I N G"+NORM+" #CTN# into the cave wall!\n",
            20,40,"physical");
  set_dead_ob(this_object()); 
}


id(str){return (::id(str) || str == "demon" || str == "thornhead demon" || str == "thornhead" || str == "Demon");} 
int aura_holy(){
  if(!random(5)){
    tell_room(environment(),
    "Demon is burned by "+atn+"'s"+HIW+" H O L Y"+NORM+" attack!\n");
    return -1000;
  }
}

int aura_evil(){
  if(!random(4)){
    tell_room(environment(),
    "Demon writhes in pleasure as "+HIK+" U N H O L Y"+NORM+" power washes over it!\n"); 
    heal_self(25);
    return 1002;
  }
}

monster_died(ob){
    object horn;   
    tell_room(environment(),
    "As the demon crashes to the ground....dead.  A massive horn cracks off.\n");
    horn = clone_object("/players/hogath/area/misc/horn.c");
    move_object(horn,environment(ob));
    }
