  id(str) { return str == "badge" || str == "zokbadge"; }
short() { return "A shiny Zokbadge that reads: 'I slew Tiamat *spit*'"; }
long() {
write("This is a small thingy made of a funky blue plastic that is\n"+
"somewhat warm to the touch. You feel that you can 'strut biggly' since you\n"+
"have killed one of the most vicious, nasty, smelly, lag-producing,\n"+
"visibly threatening, politically incorrect, and plainly unpleasant\n"+
"beasties on the mud.\n");
}

init() { 
  add_action("flauntme","strut");
}

query_auto_load() { return "/players/mizan/etheriel/items/zokbadge.c:"; }
get() { return 1; }
drop() { return 1; }

flauntme(str) {
  object ob;
  if(str != "biggly" || !str) return 0;

  ob=first_inventory(environment(this_player()));
  write("You strut biggly, with every right to, since you killed a 9-headed\n"+
  "monstrosity named Tiamat. Snort, gaggle, and weep!\n");
  say((this_player()->query_name()) + " killed a 9-headed dragon named Tiamat.\n");
  while(ob) {
    object oc;
    oc=ob;
    ob=next_inventory(ob);
      if(living(oc) && oc!=this_player()) {
    if(oc->query_level() < 20 && !present("zokbadge", oc)) {
        tell_room(environment(this_player()),
        (oc->query_name()) + " fears " + (this_player()->query_name()) + ".\n");
      } else {
        write((oc->query_name()) + " has a reason to not fear you (wiz?).\n");
      }
     }
    }
  return 1;
}
