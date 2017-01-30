#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("clerk2")) {
  move_object(clone_object("/players/francesco/univ/mob/clerk2.c"),
	this_object()); }

set_light(1);

short_desc = "Accounting office" ;
long_desc =
     "   In this room there is a computer, a small calculator, a\n"+
     "typewriter, a fax machine, a printer and a copier all aligned\n"+
     "on the side tables of the room.  There is also an ergonomic office\n"+
     "desk used by the clerk responsible for this office when she is not\n"+
     "busy somewhere else.\n";

items = ({
     "calculator","Hand held calculator, useful for making simple additions\n"+
                  "and multiplications",
     "typewriter","Needed when typing on special format sheets",
     "computer","In its hard drive there is the whole accounting of the Department",
     "fax","Plain paper fax machine",
     "copier","It has colater option so it can automatically\n"+
              "make several copies of the same report",
     "desk","An ample office desk, with some papers and a picture of a boy over it",
     "tables","Metallic tables with plastic cover",
     "printer","A colour laser printer",
    "picture","The boy represented is about 15 years old",
});

dest_dir = ({
   "/players/francesco/univ/rooms/dimec2.c","east",
});

}
