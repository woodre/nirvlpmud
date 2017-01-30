#include "/players/mythos/closed/ansi.h"
inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("smith");
  set_race("smith");
  set_gender("male");
  set_alias("sword smith");
  set_short("Sword Smith");
  set_long("The Smith is not quite what you expected.\n"+
    "He is of slim build and rather handsome.\n"+
    "He is at work...making blades of perfection.\n"+
    "If you wish to buy anything look at the sign\n"+
    "and hand him the money....\n");
  set_hp(1000);
  set_level(25);
  set_al(1000);
  set_wc(40);
  set_ac(17);
  set_heal(8,10);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(10);
  set_chat_chance(30);
  set_a_chat_chance(15);
    load_chat("The Smith hammers a long piece of hot metal.\n");
    load_chat("Hisssss......  A piece of glowing metal is placed in water.\n");
    load_chat("The Smith wipes some sweat from his brow.\n");
    load_a_chat("The Smith sidesteps your attack and whips out with Zantetsuken!\n");
    load_a_chat("The Smith passes through your defenses and slices into you!\n");
    load_a_chat("There is death reflected in the eyes of the Smith.\n");
  set_chance(40);
  set_spell_dam(random(200));
  set_spell_mess1("The smith does a quick manuever and his blade slices into his enemy!\n");
  set_spell_mess2("The Smith does a quick manuever and his blade slices into you!\n");
call_out("att",3);
}

att() {
  if(this_object()->query_attack()) {
  if(!present("zantetsuken")) {
  move_object(clone_object("/players/mythos/awep/zantetsuken2.c"),this_object());
  init_command("wield zantetsuken");
}
call_out("att",1);
return 1;}
  call_out("att",1);
return 1;}

monster_died() {
  move_object(clone_object("/players/mythos/awep/zantetsuken.c"),environment(this_object()));
   write_file("/players/mythos/logs/ob",ctime(time())+"\t"+
      (this_object()->query_attack())->query_real_name()+"\t\t"+
      (this_object()->query_attack())->query_level()+"\tsmith\n");
return 0;}
