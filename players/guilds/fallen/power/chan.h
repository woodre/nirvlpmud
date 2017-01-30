
/* recursive -Bp
#include "../defs.h"
*/

/*****************************/
/* The channel who itself */
/*****************************/
tell_ppl()
{
  object *a;
  int y,x;
  x = 1;
  a = users();
  for(y = 0; y < sizeof(a); y++)
  {
    if(a[y] == USER || (present("zeus_chatter", a[y]) &&
    (object)present("zeus_chatter", a[y])->query_maker() == USER) &&
    (object)present("zeus_chatter", a[y])->query_in())
    {
      write(pad("  "+x+":\t"+capitalize((string)a[y]->
        query_real_name()), 27));
      write("HP: "+getit(a[y]->query_hp(), a[y]->query_mhp())+"   ");
      write("SP: "+getit(a[y]->query_sp(), a[y]->query_msp())+"   ");
      if(a[y]->query_attack())
        write("Fighting: "+a[y]->query_attack()->query_name()+"   ");
      if(a[y]->query_inactive())
        write("Disconnected   ");
      if(a[y]->query_idle() > 900)
        write("Idle 15+");
      else if(a[y]->query_idle() > 600)
        write("Idle 10+");
      else if(a[y]->query_idle() > 300)
        write("Idle 5+");
      write("\n"+pad("", 30));
      write("Location:  "+environment(a[y])->short()+"\n");
      x++;
    }
  }
}

/*****************************/
/* To write to channel history */
/*****************************/
history(str)
{
  int x;
  for(x=0; x < sizeof(history); x++)
  {
    if(0 == history[x])
    {
      history[x] = str;
      return 1; 
    }
  }
  for(x=0; x < MAX-1; x++)
  {
    history[x] = history[x+1];
  }
  history[MAX-1] = str;
}

/*****************************/
/*  The monitor function  */
/*****************************/
/* Removed by Rumplemintz to try and fix mon
mon(object x){
  int i,f,s,t;
  string mon;
  i = (int)x->query_intoxination()*100 / (x->query_level()+3);
  f = (int)x->query_stuffed()*100 / (x->query_level()*8);
  s = (int)x->query_soaked()*100 / (x->query_level()*8);
  t = (int)x->query_infuse()*100 / ((x->query_level()*9)/2);
  mon = "- Hp: ";
  mon += x->query_hp()+"/"+x->query_mhp();
  mon += "   Sp: ";
  mon += x->query_sp()+"/"+x->query_msp();
  mon += "  I "+i+"%";
  mon += " F "+f+"%";
  mon += " S "+s+"%";
  mon += " T "+t+"%";
  dspeak(capitalize((string)x->query_real_name()), mon, 1);
}
*/


status dspeak(string who, string what, int echo)       /* dspeak */
{
  object *a;
  int y,w,v;
  string x,z;
  w = 0;
/*****************************/
/* To display channel history */
/*****************************/
  if(what == "history")
  {
    write(BOLD+BLK+"\n\tConversation history...\n\n"+NORM);
    for(v=0; v < sizeof(history); v++)
    {
      if(0 != history[v])
        write(history[v]);
    }
    write("\n");
    return 1;
  }
/*****************************/
/* To see who is on the channel */
/*****************************/
  if(what == "who")
  {
    write(BOLD+BLK+"\n\tConversation members...\n\n"+NORM);
    tell_ppl();
    write("\n");
    return 1;
  }
/*****************************/
/* To reset the channel history */
/*****************************/
  if(what == "reset history")
  {
    int t;
    tell_object(USER, RED+"[fallen] "+NORM+"The channel history has been reset.\n");
    for(t = 0; t < sizeof(history); t++)
    {
      history[t] = "";
    }
    return 1;
  }
  a = users();
  for(y = 0; y < sizeof(a); y++)
  {
    if(a[y] == USER || (present("zeus_chatter", a[y]) &&
    (object)present("zeus_chatter", a[y])->query_maker() == USER) &&
    (object)present("zeus_chatter", a[y])->query_in())
    {
        /*****************************/
        /* To echo on the channel */
        /*****************************/
        if(echo)
        {
          tell_object(a[y], RED+"[fallen] "+NORM+who+" "+what+"\n");
          if(0 == w)
          {
            history(RED+"[fallen] "+NORM+who+" "+what+"\n");
            w = 1;
          }
        }
        else if(sscanf(what, ":%s", z))
        {
        /*****************************/
        /* To emote on the channel */
        /*****************************/
          tell_object(a[y], RED+"[fallen] "+NORM+who+" "+z+"\n");
          if(0 == w)
          {
            history(RED+"[fallen] "+NORM+who+" "+z+"\n");
            w = 1;
          }
        }
        else {
        /*****************************/
        /* To talk on the channel */
        /*****************************/
          tell_object(a[y], RED+"[fallen] "+NORM+who+" speaks: "+
          what+"\n");
          if(0 == w)
          {
            history(RED+"[fallen] "+NORM+who+" speaks: "+what+"\n");
            w = 1;
          }
        }
    }  /* end player_chatter */
  }  /* end for */
  return 1;
}

status speak_cmd(string str)                    /* speak */
{
  object *a;
  string who,w,z;
  object add;
  int x,y,v;
  v = 0;
  if(!str)
  {
    /*****************************/
    /* To get channel commands */
    /*****************************/
    write(BOLD+BLK+"\n\tConversation commands...\n\n"+NORM+
      "\t  speak / sp\t\ttalk on channel\n"+
      "\t   <:>\t\t\temote\n"+
      "\t   <who>\t\tsee who is on the channel\n"+
      "\t   <mon>\t\ttell everyone your status\n"+
      "\t   <reset history>\treset the channel history\n"+
      "\t   <invite [who]>\tinvite [who] to join\n"+
      "\t   <remove [who]>\tremove [who] from channel\n"+
      "\t   <remove all>\t\tremove everyone\n"+
      "\t   <history>\t\tsee the channel history\n"+
      "\n");
    return 1;
  }
/*****************************/
/*   USER monitor     */
/*****************************/
/* Removed by Rumplemintz.
  if(str == "mon")
  {
    mon(USER);
    return 1;
  }
*/
/*****************************/
/* To remove players    */
/*****************************/
  if(sscanf(str, "remove %s", who))
  {
    a = users();
    for(y = 0; y < sizeof(a); y++)
    {
      if((string)a[y]->query_real_name() == who)
      {
        if(USER == a[y])
        {
          write("You can not remove yourself.\n");
          return 1;
        }
        if(present("zeus_chatter", a[y]))
        {
          dspeak(capitalize(who),
            "has been removed from the conversation.",1);
          present("zeus_chatter", a[y])->set_owner(0);
          destruct(present("zeus_chatter", a[y]));
          return 1;
        }
      } 
    }  /* end single && for */
    if(who == "all")
    {
      dspeak(capitalize((string)NAME), "has ended the conversation.",1);
      for(y = 0; y < sizeof(a); y++)
      {
        if(a[y] != USER)
        {
          if(present("zeus_chatter", a[y]))
          {
            present("zeus_chatter", a[y])->set_owner(0);
            destruct(present("zeus_chatter", a[y]));
          }
        }
      }
      write("All players have been removed from the conversation.\n");
      return 1;
    } /* end all */
  } /* end remove */
/*****************************/
/* To add a player    */
/*****************************/
  if(sscanf(str, "invite %s", who))
  {
    if(find_player(who))
    {
      if(present("zeus_chatter", find_player(who)))
      {
        if((object)present("zeus_chatter", find_player(who))->
          query_maker() == USER)
        {
          write(capitalize(who)+" is already in the conversation.\n");
          return 1;
        }
        write( capitalize(who)+" is already in a conversation.\n");
        return 1;
      }
      if(present("circle_object", find_player(who)))
      {
        if(find_player(who) == USER)
        {
          write("You can't invite yourself, smart guy.\n");
          return 1;
        }
        write("You can not invite a fellow guild member.\n");
        return 1;
      }
      if((int)find_player(who)->query_level() > 19 &&
        (int)this_player()->query_level() < 20)
      {
        write("You can not invite a wizard.\n");
        return 1;
      }
      if(find_player(who)->query_attack())
      {
        write("You can't invite someone who is in combat.\n");
        return 1;
      }
      add = clone_object("/players/guilds/fallen/OBJ/chan_obj");
      add->set_owner(USER);
      add->set_maker(USER);
      dspeak(capitalize((string)NAME), "has invited "+
        capitalize((string)find_player(who)->query_real_name())+
        " to join the conversation.", 1);
      move_object(add, find_player(who));
      return 1;
    } /* end find_player */
  } /* end sscanf for who */
/*****************************/
/* Pass on the message    */
/*****************************/
  dspeak(capitalize((string)NAME),str,0);
  return 1;
}

