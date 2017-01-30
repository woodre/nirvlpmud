inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Seht Deyad"
#define WN BOLD+BLK+"Der EngelSense"+NORM
#define BASE_WC 70
#define BASE_AC 30
object wep,armor,cap,cloak,boots,amulet,ring,bag;
object wa,*all,nmy,nmyao,tmp,gob,grd;
#ifndef __LDMUD__
object me;
#endif
string *warned, *beta;
int cnt, a, b, bloodlust, iron_skin, busy, guards;

reset(arg){
  ::reset(arg);
  if (arg) return;

  warned = ({ }); /* warned players */
  cnt = 2;        /* peace countdown timer */
  busy = 0;       /* not busy */
  guards = 1+random(3);     /* summoned guards */

  bag = clone_object("/players/mythos/prac/bag.c"); /* cloning mythos' bag */
  move_object(bag, this_object());

  for(a = 0; a < 6; a++)
  {
    wa = clone_object(DIR+"obj/water.c");
    move_object(wa, this_object());
  }

  for(a = 0; a < 2; a++)
  {
    wa = clone_object("/obj/heal.c");
    move_object(wa, this_object());
  }

  cap = clone_object("/obj/armor.c");
  cap->set_type("helmet");
  cap->set_name("fullhelm");
  cap->set_alias("helm");
  cap->set_short("A black fullhelm");
  cap->set_long(
    "This black fullhelm is as dark as night.  A grate covers to face\n"+
    "of the wearer, protecting them while still allowing a full range\n"+
    "of vision.  There are a few small scratches on the top.\n");
  cap->set_weight(2);
  cap->set_ac(1);
  cap->set_value(1200);
  move_object(cap, this_object());
  init_command("wear fullhelm");

  boots = clone_object("/obj/armor.c");
  boots->set_type("boots");
  boots->set_name("boots");
  boots->set_short("A pair of black boots");
  boots->set_long(
    "This pair of black boots look good despite a fair amount of wear and\n"+
    "a coating of sand caked around them.\n");
  boots->set_weight(2);
  boots->set_ac(1);
  boots->set_value(1400);
  move_object(boots, this_object());
  init_command("wear boots");

  cloak = clone_object("/obj/armor.c");
  cloak->set_name("black cloak");
  cloak->set_alias("cloak");
  cloak->set_type("misc");
  cloak->set_short("A black cloak");
  cloak->set_long(
    "This is a long cloak made of a black material.  While it\n"+
    "does not seem to provide much protection, it is light\n"+
    "and looks very elegant despite the dirt on it.\n");
  cloak->set_weight(1);
  cloak->set_ac(1);
  cloak->set_value(1200);
  move_object(cloak, this_object());
  init_command("wear cloak");

  amulet = clone_object(DIR+"eq/blood_amulet.c");
  move_object(amulet, this_object());
  amulet->set_random_bf_type();
  init_command("wear amulet");

  ring = clone_object(DIR+"eq/bloodfist_ring.c");
  move_object(ring, this_object());
  init_command("wear ring");

  armor = clone_object("/obj/armor.c");
  armor->set_name("ringmail");
  armor->set_type("armor");
  armor->set_short("A suit of black ringmail");
  armor->set_long(
    "This is a metal suit of black ringmail.  It is well crafted and\n"+
    "would provide a fair amount of protection in combat.\n");
  armor->set_weight(3);
  armor->set_ac(2);
  move_object(armor, this_object());
  init_command("wear armor");

  wep = clone_object(DIR+"eq/es.c");
  move_object(wep, this_object());
  init_command("wield scythe");

  set_name("Seht Deyad");
  set_alt_name("deyad");
  set_alias("seht");
  set_race("human");
  set_long(
ME+" is a tall, powerful warrior.  Clad in black armor, as he\n"+
"glides through the shadows he is almost impossible to see.  He holds\n"+
"in his hands the weapon Der EngelSense, a beautifully crafted scythe.\n"+
"He looks both ready to fight and ready to talk, so be careful how you\n"+
"approach him.  "+ME+" is a member of the Bloodfist guild.  If you\n"+
"are interested in joining the guild, perhaps you should bow to him.\n");
  set_level(25);
  set_ac(BASE_AC);
  set_wc(BASE_WC);
  set_hp(1000);
  set_hp_bonus(1100);
  set_ac_bonus(8);
  set_wc_bonus(22);
  set_heal(3,1);
  set_al(100);
  set_gender("male");
  set_aggressive(0);
  set_chat_chance(1);
  set_a_chat_chance(5);
  load_chat("Something moves among the shadows.\n");
  load_a_chat(ME+" dodges to the side.\n");
  load_a_chat(ME+" is difficult to see in the darkness.\n");
  load_a_chat(ME+" ducks down quickly.\n");
  load_a_chat(ME+" steps back into a shadow momentarily.\n");
  set_dead_ob(this_object());  
}

monster_died(){
  object gold;
  write_file("/players/fred/closed/bloodfist/log/NPC",
  ctime(time())+" - "+attacker_ob->query_real_name()+" [L "+
  attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
  "] killed "+ME+".\n");
  tell_room(environment(),
    "A pouch of coins falls from "+ME+" as he dies.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(9000 + random(4000));
  move_object(gold, environment());
}

id(str){ return (::id(str) || str == "nomad" || str == "bloodfist"
                 || str == "warrior"); }

short()
{
  if(this_player() && this_player()->query_guild_name() == "bloodfist")
    return ME+" the Nomadic Warrior";
}

calculate_worth(){
  armor_class = BASE_AC;
  weapon_class = BASE_WC;
  return ::calculate_worth();
}

string query_guild_name(){ return "bloodfist"; }

void init(){
  add_action("leave_guild", "leave_bloodfist");
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

    if((int)gob->query_trial_period() < time())
    {
      tell_room(environment(), "\n"+
        ME+" says, \"You will need to talk with Erilon to leave, "+f+".\"\n"+
        "                 \"You have been in the guild too long "+
        "for me to do it.\"\n");
      return;
    }

    gob->backup_stats();
    rm(DIR+"member/"+e+".o");
    HONOR_DAEMON->rm_member(e);
    write_file("/players/fred/closed/bloodfist/log/leave_trial",
      ctime()[4..15]+" "+pad(f, 13)+
      pad(this_player()->query_level()+"+"+g,8)+pad(h,3)+pad(i,4)+"\n");
    move_object(clone_object(DIR+"obj/scar.c"), this_player());
    tell_room(environment(), "\n"+
      ME+" says, \"Well, I'm sorry it didn't work out for you.\"\n"+
      "                 \"Good luck "+f+"...\n\n");
    tell_room(environment(), "\n"+ME+" takes "+f+"'s blood crystal from "+
      this_player()->query_objective()+".\n", ({ this_player() }));
    tell_object(this_player(),
      ME+" takes your blood crystal from you.\n");
    destruct(gob);
    this_player()->add_guild_rank((int)this_player()->query_guild_rank() * -1);
    this_player()->add_guild_exp((int)this_player()->query_guild_exp() * -1);
    this_player()->set_guild_name(0);
    this_player()->set_home("/room/church");
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
    ME+" says, \"Are you sure you don't want to stick it out?\"\n"+
    "   <Yes or No> ");
  input_to("lga");
  return 1;
}

void join_q(object me)
{
  object join;
  if(present("bloodfist_gob", me) || present("bf_join_ob", me))
  {
    tell_object(me, ME+" bows to you.\n");
    tell_room(environment(me), ME+" bows to "+me->query_name()+".\n", ({ me }));
    return;
  }
  else if(me->query_guild_name())
  {
    tell_room(environment(me), ME+" says, \"You are already in a guild "+
      me->query_name()+".\"\n", ({ me }));
    return;
  }
  else if((int)me->query_level() < 5)
  {
    tell_room(environment(me), 
      ME+" says, \"You must be at least level 5 to join Bloodfist.\"\n");
    return;
  }
  tell_object(me, ME+" says, \"Are you interested in joining the Bloodfist?\"\n"+
    "\t<Yes or No>\n");
  join = clone_object(DIR+"obj/join.c");
  move_object(join, me);
  join->begin(me);
  command("eahtpieh2pjH235zwh", me);
}

void catch_tell(string str)
{
  string t1, t2;
  object me;
  if((sscanf(str, "%sbows%syou.", t1, t2) == 2) && !busy)
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("join_q", 1, me);
  }
  else if((sscanf(str, "%sbows%syou.", t1, t2) == 2) && busy)
    return (notify_fail(ME+" looks busy.\n"), 0);
}

add_warned(string str) {
  if(!query_warned(str))
    return warned += ({ str, });
  return 0;
}

query_warned(string str) {
  if(!warned || !sizeof(warned)) return 0;
  if(index(warned, str) > -1) return str;
  return 0;
}

cmgs(object atk, int c)
{
  for(a = 0; a < random(c); a++)
  {
    b = random(9);
    switch(b)
    {
    case 0:
      tell_room(environment(),
        RED+"A red haze blurs behind "+ME+"!\n"+NORM);
      break;
    case 1:
      tell_room(environment(), 
        RED+ME+"'s motions blur as he strikes!\n"+NORM);
      break;
    case 2:
      tell_room(environment(),
        RED+ME+" moves as if through a blood cloud!\n"+NORM);
      break;
    case 3:
      tell_room(environment(),
        RED+"A red streak extends behind "+ME+"!\n"+NORM);
      break;
    case 4..8: break;
    }
    if(!atk->query_ghost())
    {
      already_fight = 0; 
      ::attack();
    }
  }
}

void drink_water()
{
  if((tmp = present("zbf_water", this_object())))
  {
    tell_room(environment(),
      ME+" drinks from a canteen of water.\n");
    hit_point += 50;
    if(tmp->use_charge() <= 0 && !random(3))
    {
      tell_room(environment(), ME+" takes water from bag.\n");
      wa = clone_object(DIR+"obj/water.c");
      move_object(wa, this_object());
    }
  }
}

heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  busy = 0;
  if(!attacker_ob) return;
  busy = 1;
  if(attacker_ob->is_player())
    cnt--;
  nmy = attacker_ob;
  nmyao = alt_attacker_ob;
  if(bloodlust)
  {
    bloodlust--;
    if(bloodlust <= 0)
    {
      tell_room(environment(), "\n"+ME+"'s bloodlust calms...\n\n");
      weapon_class -= 40;
    }
  }
  if(iron_skin)
  {
    iron_skin--;
    if(iron_skin <= 0)
    {
      tell_room(environment(),
        "\n"+ME+" can once again feel the pain of battle.\n\n");
      armor_class -= 15;
    }
  }
  if(cnt <= 0 && nmy && (!query_warned(nmy->query_real_name()
    || ((nmy != nmyao) && !query_warned(nmyao->query_real_name())))))
  {
    all = all_inventory(environment());

    drink_water();

    tell_room(environment(), 
      "\n"+ME+" holds up his hand as all fighting stops.\n\n\n");

    for(a = 0; a < sizeof(all); a++)
    {
      all[a]->stop_fight();
      all[a]->stop_fight();
      all[a]->stop_hunter();
    }
    if(nmy->is_player())
    {
      tell_room(environment(),
        ME+" says, \"Do not attack "+nmy->query_name()+
        ".  You have been warned.\"\n");
      add_warned(nmy->query_real_name());
      CHAN_DAEMON->hprint(RED+" WARNING "+NORM+BOLD+BLK+
        capitalize((string)nmy->query_real_name())+
        " is trying to break into the guild hall!"+NORM);
    }
    else if(nmyao && (nmy != nmyao) && nmyao->is_player())
    {
      tell_room(environment(),
        ME+" says, \"You have been warned as well "+
        nmyao->query_name()+", do not attack again.\"\n");
      add_warned(nmyao->query_real_name());
      CHAN_DAEMON->hprint(RED+" WARNING "+NORM+BOLD+BLK+
        capitalize((string)nmy->query_real_name())+
        " is trying to break into the guild hall!"+NORM);
    }
    cnt = 2;
    return;
  }
  if(nmy->is_npc())
  {
    hit_point += 15;
    cmgs(nmy,5);
    if(!random(4))
    {
      tell_room(environment(),
      "\n\n"+ME+"'s "+WN+" tears flesh from "+
      nmy->short()+"!\n"+
      "\tThe sound of cracking bones can be heard.\n"+
      "\tBlood pours forth onto the dry sand.\n\n\n\n"+
      nmy->short()+" begins to melt away in pain.\n");
      nmy->hit_player(100+random(30));
    }
    return;
  }
  if(cnt < 0 && query_warned(nmy->query_real_name()))
  {
    cmgs(nmy,3);
    if(!random(4) && ((hit_point + 50) < max_hp))
      drink_water();
    else if(!random(10) && !bloodlust)
    {
      tell_room(environment(), "\n"+ME+" is overcome with bloodlust!\n\n");
      bloodlust = 15;
      weapon_class += 40;
    }
    else if(!random(10) && !iron_skin)
    {
      tell_room(environment(),
        "\n"+ME+" drives himself to fight harder!\n\n");
      iron_skin = 10;
      armor_class += 15;
    }
    else if(!random(12) && present(nmy, environment()))
    {
      tell_room(environment(),
        "\n"+ME+" pulls a dagger from his belt and throws it at "+
        nmy->query_name()+".\n"+
        nmy->query_name()+" is punctured by the dagger!\n\n",
        ({ nmy }));
      tell_object(nmy,
        "\n"+ME+" pulls a dagger from his belt and throws it at you.\n"+
        "You are punctured by the dagger!\n\n");
      nmy->hit_player(80+random(50));
    }
    else if(!random(8) && hit_point < 450)
    {
      if((tmp = present("heal", this_object())))
        init_command("cast heal");
    }
    else if(hit_point < (max_hp * 2 / 3) && guards && !random(10))
    {
      guards--;
      tell_room(environment(),
        "A guard rushes into the room.\n");
/* changed ref from zeus' dir to fred's dir */
      grd = clone_object("/players/fred/closed/bloodfist/NPC/guard.c");
     move_object(grd, environment());
      grd->attack_object(attacker_ob);
    }
  }
  if(cnt < 0 && nmy && nmyao && (nmyao != nmy) && query_warned(nmyao->query_real_name()))
  {
    if(!random(7))
    {
      tell_room(environment(),
        "\n\n"+ME+" leaps high into the air...\n"+
        ME+"slashes his "+WN+" into the rock of the mountain.\n\n");
      tell_room(environment(),
        YEL+"\t\tLarge rocks break loose from the mountain!\n"+
        "\t\t"+nmyao->query_name()+" is CRUSHED by falling rocks!\n\n\n"+NORM,
        ({ nmyao }));
      tell_object(nmyao,
        "\n\n"+ME+" leaps high into the air...\n"+
        ME+"slashes his "+WN+" into the rock of the mountain.\n\n"+
        YEL+"\t\tLarge rocks break loose from the mountain!\n"+
        "\t\tYou are CRUSHED by falling rocks!\n\n\n"+NORM);
/* change ref from zeus to fred */
      nmyao->hit_player(80, "other|fred");
      nmyao->hit_player(80+random(40));
    }
  }
}

