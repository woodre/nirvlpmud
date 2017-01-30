#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_manag.c"),
	this_object());  }

set_light(1);

long_desc =
     "                              M A N A G E M E N T \n"+
     "\nLa gestione industriale si interessa    The management engineering is\n"+
     "della progettazione, dello sviluppo     concerned with the design, impro-\n"+
     "e dell'installazione di sistemi         vement and installation of inte-\n"+
     "integrati di personale, materiali ed    grated systems of personnel,\n"+ 
     "attrezzature.                           materials and equipments.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Management";}  