#include "/players/fakir/color.h"
inherit "obj/armor";
#define MAX_WEIGHT      6
int local_weight;


reset(arg) {
if(arg) return;
set_name("patchwork cloak");
set_alias("cloak");
set_short(RED+"P"+CYAN+"a"+BROWN+"t"+WHITE+"c"+YELLOW+"h"+GREEN+"w"+BLUE+"o"+RED+"r"+MAGENTA+"k"+OFF+" Cloak");
set_ac(2);
set_type("misc"); 
set_weight(2);
set_value(16745);
local_weight = 0; } 

long() {
    write("This patchwork cloak is called such due to the many scraps of fabric\n"+
          "which have been sewn together in overlapping layers and colors. Even\n"+
          "though it appears to be a simple cloak, it has hidden pockets and the\n"+
          "cloth has been magically enhanced to provide exceptional protection\n"+
          "to he who wears it.\n");
    if (first_inventory(this_object()))
        write("There is something in it.\n");
    else
        write("You can put things in it.\n");
}


add_weight(w) {
    if (local_weight + w > MAX_WEIGHT)
        return 0;
    local_weight += w;
    return 1;
}

can_put_and_get() { return 1; }



prevent_insert() {
    if (local_weight > 0) {
        write("You can't when there are things in the pocket.\n");
        return 1;
    }
    return 0;
}



