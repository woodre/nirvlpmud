#define tp this_player()
inherit "obj/armor";
int pro;

reset(arg) {
set_name("rusty shield");
set_alias("shield");
set_short("rusty shield");
set_long(
  "This rusty round shield has a partially hidden mystical emblem\n"+
  "embedded in its center.  It is lightweight, very dirty but in all\n"+
  "other aspects seems perfectly fine.\n");
set_ac(1);
set_type("shield");
set_weight(1);
set_value(245);
set_arm_light(0);
}
