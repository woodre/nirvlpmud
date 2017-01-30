/*
 *      File:                   aele.h
 *      Function:               NPC
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 11/2004
 *      Notes:                  Air elemental
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "/players/vertebraker/closed/std/monster.c";
id(str){return (::id(str) || str == "Elemental" || str == "air elemental" || str == "whirlwind");} 
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


if (x == 16){ size = "small"; hpt = 200; dam = 10;}
if (x == 17){ size = "medium"; hpt = 300; dam = 20;}
if (x == 18){ size = "large"; hpt = 400;  dam = 30;}
if (x == 19){ size = "very large";  hpt = 450;  dam = 35;}
if (x == 20){ size = "gigantic"; hpt = 500; dam = 45;}




set_name("Air elemental");
set_alias("air elemental");
set_race("elemental");
set_short(HIC+"A "+size+" air elemental"+NORM);
set_long(HIC+"With the appearence of an amorphous, shifting cloud the air\n"+
             "elemental is rarely seen but more heard in the high-pitched\n"+
             "shriek of a tornado or the low moan of a midnight storm.\n"+NORM);  
set_hp(hpt+random(80));
set_level(x);
set_al(-500+(-x*10));
set_wc(x+random(3));
set_ac(x+y+random(2));
set_heal(1,y+1);
set_chat_chance(1);
load_chat(HIC+"Winds whistle around the elemental.\n"+NORM);
load_chat(HIC+"Thunder rolls through the room.\n"+NORM);
set_armor_params("other|wind", 10,30, "aura_wind");
set_armor_params("other|earth", -10,-30, "aura_earth");
set_aggressive(1);
add_spell("wind_gust",
            "A whirlwind from the "+HIC+"#MN#"+NORM+" slams you to the ground!\n",
            "#TN# is slammed to the ground, by whirling winds!\n",
            10,(dam+33),"other|wind");
add_spell("electrical storm",
          HIY+"L I G T N I N G !!"+NORM+" arcs through the room.\n",
          "Sparks fly around the "+HIC+"#MN#"+NORM+".\n",
          20,(dam+20),"other|electric",1); 
set_dead_ob(this_object());
set_wander(120, 0, ({ "back" }));
}

monster_died(ob){
    object gem;   
    tell_room(environment(),
    "A gem falls to the ground as the"+HIC+" air elemental"+NORM+" disapates.\n");
    gem = clone_object("/players/hogath/area/misc/agem.c");
    gem->set_value(1000+(y*1000)-random(100));
    move_object(gem,environment(ob));
    }

int aura_wind(){
  if(!random(5)){
    tell_room(environment(),
    ""+HIC+"Air elemental is strengthened by the wind!"+NORM+"\n");
    heal_self(25);
    return 1002;
  }
}

int aura_earth(){
  if(!random(4)){
    tell_room(environment(),
    ""+YEL+"Air elemental is grounded by the earth based attack!\n"); 
    return -1000;
  }
}

