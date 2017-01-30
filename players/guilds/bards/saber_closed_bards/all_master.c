
/*
 * ALLIANCE MASTER (4/8/94)
 * For banishing players from the Alliance.
 */

#define SAVEFILE "players/saber/closed/bards/stats/alliance_data"

string *banished_players;


justify(str,len) { return extract(str+"                          ",0,len-1); }

query_banished() {
   restore_data();
   if(!banished_players)
     banished_players = ({ });
   return banished_players;
}

banish(str) {    
    object all_object;

    if(!str) {
      write("Who would you like to banish?\n");
      return 1;
    }
    if(member_array(str, query_banished()) != -1) {
      write(capitalize(str)+" has already been banished from the Alliance.\n");
      return 1;
    }
    if(find_player(str)) {
      all_object = present("alliance_obj", find_player(str));
      if(all_object)
        all_object->banish();
    }
    banished_players += ({ str });
    write("You have banished "+capitalize(str)+" from the Alliance.\n");
    save_data();
    return 1;
}

forgive(str) {    
    if(!str) {
      write("Who would you like to forgive?\n");
      return 1;
    }
    if(member_array(str, query_banished()) == -1) {
      write(capitalize(str)+" has not been banished from the Alliance.\n");
      return 1;
    }
    banished_players -= ({ str });
    write("You have forgiven "+capitalize(str)+".\n");
    save_data();
    return 1;
}

list_players() {
   int i, cnt;

   write("Banished Players:\n");
   write("===============================================================\n");
   if(!sizeof(banished_players)) 
     write("None.\n");
   else {
     cnt = 0;
     for(i=0; i < sizeof(banished_players); i++) {
        if(cnt == 3) {
          write("\n");
          cnt = 0;
        }
         write(justify(capitalize(banished_players[i]),15));
        cnt++;
     }
     write("\n");
   }  
   write("=============================================================\n");
   return 1;
}

save_data() {
   save_object(SAVEFILE);
   return 1;
}

restore_data() {
   restore_object(SAVEFILE);
   return 1;
}

