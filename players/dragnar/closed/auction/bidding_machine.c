#include <ansi.h>

/******************************************************************************
 * Program: bidding_machine.c
 * Path: /players/dragnar/closed/auction
 * Type: Object
 * Created: April 3rd 2014 by Dragnar
 *
 * Purpose: This object enables an auction to take place. Senior level wizards
 *          have the ability to start and end the bidding. During the open
 *          auction players can place bids. When a bid is placed it removes
 *          gold from the players bank balance. The top bids will be top
 *          MAX_BIDS at the time a senior closes the bidding. Players that
 *          do not have a winning bid are able to reclaim their bids since
 *          they did not win.
 * History:
 *          04/03/2014 - Dragnar
 *            Created
 ******************************************************************************/
 
#define SAVE_PATH "players/dragnar/closed/auction/bidding_machine"
#define RULES "/players/dragnar/closed/auction/bidding_rules.txt"
#define MAX_BIDS 3
#define TESTCHAR_D "/obj/user/testchar-d"
#define LANDD "/players/earwax/housing/land_daemon.c"

mixed *bidding;
string *winners;
int BiddingOpen;

id(string str) {
   return str == "machine" || str == "bidding machine" || str == "real estate bidding machine";
}


init() {
   add_action("read","read");
   add_action("bid","bid");
   add_action("reclaim","reclaim");
    
   if( this_player()->query_level() > 99 ) {
      add_action("view","view");
      add_action("openbidding","openbidding");
      add_action("closebidding", "closebidding");
   }
}

reset(arg){
  if(arg) return;
  restore_object( SAVE_PATH );
}

short() { 
  return "Real Estate Bidding Machine";
}

long() {
write("A rectangular machine that looks like a big computer. It is around\n\
3 feet tall and has a black metallic case with fans built into it.\n\
The case has been bolted to the floor and you see no way to open\n\
it or move it. A display terminal is mounted on the top of the\n\
machine that is active. You could could "+HIG+"read"+NORM+" it if desired.\n");
}

read(string str) {
  int i;
  
  if( !str || (str != "display" && str != "terminal" && str != "rules" ) )
    return 0;

  if( str == "rules" ) {
    cat( RULES );
    return 1;
  }
  write("A new housing development is under way in Nirvana. All players have\n\
a chance to get in on this opportunity. The new development will be\n\
in the recently added Walking Dead area. To make it fair, any player\n\
will be able to place a bid for a chance at obtaining one of the\n\
houses. The top bidders will get a chance to pick the location of\n\
their house as well as the size. NOTE: The bid is for winning the\n\
chance to buy the house. The bid WILL NOT be put toward the cost of\n\
the house itself. The top bidder will get first choice on location\n\
and size, then the next top bidder and so on.\n\n");
  write("You can do the following commands:\n\
bid                 -- Will show your current bid if it exists.\n\
bid <amount>        -- Place a new bid, or raise current bid.\n\
reclaim             -- Reclaim non-winning bids after auction closes\n\
"+HIY+"read rules"+NORM+"          -- Read auction rules\n\n");

  write("Bidding is currently: " + (BiddingOpen ? GRN+"OPEN" : RED+"Closed") +NORM+"\n");
  
  if( winners && !BiddingOpen ) {
    write( "The players with winning bids in the auction are:\n");
    for( i=0; i < sizeof(winners); i++ )
      write( "\t"+ winners[i] + "\n");
  }

  if(this_player()->query_level() > 99 ) 
    write("As a senior, you can 'view bids', 'openbidding' and 'closebidding'\n");
    
  return 1;
}

view(string str) {
  int i;
  if( !str || str != "bids" ) return 0;
  if( !bidding ) {
    write("There are no bids registered yet.\n");
    return 1;
  }
  
  for( i=0; i < sizeof(bidding); i++ ) {
    write( pad(bidding[i][0], 20) + bidding[i][1] + "\n");
  }
  return 1;

}

chan_msg(str) {
   int index;
   object *people;
   people = users();
  for (index = 0; index < sizeof(people); index++)
   if (people[index]->on_channel("announce"))
      tell_object(people[index], str);
  return 1;
}

openbidding() {
  write("You open the auction for bidding!\n");
  winners = 0;
  BiddingOpen = 1;
  chan_msg( this_player()->query_name() + " announces: The real estate auction is now OPEN! Let the bidding begin.\n");
  log_file("AUCTION", ctime() + " " +this_player()->query_real_name()+" opened the auction for bidding.\n");
  return 1;
}

set_winners() {
  int i;
  for( i=0; i < sizeof(bidding) && i < MAX_BIDS; i++ ) {
    log_file("AUCTION", "       " +bidding[i][0]+" has a winning bid of "+bidding[i][0]+" in the auction.\n");
    if( i == 0 )
      winners = ({ bidding[i][0] });
    else
      winners += ({ bidding[i][0] });
  }
  save_object( SAVE_PATH );
  
}

closebidding() {
  int i;
  write("You close the auction for bidding!\n");
  BiddingOpen = 0;
  set_winners();
  chan_msg( this_player()->query_name() + " announces: The real estate auction is now Closed.\n");
  write("The top bidder in the auction is "+winners[0]+".\n");
  log_file("AUCTION", ctime() + " " +this_player()->query_real_name()+" closed the auction for bidding.\n");
  return 1;
}

int bid_sort(mixed *a, mixed *b) {
  return ( a[1]  <  b[1] );
}

int is_member( mixed *bidding, string str ) {
  int i, idx;
  
  idx = -1;
  
  if(!bidding)
    return idx;
  
  for( i=0; i < sizeof(bidding); i++ ) {
    idx = member( bidding[i], str );
    if(idx >= 0 )
      return i;
  }
  return idx;
}

reclaim() {
  int i, idx;
  string pname;
  
  if( !bidding ) {
    write("Currently there are no bids for this auction.\n");
    return 1;
  }
  
  if( BiddingOpen ) {
    write("You must wait until the auction is closed before reclaiming bids.\n");
    return 1;
  }
  
  pname = this_player()->query_real_name();
  
  if( member( winners, pname ) >= 0 ) {
    write("As a winner of the auction, you are unable to reclaim your bid.\n");
    return 1;
  }
  
  idx = is_member( bidding, pname ) ;
  if( !bidding || idx < 0 ) {
    write("You have no bids that you can reclaim.\n");
    return 1;
  }
  
  if( bidding[idx][1] == 0 ) {
    write("Your bid has already been reclaimed.\n");
    return 1;
  }
  
  log_file("AUCTION", ctime() + " " +this_player()->query_real_name()+" reclaimed their bid of "+bidding[idx][1]+".\n");
  write("Your bid of "+bidding[idx][1]+" is deposited back into your account.\n");
  this_player()->add_bank_balance( bidding[idx][1] );
  bidding[idx][1] = 0;
  save_object( SAVE_PATH );
  return 1;
}

check_balance( object player, int amount ) {
  if(!player) return 0;
  
  if(player->query_bank_balance() < amount ) {
    write("Sorry you do not have the funds to cover that bid.\n");
    return 0;
  }
  
  log_file("AUCTION", ctime() + " " +this_player()->query_real_name()+" transferred "+amount+" coins to their bid.\n");
  player->add_bank_balance( -amount );
  write("You register your bid.\n");
  return 1;
}

bid( string str ) {
  int idx, amount, bank_amount;
  string pname, junk;
  
  pname = this_player()->query_real_name();
  
  if( !str ) {
    if( !bidding ) {
      write("You have no registered bids.\n");
      return 1;
    }
    idx = is_member( bidding, pname );
    if( idx >= 0 ) {
      write("Your current bid is "+bidding[idx][1]+".\n");
      return 1;
    }
    else {
      write("You have no registered bids.\n");
      return 1;
    }
    return 0;
  }
    
  if( !BiddingOpen ) {
    write("Bidding is currently not open.\n");
    return 1;
  }
  
  if( this_player()->query_level() > 19 ) {
    write("Build your own house!\n");
    return 1;
  }
  
  if( junk = (string) TESTCHAR_D->query_owner( pname ) ) {
    write("Test chars don't get to place bids.\n");
    return 1;
  }
  
  if( LANDD->query_land_owner( pname ) ) {
    write("This auction is only for players who don't already own land.\n");
    return 1;
  }
  
  if( sscanf(str, "%d", amount ) != 1 ) {
    write("You must bid a whole number amount.\n");
    return 1;
  }
  
  if( amount < 100000 ) {
    write("The minimum bid is 100,000.\n");
    return 1;
  }

  if( !bidding && check_balance( this_player(), amount ) ) {
    bidding = ({ ({pname, amount}) });
  }
  else {
    idx = is_member( bidding, pname );
    if( idx > -1 ) {
      if( amount <= bidding[idx][1] ) {
        write("If you wish to bid again, you must raise your current bid of: "+bidding[idx][1]+".\n");
        return 1;
      }
      if( check_balance( this_player(), amount - bidding[idx][1] ) )
        bidding[idx][1] = amount;
    }
    else
      if( check_balance( this_player(), amount ) )    
        bidding += ({ ({pname, amount}) });
      

  }
  
  if( bidding ) {
    bidding = sort_array(bidding, "bid_sort", this_object());  
    save_object( SAVE_PATH );
  }
  return 1;
}

get() { return 0; }
drop() { return 1; }
query_weight() { return 10000; }
query_value() { return 0; }
