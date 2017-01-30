#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_production.c"),
	this_object());  }

set_light(1);

long_desc =
     "                     P R O D U C T I O N    S Y S T E M S \n"+
     "\nLo studio dei sistemi di produzione    The study of the production systems\n"+
     "e' un aspetto avanzato della  tecno-   is an advanced aspect of the manu-\n"+
     "logia meccanica.  Non analizza sola-   facturing engineering.  Not only \n"+
     "mente i processi ma soprattutto la     it analyses the single processes\n"+
     "loro integrazione all'interno della    but mainly their integration\n"+
     "fabbrica                               within the industry.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Production Systems";}  