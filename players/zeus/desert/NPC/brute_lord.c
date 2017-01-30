#include <ansi.h>
inherit "/obj/monster";
object gold;
int a, b;

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("desert brute lord" );
  set_short(YEL+"The desert brute lord"+NORM);
  set_long(
"This is the largest desert brute you have seen yet.  It is at least ten\n"+
"feet tall, with arms and legs as wide as tree trunks.  It's skin is as\n"+
"tough as stone and virtually the same color.  It seems to barely even\n"+
"notice the sands whipping against it.  It's muscular arms rest against\n"+
"the ground, keeping it upright.  Absolutely do not attack this creature\n"+
"if you are not prepared for a tough fight.\n");
  set_level(27);
  set_ac(27);
  set_wc(58);
  set_wc_bonus(26);
  set_hp_bonus(600);
  set_hp(1500+random(400));
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(1);
  load_chat("The brute breaths slowly.\n");
  load_chat("The brute seems oblivious to the blowing winds.\n");
  load_chat("The brute grunts softly.\n");
  set_dead_ob(this_object());
}

id(str){ return str == "brute" || str == "lord" || str == "brute lord"
          || str == "zeus_brute_lord_npc" || str == "desert lord"
          || str == "desert brute lord" || str == "zeus_inculta_npc"; }

monster_died(){
  tell_room(environment(),
    "You find a cloak and a pile of coins among the remains of the brute.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(6000 + random(8000));
  move_object(gold, environment());
  if(!(random(2)))
    move_object(clone_object("/players/fred/closed/bloodfist/obj/gem.c"), environment());
  gold = clone_object("/players/zeus/desert/OBJ/cloak.c");
  move_object(gold, environment());
  write_file("/players/zeus/log/bigmon",
  ctime(time())+" - "+attacker_ob->query_name()+" [L "+
  attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
  "] killed the Desert Brute Lord.\n");
}


heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  if(present(attacker_ob, environment()) && !random(10))
  {
    tell_room(environment(), 
      "The brute roars up on its hind legs!\n\n\n"+
      "\t\tThe brute comes crushing down on\n\t\t"+attacker_ob->query_name()+
      " with its mighty fists!\n\n",
      ({ attacker_ob }));
    tell_object(attacker_ob,
      "The brute roars up on its hind legs!\n\n\n"+
      "\t\tThe brute comes crushing down on\n"+
      "\t\tyou with its mighty fists!\n\n");
    attacker_ob->hit_player(100+random(70));
  }
  else if(alt_attacker_ob && (alt_attacker_ob != attacker_ob) &&
    present(alt_attacker_ob, environment()) && !random(10))
  {
    tell_room(environment(),
      "The brute swings its large arms sideways "+
      "with incredible force...\n\n\n\t"+
      alt_attacker_ob->query_name()+
      " is annihilated by the visceral blow!\n\n", ({ alt_attacker_ob }));
    tell_object(alt_attacker_ob,
      "The brute swings its large arms sideways "+
      "with incredible force...\n\n\n\t"+
      "You are annihilated by the visceral blow!\n\n");
    alt_attacker_ob->hit_player(100+random(70));
  }
  else if(!random(14))
  {
    tell_room(environment(),
      YEL+"\n\n\tThe sands whirl around the brute lord!\n\n\n"+NORM+
      "The brute lord screams in rage!\n");
    hit_point += 100;
    set_heal(1,4);
    weapon_class += 4;
  }
  else if(present(attacker_ob, environment()) && !random(6))
  {
    tell_room(environment(),
      "The desert fiend roars as it smashes "+
      attacker_ob->query_name()+" with its fists!\n", ({ attacker_ob }));
    tell_object(attacker_ob,
      "The desert fiend roars as it smashes you with its fists!\n");
    a = (int)attacker_ob->query_extra_level();
    b = (int)attacker_ob->query_level();
    if(a > 0 && (a > (b * 2)))
      attacker_ob->hit_player(a);
    else
      attacker_ob->hit_player(b * 2);
  }
  else if((gold = present("corpse", environment())) && !random(4))
  {
    if(gold->is_corpse())
    {
      tell_room(environment(),
        "\nThe desert brute sees a corpse on the ground.\n"+
        "It quickly grabs the corpse and consumes it.\n\n");
      hit_point += 200;
      set_heal(1,1);
      destruct(gold);
    }
  }
}

