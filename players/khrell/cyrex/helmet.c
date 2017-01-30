inherit "obj/armor";
object helmet;
reset(arg) {
::reset(arg);
set_ac(1);
set_weight(1);
set_short("A battle-tech helmet");
set_long("A fine helmet that gives the wearer excellent protection.\n");
set_value(100);
set_alias("helmet");
set_type("helmet");
set_name("helmet");
}
