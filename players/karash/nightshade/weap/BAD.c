inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("axe");
                set_class(30); /* fixed just in case from 30 to 18
                                    - mythos <5-10-96> */
                set_value(500);
                set_weight(1);
                set_alias("axe");
                set_short("Massive Battle Axe");
set_long(
"A monstrous battle axe. If you have it, you must be damn lucky or damn good!\n");
}
}
