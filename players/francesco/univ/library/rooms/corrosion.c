#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_corr.c"),
	this_object());  }

set_light(1);

long_desc =
     "                              C O R R O S I O N \n"+
     "\nLa corrosione e' la graduale distru-   The corrosion is the gradual\n"+
     "zione di un metallo o di una lega a    destruction of a metal or alloy due \n"+
     "causa di processi chimici o elettro-   to chenical or electrochemical pro-\n"+
     "chimici connessi con fattori           cesses connected with environmental\n"+
     "ambientali.                            factors.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Corrosion";}  
