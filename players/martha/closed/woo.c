#include "/players/vital/closed/headers/vital.h"

id(str) { return str == "woo_obj" || str == "woo"; }
get() { return 1; }
drop() { return 1; }
init()
{
    if(this_player()->query_real_name() != "martha") destruct(this_object());
    add_action("woo_function","woo");
}
woo_function(str) { return "/players/vital/closed/tool/wk/_woo"->main(str); }
short() { return "Woo woo"; }
long()
{
    return "/players/vital/closed/tool/wk/_woo"->main("help");
}