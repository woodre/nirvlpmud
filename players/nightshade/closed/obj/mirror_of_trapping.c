inherit "obj/treasure";
int here, check;
object trapee;
reset(arg) {
if(arg) return;
  set_id("mirror of entrapment");
  set_alias("mirror");
  set_short("Mirror of entrapment");
  set_weight(1);
}

query_value() { return 4000 - (check * 2000); }

init() {
::init();
  if(this_player()->query_level()<21) {
    write("The trapper explodes in your hands.\n");
    destruct(this_object());
    return 1;
  }
  add_action("entrap","entrap");
  add_action("release","release");
}

entrap(str) {
  if(here) {
    write("There is already a monster trapped within the mirror.\n");
    return 1;
  }
  if(!str)
    trapee = str;
  else
    trapee = present(lower_case(str), environment(this_player()));
  if(!trapee || !living(trapee)) {
    write("Entrap who?\n");
    return 1;
  }
if(trapee->query_aggressive())
{
write("You cant trap aggressive monsters.\n");
return 1;
}
  if(trapee == this_player()) {
    write("You have second thoughts about trapping yourself.\n");
    return 1;
  }
  if(!trapee->query_npc()) {
    write("You can not trap players!\n");
    return 1;
  }
  if(trapee->query_level() > (this_player()->query_level() - 5)) {
    write(trapee->query_name()+" laughs at you as you fail to entrap it.\n");
    return 1;
  }
  write("You shine the mirror at " + trapee->query_name() +
  " and with a flash, "+ trapee->query_name()+
  "\ngets sucked into the mirror.\n");
    say(this_player()->query_name()+ " entraps "+trapee->query_name() +
    " with a mirror of entrapment.\n");
  move_object(trapee, this_object());
  here = 1;
  check += 1;
  return 1;
}

release() {
  if(!here) {
    write("There is nothing in the mirror.\n");
    return 1;
  }
  write("You release " +trapee->query_name()+ " from the mirror.\n");
  say(this_player()->query_name()+ " releases " +trapee->query_name()+
    " from the mirror.\n");
  write("It is not happy with you so it attacks you!!!\n");
  move_object(trapee, environment(this_player()));
  trapee->attack_object(this_player());
  this_player()->attack_object(trapee);
  here = 0;
  if(check > 1) {
    write("The mirror shatters into many fragments.\n");
    say(this_player()->query_name()+ "'s mirror of entrapment shatters into many fragments.\n");
    destruct(this_object());
    return 1;
  }
  return 1;
}

long() {
  write("This strange mirror pulsates in your hands. It has the ability\n");
  write("to trap a living monster as long as the user is stronger than it.\n");
  write("All that needs to be done is: <entrap> <target> \n");
  write("You can also <release> the monster, but when it comes out,\n");
  write("it will attack on sight!\n");
  if(!here) {
    write("     The mirror is empty and you can only see your reflection.\n");
    return 1;
  }
  write("       Inside the mirror you can see: "+trapee->query_name()+ ".\n");
  return 1;
}

short() {
  if(!here) return "Mirror of Entrapment";
  else return "Mirror of Entrapment ("+trapee->query_name()+")";
}
