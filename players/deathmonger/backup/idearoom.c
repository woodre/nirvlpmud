
inherit "room/room";

reset(arg){
   object board;
   short_desc = "Idea room";
   long_desc = 

"The Nirvana slave wizards are hardly at work developing new and improved\n"+
"mud services for your enjoyment.  In the unlikely event that you have a\n"+
"new-fangled idea that we haven't already considered and laughed out of\n"+
"the room, do post here.\n";


   items = ({
"boar", "The boar snorts defiantly and looks right back at you, hungrily",
"wizards", "All the wizards here mostly suck except for Deathmonger",
});
   dest_dir=({
   "players/deathmonger/bugroom", "east",
   });

   if(!present("board")){
     board = clone_object("players/deathmonger/board");
     board->set_datafile("idea");
     board->set_name("idea");
     move_object(board, this_object());
   }
   set_light(1);
}
