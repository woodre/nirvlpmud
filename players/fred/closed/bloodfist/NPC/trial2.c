inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define ME "A giant desert fiend"
int a, go;
object gob, *all;

reset(arg){
  ::reset(arg);
  if (!arg){

  set_name("desert fiend");
  set_short("A giant desert fiend");
  set_alias("fiend");
  set_race("creature");
  set_gender("creature");
  set_long(
"This is a giant atrocity that exists with one purpose--  death.  It\n"+
"is about five feet tall, with tough skin a faded brown color which\n"+
"makes it hard to see.  It has two gangly arms each of which have two\n"+
"very long claws which tend to drag on the ground.  It has two pointed\n"+
"ears, with a narrow face.  Its black eyes are very small and hidden.\n"+
"Do not fight this monster unless you are prepared for a tough fight.\n");
  set_level(22);
  set_ac(15);
  set_wc(44+random(4));
  set_wc_bonus(9);
  set_hp(1000);
  set_heal(1,3);
  set_chat_chance(3);
  set_a_chat_chance(3);
  load_chat("A fiend watches you closely.\n");
  load_chat("A fiend claws at the ground.\n");
  load_chat("A fiend wanders slowly about.\n");
  load_chat("A fiend perks its ears up.\n");
  load_chat("A fiend looks off into the sands.\n");
  load_a_chat("A fiend tears into your leg.\n");
  load_a_chat("A fiend jumps into the air.\n");
  load_a_chat("A fiend lunges at you.\n");
  set_dead_ob(this_object());
  call_out("wander", 10);
  }  
}

id(str){ return str == "fiend" || str == "desert fiend" || str == "bftrial_mob"; }

recalc_stats(object nmy){
  if(!nmy) return;
  if(nmy->query_level() > 19)
    hit_point = max_hp = 350;
  else if(nmy->query_level() < 10)
    hit_point = max_hp = 800;
  else if(nmy->query_level() < 14)
    hit_point = max_hp = 850;
  else if(nmy->query_level() < 17)
    hit_point = max_hp = 875;
  else if(nmy->query_level() <= 19 && nmy->query_extra_level() <= 4)
    hit_point = max_hp = 925;
  else if(nmy->query_extra_level() < 10)
    hit_point = max_hp = 975;
  else
    hit_point = max_hp = 1025;
}

void wander(){
  int a;
  call_out("wander", 20);
  if(attacker_ob) return;
  a = random(4);
  switch(a)
  {
  case 0:   init_command("north");  break;
  case 1:   init_command("east");  break;
  case 2:   init_command("south");  break;
  case 3:   init_command("west");  break;
  }
}

void wimpy(){
  string *dirs;
  string str;
  int x, rand;
  if(!present(attacker_ob, environment())) return;
  if(!environment()->query_dest_dir()) return;
  tell_room(environment(), "\n");
  dirs = (mixed) environment()->query_dest_dir();
  rand = random(sizeof(dirs)-1);
  x = rand / 2 * 2;
  str = dirs[x + 1];
  str += "#";
  str += dirs[x];
  this_object()->move_player(str);
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
      BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" holds up his hand as all fighting stops.\n\n\n");
    for(a = 0; a < sizeof(all); a++)
    {
      all[a]->stop_fight();
      all[a]->stop_fight();
      all[a]->stop_hunter();
    }
    return;
  }
  if(!random(13))
  {
    tell_room(environment(),
      "The fiend lunges at "+attacker_ob->query_name()+", grabbing "+
      "onto "+attacker_ob->query_possessive()+" leg.\n"+
      "The fiend begins clawing at "+attacker_ob->query_name()+"'s leg, "+
      "drawing blood!\n"+
      attacker_ob->query_name()+" manages to kick the fiend away.\n",
      ({ attacker_ob }));
    tell_object(attacker_ob,
      "\nThe fiend lunges at you, grabbing onto your leg.\n"+
      "The fiend begins clawing at your leg, drawing blood!\n"+
      "You manage to kick the fiend off you.\n");
    attacker_ob->hit_player(34+random(33));
    hit_point -=3;
  }
  else if(!random(5) && hit_point < 64)
  {
    tell_room(environment(),
      "The fiend lashes out at "+attacker_ob->query_name()+" as it flees!\n");
    attacker_ob->hit_player(35);
    wimpy();
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
    gob->add_free_gems(r[2]);
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


