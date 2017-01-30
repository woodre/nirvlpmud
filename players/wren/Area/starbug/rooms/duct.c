	/* Duct. Thanks to Novowels suggestion this room too is inhabited.   */
	/* Miles and miles of confusing crawl space.  Confidence and Paranoia*/
        /* are here.                                                         */

inherit "room/room";

reset(arg) {
    if(arg) 
       return ;

    if(!present("confidence")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/confidence.c"),this_object()); }      
    if(!present("paranoia")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/paranoia.c"),this_object()); }      

     set_light(1);
     short_desc = "A large duct";
     long_desc = 
"This is a long section of Starbug's ducts. These are used to carry air    \n\
to all the sections of the ship. You'll not want to linger too long though  \n\
for the cleaning cycle is amazingly rough. The passage extends well into the \n\
distance. \n";

  items=({
    "duct","You see that the passage continues into more ducts",
    "down","An open grate lets you get back into the main section"
           });

  dest_dir=({
     "/players/wren/Area/starbug/rooms/galley","down",
     "/players/wren/Area/starbug/rooms/duct2","duct"
               });

}
	init()  {
           ::init();
              add_action("search_room","search");
                }

        search_room() {
              write("You look around the sparse corridor and see nothing.\n");
	      say (this_player()->query_name() +" searches the area. \n");
              return 1;
                      }
