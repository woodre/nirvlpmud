inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("platemail");
set_alias("plate");
set_short("Dwarven Platemail");
set_long(
"This is well made plate mail forged from black iron plate\n");
set_weight(3);
set_value(1500);
set_ac(3);
set_type("armor");
}
