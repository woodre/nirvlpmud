inherit"obj/armor";
reset(arg) {
if(arg) return;
::reset(arg);
set_name("ring");
set_alias("ring");
set_short("Aura Ring (glowing)");
set_long(
"A glistening ring surrounded by a protective aura.\n");
set_weight(1);
set_value(1900);
set_ac(2);
set_type("ring");
}
