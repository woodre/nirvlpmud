inherit "obj/monster.c";
object weapon;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("giant");
set_alias("desert giant");
set_short("A Desert Giant");
set_long("The weathered and craggy face of the giant is scored with wrinkles.\n"+  
         "Because of his dark hair and swarthy skin you notice his blue eyes.\n"+
         "He has to be some thing like 17' tall and weighs about 7,000 pounds.\n");
set_al(0);
set_level(16);
set_wc(22);
set_ac(13);
set_hp(400);
set_aggressive(1);
if(!present("spear")) {
weapon = clone_object("players/mouzar/castle/weapons/gspear.c");
move_object(weapon,this_object());
}
}
 
