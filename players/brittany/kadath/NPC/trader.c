#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

enable_commands();
    me = this_object();
message_hit=({"massacre"," to small fragments","smashed"," with a bone crushing sound","hit"," very hard","hit"," hard","hit","","grazed","","tickled"," in the stomach"});

set_name("merchant");
set_alias("trader");
set_alt_name("man");
set_race("human");
set_short("A merchant trader");
set_long("A queerly intelligent looking old man who is oddly robed\n"+
"and has a high turban, with a strange ruby lodged into the\n"+
"middle of it.  The slant-eyed merchant will trade goods\n"+
"with the stone village merchants and anyone passing along\n"+
"the Skai Rivers.\n");

set_level(20);
set_hp(1000);
set_al(150);
set_wc(30);
set_ac(18);
set_heal(20,2);
set_aggressive(0);
set_chat_chance(8);
load_chat
("Merchant says:  I will trade most goods for fair value.\n");
set_a_chat_chance(10);

gold = clone_object("obj/money");
gold->set_money(150);
move_object(gold,this_object());
return 1;
}

monster_died() {
  tell_room(environment(this_object()),
"Trader falls to the ground and dies.\n");
return 0; }
