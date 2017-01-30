inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("large metal shield");
set_short("Shield");
set_long("A plain large metal shield\n");
set_weight(1);
set_value(300);
set_ac(1);
set_type("shield");
}
