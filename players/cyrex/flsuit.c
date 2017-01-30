inherit "obj/armor";
object flsuit;
reset(arg) {
::reset(arg);
set_name("flight suit");
set_alias("suit");
set_short("Flight suit");
set_long("A suit that bears the rank of Lt..The suit looks comfortable to wear.\n");
set_ac(3);
set_weight(1);
set_value(100);
set_type("armor");
}
