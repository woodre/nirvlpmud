inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("dagger");
                set_alias("knife");
                set_value(100);
		set_class(10);
                set_weight(2);
                set_hit_func(this_object());
set_short("A dagger");
set_long("This dagger is a piece of dung.....\n");
}
}
weapon_hit(attacker)
{
if(random(100) < 2) return 3;
}
