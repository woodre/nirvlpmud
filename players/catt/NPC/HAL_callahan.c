inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
::reset(arg);
if(arg) return;
set_name("callahan");
set_alias("callahan");
set_short("Callahan, the owner and bartender");
set_long("He is a stern looking man, but gentle in the big brutish way\n");
set_level(15);
set_hp(5000);
set_wc(10);
set_ac(15);
}
