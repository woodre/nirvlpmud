inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("green cape");
	set_alias("cape");
	set_short("A green cape");
	set_long("This is an ordinary-looking green cape.\n");
	set_value(200);
	set_ac(1);
	set_type("misc");
  set_weight(1);
}
