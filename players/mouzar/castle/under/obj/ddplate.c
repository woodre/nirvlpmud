inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("plate");
set_alias("platemail");
set_short("Shiny Platemail");
set_long(
"This platemail shines.  It is like a mirrior it shines so great.\n"
+ "It must have been for a proud knight who lost it or who died fighting.\n");
set_weight(4);
set_value(2000);
set_ac(4);
set_type("chest");
}
