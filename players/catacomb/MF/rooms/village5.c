#include "/players/catacomb/misc/ansi.h"
inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
short_desc =(BOLD+WHT+"The Dragon's Breath"+NORM);
long_desc =(
"  It appears that all the elves in the village are in here enjoying\n"+
"a glass of Shamot's finest wine.  The bar is packed with elves talking\n"+
"about anything and everything.  Several tables are scattered throughout\n"+
"the tavern, every one filled with adventurers.  A wandering minstril\n"+
"sits in the corner playing his lute, and telling marvelous stories of\n"+
"bravery.  Behind the bar, an old elf hustles to greet each customer\n"+
"in his fine establishment.  A serving lady rushes around trying to take\n"+
"everyones orders.  The elves seem to be in high spirits all through the \n"+
"bar.\n");

items = ({
         "elves",
         "Elves of every age speak to each other about unimportant issues",
         "elf",
         "An old elven barkeep hustles behind the bar trying to keep up with the orders",
         "tables",
         "Finely crafted tables are scattered around the tavern",
         "table",
         "A small table sits in the corner with a minstril sitting at it",
         "adventurers",
         "Several adventurers are scattered throughout the tavern trading stories",
         "lady",
         "The serving lady curtseys to you then rushes off to fill another order",
         "minstril",
         "A wandering minstril sings of many quests, perhaps you could 'ask' him about his most recent experiences",
         "barkeep",
         "The barkeep tells you: If you want something just 'ask' or 'order' something"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/village4.c","out"
	});
}
init(){
  ::init();
      add_action("party","listen");
      add_action("askem","ask");
      add_action("orderem","order");  
  }

party()
{
   	write("Sounds of a minstril playing a lute can be heard over the babble of\n"+
      	  "the many people in the tavern\n");
  	return 1;
}

askem(str)
{
  if (!str)
  {
    write("Ask who?");
    return 1;
  }
  else
  {
    if(str == "minstril")
    {
      write("The minstril tells you: 'Listen well my friend for I have a riddle\n");
      write("for you.'\n");
      write("Let me tell you of a great quest, one of a great feat\n");
      write("If you can find the seven lords, your life will be complete.\n");
      write("Only seeing them is a gigantic no\n");
      write("To defeat them is how you must go.\n");
      write(RED+"\nOne is the ruler of flame Ifreet\n"+NORM);
      write("He is the first you must defeat.\n");
      write(BLK+"\nAn ancient monster of the mist\n"+NORM);
      write("It too, you must dismiss.\n");
      write(WHT+"\nA beacon of light within the darkness\n"+NORM);
      write("He will be one of the toughest.\n");
      write(BLU+"\nA creature living in the very deep\n"+NORM);
      write("With its many limbs you must compete.\n");
      write(GRN+"\nYou must wander around and around\n"+NORM);
      write("To find the creature that is a part of the ground.\n");
      write(HIY+"\nDefeat the creature without a true form\n"+NORM);
      write("It can be found in the eye of the storm.\n");
      write(HIB+"\nIf you can handle these many storms\n");
      write("You shall see death in all it's forms\n"+NORM);
      write("\n\nNow if you please, I have a fine wine to finish.'\n");
      write("The ministril bids you farewell and returns to his drink.\n");
      return 1;
    }
    if (str == "barkeep")
    {
      write("The barkeep tells you: I have the following for sale:\n");
      write("\n\n =======Wine================Cost============\n");
      write(" |                                         |\n");
      write(" | 1)Shamot's finest         500           |\n");
      write(" |                                         |\n");
      write(" | 2)Shamot's recent         250           |\n");
      write(" |                                         |\n");
      write(" ===========================================\n");
      write("\n\n Just 'order' <#> of which you would like.\n");
      return 1;
    }
  }
}
orderem(str)
{
  if (!str)
  {
     write("Order which number?\n");
     return 1;
  }
  else
  {
    if (str == "1")
    {
    
    }
    
    if (str == "2")
    {
    
    }
    else
    {
      write("Order either 1 or 2.\n");
      return 1;
    }
  }
}