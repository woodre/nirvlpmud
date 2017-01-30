/*
 *     c5.c              
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "room/room";

reset(arg) {
  if(!arg)
  { 

   set_light(0);

   short_desc = HIK+"Dragons Den"+NORM;


   long_desc="\
   Coarse, moist, solid rock bulges from the walls, as roots from the \n\
above trees descend from the crest of the cave .  Pools of water \n\
gather on the muddy ground from the mist of water sprinkling down\n\
from over head.  A form of silky plantation creeps up the side of the \n\
moistened walls, leaving them soft and slick.\n",

 items=({
"rock",
	"Rigid, damp rock covered in a fungus plantation",
"rocks", 
	"Rigid, damp rock covered in a fungus plantation",
"walls",
	"Walls of the cave are made out of coarse, damp rock",
"wall",
	"Walls of the cave are made out of coarse, damp rock",
"roots",
	"Long roots from the trees above sway in the brisk breeze sneaking through the crack",
"root",
	"Long roots from the trees above sway in the brisk breeze sneaking through the crack",
"trees",
	"Long roots from the trees above sway in the brisk breeze sneaking through the crack",
"tree",
	"Long roots from the trees above sway in the brisk breeze sneaking through the crack",
"cave",
	"A dark, damp, chilling cave with muddy ground",
"pool",
	"Puddles of water gather on the ground, as it rains from the crest of the cave",
"pools",
	"Puddles of water gather on the ground, as it rains from the crest of the cave",
"water",
	"Puddles of water gather on the ground, as it rains from the crest of the cave",
"ground",
	"Puddles of water gather on the muddy ground, as it rains from the crest of the cave",
"mist",
	"A misty rain falls from above",
"plantation",
	"A silky, moist fungus climbs the damp, rigid rock walls",

   });

      add_exit("/players/katya/area/mountain/r/c4.c","west");
      add_exit("/players/katya/area/mountain/r/c6.c","east");


}
}

