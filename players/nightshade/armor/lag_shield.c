inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_short("Lag shield");
set_long("This is the shield of the net lag demon. This item has been known to cause a mud to lag horrendously.\n");
set_ac(1);
set_weight(1);
set_value(100);
set_type("shield");
set_name("shield");
}
