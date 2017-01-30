inherit "/obj/treasure.c";
#include <ansi.h>
#define TPN this_player()->query_name()
int newGame,racked,broke,playing,counter,n;
reset (arg) 
{
	set_id("table");
	set_short("A pool table.");
	set_long(
      "	A 9 foot pool table stands before you.\n"+
      "On one end is a small hole for the cue ball, \n"+ 
      "while the other end is open for the other 9 balls.\n\n");
	newGame = 1;				
	racked = 0;					
	broke = 0;					
	playing = 0;
}

init(){
  ::init();
     add_action("rackem", "rack");
     add_action("lookem", "l");
     add_action("breakem", "break");
     add_action("shootem", "shoot");   
  }

rackem(str)
{
  if(!str)
  { 
	write("What would you like to rack?\n"); 
	return 1;
  }
  if (racked == 1)
  {
     write("The balls are already racked.\n");
     return 1;
  if (playing == 1)
  {
      write("You can't rack in the middle of the game.\n");
	return 1;
  }
}
  if((str == "balls") && (newGame == 1))         
  {								  	 			
  	write("You rack the balls in a diamond shape.\n\n");
	say (TPN+" racks the balls in a diamond shape.\n\n");
	racked = 1;
  	return 1; 
  }
}

lookem(str)
{
  if (str == "at balls")
  {
    write("Maybe you could 'rack' them.\n");
    return 1; 
  }
} 

breakem(str) 
{
  if (!str)
  { 
      write("What would you like to break?\n");
	return 1;
  }
  if ((str == "rack") && (racked == 1))      
  { 	
	write("You slowly brings back the cue. Then quickly let's go a burst of strength.\n\n");
	write(BOLD+RED+"CCCC  RRRR    A     CCCC   K  K   !! !!"+NORM+"\n");
	write(BOLD+RED+"C	    R  R   A A	C      K K    !! !!"+NORM+"\n");
	write(BOLD+RED+"C	    RRRR  AAAAA   C      K      !! !!"+NORM+"\n");
	write(BOLD+RED+"C	    R R  A     A  C      K K         "+NORM+"\n");
	write(BOLD+RED+"CCCC  R  R A     A  CCCC   K  K   !! !!"+NORM+"\n");
						  			
      say(TPN+" slowly brings back the cue. Then quickly let's go a burst of strength.\n\n");
	say(BOLD+RED+"CCCC  RRRR    A     CCCC   K  K   !! !!"+NORM+"\n");
	say(BOLD+RED+"C     R  R   A A    C      K K    !! !!"+NORM+"\n");
	say(BOLD+RED+"C     RRRR  AAAAA   C      K      !! !!"+NORM+"\n");
	say(BOLD+RED+"C     R R  A     A  C      K K        "+NORM+"\n");
	say(BOLD+RED+"CCCC  R  R A     A  CCCC   K  K   !! !!"+NORM+"\n");
	say("The balls go flying.  And a ball drops.\n");
	broke = 1;
	playing = 1;
	newGame = 0;
	counter = 1;
   }
   if ((str == "rack") && (racked != 1))
   {
	write("You must rack the balls first.\n");
	return 1;
   }
}

shootem(str)
{
  if (!str) 
  {
     	write("Shoot what?\n");
     	return 1;
  }
  if ((str == "balls") && (broke == 1))
  {
 	n = random(20);
	if (n >= 10)
	{
     	    write("You take a shot and watch as the ball falls in.\n");
	    say(TPN+" takes a shot and watches as the ball falls in.\n");
	    counter = counter + 1;
	    if (counter == 9)
  	    {
		write("You have sunk the nine ball.  YOU WIN!!.\n");
		say(TPN+" cheers as the nine ball falls.\n");
		newGame == 1;
	      counter = 0;
     	      return 1;
	    }
	    return 1;

    }
  	if ((n > 2) && (n < 10))
	{
	  write("You take a shot and bank it around the table missing.\n");
	  write("YOU "+BOLD+HIR+"SUC"+NORM+BLU+"K!!"+NORM+"\n");
	  say(TPN+" goes to shoot the ball and it banks around the\n");
	  say("table, missing."+BOLD+YEL+"  YOU SUCK!!\n"+NORM);
	  return 1;
	}
	if (n <= 2)
	{
	  write("You make an amazing combo shot sinking the 9 ball.\n");
	  write(BOLD+RED+"YOU "+NORM+GRN+" WIN"+NORM+"\n");
   	  say(TPN+" makes an amazing combo shot sinking the 9 ball.\n");
	  say(TPN+BOLD+HIG+" wins the game.\n"+NORM);
	  newGame = 1;				 
	  racked = 0;				
	  broke = 0;
	  playing = 0;
        counter = 0;
	}
  }
}
query_weight() {
	return 5000;
      } 

