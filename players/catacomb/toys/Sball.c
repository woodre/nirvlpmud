inherit "/obj/treasure.c";
#include <ansi.h>
#define tpn this_player()->query_name()
reset (arg) {
	set_id("ball");
	set_short("A small squeeze ball"+YEL+"(Yellow)"+NORM);
	set_long(
      "  A ball roughly 3 inches in diameter that can be used to\n"+
      "relieve your tension.  It has a small face that becomes\n"+ 
      "distorted every time you 'squeeze' the ball\n");
}

init(){
  ::init();
     add_action("squeezeem", "squeeze");   
  }

squeezeem(str)
{
  if(!str) 
  { 
    write("What would you like to squeeze?\n");
    return 1; 
  }
  if(str == "ball")
  {
   write("You squeeze the ball over and over making the face on\n");
   write("the ball seem to "+MAG+"scream "+NORM+"out in pain.\n");
   write("With every squeeze you relieve your anger.\n");
   write(BOLD+HIY+"AAAHHHHHH, now don't you feel much better.\n"+NORM);
   say(tpn+" squeezes the ball rapidly calming their growing anger.\n");
   say(tpn+BOLD+HIM+" grits their teeth and utters: This ball\n");
   say("just saved your life.  And you think to yourself thank god\n");
   say("for the squeeze balls.\n"+NORM);
   return 1;
  } 
} 

query_weight() 
{
	return 1;
} 

