inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("halberd");
		set_class(18);
		set_value(3000);
		set_weight(3);
                set_alias("halberd");
		set_short("Longback Halberd");
set_long(
"  This is a sinister looking thing, large and painful looking, but rather\n"+
"  heavy to wield.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 10) return 6;
}
