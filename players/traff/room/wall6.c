
inherit "room/room";

reset(arg){

  if(!present("nadir"))  {
    move_object(clone_object("/players/traff/mon/nadir1.c"),this_object());
    move_object(clone_object("/players/traff/mon/nadir2.c"),this_object());
    move_object(clone_object("/players/traff/mon/nadir3.c"),this_object());  }
  if(!present("warrior"))  {
    move_object(clone_object("/players/traff/mon/war1.c"),this_object());
    move_object(clone_object("/players/traff/mon/war2.c"),this_object());
    move_object(clone_object("/players/traff/mon/war3.c"),this_object());  }

 if(!arg){

 set_light(1);
 short_desc="Wall 6";
 long_desc=
("Wall 6, the tallest, longest and widest of the walls at Delnoch\n"+
"As you gaze at the blood stained stones you imagine that you have\n"+
"arrived during the battle of Delnoch.  You hear the sounds of\n"+
"hand-to-hand combat.  You see thousands of Nadir Tribesmen scaling the\n"+
"wall.  A few have made it to the top and gained a foothold, and\n"+
"are trying to make way for more.  As Delnoch warriors rush around\n"+
"you to close the breach, you realize that you are in the center\n"+
"of the battle!\n");

items=({
"ground","The ground along the wall is mostly dirt, with some grass",
"floor","The floor of the wall is stone worn smooth by age and use\n"+
"and stained by the blood of battle\n",
"mountains","The mountains rise steadily to the north.  You see snow capped peaks",
"walls","Between sheer cliffs, 6 walls span the pass controlling access",
"plains","From here the plains seem even vaster and more desolate",
"keep","Once the residence of the Earl of Bronze, it now houses minions of Casca",
"cliffs","Grey stone cliffs tower above the pass",
 });

  dest_dir=({
"/players/traff/room/killgrnd.c","north",
});
  }   }


init()  {
 ::init();
  add_action("north","north");
}


north()  {
  write("You descend the long narrow, winding steps and head north.\n");

call_other(this_player(),"move_player","north#players/traff/room/killgrnd.c");
 return 1;
         }
