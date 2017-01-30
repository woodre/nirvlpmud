inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(14);
                set_value(500);
                set_weight(5);
                set_alias("sword");
                set_hit_func(this_object());
set_short("A guard's sword");
set_long("This is a normal sword....taken from a dead guy yeah but normal.\n");
}
}
weapon_hit(attacker)
{
if(random(100) < 5) return 3;
}
