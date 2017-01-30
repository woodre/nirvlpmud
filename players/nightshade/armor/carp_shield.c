inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_short("Carpathian Shield");
set_long("This shield also belonged to the poor Carpathian adventurer.\n");
set_ac(1);
set_weight(1);
set_value(100);
set_type("shield");
set_name("shield");
}
