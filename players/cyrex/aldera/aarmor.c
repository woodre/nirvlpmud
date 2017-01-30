inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("royal armor");
set_alias("armor");
set_short("Royal Armor");
set_long(
"This armor used to belong to one of the Royal Guards at Aldera. It is a \n"
+ "fine piece of armor decorated with the glorious symbols of Aldera. It\n"
+ "look bulky yet protective.\n");
set_weight(4);
set_value(2000);
set_ac(4);
set_type("armor");
}
