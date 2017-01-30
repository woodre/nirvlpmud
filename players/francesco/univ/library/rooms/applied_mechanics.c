#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_appmech.c"),
	this_object());  }

set_light(1);

long_desc =
     "                  A P P L I E D   M E C H A N I C S \n"+
     "\nLa meccanica applicata analizza     Applied mechanics performs the ana-\n"+
     "movimenti e le forze necessarie     lyses of the movements and of the forces\n"+
     "per trasmettere il moto da una      needed to transmit the motions from one\n"+
     "parte all'altra di una macchina.    part to another of a machine.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Applied mechanics";}  