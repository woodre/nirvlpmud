inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("dagger");
                set_class(4);
                set_value(70);
                set_weight(2);
                set_alias("dagger");
                set_short("Dagger");
set_long(
"A small dagger used by pixies and sprites.\n");
}
}
