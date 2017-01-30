#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

id(str) { return str == "woo_obj" || str == "woo"; }
get() { return 1; }
drop() { return 1; }
init() { if(this_player()->query_real_name() != VITAL) destruct(this_object());
add_action("woo","woo");
}
woo(str) { return "/players/vital/closed/tool/wk/woo"->woo(str); }
short() { return "Woo woo"; }
