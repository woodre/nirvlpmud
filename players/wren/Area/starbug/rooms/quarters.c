	/* Quarters. These are the sleeping quarters on starbug. bunks and such */
	/* additional supporting characters. still midsized.			*/

inherit "room/room";

reset(arg) {
   if(arg)
      return ;

    if(!present("gelf")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/gelf.c"),this_object()); }      
     if(!present("gelf2")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/gelf2.c"),this_object()); }      
     if(!present("kochanski")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/kochanski.c"),this_object()); }      
 
     set_light(1);
     short_desc = "Starbug Crew Quarters";
     long_desc = 
"Crew quarters for the 'bug. The crew unwinds and sleeps in this room. \n\
Or tries to, the sewage cycler is malfunctioning loudly. Bits of dirty \n\
laundry, cigar dibs, and bits of food mingle with empty beer cans on   \n\
the floor. Posters for Zero G football plaster the wall opposite the \n\
bathroom fixtures. You are amazed more things aren't moving. \n"; 

  items=({     
     "laundry","Socks, multicolored stained shirts, and boxers mix with other debris",
     "cigar","The butts of several cigars are scattered under the bunks",
     "dibs","The butts of several cigars are scattered under the bunks",
     "food","Maybe at one time this was edible, now its almost gained sentience",
     "cans","Remnants of Lister's fondness for large amounts of lager",
     "posters","Jim Bexley Speed autographed, London Jets Zero G football, Cheerleaders of Zero G",
     "toilet","An AI toilet, it activates when called. Often when it isn't paying attention as well",
     "fixtures","A toilet, a shower, and a sink",
     "shower","A fully enclosed shower",
     "sink","A sink with a razor, cans of poorly labeled shaving cream and deoderant, salad tonges?",
     "floor","You are pretty sure this room should be labeled as hazardous waste and condemned",
     "socks","Old gym socks that are board stiff. They don't flex at all",
     "shirts","It is impossible to tell how many times these stained shirts were worn",
     "boxers","Old boxers with moth holes and worse. They can almost stand on their own",
     "stains","Mostly sweat,curry,motor oil,blood,lager,and everything else that misses Lister's mouth",
     "cycler","Waste water is filtered back to drinkable water, though it tastes like Dutch lager",
     "bunks","Standard space corp beds, hard metal over thin foam padding",
     "things","You can almost swear you saw something moving out of the corner of your eye"
     });

  dest_dir = ({
      "/players/wren/Area/starbug/rooms/deck","deck"
             });

}

     init() {
        ::init();
        add_action("search_room","search");
	add_action("crap","crap");
            }

     search_room() {
           write("You search the room but don't find anything that doesn't turn your stomach.");
	   say(this_player()->query_name() +" searches the area. \n");
           return 1;
                   }
     crap() {
            write("You mumble crap and the toilet spins around, you tell it not now, it apologizes and goes away\n");
	    return 1;
            }



	/* Talkie Toaster, noisy item or monster "Would you like some toast?" I toast  */
  	/*     therefore i am".	make him worth little, maybe smash able for xtra value */
	/* Gelf1-Kinetuwaseues(sp)tribe chief, gonna trade OG unit for Lister.has unit */
	/* Gelf2-Hackachahhca(sp)daughter, lister's bride..ugly with capital Ugh. has  */
	/*     wedding veil, flowers.						       */
	/* Kochanski "screlunkle, retut, hununga, no glonbkl" "i would kill for cottage*/
	/*     cheese with pinapple chunks in"  carries cottage cheese		       */
