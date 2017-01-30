inherit "/obj/monster.c";

reset(arg){
  ::reset();
  if(arg) return;
set_name("monster");
set_short("monster <FOR WIZARD KILLING ONLY>");
set_level(17);
set_hp(10);
set_ac(0);
set_wc(1);
set_al(0);
}
