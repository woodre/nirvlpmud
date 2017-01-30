inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_short(
"GOTO NIGHTSHADES REALL KOOL AREA! LOOK AT THIS NOTICE!");
set_long
("To get to my area go south of shop, down, and enter crack!!\n"+
"To get to my newbie area go south of shop, down, enter crack, 2s, 4e\n"+
"and look at the rock :)\n");
set_weight(50);
set_alias("notice");
set_value(1);
}
