inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("glaive");
set_alias("pole");
set_short("Glaive");
set_long(
"A pole weapon with a large head shaped like a sword.  It is covered with blood.\n");
set_value(800);
set_weight(2);
set_class(17);
}
