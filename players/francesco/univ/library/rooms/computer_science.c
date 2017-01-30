#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_comp.c"),
	this_object());  }

set_light(1);

long_desc =
     "                          C O M P U T E R   S C I E N C E\n"+
     "\nL'informatica e' lo studio della   The computer science is the study of\n"+
     "teoria e delle applicazioni dei    the theory and the application of\n"+
     "calcolatori elettronici per        computers for the acquisition, the\n"+
     "l'acquisizione, l'analisi e        analysis and the presentation of \n"+
     "la presentazione di dati.          data.\\n";                           
}

realm(){ return "NT"; }

short() {return ""+"Computer science";}  
