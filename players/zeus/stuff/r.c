inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_short("A pill");
  set_long(
"This is a small white pill.  The shell is made of a solid white plastic.\n"+
"Written in black lettering on the pill are the letters:  ZP1\n");
  set_weight(1);
  set_value(0);
}

id(str){ return str == "pill" || str == "kill_check_object"; }

  init(){
  ::init();
  add_action("swallow_pill", "swallow");
}

swallow_pill()
{

write_file("/players/zeus/test",
"\n"+BOLD+BLK+
"          Established May 9th 1999\n"+NORM+
HIW+"--- -- -+- -- ---        -+-        --- -- -+- -- ---\n"+NORM+
"\n"+
RED+" *"+NORM+HIW+" The Fallen Lands\n"+NORM+
"     This large area is home to the Gurthers and those few remaining\n"+
"     members of the Fallen guild.  Be very careful though, this area is\n"+
"     not intended for young adventurers as it is plagued with danger.\n"+
"\n"+
RED+" *"+NORM+HIW+" The Museum of Legendary Warriors\n"+NORM+
"     Challenge the legendary warriors of history.  A safe area unless\n"+
"     you go into the arena, this area provides a challenge for even the\n"+
"     most skilled players.\n"+
"\n"+
RED+" *"+NORM+HIW+" Inculta Creperum\n"+NORM+
"     This area features numerous mid-level monsters as well as some very\n"+
"     large ones.  Be wary of what you attack and you will be fine.  Don't\n"+
"     forget your torch.\n"+
"\n"+
HIW+"--- -- -+- -- ---        -+-        --- -- -+- -- ---\n"+NORM+
"4w, 3n, 3w then north or south from the village green.\n"+
"\n");
}
