inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("shield of aldera");
set_alias("shield");
set_short("Shield of Aldera");
set_long(
"This shield used to belong to one of the standing guards at Aldera. It\n"
+ "shines with awesome beauty. It is a huge shield that protects the\n"
+ "wearer from chest to shin.\n");
set_weight(4);
set_value(1000);
set_ac(1);
set_type("shield");
}
