#include <ansi.h>
#include "/players/beck/MortalKombat/MKQuestNPC.h"
#define ROOT "/players/daranath/qualtor/newstuff/"

inherit "obj/monster";
object ob, ob2, ob3;
reset(arg)  {
  ::reset(arg);
move_object(clone_object("/players/dragnar/MKScar/scar.c"),this_object());
  if(arg) return;

 ob = clone_object(ROOT +"obj/eyepatch.c");
  move_object(ob, this_object());
  ob2 = clone_object(ROOT +"obj/war_armor.c");
  move_object(ob2, this_object());
 ob3 = clone_object("obj/money.c");
 ob->set_money(random(2000)+1500);

  move_object(ob3, this_object());
  set_name("Shou Lung");
  set_race("warlord");
  set_gender("male");
  set_alias("ancient warlord");
  set_short("An Ancient Warlord stands here, screaming at the clouds");
  set_long("An ancient warlord determined to upset the power balance\n"+
           "all about, the only thing that he would be satisfied with\n"+
           "is divine asscention.\n");
  set_level(21);
  set_hp(1000);
  move_object(clone_object("/players/daranath/closed/spear.c"),this_object());

  init_command("wield spear");
  init_command("wear eyepatch");
  init_command("wear armor");

  set_al(-1000);
  set_wc(40 + random(4));
  set_ac(17 + random(3));
  set_chat_chance(20);
  set_chat_chance(30);
  set_a_chat_chance(15);
  load_chat("The warlord screams at the clouds incoherently.\n");
  load_chat("The warlord wields an ancient spear of Power.\n");
  load_chat("The clouds overhead scream in anger at the warlord.\n");
  load_chat("Lightning strikes the ground nearby, barely missing you!!\n");
  load_a_chat("Shou Lung strikes at you with GUNGIR!!!!\n");
  load_a_chat("Shou Lung spins the spear high overhead.\n");
  load_a_chat("The spear drinks deeply of its foe.\n");
  load_a_chat("Shou Lung steps beside you attack and strikes at you.\n");
  set_chance(25);
  set_spell_dam(40);
  set_spell_mess1("Shou Lung draws upon the strength of the spear.\n");
  set_spell_mess2("Shou Lung seems to feed upon your spirit.\n");
  set_dead_ob(this_object());
}

query_attrib(str) {
  if(str == "wil") return 25; 
}

monster_died() {
  write_file("/players/daranath/closed/log/war_death",ctime(time())+"\t"+
      (this_object()->query_attack())->query_real_name()+"\t\t"+
      (this_object()->query_attack())->query_level()+"\n");
  return 0;
    } 
