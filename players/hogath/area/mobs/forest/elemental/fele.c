/*
 *      File:                   fele.h
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

id(str){return (::id(str) || str == "Elemental" || str == "fire elemental" || str == "fire man");} 
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


set_name("fire elemental");
set_alias("Fire elemental");
set_race("elemental");
set_short(HIR+"A "+size+" fire elemental"+NORM);
set_long(HIR+"Appearing as a tall sheet of flame. The fire elemental has\n"+
             "two armlike appendages, one on each side of its body. These\n"+
             "arms flicker back into the creature's flaming body, only to\n"+
             "spring out from its sides seconds later. It's only facial \n"+
             "features are two large glowing patches of brilliant blue fire,\n"+
             "function as eyes for the elemental.\n"+NORM);
set_hp(hpt+random(100));
set_level(x);
set_al(-500+(-x*10));
set_wc(x+random(6));
set_ac(x+y+random(5));
set_heal(1,y);
set_chat_chance(1);
load_chat(HIR+"Flames roar around the elemental.\n"+NORM);
set_armor_params("other|fire", 10,30, "aura_fire");
set_armor_params("other|water", -10,-30, "aura_water");set_aggressive(1);
set_aggressive(1);
add_spell("Flame_toss",
            ""+HIR+"#MN#"+NORM+" hurls a "+size+" fireball at you!\n",
            ""+HIR+"#MN#"+NORM+" hurls a "+size+" fireball at #CTN#!\n",
            20,(dam+10),"other|fire");
add_spell("Flame_column\n",
          ""+HIR+"#MN#"+NORM+" gestures\n"+
          ""+HIR+"A COLUMN OF FLAME ENGULFS YOU!!"+NORM+"\n",
          ""+HIR+"#MN#"+NORM+" gestures\n"+
          ""+HIR+"\n\tA COLUMN OF FLAME ENGULFS #CTN#!!"+NORM+"\n",
          10,(dam+25),"other|fire"); 
set_dead_ob(this_object());
set_wander(120, 0, ({ "back" }));
}

monster_died(ob){
    object gem;   
    tell_room(environment(),
    "A gem falls to the ground as the"+HIR+" fire elemental"+NORM+" disapates.\n");
    gem = clone_object("/players/hogath/area/misc/fgem.c");
    gem->set_value(1000+(y*1000)-random(200));
    move_object(gem,environment(ob));
    }

int aura_fire(){
  if(!random(5)){
    tell_room(environment(),
    ""+HIR+"The elemental writhes in the fire!\n"+NORM);
    heal_self(25);
    return 1002;
  }
}

int aura_water(){
  if(!random(4)){
    tell_room(environment(),
    ""+HIC+"Water streams over the elemental putting out it's fire!\n"+NORM); 
    return -1000;
  }
}

