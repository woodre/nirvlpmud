object gold;
inherit "obj/monster";

object mane;
reset(arg) {
::reset(arg);
if(!arg) {
set_alias("insect");
set_alt_name("roach");
set_name("cochroach");
set_short("A little cochroach");
    set_race("demon");
set_long(
"A little thief.  He seems quite interested in your objects.  You should make\n"+
"sure they are all here.\n");
gold = clone_object("obj/money");
gold->set_money(random(100));
move_object(gold, this_object());
set_chat_chance(10);
load_chat("The cochroach scurries about.\n");
load_chat("The cochroach climbs into your clothes and then exits swiftly.\n");
set_a_chat_chance(10);
set_spell_mess2("Plutus casts a black spell at you!\n");
   set_level(10);
   set_ac(9);
   set_wc(12);
   set_al(-150);
  set_aggressive(0);
}
}
