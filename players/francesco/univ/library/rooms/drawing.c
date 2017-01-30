#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_draw.c"),
	this_object());  }

set_light(1);

long_desc =
     "                             D R A W I N G \n"+
     "\nIl disegno meccanico e' la rappre-   Mechanical drawing is the represen-\n"+
     "sentazione di una forma o di una     tation of a form or a figure in line, \n"+
     "figura in linee, con l'aiuto di      with the aid of tools such as rulers\n"+
     "mezzi quali righe e squadre.         and squares.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Mechanical drawing";}  
