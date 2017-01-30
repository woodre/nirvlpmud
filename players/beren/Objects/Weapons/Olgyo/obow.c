inherit "obj/weapon.c";

reset (arg) {
::reset (arg);
if (arg) return;

set_name ("bow");
set_alias ("Olgyo bow");
set_short ("Olgyo bow");
set_long ("This is a weapon of Olgyo hunters.\n");
set_class (16);
set_weight (2);
/* Changed value from 1000 due to level 16 monster with 200coin armor as well. -Snow 3/00 */
set_value (random(400)+520);
}
