#include "/players/mokri/define.h"
#define PBALL_DIR "/players/mokri/stuff/paintball/"
string team;

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("gun");
   set_alias("pballgun");
   set_short("A neutral paintball gun");
   set_long("You are engaged in a paintball match!\n\n"+
      "Commands are:\n"+
      "  shoot <player> - shoot a player when you\n"+
      "                   see them to remove them from\n"+
      "                   the game! Careful not to shoot\n"+
      "                   yourself or someone on your team!\n"+
      "  pteams         - View whos playing, and what team they are on\n"+
      "  pchat <msg>    - Send <msg> to EVERYONE playing.\n"+
      "  tchat <msg>    - Send <msg> to just your team.\n"+
      "To quit, simply drop your gun.\n");
   
}

init()
{
   ::init();
   add_action("shoot","shoot");
   add_action("pteams","pteams");
   add_action("pchat","pchat");
   add_action("tchat","tchat");
}

int pteams()
{
   int x, a;
   object pgun, *us;
   
   us = users();
   for(a = 0; a < 2; a++)
   {
      write("\n");
      if(!a) write(RED);
      if(a) write(BLU);
      write("The ");
      if(!a) write("RED");
      if(a) write("BLUE");
      write(" team\n"+NORM);
      for(x = 0; x < sizeof(us); x++)
      {
         pgun = present("pballgun",us[x]);
         if(pgun)
            {
            if(!a && (string)pgun->query_team() == "red") write("  "+CAP((string)us[x]->query_real_name())+"\n");
            if(a && (string)pgun->query_team() == "blue") write("  "+CAP((string)us[x]->query_real_name())+"\n");
          }
       }
   }
   return 1;
}

int all_chat(string msg)
{
   int x;
   object *us;
   
   if(!msg)
      return 0;
   us = users();
   
   for(x = 0; x < sizeof(us); x++)
   {
      if(present("pballgun",us[x]))
         tell_object(us[x],RED+"["+BLU+"PAINTBALL"+RED+"] "+NORM+msg+"\n");
   }
   return 1;
}

int pchat(string msg)
{
   if(!msg)
      {
      write("What would you like to say?\n");
      return 1;
   }
   
   all_chat(CAP((string)TPRN) + ": " + msg);
   return 1;
}

int team_chat(string msg)
{
   int x;
string start_msg;
   object pgun, *us;
   
   if(!msg)
      return 0;
   us = users();
   
   if(team == "red") start_msg = "["+RED+"RED TEAM"+NORM+"]";
   if(team == "blue") start_msg = "["+BLU+"BLUE TEAM"+NORM+"]";
   for(x = 0; x < sizeof(us); x++)
   {
      pgun = present("pballgun",us[x]);
      if(pgun && (string)pgun->query_team() == team)
         tell_object(us[x],start_msg+" "+msg+"\n");
   }
   return 1;
}

int tchat(string msg)
{
   if(!msg)
      {
      write("What would you like to say?\n");
      return 1;
   }
   
   team_chat(CAP((string)TPRN)+ ": " + msg);
   return 1;
}

int check_win()
{
   string winner;
   object pgun, *us;
   int x, red, blue;
   
   us = users();
   for(x = 0; x < sizeof(us); x++)
   {
      pgun = present("pballgun",us[x]);
      if(pgun && (string)pgun->query_team() == "red") red++;
      if(pgun && (string)pgun->query_team() == "blue") blue++;
   }
   
   if(team == "red") red--;
   if(team == "blue") blue--;
   if(!red) winner = BLU+"Blue"+NORM;
   if(!blue) winner = RED+"Red"+NORM;
   
   if(winner)
      {
      all_chat("   The game is over!");
      all_chat("   The " + winner + " team wins!");
      write_file("/open/mokri/paintball/winners","The " + winner + " team\t\t" + ctime()+"\n");
      "/players/mokri/stuff/paintball/shack"->end_game(winner);
   }
   return 1;
}

kill_me(object who)
{
   object owner;
   owner = environment(this_object());
   if(owner != who) all_chat(CAP((string)owner->query_real_name()) + " has been shot by " + CAP((string)who->query_real_name()));
   if(owner == who) all_chat(CAP((string)owner->query_real_name()) + " is out of the game.");
   check_win();
   destruct(this_object());
}

int shoot(string who)
{
   string target_team;
   object pgun, them;
   
   who = LOWER(who);
   if(!who)
      {
      write("Whom would you like to shoot?\n");
      return 1;
   }
   
   them = find_player(who);
   if(!them || !present(them,ENV(TP)))
      {
      write("You want to shoot whom now?\n");
      return 1;
   }
   
   pgun = present("pballgun",them);
   
   if(!pgun)
      {
      write("They are not in the game!\n");
      return 1;
   }
   
   target_team = (string)pgun->query_team();
   
   if(who == LOWER((string)TPRN))
      {
      pgun->kill_me(TP);
      return 1;
   }
   
   pgun->kill_me(TP);
   if(target_team == team)
      {
      all_chat(CAP((string)TPRN)+ " has shot a team mate, and is out, too!");
      kill_me(TP);
   }
   return 1;
}

set_team(string te)
{
   team = te;
   if(team == "red") set_short(RED+"A Red Paintball Gun"+NORM);
   if(team == "blue") set_short(BLU+"A Blue Paintball Gun"+NORM);
}

query_team() { return team; }
drop()
{
   kill_me(TP);
   return 1;
}
