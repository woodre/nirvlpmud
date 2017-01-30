#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ITEM;
int fuel;
reset(arg) {
    if(arg) return;
    fuel = 240;
    set_id("gas can");
    set_short("A can of gasoline");
    set_long(
"This is a can of gasoline\n"
+"You can 'check' how much gas is left inside the gas can.\n");
set_weight(2);
    set_value(500 + (fuel * 5)); }

init() {
    ::init();
    add_action("check_gas","check");
}

id(str) {
        return str == "gas can" || str == "gas" || str == "gas_can" || str == "can" || str == "gasoline" || str == "can of gasoline"; }

add_fuel(fu) { (fuel = (fuel + fu)); set_value(500+(fuel *5)); }
query_fuel() { return fuel; }

check_gas() {
    write("You peer into the gasoline can and determine that you have "+query_fuel()+" ounces of gas left to use.\n");
    say(TPN+" peers into the gasoline can.\n");
    return 1; }

query_save_flag() { return 1; }

