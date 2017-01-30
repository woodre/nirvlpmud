/*
 * Bard channel object.  For now it simply holds the channel history, but
 * I'll gradually be adding the rest of the channel functions
 * to it as well.
 */
#include "/players/guilds/bards/def.h"
#include <ansi.h>
#define SOCIAL "/players/guilds/bards/socials/bard_social"

string *channel_history;
int last_entry;
object *instruments;

varargs void guild_broadcast(string str,status override_toggle);

void reset(status arg) {
  if(!channel_history) channel_history=allocate(20);
  if(!instruments) instruments=({});
}

void add_instrument(object ob) {
  if(member_array(ob,instruments) == -1) {
    instruments += ({ob});
    if(TP && !(TP->query_invis() && (int)TP->query_level() > 19) )
      guild_broadcast(HIB+"*"+HIM+NAME(TP)+NORM+" enters the Realms of Magic.\n");
  }
}

void check_logout(object ob) {
  if(TP && query_verb() == "quit" && !(TP->query_invis() && (int)TP->query_level() > 19) )
    guild_broadcast (HIB+"*"+HIM+NAME(TP)+NORM+" leaves the Realms of Magic.\n");
}

object *query_instruments() {
  object *new_instruments;
  int x;
  new_instruments=({});
  for(x=0;x<sizeof(instruments);x++)
    if(instruments[x])
      new_instruments+=({instruments[x]});
  instruments=new_instruments;
  return instruments;
}

void add_history(string what) {
  string strTime,strTemp;
  int intHours,intMinutes,intTemp;
  strTime=ctime(time());
  sscanf(strTime,"%s %s %d %d:%d:%d %d",strTemp,strTemp,intTemp,intHours,intMinutes,intTemp,strTemp);
  channel_history[last_entry]=ansi_format(intHours+":"+
    (intMinutes<10?"0"+intMinutes:""+intMinutes)+" "+what,76);
  last_entry++;
  if(last_entry>=20) last_entry=0;
}

void display_history() {
  int x;
  write(HIB+"     <><><><><><><><><><><><> "+HIM+"Bard Talk History"+HIB+"  <><><><><><><><><><><>\n"+NORM);
  for(x=last_entry;x<20;x++) {
    if(channel_history[x])
      write(channel_history[x]);
  }
  for(x=0;x<last_entry;x++) {
    if(channel_history[x])
      write(channel_history[x]);
  }
  write(HIB+"     <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"+NORM);
}

varargs string add_tags(string str,string tag) {
  string *words;
  int x,s;
  words=explode(str+NORM,"\n");
  s=sizeof(words);
  for(x=0;x<s-1;x++)
    words[x]=tag+words[x];
  return implode(words,"\n");
}

do_bt_social(string str) {
  string verb,arg,tmp;
  string for_room;
  string *stuff;
  object target;
  status mud_emote;
  int s;
  if(!str)
    return 0;
  if(sscanf(str,"%s %s",verb,arg)!=2)
    verb=str;
  if(sscanf(verb,"%s.%s",tmp,tmp))
    return 0;
  stuff=SOCIAL->get_social(verb);
  if(!stuff)
    if(file_size("/bin/soul/_"+verb+".c")>0) {
      mud_emote=1;
      stuff=call_other("/bin/soul/_"+verb,"query_junk");
    }
  if(!stuff)
    return 0;
  if(arg) {
    target=find_player(arg);
    if(!target || (int)target->query_invis()>(int)this_player()->query_level() ||
       !present("instrument",target) || !(present("instrument",target)->query_on())) {
      write("Your target cannot be found in the Realms of Magic.\n");
      return 1;
    }
  }
  if(!target) {
    if(mud_emote) {
      for_room=(string)"/bin/std"->x(stuff[1]);
    } else {
      for_room=(string)SOCIAL->process_codes(stuff[1],this_player())+"\n";
    }
  } else {
    if(mud_emote) {
      for_room=(string)"/bin/std"->x(stuff[3],target);
    } else {
      for_room=(string)SOCIAL->process_codes(stuff[3],this_player(),target)+"\n";
    }
  }
  for_room=add_tags(for_room,HIB+"*"+HIM+"[Bard] "+NORM);
  guild_broadcast(for_room);
  add_history(for_room);
  return 1;
}

status bard_sing(string str, int i_emote) {
  object instrument, person, *list;
  int i;
  string temp, color_temp;
  string final;
  string emote_temp;
  
  if (spell(-400, 1, 0) == -1)
    return 0;

  if(str=="history") {
    display_history();
    return 1;
  }

  instrument=previous_object();

  if (!instrument->query_on())
    FAIL("You must tune your instrument if you want to talk to your kin.\n"+
    "Use <toggle> to tune back in.\n");
  if(!str || str==":" || str==":0")
    FAIL("It is a wise Bard who says something when "+PRON(TP)+" talks.\n");
  
  if(sscanf(str,":%s",emote_temp)) {
    str=emote_temp;
    if(do_bt_social(str))
      return 1;
    i_emote=1;
  }

  if(instrument->query_bard_level()>4) str=ADDCOLOR(str)+NORM;

  
  temp = HIB + "*" + HIM + "" + tp + "" + NORM;
  if (!i_emote)
  temp = temp + " sings:";
  temp = temp + " " + str;
  final=ansi_format(temp,76);
  guild_broadcast(final,0);
  add_history(temp);
  return 1;
}

varargs void guild_broadcast(string str,status override_toggle) {
  object *list;
  int i;
  list=query_instruments();
  for (i = 0; i < sizeof(list); ++i)
    list[i]->bard_sing(str, override_toggle);
}
