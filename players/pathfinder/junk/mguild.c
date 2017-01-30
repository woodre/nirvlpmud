/* updated and revised. Working channels, debug messages are bugged */
/*
#define SAVE "players/wizardchild/closed/guild/members/"
*/
#define SAVE "players/pathfinder/junk/"
#define SLAVE "/players/pathfinder/junk/matchbox.c"
#define RN this_player()->query_real_name()
#define tp this_player()
int guild_exp;
int guild_rank;
int is_muffle;
int guild_stat;
 
do_muffle(str) {
  if(!str) {
    tell_object(tp,"Usage: muffle <on/off/stat>\n");
    return 1;
    }
  if(str == "on") {
    if(is_muffle == 1) {
      tell_object(tp,"You are already muffled.\n");
      return 1;
    } else
      is_muffle = 1;
      tell_object(tp,"You are now muffled.\n");
      tp->set_muffled(1);
      return 1;
      }
  if(str == "off") {
    if(is_muffle == 0) {
      tell_object(tp,"You were not muffled.\n");
      return 1;
    } else
      is_muffle = 0;
      tell_object(tp,"You are now not muffled.\n");
      tp->set_muffled(0);
      return 1;
      }
   if(str == "stat") {
     if(is_muffle == 0) {
       tell_object(tp,"You are not muffled.\n");
       return 1;
     } else
       tell_object(tp,"You are muffled.\n");
       return 1;
       }
}       
 
help_arson() {
  tell_object(tp,"This is the playtest version of the Arsonists guild.\n");
  tell_object(tp,"The following commands are available:\n");
  tell_object(tp,"at <str>         (talk on the guild channel)\n");
  tell_object(tp,"ae <str>         (emote on the guild channel)\n");
  tell_object(tp,"aw               (who is on the guild channel)\n");
  tell_object(tp,"; <str>          (general purpose emoter)\n");
  tell_object(tp,"light match      (create a light source)\n");
  tell_object(tp,"relight          (update your guild object)\n");
  tell_object(tp,"myscore          (see your score/guild scores)\n");
  tell_object(tp,"help_arson       (this menu <duh>)\n");
  return 1;
}
 
/* myscore modified to handle int packing */
myscore(str) {
  string bleh;
  bleh = "[^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^]\n";
  if(sscanf(str, "%d#%d#%d", guild_exp, guild_rank, is_muffle) == 3) ;
  else {
    tell_object(tp,"Error loading stats. Notify Wizardchild.\n");
    return 1;
    }
 tell_object(tp,"[-"+capitalize(RN)+"-] [guild stats]\n");
 tell_object(tp,bleh);
 tell_object(tp,"[Level]: "+tp->query_level()+"\t[Xps]: "+tp->query_exp());
 tell_object(tp,"\t[Coins]: "+tp->query_money()+"\n[Hp]: ");
 tell_object(tp,tp->query_hp()+"\t[Sp]: "+tp->query_spell_points()+"\n");
 tell_object(tp,"[Guild Rank]: "+guild_rank+"\t[Guild Xps]: "+guild_exp+"\t[Muffle]: ");
 if(is_muffle) tell_object(tp,"Yes.\n"); 
 else tell_object(tp,"No.\n");
 tell_object(tp,bleh);
 return 1;
}
 
set_guildlevel(str) {
  object player, who;
  object this;
  string name;
  int level;
 
  if(!str) {
    tell_object(tp,"Huh?\n");
    return 1;
    }
  if((!sscanf(str,"%s %d",name,level))==2) {
    tell_object(tp,"Usage: setglev <who> <level>\n");
    return 1;
    }
  who=find_living(name);
  if(!who) {
    tell_object(tp,capitalize(name)+" is not online.\n");
    return 1;
    }
  if(!present("qwerty",who)) {
    tell_object(tp,capitalize(name)+" is not a member of the guild!!!\n");
    return 1;
    }
  this=present("qwerty",who);
  this->set_grank(level);
  command("save_me",who);
  tell_object(who,"You are raised to rank "+level+".\n");
  tell_object(tp,"You raise "+capitalize(name)+" to rank "+level+".\n");
  write_file("/players/pathfinder/junk/grank.log",capitalize(RN)+" made "+capitalize(name)+" guild rank "+level+"\n");
  return 1;
}
 
set_guildexp(str) {
  object player, who;
  string name;
  int total;
  
  if(!str) {
    tell_object(tp,"Huh?\n");
    return 1;
    }
    
  if((!sscanf(str,"%s %d",name,total))==2){
    tell_object(tp,"Usage: setgxp <who> <amt>\n");
    return 1;
    }
  who=find_living(name);
  if(!who) {
    tell_object(tp,capitalize(name)+" is not online.\n");
    return 1;
    }
  if(!present("qwerty",who)) {
    tell_object(tp,capitalize(name)+" is not a member of the guild!!!\n");
    return 1;
    }
  who->set_gxp(total);
  command("save_me",who);
  tell_object(who,"You now have "+total+" total gxp.\n");
  tell_object(tp,capitalize(name)+" now has "+total+" gxp.\n");
  write_file("/players/pathfinder/junk/gxp.log",capitalize(RN)+" gave "+capitalize(name)+" "+total+" gxp.\n");
  return 1;
}
 
arson_w() {
        object g_mem;
        int indx;
        object me;
        string blah;
        g_mem = users();
        blah = "[-][-][-][-][-][-][-][-][-][-][-]";
      tell_object(tp,blah+"[-Guild Who-]"+blah+"\n");
        tell_object(tp, "[-][-][-Name-][-][-][-][-][-Guild Rank-][-][-][-][-][-Muffle-]\n");
        for(indx = 0; g_mem[indx] < sizeof(users()); indx++) {
           if(present("qwerty", g_mem[indx])) {
              me = present("qwerty", g_mem[indx]);
                if(me && me->query_invis() < 19){
                  tell_object(tp, me->query_real_name()+"\t");
                  tell_object(tp, me->query_guild_rank()+"\t");
                  if(me->query_is_muffle() == 1)
                     tell_object(tp, "Yes\n");
                  else
                     tell_object(tp, "No\n");
                 }
           }
        }
        tell_object(tp, blah+blah+"\n");
        return 1;
}
 
arson_t(str) {
  object ob, who;
  int i;
        
  if(!str) { 
    tell_object(tp,"Huh?\n"); 
    return 1; 
  }        
        
  ob = users();
  
  for(i = 0; i < sizeof(ob); i++) {
    who=(present("qwerty",ob[i]));
    if((who) && (who->query_muffled() < 1)) {
      tell_object(who,"[-"+capitalize(RN)+"-]: "+str+"\n");
    }
  }
  return 1;
}
 
panic() {
  tell_object(tp,"SHIT! This function is corrupted! Mail Wizardchild.\n");
  return 1;
}
 
arson_e(str) {
  object who, people;
  int i;
 
   if(!str) {
      tell_object(tp,"Emote what?\n");
      return 1;
   }
   people = users();
   for(i = 0; i<sizeof(people); i++) {
      who=(present("qwerty",people[i]));
      if(who && who->query_muffled() < 1) {
         tell_object(people[i], "\n[-] "+capitalize(RN)+" "+str+"\n");
       }
   }
   return 1;
} 
 
emote(str) {
  if(!str) { tell_object(tp,"Huh?\n"); return 1; }
  tell_room(environment(this_player()),capitalize(RN)+" "+str+"\n");
  return 1;
}
 
restore_me() {
  object me;
  string file;
        
  me=find_player(RN);
  file=SAVE+RN;
  if(!me) return 0;
  tell_object(tp,"Loading guild stats....\n");
  restore_object(file);
  /* if(guild_stat == 0) {
    tell_object(tp,"You have been banished from the Arsonists guild.\n");
    tell_object(tp,"If you have a problem with this, mail Wizardchild.\n");
    destruct(SLAVE);
  } else if(guild_stat == -1) {
    tell_object(tp,"You are on a temporary suspension from the arsonists\n");
    tell_object(tp,"guild. If you have a problem with this, mail Wizardchild.\n");
    destruct(SLAVE);
  } else { */
    tell_object(tp,"Guild stats restored.\n");
    SLAVE->set_stat(guild_exp +"#"+guild_rank+"#"+is_muffle);
/*  } */
}
 
flush_stats() {
  tell_object(tp,"flush stats\n");
  guild_exp = guild_rank = is_muffle = 0;
  return 1;
}
 
save_this(str) {
  object me;
  string file;
  file=SAVE+RN;
  if((!sscanf(str, "%d#%d#%d",guild_exp, guild_rank, is_muffle)) == 3) {
    tell_object(tp,"Error in saving stats.  Notify Wizardchild.\n");
    return 1;
    }
  if(!save_object(file)) {
    tell_object(tp,"Error in saving stats.  Notify Wizardchild.\n");
    return 1;
  } else {
    tell_object(tp,"Saving Guild Stats...");
    return 1;
  }
}
 
bye(str) {
  save_this(str);
}
 
 
 
/* Asthetic stuff */
/* 
short() {
  return "The arsonists' master object.";
}
 
long() {
  tell_object(tp,"PLEASE DO NOT CLONE ME!!! I should only be in Wizardchild's\n");
  tell_object(tp,"workroom!!!\n");
  return 1;
}
 
reset(arg) {
  if(arg) return 0;
  move_object(this_object(),"/players/pathfinder/workroom.c");
}
id(str) { return str == "object" || str == "arson" || str == "guild"; }
*/
/* following is slave object */
 

