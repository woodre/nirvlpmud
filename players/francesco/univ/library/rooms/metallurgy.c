#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_metal.c"),
	this_object());  }

set_light(1);

long_desc =
     "                           M E T A L L U R G Y \n"+
     "\nLa metallurgia e' la scienza e       The metallurgy is the science and\n"+
     "la tecnologia di metalli e leghe.    the technology of metals and alloys.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Metallurgy";}  