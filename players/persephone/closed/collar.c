inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("leather collar");
set_alias("collar");
set_short("Leather Collar");
set_long(
"A black soft leather collar. The collar is embroidered with gold thread\n" +
"around the edges. In the center it is emblazened with a capital S.\n");
set_weight(1);
set_value(250);
set_ac(1);
set_type("misc");
}
