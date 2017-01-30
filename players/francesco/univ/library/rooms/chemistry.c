#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_chemistry.c"),
	this_object());  }

set_light(1);

long_desc =
     "                            C H E M I S T R Y\n"+
     "\nLa chimica e' la scienza che studia   The chemistry is the science that\n"+
     "la composizione, le traformazioni,    studies the composition, the trans-\n"+
     "la struttura e le proprieta' della    formations, the structure and the\n"+
     "materia, e le corrispondenti          properties of the matter, and the\n"+
     "variazioni di energia.                accompanying energy changes.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Chemistry";}  