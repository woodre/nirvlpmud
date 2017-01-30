inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("goblin cap");
set_alias("cap");
set_short("goblin cap");
set_long(
"A solid cap of steel used by the goblins as helmets of a sort.\n" +
"It isn't pretty stuff, but it fulfills it's purpose.\n");
set_weight(1);
set_value(150);
set_ac(1);
set_type("helmet");
}
