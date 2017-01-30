inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("ring");
set_size(2);
set_short("Gold Ring");
set_long(
"A nice gold ring.\n");
set_weight(1);
set_value(200);
set_ac(1);
set_type("gloves");
}
