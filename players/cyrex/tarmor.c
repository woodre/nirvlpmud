inherit "obj/armor";
object tarmor;
reset(arg) {
::reset(arg);
set_name("tech-armor");
set_alias("armor");
set_short("Heavy Polymer Armor");
set_long("A shiny, tough armor that looks hard to penetrate.\n");
set_ac(4);
set_weight(8);
set_value(1000);
set_type("armor");
}
