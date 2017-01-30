#include <ansi.h>
#define ROOT "/players/daranath/qualtor/newstuff/"

inherit "/players/daranath/closed/monster1.c";
object ob, ob2, ob3, ob4;

reset(arg) {
   ::reset(arg);
   if (!arg) {

 ob = clone_object("obj/money");
  ob->set_money(random(1500) + 750);
/* Average coins of 3500, 1500 below monster guide */
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"junk/lav_robes.c");
  move_object(ob2, this_object());
 ob3 = clone_object("/players/daranath/qualtor/obj/sandles.c");
  move_object(ob3, this_object());
 ob4 = clone_object(ROOT+"weps/kitten.c");
  move_object(ob4, this_object());

set_name("Kaya the Monk");
set_alias("kaya");
set_alt_name("monk");
set_race("human");
set_gender("female");

set_short("Kaya, the master Monk");
set_long("Kaya stands before you, wearing a lavender set of Monk's robes that\n"+
         "have been cut to accent her fighting style. She is the creater of\n"+
         "a deadly new fighting style called the Pouncing Kitten.\n"+
         "Do you have what it takes to defeat her?\n");

set_level(20);
set_ac(17);
set_wc(25 + random(4));
set_hp(450 + random(100));
set_al(0);
set_aggressive(0);
set_dead_ob(this_object());

set_chance(20);
set_spell_dam(random(50)+25);
set_spell_mess2("Kaya hits you with a crushing blow.\n");
set_spell_mess1("Kaya crushes her foe with another blow.\n");

init_command("wield kitten");
init_command("wear robes");
init_command("wear sandles");

   }
}

monster_died() {
write_file("/players/daranath/closed/log/kaya_death",ctime(time())+"\t"+
  (this_object()->query_attack())->query_real_name()+"\t\t"+
  (this_object()->query_attack())->query_level()+"\n");
return 0;
}
