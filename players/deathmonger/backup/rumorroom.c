
inherit "room/room";

reset(arg){
   object board;
   short_desc = "Rumor room";
   long_desc = 
"Please speak in a low whisper in this room as we don't like to disturb\n"+
"the wild rumors nesting nearby.  If you would like to do your evil part\n"+
"to propagate rumors then please post them here.  The room is plushly\n"+
"decorated with silken curtains and deep carpeting.  Occasionally you\n"+
"can here faint whispers that sound distinctly like the voice of Airwoman.\n";

   items = ({
"boar", "The boar snorts defiantly and looks right back at you, hungrily",
"flames", "The flames jump and dance",
});
   dest_dir = ({
   "players/deathmonger/flameroom", "west",
   "players/deathmonger/never_ending", "east",
   });

   if(!present("board")){
     board = clone_object("players/deathmonger/board");
     board->set_datafile("rumor");
     board->set_name("rumor");
     move_object(board, this_object());
   }
   set_light(1);
}
