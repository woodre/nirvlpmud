inherit "obj/weapon.c";

reset (arg) {
::reset (arg);
if (arg) return;

set_name ("hammer");
set_alias ("huge hammer");
set_short ("Huge Hammer of Blacksmithes");
set_long ("It's very huge hammer. Gdemia Blacksmithes use it to make\n"+
	   "their fine swords.\n");
set_class (14);
/* WEIGHT should be like a real hammer... HEAVY  -mizan */
set_weight (3);
set_value (500);
}
