
inherit "room/room";

string *okremove;

reset(arg){
   object board;
   okremove = ({ "deathmonger", });
   short_desc = "Flame room";
   long_desc = 
"Flames shoot between the walls, touching the floor in places.  Any\n"+
"combustibles that touch the floor burst into flames.  When tempers\n"+
"flare, this is the place to take it out.\n";
   items = ({
"boar", "The boar snorts defiantly and looks right back at you, hungrily",
"flames", "The flames jump and dance",
"floor", "Better not walk barefoot",
});
   dest_dir=({
   "players/deathmonger/CASTLE/complaint_room", "north",
   "players/deathmonger/rumorroom", "east",
   "players/deathmonger/humorroom", "west",
   "players/deathmonger/bugroom", "south",
   });

   if(!present("board")){
     board = clone_object("open/old-flame-board/board");
     board->set_datafile("flame1");
     board->set_name("flame");
     move_object(board, this_object());
   }
   set_light(1);
}

init(){
   add_action("checkthat", "remove");
   ::init();
}

checkthat(){
   if(member_array(this_player()->query_real_name(), okremove) == -1){
write("A gnome appears from a door atop the bulletin board wielding\n"+
      "a twelve-gauge shotgun and points it at you.\n");
	  return 1;
   }
   else return 0;
}
