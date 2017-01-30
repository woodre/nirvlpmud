#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_fluid.c"),
	this_object());  }

set_light(1);

long_desc =
     "                      F L U I D    D Y N A M I C S\n"+
     "\nLa fluidodinamica studia il moto    The fluid dynamics studies the \n"+
     "dei fluidi sia liquidi che gassosi  motions of the fluids both liquid\n"+
     "e le forze che scambiano con        and gaseous and the forces that they\n"+
     "l'ambiente circostante.             they exchange with the surrounding\n"+
     "                                    environment.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Fluid dynamics";}  