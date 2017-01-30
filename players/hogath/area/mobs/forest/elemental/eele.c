/*
 *      File:                   eele.h
 *      Function:               NPC
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 11/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "/players/vertebraker/closed/std/monster.c";
id(str){return (::id(str) || str == "Elemental" || str == "earth elemental" || str == "earth man");} 
int x;
int y;
int dam;
int hpt;
string size;
string bitem;
object ob;
reset(arg){
  ::reset(arg);
  if(arg) return;
  y = (random(4));
  x = (y+16);


if (x == 16){ size = "small"; hpt = 210; dam = 10;}
if (x == 17){ size = "medium"; hpt = 310; dam = 20;}
if (x == 18){ size = "large"; hpt = 410;  dam = 30;}
if (x == 19){ size = "elder";  hpt = 460;  dam = 35;}
if (x == 20){ size = "gigantic"; hpt = 510; dam = 45;}


set_name("earth elemental");
set_alias("Earth elemental");
set_race("elemental");
set_short(YEL+"A "+size+" earth elemental"+NORM);
set_long(YEL+"A humanoid made of dirt, stones, precious metals, and gems.\n"+
             "It has a cold, expressionless face, and two eyes that sparkle\n"+
             "like brilliant, multifaceted gems. Though it has a mouth-like\n"+
             "opening in its face, it does not seem to be able to speak.\n"+NORM);
set_hp(hpt+random(100));
set_level(x);
set_al(-500+(-x*10));
set_wc(x+random(6));
set_ac(x+y+random(10));
set_heal(1,y+1);
set_chat_chance(1);
load_chat(YEL+"Elemental rumbles around the room.\n"+NORM);
set_armor_params("other|earth", 10,30, "aura_earth");
set_armor_params("other|wind", -10,-30, "aura_wind");
set_aggressive(1);
add_spell("Earth_slam",
            ""+YEL+"#MN#"+NORM+" lifts you up and!\n"+
            "\t"+BOLD+"S L A M S "+NORM+" you to the ground\n",
            ""+YEL+"#MN#"+NORM+""+BOLD+" S L A M S "+NORM+"#CTN# to the ground.\n",
            20,(dam+15),"other|earth");
add_spell("earth_quake\n",
          YEL+"#MN#"+NORM+" stomps\n"+
          YEL+"AN EARTH QUAKE SHAKES THE YOU!!"+NORM+"\n",
          YEL+"#MN#"+NORM+" stomps\n"+
          YEL+"\n\tAN EARTHQUAKE SHAKES "+NORM+"#CTN#!!\n",
          10,(dam+25),"other|earth"); 
set_dead_ob(this_object());
set_wander(120, 0, ({ "back" }));
   }

monster_died(ob){
    object gem;   
    tell_room(environment(),
    "A gem falls to the ground as the"+YEL+" earth elemental"+NORM+" crumbles.\n");
    gem = clone_object("/players/hogath/area/misc/egem.c");
    gem->set_value(1000+(y*1000)-random(200));
    move_object(gem,environment(ob));
    }

int aura_eart(){
  if(!random(5)){
    tell_room(environment(),
    ""+YEL+"The power of earth heals the elemental!"+NORM+"\n");
    heal_self(25);
    return 1002;
  }
}

int aura_wind(){
  if(!random(4)){
    tell_room(environment(),
    ""+HIC+"Wind whips through the earth elemental!\n"+NORM); 
    return -1000;
  }
}

