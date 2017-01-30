#include "/players/mokri/define.h"
#define PBALL_DIR "/players/mokri/stuff/paintball/"

inherit "/players/vertebraker/closed/std/room.c";
int game_on, starttime;
string *players, *blueplayers, *redplayers;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A Paintball Shack");
   set_long("A small shack with a counter and a sign.\n");
   add_object("/players/mokri/stuff/guesser");
   add_object("/open/mokri/maps/map_reader");
   add_object("/players/mokri/obj/itemDispenser");
   add_item("counter","A long, wooden counter extends the length of the room.\n");
   add_item("sign","You may 'read sign'.\n");
   add_exit("/room/path1","west");
   add_exit("/players/mokri/clans/hall","east");
}

init()
{
   ::init();
   add_action("read","read");
   add_action("paintball","paintball");
   add_action("joinone","joinone");
   add_action("joinall","joinall");
   add_action("unjoin","unjoin");
   add_action("endgame","endgame");
   add_action("winners","winners");
   add_action("list_players","players");
}

int get_player(string str)
{
   int how;
   
   if(!players) players = ({ });
   if(member(players,str+"_all") != -1) how = 2;
   if(member(players,str+"_once") != -1) how = 1;
   
   return how;
}

string get_player_name(string str)
{
   int x;
   string tmp, tmp2;
   
   if(!players) players = ({ });
   x = member(players,str);
   if(x == -1) return tmp;
   if(sscanf(str,"%s_%s",tmp,tmp2));
   return tmp;
}

int remove_player(string str)
{
   if(!players) players = ({ });
   str = LOWER(str);
   if(get_player(str) == 1)
      players -= ({ str + "_once" });
   if(get_player(str) == 2)
      players -= ({ str + "_all" });
   
   return 1;
}

int add_player(string str, string how)
{
   str = LOWER(str);
   how = LOWER(how);
   if(!players) players = ({ });
   if(how != "all" && how != "once") return 0;
   if(get_player(str)) return -1;
   players += ({ str + "_" + how });
   return 1;
}

int winners()
{
   write("            Recent Paintball Winners\n"+
      "================================================\n");
   tail("/open/mokri/paintball/winners");
   return 1;
}

int end_game(string winning_team)
{
   string teammembers, *my_winner;
   object pgun, *us;
   int x;
   
   starttime = 0;
   game_on = 0;
   us = users();
   for(x = 0; x < sizeof(us); x++)
   {
      pgun = present("pballgun",us[x]);
      if(get_player(LOWER((string)us[x]->query_real_name())) == 1)
         remove_player(LOWER((string)us[x]->query_real_name()));
      if(pgun) destruct(pgun);
   }
   if(winning_team == BLU+"Blue"+NORM) my_winner = blueplayers;
   if(winning_team == RED+"Red"+NORM) my_winner = redplayers;
   if(my_winner)
      {
      if(winning_team == BLU+"Blue"+NORM) my_winner = blueplayers;
      if(winning_team == RED+"Red"+NORM) my_winner = redplayers;
      teammembers = "";
      for(x = 0; x < sizeof(my_winner); x++)
      teammembers += my_winner[x]+"  ";
      write_file("/open/mokri/paintball/winners","Team Members: " + teammembers +"\n\n");
   }
   return 1;
}

int startme()
{
   string tname, pname, *tmp_removal;
   object pgun, my_player;
   int x, team, num_players;
   
   team = 1;
   blueplayers = ({ });
   redplayers = ({ });
   tmp_removal = ({ });
   for(x = 0; x < sizeof(players); x++)
   {
      pname = get_player_name(players[x]);
      my_player = find_player(pname);
      if(my_player)
         {
         pgun = clone_object(PBALL_DIR+"gun");
         if(team == 1)
            {
            pgun->set_team("blue");
            tname = BLU+"BLUE"+NORM;
            blueplayers += ({ pname });
         }
         
         if(team == -1)
            {
            pgun->set_team("red");
            tname = RED+"RED"+NORM;
            redplayers += ({ pname });
         }
         
         pgun->all_chat(CAP(pname)+" has joined the " + tname + " team.");
         move_object(pgun,my_player);
         tell_object(my_player,"A game of PAINTBALL has started!\nYou are on the " + tname + " team. Look at your gun for help.\n");
         team *= -1;
         num_players += 1;
         if(get_player(pname) == 1)
            tmp_removal += ({ pname });
       }
   }
   
   for(x = 0; x < sizeof(tmp_removal); x++)
   remove_player(tmp_removal[x]);
   
   if(num_players < 2)
      {
      pgun = clone_object(PBALL_DIR+"gun");
      pgun->all_chat("  TOO FEW PLAYERS. GAME CANCELLED.");
      end_game(0);
   }
   
   return 1;
}

int joinone()
{
   if(get_player((string)TPRN))
      {
      write("You are already signed up.\nUse 'unjoin' if you would like to quit.\n");
      return 1;
   }
   
   add_player((string)TPRN,"once");
   write("You are signed up for the next game.\nUse 'unjoin' before the game starts if you would like to quit.\n");
   return 1;
}

int joinall()
{
   if(get_player((string)TPRN))
      {
      write("You are already signed up.\nUse 'unjoin' if you would like to quit.\n");
      return 1;
   }
   
   add_player((string)TPRN,"all");
   write("You are signed up for all games until reset.\nUse 'unjoin' if you would like to quit.\n");
   return 1;
}

int unjoin()
{
   if(!get_player((string)TPRN))
      {
      write("You are not signed up.\nUse 'joinall' or 'joinone' if you would like to play.\n");
      return 1;
   }
   
   remove_player((string)TPRN);
   write("You are no longer signed up for Paintball.\n");
   return 1;
}

int endgame()
{
   object tmp_gun;
   if(TP->query_level() < 21) return 0;
   tmp_gun = clone_object(PBALL_DIR+"gun");
   tmp_gun->all_chat(CAP((string)TPRN)+ " HAS ENDED THE GAME.");
   end_game(0);
   destruct(tmp_gun);
   write("You have ended the game.\n");
   return 1;
}

int paintball()
{
   string tmp_name;
   int x;
   object tmp_guy;
   
   if(game_on)
      {
      if(time() < starttime)
         write("A game is already scheduled for:\n"+ctime(starttime)+"\n");
      if(time() >= starttime)
         write("A game is already in progress.\n");
      return 1;
   }
   
   if(!get_player((string)TPRN))
      add_player((string)TPRN,"once");
   starttime = time() + 60;
   game_on = 1;
   write("A game will start in 60 seconds.\n");
   for(x = 0; x < sizeof(players); x++)
   {
      tmp_name = get_player_name(players[x]);
      tmp_guy = find_player(tmp_name);
      if(tmp_guy)
         tell_object(tmp_guy,RED+"["+BLU+"PAINTBALL"+RED+"] "+NORM+"The game will start in 60 seconds. Quick, hide!\n");
   }
   call_out("startme",60);
   return 1;
}

int list_players()
{
   int x;
   
   write("\nRoster for next game\n"+
      "====================\n");
   if(!sizeof(players)) write("NONE.\n");
   for(x = 0; x < sizeof(players); x++)
   write((x+1) + ". " + CAP(get_player_name(players[x]))+"\n");
   return 1;
}

int read(string str)
{
   
   if(str != "sign") return 0;
   
   write("          PAINTBALL\n"+
      "=============================\n"+
      "Command                Action\n\n"+
      "paintball              Start a game\n"+
      "joinone                Join the next game\n"+
      "joinall                Auto-Join all games until reset\n"+
      "unjoin                 Unset 'join' status\n"+
      "players                Check list of players signed up\n"+
      "winners                View the most recent winning teams\n");
   if(TP->query_level() > 20)
      write("\n          Wizards Only\n"+
      "endgame                Ends the current game\n");
   
   return 1;
}

set_game_on(int go) { game_on = go; }
set_starttime(int st) { starttime = st; }

query_game_on() { return game_on; }
query_starttime() { return starttime; }
