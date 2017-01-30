
inherit "room/room";

reset(arg){
   object board;
   short_desc = "Humor room";
   long_desc = 
"This is the most drab, boring room you have ever seen.  The walls are \n"+
"painted a most uninteresting gray color, and the featureless landscape\n"+
"is punctuated only by a solemn, solitary bulletin board.\n";

   items = ({
"boar", "The boar snorts defiantly and looks right back at you, hungrily",
"walls", "I already said the walls were really, really boring",
"landscape", "You can't have a 'landscape' in a room!  Duh!",
});

   dest_dir=({
   "players/deathmonger/flameroom", "east",
   });

   if(!present("board")){
     board = clone_object("players/deathmonger/board");
     board->set_datafile("humor");
     board->set_name("humor");
     move_object(board, this_object());
   }
   set_light(1);
}
