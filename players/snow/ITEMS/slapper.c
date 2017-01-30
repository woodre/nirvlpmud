/* To annoy people I guess */

object buster;
string buname;
id(str) { return str == "slap_er"; }
short() { return "A giant Hand"; }
long() { 
  write("This is a GIANT HAND!!!! you feel scared...\n");
return 1;
}

init() {
  if(this_player()->query_real_name() == "snow") add_action("slapp","slapp");
}

slapp(arg) {
  object meat;
  if(!arg) { write("Slapp who?\n"); return 1; }
meat = find_player(arg);
  if(!meat) { write("There is not that person to slapp!\n"); return 1; }
buster = meat;
buname = capitalize(meat->query_real_name());
  move_object(this_object(),environment(meat));
  call_out("life",1);
return 1;
}

life() {
  int perc;
call_out("life",1);
perc = random(10);
  if(perc < 3) swat();
  if(perc > 2 && perc < 6) fing();
  if(perc > 5) tickle();
return 1;
}

swat() {
  tell_room(environment(this_object()),
           "The giant Hand SWATS "+buname+" HARD across the fanny!\n");
  tell_object(buster,"OUCH!!! Your rear must be red as a maraschino cherry!\n");
return 1;
}

tickle() {
  tell_room(environment(this_object()),
           "The giant Hand TICKLES "+buname+" ALL over!\n");
  tell_object(buster,"AARGH!! Will it never stop???\n");
return 1;
}

fing() {
  tell_room(environment(this_object()),
           "The giant Hand sticks a FINGER in "+buname+"'s EAR!\n");
  tell_object(buster,"OW OW OW OW OW OW OW OW OW OW OW that HURTS!!!\n");
return 1;
}
