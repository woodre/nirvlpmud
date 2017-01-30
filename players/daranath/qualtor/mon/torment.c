inherit "/players/mythos/amon/forest/monster1";
object ob;

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/wep/scourge.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/torm_armor.c"),this_object());
 ob = clone_object("obj/money.c");
 ob->set_money(2000+random(2000));
/* Average coins of 5000, per monster guide */
  move_object(ob, this_object());

     set_name("Tormentor");
     set_short("A dark figure in platemail");
     set_alias("figure");
     set_alt_name("tormentor");
     set_race("human");
     set_gender("male");
     set_long("A dark figure wearing a bizarre set of spiked platemail\n"+
              "made from a dark black metal, he stands before you\n"+ 
              "definiantly. A wicked scourge twiches in his right hand,\n"+
              "acting as if he wants to put it to use upon you.\n");
     set_level(20);

     init_command("wield scourge");
     init_command("wear plate");

     set_ac(18);
     set_wc(30 + random(4));
     set_hp(650 + random(60));
     set_al(-1000);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_a_chat_chance(20);
     load_a_chat("Tormentor growls: Don't fool yourself.\n");
     load_a_chat("Tormentor thrashes you with the Scourge.\n");
     load_a_chat("Tormentor growls: I will feast upon your soul!\n");
     load_a_chat("The scourge slices deeply into your body.\n");

   }
}

monster_died() {
write_file("/players/daranath/closed/log/tor_death",ctime(time())+"\t"+
  (this_object()->query_attack())->query_real_name()+"\t\t"+
  (this_object()->query_attack())->query_level()+"\n");
return 0;
}
