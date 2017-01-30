#include <security.h>

#define MIN 60
#define HOUR 3600
#define DAY 86400
#define WEEK 604800

#define WEEKLY_MAX 250000

#define ADV_GUILD "/room/adv_guild"
#define EXLV_GUILD "/room/exlv_guild"

int sc2() {
  string header;
  int week_start, req_exp, weekly_exp, weekly_streak, weekly_streak_max;
  int diff, hours, mins, days;

  week_start = (int) this_player()->query_lr_period_start();
  req_exp   = (int) this_player()->query_lr_required_exp();
  weekly_exp = (int) this_player()->query_lr_exp();
  weekly_streak = (int) this_player()->query_lr_streak();
  weekly_streak_max = (int) this_player()->query_lr_streak_max();
  
  header = implode(explode(pad("",40,'='),""),"-")+"\n";
  write( header );
  
  write("Login weekly rewards start: " + ctime(week_start) + "\n" );
  diff = week_start + WEEK - time();
  days = diff / DAY;
  diff -= days * DAY;
  hours = diff / HOUR;
  diff -= hours * HOUR;
  mins = diff / MIN;
  diff -= mins * MIN;
  write( "You have " +( days ? days+" days, " : "") + ( hours ? hours+" hours, " : "") + ( mins ? mins+ " minutes, " : "") +diff+" seconds before the current week ends.\n\n");
  
  diff = req_exp - weekly_exp;
  if( diff < 0 )
      diff = 0;
    
  write( pad("Weekly Exp required : " + pad( comma_number( req_exp ), -12), -40) + "\n" );
  write( pad("  Weekly Exp Earned : " + pad( comma_number( weekly_exp ), -12), -40) + "\n" );
  write( pad("  Exp Still Needed  : " + pad( comma_number( diff ), -12), -40) + "\n\n");
  
  write( "Avail Points: " + pad(comma_number( this_player()->query_nrpoints() ), -9) + 
    pad( "Current Streak: ",-35 ) + weekly_streak + "\n" );
  write( "Total Points: " + pad(comma_number( this_player()->query_totalpoints() ), -9) + 
     pad( "Longest Streak: ",-35 ) + weekly_streak_max + "\n" );

   write( header );
   return 1;
}

status cmd_lbonus(string str) {
  string header;
  int current_week;
  int weekly_exp;
  int weekly_streak;
  int weekly_streak_max;
  int weekly_streak_status;
  int diff, hours, mins, days, exp;
  
  if( str ) {
    return sc2();
  }
  
  if( !restore_object( "players/dragnar/wiztool/login_bonus") ) {
    notify_fail("Unable to restore login bonus.\n");
    return 0;
  }
  
  if( !current_week ) {
    current_week = time();
    write("Weekly streak initialized");
    weekly_streak_status = 1;
  }
  
  header = implode(explode(pad("",40,'='),""),"-")+"\n";
  write( header );
  
  /** write("Current time      : " + ctime() + "\n" ); **/
  write("Login weekly rewards start: " + ctime(current_week) + "\n" );
  diff = current_week + WEEK - time();
  days = diff / DAY;
  diff -= days * DAY;
  hours = diff / HOUR;
  diff -= hours * HOUR;
  mins = diff / MIN;
  diff -= mins * MIN;
  write( "You have " +( days ? days+" days, " : "") + ( hours ? hours+" hours, " : "") + ( mins ? mins+ " minutes, " : "") +diff+" seconds before the current week ends.\n\n");
  
  exp = (int) POINTSD->get_exp_required( find_player("darude") );
  /*********************************************
   ** Need to store weekly exp amount in case player dies
   *********************************************/
  diff = exp - weekly_exp;
  if( diff < 0 )
      diff = 0;
    
  write( pad("Weekly Exp required : " + pad( comma_number( exp ), -12), -40) + "\n" );
  write( pad("  Weekly Exp Earned : " + pad( comma_number( weekly_exp ), -12), -40) + "\n" );
  write( pad("  Exp Still Needed  : " + pad( comma_number( diff ), -12), -40) + "\n\n");
  
  write( "Avail Points: " + pad(comma_number( this_player()->query_nrpoints() ), -9) + 
    pad( "Current Streak: ",-35 ) + weekly_streak + "\n" );
  write( "Total Points: " + pad(comma_number( this_player()->query_totalpoints() ), -9) + 
     pad( "Longest Streak: ",-35 ) + weekly_streak_max + "\n" );

#ifdef DEBUG
  write("Current week      : " + current_week + " " + ctime( current_week) + "\n");
  write("Start of next week: " + (current_week+WEEK) + " " + ctime( current_week+WEEK) + "\n");
#endif  
  if( weekly_streak_status && time() > current_week + WEEK ) {
    /** Break of the streak **/
    if( weekly_streak > weekly_streak_max )
      weekly_streak_max = weekly_streak;
    weekly_streak = 0;
    current_week = time();
    write("Login weekly start reset to: " + ctime(current_week) + "\n" );
  }
  
   save_object( "players/dragnar/wiztool/login_bonus" );
   write( header );
   return 1; }
