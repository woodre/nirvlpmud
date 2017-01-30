inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("helmet");
set_short("Dwarven Helmet");
set_long(
"A black iron helmet that has more than it's share of dents in it.\n");
set_weight(1);
set_value(200);
set_ac(1);
set_type("helmet");
}
