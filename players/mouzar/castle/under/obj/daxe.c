inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_hands(2);
set_name("axe");
set_alias("battleaxe");
set_short("Dwarven Battleaxe");
set_long(
"A heavy battleaxe made to kill drow and other thing of the dark.\n");
set_value(1000);
set_weight(4);
set_class(17);
}
