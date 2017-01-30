inherit "/obj/monster";
object ob;
object money;
int n;

reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("edna");
     set_alias("edna");
 set_short("Edna the secretary");
 set_long("This is Edna, the Information Center secratary. Edna is\n"+
  "one huge woman and I really don't recommend you trying to fight her.\n");
     set_level(100);
     set_ac(18);
     set_wc(35);
     set_hp(90000);
     set_al(-99);
     set_aggressive(0);
     set_chat_chance(9);
     set_a_chat_chance(20);
n = 80000;
money = clone_object("obj/money");
money->set_money(n);
move_object(money, this_object());
    set_heart_beat(1);
}

}
 heart_beat() {
  object sucker, ob;
   ob = this_object()->query_attack();
   if(ob->query_npc()) {
        destruct(ob);
           return 1;
       }
tell_object(ob, "Well that's Pretty Damn Stupid!!!\n"+
 "You think you can knock off my Secretary? Think again!!!\n"+
 "buddy! Maybe next Year!    Later Alligator.\n\n\n"+
   "You drop all your shit and a little bastard thief runs up\n"+
   "and snatches it.\n");
   sucker = clone_object("/players/pavlik/monsters/bastard.c");
   move_object(sucker, environment(this_object()));
     move_object(ob, sucker);
   command("drop all", ob);
   command("quit", ob);
   return 1;
}
