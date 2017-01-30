inherit "obj/weapon.c";

reset (arg) {
::reset (arg);
if (arg) return;

set_name ("net");
set_alias ("Olgyo net");
set_short ("Olgyo net");
set_long ("This is a fishman net. You can catch a fish with it.\n");
set_class (8);
set_weight (1);
set_value (100);
}
