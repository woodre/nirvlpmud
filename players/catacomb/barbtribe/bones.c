inherit "/obj/treasure.c";
#define TPN this_player()->query_name()
object sNo,Ngame;

reset (arg) {
	set_id("bones");
	set_short("A set of bones");
	set_long(
      "  This is the game of the Clan of the Snake.  To play\n"+
      "just type 'throw bones' to start a game.  After the\n"+ 
      "first throw the object is to throw them until you get\n"+
      "the same amount in the circle as your first throw.  Two\n"+
      "in is a loss and one in is a win automatic on the first throw.\n");
	set_weight(1);
     	Ngame = 1;
}

init(){
  ::init();
     add_action("throws", "throw");   
  }

throws(str)
{
  if(!str) 
  { 
    write("What would you like to throw?\n"); 
    return 1; 
  }
  if(str == "bones")
  {
   write("You throw the bones into the circle.\n");
   if (Ngame == 1)
   {
    switch (random(6))
    {
     case 1:
    {
     write("You roll the bones and 1 stays in the circle, YOU WIN!!\n");
     say(TPN+" throws the bones and 1 stays in the circle, "+TPN+" WINS.\n");
     break;
    }
    case 2:
    {
      write("Ohh no two stayed in, you lose.\n");
	  say(TPN+" throws the bones and loses with two in.\n");
      break;
    }
    case 3:
    {
    	write("You've thrown a three now try and get it again.\n");
	    say(TPN+" throws the bones and gets three to stay in.\n");
	    Ngame = 0;
	    sNo = 3;
  	    break;
    }
    case 4:
    {
    	write("You've thrown a four now try and get it again.\n");
	    say(TPN+" throws the bones and gets four to stay in.\n");
	    Ngame = 0;
	    sNo = 4;
 	    break;
    }
    case 5:
    {
    	write("You've thrown a five now try and get it again.\n");
	    say(TPN+" throws the bones and gets five to stay in.\n");
	    Ngame = 0;
	    sNo = 5;
	    break;
    }
    case 6:
    {
    	write("You've thrown a six now try and get it again.\n");
	    say(TPN+" throws the bones and gets six to stay in.\n");
	    sNo = 6;
	    break;
    }
    case 0:
    {
        write("Try again all of them went out of the circle\n");
    	break;
    }
   }
   return 1;
  }
  if(Ngame == 0);
  {
   switch (random(6))
   {
    case 1:
    {
     write("1 stays in the circle, try again\n.");
     say(TPN+" throws the bones and 1 stays in the circle.\n");
     break;
    }
      case 2:
    {
      write("Ohh no two stayed in, you lose.\n");
	  say(TPN+" throws the bones and loses with two in.\n");
	  Ngame = 1;
      break;
    }
     case 3:
     {
	if (sNo == 3)
	{
	  write("You throw another three, YOU WIN!!\n");
	  say(TPN+" throws another three and wins.\n");
	  Ngame = 1;
	  break;
	}
     	else
     	{
	  write("You've throw a three but need a "+sNo+", try again.\n");
	  say(TPN+" throws a three.\n");
	  break;
     	}
     }
     case 4:
     {
	if (sNo == 4)
	{
	  write("You throw another four, YOU WIN!!\n");
	  say(TPN+" throws another four and wins.\n");
	  Ngame = 1;
	  break;
	}
     	else
     	{
	  write("You've throw a four but need a "+sNo+", try again.\n");
	  say(TPN+" throws a four.\n");
	  break;
     	}
     }	
     case 5:
     {
	if (sNo == 5)
	{
	  write("You throw another five, YOU WIN!!\n");
	  say(TPN+" throws another five and wins.\n");
	  Ngame = 1;
	  break;
	}
     	else
     	{
	  write("You've throw a five but need a "+sNo+", try again.\n");
	  say(TPN+" throws a five.\n");
	  break;
     	}
     }	
     case 6:
     {
	if (sNo == 6)
	{
	  write("You throw another six, YOU WIN!!\n");
	  say(TPN+" throws another six and wins.\n");
	  Ngame = 1;
	  break;
	}
     	else
     	{
	  write("You've throw a six but need a "+sNo+", try again.\n");
	  say(TPN+" throws a six.\n");
	  break;
     	}
     }
     case 0:
     {
	  write("All the bones fell out of the circle, throw again.\n");
	  break;
     }
   }
   return 1;
  } 	
 }
 return 1; 
}


