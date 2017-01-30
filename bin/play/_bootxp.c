#include <ansi.h>

int cmd_bootxp()
{
  int     c;
  
  c = (int) "/obj/exp_store.c"->query_player_exp( (string) this_player()->query_name() );
  if( c < 1 ) {
    write("You haven't earned any experience this boot cycle.\n");
    return 1;
  }
  
  write("You have earned "+HIW+comma_number(c)+NORM+" xp this reboot.\n");
  write("Visit Cosmo's Apartment Building or the HUD to see the Top Scores!\n");
  return 1;
}
