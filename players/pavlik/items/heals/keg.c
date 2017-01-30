/*
 * Standard Intox heal: 6 charges, Heal 20+random(40), Intox 7
 */

int drinks;
 
id(str) { 
  return str == "keg" || str == "beer" || str == "keg of beer";
}
 
reset(arg) {
  if(arg) return;
  drinks = 6;
}
 
long() {
  write(
  "A large wooden beer keg.  The smooth polished keg is quite a hefty\n"+
  "load but you can't wait to get your lips on it and drink.\n");
  if(drinks == 6) write("The keg is full.\n");
  if(drinks == 5 || drinks == 4) write("The keg is mostly full.\n");
  if(drinks == 3) write("The keg is half full (or the keg is half empty).\n");
  if(drinks == 2) write("The keg is mostly empty.\n");
  if(drinks == 1) write("The keg is nearly empty.\n");
  if(drinks < 1) write("The keg is bone dry. (sigh).\n");
}

short() { return "A keg of beer"; }

query_value() { return 100 + (drinks * 100); }

get() { return 1; }
 
query_weight() { return 2 + drinks; }
 
query_save_flag() { return 1; }
 
is_heal() { return "intox"; }
query_potence() { return 50; }
 
init() {
  add_action("drink_beer","drink");
}

drink_beer(str) {
  if(id(str)) {
    if(!drinks) {
      write("The keg is dry!\n");
      return 1;
    }
    if(!this_player()->drink_alcohol(7)) {
       return 1;
    }
    write("You lift the heavy keg and take a swig from its tap.\n");
    write("*glug* *glug* *glug* ..... AAaaaahhhh!\n");
    say(capitalize(this_player()->query_name())+" takes a swig from a "+
    "keg of beer.\n");
    this_player()->heal_self(20+random(40));

    if(present(this_object(), this_player()))
      this_player()->add_weight(-1);

    drinks--;

    if(!drinks)
      write("You empty the keg.\n");

    return 1;
  }
}
 