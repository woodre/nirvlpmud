
inherit "room/room";

reset(arg){

if(!present("sleepy"))  {
move_object(clone_object("/players/traff/mon/sleepy.c"),this_object());  }

 if(!arg){

 set_light(1);
 short_desc="Wall 1";
 long_desc=
("Wall 1.  The smallest of the walls, it is just a few steps\n"+
"above the ground to the north and slightly more that twice\n"+
"the height of a man on the south side.  For an attacker to\n"+
"get to this point would cost thousands of lives and weeks or\n"+
"months of battle!  You can see the town has grown to fill the space\n"+
"between the walls.  Some  plains are still visable to the south.\n"+
"North you can see the keep and it's grounds, and the ever present\n"+
"Skoda mountains beyond that.\n");

items=({
"ground","The ground along the wall is mostly dirt, with some grass",
"floor","The floor of the wall is stone worn smooth by age and use\n"+
"and stained by the blood of battle",
"mountains","The mountains rise steadily to the north.  You see snow capped peaks",
"walls","Between sheer cliffs, 6 walls span the pass controlling access",
"plains","Beyond the walls simi-arrid plains stretch as far as you can see",
"keep","Once the residence of the Earl of Bronze, it now houses minions of Casca",
"cliffs","Grey stone cliffs tower above the pass",
"town","You see the roofs of houses, shops, and taverns, below you\n",
 });

  dest_dir=({
"/players/traff/room/dmain.c","north",
"/players/traff/room/town.c","south",
      });
  }   }


init()  {
 ::init();
  add_action("north","north");
  add_action("south","south");
}


north()  {
  say("You descend the few steps to the ground and head north.\n");

call_other(this_player(),"move_player","north#players/traff/room/dmain.c");
 return 1;
         }

south()  {
  say("You descend the few steps to the ground and head south.\n");

call_other(this_player(),"move_player","south#players/traff/room/town.c");
 return 1;
         }
