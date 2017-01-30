inherit "obj/container";

int c,lid;
object table,abducted;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_long("This is a classic 1950s silver disc shaped flying saucer.\n"+
             "(Think of a small version of the one from The day the\n"+
             "earth stood still.) There is a large window in the front and\n"+
             "three chairs in a triangle shape. (think cylons in the\n"+
             "original battlestar galatica series) There is a medical\n"+
             "medical table in the back of the ship and a hatch.\n");
	set_short("A silver colored flying disc");
	set_name("flying disc");
	set_weight(30000);
	set_max_weight(50);
	set_value(12);
        set_can_open(1);
        lid = 1;
        table=clone_object("/players/boltar/things/ufo_table");
        move_object(table,this_object());
/*        ::open("washing machine"); */
    }
  enable_commands();
  add_crew();
}
long() {
 if(this_player() && environment(this_player()) != this_object()) {
   ::long(); return 1;
 }
 write("This flying disk is rather small, everything is designed for \n"+
       "creatures lacking elbows and knees. Even the controls. It would \n"+
       "not be possible for regular creatures to operate. The medical \n"+
       "section in back contains all sorts of strange looking tools. \n"+
       "The craft seems to take voice commands from the beano in their. \n"+
       "own language. But it is quite clear this craft is too small for \n"+
       "interstellar or intergalatic travel.\n");
 return 1;
}
init() { 
 add_action("set","set");
 add_action("quit","quit");
 add_action("open","open");
 add_action("close","close");
 add_action("out","out");
}
open(arg) {
  if(arg != "flying disc" && arg != "ufo" && arg != "hatch")
    return 0;
  if(!lid) { write("It's already open.\n"); return 1; }
  if(this_player()->query_name() != "Beano") { 
    write("You find your elbows prevent you from opening the hatch.\n");
    return 1;
  }
  say(this_player()->query_name()+" opens the flying disc's hatch.\n");
  write("You open the hatch.\n");
  lid = 0;
  ::open("flying disc");
  return 1;
}
close(arg) {
  if(arg != "flying disc" && arg != "ufo" && arg != "hatch")
    return 0;
  if(lid)  { write("It's already closed.\n"); return 1; }
  if(this_player()->query_name() != "Beano") { 
    write("You find your elbows prevent you from closing the hatch.\n");
    return 1;
  }  
  say(this_player()->query_name()+" closes the flying disc's hatch\n");
  write("You close the hatch.\n");
  lid = 1;
  ::close("flying disc");
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
do_anal_probe() {
 c += 1;
 if(c==1) { move_object(abducted,table);
   table->strapdown(abducted->query_real_name());
 }
 if(c == 1) { 
              tell_room(table,"You are strapped to the medical table.\n"); }
 if(c == 2) { 
              tell_room(table,"A beano hovers over you.\n"); }
 if(c == 3) { 
              tell_room(table,"The table flips over and opens up. You face the floor.\n"); }
 if(c == 4) { 
              tell_room(table,"You hear the beanos talking in beano to each other.\n"); }
 if(c == 5) { 
              tell_room(table,"The beanos are clanking equipment around.\n"); }
 if(c == 6) { 
              tell_room(table,"You are being probed by an energy beam!\n");}
 if(c == 7) { 
              tell_room(table,"You feel a cold metal object on your butt.\n"); }
 if(c == 8) { 
              tell_room(table,"OUCH! You scream but no sound comes out.\n"); }
 if(c == 9) { 
             tell_room(table,"The table resets, you are right side up.\n"); }
 if(c == 10) { 
             tell_room(table,"The straps release, you are dumped on the floor.\n");
             table->leave();}
 if(c == 11) { 
             tell_room(this_object(),"The beanos open the hatch and shove you out the door.\n"); 
             command("open hatch",present("beano",this_object()));
             command("out",abducted);
             command("close hatch",present("beano",this_object())); 
             }
 if(c < 11)
 call_out("do_anal_probe",10);
 if(c == 11) { c = 0; abducted = 0; }
}
out() {
 if(environment(this_player()) != this_object()) return 0;
 if(lid) { 
   write("You find the hatch is closed and latched.\n");
   write("It can only be opened by a beano or similiar creature without elbows.\n");
   tell_room(environment(this_object()),"There is some pounding from the inside of the flying disc.\n");
   return 1;
  }
  move_object(this_player(),environment(this_object()));
  say(this_player()->query_name()+" falls out of the flying disc"+
      " and crashes onto the ground.\n");
  write("You fall out of the flying disc and crash onto the ground.\n");
  return 1;
}
realm() {
 if(lid)
 return "NT"; 
}
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
random_move() {
    int n;
    n = random(12);
    if (n == 0)
        command("west");
    else if (n == 1)
        command("east");
    else if (n == 2)
        command("south");
    else if (n == 3)
        command("north");
    else if (n == 4)
        command("up");
    else if (n == 5)
        command("down");
    else if (n == 6)
        command("northwest");
    else if (n == 7)
        command("northeast");
    else if (n == 8)
        command("southeast");
    else if (n == 9)
        command("southwest");
    else if (n == 10)
        command("out");
    else if (n == 11)
        command("in");
}
move_player(dir_dest)
{
  string dir, current_room, dest, msgout, msgin;
  object ob;
  int is_light;
  
  if(!dir_dest)
    return 0;

  if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
    tell_object(this_object(), "Move to bad dir/dest\n");
    return;
  }
  current_room = dest;
  if (!msgout)
    msgout = "leaves";
    say("Flying Disc " + msgout + " " + dir + ".\n");
  is_light = set_light(0);
  if (is_light < 0)
    is_light = 0;
  move_object(this_object(), dest);
  is_light = set_light(0);
  if (is_light < 0)
    is_light = 0;
  if (!msgin)
    msgin = "arrives";
  say("Flying Disc " + msgin + ".\n");
}
abduct(human) {
 object from;
 from = environment(this_object());
 abducted = present(human,from);
 if(!abducted) return 0;
 move_object(abducted,this_object());
 tell_room(from,abducted->query_name()+" is sucked into the flying disc "+
   "on a beam of light.\n");
 tell_object(abducted,"You are sucked into the flying disc on a beam of "+
   "light.\n");
 do_anal_probe();
 return 1;
}
add_crew() {
 object beano;
/* destruct("/players/mizan/mball/beano-wandering-v7");*/
 beano = clone_object("/players/mizan/mball/beasties/beano");
 move_object(beano,this_object());
 beano = clone_object("/players/mizan/mball/beasties/beano");
 move_object(beano,this_object());
 beano = clone_object("/players/mizan/mball/beasties/beano");
 move_object(beano,this_object());
 return 1;
}
catch_tell(str) {
   int ran;
   ran = random(25);
   if (ran == 1) random_move();
   if (ran > 3 && ran < 10) random_move();
   if(!abducted)
   if (ran > 22) scan();
   return 1;
}
scan() {
  int i;
  string huntname;
  object check,huntob;
  check = allocate(20);
  check = all_inventory(environment(this_object()));
  i = 0;
  huntob = 0;
  huntname = 0;
  while (i<sizeof(check)){
   if(check[i]->is_player() && check[i]->query_level() < 21)
     if(random(20) < 3) { 
       huntob = check[i];
       huntname=lower_case(check[i]->query_real_name());
     }
   i += 1;
   }
  if(huntob) abduct(huntname);
  return 1;
}
move_me(arg) {
  command(arg);
}

