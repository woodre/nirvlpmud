inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("redtape");
                set_class(13);
                set_value(450);
                set_weight(3);
                set_alias("redtape");
set_short("Bureacratic Redtape");
set_long("This is the favored weapon of the lackies,they use it well and often\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker) {
if(random(100) < 10) return 2;
}
