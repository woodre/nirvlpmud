/*
 *      File:                   wele.h
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "/players/vertebraker/closed/std/monster.c";
id(str){return (::id(str) || str == "Elemental" || str == "water elemental" || str == "wave");} 
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
if (x == 19){ size = "elder";  hpt = 450;  dam = 35;}
if (x == 20){ size = "gigantic"; hpt = 500; dam = 45;}


set_name("water elemental");
set_alias("Water elemental");
set_race("elemental");
set_short(HIB+"A "+size+" water elemental"+NORM);
set_long(HIB+"The water elemental appears as a high-crested wave.  It's\n"+
             "arms appear as smaller waves, one thrust out on each side\n"+
             "of its main body.  The arms ebb and flow, growing longer or\n"+
             "shorter as the it moves. Two orbs of deep green peering out\n"+
             "of the front of the wave, serve it's eyes.\n"+NORM); 
set_hp(hpt+random(120));
set_level(x);
set_al(-500+(-x*10));
set_wc(x+random(4));
set_ac(x+y+random(8));
set_heal(1,y);
set_chat_chance(1);
load_chat(HIB+"Waves crash around the elemental.\n"+NORM);
set_armor_params("other|fire", -10,-30, "aura_fire");
set_armor_params("other|water", 10,30, "aura_water");
set_aggressive(1);
add_spell("drown_him",
      HIB+"#MN#"+NORM+" tries "+HIB+"to D R O W N you!\n\n",
      HIB+"#MN#"+NORM+" tries "+HIB+"to D R O W N #CTN#!\n\n"+NORM+"",
          20,(dam+12),"other|water");
add_spell("Water_Sprout",
      HIB+"#MN#"+NORM+" calls out"+NORM+"\n"+
      BLU+"A WATER SPROUT CRASHES INTO YOU!!"+NORM+"\n",
     HIB+"#MN#"+NORM+" calls out\n"+NORM+""+
     BLU+"A WATER SPROUT SLAMS INTO #CTN#!!"+NORM+"\n",
            10,(dam+27),"other|water"); 

set_dead_ob(this_object());
set_wander(120, 0, ({ "back" }));
} 
  
monster_died(ob){
    object gem;   
    tell_room(environment(),
    "A gem falls to the ground as the"+HIB+" water elemental"+NORM+" evaporates.\n");
    gem = clone_object("/players/hogath/area/misc/wgem.c");
    gem->set_value(1000+(y*1000));
    move_object(gem,environment(ob));
    }
               
int aura_fire(){
  if(!random(5)){
    tell_room(environment(),
    ""+HIR+"HEAT EVAPORATES THE ELEMENTAL!!"+NORM+"\n");
    return 1002;
  }
}

int aura_water(){
  if(!random(4)){
    tell_room(environment(),
    ""+HIC+"ELEMENTAL ABSORBS WATER INTO ITSELF!\n"+NORM); 
    heal_self(25);
    return 1002;
  }
}
