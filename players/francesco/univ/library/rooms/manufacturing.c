#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_manufac.c"),
	this_object());  }

set_light(1);

long_desc =
     "                       M A N U F A C T U R I N G \n"+
     "\nLa tecnologia meccanica studia      Manufacturing engineering studies\n"+
     "i processi ed i sistemi di produ-   the production processes and systems\n"+
     "zione per l'ottenimento di pro-     for obtaining rough, semifinished or\n"+
     "dotti e componenti grezzi, semi-    final products or components.\n"+
     "lavorati o finiti.                  \n\n";
}

realm(){ return "NT"; }

short() {return ""+"Manufacturing";}  