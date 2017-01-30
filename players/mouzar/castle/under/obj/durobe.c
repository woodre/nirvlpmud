inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("robe");
set_alias("robes");
set_size(1);
set_short("Colorful robes");
set_long(
"A very colorful robe worn by Duergar Healiers.  The robes are filled with\n"
+ "stains and are kinda smelly.  There are some sprinkles of blood on it \n"
+ "from the people that the healier must have healed or tried to.\n");
set_weight(2);
set_value(500);
set_ac(3);
set_type("chest");
}
