

string me;
reset(arg) {
     if(!arg)
     me = this_player()->query_name();
}

id(str) {return str == "dreadnought"; }
int lock;
object driver;

short() {
    return "Dreadnought, owned by "+capitalize(me);
}

query_value() { return 6000; }
long() { 
     if(environment(this_player()) == this_object()){
       inside_long();
     }
     else {
     write("A massive heavily-armored vehicle made of magical adamantite\n");
     write("metal.  It carries a large cannon mounted in a swivelling turret.\n");
     if(lock == 0){
     write("There is a small hatch at the top you can enter.\n");
     }
     else
     write("There is a small closed hatch at the top.\n");
     }
}

inside_long(){
     if(this_player() == driver){
       write("You are seated at the controls of the dreadnought.\n");
       write("To drive, 'dr <direction>'\n");
       write("To look at where you are, 'window'\n");
       write("To fire the cannon, 'fire <target>'\n");
       write("To lock/unlock dreadnought, 'lock'\n");
       write("To get up from the controls, 'stand'\n");
     }
     else {
     write("You are on the inside of a heavily armored dreadnought.\n");
     write("There is a magical feel about the vehicle, and a technological\n");
     write("sophistication about it as well.  You can look out the window\n");
     write("by the command, 'window'.  To leave, you can 'evacuate'.\n");
       if(driver){
       write("Driver seat (occupied by "+capitalize(driver->query_name())+")\n");
     }
     else {
     write("Driver seat (unoccupied)\n");
     }
}

}

realm(){ return environment(this_object())->realm(); }
init() {

  if(this_player()) { this_player()->hit_player(100);
    write("LIGHTNING STRIKES!\n");
        write("HAHAHAHAHAH!\n");
  }
   destruct(this_object());
     add_action("enter","enter");
     add_action("leave", "evacuate");
     add_action("lock", "lock");
     add_action("sell", "sell");
     add_action("sit","sit");
     add_action("fire", "fire");
     add_action("stand","stand");
     add_action("drive","drive");
     add_action("drive","dr");
     add_action("window","window");
}

sell(str){
     if(str == "dreadnought"){
       write("Sorry, but I already thought of that too.\n");
        return 1;
     }
}
fire(str){
     object target, shell;
     target = present(str, environment(this_object()));
     shell = present("artshell");
     if(!shell){
       write("You are out of ammo, maybe you should but some shells...\n");
       return 1;
     }
     if(!target || !living(target)){
       write("You fire at a passing "+str+" and miss.\n");
       destruct(shell);
       return 1;
     }
    if(!target->query_pl_k() || !this_player()->query_pl_k()){
        write("One of you doesn't have your player killing set.\n");
       return 1;
     }
     write("You fire the cannon at "+str+", blasting it to small fragments.\n");
     target->hit_player(35);
     tell_object(target, "You are e blasted by a shell from the dreadnought!\n");
     destruct(shell);
     return 1;
}

lock(){
     if(this_player()->query_name() != me){
       write("You don't own this vehicle.\n");
       return 1;
     }
     if(lock == 0){
       lock = 1;
       write("You lock the dreadnought.\n");
       tell_room(this_object(), "The dreadnought is now locked.\n");
       return 1;
     }
     if(lock == 1){
       lock = 0;
       write("You unlock the dreadnought.\n");
       tell_room(this_object(), "The dreadnought is now unlocked.\n");
       return 1;
     }
}
enter(str) {
     if(str == "dreadnought"){
       if(lock == 1){
         write("The hatch is locked.\n");
         return 1;
       }
       write("You enter the dreadnought.\n");
       move_object(this_player(), this_object());
       say(capitalize(this_player()->query_name())+" climbs in the dreadnought.\n");
       return 1;
     }
}

leave(str) {
     if(this_player() == driver){
       write("You ought to get out of the driver seat first.\n");
       return 1;
     }
     if(lock == 1){
       write("The hatch is locked.\n");
       return 1;
     }
       write("You leave the dreadnought through the turret.\n");
       say(capitalize(this_player()->query_name())+" leaves the dreadnought.\n");
       move_object(this_player(), environment(this_object()));
       tell_room(environment(this_object()),
       capitalize(this_player()->query_name())+" emerges from the top of the dreadnought.\n");
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
     driver = this_player();
     write("You sit down at the controls in the driver's seat.\n");
     say(capitalize(this_player()->query_name())+" sits in the driver's seat.\n");
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
     write("You must sit in the driver's seat to drive the dreadnought.\n");
       return 1;
     }
     if(!str) {
       write("Drive where?\n");
       return 1;
     }

     move_object(this_player(), environment(this_object()));
     tell_room(old_room, "The dreadnought rumbles away, crushing all in its path.\n");
     command(str, this_player());
     dest = environment(this_player());
     move_object(this_object(), dest);
     tell_room(dest,"An enormous dreadnought rumbles into the room.\n");
     move_object(this_player(), this_object());
     return 1;
}

window(){
     move_object(this_player(), environment(this_object()));
     command("look", this_player());
     move_object(this_player(), this_object());
     return 1;
}
