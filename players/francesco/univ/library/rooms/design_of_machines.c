#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_des_mach.c"),
	this_object());  }

set_light(1);

long_desc =
     "                     D E S I G N    O F    M A C H I N E S  \n"+
     "\nIl progetto di macchine e' l'atto di     The design of machines is the act\n"+
     "pensare e pianificare la struttura       of conceiving and planning the\n"+
     "e le caratteristiche di un componente    structure and the characteristics\n"+
     "meccanico per ottenere determinate       of a mechanical component in order\n"+
     "prestazioni.                             to achieve aforeseen performances.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Design of machines";}  
