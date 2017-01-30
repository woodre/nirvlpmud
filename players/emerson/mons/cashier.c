inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
  ob2 = clone_object("players/emerson/armor/ntag");
   move_object(ob2,this_object());
 gold = clone_object("obj/money");
 gold->set_money(200);
  move_object(gold,this_object());
     set_name("cashier");
set_short("A Cashier");
     set_race( "human");
set_long("This is a cashier, he looks like he might have some money on him.\n");
     set_level(15);
     set_ac(10);
     set_wc(20);
     set_hp(300);
     set_al(500);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(35);
      load_chat("The cashier stares at you suspiciously.\n");
      load_a_chat("The cashier scratches you with his keys.\n");
      load_a_chat("Cashier kicks you between the legs.\n");
   }
}
