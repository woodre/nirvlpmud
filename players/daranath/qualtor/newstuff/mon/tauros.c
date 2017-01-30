/* big monster, he is in a room that prevents leaving if he is present
   even blocks whimpy, so that does not show here. 
   (/players/daranath/qualtor/newstuff/arena_way4.c)   -Dar  */

#define ROOT "/players/daranath/qualtor/newstuff/"

inherit "/players/mythos/amon/forest/monster1";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, ob3, ob4;

 ob = clone_object("obj/money");
 ob->set_money(random(3000) + 3500);
/* Average coins of 8000, per monster guide */
  move_object(ob, this_object());
 ob2 = clone_object(ROOT+"obj/tauros_arm.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT+"obj/tauros_shd.c");
  move_object(ob3, this_object());
 ob4 = clone_object(ROOT+"weps/bonecrusher.c");
  move_object(ob4, this_object());

set_name("Tauros the Minotaur Champion");
set_short("Tauros, the Minotaur Champion");
set_alias("tauros");
set_alt_name("champion");
set_race("minotaur");
set_gender("male");
set_long("A former Champion of Qual'tors Arena and current leader of the minotaur\n"+
         "race, Tauros stands tall and strong before you. He is covered in\n"+
         "a variety of wicked scars, both from Arena combat and other deadly\n"+
         "contests. Both hands tightly grasp a massive Maul, while an \n"+
         "interlocking buckler made of bone is strapped to one arm.\n");
set_level(23);

init_command("wear armor");
init_command("wear shield");
init_command("wield maul");

set_ac(21);
set_wc(38 + random(8));
set_hp(750 + random(200));
set_al(-(650+random(350)));
set_aggressive(0);
set_dead_ob(this_object());
set_chat_chance(3);
load_chat("Tauros needs a few more bones for his shield.\n");
load_chat("Tauros grips BoneCrusher tightly, ready for another fight.\n");

set_mult(2);
set_mult_chance(30);
set_mult_dam1(15);
set_mult_dam2(12);

set_chance(10);
set_spell_dam(40+random(50));
set_spell_mess1("Tauros swings BoneCrusher high overhead, yelling loudly.\n");
set_spell_mess2("\nTauros pummels you with BoneCrusher, his massive Maul\n\n");
   }
}

monster_died() {
write_file("/players/daranath/closed/log/tauros_death",ctime(time())+"\t"+
  (this_object()->query_attack())->query_real_name()+"\t\t"+
  (this_object()->query_attack())->query_level()+"\n");
return 0;
}
