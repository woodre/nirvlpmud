inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Christian"
object morningstar,breastplate,boots,helm,gob,*all;
int a, go,s;
string b,c,d;

reset(arg){
  if(arg) return;
  ::reset(arg);

  helm = clone_object("/obj/armor.c");
  helm->set_weight(2);
  helm->set_value(2300);
  helm->set_type("helmet");
  helm->set_name("fullhelm");
  helm->set_alt_name("helm");
  helm->set_alias("fullhelm");
  helm->set_short(BOLD+BLK+"A black fullhelm"+NORM);
  helm->set_long(
    "This fullhelm protects the wearers entire head.  Steel bars extend\n"+
    "from beneath the eye slits down over the wearers mouth and chin.\n"+
    "At the very top of the helm is a steel point which protrudes into\n"+
    "the air.\n");
  helm->set_ac(0);
  move_object(helm, this_object());
  init_command("wear helmet");

  boots = clone_object("/obj/armor.c");
  boots->set_weight(2);
  boots->set_value(800);
  boots->set_type("boots");
  boots->set_name("black leather boots");
  boots->set_short(BOLD+BLK+"Black metal boots"+NORM);
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
  breastplate->set_short(BOLD+BLK+"A black fullplate"+NORM);
  breastplate->set_long(
    "This is a black fullplate with an insignia of swirling\n"+
    "sand on the front.  It looks moderately heavy.\n");
  breastplate->set_ac(0);
  move_object(breastplate, this_object());
  init_command("wear armor");

  morningstar = clone_object("/obj/weapon.c");
  morningstar->set_weight(3);
  morningstar->set_class(20);
  morningstar->set_type("sword");
  morningstar->set_alias("broadsword");
  morningstar->set_name("bruteslayer");
  morningstar->set_short(BOLD+BLK+ME+"'s BruteSlayer"+NORM);
  morningstar->set_long(
    "This is an exquisitely crafted broadsword.  "+
    "Nobody should ever see this.\n");
  morningstar->set_value(1400);
  move_object(morningstar, this_object());
  init_command("wield bruteslayer");

  go = 0;
  s = 10;

  set_name(ME);
  set_short(ME+" the Brute Lord Slayer");
  set_alias("slayer");
  set_long(
ME+" is a hulk of a man.  His muscles bulge beneath his black armor\n"+
"which covers him from head to toe.  At his side is his sword the\n"+
"beautiful black BruteSlayer.  He looks like a worthy opponent.\n");
  set_race("human");
  set_level(21);
  set_ac(12);
  set_ac_bonus(7);
  set_wc(24);
  set_wc_bonus(10);
  set_hp(1000);
  set_heal(1,1);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(ME+" smiles at you.\n");
  load_chat(ME+" looks around.\n");
  load_chat(ME+" clutches the BruteSlayer.\n");
  load_chat(ME+" stands idly as he looks around the area.\n");
  load_chat(ME+" briefly examines his BruteSlayer.\n");
  load_chat(ME+" grins.\n");
  load_chat(ME+" cocks his head as though he heard something.\n");
  load_chat(ME+" looks up at the sky.\n");
  load_a_chat(ME+" spits on the ground.\n");
  load_a_chat(ME+" says, \"I hope you are enjoying this.\"\n");
  load_a_chat(ME+" says, \"You are fighting well.\"\n");
  load_a_chat(ME+" dodges to the side.\n");
  load_a_chat(ME+" ducks quickly.\n");
  set_dead_ob(this_object());
  call_out("hunt", 15);
}

id(str){ return str == "christian" || str == "slayer" || str == "lord"
|| str == "bftrial_mob"; }

recalc_stats(object nmy){
  if(!nmy) return;
  if(nmy->query_level() > 19)
    hit_point = max_hp = 350;
  else if(nmy->query_level() < 10)
    hit_point = max_hp = 900;
  else if(nmy->query_level() < 14)
    hit_point = max_hp = 925;
  else if(nmy->query_level() < 17)
    hit_point = max_hp = 950;
  else if(nmy->query_level() <= 19 && nmy->query_extra_level() <= 4)
    hit_point = max_hp = 975;
  else if(nmy->query_extra_level() < 10)
    hit_point = max_hp = 1000;
  else
    hit_point = max_hp = 1025;
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
    gob->add_free_gems(r[3]);
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
    "players/fred/closed/bloodfist/r/arena_%s", d) && !random(3))
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
    call_out("hunt", 20+random(8));
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
  if(s >= 0 && !random(2))
  {
    tell_room(environment(),
      "\n"+ME+" attacks with a passionate fury!\n"+
      "  "+ME+" drives the "+BOLD+BLK+"BruteSlayer"+NORM+" into "+
      attacker_ob->query_name()+"...\n"+
      "  "+RED+"Blood pours from the wound!\n\n"+NORM,
      ({ attacker_ob }));
    tell_object(attacker_ob,
      "\n"+ME+" attacks with a passionate fury!\n"+
      "  "+ME+" drives the "+BOLD+BLK+"BruteSlayer"+NORM+" into "+
      "you...\n"+
      "  "+RED+"Blood pours from the wound!\n\n"+NORM);
    if(attacker_ob->query_level() <= 10)
      attacker_ob->hit_player(35+random(26));
    else if(attacker_ob->query_level() < 16)
      attacker_ob->hit_player(40+random(31));
    else if(attacker_ob->query_level() >= 16)
      attacker_ob->hit_player(45+random(35));
    s--;
  }
  else if(s <= 0 && !random(12))
  {
    tell_room(environment(),
      HIW+ME+" is covered in a white healing light.\n"+NORM);
    if(attacker_ob->query_level() <= 10)
      hit_point += 45+random(35);
    else if(attacker_ob->query_level() < 16)
      hit_point += 50+random(40);
    else if(attacker_ob->query_level() >= 16)
      hit_point += 55+random(45);
    s++;
  }
}
