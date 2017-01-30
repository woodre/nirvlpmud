#include "/players/pavlik/closed/colors.h"
#define TY capitalize(typ)
inherit "obj/weapon.c";

string typ;

reset(arg){
  int ran;
  ::reset(arg);
  if (arg) return;
  ran = random(4);
  if(ran==0) typ = "sword";
  if(ran==1) typ = "trident";
  if(ran==2) typ = "spear";
  if(ran==3) typ = "axe";
  set_name(HIR+"Fire"+NORM+" "+TY);
  set_alias("fire_weapon");
  set_alt_name("fire "+typ);
  set_short("A "+HIR+"Fire"+NORM+" "+TY);
  set_long(
	"This weapon is used by the fiery Salamander.  It is a little\n"+
	"smaller than most of its kind, but don't let that fool you.\n");
  set_type(typ);
  set_class(15);
  set_weight(1);
  set_value(450);
  if(typ == "sword" || typ == "axe") {
    message_hit = ({
    "HACKED", " into tiny pieces",
    "SLICED", " neatly",
    "hacked vigirously at", "",
    "chopped", " with a deft swing",
    "spliced", " neatly",
    "struck", " a solid blow",
    "shaved", "",
    });
  }
  if(typ == "trident" || typ == "spear") {
    message_hit = ({
    "BURIED the weapon into", "",
    "gouged a large chunk of flesh from", "",
    "stabbed", " in the stomach",
    "jabbed deeply into ", "",
    "punctured", "",
    "sliced", " with a deft swing",
    "poked", "",
    });
  }
  set_save_flag(0);
}

