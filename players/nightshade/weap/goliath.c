inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(17);
                set_value(500);
                set_weight(4);
                set_alias("razor");
set_short("Goliath Sword");
set_long("A very long heavy blade but very powerful.\n");
}
}
