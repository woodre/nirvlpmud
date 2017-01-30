inherit "obj/weapon";
int i;
reset (arg) {
:: reset (arg);
if (arg) return;
set_name("rope-chain");
set_alias ("rope-chain");
set_short ("A rope-chain to hold keys on");
set_long ("This rope-chain packs a reaallll wollop.\n");
set_class (15);
set_weight (5);
set_value (600);

set_hit_func (this_object());
}
weapon_hit (attacker) {
i = random (20);
if (i>5) {
say (this_player() -> query_name ()+" 's can bounces off you nogin'\n");
write ("You wish you'ld gotten a chance to finish your beans \n before this thing interrupted you\n");
return 1;
}
return 0;
}


