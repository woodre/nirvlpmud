inherit "room/room";
reset(arg){
   object eric;
   if(!arg) {
      set_light(1);
      short_desc = "Easthall basement";
      long_desc =
      "You have enter the East Hall basement.  This is where a majority\n"+
      "of the IIT students come to play Nirvana.\n";
/* next desc edited by verte 2.10.15 */
/*
      "of of the IIT students come to play Nirvana.  One particular student\n"+
      "catches you eye, it's Roomstalker.  Kill him and get the terminal \n"+
      "and log him out.\n";
*/
      
/*
      eric=clone_object("players/lew/easthall/eric");
      move_object(eric, this_object());
*/
    move_object(clone_object("players/lew/easthall/graham"), this_object());
      
      dest_dir = ( {
            "players/lew/easthall/firstfloor", "up",
            "players/lew/southhall/tunnel2","west",
            });
   }
   
}
