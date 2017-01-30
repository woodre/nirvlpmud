inherit "obj/monster";

reset(arg)
{
object gold, weapon;
  ::reset(arg);
  if(arg) return;
set_name("Dick Vitale");
set_alias("vitale");
set_short("Dick Vitale");
set_level(10);
set_hp(200);
set_wc(15);
set_ac(8);
set_al(200);
set_chat_chance(30);
load_chat("Better call a T.O. baby!!!\n");
gold=clone_object("obj/money");
gold->set_money(400);
move_object(gold, this_object());
}
heart_beat(){
if(this_object()->query_attack()){
(this_object()->query_attack())->hit_player(5,0,"other|fire",1,"other|electricity");
}
::heart_beat();
}
