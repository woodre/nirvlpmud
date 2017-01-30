#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_calc.c"),
	this_object());  }

set_light(1);

long_desc =
     "                              C A L C U L U S\n"+
     "\nL'analisi matematica e' quella parte  The calculus is the branch of ma-\n"+
     "della matematica che studia le deri-  thematics dealing with the derivati-\n"+
     "vate, gli integrali e argomenti       ves and the integrals and related\n"+
     "collegati.                            topics.\n \n";
}

realm(){ return "NT"; }

short() {return ""+"Calculus";}  