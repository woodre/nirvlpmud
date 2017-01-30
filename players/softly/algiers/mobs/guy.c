#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

int ishere, i;
string hand1, hand2, winner, loser, hitter, hittee;

reset(arg) {

  if (arg) return;
  ::reset();   

  set_name("guy");
  set_alt_name("referee");   
  set_alias("Vizard");
  set_long("\nGuy is a strong tall man, muscular with very large hands.\n\
He wears khaki pants and suspenders over a white t-shirt.  His\n\
slick long black hair is combed straight back.  As he walks\n\
around the pit area, from one handler to another examining the\n\
gamecocks, it is clear that he is at home in this domain.\n");
  set_short("Guy Vizard, a referee");
  set_race("human");
  set_gender("male");
  set_level(1);
  set_attrib("str", 20);
  set_attrib("sta", 20);
  set_al(-800);
  set_aggressive(0);
  ishere = 0;
}
/* ishere is the test for if players are present ... 
   no reason to continue a fight without an audience  */
decrease_ishere() 
{ 
  ishere--;
} 

void 
init() 
{ 
  ::init();
  if (this_player() && this_player()->is_player() && !ishere 
      && environment() && (environment(this_player()) == environment())
      && find_call_out("cock_fight") == -1 && find_call_out("cock_fight2") == -1 
      && find_call_out("cock_fight3") == -1 && find_call_out("cock_fight4") == -1 
      && find_call_out("cock_fight5") == -1 && find_call_out("cock_fight6") == -1 
      && find_call_out("cock_fight7") == -1 && find_call_out("cock_fight8") == -1 
      && find_call_out("cock_fight9") == -1)
    { 
      ishere ++; 
      call_out("cock_fight", 2); 
    } 
}

cock_fight()
{ 

  switch(random(8))
    {
    case 0:
      hand1 = ("Gerard");break;
    case 1:
      hand1 = ("Alex");break;
    case 2:
      hand1 = ("Raymond");break;
    case 3:
      hand1 = ("Claude");break;     
    case 4:
      hand1 = ("Al");break;
    case 5:
      hand1 = ("Hadley");break;
    case 6:
      hand1 = ("Mervin");break;
    case 7:
      hand1 = ("Oliver");break;     
    }

  switch(random(8))
    {
    case 0:
      hand2 = ("Terry");break;
    case 1:
      hand2 = ("Michael");break;
    case 2:
      hand2 = ("David");break;
    case 3:
      hand2 = ("Jules");break;     
    case 4:
      hand2 = ("Waylon");break;
    case 5:
      hand2 = ("Errol");break;    
    case 6:
      hand2 = ("George");break;
    case 7:
      hand2 = ("Abner");break;   
    }
  if(!random(2)) 
    { 
      winner = hand1; 
      loser = hand2; 
    } 
  else 
    { 
      winner = hand2; 
      loser = hand1; 
    } 

  present("f15h", environment())->set_winlose(winner, loser);
  say("\nThe referee moves to the center of the pit.\n"+
      "He gazes over the crowd then raises his right hand.\n\n"+
      " A hush falls over the crowd . . . . .\n\n"+
      "The man begins to speak...\n\n"+BOLD+
      "   'I, Guy Vizard, will begin the next match in a moment.'\n\n"+NORM);
  call_out("cock_fight2",6);
}

cock_fight2()
{ 
  say(BOLD+"   'The next match will pit two fine local birds against each other.'\n"+NORM);
  say(BOLD+"   '"+hand1+" has brought some of his finest cocks today.'\n"+NORM);
  say(BOLD+"   'And over here is "+hand2+" who has brought some excellent birds.'\n\n"+NORM); 
  call_out("cock_fight3",12);
}

cock_fight3()
{

  say("He walks over to the first handler gently looking over the contender.\n"+
      "He then slowly walks across the pit to examine the second contender.\n\n");
  call_out("cock_fight4",10);
}

cock_fight4()
{ 
  say("He walks back to the center of the pit and announces:\n\n"+BOLD+
      "   'These excellent aggressive birds are ready.'\n\n"+NORM);
  call_out("cock_fight5",8);
}

cock_fight5()
{ 
  say("An assistant brings an old but still feisty cock to the center.\n\n"+
      "The handlers hold their birds more tightly as the birds claw the\n"+
      "air and become more agitated, trying to attack the bait bird.\n\n");
  say(" The crowd waits anxiously . . . . .\n\n");
  call_out("cock_fight6",14);
}

cock_fight6()
{ 
  say("Each of the handlers squats and places his bird on the\n"+
      "earth at the edge of the pit, holding it closely but gently.\n");
  say("The cocks scratch and squawk as they try to reach the center.\n\n");
  call_out("cock_fight7",12);
}

cock_fight7()
{ 
  say(hand1 + " brings his cock to the center of the pit.\n");
  say("The assistant struggles to hold the bait bird.\n");
  say(hand2 + " brings his cock to the center of the pit.\n\n"); 
  if(!present("cock", environment()))
    {
    for(i=0;i<2;i++) 
      {
      move_object(clone_object("players/softly/algiers/mobs/cocks.c"),
		  environment(this_object()));     
    }
  }
  call_out("cock_fight8",6);
}

cock_fight8()
{ 
  say("The assistant snatches up the bait bird and quickly moves\n"+
      "to the back.\n\n");
  say(BOLD+"   'Release your cocks.'\n\n"+NORM);
  call_out("cock_fight9",4, 1);
}

/* All of the fight takes place here */
cock_fight9(round)
{
  string hitter, hittee;
  /* Let the winner have more talking than the loser */
  if(random(3)) 
    {
      hitter = winner; 
      hittee = loser;
    } 
  else 
    {
      hitter = loser; 
      hittee = winner;
    }
     
   switch(random(11))
	     {
	     case 0: say(HIW + "\n\t" + hitter + "'s bird flies feet first into " + hittee + "'s\n"+
			 "\t who retreats, then shakes slightly...\n\n" + NORM); 
	     break;
	     case 1:say(HIW + "\n\t" + hitter + "'s bold cock lifts into the air, beating\n"+
			"\t "+ hittee + "'s cock with its strong wings...\n\n" + NORM); 
	     break;
	     case 2:say(HIW + "\n\t" + "In a flurry of feathers, " + hitter + "'s bird\n"+
			"\t leaps to attack, it's gaff and talons clawing\n"+
			"\t " + hittee + "'s cock...\n\n" + NORM); 
	     break;
	     case 3:say(HIW + "\n\t" + hitter + "'s cock jumps forward and mauls his\n"+
			"\t opponent.  Blood pours from "+ hittee +"'s bird...\n\n" + NORM); 
	     break;
	     case 4:say(HIW + "\n\t" + "Dust roils up from the floor of the pit as\n"+
			"\t "+ hitter + "'s cock scratches and pounds his opponent\n"+
			"\t with his wings...\n\n" + NORM); 
	     break;
	     case 5:say(HIW + "\n\t" + "The two fighting cocks face off in the center\n"+
			"\t of the pit.  "+ hitter + "'s cock stretches forward\n"+
			"\t to claw at "+ hittee +"'s cock...\n\n"+ NORM); 
	     break;
	     case 6:say(HIW + "\n\t" + "Dust roils up from the floor of the pit as\n"+
			"\t "  + hitter + "'s cock scratches and pounds his opponent\n"+
			"\t with his wings...\n\n" + NORM); 
	     break;
	     case 7:say(HIW + "\n\t" + "The deafening sound of wings flapping hard breaks\n"+
			"\t the air.  "+ hittee +"'s cock goes down and "+ hitter +"'s\n"+
			"\t bird lands atop him, his claws engaged...\n\n" + NORM); 
	     break;
	     case 8:say(HIW + "\n\t" + hitter +"'s aggressive bird tears into his\n"+
			"\t opponent, ripping a gouge in "+hittee+"'s cocks chest...\n\n" + NORM); 
	     break;
	     case 9:say(HIW + "\n\t" + "Stalking his prey, "+hitter+"'s wild eyed cock\n"+
			"\t leaps talons first to attack.  "+hittee+"'s bird\n"+
			"\t is no match for him and lands in a heap...\n\n" + NORM); 
	     break;
	     case 10:say(HIW + "\n\t" + "A face-off.  Two birds, both strong and proud,\n"+
			"\t meet in the center of the pit.  Suddenly "+ hitter +"'s\n"+
			"\t bird attacks!  "+hittee+"'s cock slumps...\n\n" + NORM); 
	     break;
	     }
	
      /* Round over  - count it*/
      round ++;
    
  /* End it */
  if(round > 7) 
    { 
      say(BOLD + "   'Another fine match!  " + winner + "'s cock wins again.'\n\n"+ NORM +
	  "As "+ loser + " drags the lifeless body of his cock away, "+winner+" walks\n"+
	  "around the pit holding his victorious cock high in the air.\n\n");
      say("The assistant rushes out and brushes away feathers and debris,\n"+
	  "readying the pit ready for the next match.\n\n\n");
      destruct(present("cock", environment()));
      destruct(present("cock", environment()));
      if(present("fish", environment())) present("fish", environment())->fight_over();
      if(present("fish", environment())) present("fish", environment())->init();
      call_out ("cock_fight",34); /* Go back and do it again */
      return; 
    }
  /* Do another round of the fight */
  call_out("cock_fight9", 6, round);
}
