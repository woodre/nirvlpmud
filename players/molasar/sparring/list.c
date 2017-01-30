
/*
 * LIST (4/27/94)
 * Holds all the players participating in the sparring
 * with their wins and losses
 */

#define MIN_POINTS 0

/* minimum level to manipulate data */
#define MIN_LEVEL 100

#define SAVEFILE "players/molasar/sparring/data"

justify(str, len) { return extract(str+"                       ",0,len-1); }

int *wins;
int *loses;
string *players;
static string *top_players;
static int top_time;

reset(arg) {
   if(!arg) 
     restore_object(SAVEFILE);
   if(!players) players = ({ });
   if(!wins) wins = ({ });
   if(!loses) loses = ({ });
   get_top_ten_list(); 
}

add_player(what, who) {
   int i;
   
   if(member_array(who, players) == -1) {
     players += ({ who });
     if(what == "won") {
       wins += ({ 1 });
       loses += ({ 0 });
     }
     if(what == "lost") {
       loses += ({ 1 });
       wins += ({ 0 });
     }  
     save_file();
     return 1;
   }
  for(i=0; i < sizeof(players); i++) {
     if(who == players[i])
       break;
  }
  if(what == "won")
     wins[i] += 1;
  if(what == "lost")
    loses[i] += 1; 
  save_file();
  return 1;
}

save_file() {
   save_object(SAVEFILE);
   return 1;
}

show_players() {
   int i, tmp, tmp_wins, tmp_loses;

   write(justify("Player:",14)+justify(" W ",5)+justify(" L ",5)+
         justify(" ",3)+
         justify("Player:",14)+justify(" W ",5)+justify(" L ",5)+
         justify(" ",3)+
         justify("Player:",14)+justify(" W ",5)+justify(" L ",5)+"\n"); 
   write(justify("-------",14)+justify("---",5)+justify("---",5)+
         justify(" ",3)+
         justify("-------",14)+justify("---",5)+justify("---",5)+
         justify(" ",3)+
         justify("-------",14)+justify("---",5)+justify("---",5)+"\n"); 
   tmp = 0;
   if(!sizeof(players))
     return 1;
   for(i=0; i < sizeof(players); i++) {
      tmp += 1;
      write(justify(capitalize(players[i]),14));
      tmp_wins = wins[i];
      tmp_loses = loses[i];
      if(tmp_wins > 99)
        write(justify(tmp_wins,5));
      else
        write(justify(" "+tmp_wins,5));
      if(tmp_loses > 99)
        write(justify(tmp_loses,5)); 
      else
        write(justify(" "+tmp_loses,5));
      if(tmp == 3) {
        write("\n");
        tmp = 0;
      } else
        write(justify(" ",3));
   }
   write("\n");
   return 1;
}

remove_player(who) {
   int i;
   
   if(this_player()->query_level() < MIN_LEVEL)
     return 0;
   if(!who) {
     write("Who do you wish to remove from the player list?\n");
     return 1;
   }
   if(member_array(who, players) == -1) {   
     write(capitalize(who)+" is not listed among the players.\n");
     return 1;
   }
   for(i=0; i < sizeof(players); i++) {
      if(who == players[i])
        break;
   }
   players -= ({ players[i] });
   wins -= ({ wins[i] });
   loses -= ({ loses[i] });
   write(capitalize(who)+" has been removed from the players list.\n");
   save_file();
   get_top_ten_list();
   return 1;
}

set_player(str) {
   string who;
   
   if(this_player()->query_level() < MIN_LEVEL)
     return 0;
   if(!str) {
     write("Who do you wish to add to the player list?\n");
     return 1;
   }
   if(sscanf(str, "%s", who) != 1) {
     write("Usage: add <player_name>\n");
     return 1;
   }
   if(member_array(who, players) != -1) {   
     write(capitalize(who)+" is already listed among the players.\n");
     return 1;
   }
   if(!restore_object("players/"+who)) {
     write("There is no such player on Nirvana.\n");
     return 1;
   }
   players += ({ who });
   wins += ({ 0 });
   loses += ({ 0 }); 
   write(capitalize(who)+" has been placed in the player list.\n");
   save_file();
   return 1;
}
   
win(str) {
   string who, amt;
   int i;

   if(this_player()->query_level() < MIN_LEVEL)
     return 0;
   if(!str || sscanf(str, "%s %d", who, amt) != 2) {
     write("Usage: win <player> <amount>\n");
     return 1;
   }
   if(member_array(who, players) == -1) {
     write(capitalize(who)+" is not listed among the players.\n");
     return 1;
   }
   if(amt > 999 || amt < 0) {
     write("The number must be between 0 and 999.\n");
     return 1;
   }
   for(i=0; i < sizeof(players); i++) {
      if(who == players[i])
        break;
   }
   wins[i] = amt;
   write(capitalize(who)+"'s wins set at "+amt+".\n");
   save_file();
   return 1;
}

lose(str) {
   string who, amt;
   int i;

   if(this_player()->query_level() < MIN_LEVEL)
     return 0;
   if(!str || sscanf(str, "%s %d", who, amt) != 2) {
     write("Usage: lose <player> <amount>\n");
     return 1;
   }
   if(member_array(who, players) == -1) {
     write(capitalize(who)+" is not listed among the players.\n");
     return 1;
   }
   if(amt > 999 || amt < 0) {
     write("The number must be between 0 and 999.\n");
     return 1;
   }
   for(i=0; i < sizeof(players); i++) {
      if(who == players[i])
        break;
   }
   loses[i] = amt;
   write(capitalize(who)+"'s loses set at "+amt+".\n");
   save_file();
   return 1;
}

query_record(who) {
   int i;
   string mess;

   if(member_array(who, players) == -1) 
     return "No record";
   for(i=0; i < sizeof(players); i++) {
      if(who == players[i])
        break;
   }
   mess = "Won: "+wins[i]+" Lost: "+loses[i];
   return mess;
}

query_points(who) {
   int i, points;

   i = who;
   points = wins[i] * 3;
   points -= loses[i] * 2;
   return points;
}

get_top_ten_list() {
   int count, i, high_points, high_player;
   string *tmp_players;

   tmp_players = ({ });
   for(i=0; i < sizeof(players); i++) 
   if(query_points(i) >= MIN_POINTS)
        tmp_players += ({ players[i] });
   top_players = ({ });
   if(sizeof(tmp_players) > 10)
     count = 10;
   else
     count = sizeof(tmp_players);
   while(count) {
     high_points = -10000;
     for(i=0; i < sizeof(tmp_players); i++) {
        if(query_points(i) >= high_points) {
          high_player = i;
       high_points = query_points(i);
        }
     }
     top_players += ({ tmp_players[high_player] });
     tmp_players -= ({ tmp_players[high_player] });
     count -= 1;
   }
   top_time = time();  
}

top_ten_list() {
   int i;

write("********* TOP TEN SPARRING LIST ["+ctime(top_time)+"] *********\n");
write("\n");
write(justify("NO:",5));
write(justify("Name:",14)+justify("Points:",10)+justify("Record:",20)+"\n");       
write(justify("---",5));
write(justify("-----",14)+justify("-------",10)+justify("-------",20)+"\n");   
   for(i=0; i < sizeof(top_players); i++) {
      if(i == 9) 
        write(justify((i+1),5));
      else
        write(justify(" "+(i+1),5));
      write(justify(capitalize(top_players[i]),14));
    write(justify(query_points(i),10));
      write(justify(query_record(top_players[i]),20));
      write("\n");
   }
   write("\n");
   write("SCORING: 3 points for a win, -2 point for a loss.\n");
   return 1;
}




