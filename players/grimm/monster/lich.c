inherit "obj/monster.talk";
object coins, item, attack_ob;
int i, j;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("lich");
set_short("A Lich");
set_long("This is one of the fiercest undead creatures known to man.\n");
set_al(-1000);
set_level(20);
set_wc(30);
set_hp(500);
set_ac(17);
set_aggressive(0);
item = clone_object("players/grimm/weapons/lich_axe");
move_object(item,this_object());
coins = clone_object("obj/money");
coins->set_money(500+(random(200)));
move_object(coins,this_object());
}
attack() {
j=random(100);
attack_ob=query_attack();
i=random(20);
if ((j<45) && (attack_ob->query_sp() > 20)) {
  if (i<1) {
tell_room(environment(),"The Lich drains the life from "+
attack_ob->query_name()+".\n");
  call_other(attack_ob,"add_spell_points",-20);
  return::attack();
}
  else {
  if (i<4) {
    tell_room(environment(),"The Lich uses a psy-attack on "+
attack_ob->query_name()+".\n");
    call_other(attack_ob,"add_spell_points",-10);
    return::attack();
  }
   else {
    if (i<6) {
      tell_room(environment(),"The Lich uses a psychic blast on "+
        attack_ob->query_name()+".\n");
      call_other(attack_ob,"add_spell_points",-5);
      return::attack();
    }
    else {
      tell_room(environment(),"The Lich begins to melt "+
        attack_ob->query_name()+"'s brain.\n");
      call_other(attack_ob,"add_spell_points",-3);
      return::attack();
    }
  }
 }
}
return::attack();
}
