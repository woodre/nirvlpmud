/* A do-nothing reward for completing the Elemental Test */
#include "/players/snow/closed/color.h"

id(str) { return str == "elemental aura"; }
get() { return 1; }
drop() { return 1; }
can_put_and_get() { return 0; }
query_auto_load() { return "/players/snow/closed/test/aura.c:"; }
extra_look() { return RED+"~ "+OFF+BLUE+"Ele"+OFF+GREEN+"men"+OFF+BOLD+"tal Wa"+OFF+
                      GREEN+"rri"+OFF+BLUE+"or"+OFF+RED+" ~"+OFF; }

init() {
  add_action("elemental_title","elemental");
}

elemental_title() {
  if(!environment()) return;
  if(environment()->query_npc()) return;
  if(!living(environment())) return;
  environment()->set_title("the "+RED+"~ "+OFF+BLUE+"Ele"+OFF+GREEN+"men"+
    OFF+BOLD+"tal Wa"+OFF+GREEN+"rri"+OFF+BLUE+"or"+OFF+RED+" ~"+OFF);
  tell_object(environment(), "Your elemental title is set.\n");
  return 1; }
