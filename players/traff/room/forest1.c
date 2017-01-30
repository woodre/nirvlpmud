
inherit "room/room";

reset(arg){


 if(!arg){

 set_light(1);
 short_desc="Skoda Forest";
 long_desc=
("You have wandered into the Skoda forest.  This forest covers\n"+
"hundreds of square miles of the lower part of the Skoda mountains\n"+
"You are surounded by trees that all look pretty much alike.\n"+
"It would be easy to get lost here.\n");

items=({
"ground","The ground is cover with pine needles",
"trees","Mostly conifers, they are tall and green",
"mountains","The mountains rise steadily to the north.  You see snow capped peaks",
 });

  dest_dir=({
"/players/traff/room/forest1.c","north",
"/players/traff/room/dmain.c","south",
"/players/traff/room/forest1.c","east",
"/players/traff/room/forest1.c","west",
      });
  }   }

