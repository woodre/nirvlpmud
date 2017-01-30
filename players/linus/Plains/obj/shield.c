inherit "/obj/armor.c";
id(str) { return str=="shield" || str=="wooden shield"; }
reset(arg) {
 ::reset(arg);
 set_name("shield");
 set_short("A wooden shield");
 set_long(
  "  The wood is old and cracked, held together by metal bands in\n"+
  "a crossing pattern.  Leather straps are fastened to the back of\n"+
  "the shield for handles.\n");
 set_ac(1);
 set_type("shield");
 set_weight(2);
 set_value(200+random(600));
}
