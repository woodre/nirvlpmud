     /*  Engine Room. This area is big and entertaining. The big bad boys are here */
     /*  Polymorph and Inquisitor are vile vile opponents.			   */

inherit "room/room.c";
int searched;

reset(arg)  {
   if(arg)
      return ;

   if(!present("inquisitor")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/inquisitor.c"),this_object()); }      
   if(!present("polymorph")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/polymorph.c"),this_object()); }      

   set_light(1);
   short_desc = "Starbug Engine Room";
   long_desc = 
"Starbug's Engine room appears to be massive. Large antimatter drives\n\
provided by some twisted rogue simulants to make the 'bug a more sporting\n\
challenge. Conduits and vast sections of pipes link things around the room. \n\
There is a large open area that someone has set a big throne in. You are \n\
getting a seriously bad vibe here.  \n";

    items=({
      "drives","Quark level antimatter drives capable of great speed and handling",
      "conduits","Conduits keep the wiring up and out of the way",
      "pipes","These channel all sorts of materials from water, to waste, to air",
      "area","An open space that has a throne centered in it",
      "throne","The massive and creapy throne of someone able to back their ego"
          });

    dest_dir = ({
        "/players/wren/Area/starbug/rooms/deck","deck",
        "/players/wren/Area/starbug/rooms/cargo","cargo"
               });
searched = 0;
}

   init() {
      ::init();
        add_action("duct","duct");
        add_action("search_room","search");
           }

   duct() {
        this_player()->move_player("into the duct#/players/wren/Area/starbug/rooms/duct2");
        return 1;
           }

  search_room() {
       if(searched == 0) {
           write("Something moves as you search...it jumps at you!");
           say(this_player()->query_name() + "searches the area. \n");
           move_object(clone_object("/players/wren/Area/starbug/posse/polymorph.c"),this_object()); 
              if(environment())
  	      tell_room(environment(),"A second Polymorph was lurking in the machinery.\n");
           searched = 1;
           return 1;
                         }
        else {
           write("You find a duct above that you may be able to access. \n");
	   write("       Just 'duct' to enter. \n");
           say (this_player()->query_name() +" searches the area. \n");
           return 1;
             }
    }

	/* Inquisitor with guantlet WC16 special 21 timed and delayed bonus  */
        /* search reveals Polymorph, need several odd forms, biggest mob here*/
        /* Can spawn twice, like the show mentions "contents two" NOT A BUG! */
        /* So please don't be rewarding Vodka for noticing it can be repoped */
