#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_thermo.c"),
	this_object());  }

set_light(1);

long_desc =
     "                        T H E R M O D Y N A M I C S\n"+
     "\nLa termodinamica e' la branca della    The thermodynamics is the branch\n"+
     "fisica che analizza le proprieta'      of the physics that analyses those\n"+
     "della materia connesse con le varia-   properties of the matter connected\n"+
     "zioni di temperatura e la conversione  to changes of temperature and to the\n"+     
     "di energia da una forma all'altra.     conversion of energy from one form\n"+
     "                                       to another.\n\n";
  
}

realm(){ return "NT"; }

short() {return ""+"Thermodynamics";}  