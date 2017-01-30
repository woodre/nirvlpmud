/*
*      Function:
*      Change History:
*/
#include <ansi.h>
inherit "/room/room";

reset(arg)
{
::reset(arg);

if(arg) return;

  set_no_clean(1);
set_light(3);

short_desc = ""+HIK+"("+NORM+""+HIC+"Nirvana Cinemas"+NORM+""+HIK+")"+NORM+" "+HIK+"Ticket Stand"+NORM+"";

long_desc =
	"You have happened upon the ticket stand of the famous "+HIC+"Nirvana Cinemas"+NORM+"\n"+
	"theater. There is a long row of plexiglass windows, each with a semi-\n"+
	"circular hole cut from the bottom of each one. There is a door on the\n"+
	"side which looks to be locked, and some levers and a couple chairs\n"+
	"inside the booth, as well as the ticket dispenser. There is a bell\n"+
	"here to ring for service and a sign, which lists which movies are\n"+
	"currently being played.\n";

	items =
({
	"seller",
	"An elderly man in a theater employee uniform. He's here to sell\n"+
	"you your matinee tickets",
	"stand",
	"It's a large ticket stand where you can purchase your way in\n"+
	"to see whatever movie(s) you choose",
	"door",
	"The door looks to be locked up tight",
	"sign",
	"-------"+HIW+"NOW PLAYING"+NORM+"-------\n"+
	"Alien VS Predator               Anaconda\n"+
	"Cujo                            Arachnaphobia\n"+
	"The Hills Have Eyes             \n"+
	"-------"+HIW+"COMING SOON"+NORM+"-------\n"+
	"Candyman                        Gremlins\n"+
	"Hellraiser                      Pumpkinhead\n"+
	"Resident Evil Apocalypse        Texas Chainsaw Massacre\n"+
	"A Nightmare on Elm Street       Friday the 13TH\n"+
	"Saw III                         Deep Blue Sea\n"+
	"Lady in the Water               Critters\n"+
	"Pirates of the Caribbean: Curse of the Black Pearl\n"+
	"Pirates of the Caribbean: Dead Man's Chest\n"+
	"Pirates of the Caribbean: At World's End\n"+
	""+HIW+"One matinee ticket gives you access to all the movies listed."+NORM+"\n"+
	""+HIW+"Tickets are 10000 coins a piece to 'purchase'"+NORM+"\n"+
	""+HIR+"WARNING:"+NORM+" "+GRN+"This is a VERY dangerous area with very large creatures."+NORM+"\n"+
	""+GRN+"Not recommended for solo players, or parties with smaller players in them"+NORM+"",
	"windows",
	"They are made of simple plexiglass but very sturdy",
	"plexiglass",
	"The material used in making these windows so sturdy",
	"levers",
	"The salesman pulls one of these depending on what movie you choose to see\n"+
	"All the levers say "+HIR+"Out of Order"+NORM+" on them except the matinee lever",
	"holes",
	"This is where the ticket seller places your ticket for you to grab upon purchase",
	"chairs",
	"These supply a place for the ticket seller to sit during his long night of work",
	"dispenser",
	"This is where the tickets are dispensed from when the seller pulls one of the\n"+
	"several levers",
	"bell",
	"The bell is out of order, but the seller is already ready to\n"+
	"assist you",
	"matinee lever",
	"This is the only working lever out of them all.\n"+
	"Luckily it's the one you need!",
	});

dest_dir =
({
	"/players/chip/myworkroom.c",     "return",
	});

}
string *names;

init(){
  ::init();
  add_action("cmd_purchase","purchase");
}

cmd_purchase(str){
  if(!str){
    notify_fail("Purchase what?\n");
    return 0;
  }
  if(str != "ticket"){
    notify_fail("You may only purchase a ticket.\n");
    return 0;
  }
  if(!names) names = ({ });
  if(member_array(this_player()->query_real_name(), names) == -1)
  {
    if(this_player()->query_money() < 10000){
      write("You don't have enough money...get a job!\n");
      return 1;
    }
    this_player()->add_money(-10000);
    names += ({ this_player()->query_real_name() });
  }
  else
  {
    write("You already have purchased a ticket...\n");
  }
  this_player()->move_player("into the movies#/players/chip/room/movies/room4.c");
  return 1;
}
