inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("bull");
set_short("Big bull");
set_long("The one and only bull of Lindendale.\n");
set_al(0);
set_level(4);
set_wc(8);
set_ac(4);
set_hp(60);
set_aggressive(0);
}
 
