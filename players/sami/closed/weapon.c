#include "/ansi.h"
#define USER environment()
#define TP this_player()
#define POS query_possessive()
#define OBJ query_objective()
#define PRO query_pronoun()
inherit "players/maledicta/weapon/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("gunblade");
set_alias("blade");
set_short(""+HIK+"G"+NORM+CYAN+"un"+HIK+"B"+NORM+CYAN+"lade"+NORM+"");
set_long(
"Diamond encrusted wire, bladed whip heads, leather wrapped bone handle. Need I say more?\n");
set_hit_func(this_object());
set_type("sword");

set_class(21);
set_weight(3);
set_value(2000);
set_two_handed_wep(1);
add_special_fun("/players/sami/closed/speed.c");
add_special_fun("/players/sami/closed/hps.c");
add_special_fun("/players/sami/closed/det.c");
add_special_fun("/players/sami/closed/poison.c");
add_special_fun("/players/sami/closed/sps.c");

message_hit = ({
  HIY+HBRED+"DOMINATED"+NORM," leaving only a bloody, squirming mess on the floor",
  HIR+"showed"+NORM, " what it's like to be OWNED",
  RED+"BRUTALIZED"+NORM, " with a deadly combination of attacks",
  HIW+"thrashed"+NORM, " severely, causing great pain",
  HIW+"wounded"+NORM, " leaving deep gashes",
  "sliced", " open with a quick snap of the whip",
  "nicked", " with the tip of the whip"
  });
  }