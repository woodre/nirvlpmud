#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

int ishere, i;
string hand1, hand2, winner, loser, hitter, hittee;

reset(arg) {

  if (arg) return;
   
  set_name("guy");
  set_alt_name("referee");   
  set_alias("Vizard");
  set_long("\nGuy is a strong tall man, muscular with very large hands.\n\
He wears khaki pants and suspenders over a white t-shirt.  His\n\
slick long black hair is combed straight back.  As he walks\n\
around the pit area, from one handler to another examining the\n\
gamecocks, it is clear that he is at home in this domain.\n");
  set_short("Guy Vizard, a referee");
  set_type("human");
  set_level(1);
  set_attrib("str", 20);
  set_attrib("sta", 20);
  set_al(-800);
  set_aggressive(0);
  ishere = 0;

/* Let's have a way to distinguish these guys so we can call the fight */
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
  if (this_player() && this_player()->is_player() && !ishere 
      && find_call_out("cock_fight") == -1 && find_call_out("cock_fight2") == -1 
      && find_call_out("cock_fight3") == -1 && find_call_out("cock_fight4") == -1 
      && find_call_out("cock_fight5") == -1 && find_call_out("cock_fight6") == -1 
      && find_call_out("cock_fight7") == -1 && find_call_out("cock_fight8") == -1 
      && find_call_out("cock_fight9") == -1)
    { 
      call_out("cock_fight", 2); 
      ishere ++; 
    } 
}

cock_fight()
{ 
  say("\nThe referee moves to the center of the pit.\n"+
      "He gazes over the crowd then raises his right hand.\n\n"+
      "A hush falls over the crowd . . . . .\n\n");
  call_out("cock_fight2",6);
}

cock_fight2()
{ 
  say(BOLD+"    'The next match will pit two fine local birds against each other.'\n\n"+NORM+
      "He walks over to the first handler\n"+
      "  gently looking over the contender.\n\n"+
      "He then slowly walks across the pit\n"+
      "  to examine the second contender.\n\n");
  call_out("cock_fight3",5);
}

cock_fight3()
{
  say("He walks back to the center of the pit and announces:\n\n"+BOLD+
      "     'These excellent aggressive birds are ready.'\n\n"+NORM);
  call_out("cock_fight4",4);
}

cock_fight4()
{ 
  say("Each of the handlers squats and places his bird on the\n"+
      "earth at the edge of the pit, holding it closely but gently.\n\n");
  say("An assistant brings an old but still feisty cock to the center.\n\n"+
      "The handlers hold their birds more tightly as the birds claw the\n"+
      "air and become more agitated, trying to attack the bait bird.\n\n");
  call_out("cock_fight5",8);
}

cock_fight5()
{ 
  say("The crowd waits anxiously . . . . .\n\n");
  call_out("cock_fight6",6);
}

cock_fight6()
{ 
  say("Each of the handlers squats and places his bird on the\n"+
      "earth at the edge of the pit, holding it closely but gently.\n");
  say("The cocks scratch and squawk as they try to reach the center.\n\n");
  call_out("cock_fight7",8);
}

cock_fight7()
{ 

  say(BOLD+"     "+hand1+" has brought some of his finest cocks today.\n\n"+NORM);
  say(hand1 + " brings his cock to the center of the pit.\n\n");
  say(BOLD+"     And over here is "+hand2+" who has brought an excellent bird.\n\n"+NORM);
  say(hand2 + " brings his cock to the center of the pit.\n\n"); 
  if(!present("cock", environment()))
    {
    for(i=0;i<2;i++) 
      {
      move_object(clone_object("players/softly/algiers/mobs/cocks.c"),
		  environment(this_object()));     
    }
  }
  call_out("cock_fight8",4);
}

cock_fight8()
{ 
  say("The assistant snatches up the bait bird and moves to the back.\n\n");
  say(BOLD+"     Release your cocks.\n\n"+NORM);
  call_out("cock_fight9",4, 1);
}

/* All of the fight takes place here */
cock_fight9(round)
{
  string hitter, hittee;
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
  /* Let the winner have more talking than the loser */
  if(random(3)) do_hit(winner, loser); 
  else do_hit(loser, winner);

  do_hit(hitter, hittee)
    {
      switch(random(7))
	     {
	     case 0: say(HIR + "     " + hitter + "'s bird flies feet first into " + hittee + "'s\n"+
			 "     who retreats, then shakes slightly.\n\n" + NORM); 
	     break;
	     case 1:say(HIR + "     " + hitter + "'s bold cock lifts into the air, beating \n"+
			"     "+ hittee + "'s cock with its strong wings.\n\n" + NORM); 
	     break;
	     case 2:say(HIR + "     ""In a flurry of feaathers," + hitter + "'s bird leaps to\n"+
			"     attack, it's gaff and talons clawing " + hittee + "'s cock.\n\n" + NORM); 
	     break;
	     case 3:say(HIR + "     " + hitter + "'s cock jumps forward and mauls his opponent.\n"+
			"     Blood pours from "+ hittee +"'s cock.\n\n" + NORM); 
	     break;
	     case 4:say(HIR + "     ""Dust roils up from the floor of the pit as "  + hitter + "'s\n"+
			"     cock scratches and pounds his opponent with his wings.\n\n" + NORM); 
	     break;
	     case 5:say(HIR + "     ""The two fighting cocks face off in the center of the pit.\n"+
			"     " + hittee + "'s cock stretches forward to claw at "+ hittee +"'s cock.\n\n"+ NORM); 
	     break;
	     case 6:say(HIR + "     ""Dust roils up from the floor of the pit as "  + hitter + "'s\n"+
			"     cock scratches and pounds his opponent with his wings.\n\n" + NORM); 
	     break;
	     }
	     }
      /* Round over  - count it*/
      round ++;
    }
  /* End it */
  if(round > 6) 
    { 
      say(BOLD + "     " + winner + "'s cock wins again.\n\n"+ NORM +
	  "As "+ loser + "drags the lifeless body of his cock away,\n"+hitter+
	  "walks around the pit holding his victorious cock high in the air.\n\n");
      destruct(present("cock", environment()));
      destruct(present("cock", environment()));
      call_out ("cock_fight",30); /* Go back and do it again */
      return; 
    }
  /* Do another round of the fight */
  call_out("cock_fight9", 2, round);
}
