inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_id("berry");
  set_short("A red berry");
  set_weight(1);
  set_value(0);
  set_long(
"This is a small red berry.  It is somewhat plump and looks rather tasty.\n"+
"Some sticky yellow liquid can be seen on the outside of the berry.  To\n"+
"sell it for it's full value you could 'cash' it in, or you could 'eat' it.\n");
}

  void init(){
    ::init();
  add_action("eat_cmd", "eat");
  add_action("cash_cmd", "cash");
}

status eat_cmd(string str)
{
int msg;
 msg = random(5);
 if(!present(TO, TP)) return 0;
 if(!str) return 0;
  if(str=="fruit", "berry")
  {
  write("You swallow the red berry...\n");
  switch(msg)
  {
  case 0:
	  write("Your stomach begins to ache all over...\n");
	  break;
  case 1:
	  write("You suddenly feel very dizzy...\n");
	  break;
  case 2:
	  write("You all of a sudden don't feel too good...\n");
	  break;
  case 3:
	  write("Suddenly your vision gets blurry...\n");
	  break;
  case 4:
	  write("Your muscles begin to ache all over...\n");
	  break;
  }
  TP->add_hit_point(-7);
   say(TP->QN+" eats a red berry and begins to look ill.\n");
    destruct(TO);
return 1; 
  } 
return 1; 
}


status cash_cmd(string str){
int cash, rcash;
 if(!present(TO, TP))  return 0;
 if(!str){ write("Usage:  'cash berry'\n");  return 1; }
 if(str=="berry"){
 cash = 0-random(100);
 rcash = cash * -1;
  write(
"You hold the berry up and ask if anyone wants it...    An old woman\n"+
"offers to take it off your hands if you'll pay her "+rcash+" coins.  You pay\n"+
"her the "+rcash+" coins, happy to be rid of the berry.\n");
  TP->add_money(cash);
  if(TP->query_money() < 0)
  {
   write("\nYou don't have enough money, but she takes the berry anyway.\n");
	  TP->add_money((int)TP->query_money() * -1);
	  return 1;
  }
  destruct(TO);
return 1; } }
