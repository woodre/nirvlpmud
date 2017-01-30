#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_engines.c"),
	this_object());  }

set_light(1);

long_desc =
     "                              E N G I N E S \n"+
     "\nIl motore e' una macchina in cui la   The engine is a machine in which \n"+
     "potenza e' applicata per compiere     the power is applied to do work by\n"+
     "lavoro attraverso la conversione di   the conversion of various forms of\n"+
     "varie forme di energia in forze e     energy into mechanical force and \n"+
     "movimenti.                            and motions.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Engines";}  