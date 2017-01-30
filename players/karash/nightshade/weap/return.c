inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(15);
                set_value(500);
                set_weight(3);
                set_alias("sword");
set_short("Sentry sword");
set_long(
"A longsword belonging to the town watch.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) <30)
{
write("The sword is returning 2 right now.\n");
return 2;
}
}
