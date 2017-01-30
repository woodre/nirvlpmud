#include <ansi.h>
#define SIZE 25  /* 25 last channel msgs saved */
#define SAVE 600 /* save guild info every 10 minutes */
#define TIME_STYLE BOLD+BLK+"["+NORM+ctime()[11..15]+BOLD+BLK+"]"+NORM
#define STYLE HIR+"bf"+BOLD+BLK+">> "+NORM
#define STYLE2 HIR+"bfM"+BOLD+BLK+">> "+NORM
string *history,msg, *bfm_history;
object *all, *local_users, s, t;
int next,next2,a, sa, ls;

reset(arg){
  if(arg) return;

  next = 0;
  next2 = 0;
  history = allocate(SIZE);
  bfm_history = allocate(SIZE);
  call_out("autosave", SAVE);
}

autosave(){
  local_users = users();
  ls = sizeof(local_users);
  for(a = 0; a < ls; a++)
  {
    if((s = local_users[a]))
    {
      if((t = present("bloodfist_gob", s)) && s->query_level() < 20)
      {
        t->save_stats();
        tell_object(s, "\nSaving your guild stats...\n");
      }
    }
  }
  call_out("autosave", SAVE);
}

add_history(str, which){
  int a;
  if(which == 1)
  {
    history[next] = TIME_STYLE+str;
    next++;
    if(next >= SIZE)
    {
      next = (SIZE-1);
      for(a = 0; a < (SIZE-1); a++)
        history[a] = history[a+1];

    }
  }
  else if(which == 2)
  {
    bfm_history[next2] = TIME_STYLE+str;
    next2++;
    if(next2 >= SIZE)
    {
      next2 = (SIZE-1);
      for(a = 0; a < (SIZE-1); a++)
        bfm_history[a] = bfm_history[a+1];

    }
  }
}

print_history(object x, int which){
  int a;
  if(which == 1)
  {
    if(!next)
      tell_object(x, "There is currently no history.\n");
    else {
      tell_object(x, "Bloodfist Channel history:\n");
      for(a = 0; a < next; a++)
        tell_object(x, history[a]);
      tell_object(x, "\nCurrent time is: "+TIME_STYLE+"\n\n");
    }
  }
  else if(which == 2)
  {
    if(!next2)
      tell_object(x, "There is currently no history.\n");
    else {
      tell_object(x, "Bloodfist Private Channel history:\n");
      for(a = 0; a < next2; a++)
        tell_object(x, bfm_history[a]);
      tell_object(x, "\nCurrent time is: "+TIME_STYLE+"\n\n");
    }
  }
}

reset_history(object x, int which)
{
  if(which == 1) /* public */
  {
    tell_object(x, "You reset the public channel history.\n");
    next = 0;
  }
  else if(which == 2) /* private */
  {
    tell_object(x, "You reset the private channel history.\n");
    next2 = 0;
  }
}

/* if val == 1, normal msg
   if val == 2, emote
   if val == 3, echo
*/
print(object me, string str, int val){
  object gob;
  all = users();
  sa = sizeof(all);

  if(str == "mon")
  {
    int i,f,s,t;
    i = (int)me->query_intoxination()*100 / (me->query_max_intox());
    f = (int)me->query_stuffed()*100 / (me->query_max_stuff());
    s = (int)me->query_soaked()*100 / (me->query_max_soak());
    t = (int)me->query_infuse()*100 / ((me->query_level()*9)/2);
    str = "- Hp: ";
    str += me->query_hp()+"/"+me->query_mhp();
    str += "   Sp: ";
    str += me->query_sp()+"/"+me->query_msp();
    str += "  I "+i+"%";
    str += " F "+f+"%";
    str += " S "+s+"%";
    str += " T "+t+"%";

    if(val == 4) return str;
  }

  else if(str == "list")
  {
    int d;
    d = 0;
    str = "Bloodfist Channel members:";
    for(a = 0; a < sa; a++)
    {
      if(environment(all[a]) && present("bloodfist_gob", all[a]))
      {
        if((all[a]->query_level() >= 21 && !all[a]->query_invis()) ||
          (all[a]->query_level() < 21))
        {
          if(!d){
            str += "\nGuild: ";
            d = 1;
          }
          str += all[a]->query_name()+" ";
        }
      }
    }
    d = 0;
    for(a = 0; a < sa; a++)
    {
      if(environment(all[a]) && present("bloodfist_gob_chan", all[a])
        && present("bloodfist_gob_chan", all[a])->qk())
      {
        if((all[a]->query_level() >= 21 && !all[a]->query_invis()) ||
          all[a]->query_level() < 21)
        {
          if(!d){
            str += "\nOutside: ";
            d = 1;
          }
          str += all[a]->query_name()+" ";
        }
      }
    }
    str += "\n";

    tell_object(me, str);
    return 1;
  }

  gob = present("bloodfist_gob", me);

  if(val == 1)  /* normal message */
  {
    if(gob && gob->is_testchar())
      msg = msg = STYLE+capitalize((string)me->query_real_name())+
      " (testchar): "+str+"\n";
    else
      msg = STYLE+capitalize((string)me->query_real_name())+": "+str+"\n";
  }
  else if(val == 2)  /* emote */
  {
    if(gob && gob->is_testchar())
      msg = STYLE+capitalize((string)me->query_real_name())+
      " (testchar) "+str+"\n";
    else
      msg = STYLE+capitalize((string)me->query_real_name())+" "+str+"\n";
  }
  else if(val == 3)  /* echo */
    msg = STYLE+str+"\n";

  for(a = 0; a < sa; a++)
  {
    if(environment(all[a]) && ((gob = present("bloodfist_gob", all[a]))
      && !gob->query_bf_chan_muffle() ||
      (present("bloodfist_gob_chan", all[a]) && 
      present("bloodfist_gob_chan", all[a])->qk())))
      tell_object(all[a], msg);
  }
  add_history(msg, 1);
}

bfm(object me, string str, int val)
{
  object gob;
  all = users();
  sa = sizeof(all);
  if(val == 1)  /* normal message */
    msg = STYLE2+capitalize((string)me->query_real_name())+": "+str+"\n";
  else if(val == 2)  /* emote */
    msg = STYLE2+capitalize((string)me->query_real_name())+" "+str+"\n";
  for(a = 0; a < sa; a++)
  {
    if(environment(all[a]) && ((gob = present("bloodfist_gob", all[a])))
      && !gob->query_bf_chan_muffle())
      tell_object(all[a], msg);
  }
  add_history(msg, 2);
}

hprint(string str)
{
  all = users();
  sa = sizeof(all);
  msg = STYLE+str+"\n";
  for(a = 0; a < sa; a++)
  {
    if(environment(all[a]) && (present("bloodfist_gob", all[a])))
      tell_object(all[a], msg);
  }
  add_history(msg, 1);
}

login(object x){
  string a;
  if(x->query_level() < 21)
  {
    if(present("bloodfist_gob", x)->is_testchar())
      a = capitalize((string)x->query_real_name())+
      " (testchar) enters this world.";
    else if((a = present("bloodfist_gob", x)->query_inmsg())){}
    else
      a = capitalize((string)x->query_real_name())+
      " enters this world.";
    print(x,BOLD+BLK+a+NORM,3);
  }
}

logout(object x){
  string a;
  if(x->query_level() < 21)
  {
    if(present("bloodfist_gob", x)->is_testchar())
      a = capitalize((string)x->query_real_name())+
      " (testchar) leaves this world.";
    else if((a = (present("bloodfist_gob", x)->query_outmsg()))){}
    else
      a = capitalize((string)x->query_real_name())+
      " leaves this world.";
    print(x,BOLD+BLK+a+NORM,3);
  }
}

