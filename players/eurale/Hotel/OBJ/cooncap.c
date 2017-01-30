/*  A coonskin cap  */

inherit "obj/armor";
reset(arg) {
  set_name("cap");
  set_short("A coonskin cap");
  set_alias("cap");
  set_long(
	"  A hand-sewn cap made from the pelt of one of the mountain \n"+
	"raccoons.  It is lush and provides warmth on cold days. \n");
  set_ac(1);
  set_type("helmet");
  set_weight(1);
  set_value(200);
}
