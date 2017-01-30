#include "/players/feldegast/defines.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("scroll");
  set_short("Scroll of Transmigration");
  set_weight(1);
  set_value(1500);
  set_long(
"This scroll has been carefully inscribed with intricate geometric\n"+
"patterns and faintly glowing runes.  An inscription at the top of\n"+
"the scroll reads, 'Scroll of Transmigration'.\n");
}
init() {
  add_action("cmd_read","read");
}
cmd_read(str) {
  string where;
  notify_fail("Read what?\n");
  if(!str) return 0;
  if(str!="scroll") return 0;
  if(environment(TP)->realm()=="NT" ||
    environment(TP)->realm()=="NM" ||
    environment(TP)->query_NM()) {
    write("As you read the scroll, the runes start to glow increasingly\n"+
          "bright and then...fade back to normal.\n");
    say(TPN+" reads a scroll but nothing happens.\n");
    return 1;
  }
  if(TP->query_attrib("int") < random(24)) {
    write("You misread the scroll.\nThe scroll crumbles to dust in your hands.\n");
    destruct(this_object());
    TP->add_weight(-1);
    return 1;
  }
  while(!(where=call_other("obj/base_tele","teleport"))) ;
  write("As you read the scroll, the runes start to glow increasingly bright.\n"+
        "When you reach the end of the scroll, the light becomes blinding.\n"+
        "At last, when your eyes finally clear, you are somewhere else.\n\n");
  say(TPN+" disappears in a flash of light as "+TP->query_pronoun()+" reads a scroll.\n");
  move_object(TP,where);
  command("look",TP);
  write("The scroll crumbles to dust in your hands.\n");
  say(TPN+" arrives in a flash of light.\n");
  destruct(this_object());
  TP->add_weight(-1);
  return 1;
}
