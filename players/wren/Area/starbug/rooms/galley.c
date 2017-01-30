	/* Galley. This is the kitchen area. Probably should borrow the cabinet */
        /* trick from Verte and put things on shelves. Hidden exit to the ducts */
	/* here. Second set of guys, from the polymorph episode.		*/
        
inherit "room/room";

reset(arg) {

     if(arg)
         return ;

    if(!present("rimmer")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/rimmer2.c"),this_object()); }      
    if(!present("cat")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/cat2.c"),this_object()); }      
    if(!present("lister")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/lister2.c"),this_object()); }      
    if(!present("kryten")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/kryten2.c"),this_object()); }      

     set_light(1);
     short_desc = "Starbug Galley";
     long_desc = 
"Starbug's Galley. This is Kryten's domain and he rules it with an \n\
authoritative dustwand. He does laundry, cooks, and cleans up in this \n\
room. Dirty pans, skillets, and beer mugs fill the sink. There is a  \n\
peculiar smell coming from the fridge. The crew isn't looking quite \n\
like themselves. Something must have occured to them recently to alter\n\
their behaviors. \n";

      items=({
           "pans","A pile of pans caked with nasty crusty food? maybe it was once",
	   "skillets","Skillets coated in grease and grime",
	   "mugs","Mugs that once housed lager now sit with cigar dibs in them",
	   "sink","The sink is disgusting and full of things that need to be washed",
	   "fridge","The fridge stink assails you, are those a pair of trainers?",
	   "duct","A duct into the ships ventilation system its big enough to enter",
           "dustwand","Kryten's dust wand. Useful only if you want to kill dustbunnies",
           "food","It once may have been edible but you wouldn't wan to try now",
           "cigar","Cigar remains",
           "dibs","The burnt out remains of cigars"
             });   

      dest_dir = ({
          "/players/wren/Area/starbug/rooms/deck","deck"
                 });
}
      init() {
         ::init();
           add_action("duct","duct");
           add_action("search_room","search");
	   add_action("smell","smell");
             }


      duct()  {
          this_player()->move_player("into the duct#/players/wren/Area/starbug/rooms/duct");
          return 1;
              }

      search_room() {
          write("You find a duct in the ceiling that you could probably access.\n");
	  write("              Just 'duct' to enter. \n");
          say (this_player()->query_name()+" searches the area. \n");
          return 1;
                }

      smell()  {
          write("You smell something horribly funky from the area around the fridge.\n");
          say (this_player()->query_name() +"'s nose wrinkles in disgust at something.\n");
          return 1;
               }


	/* Kryton2(guiltless)"Just call me badass""Maybe if i feed it you guys"   */
	/* Lister2(fearless)"Let's go to the weapon's locker, get a nuke, strap   */
	/*    it to me forehead and I'll nut the sucker to oblivion"(BallbatWC18) */
	/* Cat2(vanityless)"Don't mind me I'm nobody" (coat smelling of yak urine)*/
	/* Rimmer2(angerless)"We'll start a leaflet campaign""C.L.I.T.O.R.I.S."   */
	/* search reveals:duct entrance						  */

