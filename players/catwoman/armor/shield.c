
inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("shield");
set_alias("rusty shield");
set_short("A rusty shield");
set_long("A rusty shield.\n");
set_weight(1);
set_value(250);
set_ac(1);
set_type("shield");
}
 
