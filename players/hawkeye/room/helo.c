

#include "std.h"
reset(arg){
    if(!arg){
    set_light(1);
    }
}
 init()
 {
    add_action("exit_church","church");
    add_action("exit_west","west");
/* Pavlik's area no longer exists.
    add_action("exit_pavlik","pavlik");
*/
    add_action("exit_hotel","hotel");
    add_action("exit_pub","pub");
    add_action("exit_lockers", "lockers");
    add_action("exit_shop","shop");
 }

 short() {
  return"4077th Helo Pad";
 }
long(str){
   write("You are at the Helicoptor Pad of this particular M*A*S*H camp\n" +
       "To go to your destination type the appropriate command!\n" +
     "Church, Hotel, Pub, Shop, Lockers, West\n");
}

exit_pavlik(){
    call_other(this_player(),"move_player","pavlik#room/eastroad2.c");
    return 1;
 }

  exit_lockers() {
    call_other(this_player(), "move_player","lockers#/players/catwoman/tl.c");
  return 1;
}
 exit_church(){
 call_other(this_player(),"move_player","church#room/church");
    return 1;
 }

exit_west(){
    call_other(this_player(),"move_player","west#players/hawkeye/room/rd4.c");

    return 1;
}
exit_hotel(){
    call_other(this_player(),"move_player","hotel.c#players/boltar/hotel/hotel.c");
    return 1;
}
exit_pub(){
    call_other(this_player(),"move_player","pub#players/hawkeye/room/rose.c");
    return 1;
}

exit_shop(){
   call_other(this_player(),"move_player","shop#players/hawkeye/room/bshop");
    return 1;
}
