inherit "obj/weapon.c";

reset (arg) {
::reset (arg);
if (arg) return;

set_name ("longsword");
set_alias ("sword");
set_short ("Olgyo longsword");
set_long ("It's very good sharp longsword made by Gdemia.\n");
set_class (16);
set_weight (1);
set_value (800);
}
