#include <std.h>

#undef EXTRA_INIT
#define EXTRA_INIT  add_action("register", "register");

ONE_EXIT("room/church", "west",
         "The clinic",
         "This is an outpatient clinic, for adventurers who find themselves with\n" +
         "minor problems.  This clinic can treat problems such as your not being\n" +
         "able to fight, not being able to carry as much as you should, and\n" +
         "similar inconveniences.  If you have one of these problems, just type\n" +
         "'register' and the problem should go away.\n", 1)

register() {
    if(call_other(this_player(),"query_ghost")) {
       write("You are beyond the power of the clinic to help.\n" +
             "You need to deal with your maker.\n");
       return 1;
    }
    call_other(this_player(),"reset",1);
    this_player()->recalc_quest();
    return 1;
}
