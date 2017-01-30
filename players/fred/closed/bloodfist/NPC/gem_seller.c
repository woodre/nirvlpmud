inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define GEM_PRICE 10000
#define UNKNOWN_PRICE 60000
#define ME "Bale"
object armor,gob;
string *gnames;

reset(arg){
  if(arg) return;
  ::reset(arg);

  armor = clone_object("/obj/armor.c");
  armor->set_name("robe");
  armor->set_type("armor");
  armor->set_short("A long brown robe");
  armor->set_long(
    "This long brown robe drags was made for someone about five and a\n"+
    "half feet tall.  The sleeves are quite long and completely cover\n"+
    "the hands of the wearer.  The oversized hood hangs loosely from\n"+
    "the neck of the robe.  It is undeniably well made.\n");
  armor->set_weight(1);
  armor->set_ac(3);
  move_object(armor, this_object());
  init_command("wear robe");

  gnames =({ "crystal gem", "ruby gem", "emerald gem", "sapphire gem", 
    "diamond gem", "onyx gem", "topaz gem", "amethyst gem", 
  });

  set_name("bale");
  set_alt_name("man");
  set_alias("old man");
  set_short("An old man in a long brown robe");
  set_long(
"The man that stands before you is "+ME+".  He is completely hidden\n"+
"beneath his signature brown robe.  He stands about five and a half\n"+
"feet tall, and does not appear to be a very brawny man.  It is\n"+
"impossible to guage his age, however you know him to be a very old\n"+
"adventurer.  Perhaps you could buy something from him.  To see a list\n"+
"of things for sale, type 'list'.\n");
  set_race("human");
  set_level(23);
  set_ac(17);
  set_ac_bonus(10);
  set_wc(40);
  set_wc_bonus(10);
  set_hp(4000);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(ME+"'s robe blows slightly in the breeze.\n");
  load_chat(ME+" shuffles slightly beneath his robe.\n");
  load_chat(ME+" looks up at the darkness.\n");
  load_chat(ME+" looks up at the sky.\n");
  load_chat(ME+" asks, \"Do you need any gems?\"\n");
  load_chat(ME+" glances at you.\n");
  load_chat(ME+" looks you up and down.\n");
  load_chat(ME+" asks, \"Do you need anything?\"\n");
  load_a_chat(ME+" says, \"You will gain nothing from my death.\"\n");
  load_a_chat(ME+" dodges to the side.\n");
  load_a_chat(ME+" ducks quickly.\n");
  set_dead_ob(this_object());
}

void monster_died(){
  write_file("/players/fred/closed/bloodfist/log/NPC",
  ctime(time())+" - "+attacker_ob->query_real_name()+
  " [L "+attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
  "] killed "+ME+".\n");
}

void init(){
  ::init();
  add_action("buy_cmd", "buy");
  add_action("list_cmd", "list");
  add_action("ask_cmd", "ask");
}

void bow_back(object you){
  if(you && present(you, environment()))
  {
    if(gob = present("bloodfist_gob", you))
    {
      tell_object(you, ME+" bows to you.\n");
      tell_room(environment(), ME+" bows to "+you->query_name()+".\n",
        ({ you }));
    }
    else {
      tell_object(you, ME+" glances at you.\n");
      tell_room(environment(), ME+" glances at "+you->query_name()+".\n",
        ({ you }));
    }
  }
}

void arrives(object you)
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
    case 5..7:
      tell_room(environment(), 
        ME+" says, \"Hello "+you->query_name()+", do you need any"+
        " gems?\"\n");
      break;
    case 8:
      tell_room(environment(),
        ME+" says, \"Hello "+you->query_name()+".\"\n");
      break;
    case 9:
      tell_object(you, ME+" smiles at you.\n");
      tell_room(environment(), ME+" smiles at "+you->query_name()+
        " for a second.\n",
        ({ you }));
      break;
    case 10:
      break;
    }
  }
}

status ask_cmd(string str)
{
  int a;
  object gob;
  if(str != "about gems" && str != "seller about gems"
    && str != "about free gems" && str != "seller about free gems")
    return 0;
  gob = present("bloodfist_gob", this_player());
  if(!gob || (string)this_player()->query_guild_name() != "bloodfist")
  {
    tell_room(environment(), ME+" ignores you.\n");
    return 1;
  }
  if((a = (int)gob->query_free_gems()) == 0)
    return (notify_fail(ME+" says, \"Sorry friend, no gems for you.\"\n"), 0);
  else if(a < 0)
    return (notify_fail(ME+" asks, \"How the fuck did that happen?\"\n"), 0);
  tell_room(environment(), 
    ME+" says, \"I owe you "+a+" free gems.  You can store up to "+
    gob->query_available_gem_space()+" more gems.\"\n"+
    "           \"Do you want to claim your free gems now?\"  y/n\n"+
    "y/n> ");
  move_object(clone_object(DIR+"obj/accept.c"), this_player());
  return 1;
}

void ask_okay(object me)
{
  object gob;
  int w, e;
  gob = present("bloodfist_gob", me);
  if(!gob)
    return (notify_fail(ME+" says, \"You have no gob.\"\n"), 0);
  w = (int)gob->query_free_gems();  
  for(e = 0; e < w; e++)
  {
    if(!me->add_weight(1))
      break;
    move_object(clone_object(DIR+"obj/gem.c"), me);
    gob->add_free_gems(-1);
  }
  if(e == 0)
    tell_object(me, ME+" says, \"You are not able to carry any gems.\"\n");
  else if(e < w)
    tell_object(me, ME+" says, \"You are only able to carry "+e+" gems.\"\n"+
    "           \"Hold the gems to uncover their magical properties.\"\n");
  else {
    tell_room(environment(),
      ME+" hands "+me->query_name()+" "+e+" gems.\n", ({ me }));
    tell_object(me, ME+" reaches out and hands you "+e+" gems.\n"+
      ME+" says, \"Hold the gems to uncover their magical properties.\"\n");
  }
}

void ask_deny(object me)
{
  tell_room(environment(),
    ME+" nods solemnly at "+me->query_name()+".\n", ({ me }));
  tell_object(me, ME+" nods solemnly at you.\n");
}

status buy_cmd(string str)
{
  int type;
  object gem, gob;
  if(!str) return 0;
  else if((string)this_player()->query_guild_name() != "bloodfist")
  {
    tell_room(environment(),
      ME+" ignores you.\n");
    return 1;
  }
  else if(str == "ruby" || str == "ruby gem" || str == "1")
    type = 1;
  else if(str == "emerald" || str == "emerald gem" || str == "2")
    type = 2;
  else if(str == "sapphire" || str == "sapphire gem" || str == "3")
    type = 3;
  else if(str == "diamond" || str == "diamond gem" || str == "4")
    type = 4;
  else if(str == "onyx" || str == "onyx gem" || str == "5")
    type = 5;
  else if(str == "topaz" || str == "topaz gem" || str == "6")
    type = 6;
  else if(str == "amethyst" || str == "amethyst gem" || str == "7")
    type = 7;
  else if(str == "unidentified" || str == "unknown")
    type = 8;
  else {
    tell_room(environment(), 
      ME+" asks, \"What kind of gem do you want "+
      this_player()->query_name()+"?\"\n");
    return 1;
  }
  if(!this_player()->add_weight(1))
  {
    tell_room(environment(), 
      ME+" says, \"It doesn't look like you can carry it "+
      this_player()->query_name()+".\"\n");
    return 1;
  }
  if(this_player()->query_level() < 21)
  {
    if(type > 0 && type < 8)
    {
      if((int)this_player()->query_bank_balance() > GEM_PRICE)
      {
        this_player()->add_bank_balance(-GEM_PRICE);
      }
      else if((int)this_player()->query_money() > GEM_PRICE)
      {
        this_player()->add_money(-GEM_PRICE);
      }
      else
      {
        tell_room(environment(),
          ME+" says, \"It doesn't look like you can afford it "+
          this_player()->query_name()+".\"\n");
        return 1;
      }
    }
    else if(type == 8)
    {
      if((int)this_player()->query_bank_balance() > UNKNOWN_PRICE)
      {
        this_player()->add_bank_balance(-UNKNOWN_PRICE);
      }
      else if((int)this_player()->query_money() > UNKNOWN_PRICE)
      {
        this_player()->add_money(-UNKNOWN_PRICE);
      }
      else
      {
        tell_room(environment(),
          ME+" says, \"It doesn't look like you can afford it "+
          this_player()->query_name()+".\"\n");
        return 1;
      }
    }
  }

  gob = present("bloodfist_gob", this_player());
  if(gob)
  {
    write_file("/players/fred/closed/bloodfist/log/gem_purchase",
    ctime(time())+" - "+
    pad(capitalize((string)this_player()->query_real_name()), 12)+
    "  "+this_player()->query_level()+"+"+
      pad((string)this_player()->query_extra_level(),3)+" "+
      "  "+pad((string)this_player()->query_money(), 8)+
      pad((string)gob->query_glevel(),7)+type+"\n");
  }

  tell_object(this_player(),
      ME+" pulls a gem from his pocket and hands it to you.\n");
  tell_room(environment(), 
      ME+" pulls a gem from his pocket and hands it to "+
      this_player()->query_name()+".\n", ({ this_player() }));

  gem = clone_object("/players/fred/closed/bloodfist/obj/gem.c");
  if(type > 0 && type < 8)
  {
    gem->set_stype(type);
    gem->set_held(1);
  }
  move_object(gem, this_player());
  return 1;
}

status list_cmd(string str)
{
  int c;
  if((string)this_player()->query_guild_name() != "bloodfist")
  {
    tell_room(environment(),
      ME+" ignores you.\n");
    return 1;
  }
  if(!str || str == "gems")
  {
    tell_room(environment(), 
      ME+" says, \"I have the following regular gems for sale.\"\n");
    for(c = 1; c < 8; c++)
      tell_room(environment(), "  "+c+".  "+capitalize(gnames[c])+"\n");
    tell_room(environment(),
    "\n"+ME+" says, \"All gems are 10000 gold.\"\n");
    call_out("list_also", 3);
    return 1;
  }
}

list_also()
{
  tell_room(environment(), 
    "\n"+ME+" says, \""+
    "Oh, I do also have unidentified gems, only 60000 gold.\"\n");
}

void catch_tell(string str)
{
  string t1, t2, t3;
  object me;
  if(sscanf(str, "%sbows%syou.", t1, t2) == 2)
  {
    me = this_player();
    if(me->is_player() && !me->query_attack())
      call_out("bow_back", 1, me);
  }
  else if(sscanf(str, "%s arrives.%s\n", t1, t2) == 2)
  {
    if(!random(5))
      call_out("arrives", 2, find_player(lower_case(t1)));
  }
}
