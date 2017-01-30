/* Sobering bread -Dar */

#define tpn this_player()->query_name()
inherit "/obj/treasure";
id(str) { return (str == "loaf" || str == "bread"); }
reset() { save_flag = 1; }
short() { return ("A loaf of bread"); }
long() {write("A load of hearty peasent bread, it is a local cure\n"+
              "for the drunkards around town.\n"); }

init() {
  add_action("eat","eat");
}

eat(arg)
{
  if (id(arg)) {
    this_player()->drink_alcohol(-15);
    say(tpn + " takes a loaf of bread and chokes it down.\n");
    write("You choke down the stale loaf of bread.\n");
      this_player()->add_weight(-1);
      destruct(this_object()); 
      return 1;
      }
   else { 
   return 0; 
   }
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 200; }

