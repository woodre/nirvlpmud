inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("test");
set_short("WC 20");
set_long("test\n");
  set_gender("female");
set_level(30);
  set_wc(20);
set_ac(1);
set_hp(500);
}
