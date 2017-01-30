#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

int amount, payout;
string winner, loser, who;

mapping wagers;

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("fish");
  set_alt_name("weasel");   
  set_alias("f15h");
  set_long("\nFish is a small weasel-faced man with a furtive manner.  He\n\
scurries around the spectator area of cock fights, searching\n\
for those who wish to place a wager.  He wears limp black\n\
trousers that appear 3 sizes too big and a white dress shirt\n\
that is rumpled and worn.  His brown belt is long enough to\n\
wrap around his body twice.  His shoes are very dusty and worn.\n\
To place a bet just "+BOLD+"wager <handler> <amount>\n"+NORM);
  set_short("Fish");
  set_race("human");
  set_gender("male");
  set_level(12);
  set_al(0);
  set_aggressive(0);
  add_money(400+random(150));
  set_chat_chance(12);
  load_chat("Fish sidles up to you and says: Want to place a wager?\n");
  load_chat("Fish goes: Psssst.  You can place a bet with me.\n");
  load_chat("Fish says: You know you want to bet on a winner.\n");
  load_chat("Fish tells you: Double your money!.\n");
  load_chat("Fish holds up a wad of bills and rifles through them.\n");
  load_chat("Fish says: It's easy.  Just 'wager <handler> <amount>'\n");
  wagers = ([ ]);
}

init() 
{ 
  ::init(); 
  /* blah blah blah ... this shuts him up but he never starts again */
  if(environment() && present("cock", 
			      environment())) set_chat_chance(0); 
  else set_chat_chance(8); 
  add_action("cmd_wager","wager");
  add_action("cmd_wager","bet");
}

set_winlose(arg1,arg2) 
{ 
  winner = arg1; 
  loser = arg2; 
  wagers = ([ ]);
} 

cmd_wager(string str)
{
  if(!str) return 0;
  if(sscanf(str, "%s %d", who, amount) == 2)
    {
      who = capitalize(who);
      if(who != winner && who != loser)
        {
          notify_fail("\
Fish sneers: Bet on one of the handlers in this match.\n");
          return 0;
        } 
      if(wagers[(string)this_player()->query_real_name()]) 
        { 
          write("Fish says: You already bet.  Wait 'til next time Bud.\n"); 
          return 1; 
        }
      if(present("cock",environment())) 
	{
	  write("Fish growls: Fights started.  Wait til the next one...\n");
	  return 1;
	}      
      if(amount<0) 
	{
	  write("Fish snarls: What kinda game are you playing?\n");
	  return 1;
	}          
      if(this_player()->query_money() <amount) 
	{
	  write("Fish snaps: You can't afford that!\n");
	  return 1;
	}    
      this_player()->add_money(-(amount));
      if(!wagers[this_player()->query_real_name()]) 
        wagers[this_player()->query_real_name()] = ({ who , amount });  
      write("Fish says: You bet "+amount+" coins on "+who+"'s bird to win.\n");
      return 1;
    }
  notify_fail("\
Fish says: Just 'wager <handler> <amount>'\n");
  return 0;
}


fight_over()
{
  int i, size; 
  string *k; 
  k = keys(wagers); 
  size = sizeof(k); 
  for(i = 0; i < size; i ++) 
    { 
      if(wagers[k[i]][0] == winner)
	{ 
	  payout = (wagers[k[i]][1] * 2);
	  if(find_player(k[i]))
	    {
	      (find_player(k[i]))->add_money(payout);
	      tell_object(find_player(k[i]), "Fish slowly counts out "+payout+" coins.\n");
	    }
	}
      else if(find_player(k[i])) 
	{
	  tell_object(find_player(k[i]), "Fish says: Not this time.  Nice doin' business with ya'.\n");
	}    
    }
}

