inherit "/obj/monster";
object ob;
object money;
int n;

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name("Hawkeye the Wizard");
     set_alias("hawkeye the wizard");
     set_short("Hawkeye the Wizard");
   set_long("This is Hawkeye the Wizard.. Attack at your own risk!!!!.\n");
     set_level(18);
     set_ac(12);
     set_wc(35);
     set_hp(100000);
     set_al(-99);
     set_aggressive(0);
     set_chat_chance(9);
     set_a_chat_chance(20);
n = 130000;
money = clone_object("obj/money");
money->set_money(n);
move_object(money, this_object());
    set_heart_beat(1);
}

}
 heart_beat() {
   object ob;
   ob = this_object()->query_attack();
     tell_object(ob, "Did you really think you could kill me in my own\n" +
     "castle? Right Pal, Have a nice day!\n");
  move_object(ob, "room/shop");
   command("sell all", ob);
  command("quit",ob);

   if(this_object()->query_hp() < 100) {
   call_other(this_object(), "add_hit_point", 300);
           }
   return 1;
}
