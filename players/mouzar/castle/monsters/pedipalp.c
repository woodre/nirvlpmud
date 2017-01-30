inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("pedipalp");
set_short("Pedipalp");
set_race("beast");
set_long("A large spider-scopion like thing with a long whip-like tail,that\n" +
        "rather resemble the stings of scorpions when held aloft.\n");
set_al(0);
set_level(8);
set_wc(12);
set_ac(7);
set_hp(120);
set_aggressive(0);
set_dead_ob(this_object());
}
 
monster_died(ob) {
  object money;
  tell_room(environment(),"As the pedipalp dies, you notice a sack of coins left behind by some foolish adventurer.\n");
  money=clone_object("/obj/money.c");
  money->set_money(300+random(100));
  move_object(money,environment(ob));
}
