inherit "/obj/treasure.c";
#define SKILLS (({"sword", "knife", "club", "axe", "bow", "polearm", "shield", "horse"})) 

reset(arg)
{
  set_name("tool");
  SetMultipleIds(({"templar tool","wand","templar wand"}));
}

short()
{
  if(this_player()->query_level() < 20) return;
  return "Templar Tool";
}

long()
{
  tell_object(this_player(),
  "This tool can be used to for the following things:\n\n"+
  "Set Skill:              sskill <name> <skill> <level>\n"+
  "Set Rank:               srank <name> <rank>\n"+
  "Set Guild Exp:          sgexp <name> <amount>\n"+
  "Add Guild Exp:          agexp <name> <amount>\n\n");
}

drop(){ return 1; }

get(){ return 1; }

init()
{
  ::init();
  if(!environment(this_object())) return 1;
  if(!environment(this_object())->is_player()) return 1;
  if(this_player()->query_level() > 19)
  {
    add_action("Cmd_sskill","sskill");
    add_action("Cmd_srank","srank");
    add_action("Cmd_sgexp","sgexp");
    add_action("Cmd_agexp","agexp");
  }
}

Cmd_sskill(str)
{
  int x, i, y, skill;
  object who, cross;
  string what;
  if(!str)
  {
    write("sskill <name> <skill> <level>\n");
    return 1;
  }
  if(sscanf(str, "%s %s %d", str, what, x) !=3)
  {
    write("sskill <name> <skill> <level>\n"); 
    return 1;
  }
  who = find_player(str);
  if(!who)
  {
    write(capitalize(str)+" is not logged on.\n");
    return 1;
  }
  cross = present("KnightTemplar", who);
  if(!cross)
  {
    write(capitalize(str)+" is not a member of the Knights Templar.\n");
    return 1;
  }
  if(member_array(what, SKILLS) == -1)
  {
    write(capitalize(what)+" is not a skill that can be trained.\n");
    return 1;
  }
  skill = (int)cross->query_skill(what);
  y = (x - skill);
  if(x > 10)
  {
    write("You can't set "+capitalize(str)+"'s "+what+" that high.\n");
    return 1;
  }
  if(y > 0)
  {
    for(i=0; i<y; i++)
    {
      cross->add_skill(what,1);
      cross->save_ob();
    }
  }
  if(y < 0)
  {
    for(i=0; i>y; i--)
    {
      cross->add_skill(what,-1);
      cross->save_ob();
    }
  }

  tell_object(this_player(),
  "You set "+capitalize(str)+"'s "+what+" skill to "+x+"\n");

  tell_object(who,
  this_player()->query_name()+" has set your "+what+" to "+x+"\n");
  return 1;
}

Cmd_srank(str)
{
  int x;
  object who, cross;
  if(!str)
  {
    write("srank <name> <rank>\n");
    return 1;
  }
  if(sscanf(str, "%s %d", str, x) !=2)
  {
    write("srank <name> <rank>\n"); 
    return 1;
  }
  who = find_player(str);
  if(!who)
  {
    write(capitalize(str)+" is not logged on.\n");
    return 1;
  }
  cross = present("KnightTemplar", who);
  if(!cross)
  {
    write(capitalize(str)+" is not a member of the Knights Templar.\n");
    return 1;
  }
  if(x > 10)
  {
    write("You can't set "+capitalize(str)+"'s rank that high.\n");
    return 1;
  }
  if(x < 0)
  {
    write("You can't set "+capitalize(str)+"'s rank to a negative number.\n");
    return 1;
  }
  
  who->set_guild_rank(x);
  
  tell_object(this_player(),
  "You set "+capitalize(str)+"'s rank to "+x+"\n");

  tell_object(who,
  this_player()->query_name()+" has set your rank to "+x+"\n");
  return 1;
}

Cmd_sgexp(str)
{
  int x;
  object who, cross;
  if(!str)
  {
    write("sgexp <name> <amount>\n");
    return 1;
  }
  if(sscanf(str, "%s %d", str, x) !=2)
  {
    write("sgexp <name> <amount>\n"); 
    return 1;
  }
  who = find_player(str);
  if(!who)
  {
    write(capitalize(str)+" is not logged on.\n");
    return 1;
  }
  cross = present("KnightTemplar", who);
  if(!cross)
  {
    write(capitalize(str)+" is not a member of the Knights Templar.\n");
    return 1;
  }
  if(x < 0)
  {
    write("You can't set "+capitalize(str)+"'s guild experience to a negative number.\n");
    return 1;
  }
  
  who->set_guild_exp(x);
  
  tell_object(this_player(),
  "You set "+capitalize(str)+"'s guild experience to "+x+"\n");

  tell_object(who,
  this_player()->query_name()+" has adjusted your guild experience to "+x+"\n");
  return 1;
}

Cmd_agexp(str)
{
  int x, y;
  object who, cross;
  if(!str)
  {
    write("agexp <name> <amount>\n");
    return 1;
  }
  if(sscanf(str, "%s %d", str, x) !=2)
  {
    write("agexp <name> <amount>\n"); 
    return 1;
  }
  who = find_player(str);
  if(!who)
  {
    write(capitalize(str)+" is not logged on.\n");
    return 1;
  }
  cross = present("KnightTemplar", who);
  if(!cross)
  {
    write(capitalize(str)+" is not a member of the Knights Templar.\n");
    return 1;
  }
  y = who->query_guild_exp();
  if((x+y)<0)
  {
    write("You can't set "+capitalize(str)+"'s guild experience to a negative number.\n");
    return 1;
  }  
  
  who->add_guild_exp(x);
  
  tell_object(this_player(),
  "You add "+x+" to "+capitalize(str)+"'s guild experience.\n");

  tell_object(who,
  this_player()->query_name()+" has adjusted your guild experience by "+x+".\n");
  return 1;
}
