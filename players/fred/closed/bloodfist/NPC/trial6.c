inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Bruetus Faust"
#define WNAME HIC+"StormHane"+NORM+" the "+BOLD+BLK+"Warhammer"+NORM
object morningstar,breastplate,boots,helm,gob,*all;
int a, go;
string b,c;

reset(arg){
  if(arg) return;
  ::reset(arg);

  for(a = 0; a < 3; a++)
    move_object(clone_object(DIR+"obj/water.c"), this_object());

  helm = clone_object("/obj/armor.c");
  helm->set_weight(2);
  helm->set_value(2300);
  helm->set_type("helmet");
  helm->set_name("fullhelm");
  helm->set_alt_name("helm");
  helm->set_alias("fullhelm");
  helm->set_short("Death Casque");
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
  boots->set_short("Black Boots");
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
  breastplate->set_short("Death Cage");
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
  morningstar->set_name("stormhane");
  morningstar->set_short(WNAME+" (wielded) [gem of battle rites]");
  morningstar->set_long(
    "This is an exquisitely crafted warhammer.  It has a black leather\n"+
    "grip at the base of the handle.  The length of it is engraved with\n"+
    "a pattern of blowing sand and small, intricate symbols.  The ball\n"+
    "which hangs from the top is a large ball of steel with narrow spikes\n"+
    "that extend over an inch from the ball itself.\n");
  morningstar->set_value(1400);
  move_object(morningstar, this_object());

  go = 0;

  set_name(ME);
  set_short("Lord "+ME+" of the Bloodfist");
  set_long(
"The man before you is incredibly intimidating.  "+ME+" is a wearing\n"+
"a black suit of armor the likes of which you have never seen before.\n"+
"It reminds you of bones jutting out, almost like an exoskeleton.  His\n"+
"head is similarly protected behind his helmet, only blonde hair can be\n"+
"see in a few spots.  In his fists he carries the mighty warhammer\n"+
"StormHane which looks like it could easily crush your bones with a\n"+
"single blow.  You had best be careful.\n");
  set_race("human");
  set_level(21);
  set_ac(17);
  set_wc(38);
  set_hp(1000);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(ME+" looks at you.\n");
  load_chat(ME+" looks around.\n");
  load_chat(ME+" clutches the StormHane.\n");
  load_chat(ME+" stands idly as he looks around the area.\n");
  load_chat(ME+" briefly examines his warhammer.\n");
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

id(str){ return str == "bruetus" || str == "lord" || str == "faust"
|| str == "bruetus faust" || str == "no_bfstudy" || str == "bftrial_mob"; }

recalc_stats(object nmy){
  if(!nmy) return;
  if(nmy->query_level() > 19)
    hit_point = max_hp = 350;
  else if(nmy->query_level() < 10)
    hit_point = max_hp = 1000;
  else if(nmy->query_level() < 14)
    hit_point = max_hp = 1050;
  else if(nmy->query_level() < 17)
    hit_point = max_hp = 1100;
  else if(nmy->query_level() <= 19 && nmy->query_extra_level() <= 4)
    hit_point = max_hp = 1150;
  else if(nmy->query_extra_level() < 10)
    hit_point = max_hp = 1200;
  else
    hit_point = max_hp = 1250;
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

void study_response(object q){
  if(!environment()) return;
  if(!q) return;
  tell_room(environment(),
    "\n"+ME+" say, \"Don't waste my time "+q->query_name()+".\n", ({ q }));
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
    gob->add_free_gems(r[6]);
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
  if(random(2))
  {
    a = random(8);
    switch(a)
    {
    case 0:
      tell_room(environment(), ME+"'s "+WNAME+" crackles with energy.\n");
      break;
    case 1:
      tell_room(environment(), "An arc of lightning jumps off of "+
        ME+"'s "+WNAME+".\n");
      break;
    case 2:
      tell_room(environment(), ME+" crushes "+attacker_ob->query_name()+
        " with his "+WNAME+"!\n", ({ attacker_ob }));
      tell_object(attacker_ob, ME+" crushes you with his "+WNAME+"!\n");
      attacker_ob->hit_player(25);
      break;
    case 3:
      tell_room(environment(), ME+"'s "+WNAME+
        " explodes with a sudden burst of energy.\n");
      break;
    case 4:
      tell_room(environment(), ME+" swings his "+WNAME+
        " as lightning crackles.\n");
      break;
    case 5:
      tell_room(environment(), ME+" swings his "+WNAME+
        " into "+attacker_ob->query_name()+"!\n", ({ attacker_ob }));
      tell_object(attacker_ob, ME+" swings his "+WNAME+" into you!\n");
      attacker_ob->hit_player(20);
      break;
    case 6:
      tell_room(environment(), ME+" holds his "+WNAME+
        " overhead as lightning surges.\n");
      break;
    case 7:
      tell_room(environment(), ME+" watches "+attacker_ob->query_name()+
        "'s movements closely.\n",  ({ attacker_ob }));
      tell_object(attacker_ob, ME+" watches your movements closely.\n");
      break;
    }
    a = random(6);
    switch(a)
    {
    case 0:
      tell_room(environment(), ME+" laughs at your movements.\n");
      break;
    case 1:
      tell_room(environment(), ME+" dodges your attack.\n");
      break;
    case 2:
      tell_room(environment(), ME+" sidesteps your attack.\n");
      break;
    case 3:
      tell_room(environment(), ME+" jumps backwards momentarily.\n");
      break;
    case 4:
      tell_room(environment(), ME+" clutches "+WNAME+" tightly.\n");
      break;
    case 5:
      tell_room(environment(), ME+" growls deeply at "+
        attacker_ob->query_name()+".\n", ({ attacker_ob }));
      tell_object(attacker_ob, ME+" growls deeply at you.\n");
      break;
    }
  }
  if(!random(5) && !attacker_ob->query_ghost())
  {
    if(!random(3))
      tell_room(environment(), ME+" moves with quickly to strike.\n");
    already_fight = 0;
    ::attack();
  }
  if(!random(15))
    tell_room(environment(), ME+" drives himself to fight harder!\n");
  else if(!random(14))
  {
    tell_room(environment(), 
      "\n"+ME+"'s "+WNAME+" explodes in a mass of lightning!\n"+
      ME+" brings his warhammer down into "+attacker_ob->query_name()+
      " with a sickening crunch!\n\n\n"+attacker_ob->query_name()+
      " stumbles backwards from the blow.\n\n", ({ attacker_ob }));
    tell_object(attacker_ob,
      "\n"+ME+"'s "+WNAME+" explodes in a mass of lightning!\n"+
      ME+" brings his warhammer down into you with a sickening crunch!\n"+
      "\n\nYou stumble backwards from the blow.\n\n");
    attacker_ob->hit_player(60);
    attacker_ob->hit_player(30, "other|electric");
  }
  else if(!random(14))
  {
    tell_room(environment(),
      "\n\n"+ME+" leaps into the air...\n\n\n\t"+
      "The "+WNAME+" comes smashing into "+attacker_ob->query_name()+
      "'s body from above!\n\n\n"+ME+
      " laughs as he jumps backwards away from "+
      attacker_ob->query_name()+".\n", ({ attacker_ob }));
    tell_object(attacker_ob,
      "\n\n"+ME+" leaps into the air...\n\n\n\t"+
      "The "+WNAME+" comes smashing into your body from above!\n\n\n"+
      ME+" laughs as he jumps backwards away from you.\n");
    attacker_ob->hit_player(50+random(40));
  }
  if(hit_point < 600 && !random(5))
    drink_water();
  if(alt_attacker_ob && attacker_ob != alt_attacker_ob && !random(3))
  {
    tell_room(environment(), "\n"+
      ME+" crushes "+alt_attacker_ob->query_name()+" with his "+
      WNAME+"!\n\n");
    alt_attacker_ob->hit_player(30);
  }
}

query_bf_trialmob(){ return 1; }

