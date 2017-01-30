int lock;
object driver;

void reset(int arg){ if(arg) return; }

id(str) {return str == "boat"; }

short(){ return "A Boat"; }

long() { 
   if(environment(this_player()) == this_object()){
      inside_long();
   }
   else {
      write("This is a Boat, maybe you can 'get on' it.\n");
      if(lock == 0){
         write("The keys are in it!\n");
      }
      else
         write("There seems to be no keys.\n");
   }
}

inside_long(){
   if(this_player() == driver){
      write("You are seated at the controls of the boat.\n");
      write("To drive, 'dr <direction>'\n");
      write("To look at where you are, 'window'\n");
      write("To honk the horn, 'honk <target>'\n");
      write("To lock/unlock the boat, 'lock'\n");
      write("To get up from the controls, 'stand'\n");
   }
   else {
      write("You are a passenger on the boat.\n");
      write("There is a magical feel about the vehicle, and a technological\n");
      write("sophistication about it as well.  You can look out the window\n");
      write("by the command, 'window'.  To leave, you can 'evacuate'.\n");
      if(driver){
         write("Driver seat (occupied by "+driver->query_name()+")\n");
      }
      else {
         write("Driver seat (unoccupied)\n");
      }
   }
   
}

realm(){ return environment(this_object())->realm(); }
init() {
   add_action("get","get");
   add_action("leave", "evacuate");
   add_action("lock", "lock");
   add_action("sell", "sell");
   add_action("sit","sit");
   add_action("honk", "honk");
   add_action("stand","stand");
   add_action("drive","drive");
   add_action("drive","dr");
   add_action("window","window");
}

sell(str){
   if(str == "boat"){
      write("Sorry, but I already thought of that too.\n");
      return 1;
   }
}
honk(str){
   object target;
   target = present(str, environment(this_object()));
   write("You honk the horn at "+str+", deafning it's ears!\n");
   target->hit_player(10);
   tell_object(target, "You go temporarily deaf from the boat horn, man that hurts!\n");
   return 1;
}

lock(){
   if(this_player()->query_name() !="Rumplemintz"){
      write("You don't own this boat.\n");
      return 1;
   }
   if(lock == 0){
      lock = 1;
      write("You lock the boat.\n");
      tell_room(this_object(), "The boat is now locked.\n");
      return 1;
   }
   if(lock == 1){
      lock = 0;
      write("You unlock the boat.\n");
      tell_room(this_object(), "The boat is now unlocked.\n");
      return 1;
   }
}
get(str) {
   if(str == "on boat"){
      if(lock == 1){
         write("The boat is locked, and won't let you get on.\n");
         return 1;
      }
      write("You board the boat.\n");
      move_object(this_player(), this_object());
      say(capitalize(this_player()->query_name())+" climbs on the boat.\n");
      return 1;
   }
}

leave(str) {
   if(this_player() == driver){
      write("You ought to get out of the driver seat first.\n");
      return 1;
   }
   if(lock == 1){
      write("The boat is locked.\n");
      return 1;
   }
   write("You get off the boat.\n");
   say(capitalize(this_player()->query_name())+" gets off the boat.\n");
   move_object(this_player(), environment(this_object()));
   tell_room(environment(this_object()),
      capitalize(this_player()->query_name())+" climbs off the boat.\n");
   return 1;
}

sit(){
   if(driver){
      write("Somebody is already sitting there.\n");
      return 1;
   }
   if(!present(this_player(), this_object())){
      write("What?\n");
      return 1;
   }
   if(!present(this_player())){
      write("What?\n");
      return 1;
   }
   if(!present("boat_license", this_player())){
      write("You don't have a license to drive the boat!\n");
      return 1;
   }
   driver = this_player();
   write("You sit down at the controls in the driver's seat.\n");
   say(this_player()->query_name()+" sits in the dirver's seat.\n");
   return 1;
}

stand(){
   if(this_player() != driver){
      write("You are not sitting.\n");
      return 1;
   }
   driver = 0;
   write("You get out of the driver's seat.\n");
   say(capitalize(this_player()->query_name())+" gets out of the driver's seat.\n");
   return 1;
}

drive(str) {
   object dest, old_room;
   string destlong;
   old_room = environment(this_player());
   if(this_player() != driver){
      write("You must sit in the driver's seat to drive the boat.\n");
      return 1;
   }
   if(!str) {
      write("Drive where?\n");
      return 1;
   }
   move_object(this_player(), environment(this_object()));
   tell_room(old_room, "The boat motors away, making rude noises upon it's exit.\n");
   command(str, this_player());
   dest = environment(this_player());
   move_object(this_object(), dest);
   tell_room(dest, this_player()->query_name()+" cruises into the room on a Boat!\n");
   move_object(this_player(), this_object());
   return 1;
}

window(){
   move_object(this_player(), environment(this_object()));
   command("look", this_player());
   move_object(this_player(), this_object());
   return 1;
}
