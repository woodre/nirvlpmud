
inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("suit");
set_alias("red suit");
set_short("A red suit");
set_long("Spidy's red suit.\n");
set_weight(5);
set_value(1250);
set_ac(5);
set_type("armor");
}
 
query_save_flag() { return 1;}

