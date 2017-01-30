inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Jethro Hunter"
object morningstar,breastplate,boots,helm,gob,*all;
int a, go;
string b,c;

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
  helm->set_short("A well made fullhelm");
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
  boots->set_short("Black leather boots");
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
  breastplate->set_name("beastplate");
  breastplate->set_alias("plate");
  breastplate->set_short("A sturdy breastplate");
  breastplate->set_long(
    "This is a well made breastplate with an insignia of swirling\n"+
    "sand on the front.  It looks moderately heavy.\n");
  breastplate->set_ac(0);
  move_object(breastplate, this_object());
  init_command("wear armor");

  morningstar = clone_object("/obj/weapon.c");
  morningstar->set_weight(3);
  morningstar->set_class(20);
  morningstar->set_type("club");
  morningstar->set_alias("morningstar");
  morningstar->set_name("honor of the sand");
  morningstar->set_short("The Honor of the Sand");
  morningstar->set_long(
    "This is an exquisitely crafted morningstar.  It has a black leather\n"+
    "grip at the base of the handle.  The length of it is engraved with\n"+
    "a pattern of blowing sand and small, intricate symbols.  The ball\n"+
    "which hangs from the top is a large ball of steel with narrow spikes\n"+
    "that extend over an inch from the ball itself.\n");
  morningstar->set_value(1400);
  move_object(morningstar, this_object());
  init_command("wield morningstar");

  go = 0;

  set_name(ME);
  set_short(ME+" the Warrior");
  set_long(
ME+" is an experienced fighter and trainer alike.  He stands six feet\n"+
"tall in his body armor.  At his side he holds his signature morningstar,\n"+
"the Honor of the Sand, which rumor says he won from a cruel Dijin many\n"+
"years ago.  As always he is ready for combat.\n");
  set_race("human");
  set_level(21);
  set_ac(10);
  set_ac_bonus(7);
  set_wc(44);
  set_wc_bonus(10);
  set_hp(1000);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(ME+" smiles at you.\n");
  load_chat(ME+" looks around.\n");
  load_chat(ME+" clutches the Honor of the Sand.\n");
  load_chat(ME+" stands idly as he looks around the area.\n");
  load_chat(ME+" briefly examines his morningstar.\n");
  load_chat(ME+" grins.\n");
  load_chat(ME+" cocks his head as though he heard something.\n");
  load_chat(ME+" looks up at the sky.\n");
  load_a_chat(ME+" spits on the ground.\n");
  load_a_chat(ME+" says, \"I hope you are enjoying this.\"\n");
  load_a_chat(ME+" says, \"You are fighting well.\"\n");
  load_a_chat(ME+" dodges to the side.\n");
  load_a_chat(ME+" ducks quickly.\n");
  set_dead_ob(this_object());
}

id(str){ return str == "jethro" || str == "hunter" || str == "warrior"
|| str == "jethro hunter" || str == "bftrial_mob"; }

recalc_stats(object nmy){
  if(!nmy) return;
  if(nmy->query_level() > 19)
    hit_point = max_hp = 350;
  else if(nmy->query_level() < 10)
    hit_point = max_hp = 550;
  else if(nmy->query_level() < 14)
    hit_point = max_hp = 575;
  else if(nmy->query_level() < 17)
    hit_point = max_hp = 600;
  else if(nmy->query_level() <= 19 && nmy->query_extra_level() <= 4)
    hit_point = max_hp = 625;
  else if(nmy->query_extra_level() < 10)
    hit_point = max_hp = 650;
  else
    hit_point = max_hp = 675;
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
    gob->add_free_gems(r[1]);
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
  if(hit_point < 150 && !go)
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
       BOLD+BLK+"\n[A]"+NORM+HIR+">>> "+NORM+ME+" holds up his hand as all fighting stops.\n\n\n");    
    for(a = 0; a < sizeof(all); a++)
    {
      all[a]->stop_fight();
      all[a]->stop_fight();
      all[a]->stop_hunter();
    }
    return;
  }
  if(random(3))
  {
    tell_object(attacker_ob, ME+
      " swings the Honor of the Sand into you...\n");
    tell_room(environment(), ME+" swings the Honor of the Sand into "+
      attacker_ob->query_name()+"...\n", ({ attacker_ob }));
    if(!random(10)){
      tell_object(attacker_ob, BOLD+BLK+
        "\n\tYou stagger backwards as\n"+NORM+RED+
        "\t\t\t--- B L O O D ---\n"+NORM+BOLD+BLK+
        "\t\t\t\tpours from your head!\n"+NORM);
      tell_room(environment(), BOLD+BLK+
        "\n\t"+attacker_ob->query_name()+" staggers backwards as\n"+NORM+RED+
        "\t\t\t--- B L O O D ---\n"+NORM+BOLD+BLK+
        "\t\t\t\tpours from "+attacker_ob->POS+" head!\n"+NORM,
        ({ attacker_ob }));
      attacker_ob->hit_player(50);
      return;
    }
    a = random(5);
    switch(a){
    case 0:
      b = "You stagger from the blow!";
      c = attacker_ob->query_name()+" staggers from the blow!";
      break;
    case 1:
      b = "You crumple beneath the massive blow!";
      c = attacker_ob->query_name()+" crumples beneath the massive blow!";
      break;
    case 2:
      b = "You fall to your feet from the blow!";
      c = attacker_ob->query_name()+" falls to "+attacker_ob->POS+" feet "+
        "from the blow!";
      break;
    case 3:
      b = "You are knocked back by the attack!";
      c = attacker_ob->query_name()+" is knocked back by the attack!";
      break;
    case 4:
      b = "You stumble from the attack!";
      c = attacker_ob->query_name()+" stumbles from the attack!";
      break;
    }
    tell_object(attacker_ob, b+"\n");
    tell_room(environment(), c+"\n", ({ attacker_ob }));
    if(random(2) && alt_attacker_ob && alt_attacker_ob != attacker_ob &&
      present(alt_attacker_ob, environment()))
    {
      tell_room(environment(), ME+" swings the Honor of the Sand into "+
        alt_attacker_ob->query_name()+"!\n");
      alt_attacker_ob->hit_player(13);
    }
  }
}
