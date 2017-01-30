inherit"/room/room";

reset(arg) {
   set_light(1);
   if(arg) return;
   short_desc = "The Info Booth";
   long_desc = 
"You have entered what appeared to be a small booth from the outside, but is"+
"\nactually quite large inside.  On the while you notice two bulletin boards."+
"\nOne is the 'castle board' and the other is the 'guild board'.  Wizzes will"+
"\nkeep the latest castle and guild announcments on these boards, for your "+
"\nfurther mudding enjoyment.\n   You can examine the boards with 'look at"+
" <castle/guild> board.\n";
   dest_dir = ({"/room/church","leave"});
   if(!present("guild board", this_object())) 
      move_object(clone_object("/players/blue/info/guild_board.c"),
         this_object());
   if(!present("castle board", this_object()))
      move_object(clone_object("/players/blue/info/castle_board.c"),
         this_object());

}

