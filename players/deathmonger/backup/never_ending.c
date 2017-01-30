
inherit "room/room";

reset(arg){
   object board;
   short_desc = "Never ending story";
   long_desc = 
"A nice, warm campfire is the centerpiece of this room.  Apprentice\n"+
"story-tellers wield their tallest tales to all that would listen.  No\n"+
"one can say when the story will end, not till Nirvana itself goes down\n"+
"in a torrent of random bits.\n";

   items = ({
"boar", "The boar snorts defiantly and looks right back at you, hungrily",
"campfire", "The campfire is just right for toasting marshmellows",
"fire", "Fire is hot",
"landscape", "You can't have a 'landscape' in a room!  Duh!",
});

   dest_dir=({
   "players/deathmonger/rumorroom", "west",
   });

   if(!present("board")){
     board = clone_object("players/deathmonger/board");
     board->set_datafile("never_end");
     board->set_name("Never-ending story");
     move_object(board, this_object());
   }
   set_light(1);
}
