#include "/players/mythos/closed/guild/def.h"
inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("ryo");
  set_short();
  set_alias("ryo");
  set_race("spirit");
  set_long("A bodiless head of a woman.\n"+
    "She died in tormet and she now longs for life again.\n"+
    "It is said that should she drink of the blood of the\n"+
    "Jinro- half man half beast, she will live again.\n");
  set_hp(550);
  set_level(20);
  set_al(-500);
  set_wc(40);
  set_ac(18);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("Something whispers in your ear, 'I need blood...'\n");
  load_chat("The darkness presses down on you like a heavy weight.  You feel tired...\n");
  load_a_chat("Something is really, really WRONG!\n");

  set_chance(30);
  set_spell_dam(20);
  set_spell_mess1("Something is really, really WRONG!\n");
  set_spell_mess2("The head flies at you... it passes by and you feel a great pain in your neck!\n"+
    "Your Blood is slurped up by the Ryo.\n");

  gold=clone_object("obj/money");
  gold->set_money(random(4000)+3000);
        /*  Point of note: 3000 +random(4000)  averages 5000 coins i.e. legal limit */
  move_object(gold,this_object());
}

monster_died() {
string msg,type_s;
  if(present(fear,this_object()->query_attack())) {
  switch(random(3)) {
    case 0:
    present(fear,this_object()->query_attack())->set_rev(1);
    msg = "Suddenly you feel a jolt of energy!\nYou can now reverse damage!\n"+
          "Type <reverse>\n";
    type_s = "reverse";
    break; 
    case 1: 
    present(fear,this_object()->query_attack())->set_sim(1);
    msg = "You feel strange.... \nThe Power to Deceive is at your fingertips!\n"+
          "Type <simulacrum>\n";
    type_s = "simulacrum";
    break; 
    case 2: 
    present(fear,this_object()->query_attack())->set_send(1);
    msg = "DEATH reaches out and gives you power!\nType <creeping_doom>\n";
    type_s = "creeping_doom";
    break; 
  }
    present(fear,this_object()->query_attack())->save_dark();
    command("uu",this_object()->query_attack());
    tell_object(this_object()->query_attack(),msg);
  write_file("/players/mythos/closed/guild/task_spell",
    ctime(time())+" "+(this_object()->query_attack())->query_real_name()+
    "  "+type_s+"\n");
  }
}

#include "/players/mythos/amon/hb_ag.h"
