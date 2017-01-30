	/* Cargo Bay. Funny area, probably should have some stuff in the boxes.            */
	/* We'll put some of the other mobs that are interesting but don't necessarily fit */
        /* Rimmer3, Mr.Flibble...Psiren, scutters, original Kochanski		           */

inherit "room/room";
reset(arg)  {
   if(arg) 
      return ;

   if(!present("kochanski2")) {
      move_object(clone_object("/players/wren/Area/starbug/posse/kochanski2.c"),this_object()); }
   if(!present("scutter2")) {
      move_object(clone_object("/players/wren/Area/starbug/posse/scutter2.c"),this_object()); }
   if(!present("scutter1")) {
      move_object(clone_object("/players/wren/Area/starbug/posse/scutter1.c"),this_object()); }
   if(!present("psiren")) {
      move_object(clone_object("/players/wren/Area/starbug/posse/psiren.c"),this_object()); }
   if(!present("rimmer")) {
      move_object(clone_object("/players/wren/Area/starbug/posse/rimmer3.c"),this_object()); }
 

   set_light(1);
   short_desc = "Starbug's Cargo Bay";
   long_desc = 
"This is the cargo bay. A lot of strange things have happened here. One time \n\
Holly detected an unidentified life form, it turned out to be one of Lister's \n\
sweat socks. Crates and supplies are stacked here. It all varies from useful \n\
to just novelties. Lots and lots of Indian food and beer. \n";

     items =({
          "crates","Crates full of strange and varied things. An old battery crate is mildly interesting",
	  "crate","The battery brand was Ouroboros (tm)",
	  "supplies","Ropes, netting, chains, and spare parts are scattered around the crates",
	  "food","Curries and pompadoms",
	  "beer","Lager, lots and lots of it",
          "rope","Coils of rope that you don't need",
          "netting","It looks like old fishing net, or perhaps for holding down cargo",
          "chains","Chains to fasten down large items",
          "parts","Spare bits and bobbles that ended up here",
          "curries","Some of that Indian cuisine that Lister is so fond of",
          "poppadoms","Some of that Indian cuisine that Lister is so fond of"
            });

     dest_dir = ({
           "/players/wren/Area/starbug/rooms/engine","engine"
                });
}

     init() {
       ::init();
          add_action("search_room","search");
            }

     search_room() {
           write("You rattle about the crates and things and find nothing portable. \n");
           say(this_player()->query_name() +" searches the area. \n");
           return 1;
                   }


	/* Rimmer3 : Red Gingham dress, Mr. Flibble (WC19)                           */
        /* Psiren : plastic straw "appears as pete transky's sister, vending machine */
	/* Scutter: Bob,cowboy hat, cap pistol					     */
	/* Scutter2: Karl,indian feathers, mini tomahawk			     */
	/* Original Kochanski: boggles about what happened to her		     */
          
