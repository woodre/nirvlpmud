inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("goblin armor");
set_alias("armor");
set_short("Goblin armor");
set_long(
"Goblin armor used by sentries of goblin mountain.\n");
set_weight(3);
/* Changed value 500 to 200 -Snow */
set_value(200);
set_ac(2);
set_type("armor");
}
