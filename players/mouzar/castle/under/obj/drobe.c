inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("robes");
set_alias("robe");
set_size(2);
set_short("Black Wizard Robes");
set_long(
"These robes are made of black silk.  There are no pockets to be found.\n"
+ "They are light weight and have a strange glow to them.  Magical?\n");
set_weight(1);
set_value(4000);
set_ac(4);
set_type("armor");
}
