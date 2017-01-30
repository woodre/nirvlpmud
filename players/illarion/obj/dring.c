inherit "obj/treasure";
#include "/players/illarion/dfns.h"
#define ADDCOLOR(x) call_other("/players/illarion/obj/addcolor","addcolor",x);
#define CHAN "/bin/channel_daemon"

object worn_by;
object vshadow;
int ring_light;
int pretend_knight;
int pretend_poly;
int pretend_vamp;
int pretend_derv;
string *ignored;
string *ring_hist;
int hist_index;
int star_on;

reset(int arg) {
  if(arg) return;

  ring_hist=allocate(10);
  
  set_id("ring");
  set_short("An "+CYN+"oddly glowing"+NORM+" ring");
  set_long(
"A slim mithril band carved with a few small runes, and glowing with an\n"+
"odd light.\n");
  ignored=({});
}
get(int s) {
  if(TP->query_real_name()!="illarion") {
    write("The ring slips out of your grasp and vanishes.\n");
    destruct(this_object());
    return 0;
  }
  return 1;
}
drop(int s) {
  return 1;
}
get_rid_of_me() {
  destruct(this_object());
}
init() {
  if(TP->query_real_name()!="illarion") {
    call_out("get_rid_of_me",1);
    return;
  }
  ::init();
  if(ETO && ETO->is_player() && TP==ETO) {
    cmd_toggle_star();
  }
  add_action("cmd_show_hist","rhist");
  add_action("cmd_inscribe","inscribe");
  add_action("cmd_wear","wear");
  add_action("cmd_xls","xls");
  add_action("cmd_xhelp","xhelp");
  add_action("cmd_man","xman");
  add_action("cmd_more","mmore");
  add_action("cmd_wwho","wwho");
  add_action("cmd_exec","Exec");
  add_action("cmd_exec","Execp");
  add_action("cmd_change_race","change_race");
  add_action("cmd_free_exits","free_exits");
  add_action("cmd_clear_guild","clear_guild");
  add_action("cmd_fix_weight","fix_weight");
  add_action("cmd_inflict","inflict");
  add_action("cmd_work_log","work_log");
  add_action("cmd_work_log","lib_log");
  add_action("cmd_remove","remove");
  add_action("cmd_tell","tell");
  add_action("cmd_tell","TELL");
  add_action("cmd_tell","telle");
  add_action("cmd_tell","reply");
  add_action("cmd_say","say",2);
  add_action("cmd_emote","emote");
  add_action("cmd_pemote","pemote");
  add_action("cmd_pemote","pem");
  add_action("cmd_scarf","scarf");
  add_action("cmd_emoteto","emoteto");
  add_action("cmd_emoteto","emto");
  add_action("cmd_checktells","checktells");
  add_action("cmd_summon","summon");
  add_action("cmd_summon","SUMMON");
  add_action("cmd_give_dragon","give_dragon");
  add_action("cmd_my_dragon","my_dragon");
  add_action("cmd_lighten","lighten");
  add_action("cmd_darken","darken");
  add_action("cmd_check_light","check_light");
  add_action("cmd_dis_shadow","dis_shadow");
  add_action("cmd_change_weight","change_weight");
  add_action("cmd_start_fight","start_fight");
  add_action("cmd_xcp","xcp");
  add_action("cmd_wep","wep");
  add_action("cmd_xgrep","xgrep");
  add_action("cmd_check_odds","check_odds");
  add_action("cmd_analyze","analyze");
  add_action("cmd_tget","tget");
  add_action("cmd_tput","tput");
  add_action("cmd_guild_listen","guild_listen");
  add_action("cmd_guild_ignore","guild_ignore");
  add_action("cmd_guild_speak","guild_speak");
  add_action("cmd_center","center");
  add_action("cmd_make_stats","make_stats");
  add_action("cmd_star","star");
  add_action("cmd_toggle_star","toggle_star");
  add_action("cmd_sneaky_inv","INV");
  add_action("cmd_random_monster","make_random_monster");
  add_action("cmd_supergoto","GOTO");
  add_action("cmd_slay","slay");
  TP->set_noidlequit();
}

status cmd_toggle_star() {
  star_on = (int)CHAN->query_channel("star", TP);
  star_on = !star_on;
  if(star_on) "/bin/channel_daemon"->add_channel("star", TP);
  else "/bin/channel_daemon"->remove_channel("star", TP);
  write("Star is "+(star_on?"on":"off")+".\n");
  return 1;
}

cmd_guild_speak(string str) {
  string guild, what;
  string name;
  status emote;
  if(!str || sscanf(str,"%s %s",guild,what)!=2 || !guild || !what)
    FAIL("Syntax: guild_speak <guild> <message>\n");
  TO->cmd_guild_listen(guild,1);
  if(what[0..0]==":") {
    what=what[1..-1];
    emote=1;
  }
  name=NAME(TP);
  switch(guild) {
    case "shardak": case "shard": case "shards":
      call_other("/players/vertebraker/closed/shardak/daemons/channel",
          "broadcast",name+(emote?"":":")+" "+what,0,"{Servants}");
      return 1;
    case "poly": case "polymorph":
      if(emote) what=":"+what;
      return call_other("/players/mizan/closed/poly/PDM","guild_tell",what);
	case "vampire":  
	  if(!emote) return call_other("/players/eurale/VAMPIRES/vampbase","telepathy",what);
    else return call_other("/players/eurale/VAMPIRES/vampbase","telepathyfeel",what);
    default:
      write("Not implemented yet.\n");
      return 1;
  }
}

cmd_guild_listen(string str, status quietly) {
  if(!str) FAIL("What guild channel do you want to listen in on?\n");
  switch(str) {
    case "knights": case "knight":
      pretend_knight=1;
      break;
    case "shardak": case "shard": case "shards":
      call_other("/players/vertebraker/closed/shardak/daemons/channel",
          "register",TP,({"[Servants]","{Servants}"}));
      break;
    case "polymorph": case "poly": case "polys":
      pretend_poly=1;
      break;
    case "vampire": case "vamp":
      if(!pretend_vamp) {
        pretend_vamp=1;
        CHAN->add_channel("Vampire", TP);
      }
      break;
    case "dervish": case "derv":
      pretend_derv=1;
      call_other("/players/snow/dervish/objects/chatob.c","resetchannel");
      break;
    default:
      write("Not yet implemented.\n");
      return 1;
  }
  if(!quietly)
    write("Eavesdropping for "+str+" on.\n");
  return 1;
}

cmd_guild_ignore(string str) {
  if(!str) FAIL("What guild do you want to stop eavesdropping on?\n");
  switch(str) {
    case "dervish": case "derv":
      pretend_derv=0;
      call_other("/players/snow/dervish/objects/chatob.c","resetchannel");
      break;
    case "vamp": case "vampire":
      if(pretend_vamp) {
        pretend_vamp=0;
        CHAN->remove_channel("Vampire", TP);
      }
      break;
    case "knights": case "knight":
      pretend_knight=0;
      break;
    case "shardak": case "shard": case "shards":
      call_other("/players/vertebraker/closed/shardak/daemons/channel",
          "deregister",TP,({"[Servants]","{Servants}"}));
      break;
    case "polymorph": case "poly": case "polys":
      pretend_poly=0;
      break;
    default:
      write("Not yet implemented.\n");
      return 1;
  }
  write("Eavesdropping for "+str+" off.\n");
  return 1;
}
 
query_telepathy() {
  return pretend_vamp;
}

query_BLOODPTS() { return pretend_vamp?100:0; }


query_original() {
  return pretend_poly;
}

void check_wear() {
  object ob;
  if(!worn_by) return;
  if(!(ob=environment(this_object())) || ob!=worn_by) {
    worn_by=0;
    return;
  }
}

void real_say(string str) {
  object *ppl;
  int x,s;
  
  if(!str) return;
  
  ppl=all_inventory(environment(TP));
  s=sizeof(ppl);
  for(x=0;x<s;x++) {
    if(!living(ppl[x])) continue;
    if(ppl[x]==TP) continue;
    tell_object(ppl[x],str);
  }
}

short() {
  object ob,ob2;
  if((ob=environment(this_object())))
    if(TP && TP!=ob && (ob2=environment(ob)) && (!present(TP,ob2)))
      if(!present(TP,ob2)) {
        write("     NOSY       NOSY!\n");
        tell_object(ob,capitalize(TP->query_real_name())+" is being nosy.\n");
      }
  check_wear();
  return ::short()+(worn_by?" (worn)":"");
}
cmd_wear(string str) {
  if(!str || present(str,TP)!=this_object())
    FAIL("Wear what?\n");
  check_wear();
  if(worn_by) {
    write("You already wear it!\n");
    return 1;
  }
  write("You slip on "+lower_case(short_desc)+".\n");
  say(TPN+" slips on "+lower_case(short_desc)+".\n");
  worn_by=TP;
  return 1;
}
cmd_remove(string str) {
  if(!str || present(str,TP)!=this_object())
    FAIL("Remove what?\n");
  check_wear();
  if(!worn_by) {
    write("You aren't wearing it.\n");
    return 1;
  }
  write("You slip off "+lower_case(short_desc)+".\n");
  say(TPN+" takes off "+lower_case(short_desc)+".\n");
  worn_by=0;
  return 1;
}
cmd_scarf(string str) {
  object ob;
  object scarf;
  if(!str) FAIL("To who?\n");
  if(!(ob=find_player(lower_case(str)))) FAIL(capitalize(str)+" is not on.\n");
    if(present("itell",ob)) {
      write(ob->query_name()+" already has a scarf.\n");
      return 1;
    }
  tell_object(ob,
    "A piece of cloth seperates from the shadows and lands in your hand.\n"+
    "It can be used to "+BLD("itell(e)")+" Illarion something.\n");
  write("Scarf placed on "+ob->query_name()+".\n");
  scarf = clone_object("/players/illarion/obj/bscarf");
  scarf->set_owner(ob);
  transfer(scarf,ob);
  return 1;
}

object find_player_bruteforce(string name) {
  object *ppl;
  int s;
  s=sizeof((ppl=users()));
  while(s--)
    if((string)ppl[s]->query_real_name() == name)
      return ppl[s];
}

cmd_tell(string str) {
  string who,what,verb;
  string final,afk;
  object ob, scarf;
  int k;
  string name;
  verb=query_verb();
  if(verb=="TELL") verb="tell";
  if(verb=="reply") {
    verb="tell";
    who=TP->Replyer();
    what=str;
    if(!who) {
      write("You aren't replying to anyone.\n");
      return 1;
    }
    if(!str) {
      write("You are replying to: "+who+".\n");
      return 1;
    }
  } else if(!sscanf(str,"%s %s",who,what))
    { write("Tell "+capitalize(str)+" what?\n"); return 1; }
  if(!(ob=find_player_bruteforce(lower_case(who))))
    { write(capitalize(who)+" is not here.\n"); return 1; }
  if(ob->query_level() > TP->query_level() && in_editor(ob) && query_verb() != "TELL")
    { write("Not while they're editing.\n"); return 1; }
  if(!ob->query_interactive())
    write(capitalize(who)+" is linkdead, and won't hear this.\n");
  else if((k=query_idle(ob))>300)
    write(capitalize(who)+" has been idle for at least "+(k/60)+" minutes.\n");
  if((afk=ob->query_afk_message()))
    write(capitalize(who)+" is afk: "+afk+"\n");
  if(!str) FAIL(capitalize(verb)+" who what?\n");
  what=HIY+what+NORM;
  name=capitalize(TPRN);
  if(TP->query_invis())
    name="(invis) "+name;
  final=call_other(CLF,"colorformat",name+
    (verb=="tell"?" tells you: ":" ")+what,78);
  tell_object(ob,final);
  scarf=present("illarion_scarf_object",ob);
  if(scarf)
    scarf->add_scarf_hist(name+" "+(verb=="tell"?"told you: ":"")+what+"\n");
  else
    ob->add_tellhistory(name+" "+(verb=="tell"?"told you: ":"")+what);
  ob->Replyer(TPRN);
  if(verb=="tell")
    write(call_other(CLF,"colorformat",
      "You tell "+capitalize(who)+((k=ob->query_invis())?"(i:"+k+")":"")+
      ": "+what+"\n",78));
  else
    write(call_other(CLF,"colorformat",
      "(telle=>"+ob->query_name()+") "+TPN+" "+what+"\n",78));
  return 1;
}
cmd_say(string str) {
  string output;
  string sverb,rverb,modifier;
  string temp,temp2;
  rverb="says";
  sverb="say";
  if(!str) {
    write("Say what?");
    return 1;
  }
  if((temp=extract(str,strlen(str)-2))=="?!" || temp == "!?") {
    sverb="demand";
    rverb="demands";
  } else if(extract(str,strlen(str)-1)=="?") {
    sverb="inquire";
    rverb="inquires";
  } else if(extract(str,strlen(str)-1)=="!") {
    sverb="exclaim";
    rverb="exclaims";
  }
  if(sscanf(str,"%s:)",temp)) {
    modifier=" with a smile";
  } else if(sscanf(str,"%s;)",temp)) {
    modifier=" with a wink";
  } else if(sscanf(str,"%s:(",temp)) {
    modifier=" with a frown";
  }
  str=ADDCOLOR(str);
  write(call_other(CLF,"colorformat",
    "You "+(modifier?sverb+modifier:sverb)+", \""+
    CYN+str+NORM+"\"\n",78));
  real_say(call_other(CLF,"colorformat",
    TPN+" "+(modifier?rverb+modifier:rverb)+", \""+
    CYN+str+NORM+"\"\n",78));
  return 1;
}

check_ignored() {
  if(TP && member_array(TPRN,ignored)!=-1) return 1;
  return 0;
}


int id(string str) {
  return str=="illarion_dring" || (worn_by && str=="dark_sight_object")
    || (pretend_knight && str=="KnightTemplar") 
    || (pretend_poly && str=="Mizan-guild-object")
    || (pretend_vamp && str=="vampire fangs")
    || (pretend_derv && str=="dervish_tattoo")
    || str=="generic_sp_bonus"
    || ::id(str);
}


add_ignored(str) {
  if(!str) {
    write("ignored: "+ ( ignored? implode(ignored,", ") : "none") + "\n");
    return 1;
  }
  str=lower_case(str);
  if(member_array(str,ignored) != -1) {
    ignored -= ({str});
    write("Ignored removed: str\n");
  } else {
    ignored += ({str});
    write("Ignored added: str\n");
  }
}

gen_sp_bonus() { return 4000; }

int cmd_work_log(string str) {
  string timestr;
  string file;
  if(query_verb()=="work_log")
    file="illarion_workreport";
  else
    file="illarion_libreport";

  if(!str) {
    write("   /log/WR/"+file+":\n");
    tail("/log/WR/"+file);
    return 1;
  }
  timestr=ctime();
  if(timestr[8..8]==" ")
    timestr=timestr[0..7]+"0"+timestr[9..-1];
  timestr=CYN+"["+NORM+timestr[8..10]+timestr[4..6]+timestr[-5..-1]+timestr[10..15]+CYN+"] "+NORM;
  write_file("/log/WR/"+file,timestr+str+"\n");
  write("Logged in /log/WR/"+file+":\n"+timestr+str+"\n");
  return 1;
}

int cmd_desc(string str) {
  object what;
  if(!str) FAIL("syntax: desc <what>\n");
  what=present(str,environment(TP));
  if(!what)
    what = find_player(str);
  if(!what)
     FAIL(str+" is nowhere to be found.\n");
   what->long();
   return 1;
}
string resolve_quotes(string str) {
   string final;
   string *tokens;
   int x,n;
   tokens=explode(str,"\"");
   n=sizeof(tokens);
   if(n<=1)
      return str;
   for(x=1;x<n;x+=2)
      tokens[x]="\""+CYN+tokens[x]+NORM+"\"";
   final = implode(tokens,"");
   return final;
}
int cmd_emote(string str) {
   str = (string)CLF->colorformat(resolve_quotes(TPN+" "+str));
   write(str);
   real_say(str);
   return 1;
}
int cmd_pemote(string str) {
   tell_room(environment(this_player()),(string)CLF->colorformat(
             resolve_quotes(TPN+"'s "+str)));
   return 1;
}
int cmd_emoteto(string str) {
   string whos,whats,roomstr,nextletter;
   string *tokens;
   object who;
   status usedname,useposs;
   int n,x;
   if(!str || sscanf(str,"%s %s",whos,whats) !=2)
      FAIL("Syntax: emoteto <who> <what>\n");
   who=present(whos,environment(TP));
   if(!who)
      FAIL(whos+" is not here.\n");
   whos= "|"+whos+"|";
   tokens = explode(whats,"you");
   n=sizeof(tokens);
   roomstr="";
   for(x=0;x<n-1;x++) {
      useposs=0;
      nextletter=extract(tokens[x+1],0,0);
      roomstr+=tokens[x];
      if(nextletter == "n" || nextletter == "t") {
         roomstr+="you";
         continue;
      }
      if(nextletter == "r") {
         useposs=1;
         tokens[x+1]=extract(tokens[x+1],1);
      }
      if(!usedname) {
         usedname=1;
         roomstr+=(string)who->query_name()+(useposs?"'s":"");
      } else {
         if(useposs)
           roomstr+=(string)who->query_possessive();
         else
           roomstr+=(string)who->query_objective();
      }
   }
   if(!usedname) {
      write("You must use 'you' at least once in an emoteto.\n");
      return 1;
   }
   roomstr+=tokens[n-1];
   sscanf(roomstr,"|%s|",roomstr);
   tell_room(environment(TP),format(TPN+" "+roomstr),({who}));
   tell_object(who,format(TPN+" "+whats));
   return 1;
}
int cmd_checktells(string str) {
   object ob;
   if(!str) return 0;
   ob=find_player(str);
   if(!ob) return 0;
   ob->write_tellhistory();
   return 1;
}
status cmd_summon(string str) {
   object who;
   if(!str) {
      write("Summon whom?");
      return 1;
   }
   who=find_player(str);
   if(!who) {
      write(str+" not found.\n");
      return 1;
   }
   if(who->query_level() > TP->query_level()) {
      write("You might want to rethink that.\n");
      return 1;
   }
   if(query_verb() == "SUMMON") {
     tell_room(environment(who),format(
      "A flash of white light blinds you for a moment.  When your vision "+
      "clears, "+who->query_name()+" is gone."),({who}));
     tell_object(who,format(
      "A flash of white light suddenly obscures your vision.   When it "+
      "clears, you find yourself elsewhere.\n"));
     tell_room(environment(TP),format(
      "A flash of light blinds you for a moment.  When your vision clears, "+
      who->query_name()+" is here.\n"));
     move_object(who,environment(TP));
     command("look",who);
   } else {
     object scroll;
     scroll = clone_object("/players/illarion/obj/summonscroll");
     scroll->summon_player(who,this_player(),60);
     write("Scroll placed.\n");
   }
   return 1;
}
status cmd_give_dragon(string str) {
  object owner,dragon;
  if(!str)
    return 0;
  owner=find_player(str);
  if(!owner)
    return 0;
  dragon=clone_object("/players/illarion/obj/dragon");
  tell_object(owner,TPN+" has granted you a dragon.\n");
  move_object(dragon,environment(owner));
  dragon->set_owner(owner);
  return 1;
}
status cmd_my_dragon() {
  object dragon;
  dragon=clone_object("/players/illarion/obj/odragon");
  dragon->set_owner(TP);
  move_object(dragon,environment(TP));
  write("You summon your dragon.\n");
  say("A small obsidian dragon flies to "+TPN+" shoulder.\n");
  return 1;
}
void light_up(int arg) {
  set_light(arg);
  return;
}
int test_light() {
  return set_light(0);
}
status cmd_dis_shadow() {
  if(!vshadow) FAIL("You don't have a shadow to get rid of.\n");
  vshadow->stop_vampstuff();
  write("You stop trying to see in the dark.\n");
  return 1;
}
status cmd_check_light() {
  int current_light;
  current_light=set_light(0);
  write("The total light in your environment is: "+current_light+".\n");
  write("Your ring's current contribution is: "+ring_light+".\n");
  return 1;
}
status cmd_lighten() {
  ring_light++;
  set_light(1);
  cmd_check_light();
  return 1;
}
status cmd_darken() {
  ring_light--;
  set_light(-1);
  cmd_check_light();
  return 1;
}

status cmd_change_weight(string str) {
  string whos;
  int amt;
  object who;
  if(!str || sscanf(str,"%s %d",whos,amt)!=2)
    FAIL("Syntax: change_weight <who> <amount>\n");
  who=find_player(whos);
  if(!who)
    FAIL("Player not found.\n");
  if(who->query_pregnancy()) {
    write("Not a good idea, she's pregnant.\n");
    return 1;
  }
  who->add_phys_at(3,amt);
  write("Weight of "+amt+" added to "+who->query_name()+".\n");
  tell_object(who,"You feel "+(amt>0?"heavier":"lighter")+".\n");
  return 1;
}

status cmd_inflict(string str) {
  int dam,final_dam;
  string type,who,name;
  object what;
  if(!str || sscanf(str,"%d %s on %s",dam,type,who)!=3)
    FAIL("Syntax: inflict <amount> <damage type> on <what>\n");
  what=present(who,environment(TP));
  name=(string)what->query_name();
  if(!what) FAIL(who+" not found.\n");
  final_dam=(int)what->do_damage(({dam}),({type}));
  if(what)
    write(format("You have done "+final_dam+" of "+dam+" of type "+type+" to "+name+"\n"));
  else
    write(format("you have done "+final_dam+" of "+dam+" of type "+type+", killing "+name+".\n"));
  return 1;
}
glev(string str) {
  int lev;
  sscanf(str,"%d",lev);
  this_player()->add_guild_rank(lev);
  return 1;
}
status cmd_clear_guild(string str) {
  object p;
  if(!str) FAIL("Argument required.\n");
  p=find_player(str);
  if(!p) FAIL("Player not found.\n");
  p->set_guild_name(0);
  return 1;
}
status cmd_fix_weight(string str) {
  object who;
  if(!str) FAIL("Argument required.\n");
  who=find_player(str);
  if(!who) FAIL("Not found.\n");
  who->recalc_carry();
  write("Weight fixed.\n");
  return 1;
}

cmd_free_exits(str) {
  object ob;
  object sob;
  if(!str || !(ob=find_player(str))) FAIL("Not found.\n");
  sob = clone_object("/players/illarion/obj/freeexit.c");
  sob->start_shadow(environment(ob));
  return 1;
}

code_resolve(str) {
  object ob;
  ob=present(str,TP);
  if(ob) 
    return "present(\""+str+"\",this_player())";
  ob=present(str,environment(TP));
  if(ob)
    return "present(\""+str+"\",environment(this_player()))";
  ob=find_player(str);
  if(ob)
    return "find_player(\""+str+"\")";
  ob=find_living(str);
  if(ob)
    return "find_living(\""+str+"\")";
  return "!ERROR!";
}
cmd_exec(string str) {
  string temp,before,mid,after;
  mixed ret;
  int s;
  status delayed;
  delayed = (query_verb() == "Execp"?1:0);
  write("Verb: "+query_verb()+"\n");
  if(!str) FAIL("exec what?\n");
  while(sscanf(str,"%s&%s&%s",before,mid,after))
    str=(before?before:"")+code_resolve(mid)+(after?after:"");
  if(str[-1..-1]!=";") str+=";";
  str="  "+implode(explode(str,"; "),";\n  ");
  write("new str:\n"+str+"\n");
  if(sscanf(str,"%s!ERROR!%s",before,after))
    return 1;
  command("update /players/illarion/exec_temp",TP);
  rm("/players/illarion/exec_temp.c");
  write_file("/players/illarion/exec_temp.c","#include \"/players/illarion/dfns.h\"\n");
  write_file("/players/illarion/exec_temp.c","main() {\n"+str+"\n}\n");
  if(delayed) {
    call_out("finish_exec",0);
    return 1;
  }
  ret=call_other("/players/illarion/exec_temp","main");
  write("\nReturned: ");
  write(ret);
  write("\n");
  return 1;
}

void finish_exec() {
  call_other("/players/illarion/exec_temp","main");
  tell_object(environment(),"\nDelayed Exec Completed.\n");
}

status cmd_wwho(string str) {
  return (int)call_other("/players/illarion/obj/who_thing","display_who",str);
}

status cmd_start_fight(string arg) {
  string str1,str2;
  object ob1,ob2;
  if(!arg || sscanf(arg,"%s %s",str1,str2)!=2) 
    FAIL("Syntax: start_fight <fighter1> <fighter2>\n");
  ob1=present(str1,environment(TP));
  ob2=present(str2,environment(TP));
  if(!ob1)
    FAIL(str1+" not found.\n");
  if(!ob2)
    FAIL(str2+" not found.\n");
  ob1->attack_object(ob2);
  return 1;
}

cmd_more(string arg) {
  object more_ob;
  if(!arg) FAIL("You need a filename, stupid.\n");
  more_ob=clone_object("/players/illarion/obj/more_ob");
  more_ob->more(arg);
  return 1;
}

cmd_xcp(string arg) {
  return call_other("/players/illarion/obj/xcp","xcp",arg);
}

cmd_xls(string arg) {
  return call_other("/players/illarion/obj/xls","xls",arg);
}

cmd_wep() {
  write("Attempting to make a random weapon...\n");
  transfer("/players/illarion/maze/obj/wep_daem"->make_weapon(0,0,0,4),this_player());

  return 1;
}

cmd_xgrep(string arg) {
  return "/players/illarion/obj/xgrep.c"->cmd_grep(arg);
}

cmd_man(string str) {
  return "/players/illarion/obj/man.c"->cmd_man(str);
}

cmd_xhelp(str) {
  return "/players/illarion/obj/help.c"->cmd_help(str);
}
cmd_check_odds(str) {
  int rand1,rand2;
  int x,y;
  if(!str || sscanf(str,"%d %d",rand1,rand2) != 2)
    FAIL("Syntax: check_odds num1 num2\n");
  x=10000;
  while(x--)
    if(random(rand1) > random(rand2))
      y++;
  write("random("+rand1+") was greater than random("+rand2+") "+
    y+" times out of 10000\n");
  return 1;
}

get_hp_factor(max_hp,bonus) {
   int hp_factor, tmp_hp, hp_diff,x;
   tmp_hp = max_hp;
   x = 1;
   hp_factor = 0;
   while(tmp_hp>2000) {
     hp_diff = tmp_hp-2000;
     if(hp_diff > 1000)
       hp_diff = 1000;
     hp_factor += hp_diff / (50+20*x);
     x++;
     tmp_hp -= hp_diff;
   }
   hp_factor += tmp_hp/50;
  return hp_factor+bonus/50;
}

cmd_analyze(str) {
  int *stuff;
  object what;
  if(!str) 
    FAIL("Syntax: analyze <what>\n");
  what=present(str,environment(TP));
  if(!what)
    what=find_living(str);
  if(!what)
    FAIL("Target not found.\n");
  stuff=allocate(13);
  write("calculate_worth() data for "+what->short()+":\n"
+"calculate_worth:   "+what->calculate_worth()+"\n\n"
+"max hp:            "+pad(""+(stuff[0]=what->query_mhp()),10)+"hp factor:\n"
+"hp bonus:          "+pad(""+(stuff[1]=what->query_hp_bonus()),10)+"  "+get_hp_factor(stuff[0],stuff[1])+"\n"
+"damage potential:  "+pad(""+(stuff[2]=what->query_damage_potential()),10)+"\n"
+"wc:                "+pad(""+(stuff[3]=what->query_wc()),10)+"\n"
+"spell dam:         "+pad(""+(stuff[4]=what->query_spell_dam()),10)+"\n"
+"spell chance:      "+pad(""+(stuff[5]=what->query_spell_chance()),10)+"\n"
+"spell exp:         "+pad(""+(stuff[6]=what->query_spell_exp()),10)+"wc factor:\n"
+"wc bonus:          "+pad(""+(stuff[7]=what->query_wc_bonus()),10)+"  "+((stuff[2]?stuff[2]:stuff[3])+(stuff[4]*stuff[5]/200)+stuff[6]+stuff[7])+"\n"
+"defense potential: "+pad(""+(stuff[8]=what->query_defense_potential()),10)+"\n"
+"ac:                "+pad(""+(stuff[9]=what->query_ac()),10)+"\n"
+"heal rate:         "+pad(""+(stuff[10]=what->query_heal_rate()),10)+"\n"
+"heal interval:     "+pad(""+(stuff[11]=what->query_heal_intv()),10)+"ac factor:\n"
+"ac bonus:          "+pad(""+(stuff[12]=what->query_ac_bonus()),10)+"  "+( (stuff[8]?stuff[8]:stuff[9])+(stuff[10]>0&&stuff[11]>0?stuff[10]*3/stuff[11]:0)+stuff[12] )+"\n"
);
  return 1;
}

cmd_tget(str) {
  string *words;
  if(!str)
    FAIL("syntax: tget <file>\n");
  str=resolv_path(TP->get_path(),str);
  if(file_size(str) < 0)
    FAIL("File does not exist.\n");
  words=explode(str,"/");
  write("Copying "+str+" to /players/illarion/test/"+words[sizeof(words)-1]+"\n");
  TP->force_us("cp "+str+" /players/illarion/test/"+words[sizeof(words)-1]);
  return 1;
}

cmd_center(str) {
  string blah;
  int amt;
  int siz;
  sscanf(str,"%s*%d",blah,amt);
  siz=strlen(blah);
  write("|"+pad(blah[0..siz/2],-amt/2)+pad(blah[1+siz/2..-1],amt/2)+"|\n");
  return 1;
}

cmd_make_stats(str) {
  int amt;
  int hp, wc, ac;
  int hp_factor, wc_factor, ac_factor;
  object testmon;
  if(!str || !sscanf(str,"%d",amt)) FAIL("syntax: make_stats <exp desired>\n");

  
  
  write("Hp: "+hp+" wc: "+wc+" ac:" +ac+"\n");
  testmon=clone_object("obj/monster");
  testmon->set_hp(hp);
  testmon->set_ac(ac);
  testmon->set_wc(wc);
  write("Actual Monster value: "+testmon->calculate_worth()+"\n");
  return 1;
}

cmd_star(str) {
  if(star_on) {
    call_other("/players/pain/NEW/items/star_daemon","star",str);
    return 1;
  }
  FAIL("Star is currently off.\n");
}

cmd_sneaky_inv(string str) {
  object target;
  if(!str) target = this_player();
  else target = find_player(str);
  if(!str) FAIL("No target found.");
  call_out("do_sneaky_inventory",0,target);
  return 1;
}
do_sneaky_inventory(object target,int padAmount) {
  int s,t;
  object *stuff;
  if(!target || !ENV(TO)) return;
  t=s=sizeof(stuff=all_inventory(target));
  if(s==0) return;
  if(padAmount==0) tell_object(ENV(TO),"Inventory:\n");
  while(s--) {
    tell_object(ENV(TO), pad("",padAmount)+call_other("/bin/wiz/_I.c","print_obj_info",t-s,stuff[s])+"\n");
    do_sneaky_inventory(stuff[s],padAmount+4);
  }
  if(padAmount==0) tell_object(ENV(TO),"Listing complete.\n");
}

status cmd_random_monster(string blah) {
  int level,variance;
  object mon;
  if(!blah || sscanf(blah,"%d %d",level,variance)!=2) FAIL("make_random_monster <level> <variance>\n");
  mon = (object)"/players/illarion/maze/mon/monster_guide"->make_monster(level,25);
  move_object(mon,environment(this_player()));
  return 1;
}
cmd_inscribe(str) {
  return "/players/illarion/11_inscribe"->main(str);
}

add_ring_hist(str) {
  ring_hist[hist_index++] = "["+ctime()[11..15]+"]"+str;
  if(hist_index >9) hist_index=0;
}

cmd_show_hist() {
  int x;
  if(!this_player()) return;
  if(this_player()->query_real_name() != "illarion") {
    if(environment())
      tell_object(environment(),this_player()->query_real_name()+" tried to read the ring's history.\n");
    write("I don't think so.\n");
  }
  for(x=hist_index; x<10; x++)
    if(ring_hist[x]) write(ring_hist[x]);
  for(x=0; x< hist_index; x++)
    if(ring_hist[x]) write(ring_hist[x]);
  return 1;
}

status cmd_supergoto(string str) {
  object target;
  object shadow_object;
  if(!str) FAIL("Syntax: GOTO <target>\n");
  target=find_player(str);
  if(!target)
  target=find_living(str);
  if(!target) FAIL("Unable to find "+str+".\n");
  target=environment(target);
  if(!target) FAIL("No environment for: "+str+".\n");
  shadow_object=clone_object("/players/illarion/obj/init_shadow.c");
  shadow_object->start(target);
  move_object(TP,target);
  shadow_object->stop();
  destruct(shadow_object);
  return 1;
 }
 
 
cmd_slay(string str) {
  object who;
  if(!str) FAIL("Slay <target>\n");
  who = present(str, ENV(TP));
  if(!who) FAIL("Target not found.\n");
  who->attacked_by(TP);
  who->death();
  return 1;
}