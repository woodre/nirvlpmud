#include "../std.h"
int x;
object blob;
main(str) {
   if(!str) {
      write("Petrify who?\n");
      return 1; }
   blob = present(str,ENV(TP));
   tell_room(ENV(TP),BOLD+BLK+TPN+" points at "+CAP(str)+".\n"+NORM);
   tell_object(blob,"You suddenly lose the ability to move.\n");
   MO(CO("/players/vertebraker/obj/petrify"),blob);
   call_out("call",3);
   return 1; }

call() {
   x+= 1;
   if(blob && ENV(blob)) {
      if(x == 1) {
         tell_room(ENV(blob),BOLD+BLK+blob->QN+"'s legs turn to stone!\n"+NORM);
         present("petrify_obj",blob)->set_petrify(1);
         call_out("call",3); return 1; }
      if(x == 2) {
         tell_room(ENV(blob),BOLD+BLK+blob->QN+"'s torso turns into a hard chunk of rock!\n"+NORM);
         present("petrify_obj",blob)->set_petrify(2);
         call_out("call",3); return 1; }
      if(x == 3) {
         tell_room(ENV(blob),BOLD+BLK+blob->QN+" turns ENTIRELY to STONE!\n"+NORM);
         present("petrify_obj",blob)->set_petrify(3);
         x = 0;
         return 1; }
   }
   return 1; }
