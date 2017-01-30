#define tp this_player()
inherit "obj/armor";

reset(arg) {
set_name("shawl");
set_alias("threadbare shawl");
set_short("Threadbare shawl");
set_long(
  "This threadbare shawl has seen better days.  The material is worn\n"+
  "the colors are faded, and it hasn't seen a decent washing in ages.\n");
set_ac(1);
set_type("misc");
set_weight(1);
set_value(545);
set_arm_light(0);
}
