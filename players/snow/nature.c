inherit "room/room";
 
#include "/players/snow/closed/color.h"
reset(arg){

 if(!arg){
 
 set_light(1);
short_desc="Nexus <Nature>";
 long_desc=
"You have reached an interdimensional nexus. Streaks of blue fire streak\n"+
"across every horizon. Though it is cold as death in this nether-space,\n"+
"you feel strangely unafraid.\n";
 
items=({
"nexus","This is an interdimensional nexus",
"fire","Streaks of ice-blue fire flash across the blackness that is your\n"+
       "current world"
          });
 
  dest_dir=({
"/players/snow/gate.c","nexus",
"/players/snow/beach/beach1.c","beach",
"/players/snow/ROOMS/path1.c","mountain",
"/players/quantos/desert/des_ent.c","desert",
      });
  }   }
