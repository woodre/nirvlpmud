inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("scalemail");
set_alias("mail");
set_size(1);
set_short("Dirty Scalemail");
set_long(
"This suit of scalemail is dirty.  It is dented and broken in many places.\n"
+ "It is something someone would not want to wear.\n");
set_weight(2);
set_value(300);
set_ac(3);
set_type("armor");
}
