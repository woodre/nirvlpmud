inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Katana");
set_alias("katana");
set_short("Katana");
set_long(
"A light two handed sword made of a high carbon steel edge, slowly\n"
+ "changing into a softer flexible back.  It has one edge, which is\n"
+ "sharpened into a razor point.\n");
set_value(6000);
set_weight(1);
set_class(17);
set_hit_func(this_object());
}
