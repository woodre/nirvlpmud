	/* Airlock. Starting room for area. Have BlueMidget dock and drop them off. */
        /* Right off, meet two of the odder forms. Not much gear but full of lines  */


inherit "room/room";

reset(arg) {
    if(arg)
       return ;

    if(!present("ace")) {
           move_object(clone_object("/players/wren/Area/starbug/posse/ace.c"),this_object()); }
    if(!present("dwayne")) {
           move_object(clone_object("/players/wren/Area/starbug/posse/dwayne.c"),this_object()); }

    set_light(1);
    short_desc = "Starbug Airlock";
    long_desc = 
"Starbug's Airlock. Through these reinforced doors have passed \n\
some of the universe's strangest beings, which includes this crew. \n\
The blast doors are solid, with scorch marks from weapon fire and \n\
meteorite impact. A video intercom is mounted here so the crew can \n\
communicate with those in the entry. A complicated keypad grants \n\
access but a good swift kick will probably work as well. \n";

     items=({
             "doors","Heavy blast doors to keep space out and air in",
             "marks","There are some black streaks and large dents",
             "intercom","A simple camera and monitor to talk with those inside",
             "keypad","A crypto pad to keep unwanteds out. Doesn't look secure",
             "streaks","Soot marks where energy weapons have vaporized paint",
             "dents","Damage from meteorite impacts, this ship has been run hard",
             "camera","A standard video device in a protected case",
             "monitor","A small tv monitor to show the face of the person on the other side of door"
            });
     dest_dir = ({
         "/players/wren/Area/entrance","megalith",
         "/players/wren/Area/starbug/rooms/deck","deck"
                });   
}
     init() {
        ::init();
           add_action("search_room","search");
           add_action("swift_kick","kick");
	   add_action("credits","credits");
            }

     search_room() {
          write("You prod about the room but don't find anything interesting.\n");
	  write("An odd urge to 'credits' catches you though.\n");
          say(this_player()->query_name() +" searches the area. \n");
          return 1;
                   }

     swift_kick()  {
          write("You kick above the keypad and the interior door opens \n");
	  say (this_player()->query_name() +" kicks the panel to open the door \n");
          return 1;
                   }

     credits() {
	  write("You recognize the hand of Wren in the creation of this area. \n");
	  write("He thinks you should know the origins of this place. For more \n");
	  write("info on this great show check out --> www.reddwarf.co.uk <-- \n");
	  write("you'll be glad you did ;) \n");
	  write("	Enjoy!						-WREN \n");
	  return 1;
               }


	/* Ace Rimmer "Smoke me a kipper, I'll be back for breakfast"     */
	/*    have room emotes off him saying "someone swoons-what a guy" */
        /* Dwayne Dibbly "what a guy, i'm such a dork, you never know.."  */
        /*    "why suck my thermos" carries: thermos, lunchbox            */
