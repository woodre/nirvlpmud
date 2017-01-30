#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_operres.c"),
	this_object());  }

set_light(1);

long_desc =
     "                    O P E R A T I O N S    R E S E A R C H\n"+
     "\nLa ricerca operativa e' lo studio    The operations research is the \n"+
     "matematico di sistemi con ingressi   mathematical study of systems\n"+
     "ed uscite dal punto di vista della   with input and output from the\n"+
     "ottimizzazione soggetta a vincoli    viewpoint of the optimization\n"+
     "assegnati.                           subjected to given constraints.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Operations Research";}  