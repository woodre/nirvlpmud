inherit "obj/container";

int c,lid;

reset(arg) {
    ::reset(arg);
    if (!arg) {
        set_long("A green washing machine. It is a full size toploader with\n"+
                 "one dial and lid. You can set the dial.\n");
	set_short("A Washing Machine");
	set_name("washing machine");
	set_weight(300);
	set_max_weight(6);
	set_value(12);
        set_can_open(1);
        ::open("washing machine");
    }
}
init() { 
 add_action("set","set");
 add_action("sit","sit");
 add_action("quit","quit");
 add_action("open","open");
 add_action("close","close");
 add_action("up","up");
}
open(arg) {
  if(arg != "washing machine" && arg != "washing machine lid" && arg != "lid")
    return 0;
  if(!lid) { write("It's already open.\n"); return 1; }
  if(c) { write("You can't open the machine when it's running.\n"); return 1; }
  say(this_player()->query_name()+" opens the washing machine's lid.\n");
  write("You open the lid.\n");
  lid = 0;
  ::open("washing machine");
  return 1;
}
close(arg) {
  if(arg != "washing machine" && arg != "washing machine lid" && arg != "lid")
    return 0;
  if(lid)  { write("It's already closed.\n"); return 1; }
  say(this_player()->query_name()+" closes the washing machine's lid.\n");
  write("You close the lid.\n");
  lid = 1;
  ::close("washing machine");
  return 1;
}
set(arg) {
 if(arg != "washing machine" && arg != "dial") return 0;
  if(!lid) { write("You need to close the lid.\n"); return 1;}
  if(c) { write("It's already running.\n"); return 1;}
 say(this_player()->query_name()+" sets the dial on the washing machine.\n");
 say("The washing machine shakes and makes noise.\n");
 write("You set the dial.\n");
 write("The washing machine shakes and makes noise.\n");
 c = 0;
 set_short("A Washing Machine <RUNNING>\n");
 call_out("do_cycle",1);
  return 1;
}
do_cycle() {
 c += 1;
 if(c == 1) { say("You hear water rushing inside the machine.\n");
              tell_room(this_object(),"You're getting wet.\n"); }
 if(c == 2) { say("The washing machine makes a wirring sound.\n");
              tell_room(this_object(),"You're spinning around.\n"); }
 if(c == 3) { say("The washing machine is aggitating the load.\n");
              tell_room(this_object(),"You are being shaken back and forth.\n"); }
 if(c == 4) { say("The washing machine is spewing dirty, soapy water on the ground.\n");
            tell_room(this_object(),"The water level is dropping.\n"); }
 if(c == 5) { say("You hear water rushing inside the machine.\n");
              tell_room(this_object(),"The water level is rising.\n"); }
 if(c == 6) { say("The washing machine is aggitating the load.\n");
              tell_room(this_object(),"You are being shaken back and forth.\n");}
 if(c == 7) { say("The washing machine is spewing water out on the ground.\n");
              tell_room(this_object(),"The water level is dropping.\n"); }
 if(c == 8) { say("The washing machine spining sound is increasing in speed.\n");
              tell_room(this_object(),"You are being spun at a high rate of speed.\n"); }
 if(c == 9) { say("The washing machine spining noise adds a thunk on each rotation.\n");
             tell_room(this_object(),"The spinning worsens and becomes unbalanced.\n"); }
 if(c == 10) { say("The washing machine goes thunk-thunk-thunk-thunk.\n");
             tell_room(this_object(),"Your head is being wacked against the side with each rotation.\n"); }
 if(c == 11) { say("The washing machine thunks and wheezes to a stop.\n");
               tell_room(this_object(),"The spinning slows and stops.\n"); }
 if(c < 11)
 call_out("do_cycle",30);
 if(c == 11) { c = 0; set_short("A Washing Machine"); }
}
up() {
 if(environment(this_player()) != this_object()) return 0;
 if(lid) { 
   write("You find the lid is closed and latched.\n");
   write("It can only be opened from the outside.\n");
   tell_room(environment(this_object()),"There is some pounding from the inside of the machine.\n");
   return 1;
  }
  move_object(this_player(),environment(this_object()));
  say(this_player()->query_name()+" pops out of the washing machine.\n");
  write("You pop out of the washing machine.\n");
  return 1;
}
realm() {
 if(lid)
 return "NT"; }
quit() {
  if(environment(this_player()) != this_object()) return 0;
 if(!lid) return 0;
 write("You're trapped here buddy.\n");
  return 1;
}
sit(arg) {
  if(arg != "on washing machine" && arg != "on washing machine lid" && arg != "on lid")
    return 0;
  if(!lid) { write("You fall in! The lid was open!\n");
    say(this_player()->query_name()+" tries to sit on the washing machine and falls in.\n");
    move_object(this_player(),this_object());
    return 1;
  }
  write("You sit on top of the washer.\n");
  say(this_player()->query_name()+" sits on top of the washing machine.\n");
  return 1;
 }
