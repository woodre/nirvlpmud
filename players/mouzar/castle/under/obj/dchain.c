inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("chainmail");
set_alias("chain");
set_size(2);
set_short("Drow Chainmail");
set_long(
"Some of the finest crafted chianmail that is made.  It is light weight and\n"
+ "durable.\n");
set_weight(2);
set_value(600);
set_ac(3);
set_type("chest");
}
