inherit "obj/weapon";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_id("sword");
set_weapon_type("sword");
set_level(25);
set_short("The Z Sword");
set_long(
"This is the illusive Z Sword, found only on the Grand Kai's home planet.\n");
}
