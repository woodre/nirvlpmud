/* hoop.c: hoola hoop */
status twirl;
short() { 
  return (twirl?"A hoola hoop (spinning)":"A hoola hoop");
}
long()  { 
  write("A large, hollow, plastic circular thing, with a pinkish color\n");
  write("to it. Just holding on to it, you feel like you're back in the 70's.\n");
  if(!twirl) write("You could probably \"twirl\" it.\n");
  return 1;
}
query_value() { return 50; }
get() { return 1; }
drop() { if(twirl) command("twirl", this_player()); return 0; }
id(str) { return str == "hoola hoop" || str == "hoop"; }
init() {
  if(environment(this_object()) == this_player())
  add_action("twirl", "twirl");
  else destruct(this_object());
}
twirl() {
  if(twirl) {
    write("You stop moving your hips.\n");
    write("The hoola hoop wobbles gently, then slowly falls to the ground.\n");
    write("You pick it up.\n");
    twirl = 0;
    say(this_player()->query_name()+" stops twirling the hoola hoop.\n");
    while(remove_call_out("do_twirl") != -1) ;
  } else {
    write("You 'step' inside the hoola hoop.\n");
    write("With a great exertion of force, you begin wildly moving your hips.\n");
    say(this_player()->query_name()+" begins to swing "+this_player()->query_possessive()+" wildly.\n");
    if(!random(10)) 
      write("The hoola hoop falls to the ground, and you are left with your body moving\n"
           +"in an insane motion.\n");
    else {
      write("Slowly, the hoola hoop begins to twirl.\n");
      say(this_player()->query_name()+" suceeds in getting the hoola hoop going.\n");
      twirl = 1;
      call_out("do_twirl", 10);
    }
  }
  return 1;
}
do_twirl() {
  if(!twirl) return 0;
  if(!living(environment(this_object()))) return 0;
  while(remove_call_out("do_twirl") != -1) ;
  tell_object(environment(this_object()), "You continue twirling the hoola hoop.\n");
   say(environment(this_object())->query_name()+" just has a knack with that hoola hoop.\n");
  call_out("do_twirl", 10+random(5));
}
