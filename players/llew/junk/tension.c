inherit "obj/clean";

int num_pop;
reset(arg) {
  if(arg) return;
num_pop = 5;
}

id(str)   {
  return str == "sheet" || str == "tension sheet";
}

short () {
  return "A tension sheet"; 
}

long () {
  write("A red, one foot square piece of plastic with\n"+
    "numerous air bubbles.  Written in bold letters\n"+
    "is the word TENSION.  You have the urge to 'pop'\n"+
    "the sheet.\n");
}

get() { return 1; }

query_weight() { return 1; }
query_value() { return 1; }

init() {
  add_action("pop_bubble","pop");
}

pop_bubble(str) {

  if((!str) || !id(str))  {
  return 0;
}

  if(environment() != this_player())  {
    write("You'd best pick it up first.\n");
  return 1;
}
  if(num_pop <= 0) { 
    write("You squeeze your hardest, but all the bubbles have been popped.\n");
  return 1;
}

num_pop = num_pop - 1;
write("Your fingers squeeze the sheet hard!  You hear a loud POP.\n"+
    "The effort makes you feel more relaxed.\n");
say("You hear a loud POP coming from "+this_player()->query_name()+".\n"+
    this_player()->query_name()+" looks calmer than before.\n");

return 1;
}
