inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("axe");
set_alias("orc axe");
set_short("Axe");
set_long(
"This axe has not been taken care of.  It has chips missing out of the\n"
+ "handle and it is covered in dry blood.  It doesn't look like much.\n");
set_value(100);
set_weight(2);
set_class(14);
}
