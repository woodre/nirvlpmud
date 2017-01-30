inherit "obj/weapon.c";

reset (arg) {
::reset (arg);
if (arg) return;

set_name ("sword");
set_alias ("Olgyo sword");
set_short ("Olgyo sword");
set_long ("It's primitive Olgyo sword.\n");
set_class (12);
set_weight (1);
set_value (500);
}
