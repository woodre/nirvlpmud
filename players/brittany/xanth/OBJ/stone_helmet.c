inherit "obj/armor";

reset(arg){
::reset(arg);

set_name("helmet");
set_short ("A stone helmet");
set_alias("helmet");
set_long("A helmet made out of stone.\n");

   set_ac(1);
set_type("helmet");
set_weight(1);
set_value(200+random(300));
set_save_flag(1);
}
