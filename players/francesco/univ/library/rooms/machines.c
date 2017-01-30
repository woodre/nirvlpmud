#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_machines.c"),
	this_object());  }

set_light(1);

long_desc =
     "                              M A C H I N E S\n"+
     "\nLe macchine sono una combinazione    The machines are a combination \n"+
     "di corpi rigidi e resistenti con     of rigid and resistant bodies\n"+
     "definiti movimenti e adatti  a       having definite motions and capable \n"+
     "compiere lavoro utile.               of performing useful work.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Machines";}  