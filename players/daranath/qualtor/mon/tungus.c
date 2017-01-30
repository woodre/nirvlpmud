#define ROOT "/players/daranath/qualtor/"
inherit "/obj/monster";
object ob;

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object(ROOT+"wep/tungus_axe.c"),this_object());
move_object(clone_object(ROOT+"obj/tungus_chain.c"),this_object());
move_object(clone_object(ROOT+"obj/tungus_boots.c"),this_object());

 ob = clone_object("obj/money.c");
 ob->set_money(random(2000)+1000);
  move_object(ob, this_object());

     set_name("Tungus Grump");
     set_short("A nasty little dwarf");
     set_alias("tungus");
     set_race("dwarf");
     set_gender("male");
     set_long("Tungus Grump is short, even for one of his race. Not quite\n"+
              "four feet tall, he spreads his anger all about Nirvana, annoying\n"+
              "wizard and adventuror alike. His fire orange beard is fading\n"+
              "with age, turning brownish the grey as it descends to\n"+
              "the ground.\n");
     set_level(20);

     init_command("wield axe");
     init_command("wear chain");
     init_command("wear boots");

     set_ac(22);
     set_wc(38 + random(4));
     set_hp(850 + random(80));
     set_al(-1000);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(15);
     set_a_chat_chance(20);
     load_chat("Tungus digs through his beard looking for something to eat.\n");
     load_chat("Tungus says: Dem Rats are good eatin'!\n");
     load_chat("Tungus gives off a foul order from somewhere within his body.\n");
     load_chat("Tungus chases around the area after something you cannot see.\n");
     load_a_chat("Tungus growls at you in a bizarre manner.\n");
     load_a_chat("Tungus Grump hits you with a bone crushing sound.\n");
     load_a_chat("Tungus stop for a second to pick his nose, then flicks it at you.\n");
     load_a_chat("Tungus Grump is gonna put a hurt on you!!!!\n");

   }
}

monster_died() {
write_file("/players/daranath/closed/log/tungus_death",ctime(time())+"\t"+
  (this_object()->query_attack())->query_real_name()+"\t\t"+
  (this_object()->query_attack())->query_level()+"\n");
return 0;
}
