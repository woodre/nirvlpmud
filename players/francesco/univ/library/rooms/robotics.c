#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_robot.c"),
	this_object());  }

set_light(1);

long_desc =
     "                              R O B O T I C S\n"+
     "\nLa robotica applica le teorie      The robotics applies the theories\n"+
     "della automazione per realizzare   of the automation in order to build\n"+
     "macchine che possano essere        up devices that could be completely\n"+
     "completamente autocontrollate,     self-controlled either mechanically,\n"+
     "per via meccanica, elettronica     electronically or electrically.\n"+
     "o elettrica.\n\n";
}

realm(){ return "NT"; }

short() {return ""+"Robotics";}  