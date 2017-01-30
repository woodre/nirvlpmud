/*
  oak_branch.c
*/

inherit "obj/weapon";

reset(arg) {
  set_name("oak branch");
  set_id("branch");
  set_alias("oak branch");
  set_short("A heavy oak branch");
  set_long("It is a heavy oak branch.\n");
  set_class(6);
  set_weight(2);
  set_value(30);
}

query_save_flag() { return 1; }

id(str) { return str=="oak branch" || str=="branch" ||
                 str=="nooneelseoakbranch"; }
