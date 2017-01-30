
inherit "room/room";

reset(arg){
   object board;
   short_desc = "Bug room";
   long_desc = 
"Disgusting insects cover the exposed surfaces of this room.  Roaches \n"+
"skitter across the floor, and horrible beetles meander up and down the\n"+
"walls.  Spiders dance on the ceiling.  This looks like a good place to \n"+
"report unlikely events like game bugs.\n";
items = ({
"boar", "The boar snorts defiantly and looks right back at you, hungrily",
"insects", "The insects are really nasty looking, with lots of eyes",
"roaches", "Roaches are filthy, disgusting bugs, but that's just one opinion",
"spiders", "The spiders occasionally suspend themselves from a thread",
});

   dest_dir=({
   "players/deathmonger/flameroom", "north",
   "players/deathmonger/idearoom", "west",
   });

   if(!present("board")){
     board = clone_object("players/deathmonger/board");
     board->set_datafile("bug");
     board->set_name("bug");
     move_object(board, this_object());
   }
   set_light(1);
}
