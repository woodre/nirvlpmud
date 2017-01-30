#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_electrotec.c"),
	this_object());  }

set_light(1);

long_desc =
     "                  E L E C T R O T E C H N I C S \n"+
     "\nL'elettrotecnica e' la scienza     The electrotechnics is the science\n"+
     "dei metodi, processi, ed opera-    of the methods, processes and ope-\n"+
     "zioni attraverso cui l'elettri-    rations by which the electricity is\n"+
     "cita' e' applicata nella pratica   applied in the industrial activities.\n"+
     "industriale.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Electrotechnics";}  