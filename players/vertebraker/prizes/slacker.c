#include <ansi.h>

inherit "/obj/treasure";

reset(arg)
{
  if(arg) return;
  set_id("lightning bolt tattoo");
  set_alias("lightning bolt");
  SetMultipleIds(({"bolt","bolt tattoo","lightning tattoo",
                   "tattoo of a lightning bolt"}));
  set_short("A tattoo of a "+HIY+"lightning bolt"+NORM);
  set_long("\
Emblazoned on your shoulder is a tattoo of a bright\n\
yellow "+HIY+"lightning bolt"+NORM+".\n");
  set_weight(0);
  set_value(0);
}

int drop() { return 1; }

query_auto_load() { return basename(this_object())+":0"; }

init()
{
  add_action("cmd_bolt","bolt");
}

cmd_bolt(str)
{
  object atk;
  string msg1, msg2;
  int    num;
  
  if(!str) atk = this_player()->query_attack();
  else atk = present(str, environment(this_player()));
  
  if(!atk) {
    write("You don't see \""+str+"\" here.\n");
    return 1;
  }
  
  if(!this_player()->valid_attack(atk))
    return 1;
    
  if(this_player()->query_spell_dam())
    return 1;
    
  if(this_player()->query_sp() < 25)
  {
    write("You need [25] spell points.\n");
    return 1;
  }
  
  msg1 = "whispered an incantation and the sky "+HIK+"darkened"+NORM+"\n\
menacingly overhead.\n";
  num = 1 + random(12);
  msg2 = "A blinding "+HIC+num+",000"+NORM+" amp bolt of "+
HIY+"lightning"+NORM+" arcs down\n\
and "+HIY+"STRIKES"+NORM+" ";
  
  this_player()->spell_object(atk,
    "lightning bolt",
    33 + num,
    25,
    "You "+msg1+msg2+atk->query_name()+"!\n",
    this_player()->query_name()+" "+msg1+msg2+"you!\n",
    this_player()->query_name()+" "+msg1+msg2+atk->query_name()+"!\n");
  this_player()->set_spell_dtype("other|electric");
  return 1;
}