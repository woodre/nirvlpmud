inherit "obj/weapon.c";

reset (arg) {
::reset (arg);
if (arg) return;

set_name ("sword");
set_alias ("gdemia sword");
set_short ("Gdemia Sword");
set_long ("It's very nice sword made by Gdemia Blacksmithes!\n");
set_class (16);
set_weight (2);
set_value (600);
set_hit_func(this_object ());
}

weapon_hit(attacker)
{
 if (random (10) > 2) return 0;
 write (this_player()->query_name()+" makes a smart move and hits his opponent in a weak spot.\n");
 say (this_player()->query_name()+" hits "+(this_player()->query_attack())->query_name()+" in a weak spot.\n");
  return (5 + random (8));
}
