inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Erilon"
object cloak,sword,shield,boots,plate,ring,gob,*all;
int a, fighting, go ,busy, fire, check;
int ok;
string d;

reset(arg){
  if(arg) return;
  ::reset(arg);

  for(a = 0; a < 4; a++)
    move_object(clone_object(DIR+"obj/water.c"), this_object());

  set_no_clean(1);

  ring = clone_object("/obj/armor.c");
  ring->set_type("ring");
  ring->set_name("black ring");
  ring->set_short(BOLD+BLK+"A black ring"+NORM);
  ring->set_long(
    "This is a rather simple ring constructed from a black material\n"+
    "similiar to Erilon's sword.  There is a pattern etched into the\n"+
    "ring which circles the length of it.\n");
  ring->set_weight(1);
  ring->set_ac(1);
  ring->set_value(1100);
  move_object(ring, this_object());
  init_command("wear ring");

  boots = clone_object("/obj/armor.c");
  boots->set_type("boots");
  boots->set_name("black boots");
  boots->set_short(BOLD+BLK+"A pair of black boots"+NORM);
  boots->set_long(
    "These are a pair of black leather boots.  Each one is very\n"+
    "worn and a bit torn up from all the use they've had.  Despite\n"+
    "this fact each boot looks very stylish.\n");
  boots->set_weight(2);
  boots->set_ac(1);
  boots->set_value(1400);
  move_object(boots, this_object());
  init_command("wear boots");

  cloak = clone_object("/obj/armor.c");
  cloak->set_name("black cloak");
  cloak->set_alias("cloak");
  cloak->set_type("misc");
  cloak->set_short(BOLD+BLK+"A long black cloak"+NORM);
  cloak->set_long(
    "This is a long cloak made of a black material.  While it\n"+
    "does not seem to provide much protection, it is light\n"+
    "and looks very elegant despite the dirt on it.\n");
  cloak->set_weight(1);
  cloak->set_ac(2);
  cloak->set_value(1200);
  move_object(cloak, this_object());
  init_command("wear cloak");

  shield = clone_object("/obj/armor.c");
  shield->set_type("shield");
  shield->set_name("shield");
  shield->set_short(BOLD+BLK+"A black tower shield"+NORM);
  shield->set_long(
    "This is a tower shield made from a strange black material.\n"+
    "It appears to be about four feet long and two feet wide,\n"+
    "protecting much of the wearers body.\n");
  shield->set_weight(2);
  shield->set_ac(2);
  shield->set_value(1200);
  move_object(shield, this_object());
  init_command("wear shield");

  plate = clone_object("/obj/armor.c");
  plate->set_name("breastplate");
  plate->set_type("armor");
  plate->set_short(BOLD+BLK+"An exquisite black breastplate"+NORM);
  plate->set_long(
    "This is an exquisitely designed black breastplate.  Despite its\n"+
    "obvious age it shines with magnificent light.  There are however\n"+
    "a few scratches and chips missing from it which will forever flaw\n"+
    "its otherwise perfect surface.\n");
  plate->set_weight(4);
  plate->set_ac(4);
  move_object(plate, this_object());
  init_command("wear armor");

  sword = clone_object("/obj/weapon.c");
  sword->set_type("sword");
  sword->set_alias("longsword");
  sword->set_class(19);
  sword->set_short(BOLD+BLK+"A black longsword"+NORM);
  sword->set_long(
    "This longsword is constructed from a strange black material.\n"+
    "There are many nicks and cuts along the length of it, a true\n"+
    "testament to its age.  An inscription at the base reads, \n"+
    "                \"forever with you\"\n");
  move_object(sword, this_object());
  init_command("wield sword");

  set_name("erilon");
  set_alias("elder");
  set_short("Erilon the Elder");
  set_long(
"Erilon stands 6 feet tall in his black armor, his sword hanging loosely\n"+
"at his side.  Despite his age he has a powerfully built body with very\n"+
"toned muscles.  His eyes have a piercing intensity to them, the highlight\n"+
"of his shaved head.  It is apparent that this man has seen much carnage\n"+
"in his life and that he would not hesitate to do it all again.\n");
  set_race("human");
  set_level(23);
  set_ac(17);
  set_ac_bonus(10);
  set_wc(60);
  set_wc_bonus(10);
  set_hp(4000);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(ME+" clutches at his sword.\n");
  load_chat(ME+" adjusts the ring on his hand.\n");
  load_chat(ME+" looks up at you.\n");
  load_chat(ME+" grimaces.\n");
  load_chat(ME+" says, \"We will never give up.\"\n");
  load_chat(ME+" glances at you.\n");
  load_chat(ME+" looks you up and down.\n");
  load_chat(ME+" says, \"I will defend our home with my life.\"\n");
  load_a_chat(ME+" says, \"You will gain nothing from my death.\"\n");
  load_a_chat(ME+" dodges to the side.\n");
  load_a_chat(ME+" ducks quickly.\n");
  set_dead_ob(this_object());
  call_out("hunt", 7);

  fighting = 0;
  go = 0;
  check = 0;
  busy = 0;
  ok = 0;
}

id(str){ return str == "no_bfstudy" || str == name || str == alias || str == "bftrial_mob_erilon"; }

monster_died(){
  write_file("/players/fred/closed/bloodfist/log/NPC",
  ctime(time())+" - "+attacker_ob->query_real_name()+" [L "+
  attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
  "] killed "+ME+".\n");
}

void toggle_fighting(){ if(fighting) fighting = 0; else fighting = 1; }
int query_busy(){ return busy; } /* true if advancing a player */

void init(){
  add_action("leave_guild", "leave_bloodfist");
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

void lga(string str)  /* LEAVE THE GUILD CODE */
{
  string e,f;
  int g,h,i;
  object y;
  if(str == "Yes" || str == "yes")
  {
    if(!(gob = present("bloodfist_gob", this_player())))
    {
      write(ME+" says, \"You have no guild object.\"\n");
      return;
    }
    
    e = (string)this_player()->query_real_name();
    f = capitalize(e);
    g = (int)this_player()->query_extra_level();
    h = (int)gob->query_glevel();
    i = (int)gob->query_attrib_lvl();

    if(file_size(DIR+"member/"+e+".o") < 1)
    {
      write(ME+" says, \"You have no Bloodfist .o file.\"\n");
      return;
    }

    gob->backup_stats();
    rm(DIR+"member/"+e+".o");
    HONOR_DAEMON->rm_member(e);
    write_file("/players/fred/closed/bloodfist/log/leave",
      ctime()[4..15]+" "+pad(f, 13)+
      pad(this_player()->query_level()+"+"+g,8)+pad(h,3)+pad(i,4)+"\n");
    move_object(clone_object(DIR+"obj/scar.c"), this_player());
    tell_room(environment(), "\n"+
      ME+" unsheathes his black longsword and bows slightly.\n"+
      ME+" plunges his black longsword into "+f+"'s stomach.\n\n\n"+
      f+" collapses to the ground...\n", ({ this_player() }));
    tell_object(this_player(), "\n"+
      ME+" unsheathes his black longsword and bows slightly.\n"+
      ME+" plunges his black longsword into your stomach.\n\n\n"+
      "You feel feint...\n");
    destruct(gob);
    this_player()->add_guild_rank((int)this_player()->query_guild_rank() * -1);
    this_player()->add_guild_exp((int)this_player()->query_guild_exp() * -1);
    this_player()->set_guild_name(0);
    this_player()->set_guild_file(0);
    this_player()->set_home("/room/church");
    this_player()->death("Erilon");
    this_player()->save_me();
  }
  else
    tell_object(this_player(), ME+" nods solemnly.\n");
}

status leave_guild()
{
  if(busy)
    return (notify_fail(ME+" looks busy right now.\n"), 0);
  if((string)this_player()->query_guild_name() != "bloodfist")
    return (notify_fail(ME+" says, \"You are no Bloodfist.\n"), 0);
  tell_object(this_player(), 
    ME+" says, \"Are you sure you want to forever leave this path?\"\n"+
    "   <Yes or No> \n");
  input_to("lga");
  return 1;
}

int gone(object you){
  if(!you) return 1;
  if(!present(you, environment()))
  {
    if(find_player((string)you->query_real_name()))
    {
      tell_room(environment(), 
        ME+" looks around for "+you->query_name()+".\n");
      tell_object(you, ME+
        " tells you, \"You must be here for me to advance your rank.\"\n");
    }
    return 1;
  }
  return 0;
}

void study_response(object q){
  if(!environment()) return;
  if(!q) return;
  tell_room(environment(),
    "\n"+ME+" asks, \"You think I am that simple "+q->query_name()+"?\n");
}

void honor_display(object you){
  tell_room(environment(you),
    "\n"+ME+" says something to "+you->query_name()+".\n", ({ you }));
  tell_object(you,
    "\n"+ME+" says, \"Here is where everyone stands in honor:\"\n");
  HONOR_DAEMON->print_members(you);
}

void top_honor_display(object you){
  tell_room(environment(you),
    "\n"+ME+" says something to "+you->query_name()+".\n", ({ you }));
  tell_object(you,
    "\n"+ME+" says, \"Here are the top ten players in honor:\"\n");
  HONOR_DAEMON->print_top_members(you);
}

void advance1(object you){
  int d;
  d = random(3);
  switch(d){
  case 0:
    tell_room(environment(), ME+" says, \"Well done "+
      you->query_name()+", ");
    break;
  case 1:
    tell_room(environment(), ME+" says, \"Wonderful job "+
      you->query_name()+", ");
    break;
  case 2:
    tell_room(environment(), ME+" says, \"Congratulations "+
      you->query_name()+", ");
    break;
  }
  tell_room(environment(), "you have earned this.\"\n");
  call_out("advance2", 5, you);
}

void advance2(object you){
  if(gone(you)) return;
  tell_object(you, ME+
    " takes your left arm as he pulls out a curved knife.\n");
  tell_room(environment(), ME+
    " takes "+you->query_name()+"'s left arm as he pulls out a "+
    "curved knife.\n", ({ you }));
  call_out("advance3", 6, you);
}

void advance3(object you){
  if(gone(you)) return;
  if(!random(5))
  {
    tell_object(you, ME+" grins as he gazes into your eyes.\n");
    tell_room(environment(), 
      ME+" grins as he gazes into "+you->query_name()+"'s eyes.\n",
      ({ you }));
    call_out("advance3_2", 3, you);
  }
  else {
    tell_object(you, ME+" slowly drags the knife across your arm.\n");
    tell_room(environment(), ME+" slowly drags the knife across "+
      you->query_name()+"'s arm.\n", ({ you }));
    you->hit_player(60 + ((int)gob->query_glevel() * 20));
    call_out("advance4", 5, you);
  }
}

void advance3_2(object you){
  int amt;
  if(gone(you)) return;
  tell_object(you, ME+" slowly drags the knife across your arm.\n");
  tell_room(environment(), ME+" slowly drags the knife across "+
    you->query_name()+"'s arm.\n", ({ you }));
  amt = 60 + ((int)gob->query_glevel() * 20);
  if((int)you->query_hp() - amt < 1)
    you->hit_player((int)you->query_hp() + 1, "other|zeus");
  else
    you->hit_player(amt, "other|zeus");
  call_out("advance4", 5, you);
}

void advance4(object you){
  if(gone(you)) return;
  if(you->query_ghost())
  {
    tell_object(you, ME+" frowns at you.\n");
    tell_room(environment(), ME+" frowns at "+you->query_name()+".\n",
      ({ you }));
    busy = 0;
    check = 0;
    return;
  }
  tell_room(environment(), ME+
    " says, \"You are indeed worthy of your new rank "+
    you->query_name()+".\"\n");

  gob->advance();  /* advance guild level */
  call_out("advance5", 3, you);
}

void advance5(object you){
  CHAN_DAEMON->hprint(BOLD+BLK+
    capitalize((string)you->query_real_name())+" has advanced to level "+
    gob->query_glevel()+" in the guild!"+NORM);
  if(present(you, environment()))
  {
    if(find_player((string)you->query_real_name()))
    {
      tell_object(you, ME+" bows humbly to you.\n");
      tell_room(environment(), ME+" bows humbly to "+you->query_name()+
        ".\n", ({ you }));
      busy = 0;
      check = 0;
    }
  }
  else
    tell_object(you, ME+" bows humbly to you from afar.\n");
  busy = 0;  /* RESET BUSY */
  check = 0;
}

void bow_back(object you){
  if(you && present(you, environment()))
  {
    if(gob = present("bloodfist_gob", you))
    {
      if(gob->query_ready_to_advance())
      {
        tell_room(environment(), ME+" smiles happily.\n");
        call_out("advance1", 4, you);
        busy = 1;  /* BUSY */
      }
      else {
        tell_object(you, ME+" bows to you.\n");
        tell_room(environment(), ME+" bows to "+you->query_name()+".\n",
          ({ you }));
        check = 0;
      }
    }
    else {
      tell_object(you, ME+" glances at you.\n");
      tell_room(environment(), ME+" glances at "+you->query_name()+".\n",
        ({ you }));
      check = 0;
    }
  }
}

arrives(object you)
{
  int g;
  if(you && present(you, environment()))
  {
    g = random(11);
    switch(g)
    {
    case 0..4:
      tell_object(you, ME+" glances at you.\n");
      tell_room(environment(), ME+" glances at "+you->query_name()+".\n",
        ({ you }));
      break;
    case 5:
      tell_room(environment(), 
        ME+" says, \"Greetings "+you->query_name()+".\"\n");
      break;
    case 6:
      tell_room(environment(),
        ME+" says, \"Hello "+you->query_name()+".\"\n");
      break;
    case 7:
      tell_object(you, ME+" smiles at you.\n");
      tell_room(environment(), ME+" smiles at "+you->query_name()+".\n",
        ({ you }));
      break;
    case 8..10:
      break;
    }
  }
}

advance(object you)
{
  object gob;
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
      ME+" says, \"I will not train you "+yn+
      "... you are no Bloodfist.\"\n");
    return;
  }
  if(gob->query_ready_to_advance())
  {
    tell_room(environment(),
      ME+" says, \"Ahh, yes it looks like you are ready "+yn+".\"\n"+
      ME+" says, \"You shall have to bow to me though.\"\n");
    return;
  }    
  if(gob->query_glevel() == 0 && you->query_level() < 7)
  {
    tell_room(environment(),
      ME+" says, \"You are not yet ready to advance "+yn+".\"\n"+
      ME+" says, \"You still need to advance in level.\"\n");
    return;
  }
  else if(gob->query_glevel() == 1 && you->query_level() < 10)
  {
    tell_room(environment(), 
      ME+" says, \"You are not yet ready to advance "+yn+".\"\n"+
      ME+" says, \"You still need to advance in level.\"\n");
    return;
  }
  else if(gob->query_glevel() == 2 && you->query_level() < 13)
  {
    tell_room(environment(), 
      ME+" says, \"You are not yet ready to advance "+yn+".\"\n"+
      ME+" says, \"You still need to advance in level.\"\n");
    return;
  }
  else if(gob->query_glevel() == 3 && you->query_level() < 15)
  {
    tell_room(environment(), 
      ME+" says, \"You are not yet ready to advance "+yn+".\"\n"+
      ME+" says, \"You still need to advance in level.\"\n");
    return;
  }
  else if(gob->query_glevel() == 4 && you->query_level() < 17)
  {
    tell_room(environment(), 
      ME+" says, \"You are not yet ready to advance "+yn+".\"\n"+
      ME+" says, \"You still need to advance in level.\"\n");
    return;
  }
  else if(gob->query_glevel() == 5 && you->query_level() < 19)
  {
    tell_room(environment(), 
      ME+" says, \"You are not yet ready to advance "+yn+".\"\n"+
      ME+" says, \"You still need to advance in level.\"\n");
    return;
  }
  else if(gob->query_glevel() == 6 && you->query_extra_level() < 3)
  {
    tell_room(environment(), 
      ME+" says, \"You are not yet ready to advance "+yn+".\"\n"+
      ME+" says, \"You still need to advance in level.\"\n");
    return;
  }
  else if(gob->query_glevel() == 7 && you->query_extra_level() < 5)
  {
    tell_room(environment(), 
      ME+" says, \"You are not yet ready to advance "+yn+".\"\n"+
      ME+" says, \"You still need to advance in level.\"\n");
    return;
  }
  if(gob->query_glevel_amt() < gob->query_glevel_costdif())
  {
    int blah;
    blah = ((gob->query_glevel_costdif())-(gob->query_glevel_amt()));
    tell_room(environment(), 
      ME+" says, \"You are not yet ready to advance "+yn+".\"\n"+
      ME+" says, \"You still need "+blah+" more guild experience.\"\n");
    return 1;
  }
   else
  {
    if(gob->query_trial_to_do())
    {
      tell_room(environment(),
        ME+" says, \"You must now do your trial to advance "+yn+".\"\n"+
        ME+" says, \"Go and speak with Atheos when you are ready.\"\n");
      return;
    }
    gob->trial_to_do();
    tell_room(environment(), 
      ME+" says, \"You have made very nice progress "+yn+
      ", I am impressed.\"\n"+
      ME+" says, \"I have let Atheos know that "+
      "you are ready for your trial.\"\n"+
      ME+" says, \"When you think you are ready "+
      "go speak with him.\"\n");
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
    if(me->is_player() && !me->query_attack() && !check)
    {
      check = 1;
      call_out("bow_back", 1, me);
    }
  }
  else if(sscanf(str, "%s: train%s", t1, t2) == 2 ||
    sscanf(str, "%s: advance%s", t1, t2) == 2)
  {
    me = this_player();
    if(me->is_player() && !me->query_attack() && !busy)
      call_out("advance", 1, me);
  }
  else if(sscanf(str, "%s: honor%s", t1, t2) == 2)
  {
    me = this_player();
    if(me->is_player() && !me->query_attack() && !busy)
      call_out("honor_display", 1, me);
  }
  else if(sscanf(str, "%s: top honor%s", t1, t2) == 2)
  {
    me = this_player();
    if(me->is_player() && !me->query_attack() && !busy)
      call_out("top_honor_display", 1, me);
  }
  else if(sscanf(str, "%s arrives.%s\n", t1, t2) == 2)
  {
    if(!random(5))
      call_out("arrives", 2, find_player(lower_case(t1)));
  }
}

recalc_stats(object nmy){
  if(!nmy) return;
  if(nmy->query_level() > 19)
    hit_point = max_hp = 350;
  else if(nmy->query_level() <= 19 && nmy->query_extra_level() <= 4)
    hit_point = max_hp = 1900;
  else if(nmy->query_extra_level() < 10)
    hit_point = max_hp = 1950;
  else if(nmy->query_extra_level() < 20)
    hit_point = max_hp = 2000;
  else
    hit_point = max_hp = 2050;
}

void victory1(object you){
  int *r;
  tell_object(you, ME+" smiles at you.\n");
  tell_room(environment(), ME+" smiles at "+you->query_name()+".\n",
    ({ you }));
  gob = present("bloodfist_gob", you);
  if(gob)
  {
    if(gob->query_trial_to_do())
      gob->ready_to_advance();  /* no longer has a trial to do */
    else
      tell_object(you, ME+" says, \"You didn't have a trial to do.\"\n");
    r = GEM_REWARDS;
    gob->add_free_gems(r[8]);
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
    "             \"to advance within the Bloodfist.\"\n");
  call_out("victory4", 8, you);
}

void victory4(object you){
  tell_room(environment(),
    ME+" says, \"Come and see me in the meeting room and I shall advance "+
    "your rank.\" (bow to me)\n");
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" says, \"Come and see me in the meeting room and I shall advance "+
    "your rank.\" (bow to me)\n");
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

  tell_room(environment(), ME+" bows to "+you->query_name()+".\n", ({ you }));

  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" bows to "+you->query_name()+".\n");
  call_out("victory7", 4, you);
}

void victory7(object you){
  tell_room(environment(), ME+" leaves the room.\n");
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+"[A]"+NORM+HIR+">>> "+NORM+ME+" leaves the room.\n");
  hit_point = max_hp;
  weapon_class = 60;
  move_object(this_object(), "/players/fred/closed/bloodfist/r/meeting.c");
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
      move_object(this_object(), DIR+"r/meeting.c"); /* go home */
      tell_room(environment(),
        ME+" walks into the room and smiles.\n");
      fighting = 0;
    }
  }
  else
    call_out("hunt", 7);
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) 
    return;
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
  if(hit_point < 250 && !go && ok)
  {
    go = 1;
    fighting = 0;
    ok = 0;
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
      ME+" slashes you violently with his longsword.\n"+BOLD+BLK+
      "The wound expands as dark fire burns your flesh!\n"+NORM);
    tell_room(environment(attacker_ob),
      ME+" slashes "+attacker_ob->query_name()+" violently with his"+
      " longsword.\n"+BOLD+BLK+
      "The wound expands as dark fire burns "+attacker_ob->query_name()+
      "'s flesh!\n"+NORM, ({ attacker_ob }));
    attacker_ob->hit_player(100, "other|fire");
  }
  else if(!random(20))
  {
    tell_room(environment(), ME+" motions...\n\n\n"+RED+
      "\t\t\tDark fire rips through the room!\n\n\n\n"+NORM);
    attacker_ob->hit_player(40+random(30));
    if(alt_attacker_ob && alt_attacker_ob != attacker_ob)
      alt_attacker_ob->hit_player(40+random(30), "other|fire");
  }
  else if(!random(12))
  {
    tell_room(environment(),
      ME+" lunges at "+attacker_ob->query_name()+" with his longsword out.\n"+
      ME+" drives his sword deep into "+attacker_ob->query_name()+"!\n",
      ({ attacker_ob }));
    tell_object(attacker_ob,
      ME+" lunges at you with his longsword out.\n"+
      ME+" drives his sword deep into you!\n");
    attacker_ob->hit_player(30+random(20));
  }
  if(!random(16) && !fire)
  {
    tell_room(environment(),
      "\n"+ME+"'s fists are consumed by blazing balls of dark fire!\n\n");
    fire = 7+random(6);
  }
  if(fire)
  {
    fire--;
    if(!random(2))
    {
      tell_room(environment(), RED+
        "Dark fire burns across "+attacker_ob->query_name()+"'s body.\n"+NORM,
        ({ attacker_ob }));
      tell_object(attacker_ob,
        RED+"Dark fire burns across your body.\n"+NORM);
    }
    weapon_class = 75;
    if(fire <= 0)
    {
      tell_room(environment(),
        "The fire around "+ME+"'s fists dies down.\n");
      weapon_class = 60;
    }
  }
  if(!random(5))
  {
    a = random(6);
    switch(a)
    {
    case 0:
      tell_room(environment(),
        ME+"'s longsword glows with a dark flame.\n");
      break;
    case 1:
      tell_room(environment(),
        ME+" says, \"Ahh...  you can't beat this!\"\n");
      break;
    case 2:
      tell_room(environment(), ME+" laughs heartily.\n");
      break;
    case 3:
      tell_room(environment(), ME+" dodges quickly to the side.\n");
      break;
    case 4:
      tell_room(environment(), ME+" lunges forward then steps back.\n");
      break;
    case 5:
      tell_room(environment(), ME+" grips his longsword tightly.\n");
      break;
    }
  }
  if(hit_point < 1500 && !random(5))
    drink_water();
  if(alt_attacker_ob && attacker_ob != alt_attacker_ob && !random(3))
  {
    tell_room(environment(), "\n"+
      ME+" slashes "+alt_attacker_ob->query_name()+" with his "+
      "longsword!\n\n");
    alt_attacker_ob->hit_player(40);
  }
}

set_ok(int num){ ok = num; }
