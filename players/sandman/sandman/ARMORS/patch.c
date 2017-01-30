inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("eye patch");
set_alias("patch");
set_short("Eye Patch");
set_long(
"A black leather eye patch, of late belonging to the Mighty Odin.\n");
set_weight(1);
set_value(750);
set_ac(1);
set_type("helmet");
}
