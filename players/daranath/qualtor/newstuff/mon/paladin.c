#define ROOT "/players/daranath/qualtor/newstuff/"

inherit "/players/mythos/amon/forest/monster1";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, ob3, ob4;

 ob = clone_object("obj/money");
 ob->set_money(random(440) + 500);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT+"weps/pal_blade.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT+"obj/pal_plate.c");
  move_object(ob3, this_object());
 ob4 = clone_object(ROOT+"obj/surcoat1.c");
  move_object(ob4, this_object());

set_name("Qual'tor Paladin");
set_short("Paladin of Qual'tor");
set_alias("paladin");
set_alt_name("churchmon");
set_race("human");
set_gender("male");
set_long("Long since missing from the city of Qual'tor, the Paladins have recently\n"+
         "made a comeback, returning to defend the City Ward from the undead \n"+
         "threats that lurk about.\n");
set_level(19);

init_command("wear armor");
init_command("wear surcoat");
init_command("wield blade");

set_ac(16);
set_wc(25 + random(8));
set_hp(450 + random(120));
set_al(1200);
set_aggressive(0);
set_chat_chance(6);
set_a_chat_chance(15);
load_chat("Paladin of Qual'tor stands watch over the Ghost Ward.\n");
load_chat("Paladin of Qual'tor stands watch over the barricade.\n");
load_chat("The Paladin whispers a brief prayer for those who are going into Ghost Ward.\n");
load_chat("The Paladin whispers a brief prayer to Targos, the Sun God.\n");
load_chat("Paladin says: Nothing will get by me while I still live.\n");
load_chat("Paladin says: I must stand watch here, the citizens depend on me.\n");
load_a_chat("Paladin shouts: Get back, foul demon!\n");

   }
}
