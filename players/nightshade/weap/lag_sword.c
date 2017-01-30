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
set_short("Net lag sword");
set_long(
"This is the infamous net lag sword. The demon has been causing muds all\n"+
"over the United States with it. It has caused crashes, lag beyond\n"+
"belief and host unreachable. Might make a good weapon too.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 30) return 2;
}
