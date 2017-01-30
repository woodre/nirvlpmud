#include "/players/guilds/bards/def.h"
#include "/players/guilds/bards/lib/ansi_pad.h"
#define CHANNELHIST "/obj/user/chistory"
#define SOCIAL "/players/guilds/bards/socials/bard_social"

varargs string add_tags(string str,string tag, object who, string channel) {
  string *words;
  int x,s;
  if(who && channel && who->get_ansi_pref(channel))
    tag=(string)who->get_ansi_pref(channel)+tag+NORM;
  words=explode(str+NORM,"\n");
  s=sizeof(words);
  for(x=0;x<s-1;x++)
    words[x]=tag+words[x];
  return implode(words,"\n");
}

farsong_social(string str,string channel) {
  string verb,arg,tmp;
  string for_self,for_room,for_target;
  string *stuff;
  object target;
  status mud_emote;
  object *list;
  int s;
  if(!str)
    return 0;
  if(!TP->on_channel(channel))
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
    if(!target || !target->on_channel(channel) || (int)target->query_invis()>(int)this_player()->query_level()) {
      write("Your target cannot be found in the Realms of Magic.\n");
      return 1;
    }
  }
  list=users();
  if(!target) {
    if(mud_emote) {
      for_self=(string)"/bin/std"->x(stuff[0]);
      for_room=(string)"/bin/std"->x(stuff[1]);
    } else {
      for_self=(string)SOCIAL->process_codes(stuff[0],this_player())+"\n";
      for_room=(string)SOCIAL->process_codes(stuff[1],this_player())+"\n";
    }
    for_self=add_tags(for_self,"(Songs) ",TP,"gossip");
    list-=({TP});
    tell_object(TP,for_self);
    s=sizeof(list);
    while(s--)
      if(list[s]->on_channel(channel))
        tell_object(list[s],add_tags(for_room,"(Songs) ",list[s],"gossip"));
    "/bin/channel_daemon"->add_channel_history("gossip",add_tags(for_room,"(Songs) "));
  } else {
    if(mud_emote) {
      for_self=(string)"/bin/std"->x(stuff[2],target);
      for_room=(string)"/bin/std"->x(stuff[3],target);
      for_target=(string)"/bin/std"->x(stuff[4],target);
    } else {
      for_self=(string)SOCIAL->process_codes(stuff[2],this_player(),target)+"\n";
      for_room=(string)SOCIAL->process_codes(stuff[3],this_player(),target)+"\n";
      for_target=(string)SOCIAL->process_codes(stuff[4],this_player(),target)+"\n";
    }
    for_self=add_tags(for_self,"(Songs) ",TP,"gossip");
    for_target=add_tags(for_target,"(Songs) ",target,"gossip");
    list-=({TP});
    list-=({target});
    tell_object(TP,for_self);
    tell_object(target,for_target);
    CHANNELHIST->add_history(channel,add_tags(for_room,"(Songs) "));
    s=sizeof(list);
    while(s--)
      if(list[s]->on_channel(channel))
        tell_object(list[s],add_tags(for_room,"(Songs) ",list[s],"gossip"));
  }
  return 1;
}

status main(string str,status i_emote) {
  object member2, person, *list, *people;
  int i;
  string temp,str1;
  
  if (spell(-195, 5, 3) == -1)
    return 0;

  people = (object*)"/bin/channel_daemon"->on_channel("gossip");
  if(member(people,this_player()) == -1)
    FAIL("You are not on the gossip channel, so you may not sing.\n");
  if (!str)
    FAIL("What do you want to sing?\n");
  if(str=="history") {
    write(CHANNELHIST->query_history("gossip"));
    return 1;
  }
    
  if(sscanf(str,":%s",str1)) {
    str=str1;
    if(farsong_social(str,"gossip"))
      return 1;
    i_emote=1;
  }
  if (!i_emote)
    temp = tp + " sings: "+str+"\n";
  else
    temp = tp + " "+str+"\n";
/*
  temp = ansi_format(temp + " " + ADDCOLOR(str),76);
*/
  list = users();
  for (i = 0; i < sizeof(list); ++i) {
    person = list[i];
    if (member(people,person) > -1) {
      tell_object(person, add_tags(temp,"(Songs) ",person,"gossip"));
    }
  }
  "/bin/channel_daemon"->add_channel_history("gossip","[" + ctime()[11..18] + "] " + add_tags(temp,"(Songs )"));
  call_other(TP, "add_spell_point", -3);
  return 1;
}
