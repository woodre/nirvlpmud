#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("clerk1")) {
  move_object(clone_object("/players/francesco/univ/mob/clerk1.c"),
	this_object()); }
if (!present("clerk1 1")) {
  move_object(clone_object("/players/francesco/univ/mob/clerk4.c"),
	this_object()); }

set_light(1);

short_desc = "Study plans office" ;
long_desc =
     "    In this well lit and ordered room it is possible to inquire\n"+
     "of the clerks about the study plans.  The students usually come\n"+
     "here to get a flier they will examine in depth so they could then\n"+
     "decide on their own academic career.\n",
items = ({
   "flier","A small brochure with the info about the courses taught in\n"+
           "the Department of Mechanical Engineering\n",

});


dest_dir = ({
   "/players/francesco/univ/rooms/dimec2.c","west",
});

}

init() {
     ::init();
     add_action("inquire","inquire");
       }
inquire(str) {
      object dummy;     
      if (str!= "of katya")
         {
          write("Inquire of whom?\n");
          return 1;
         }
      if(!present("katya",this_object()))
             {
            write("The clerk is momentarily absent, please come back later.\n");
            return 1;    
             }
     write("The clerk searchs within a shelf and hands you a flier.\n");
     dummy = clone_object("/players/francesco/univ/items/flier.c");
     move_object(dummy,this_player());
     return 1;
 }
   
