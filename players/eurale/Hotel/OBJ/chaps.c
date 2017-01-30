/*  leather chaps  */

inherit "obj/armor";
reset(arg) {
  set_name("chaps");
  set_short("Leather chaps");
  set_alias("chaps");
  set_long(
	"  These tough leather chaps provide protection for the legs \n"+
	"when traveling through rough terrain.\n");
  set_ac(1);
  set_type("misc");
  set_weight(2);
  set_value(400);
}
