#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_physics.c"),
	this_object());  }

set_light(1);

long_desc =
     "                              P H Y S I C S \n"+
     "\nLa fisica e' lo studio di quegli    The phisics is the study of those\n"+
     "aspetti della natura che possono    aspects of the nature which can be\n"+
     "essere capiti in modo fondamentale  undestood in a fundamental way in\n"+
     "in termini di principi elementari   terms of elementary principles and\n"+
     "e di leggi.                         laws.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Phisics";}  