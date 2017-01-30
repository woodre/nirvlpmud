#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_mechmat.c"),
	this_object());  }

set_light(1);

long_desc =
     "            M E C H A N I C S    O F    M A T E R I A L S \n"+
     "\nLa meccanica dei materiali studia     The mechanics of materials studies\n"+
     "la resistenza dei materiali e delle   the resistance of the materials and \n"+
     "strutture sotto l'azione di forze     of the structures under the action \n"+
     "esterne.                              of external forces.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Mechanics of Materials";}  