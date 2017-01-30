inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_short("Black shield");
set_long("A shield nade from glassteeled black diamond.\n");
set_ac(1);
set_weight(1);
set_value(500);
set_type("shield");
set_name("shield");
}
