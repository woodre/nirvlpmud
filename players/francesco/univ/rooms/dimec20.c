#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("fran")) {
  move_object(clone_object("/players/francesco/univ/mob/fran.c"),
	this_object());  }

set_light(1);

short_desc = "An office" ;
long_desc =
     
           "   A strange  feeling permeates  this office:  if you look at the type of\n"+
           "the items inside, then you can understand that the guy working here  must\n"+
           "be full  of interests  in  the engineering.  In fact, the books scattered\n"+
           "around are typically addressed  to such studies, with particular emphasis\n"+
           "to the manufacturing  and mechanical sciences.  Moreover,  it is possible\n"+
           "to see  some items useful  for experiencing  and studying those subjects:\n"+
           "micrometers,  cutting tools,  posters  depicting  industrial  activities,\n"+
           "and even a small demonstrative lathe.  On the other side,  there is a lot\n"+
           "of confusion  and the chaos is huge.  Piles of papers  lay on the top  of\n"+
           "the desk,  a printer is always running,  a crackling intercom to the labs\n"+
           "is insistently buzzing  and continuosly annoying you and if you just stay\n"+
           "for a couple of minutes here, then you can see hordes of students running\n"+
           "in and out of the office,  asking and questioning  about their thesis and\n"+
           "about their homeworks  and about their finals  and about their study plan\n"+
           "and about their graduation time and about.......  Oh my!!!  You wonder if\n"+
           "that guy  is somehow  crazy or  he could be  reliable enough  in order to\n"+
           "handle all these activities about his work.\n"+
           "\n",

items = ({
   

});

dest_dir = ({
   
   "/players/francesco/univ/rooms/dimec18.c","east",
   
   
});

}
