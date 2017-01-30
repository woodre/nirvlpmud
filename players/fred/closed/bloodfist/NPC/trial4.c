inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Trugen"
object morningstar,orningstar,breastplate,boots,helm,belt,gob,*all,*arena;
int a, go;
string b,c,d;

reset(arg){
  if(arg) return;
  ::reset(arg);

  arena = ({ 
    "players/fred/closed/bloodfist/r/arena_room1",
    "players/fred/closed/bloodfist/r/arena_room2",
    "players/fred/closed/bloodfist/r/arena_room3",
    "players/fred/closed/bloodfist/r/arena_room4", });

  move_object(clone_object(DIR+"obj/water.c"), this_object());
  move_object(clone_object(DIR+"obj/water.c"), this_object());

  helm = clone_object("/obj/armor.c");
  helm->set_weight(2);
  helm->set_value(2300);
  helm->set_type("helmet");
  helm->set_name("fullhelm");
  helm->set_alt_name("helm");
  helm->set_alias("fullhelm");
  helm->set_short(RED+"A firesign fullhelm"+NORM);
  helm->set_long(
    "This fullhelm protects the wearers entire head.  Steel bars extend\n"+
    "from beneath the eye slits down over the wearers mouth and chin.\n"+
    "At the very top of the helm is a steel point which protrudes into\n"+
    "the air.\n");
  helm->set_ac(0);
  move_object(helm, this_object());
  init_command("wear helmet");

  belt = clone_object("/obj/armor.c");
  belt->set_weight(1);
  belt->set_value(2300);
  belt->set_type("misc");
  belt->set_name("belt");
  belt->set_short(RED+"A firesign belt"+NORM);
  belt->set_long(
    "Firesign belt - beautiful and never to be seen by players.\n");
  belt->set_ac(0);
  move_object(belt, this_object());
  init_command("wear belt");

  boots = clone_object("/obj/armor.c");
  boots->set_weight(2);
  boots->set_value(800);
  boots->set_type("boots");
  boots->set_name("black leather boots");
  boots->set_short(RED+"Firesign boots"+NORM);
  boots->set_long(
    "A pair of black leather boots.  They are well made however would\n"+
    "only provide moderate protection.  They look as though they were\n"+
    "recently cleaned, however still hand sand and dirt on them.\n");
  boots->set_ac(0);
  move_object(boots, this_object());
  init_command("wear boots");

  breastplate = clone_object("/obj/armor.c");
  breastplate->set_weight(4);
  breastplate->set_value(500);
  breastplate->set_type("armor");
  breastplate->set_name("fullplate");
  breastplate->set_alias("plate");
  breastplate->set_short(RED+"Firesign plate"+NORM);
  breastplate->set_long(
    "This is a black fullplate with an insignia of swirling\n"+
    "sand on the front.  It looks moderately heavy.\n");
  breastplate->set_ac(0);
  move_object(breastplate, this_object());
  init_command("wear armor");

  orningstar = clone_object("/obj/weapon.c");
  orningstar->set_weight(3);
  orningstar->set_class(20);
  orningstar->set_type("axe");
  orningstar->set_alias("broadsword");
  orningstar->set_name("bruteslayer");
  orningstar->set_short(BOLD+BLK+ME+"'s Hatchet (left)"+NORM);
  orningstar->set_long(
    "This is an exquisitely crafted broadsword.  "+
    "Nobody should ever see this.\n");
  orningstar->set_value(1400);
  move_object(orningstar, this_object());
  init_command("offwield axe");

  morningstar = clone_object("/obj/weapon.c");
  morningstar->set_weight(3);
  morningstar->set_class(20);
  morningstar->set_type("sword");
  morningstar->set_alias("broadsword");
  morningstar->set_name("bruteslayer");
  morningstar->set_short(BOLD+BLK+ME+"'s Hatchet (right)"+NORM);
  morningstar->set_long(
    "This is an exquisitely crafted broadsword.  "+
    "Nobody should ever see this.\n");
  morningstar->set_value(1400);
  move_object(morningstar, this_object());
  init_command("wield sword");

  go = 0;

  set_name(ME);
  set_short(ME+" the Desert Berserker");
  set_alias("berserker");
  set_long(
ME+" is clad in an elegant suit of armor.  Each piece bares the\n"+
"firesign insignia and seems to emit a very soft, almost dark glow.\n"+
"In each of "+ME+"'s hands is a unique looking hatchet, both of which\n"+
"are as sharp as knives and rather heavy.  "+ME+" walks with a\n"+
"tough confidence that makes you wary to fight him.\n");
  set_race("human");
  set_level(21);
  set_ac(9);
  set_ac_bonus(7);
  set_wc(41);
  set_wc_bonus(10);
  set_hp(1000);
  set_heal(2,1);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(ME+" smiles at you.\n");
  load_chat(ME+" looks around.\n");
  load_chat(ME+" clutches each of his hatchets.\n");
  load_chat(ME+" stands idly as he looks around the area.\n");
  load_chat(ME+" briefly examines his hatchets.\n");
  load_chat(ME+" grins.\n");
  load_chat(ME+" cocks his head as though he heard something.\n");
  load_chat(ME+" looks up at the sky.\n");
  load_a_chat(ME+" spits on the ground.\n");
  load_a_chat(ME+" says, \"I hope you are enjoying this.\"\n");
  load_a_chat(ME+" says, \"You are fighting well.\"\n");
  load_a_chat(ME+" dodges to the side.\n");
  load_a_chat(ME+" ducks quickly.\n");
  set_dead_ob(this_object());
  call_out("hunt", 5);
}

id(str){ return str == "trugen" || str == "berserker" || str == "bftrial_mob"; }

recalc_stats(object nmy){
  if(!nmy) return;
  if(nmy->query_level() > 19)
    hit_point = max_hp = 350;
  else if(nmy->query_level() < 10)
    hit_point = max_hp = 1050;
  else if(nmy->query_level() < 14)
    hit_point = max_hp = 1100;
  else if(nmy->query_level() < 17)
    hit_point = max_hp = 1150;
  else if(nmy->query_level() <= 19 && nmy->query_extra_level() <= 4)
    hit_point = max_hp = 1200;
  else if(nmy->query_extra_level() < 10)
    hit_point = max_hp = 1350;
  else
    hit_point = max_hp = 1500;
}

void combat_spam()
{
  int g;
  string msg;
  g = random(8);
  switch(g)
  {
  case 0:
    msg = ME+" spins to the right with his hatchets extended.\n";
    break;
  case 1:
    msg = ME+" spins to the left with his hatchets extended.\n";
    break;
  case 2:
    msg = ME+" spins forward with his hatchets extended.\n";
    break;
  case 3:
    msg = ME+" spins backward with his hatchets extended.\n";
    break;
  case 4:
    msg = ME+" lunges forward, slashing with his hatchets.\n";
    break;
  case 5:
    msg = ME+" falls backward, slashing wildly with his hatchets.\n";
    break;
  case 6:
    msg = ME+" leaps forward slashing with his hatchets.\n";
    break;
  case 7:
    msg = ME+" snarls at you.\n";
    break;
  }
  tell_room(environment(), msg);
}

void drink_water()
{
  object tmp;
  if((tmp = present("zbf_water", this_object())))
  {
    tell_room(environment(),
      ME+" drinks from a canteen of water.\n");
    hit_point += 50;
    tmp->use_charge();
  }
}

void victory1(object you){
  int *r;
  tell_object(you, ME+" smiles at you.\n");
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" smiles at "+you->query_name()+".\n"); 
  gob = present("bloodfist_gob", you);
  if(gob)
  {
    if(gob->query_trial_to_do())
      gob->ready_to_advance();  /* no longer has a trial to do */
    else
      tell_object(you, ME+" says, \"You didn't have a trial to do.\"\n");
    r = GEM_REWARDS;
    gob->add_free_gems(r[4]);
  }
  else
    tell_object(you, ME+" says, \"You are no Bloodfist.\"\n");
  call_out("victory2", 2, you);
}

void victory2(object you){
  tell_room(environment(), 
    ME+" says, \"Very well done "+you->query_name()+".\"\n");
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" says, \"Very well done "+you->query_name()+".\"\n");
  call_out("victory3", 5, you);
}

void victory3(object you){
  tell_room(environment(),
    ME+" says, \"By defeating me you have proven that you are ready\"\n"+
    "                    \"to advance within the Bloodfist.\"\n");
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" says, \"By defeating me you have proven that you are ready\"\n"+
    "                    \"to advance within the Bloodfist.\"\n");
  call_out("victory4", 8, you);
}

void victory4(object you){
  tell_room(environment(),
    ME+" says, \"Go see Erilon and he will advance "+
    "your rank.\" (bow to him)\n");
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" says, \"Go see Erilon and he will advance "+
    "your rank.\" (bow to him)\n");
  call_out("victory5", 5, you);
}

void victory5(object you){
  tell_room(environment(),
    ME+" says, \"May your skills never dull "+you->query_name()+".\"\n");
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" says, \"May your skills never dull "+you->query_name()+".\"\n");
  call_out("victory6", 3, you);
}

void victory6(object you){
  if(present(you, environment()))
    tell_object(you, ME+" bows to you.\n");
  else
    tell_object(you, ME+" bows to you from afar.\n");
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" bows to "+you->query_name()+".\n");
  call_out("victory7", 4, you);
}

void victory7(object you){
  tell_room(environment(), ME+" leaves the room.\n");
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" leaves the room.\n");
  move_object(this_object(), "/room/void.c");
  destruct(this_object());
}

hunt(){
  if(environment() && attacker_ob && !present(attacker_ob, environment())
    && !attacker_ob->query_ghost()
    && sscanf(file_name(environment(attacker_ob)),
    "players/fred/closed/bloodfist/r/arena_%s", d) && !random(5))
  {
    tell_room(environment(), ME+" goes after "+
      attacker_ob->query_name()+".\n");
    move_object(this_object(), environment(attacker_ob));
    tell_room(environment(), ME+" arrives and lunges at "+
      attacker_ob->query_name()+".\n", ({ attacker_ob }));
    tell_object(attacker_ob, ME+" arrives and lunges at you.\n\n");
    attack_object(attacker_ob);
  }
  else
    call_out("hunt", 14);
}

void move_me(string loc)
{
  all = all_inventory(environment());
  for(a = 0; a < sizeof(all); a++)
  {
    all[a]->stop_fight();
    all[a]->stop_fight();
    all[a]->stop_hunter();
  }
  while(loc == file_name(environment()))
    move_object(this_object(), arena[random(sizeof(arena))]);
}

heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if(go && attacker_ob)
  {
    all = all_inventory(environment());
    for(a = 0; a < sizeof(all); a++)
    {
      all[a]->stop_fight();
      all[a]->stop_fight();
      all[a]->stop_hunter();
    }
  }
  if(!attacker_ob) return;
  if(!present(attacker_ob, environment())) return;
  if(hit_point < 200 && !go)
  {
    go = 1;
    all = all_inventory(environment());

    if(ARENA_DAEMON->gfp())
      call_out("victory1", 3, ARENA_DAEMON->gfp());
    else if(attacker_ob->is_player())
      call_out("victory1", 3, attacker_ob);
    else if(alt_attacker_ob->is_player())
      call_out("victory1", 3, alt_attacker_ob);
    else {
      tell_room(environment(), 
      "\n\n"+ME+" says, \"Well someone won but i'm not sure who.\"\n"+
      "\"This is a bug, contact Fred\"\n\n\n\n");

      write_file("/players/fred/closed/bloodfist/log/err",
      ctime(time())+" "+ME+" died but the victor was unknown.\n");
    }

    tell_room(environment(), 
      "\n"+ME+" holds up his hand as all fighting stops.\n\n\n");
   
    tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" holds up his hand as all fighting stops.\n\n\n");

    for(a = 0; a < sizeof(all); a++)
    {
      all[a]->stop_fight();
      all[a]->stop_fight();
      all[a]->stop_hunter();
    }
    return;
  }
  if(random(3) && !attacker_ob->query_ghost())
  {
    already_fight = 0;
    ::attack();
  }
  if(!random(7))
  {
    tell_object(attacker_ob,
      "\n"+ME+" rips into you with his hatchets!\n\n");
    tell_room(environment(),
      "\n"+ME+" rips into "+attacker_ob->query_name()+
      " with his hatchets!\n\n", ({ attacker_ob }));
    attacker_ob->hit_player(30);
  }
  if(!random(2))
    combat_spam();
  if(hit_point < 600 && !random(4))
    drink_water();
  else if(hit_point < 600 && !random(5))
  {
    tell_room(environment(), ME+" darts quickly from the room.\n");
    move_me(file_name(environment()));
    hit_point += 66;
  }
}

query_bf_trialmob(){ return 1; }

