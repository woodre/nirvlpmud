#include <std.h>

#undef EXTRA_INIT
#define EXTRA_INIT  add_action("signin", "signin");

ONE_EXIT("players/boltar/sprooms/clinic/sbank", "up",
   "The clinic",
   "This is an outpatient clinic, for adventurers who find themselves with\n" +
       "an unwanted pregnancy. For the small fee of 1000 coins, the clinic's staff\n"+
       "will magically warp time and change the past, so that the patient will have\n"+
       "never become pregnant. Just type 'signin' and all will be undone.\n",1)

signin() {
   int tmp;
    if(call_other(this_player(),"query_ghost")) {
       write("You are beyond the power of the clinic to help.\n" +
             "You need to deal with your maker.\n");
       return 1;
    }
     if(this_player()->query_money() < 1000) {
      write("You do not have enough money.\n");
      return 1;
     }
     if(!this_player()->query_pregnancy()){
      write("You are not pregnant.\n");
      return 1;
     }
     tmp = this_player()->query_age()-this_player()->query_pregnancy();
     if(tmp > 6500) {
     write("You are too far along, we cannot move that far into the past.\n");
     return 1;
     }
     this_player()->add_money(-1000);
     if(present("fertility",this_player())) {
       write("The operation fails.\n");
       return 1;
     }
     this_player()->clear_pregnancy();
    return 1;
}
