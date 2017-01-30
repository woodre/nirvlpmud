inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Atheos"
object axe,tunic,boots,arena,gob,*all;
int a, fighting, go, *lvl_reqs;
string d;

reset(arg){
  if(arg) return;
  ::reset(arg);

  set_no_clean(1);
  arena = "players/fred/closed/bloodfist/r/arena";
  lvl_reqs =({ 7,10,13,15,17,19,22,24 }); /*lvl req to advance to next glvl*/

  for(a = 0; a < 2; a++)
    move_object(clone_object(DIR+"obj/water.c"), this_object());

  boots = clone_object("/obj/armor.c");
  boots->set_weight(2);
  boots->set_value(800);
  boots->set_type("boots");
  boots->set_name("leather boots");
  boots->set_short("An old pair of leather boots");
  boots->set_long(
    "These old boots look as though they have seen many adventures.\n"+
    "Each one has lost almost all of its rigidity because of how much\n"+
    "they have been used.  You guess that the owner wouldn't have\n"+
    "traded them for anything in the world.\n");
  boots->set_ac(1);
  move_object(boots, this_object());
  init_command("wear boots");

  tunic = clone_object("/obj/armor.c");
  tunic->set_weight(2);
  tunic->set_value(500);
  tunic->set_type("armor");
  tunic->set_name("leather tunic");
  tunic->set_alias("tunic");
  tunic->set_short("An old leather tunic");
  tunic->set_long(
    "This is a generic looking leather tunic.  The edges are frayed\n"+
    "and in many places it looks as though it is about to split.\n");
  tunic->set_ac(2);
  move_object(tunic, this_object());
  init_command("wear tunic");

  axe = clone_object("/obj/weapon.c");
  axe->set_weight(6);
  axe->set_class(20);
  axe->set_type("axe");
  axe->set_name("battleaxe");
  axe->set_short("A massive battleaxe");
  axe->set_long(
    "This massive battleaxe was once wielded by the warrior Atheos\n"+
    "of the Bloodfist.  It has a thick wood handle lined with\n"+
    "scratches and grooves.  The bulbous metal head is enourmous,\n"+
    "with a razor sharp blade.  There are a few splotches of dried\n"+
    "blood on the blade of the battleaxe.\n");
  axe->set_value(1400);
  move_object(axe, this_object());
  init_command("wield axe");

  set_name("atheos");
  set_alias("beastmaster");
  set_short(ME+" the Beastmaster");
  set_long(
ME+" is a massive hulk of a man.  He seems to tower over all the people\n"+
"around him.  Clad in an old leather outfit he dons a massive battleaxe\n"+
"that looks as though it must weigh at least 30 pounds.  His chiseled\n"+
"face is dirty yet he exudes an incredible aura of strength and power.\n"+
"You find it hard not to be captivated by this hulking giant of a man.\n");
  set_race("human");
  set_level(23);
  set_ac(14);
  set_ac_bonus(3);
  set_wc(80);
  set_wc_bonus(10);
  set_hp(4000);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(ME+" smiles at you.\n");
  load_chat(ME+" looks around.\n");
  load_chat(ME+" clutches his battleaxe.\n");
  load_chat(ME+" stands idly as he looks around the area.\n");
  load_chat(ME+" briefly examines the head of his battleaxe.\n");
  load_chat(ME+" grins.\n");
  load_chat(ME+" cocks his head as though he heard something.\n");
  load_chat(ME+" looks up at the sky.\n");
  load_a_chat(ME+" spits on the ground.\n");
  load_a_chat(ME+" says, \"You will gain nothing from my death.\"\n");
  load_a_chat(ME+" dodges to the side.\n");
  load_a_chat(ME+" ducks quickly.\n");
  set_dead_ob(this_object());
  call_out("hunt", 7);

  fighting = 0;
  go = 0;
}

id(str){ return str == name || str == alias || str == "zbm0x2"
|| str == "no_bfstudy" || str == "bftrial_mob_atheos"; }

monster_died(){
  write_file("/players/fred/closed/bloodfist/log/NPC",
  ctime(time())+" - "+attacker_ob->query_name()+
  " [L "+attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
  "] killed "+ME+".\n");
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

void dead_get2(object you)
{
  tell_room(environment(you),
    ME+" says, \"Well, there you go "+you->query_name()+
    ".  Let me know when\"\n"+
    "             \"you're ready to fight in the arena again.\"\n\n"+
    ME+" leaves the room.\n");
    fighting = 0;
  move_object(this_object(), "/players/fred/closed/bloodfist/r/arena.c");
}

void dead_get1(object you)
{
  tell_object(you, "You follow "+ME+"...\n\n");
  you->move_player("away#/players/fred/closed/bloodfist/r/backroom.c");
  ARENA_DAEMON->rm_dead(you->query_real_name());
  call_out("dead_get2", 3, you);
}

void bow_back(object you)
{
  if(you && present(you, environment()))
  {
    if(gob = present("bloodfist_gob", you))
    {
      if(ARENA_DAEMON->query_dead(you->query_real_name()))
      {
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        ARENA_DAEMON->move_arena_contents();
        tell_room(environment(), ME+" says, \"Follow me "+
          you->query_name()+".\"\n\n"+
          ME+" leaves the room.\n");
        move_object(this_object(), DIR+"r/backroom.c");
        call_out("dead_get1", 1, you);
      }
      else {
        tell_object(you, ME+" bows to you.\n");
        tell_room(environment(), ME+" bows to "+you->query_name()+".\n",
          ({ you }));
      }
    }
    else {
      tell_object(you, ME+" glances at you.\n");
      tell_room(environment(), ME+" glances at "+you->query_name()+
        " stonily.\n",
        ({ you }));
    }
  }
}

void study_response(object q){
  if(!environment()) return;
  if(!q) return;
  tell_room(environment(),
    "\n"+ME+" laughs heartily at "+q->query_name()+".\n", ({ q }));
  tell_object(q, "\n"+ME+" laughs heartily at you.\n");
}

battle_info(object you){
  string yn;
  int c;
  if(!you) return;
  yn = you->query_name();
  if(!present(you, environment()))
  {
    tell_object(you, ME+" tells you, \"You must come to me "+yn+".\"\n");
    return;
  }
  if(!(gob = present("bloodfist_gob", you)))
  {
    tell_room(environment(), 
      ME+" says, \"You can not fight "+yn+
      "... you are no Bloodfist.\"\n");
    return;
  }
  if(!gob->query_trial_to_do())
  {
    tell_room(environment(), ME+
      " says, \"You aren't ready to fight anything "+yn+".\"\n");
    return;
  }
  if(gob->query_glevel() == 0)
  {
    tell_object(you,
      ME+" says, \"You will be fighting Jethro Hunter, one of our more\"\n"+
      "                 \"experienced fighters.  He will try and match your\"\n"+
      "                 \"strength.  It won't be an easy fight, but if you\"\n"+
      "                 \"are prepared then you should do just fine against him.\"\n");
  }
  else if(gob->query_glevel() == 1)
  {
    tell_object(you,
      ME+" says, \"To advance your rank you must defeat a desert fiend. \"\n"+
      "                 \"We captured it from the desert and it is not very\"\n"+
      "                 \"happy to be here.  They can be pretty nasty, so\"\n"+
      "                 \"watch yourself in there.\"\n");
  }
  else if(gob->query_glevel() == 2)
  {
   tell_object(you,
     ME+" says, \"To advance to guild rank 3 you must defeat Christian.\"\n"+
     "                 \"He is a powerful warrior and will attack with an\"\n"+
     "                 \"incredible fury, so watch yourself.  If you can hold\"\n"+
     "                 \"off long enough you should be fine.\"\n");
  }
  else if(gob->query_glevel() == 3)
  {
    tell_object(you,
      ME+" says, \"You must defeat Trugen the Berserker to advance to\"\n"+
      "                 \"guild rank 4.  He is a masterful fighter and will\"\n"+
      "                 \"strike quickly, so be ready for him.  I've never\"\n"+
      "                 \"seen any other man so good with two hatchets.\"\n");
  }
  else if(gob->query_glevel() == 4)
  {
   tell_object(you,
     ME+" says, \"You will be fighting me to advance your rank this time.\"\n"+
     "                 \"Don't worry, I won't be too tough on you.\"\n");
  }
  else if(gob->query_glevel() == 5)
  {
   tell_object(you,
     ME+" says, \"You will have to fight Lord Bruetus the Bloodfist in order\"\n"+
     "                 \"to advance to rank 6.  Bruetus is a very powerful warrior\"\n"+
     "                 \"from centuries ago.  He has a terrible temper and attacks\"\n"+
     "                 \"mercilessly.  Be careful in there.\"\n");
  }
  else if(gob->query_glevel() == 6)
  {
   tell_object(you,
     ME+" says, \"Your next opponent will be Haemon the Night Lurker. Haemon\"\n"+
     "                 \"draws his power from staying out of sight.  He's hard to\"\n"+
     "                 \"locate so stay focused.\"\n");
  }
  else if(gob->query_glevel() == 7)
  {
   tell_object(you,
     ME+" says, \"Your final opponent will be Erilon.  "+
     "Good luck "+yn+".\"\n");
  }
}

advance(object you){
  object gob, *in, nmy;
  string yn;
  int c, d;
  if(!you) return;
  yn = you->query_name();
  if(!present(you, environment()))
  {
    tell_object(you, ME+" tells you, \"You must come to me "+yn+".\"\n");
    return;
  }
  if(!(gob = present("bloodfist_gob", you)))
  {
    tell_room(environment(), 
      ME+" says, \"You can not fight "+yn+
      "... you are no Bloodfist.\"\n");
    return;
  }
  if(gob->query_glevel() >= 8)
  {
    tell_room(environment(), 
      ME+" says, \"You are already guild level 8 "+yn+".\"\n");
    return;
  }
  if((c = gob->query_glevel_togo()) > 0)
  {
    tell_room(environment(), 
      ME+" says, \"You are not yet ready for your trial "+yn+".\"\n");
    return;
  }
  if(c <= 0)      /* good to go xp wise */
  {
    if((you->query_level() + you->query_extra_level())   /* LEVEL CHECK */
      < lvl_reqs[(d = gob->query_glevel())])
    {
      if(d >= 6) /* advancing to 7 or 8 has xlvl req */
        return (notify_fail(
        ME+" says, \"You need to be at least level 19+"+(d-19)+
        " to fight in the arena.\"\n"+
        "             \"I wouldn't want to see you get hurt.\"\n"),0);
      else
        return (notify_fail(
        ME+" says, \"You need to be at least level "+d+
        " to fight in the arena.\"\n"+
        "             \"I wouldn't want to see you get hurt.\"\n"),0);
    }
    if(gob->query_trial_to_do()) /* has spoken with Erilon */
    {
      if(in = ARENA_DAEMON->occupants())  /* arena is full */
      {
        if(sizeof(in) == 1)
          tell_room(environment(),
            ME+" says, \"Sorry, "+in[0]->query_name()+" is "+
            "in the arena right now.\"\n");
        else {
          tell_room(environment(), ME+" says, \"Sorry, ");
          for(c = 0; c < sizeof(in); c++)
            tell_room(environment(), in[c]->query_name()+" ");
          tell_room(environment(), "are in it.\"\n");
        }
        return;
      }
      else
        ARENA_DAEMON->clean_arena();

      if(gob->query_glevel() == 0)
        nmy = clone_object(DIR+"NPC/trial1.c"); /* Jethro Hunter */
      else if(gob->query_glevel() == 1)
        nmy = clone_object(DIR+"NPC/trial2.c"); /* Desert Fiend */
      else if(gob->query_glevel() == 2)
        nmy = clone_object(DIR+"NPC/trial3.c"); /* Christian */
      else if(gob->query_glevel() == 3)
        nmy = clone_object(DIR+"NPC/trial4.c"); /* */
      else if(gob->query_glevel() == 4)
        nmy = this_object();                    /* Atheos (beastmaster) */
      else if(gob->query_glevel() == 5)
        nmy = clone_object(DIR+"NPC/trial6.c"); /* */
      else if(gob->query_glevel() == 6)
        nmy = clone_object(DIR+"NPC/trial7.c"); /* */
      else if(gob->query_glevel() == 7)
        nmy = find_living("erilon");            /* Erilon (elder) */
      else if(gob->query_glevel() == 8)
      {
        tell_room(environment(),
          ME+" says, \"You have advanced to the highest rank "+yn+".\"\n");
        return;
      }
      else { /* error */
        tell_room(environment(),
          ME+" asks, \"What's going on?\"\n");
        return;
      }
      if(nmy)
      {
        if(gob->query_glevel() == 4)
        {
          tell_room(environment(), "Atheos leaves into the arena.\n");
          fighting = 1;
        }
        else if(gob->query_glevel() == 7)
        {
          if(!nmy)
            nmy = clone_object(DIR+"NPC/elder.c");
          else {
            if(nmy->query_busy())
            {
              tell_room(environment(),
                "Atheos says, \"Erilon is busy right now, "+
                "try again in a minute.\"\n");
              return;
            }
            else {
              tell_room(environment(nmy),
              "Erilon says, \"I must now fight "+you->query_name()+".  "+
              "I will return shortly.\"\n");
              nmy->toggle_fighting();
              nmy->set_ok(1);
            }
          }
          nmy->toggle_fighting();
          nmy->set_ok(1);
        }
        move_object(nmy, "/players/fred/closed/bloodfist/r/arena_room4.c");
        tell_room(environment(nmy), nmy->short()+" steps into the arena.\n");
        nmy->recalc_stats(you);
      }

      arena->ready(you);        /* lock doors for 60 seconds */
      if(gob->query_glevel() == 4)
      {
        tell_object(you,
          ME+" tells you, \"I'm ready when you are, "+yn+".\"\n");
      }
      else {
        tell_room(environment(),
          ME+" says, \"Alright, the arena is ready "+yn+
          ".  Enter when you are.\"\n"+
          "             \"I'll keep it ready for 60 seconds.\"\n"+
          "             \"All you have to do is 'enter' the 'arena'.\"\n");
      }

      return;
    }
    else {
      tell_room(environment(), 
        ME+" says, \"You must first speak with "+
        "Erilon and gain his approval.\"\n");
    }
  }
}

void catch_tell(string str)
{
  string t1, t2, t3;
  object me;
  if(fighting) return;
  if(sscanf(str, "%sbows%syou.", t1, t2) == 2)
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("bow_back", 1, me);
  }
  else if(sscanf(str, "%s: im ready%s", t1, t2) == 2 ||
    sscanf(str, "%s: advance%s", t1, t2) == 2 ||
    sscanf(str, "%s: I am ready%s", t1, t2) == 2 ||
    sscanf(str, "%s: I'm ready%s", t1, t2) == 2 ||
    sscanf(str, "%s: i'm ready%s", t1, t2) == 2)
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("advance", 1, me);
  }
  else if(sscanf(str, "%sdied%s", t1, t2) ||
    sscanf(str, "%sdead%s", t1, t2))
  {
    me = this_player();
    if(ARENA_DAEMON->query_dead(me->query_real_name()))
    {
      tell_room(environment(), ME+" says, \"You must bow to me "+
        me->query_name()+".\"\n");
      fighting = 0;
    }
  }
  else if(sscanf(str, "%s: what %s fight%s", t1, t2, t3) == 3
    || sscanf(str, "%s: who %s fight%s", t1, t2, t3) == 3)
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("battle_info", 1, me);
  }
}

recalc_stats(object nmy){
  if(!nmy) return;
  if(nmy->query_level() > 19)
    hit_point = max_hp = 350;
  else if(nmy->query_level() < 10)
    hit_point = max_hp = 1600;
  else if(nmy->query_level() < 14)
    hit_point = max_hp = 1700;
  else if(nmy->query_level() < 17)
    hit_point = max_hp = 1800;
  else if(nmy->query_level() <= 19 && nmy->query_extra_level() <= 4)
    hit_point = max_hp = 1900;
  else if(nmy->query_extra_level() < 10)
    hit_point = max_hp = 2000;
  else
    hit_point = max_hp = 2100;
  weapon_class = 44;
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
    gob->add_free_gems(r[5]);
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
    "             \"to advance within the Bloodfist.\"\n");
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" says, \"By defeating me you have proven that you are ready\"\n"+
    "             \"to advance within the Bloodfist.\"\n");
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
  hit_point = max_hp;
  weapon_class = 80;
  move_object(this_object(), "/players/fred/closed/bloodfist/r/arena.c");
}

hunt(){
  if(environment() && attacker_ob && fighting && 
    !present(attacker_ob, environment()) && !attacker_ob->query_ghost()
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
  else if(environment() && hit_point < max_hp && fighting
    && sscanf(file_name(environment(this_object())),
    "players/fred/closed/bloodfist/r/arena_%s", d))
  {
    if(ARENA_DAEMON->gfp() == 0)
    {
      move_object(this_object(), DIR+"r/arena.c"); /* go home */
      tell_room(environment(),
        ME+" walks into the room and smiles.\n");
      fighting = 0;
      hit_point = max_hp;
      weapon_class = 80;
    }
  }
  else
    call_out("hunt", 7);
}

next_time(object x)
{
  if(!present(x, environment(this_object())))
  {
    tell_object(x,
     "\n"+ME+" tells you: \"Good try.  Better luck next time.\"\n");
  }
    tell_object(x,
     ME+" says, \"Good try. Better luck next time.\"\n");  
    call_out("next_time1", 4, x);
}

next_time1(object x)
{
  if(!present(x, environment(this_object())))
  {
    tell_object(x,
     ME+" tells you: \"Don't forget to come back to and bow to me to get your stuff.\"\n");
  }
    tell_object(x,
     ME+" says, \"Don't forget to come back to and bow to me to get your stuff.\"\n");    
    call_out("next_time2", 5, x);
}

next_time2(object x)
{
  tell_room(environment(),
   ME+" bows and leaves the room\n");
  move_object(this_object(), DIR+"r/arena.c"); /* go home */
   tell_room(environment(),
     ME+" walks into the room and smiles.\n");
   fighting = 0;
   hit_point = max_hp;
   weapon_class = 80;
}


heart_beat()
{
  ::heart_beat();
  if(!environment()) 
    return;
  if(attacker_ob && attacker_ob->query_ghost())
  {
    call_out("next_time", 5, attacker_ob);
    all = all_inventory(environment());
    for(a = 0; a < sizeof(all); a++)
    {
      all[a]->stop_fight();
      all[a]->stop_fight();
      all[a]->stop_hunter();
    }
  }
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
  if(hit_point < 200 && !go && fighting)
  {
    go = 1;
    fighting = 0;
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
  if(!random(10))
  {
    tell_object(attacker_ob,
      "\n"+ME+" brings his massive battleaxe crashing into you.\n"+
      "Your body heaves as blood gushes from the wound.\n\n");
    tell_room(environment(attacker_ob),
      "\n"+ME+" crushes "+attacker_ob->query_name()+" violently with his"+
      " battleaxe.\n\n", ({ attacker_ob }));
    attacker_ob->hit_player(100);
  }
  if(hit_point < 1200 && !random(5))
    drink_water();
  if(alt_attacker_ob && attacker_ob != alt_attacker_ob && !random(3))
  {
    tell_room(environment(), "\n"+
      ME+" slashes "+alt_attacker_ob->query_name()+" with his "+
      "battleaxe!\n\n");
    alt_attacker_ob->hit_player(40);
  }
}


