inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("bright cloak");
set_alias("cloak");
set_short("a brightly colored cloak");
set_long(
"This cloak used to belong to one of the Royal Guards at Aldera. It has a\n"
+ "multiple array of bright colors that show off the glory of Aldera. It looks\n"
+ "thick and strong.\n");
set_weight(3);
set_value(900);
set_ac(1);
set_type("misc");
}
