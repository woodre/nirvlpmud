inherit "obj/monster.talk";
object coins, item, attack_ob;
int i, j;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("flayer");
set_short("A Mind Flayer");
set_long("This is a rather mysterious creature that has been known to have"
+" very\nstrong mental powers.\n");
set_al(-500);
set_level(20);
set_wc(30);
set_hp(600);
set_ac(18);
set_aggressive(0);

item = clone_object("players/grimm/weapons/cuth_mace");
move_object(item,this_object());
coins = clone_object("obj/money");
coins->set_money(500+(random(200)));
move_object(coins,this_object());
}
/* Special attack: drains spell points */
attack() {
j=random(100);
attack_ob=query_attack();
if ((j<40) && (attack_ob->query_sp() > 30)) {
  i=20+random(20);
tell_room(environment(),"The Mind Flayer drains the life from "+
attack_ob->query_name()+".\n");
  call_other(attack_ob,"add_spell_points",-i);
  return::attack();
}
return::attack();
}
