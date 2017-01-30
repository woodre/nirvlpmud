/* variety.c: variety pack */
#define uses 12
int used;
short() { 
  string sh;
  sh = "A variety pack";
  if(this_player()->query_level() > 30)
    sh+= " <heal "+query_heal()+", intox "+query_intox()+", #left "+(uses-used)+">";
  return sh;
}
long() {
  write("A package with assorted goods, looks like.\n");
  write("Just type \"eat variety\" to get something out of it.\n");
}
id(str) { return str == "variety" || str == "variety pack"; }
get() { return 1; }                                    
drop() {
  write("You drop the variety pack.\nIt crumbles as it hits the ground.\n");
  destruct(this_object());
}
query_weight() { return uses/3; }
query_value() { return 2000; }
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
  x = 30 + random(10);
  name = this_player()->query_name();
  write("You reach into the variety pack.\n");
  if(x > 35) {
    write("You pull out a small bag of jelly beans. Yummie!\n");
    say(name+" munches on some jelly beans.\n");
  } else {
    write("You pull out a tootsie roll. Everyone laughs as you eat it.\n");
    say(name+" munches on a tootsie roll. How dumb is he to eat that??\n");
  }
  this_player()->heal_self(x);
  used++;
  if(used >= uses) {
    write("You have emptied the box. It falls to the ground and crumbles.\n");
    destruct(this_object());
  }
  return 1;
}
