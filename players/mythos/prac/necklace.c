#define tp this_player()
inherit "obj/treasure";
reset(arg) {
  set_id("necklace");
  set_short("A Jeweled Necklace");
  set_long("A nice necklace... it radiates a strange power- change\n");
  set_weight(0);
  set_value(0);
}
init() {
  ::init();
 add_action("change","change");
return 1;
}

change(str) {
  object ob;
  int num;
  sscanf(str,"%d",num);
  ob=present("instrument",tp);
ob->set_bard_level(str);
return 1;
}
