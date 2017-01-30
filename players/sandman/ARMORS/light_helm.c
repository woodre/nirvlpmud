inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("glowing helmet");
set_alias("helmet");
set_short("Glowing Helmet");
set_long(
"A finely crafted helmet, it seems to emit a soft glow\n");
set_weight(1);
set_value(350);
set_ac(1);
set_type("helmet");
set_arm_light(1);
}
