	/* Duct. Emohawk lair, smaller mean cousin of the big polymorph    */
	/* Miles and miles of confusing crawl space.  			   */

inherit "room/room";
int searched;

reset(arg) {
   if(arg) 
      return ;

   if(!present("emohawk")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/emohawk.c"),this_object()); }      
 
   set_light(1);
   short_desc = "A large duct";
   long_desc =
"This is a long section of Starbug's ducts. These are used to carry air \n\
to all the sections of the ship. You'll not want to linger too long though \n\
for the cleaning cycle is amazingly rough. The passage extends well into the \n\
distance. \n";

   items=({
       "duct","The duct go on forever. A near by section looks easily accessible",
       "down","A piece of grate has been battered free, you see the engine room below"
         });

   dest_dir=({
      "/players/wren/Area/starbug/rooms/engine","down",
      "/players/wren/Area/starbug/rooms/duct","duct"
            });
searched = 0;
}
   init()  {
      ::init();
      add_action("search_room","search");
           }

   search_room() {
      if(searched == 0) {
         write("You search around and find something in a dark corner.\n");
         say(this_player()->query_name() +" searches the area.\n");
         move_object(clone_object("/players/wren/Area/starbug/items/disks.c"),this_object()); 
         searched = 1;
         return 1;
                             }
      else { 
         write("You look around the sparse corridor and see nothing.\n");
         say (this_player()->query_name() +" searches the area. \n");
         return 1;
           }
      }
	/* Emohawk, several forms. Nothing too tough             */
	/* search reveals Red Dwarf memory disks, Lister's cigs  */
