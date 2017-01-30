/*
 *      File:                   tsprite.c
 *      Function:               monster.c
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 11/2004
 *      Notes:                  
 *      Change History:         Corrupted tree sprite
 */

#include <ansi.h>
#include "/players/hogath/tools/def.h"

inherit "obj/monster.c";
string color;
reset(arg){
  ::reset(arg);
  if(arg) return;
  if (!present("dagger"));
   get_weapon();
   switch (random(4))  {
           case 0: color=BOLD; break;
           case 1: color=YEL; break;
           case 2: color=BOLD; break;
           case 3: color=HIY; break;
           default: color=BOLD; break;
                              }
  set_name("tree sprite");
  set_race("sprite");
  set_short(color+"Malzar"+NORM);
  set_long("This diminutive sprite has been twisted by the magic of the\n"+
           "forest and the death of his friends.  He is dressed in colors\n"+
           "matching the forest background and belie his.  An evil fire\n"+
           "burns once peaceful eyes and a little drool escapes his mouth.\n");
  set_level(20);
  set_hp(400);
  set_al(-250);
  set_ac(20+random(5));
  set_wc(19);
  set_heal(1,2);
  set_aggressive(1);
  set_chat_chance(2);
  load_chat(color+"Malzar"+NORM+" shouts:  \"THE FOREST WILL TWIST YOU.\"\n");
  load_chat(color+"Malzar"+NORM+" slobbers and laughs a manic's laugh.\n");
  set_a_chat_chance(5);
  load_a_chat(color+"Malzar"+NORM+" steps to the side, avoiding the attack.\n");
  set_armor_params("other|holy", -5,-10, "aura_holy");
  set_armor_params("other|evil", 10,30, "aura_evil");
  add_spell("eye gouge",
            color+"Malzar "+HIR+" G O U G E S your eyes!\n"+NORM,
            color+"Malzar"+NORM+" "+BOLD+"G O U G E S"+NORM+" #CTN# eyes!\n",
            15,45,"physical");
 set_dead_ob(this_object());
 }
monster_died(ob){
    object bag;   
    tell_room(environment(),
    color+"Malzar"+NORM+" drops a small purse as he perishes.\n");
    bag = clone_object("/players/hogath/area/misc/coinbag.c");
    move_object(bag,environment(ob));
    }
id(str){return (::id(str) || str == "sprite" || str == "tree sprite" || str == "demon" || str =="malzar");}

int aura_holy(){
  if(!random(5)){
    tell_room(environment(),
    ""+HIW+"Malzar is burned fiercely by the holy light"+NORM+"!\n");
    return -1000;
  }
}

int aura_evil(){
  if(!random(4)){
    tell_room(environment(),
    ""+HIK+"Malzar seems to absorb and revel in the unholy energy!\n"+NORM); 
    heal_self(25);
    return 1002;
  }
}

get_weapon(){
  move_object(clone_object("/players/hogath/area/items/weapons/odagger.c"));
  init_command("wield dagger");
}
