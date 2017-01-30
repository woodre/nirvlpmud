#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ARMOUR;
reset(arg) {
    if(arg) return;
    set_id("silvery pendant");
    set_alias("pendant");
    set_short("A silvery pendant");
    set_long(
    "Sterling silver and gleaming, this pendant shines with the brightness\n"+
    "of a distant star.  There are several etchings on the side that you may\n"+
   "be able to read.\n");
    set_type("amulet");
    set_value(500);
    set_weight(1);
    set_ac(2); }

init() {
    ::init();
    add_action("read_me","read"); }

read_me(arg) {
    if(arg == "pendant" || arg == "etchings") {
        write(
" The pendant is engraved:\n\n"+
"        To Linda with love - Ashley\n"); return 1; } }


/* Changed from return 0 to return 1 - no save -Snow 3/00 */
query_save_flag() { return 1; }
