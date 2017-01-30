inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Haemon"
object morningstar,breastplate,gob,*all, *arena;
int a, go, vis;
string b,c,d;

reset(arg){
  if(arg) return;
  ::reset(arg);


  arena = ({ 
    "players/fred/closed/bloodfist/r/arena_room1",
    "players/fred/closed/bloodfist/r/arena_room2",
    "players/fred/closed/bloodfist/r/arena_room3",
    "players/fred/closed/bloodfist/r/arena_room4", });

  for(a = 0; a < 4; a++)
    move_object(clone_object(DIR+"obj/water.c"), this_object());

  breastplate = clone_object("/obj/armor.c");
  breastplate->set_weight(1);
  breastplate->set_value(500);
  breastplate->set_type("misc");
  breastplate->set_name("night cloak");
  breastplate->set_alias("cloak");
  breastplate->set_short(BLU+"Night Cloak"+NORM);
  breastplate->set_long(
    "This is a black night cloak.  It looks light.\n");
  breastplate->set_ac(0);
  move_object(breastplate, this_object());
  init_command("wear cloak");

 
  morningstar = clone_object("/obj/weapon.c");
  morningstar->set_weight(2);
  morningstar->set_class(20);
  morningstar->set_type("sword");
  morningstar->set_alias("blade");
  morningstar->set_name("bruteslayer");
  morningstar->set_short(BLU+"Twin Night Blades"+NORM+
    " (wielded) [major gem of agility]");
  morningstar->set_long(
    "This is an exquisitely crafted two shortswords.  "+
    "Nobody should ever see this.\n");
  morningstar->set_value(1400);
  move_object(morningstar, this_object());

  go = 0;
  vis = 1;

  set_name(ME);
  set_alias("lurker");
  set_long(
ME+" is hidden behind the magical night cloak.  He moves among the\n"+
"shadows with grace and speed and is very difficult to see.  Beneath\n"+
"the cloak the glint of twin night blades are visible, "+ME+"'s\n"+
"trademark weapons.  "+ME+" is a master of stealth combat.\n");
  set_race("human");
  set_level(21);
  set_ac(16);
  set_ac_bonus(7);
  set_wc(37);
  set_wc_bonus(10);
  set_hp(1000);
  set_heal(1,1);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(ME+" smiles at you.\n");
  load_chat(ME+" looks around.\n");
  load_chat(ME+" clutches each of his blades.\n");
  load_chat(ME+" stands idly as he looks around the area.\n");
  load_chat(ME+" briefly examines his blades.\n");
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

short(){ if(vis) return ME+" the Night Lurker"; else return ""; }

id(str){ return str == "haemon" || str == "lurker" || str == "no_bfstudy"
|| str == "bftrial_mob"; }

recalc_stats(object nmy){
  if(!nmy) return;
  if(nmy->query_level() > 19)
    hit_point = max_hp = 350;
  else if(nmy->query_level() < 10)
    hit_point = max_hp = 1300;
  else if(nmy->query_level() < 14)
    hit_point = max_hp = 1350;
  else if(nmy->query_level() < 17)
    hit_point = max_hp = 1400;
  else if(nmy->query_level() <= 19 && nmy->query_extra_level() <= 4)
    hit_point = max_hp = 1450;
  else if(nmy->query_extra_level() < 10)
    hit_point = max_hp = 1500;
  else
    hit_point = max_hp = 1550;
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
    "\n"+ME+" grins evilly at "+q->query_name()+".\n", ({ q }));
  tell_object(q, "\n"+ME+" grins evilly at you.\n");
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
    gob->add_free_gems(r[7]);
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

hunt()
{
  if(environment() && attacker_ob && !present(attacker_ob, environment())
    && !attacker_ob->query_ghost()
    && sscanf(file_name(environment(attacker_ob)),
    "players/fred/closed/bloodfist/r/arena_%s", d) && !random(5)
    && vis)
  {
    tell_room(environment(), ME+" goes after "+
      attacker_ob->query_name()+".\n");
    move_object(this_object(), environment(attacker_ob));
    tell_room(environment(), ME+" arrives and lunges at "+
      attacker_ob->query_name()+".\n", ({ attacker_ob }));
    tell_object(attacker_ob, ME+" arrives and lunges at you.\n\n");
    weapon_class += 5;
    attack_object(attacker_ob);
  }
  else
    call_out("hunt", 5);
}

void attack_again(){  hunt();  }

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
  vis = 0;                      /* invis */
  set_heal(8,1);                /* increased healing */
  call_out("attack_again", 30); /* duration */
}

heart_beat()
{
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
  if(vis)
  {
    vis = 0;         /* if attacked while invis, become vis */
    set_heal(1,1);   /* reset healing */
  }
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
  if(hit_point < 600 && !random(5))
  {
    tell_room(environment(), ME+" disappears into a shadow.\n");
    move_me(file_name(environment()));
  }
  if(random(4) && attacker_ob && !attacker_ob->query_ghost())
  {
    already_fight = 0;
    ::attack();
  }
  if(!random(7))
  {
    a = random(4);
    switch(a)
    {
    case 0:
      tell_room(environment(), "\n"+ME+
        " leaps foward and plunges his blades into "+attacker_ob->query_name()+
        "'s chest.\n"+
        attacker_ob->query_name()+" staggers as blood pours from "+
        "the wounds.\n\n", ({ attacker_ob }));
      tell_object(attacker_ob,  "\n"+ME+
        " leaps foward and plunges his blades into your chest.\n"+
        "You stagger as blood pours from the wounds.\n\n");
      attacker_ob->hit_player(50+random(33));
      break;
    case 1:
      tell_room(environment(),
        ME+" spins swifly, slashing "+attacker_ob->query_name()+
        " with his blades.\n", ({ attacker_ob }));
      tell_object(attacker_ob,
        ME+" spins swifly, slashing you with his blades.\n");
      attacker_ob->hit_player(20);
      break;
    case 2:
      tell_room(environment(),
        "\n"+ME+" shouts, \"Death becomes you!\"\n\n\n"+
        ME+" runs at "+attacker_ob->query_name()+" and drives his blades "+
        "deep into "+attacker_ob->POS+" stomach.\n\n"+
        attacker_ob->query_name()+" recoils in pain.\n", ({ attacker_ob }));
      tell_object(attacker_ob,
        "\n"+ME+" shouts, \"Death becomes you!\"\n\n\n"+
        ME+" runs at you and drives his blades deep into your stomach.\n\n"+
        "You recoil in pain.\n");
      attacker_ob->hit_player(50+random(33));
      break;
    case 3:
      tell_room(environment(), 
        ME+" moves swiftly as his cloak flutters in the wind.\n");
      break;
    }
  }
  if(hit_point < 1100 && !random(5))
    drink_water();
  if(alt_attacker_ob && attacker_ob != alt_attacker_ob && !random(3))
  {
    tell_room(environment(), "\n"+
      ME+" slashes "+alt_attacker_ob->query_name()+" with his "+
      "blades!\n\n");
    alt_attacker_ob->hit_player(30);
  }
}

query_bf_trialmob(){ return 1; }

