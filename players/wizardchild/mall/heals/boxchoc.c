/* boxchoc.c: box of chocolates */
/* this does not use the standard driver, because it has a setback */
#define uses 6
int used;
short() { 
  string sh;
  sh = "A box of chocolates";
  if(this_player()->query_level() > 30)
    sh+= " <heal "+query_heal()+", intox "+query_intox()+", #left "+(uses-used)+">";
  return sh;
}
long() {
  write("Just like Forrest Gump said, \"You never know what you're going to get!\".\n");
  write("Type \"eat chocolates\".\n");
}
id(str) { return str == "chocolates" || str == "box of chocolates"; }
get() { return 1; }
drop() {
  write("You drop the box of chocolates, and they turn bad as they hit the ground.\n");
  destruct(this_object());
}
query_weight() { return uses/3; }
query_value() { return 1000; }
query_intox() { return 10;   }
query_heal()  { return 35;   }
query_uses()  { return uses; }
query_used()  { return used; }
init() { add_action("eat_me", "eat"); }
eat_me(str) {
  string name;
  int x;
  if(!id(str)) return 0;
  if(!this_player()->eat_food(query_intox())) 
    return 0;                    
  x = 35;
  name = this_player()->query_name();
  if(random(10) == 1) x = -10;
  write("You pop a few chocolates in your mouth.\n");
  if(x > 0) {
    write("The overly-sweet chocolates give you an instant sugar high.\n");
    say(name+" pops a few chocolates and goes on an instant sugar high.\n");
  } else {
    write("Oh, sh**! You hit one of those nasty purple ones!\n");
    write("You instantly loose half your lunch.\n");
    say(name+" pops a few nasty chocolates and looses half their lunch.\n");
  }
  this_player()->heal_self(x);
  used++;
  if(used >= uses) {
    write("You have emptied the box. It falls to the ground and crumbles.\n");
    destruct(this_object());
  }
  return 1;
}
