inherit "obj/monster.c";
reset(arg) {
  ::reset(arg);
  if(!arg) {
object gold;
gold=clone_object("obj/money");
gold->set_money(100+random(400));
move_object(gold, this_player());
 set_name("baloo");
 set_alias("bear");
 set_alias("Baloo");
 set_short("Baloo, a huge blue-grey bear");
set_long("A huge blue-grey bear. He is picking fruit from\n"+
         "a prickly Paw-paw tree and singing a snappy tune.\n");
  set_level(10);
 set_ac(8);
 set_wc(14);
 set_hp(150);
 set_chat_chance(35);
load_chat("Baloo sings: Look for the bear necessities, the simple bear necessities!\n");
load_chat("Baloo says: I'm gone man, solid gone!\n");
set_a_chat_chance(50);
load_a_chat("Baloo yells: Bagera!! Help me!!!\n");
load_a_chat("Baaaaaaageeeeeeeeeeraaaaaaaaaaaaa!!!\n");
 }
}
