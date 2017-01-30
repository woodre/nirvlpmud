inherit "obj/weapon.c";

reset (arg) {
::reset (arg);
if (arg) return;

set_name ("cudgel");
set_alias ("great cudgel");
set_short ("Cudgel of Zgama");
set_long ("It's very big cudgel. Smash the heads with it!\n");
set_class (18);
/* Changed weight from 2 to 3. -Snow 3/00 */
set_weight (3);
set_value (1000);
set_hit_func(this_object ());
}

weapon_hit(attacker)
{
 if (random (10) > 2) return 0;
 write("You nearly smashed your opponent's head with your cudgel.\n");
 say (this_player()->query_name()+" nearly smashed his opponent's head.\n");
 return random(5)+3;
}
