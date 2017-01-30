#include "/players/feldegast/defines.h"
inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("scroll");
  set_alias("firestorm");
  set_short("Scroll: "+HIR+"Firestorm"+NORM);
  set_long(
"Magic formulae and incantations are inscribed in a spidery script on\n"+
"a tightly rolled vellum scroll.  The scroll smells of dust and the\n"+
"reagents of powerful magic.\n"
  );
  set_weight(1);
  set_value(1000+random(500));
}
init() {
  ::init();
  add_action("cmd_firestorm","read");
}

static cmd_firestorm(str) {
  object ob;
  object next;
  int n,ahp;
  notify_fail("Read what?\n");
  if(!str || str!="scroll") return 0;
  tell_room(environment(TP),TP->query_name()+" begins reading a scroll.\n");
  tell_room(environment(TP),RED+"A swirling wind of flame descends from the sky, engulfing the room in\n"+
           "an inferno of burning death.\n"+NORM);
  ob=first_inventory(environment(TP));
  while(ob) {
    next=next_inventory(ob);
    if(living(ob)) {
      if( ob!=TP && TP->valid_attack(ob) ) {
        if(ob->is_player()) n = random(15)+TP->query_attrib("wil");
        else n=30+TP->query_attrib("wil");
        ahp = ob->query_hp();
        if(TP->query_sp() >= 10 ) {
          if(n>ahp) { n = ahp - 1; }
          ob->hit_player(n);
          TP->add_sp(-10);
          tell_room(environment(TP),
            ob->query_name()+" is "+RED+"engulfed in "+HIR+"flames!\n"+NORM);
           TP->attacked_by(ob);
           ob->attacked_by(TP);
        }
      }
    }
    ob=next;
  }
  destruct(this_object());
  return 1;
}
