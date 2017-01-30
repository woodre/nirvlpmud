/* Room of portals for the assassins guild. */
#include "std.h"
reset(arg) {
   if(!arg) set_light(1);
}
init() {
   if(!present("license", this_player()) &&
      this_player()->query_level() < 21) {
      write("You're not an assassin, begone!\n");
      move_object(this_player(), "room/church");
      return 1;
         }
   add_action("enter_portals","enter");
}
enter_portals(str) {

   /* Portals are as follows: */
   /* blue -> church */
   /* red  -> shop   */
   /* white -> hotel */
   /* black -> well  */
   /* grey -> blackadders  */

   if(str == "blue") {
      write("You enter the blue portal and teleport to a new place.\n");
      say(this_player()->query_name()+" entered the blue portal.\n");
      move_object(this_player(), "room/church");
      return 1;
          }
   if(str == "red") {
      write("You enter the red portal and teleport to a new place.\n");
      say(this_player()->query_name()+" entered the red portal.\n");
      move_object(this_player(), "room/shop");
      return 1;
          }
   if(str == "white") {
      write("You enter the white portal and teleport to a new place.\n");
      say(this_player()->query_name()+" entered the white portal.\n");
    move_object(this_player(), "players/boltar/hotel/hotel");
    return 1;
        }
   if(str == "black") {
      write("You enter the black portal and teleport to a new place.\n");
      say(this_player()->query_name()+" entered the black portal.\n");
      move_object(this_player(), "room/well");
      return 1;
          }
   if(str == "grey") {
      write("You enter the grey portal.\n");
      say(this_player()->query_name()+" entered the grey portal.\n");
      move_object(this_player(), "players/blackadder/entrance");
      return 1;
      }
   if(str == "guild") {
      write("You leave back into the guild.\n");
      say(this_player()->query_name()+" enters the guild.\n");
      move_object(this_player(), "players/deathmonger/ASSASSIN/cenguild");
      return 1;
      }
}
   short() { return "Hall of Worlds"; }
   long() {
      write("You enter into a large cavern in the deeps of the earth.\n");
   write("Other than the soft glow from some oddly shaped portals the\n");
   write("cavern is dark. You turn your attention to the portals and find\n");
   write("each one is a different hue. One is white, red, blue, black, \n");
   write("and grey. They seem to be attuned to your essence.\n");
   write("\n    Usage: enter {color} or guild \n");
}
