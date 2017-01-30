  id(str) { return str == "badge" || str == "spuckbadge"; }
short() { return "The Badge of the High Lord SpuckWarrior (shiny)"; }
long() {
  write("This is a shiny silvery thing, pretty useless, except for a\n"+
	"small intonation cast upon it. Typing 'flaunt badge' does wonders\n"+
	"to the ego of the wearer of this badge, etc.\n");
}

init() { 
  add_action("flauntme","flaunt");
}

get() { return 1; }
drop() { return 1; }
query_auto_load() { return "/players/mizan/etheriel/items/spuckbadge.c:"; }

flauntme(str) {
  object ob;
  if(str != "badge" || !str) return 0;

  ob=first_inventory(environment(this_player()));
 write("You flaunt your badge, and watch happily as the mortals react.\n");
  say((this_player()->query_name())+" flashes an impressive Badge of the Legion of the Spucks.\n");
  while(ob) {
    object oc;
    oc=ob;
    ob=next_inventory(ob);
      if(living(oc) && oc!=this_player()) {
    if(oc->query_level() < 20 && !present("spuckbadge", oc)) {
        command("worship "+(this_player()->query_name()), oc);
      } else {
        write((oc->query_name())+" refuses to worship you.\n");
      }
     }
    }
  return 1;
}
