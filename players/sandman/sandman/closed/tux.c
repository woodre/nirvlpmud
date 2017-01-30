inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("black tuxedo");
set_alias("tuxedo");
set_short("Black Formal Tuxedo");
set_long(
"A sleek fitting tuxedo. This tuxedo is classic black, so black as to almost\n"+
"absorb the light around it.\n");
set_weight(1);
set_value(0);
set_ac(5);
set_type("armor");
set_arm_light(0);
}
