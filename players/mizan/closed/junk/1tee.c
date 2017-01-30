inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("shirt");
set_alias("tee shirt");
set_short("A tee shirt that reads 'I Rocked Castle Mizan!'");
set_long(
"You are the proud wearer of this shirt, which entitles you to a free \n"
+ "donut at all participating Dunkin Donut stores.\n");
set_weight(1);
set_value(100);
set_ac(1);
set_type("armor");
}
