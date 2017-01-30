/* tmieczkowski@hotmail.com [v] */

#include <ansi.h>
#include "/players/vital/closed/headers/channel.h"
#include "/bin/all.h"

#define CAP capitalize
#define t this_player()

/*
 * Room [nontarget]
 * a[0]= What you see
 * a[1]= What room sees
 *
 * Room [target]
 * a[2]= What you see
 * a[3]= What room sees, except target
 * a[4]= What target sees
 *
 *
 * Afar
 * a[5] = What you see
 * a[6] = What target sees
 */

mixed *a;

void reset(int x) { if(!x) a=allocate(7); }

void
nontarget(string d, string e)
{
    a[0]=d;
    a[1]=e;
}

void
target(string d, string e, string f)
{
    a[2]=d;
    a[3]=e;
    a[4]=f;
}

void
afar(string d, string e)
{
    a[5]=d;
    a[6]=e;
}

mixed * query_junk() { return a; }
string
replace_read(string arg, object target)
{
    switch(arg)
    {
      case "MN":  /* my name */
        return (string)t->query_name();
      case "MP":  /* my possessive */
        return possessive(t);
      case "MS":  /* my subjective */
        return subjective(t);
      case "MO":  /* my objective */
        return objective(t);
      case "TN":  /* target name */
        return ((string)target->query_name() != "some mist" ? (string)target->query_name() : (string)target->short());
      case "TP":  /* target possessive */
        return possessive(target);
      case "TS":  /* target subjective */
        return subjective(target);
      case "TO":  /* target objective */
        return objective(target);
      case "RET": /* carriage return */
         return "\n";
      case "CMN": return capitalize((string)t->query_name());
      case "CTN": return capitalize((string)target->query_name());
      case "CMP": return capitalize(possessive(t));
      case "CMS": return capitalize(subjective(t));
      case "CMO": return capitalize(objective(t));
      case "CTO": return capitalize(objective(target));
      case "CTS": return capitalize(subjective(target));
      case "CTP": return capitalize(possessive(target));
    }
    return arg;
}
      

string
x(string arg, object target)
{
   int s; 
   string *words, rr;
   object play_ob;

   words = explode(arg, "#");
   s = sizeof(words);

   while(s--)
     if(rr=replace_read(words[s], target))
       words[s] = rr;

   arg = (implode(words, ""));

   words = explode(arg, "$");
   play_ob = find_object("/obj/player");
   if(!play_ob) {
    "/obj/player"->load_me();
    play_ob = find_object("/obj/player");
  }
   s = sizeof(words);

   while(s--)
   {
     if(rr=(string)play_ob->replace_ansi(words[s], target))
       words[s] = rr;
     if(rr=replace_read(words[s], target))
       words[s] = rr;
  }

   arg = (implode(words, "")) + esc + "[0m";
   return arg;
}

int
do_cmd(string arg)
{
    object ob;
    int       z;

    if(ghost()) return 0;

    if(!arg)
    {

      if(stringp(a[0]) && a[0] != "0\n" && a[0] != "0$N$\n")
      {
        z=1;
        write(x(a[0], ob));
      }
      if(stringp(a[1]) && a[1] != "0\n" && a[1] != "0$N$\n")
      {
        z=1;
        this_player()->remote_say(x(a[1], ob));
      }
      if(!z)
        return (notify_fail(capitalize(query_verb()) + " who?\n"), 0);
        return 1;
    }
    else
    {
      if(!(ob = arg_check(arg)))
        return 0;
      if(environment(ob) == environment(t))
      {
        if(stringp(a[2]) && a[2] != "0\n" && a[2] != "0$N$\n")
        {
          z=1;
          write(x(a[2], ob));
        }
        if(stringp(a[3]) && a[3] != "0\n" && a[3] != "0$N$\n")
        {
          z=1;
          this_player()->remote_say(x(a[3], ob), ob);
        }
        if(stringp(a[4]) && a[4] != "0\n" && a[4] != "0$N$\n")
        {
          z=1;

          tell_object(ob, x(a[4], ob) + "->> ");
        }
        if(!z)
          return 0;
        return 1;
      }
      else
      {
        if(stringp(a[5]) && a[5] != "0\n" && a[5] != "0$N$\n")
        {
          z=1;
          write(x(a[5], ob));
        }
        if(stringp(a[6]) && a[6] != "0\n" && a[6] != "0$N$\n")
        {
          z=1;

          tell_object(ob, x(a[6], ob) + "->> ");
        }
        if(!z)
          return (notify_fail("You don't see " + capitalize(arg) + 
                   " around you.\n"), 0);
        return 1;
      }
    }
}

string br_format_rets(string msg, string channel)
{
  string *arr;
  arr = explode(msg, "\n");
 if(sizeof(arr) > 1)
  arr = arr[0..sizeof(arr)-2];
  return (implode(arr, "\n("+channel+") ")+"\n");
}

string br_format_ansiprefs(string msg, string channel, object play)
{
  string ansi, heh, what;
  heh = implode(explode(msg, "("+channel+")"), ((
     ansi=(string)play->get_ansi_pref(channel))?ansi:"")+
     ("("+channel+")"+NORM));
  return ((ansi?ansi:"")+"("+channel+")"+NORM+" "+heh);
}

int guildcast(string channel, string who)
{
  string channel_obj, junk, msg, msg2, msg3;
  string query_tag_func, query_users_func, history_func;
  object play, *us, ob;
  string tag, *j;
  int tag_length, s, ll;
  
  play = this_player();

  switch(channel)
  {
      /* illarion implemented bards */
      case "black circle":
        query_tag_func = "query_tag";
        query_users_func = "query_bcms";
        history_func = "add_history";
        channel_obj = "/players/fred/mages/obj/verte_chan";
        break;
      case "bloodfist":
        if(query_verb() == "bf") {
          query_tag_func = "query_bf_tag";
          query_users_func = "query_bfs";
          history_func = "add_bf_history";
        }
        else if(query_verb() == "bfm") {
          query_tag_func = "query_bfm_tag";
          query_users_func = "query_bfms";
          history_func = "add_bfm_history";
        }
        channel_obj = "/players/fred/closed/bloodfist/daemon/verte_chan";
        break;
      case "cyberninja":
        if(query_verb() == "nem") {
          query_tag_func = "query_nem_tag";
          query_users_func = "query_listeners";
          history_func = "addhistory";
        }
        else if(query_verb() == "onem") {
          query_tag_func = "query_onem_tag";
          query_users_func = "query_officers";
          history_func = "add_ohistory";
        }
        channel_obj = "/players/dune/closed/guild/daemons/channels";
        break;
      case "Dark Order":
        query_tag_func = "query_tag";
        query_users_func = "query_dos";
        history_func = "add_history";
        channel_obj = "/players/pestilence/closed/dark/daemons/verte_chan";
        break;
      case "rangers":
        query_tag_func = "query_tag";
        query_users_func = "query_rangers";
        history_func = "add_history";
        channel_obj = "/players/vital/Rangers/verte/verte_chan";
        break;
      case "Knights Templar":
        query_tag_func = "query_tag";
        query_users_func = "query_knights";
        history_func = "add_history";
        channel_obj = "/players/boltar/templar/daemon/vk_chan";
        break;
      case "shardak":
        if(query_verb() == "ge" || query_verb() == "gte" || query_verb() == "ae") {
          query_tag_func = "query_gte_chan";
          query_users_func = "query_all";
          history_func = "add_gte_history";
        }
        else {
          query_tag_func = "query_gpe_chan";
          query_users_func = "query_servants";
          history_func = "add_gpe_history";
        }
        channel_obj = "/players/vertebraker/closed/shardak/daemons/channel";
        break;
      case "vampire":
        query_tag_func = "query_tag";
        query_users_func = "query_vampires";
        history_func = "add_history";
        channel_obj = "/players/eurale/VAMPIRES/daemons/verte_chan";
        break;
      case "necromancer":
        query_tag_func = "query_tag";
        query_users_func = "query_listeners";
        history_func = "addhistory";
        channel_obj = "/players/wocket/necro/obj/daemons/channel_d";
        break;
      case "dervish":
        query_tag_func = "query_tag";
        query_users_func = "query_listeners";
        history_func = "add_history";
        channel_obj = "/players/snow/dervish/objects/chatob";
        break;
      case "mage":
        query_tag_func="query_tag";
        query_users_func="query_mages";
        history_func="add_history";
        channel_obj="/players/vertebraker/guilds/mages/obj/verte_chan";
        break;
      case "star":
        query_tag_func = "query_tag";
        query_users_func = "query_stars";
        history_func = "add_history";
        channel_obj = "/players/pain/NEW/items/star_daemon";
        break;
  }
  
  if(who && who != "someone")
  {
    if(!(ob=find_player(who,1)) ||
       ((int)ob->query_invis() >
        (int)play->query_level()))
    {
      write("You don't see "+CAP(who)+" on Nirvana.\n");
      return 1;
    }
    
    call_other(channel_obj, "???");
    
    s = sizeof(us = (object*)call_other(channel_obj, query_users_func));
    
    if(member_array(ob, us) == -1)
    {
      write(CAP(who)+" is not on the "+channel+" channel.\n");
      return 1;
    }
  }
  
  else if(who)
    if(!(ob = find_object("/bin/soul/someone_dummy")))
      ob = (object)"/bin/soul/someone_dummy"->LoadMe();
  
  s = sizeof(us = (object*)call_other(channel_obj, query_users_func));
      
  if(who)
  {
    if(stringp(junk=a[2]) && junk != "0\n" && junk != "0$N$\n")
      msg = x(junk, ob);
    if(stringp(junk=a[3]) && junk != "0\n" && junk != "0$N$\n")
      msg2 = x(junk, ob);
    if(stringp(junk=a[4]) && junk != "0\n" && junk != "0$N$\n")
      msg3 = x(junk, ob);
  }
  else
  {
    if(stringp(junk=a[0]) && junk != "0\n" && junk != "0$N$\n")
      msg = x(junk, ob);
    if(stringp(junk=a[1]) && junk != "0\n" && junk != "0$N$\n")
      msg2 = x(junk, ob);
  }
  
  tag = (string)call_other(channel_obj, query_tag_func);
  
  tag += " ";
  
  tag_length = strlen(delete_colour(tag));
  
  msg  = tag+implode(explode(msg,  "\n"), "\n"+pad("",tag_length,' '));
  
  msg2 = tag+implode(explode(msg2, "\n"), "\n"+pad("",tag_length,' '));
  
  j = explode(msg, "\n");
  j -= ({ j[sizeof(j)-1] });
  msg = implode(j, "\n") + "\n";
  
  j = explode(msg2, "\n");
  j -= ({ j[sizeof(j)-1] });
  msg2 = implode(j, "\n") + "\n";
  
  if(msg3)
  {
    msg3 = tag+implode(explode(msg3, "\n"), "\n"+pad("",tag_length,' '));
    j = explode(msg3, "\n");
    j -= ({ j[sizeof(j)-1] });
    msg3 = implode(j, "\n") + "\n";
  }
  
  write(msg);
  
  while(s --)
  {
    if(us[s] && us[s] != play && us[s] != ob && environment(us[s]))
    {
      tell_object(us[s], msg2);
    }
  }
  
  if(msg3)
    tell_object(ob, msg3);
  
  call_other(channel_obj, history_func, msg2);
  return 1;
}

mixed
channel_emote(string channel, string who)
{
  object fd, ob, play, *us;
  string msg, msg2, msg3, junk;
  int    s;
  play = this_player();
  if(who && who != "someone")
  {
    if(!(ob = find_player(who,1)) ||
       ((int)ob->query_invis() >
        (int)play->query_level()))
    {
      tell_object(play, "You don't see "+CAP(who)+" on Nirvana.\n");
      return 1;
    }
    if( CHANNELD->query_channel(channel, who) )
    {
      tell_object(play, CAP(who)+" is not on the "+channel+" channel.\n");
      return 1;
    }
    if(ob->query_muffled())
    {
      write(CAP(who)+" is muffling all channels.\n");
      return 1;
    }
  }
  else if(who)
    if(!(ob = find_object("/bin/soul/someone_dummy")))
      ob = (object)"/bin/soul/someone_dummy"->LoadMe();
  if(who)
  {
    if(stringp(junk=a[2]) && junk != "0\n" && junk != "0$N$\n")
      msg = x(junk, ob);
    if(stringp(junk=a[3]) && junk != "0\n" && junk != "0$N$\n")
      msg2 = x(junk, ob);
    if(stringp(junk=a[4]) && junk != "0\n" && junk != "0$N$\n")
      msg3 = x(junk, ob);
  }
  else
  {
    if(stringp(junk=a[0]) && junk != "0\n" && junk != "0$N$\n")
      msg = x(junk, ob);
    if(stringp(junk=a[1]) && junk != "0\n" && junk != "0$N$\n")
      msg2 = x(junk, ob);
  }
  if( member_array(channel, CENSORED_CHANNELS ) )
  {
   if(msg)
    msg = (string)"/obj/verte/text_sanitizer"->sanitize_text(msg);
    if(msg2) msg2 = (string)"/obj/verte/text_sanitizer"->sanitize_text(msg2);
    if(msg3) msg3 = (string)"/obj/verte/text_sanitizer"->sanitize_text(msg3);
  }
  if(msg)
    msg  = br_format_rets(msg, channel);
  if(msg2) 
    msg2 = br_format_rets(msg2, channel);
  if(msg3)
    msg3 = br_format_rets(msg3, channel);
  if(msg)
    tell_object(play, br_format_ansiprefs(msg, channel, play));
  if(msg3)
    tell_object(ob, br_format_ansiprefs(msg3, channel, ob));
  s = sizeof(us = users());
  if(msg2)
    return msg2;
  return "This is a botched emote string.\n";
}

int broadcast(string channel, string who)
{
  object fd, ob, play, *us;
  string msg, msg2, msg3, junk;
  int    s;
  
  play = this_player();

  if(who && who != "someone")
  {
    if(!(ob = find_player(who,1)) ||
       ((int)ob->query_invis() >
        (int)play->query_level()))
    {
      write("You don't see "+CAP(who)+" on Nirvana.\n");
      return 1;
    }
    if(!ob->on_channel(channel))
    {
      write(CAP(who)+" is not on the "+channel+" channel.\n");
      return 1;
    }
    if(ob->query_muffled())
    {
      write(CAP(who)+" is muffling all channels.\n");
      return 1;
    }
  }
  
  else if(who)
    if(!(ob = find_object("/bin/soul/someone_dummy")))
      ob = (object)"/bin/soul/someone_dummy"->LoadMe();
      
  if(who)
  {
    if(stringp(junk=a[2]) && junk != "0\n" && junk != "0$N$\n")
      msg = x(junk, ob);
    if(stringp(junk=a[3]) && junk != "0\n" && junk != "0$N$\n")
      msg2 = x(junk, ob);
    if(stringp(junk=a[4]) && junk != "0\n" && junk != "0$N$\n")
      msg3 = x(junk, ob);
  }
  else
  {
    if(stringp(junk=a[0]) && junk != "0\n" && junk != "0$N$\n")
      msg = x(junk, ob);
    if(stringp(junk=a[1]) && junk != "0\n" && junk != "0$N$\n")
      msg2 = x(junk, ob);
  }
  
  if(channel != "risque" && channel != "wiz" && channel != "admin" &&
     channel != "pk" && channel != "announce")
  {
   if(msg)
    msg = (string)"/obj/verte/text_sanitizer"->sanitize_text(msg);
    if(msg2) msg2 = (string)"/obj/verte/text_sanitizer"->sanitize_text(msg2);
    if(msg3) msg3 = (string)"/obj/verte/text_sanitizer"->sanitize_text(msg3);
  }
  "/obj/user/chistory"->add_history(channel, msg2);
  if(msg)
  msg  = br_format_rets(msg, channel);
  if(msg2) 
  msg2 = br_format_rets(msg2, channel);
 if(msg3)
  msg3 = br_format_rets(msg3, channel);
 
 if(msg)
  write(br_format_ansiprefs(msg,channel,play));
  
  if(msg3)
    tell_object(ob, br_format_ansiprefs(msg3,channel,ob));
  
   
  s = sizeof(us = users());
  if(msg2)
  while(s--)
    if(((fd=us[s]) && fd->on_channel(channel) && 
       (fd != play) && (fd != ob) &&
       !fd->query_muffled()) || channel == "announce")
      tell_object(fd, br_format_ansiprefs(msg2,channel,fd));
  return 1;
}
