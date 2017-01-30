#include <ansi.h>
inherit "obj/treasure";
#define ME capitalize(me->query_name())
#define RABMAS "/players/pavlik/closed/stuff/rabies-master.c"

int shush;

reset(arg) {
  if(arg) return;
  set_short("rabies");
  set_alias("rabies");
  set_long(
	"You are infected with "+YEL+"rabies!"+NORM+"\n"+
	"type '"+GRN+"rabid help"+NORM+"' to find out how this affects you.\n");
  set_weight(0);
  set_value(0);
  shush = 0;
  RABMAS->add_rabid(this_object());
}

id(str){ return str == "rabies" || str == "disease" || str == "virus" || str == "rab_obj";  }

short() { return; }
get() { return 1; }
drop() { return 1; }
set_shush(sh){ shush = sh; }
query_shush(){ return shush; }

query_auto_load(){ return "players/pavlik/closed/stuff/rabies.c:"; }

init() {
  ::init();
  if(this_player()->query_guild_name() == "vampire") add_action("rabies", "rbite");
  else add_action("rabies","bite");
  add_action("rabies","rabid");
  add_action("rabies","shush");
  add_action("rabies","CURE");
  add_action("rabies","rchat");
}

rabies(str){
  RABMAS->rabies(str);
  return 1;
}

