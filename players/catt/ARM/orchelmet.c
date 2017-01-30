inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
   set_name("orc helm");
   set_alias("helm");
   set_short("Orc Helm");
   set_long("A solid helmet of steel used by orc warriors. It looks useful.\n");
set_weight(1);
set_value(150);
set_ac(1);
set_type("helmet");
}
