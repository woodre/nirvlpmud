inherit "obj/monster";

object money,uniform;

reset(arg) {
  set_name("rom");
  set_alias("ferrengi");
  set_short("Rom");
  set_long(format("Rom is a ferrengi, who after years of slaving away "+
                  "and being degraded in his brothers' bar, finally "+
                  "realized his potential and became an engineer on "+
                  "Chief O'Brien's engineering team. Right now, he is "+
                  "fixing a broken computer relay.\n",75));
  set_level(18+random(10));
  set_wc(20+random(10));
  set_ac(10+random(10));
  set_hp(700+random(200));
  set_al(100);
  money = clone_object("obj/money");
  money->set_money(random(600)+300);
  move_object(money, this_object());
  uniform = clone_object("players/gowron/ds9/obj/rom_uniform");
  move_object(uniform, this_object());
}     
