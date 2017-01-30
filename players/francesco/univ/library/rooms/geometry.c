#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_geometry.c"),
	this_object());  }

set_light(1);

long_desc =
     "                             G E O M E T R Y\n"+
     "\nLa geometria e' lo studio delle     The geometry is the study of the \n"+
     "delle forme e delle dimensioni.     shapes and of the size.  It can be\n"+
     "Puo' essere effettuato attraverso   performed through the use of equa-\n"+
     "equazioni e formule.                tions and formulas.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Geometry";}  