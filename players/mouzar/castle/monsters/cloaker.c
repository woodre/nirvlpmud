inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("cloaker");
set_short("Cloaker");
set_long("This monster looks just like a black cloak.  The two rows of black\n" +
        "eye eye spots running down it that look much like buttons, and the two \n" +
        "ivory-colored claws on its upper edge look just like bone clasps.\n");
set_al(0);
set_level(12);
set_wc(16);
set_ac(9);
set_hp(180);
set_aggressive(1);
set_dead_ob(this_object());
}
 
monster_died(ob) {
  object money;
  tell_room(environment(),"Your final blow splits open the cloaker's stomach, revealing bits of undigested metal.\n");
  money=clone_object("/obj/money.c");
  money->set_money(400+random(400));
  move_object(money,environment());
}
