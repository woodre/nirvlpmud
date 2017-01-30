/* antfood.c: simple heal */
#define HPHEAL 15
#define SPHEAL  5
int times;
short() { return "A collection of ant food"; }
long() {
  write("A small pile of various plants and insect pieces. They look only slightly more\n");
  write("appetizing than the ant eggs, but you could probably choke some down.\n");
  return 1;
}
id(str) { return str == "ant food" || str == "food" || str == "collection of ant food"; }
get()          { return 1;   } 
query_weight() { return 2;   }
query_value()  { return 900; }
init() {
  add_action("eat_me", "eat");
}
eat_me(str) {
  if(!id(str)) 
    return 0;
  times++;
  if(times == 1) 
    write("You try to eat the ant food, and end up puking up half of it.\n");
  else 
    write("You finish off the ant food.\n");  
  this_player()->add_hit_point(HPHEAL);
  this_player()->add_spell_point(SPHEAL);
  if(times == 2)
    destruct(this_object());
  return 1;
}
