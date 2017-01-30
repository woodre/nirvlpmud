inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
  gold->set_money(random(25));
  move_object(gold,this_object());
  ob2 = clone_object("/players/saber/armor/choker.c");
move_object(ob2,this_object());
 ob3 = clone_object("/players/saber/armor/fmask.c");
move_object(ob3,this_object());

set_name("Masked bandit"); /* Took out the number -Dar */
     set_short("A Masked Bandit");
     set_race( "human");
set_alias("bandit");
     set_long("A tough, shady looking character wearing a black face mask.\n");
     set_level(3);
     set_ac(4);
     set_wc(7);
     set_hp(45);
     set_al(-160);
     set_aggressive(0);
   }
}
