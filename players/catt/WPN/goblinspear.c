inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("wicked spear");
set_alias("spear");
set_short("a wicked spear");
set_long(
"a wicked spear used by goblin sentries to guard their mountain.\n");
/* Replaced value 700 with 50 -Snow */
set_value(50);
set_weight(3);
set_class(10);
}
