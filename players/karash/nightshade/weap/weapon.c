inherit "obj/weapon";
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(14);
                set_value(2000);
                set_weight(5);
                set_alias("bastard sword");
                set_short("Bastard Sword");
set_long("This sword is made to do considerable damage.  It is large and heavy with a razor sharp edge.\n");
}
}
