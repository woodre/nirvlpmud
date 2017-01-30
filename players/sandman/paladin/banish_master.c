
/*
 * BANISH_MASTER (4/21/94)
 * Holds all banished players.
 */

#define FILE "players/sandman/paladin/banished"
#define LOGBANISH
#define LOGFILE "/players/sandman/paladin/log/banish"

justify(str,len) { return extract(str+"                        ",0,len-1); }

string *banished;

banish(str) {
   object target, medal;

   restore_data();
   if(!banished)
     banished = ({ });
   if(member_array(str, banished) != -1) {
     write(capitalize(str)+" has already been banished!\n");
     return 1;
   }
   banished += ({ str });
   write("You have banished "+capitalize(str)+" from the Paladins.\n");
#ifdef LOGBANISH
   write_file(LOGFILE, "[*] "+capitalize(str)+" banished by "+
        capitalize(this_player()->query_real_name())+" "+ctime(time())+"\n");
#endif
   target = find_player(str);
   if(target) {
     medal = present("guild_medal", target);
     if(medal) {
       command("savemedal",target);
       destruct(medal);
       tell_object(target, "You have been banished from the Paladins Guild "+
           "by "+capitalize(this_player()->query_real_name())+".\n");
       target->add_guild_exp(-target->query_guild_exp());
     }
   }
   save_data();
   return 1;
}

restore(str) {
   int i;

   restore_data();
   if(!banished)   
     banished = ({ });
   if(member_array(str, banished) == -1) {
     write(capitalize(str)+" has not been banished from the Paladins.\n");
     return 1;
   }
   for(i=0; i < sizeof(banished); i++)
      if(str == banished[i])
        break;
   banished -= ({ banished[i] });
   write(capitalize(str)+" has been remove from the banish list.\n");
#ifdef LOGBANISH   
   write_file(LOGFILE, "[*] "+capitalize(str)+" was removed from the "+
        "banished list by "+capitalize(this_player()->query_real_name())+
        " "+ctime(time())+"\n");
#endif
   save_data();
   return 1;
}

banish_list() {
   int i, cnt;

   restore_data();
   if(!banished)
     banished = ({ });
   cnt = 0;
   write("Players banished from Paladins:\n");
write("[================================================================]\n");   
   if(!sizeof(banished))
     write("None.\n");
   else
   for(i=0; i < sizeof(banished); i++) {
      write(justify(capitalize(banished[i]),15));
      cnt++;
      if(cnt == 4) {
        write("\n");
        cnt = 0;
      } else
        write(justify("",3));
   }
   if(cnt)
     write("\n");
write("[================================================================]\n");   
   return 1;
}

save_data() {
   save_object(FILE);
   return 1;
}

restore_data() {
   restore_object(FILE);
   return 1;
}

query_banished() {
   restore_data();
   if(!banished)
     banished = ({ });
   return banished;
}


