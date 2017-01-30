inherit "/obj/treasure.c";
#include "/players/fred/closed/bloodfist/defs.h"
int stype, ws, spec, size, x;
object gem, gob, own;
string *gnames, *spec1, *spec2, *spec3, *local_gems, *num;

reset(arg){

  gnames =({ "crystal gem", "ruby gem", "emerald gem", "sapphire gem", 
    "diamond gem", "onyx gem", "topaz gem", "amethyst gem", 
  });

  spec1 =({ "crystal gem", "minor gem of agility", "minor gem of might", 
    "minor gem of accuracy", "minor gem of vigor", "minor gem of wisdom",
    "minor gem of faith", "prismatic gem", "gem of decay", "chaos gem",
    "gem of purity", "gem of hatred", "minor gem of performance",
    "gem of beauty", "gem of fury", "gem of eternity", "vortex gem",
    "lightning gem", "gem of unholy death rites", "gem of fortitude",
    "gem of moss", "gem of rain", "gem of idiocy", "gem of emotion",
    "minor gold gem", "minor gem of regeneration", 
    "minor gem of rejuvenation", "minor gem of restoration",
    "gem of instability", "faerie gem", "gem of pk", "gem of winter",
    "minor gem of cleansing", "gem of combat skills",
  });

  spec2 =({ "crystal gem", "gem of agility", "gem of might",
    "gem of accuracy", "gem of vigor", "gem of wisdom", "gem of faith",
    "soul gem", "gem of speed", "gem of performance", "blood gem",
    "sand gem", "ryo gem", "xetra gem", "gold gem", "angelic gem",
    "demonic gem", "gem of regeneration", "gem of rejuvenation",
    "gem of restoration", "gem of provoked aggression", "gem of the dragon",
    "gem of cleansing",
  });

  spec3 =({ "crystal gem", "major gem of agility", "major gem of might", 
    "major gem of accuracy", "major gem of vigor", "major gem of wisdom",
    "major gem of faith", "major gem of performance", "major gold gem",
    "gem of zeus", "holy angelic gem", "unholy demonic gem",
    "major gem of regeneration", "major gem of rejuvenation",
    "major gem of restoration", "minds eye gem", "gem of inescapable horror",
    "major gem of cleansing", "gem of battle rites", "sage gem",
    "timeless gem",
  });
  
  num = ({"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11",
          "12", "13", "14", "15", "16", "17", "18", "19", "20", "21",
          "22", "23", "24", "25",
  });

  set_long(
"This is a somewhat small treasure chest used to store gems.  There is\n"+
"a lock on the front that keeps anyone but the owner from getting into\n"+
"it.  It is a rather plain chest and easy to overlook in the room.\n");
}

id(str){ return str == "chest" || str == "treasure chest"
|| str == "f_bf_gem_tc"; }

short(){
  if(this_player()->query_guild_name() == "bloodfist")
    return "A treasure chest";
  else
    return 0;
}

drop(){              return 1; } 
get(){               return 0; }
can_put_and_get(){   return 0; }

void init(){
  ::init();
  if(!environment()) return;
  if(!environment()->query_bf_priv_room()) return 0;

  add_action("deposit",  "deposit");
  add_action("list",     "list");
  add_action("withdraw", "withdraw");
  add_action("show",     "show");
}

int owner_check(string name)
{
  string myname;
  if(!environment()) return 0;
  if(!environment()->query_bf_priv_room()) return 0;
  myname = (string)environment()->query_owner();
  if(myname != name) return 0;
  return 1;
}

show(str)
{
  if(str != "chest" && str != "gems" && str != "contents") return 0;
  if(!owner_check(this_player()->query_real_name())) return 0;
  if(!(gob = present("bloodfist_gob", this_player())))
  {
    write("No gob present.\n");
    return 1;
  }
  local_gems = gob->query_gems();
  size = gob->query_stored_gems();
  if(!size)
  {
    write("There are no gems in your chest.\n");
    return 1;
  }
  tell_room(environment(), this_player()->query_name()+" shows the "+
    "room the contents of "+this_player()->POS+
    " treasure chest.\n", ({ this_player() }));
  write("You show the room the contents of your treasure chest.\n");
  for(x = 0; x < size; x++)
  {
    if(local_gems[x])
    {
      tell_room(environment(), " "+(x+1)+". ");
      if(sscanf(local_gems[x], "%d %d %d", spec, ws, stype))
      {
        if(stype)
          tell_room(environment(), gnames[stype]);
        else if(spec == 1)
          tell_room(environment(), spec1[ws]);
        else if(spec == 2)
          tell_room(environment(), spec2[ws]);
        else if(spec == 3)
          tell_room(environment(), spec3[ws]);
        else
          tell_room(environment(), "crystal gem");
      }
      tell_room(environment(), "\n");
    }
    else
      tell_room(environment(), "blank\n");
  }
  return 1;
}

list(){
  if(!owner_check(this_player()->query_real_name())) return 0;
  if(!(gob = present("bloodfist_gob", this_player())))
  {
    write("No gob present.\n");
    return 1;
  }
  local_gems = gob->query_gems();
  size = gob->query_stored_gems();
  if(!size)
  {
    write("There are no gems in your chest.\n");
    return 1;
  }
  write("You look to see what gems are in your treasure chest.\n");
  for(x = 0; x < size; x++)
  {
    if(local_gems[x])
    {
      write(" "+(x+1)+". ");
      if(sscanf(local_gems[x], "%d %d %d", spec, ws, stype))
      {
        if(stype)
          write(gnames[stype]);
        else if(spec == 1)
          write(spec1[ws]);
        else if(spec == 2)
          write(spec2[ws]);
        else if(spec == 3)
          write(spec3[ws]);
        else
          write("crystal gem");
      }
      write("\n");
    }
    else
      write("blank\n");
  }
  return 1;
}

withdraw(string x){ /* x is the gem number, 1 above the index */
  object new_gem;
  string gem_info;
  int index;
  if(!owner_check(this_player()->query_real_name())) return 0;
  if(member_array(x, num) < 0)
  {
    tell_object(this_player(),
      "You may 'withdraw #' of the gem you want.\n");
    return 1;
  }
  if(!(gob = present("bloodfist_gob", this_player())))
  {
    write("No gob present.\n");
    return 1;
  }
  sscanf(x, "%d", index);
  if(!(gem_info = gob->get_gem((index))))
  {
    write("You don't seem to have that gem.\n");
    return 1;
  }
  if(sscanf(gem_info, "%d %d %d", spec, ws, stype))
  {
    new_gem = clone_object("/players/fred/closed/bloodfist/obj/gem.c");
    new_gem->set_stype(stype);
    new_gem->set_spec(spec);
    new_gem->set_ws(ws);
    new_gem->set_held(1);
    move_object(new_gem, this_player());
    write("You withdraw, \""+new_gem->short()+"\", from the chest\n");
    say(this_player()->query_name()+" takes something from "+
      this_player()->POS+" treasure chest.\n");
    gob->advance_checks();
    gob->save_stats();
    return 1;
  }
  else
    write("You can't withdraw that gem.\n");
  return 1;
}

status deposit(string str){
  if(!owner_check((string)this_player()->query_real_name())) return 0;
  if(str != "gem") return 0;
  if(!(gem = present("fred_bloodfist_gem", this_player())))
  {
    write("You do not have a gem to deposit.\n");
    return 1;
  }
  if(!(gob = present("bloodfist_gob", this_player())))
  {
    write("No gob present.\n");
    return 1;
  }
  if(gob->add_gem(gem->query_spec(), gem->query_ws(), gem->query_stype()))
  {
    write("You carefully place your "+gem->short()+" in the chest.\n");
    say(this_player()->query_name()+" puts something in "+
      this_player()->POS+" treasure chest.\n");
    destruct(gem);
    gob->advance_checks();
    gob->save_stats();
  }
  else
    write("You were unable to deposit the gem.\n");
  return 1;
}
