inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("shield");
set_alias("ddshield");
set_short("Shield");
set_long(
"A nice looking shield.  Whoever had this before you must have died to depart\n"
+ "with such a great shield.\n");
set_weight(1);
set_value(500);
set_ac(1);
set_type("shield");
}
