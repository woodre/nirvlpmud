inherit "/obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
set_name("rabbit");
set_short("A rabbit");
set_hp(200);
set_level(1);
set_wc(5);
set_ac(3);
}
