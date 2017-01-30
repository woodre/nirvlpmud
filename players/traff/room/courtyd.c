
inherit "room/room";

reset(arg){

if(!present("minion"))  {
move_object(clone_object("/players/traff/mon/minion.c"),this_object());  }

 if(!arg){

 set_light(1);
 short_desc="Courtyard";
 long_desc=
("A beautiful open courtyard.  In the center is a medium size\n"+
"statue.  To the north is a well trimmed hedge with an open\n"+
"archway cut in it.  On either side are the walls of the Keep.  All\n"+
"around you are beds of flowers, and well trimmed bushes.\n");

items=({
"ground","What is not covered with flowers and bushes is grass",
"statue","A statue of a dragon.  On the base someone has written"+
"in a crude hand, THE DRAGON LIVES",
"flowers","Many varities and all colors, their fragrance fills the air",
"hedge","About 6 feet tall, you can see a path through the opening",
"bushes","They appear to be evergreens of some sort",
"walls","The walls of the keep are grey stone, from the mountains",
 });

  dest_dir=({
"/players/traff/room/forest1.c","north",
"/players/traff/room/kentry.c","south",
      });
  }   }

