#define ME capitalize(this_player()->query_real_name())

int bites;

reset(arg) {
  if(arg) return;
  bites = 2+random(4);
}

short() { return "A loaf of bread"; }

long() {
  write(
  "A loaf of moldy bread.  It isn't exactly fresh, but it appears to\n"+
  "still be edible.\n");
  return;
}

id(str) { return (str == "bread" || str == "loaf"); }

init() {
  add_action("eat","eat");
}

eat(arg) {
  if(id(arg)) {
    write("You bite of a hunk of the old bread.\n");
    write("The bread of hard to chew, but it feels good in your stomach.\n");
    say(ME+" takes a bite from a loaf of bread.\n");
    this_player()->heal_self(10+random(20));
    bites--;

    if(!bites) {
      write("You finish off the last bit of bread.\n");
      this_player()->add_weight(-1);
      destruct(this_object()); 
      return 1;
    }

    return 1;
  }
}
 
get() { return 1; }
query_weight() { return 1; }
query_value() { return 200; }
query_save_flag(){ return 1; }

