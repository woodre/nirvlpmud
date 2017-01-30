inherit "obj/weapon.c";

reset (arg) {
::reset (arg);
if (arg) return;

set_name ("longsword");
set_alias ("sword");
set_short ("Gdemia Longsword");
set_long ("It's very nice longsword made by Gdemia Blacksmithes!\n");
set_class (18);
set_weight (2);
set_value (1000);
set_hit_func(this_object ());
}

weapon_hit(attacker)
{
 if (random (10) > 2) return 0;
 write(this_player()->query_name()+" makes a smart move and hits "+
       "his opponent in a weak spot.\n");
 say (this_player()->query_name()+" hits "+
      (this_player()->query_attack())->query_name()+" in a weak spot.\n");
/*
 RETURN is WAY too high, patched by mizan
 return 10 + random (15);
*/
 return 7;
}
