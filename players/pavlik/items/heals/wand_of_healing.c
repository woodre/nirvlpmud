#define ME capitalize(this_player()->query_name())
#define IT capitalize(obj->query_name())

int charges;

id(str) {
  return str == "wand of healing" || str == "wand";
}

reset(arg){
  if(arg) return;
  charges = 2 + random(4);
}

long() {
  write(
  "A magical wand of healing.  The short piece of enchanted\n"+
  "woods contains the ability to heal wounds.  To use this\n"+
  "magical item simply wave it over who you want to heal.\n");
  if(charges == 1) write("The tiny rod is nearly 1 foot in length.\n");
  else write("The wooden rod is nearly "+charges+" feet in length.\n");
  return;
}

short() { return "A Wand (enchanted)"; }

init() {
  add_action("use_wand","wave");
}

get() { return 1; }

query_value() { return charges * 100; }

query_weight() { return 1; }

query_save_flag() { return 1; }

is_heal() { return "nontox"; }

query_potence() { return 100; }

use_wand(str){
  string who;
  object obj;

  if(str == "wand" || sscanf(str, "wand over %s", who) == 1) {
    if(!who) obj = this_player();
    else obj = present(who, environment(this_player()));
    if(!obj || !living(obj)) return 0;
    if(obj == this_player()) write("You wave the wand over yourself.\n");
    else write("You wave the magic wand over "+IT+".\n");
    say(ME+" waves a magical wand through the air.\n");
    tell_object(obj,
    "The melodious magic of healing seeps into your body and soothes\n"+
    "your wounds.  You feel much better.\n");
    tell_room(environment(this_player()),
    "A magical aura briefly encompasses "+IT+".\n");
    obj->heal_self(50+random(50));
    charges--;

    if(charges == 0) {
      write("The magic wand shrinks into nothing and disappears.\n");
      this_player()->add_weight(-1);
      destruct(this_object());
    }
    return 1;
  }
}

