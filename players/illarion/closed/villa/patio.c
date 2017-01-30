inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

string *sitting_ppl;

void reset(int arg) {
  if(arg) return;
  if(!sitting_ppl) sitting_ppl=({});

  set_light(1);
  set_short("A "+HIG+"tropical"+NORM+" honeymoon villa");
  set_long(
     "A wide patio runs almost the entire length of the villa here on the "
    +"seaward side.  The beach itself is down a short slope, leaving the "
    +"patio exposed to the sea breeze.  Several comfortable wooden sunbathing "
    +"chairs are lined up along the patio, alternating with small tables "
    +"for drinks.  The villa is to the west, and to the east, a path "
    +"leads toward the beach.");
  
  add_item("patio","The patio is smooth, and cool, even in the heat of the "
                  +"tropical sun.");
  add_item("villa","The sprawling villa is just to the west.");
  add_item("beach","The beach is just down a hill to the east, completely "
                  +"clean, and picture perfect.");
  add_item("chairs","Nice wooden chairs for relaxing, and getting a tan on.  "
                   +"They almost beg you to sit down on one.");
  add_item("tables","Small, shell-trimmed tables for putting drinks, or maybe "
                   +"a book on.");

  add_exit("northwest",VILLA+"bedroom");
  add_exit("west",VILLA+"livingroom");
  add_exit("southwest",VILLA+"dining");
  add_exit("beach",VILLA+"beach");
}
void init() {
  ::init();
  add_action("cmd_sit","sit");
  add_action("cmd_stand","stand");
  if(sitting_ppl && member_array(TP->query_real_name(),sitting_ppl)!=-1)
    sitting_ppl-=({TP->query_real_name()});
}
cmd_sit(string str) {
  if(!str || (str !="chair" && str !="on chair"))
    FAIL("Sit where?\n");
  if(!sitting_ppl) sitting_ppl=({});
  if(member_array(TP->query_real_name(),sitting_ppl)!=-1) {
    write("You're already sitting.\n");
    return 1;
  }
  write("You stretch out on one of the sunbathing chairs.\n");
  say(TPN+" stretches out on one of the sunbathing chairs.\n");
  sitting_ppl+=({TP->query_real_name()});
  return 1;
}
cmd_stand() {
  if(!sitting_ppl) sitting_ppl=-1;
  if(member_array(TP->query_real_name(),sitting_ppl)==-1) {
    write("You're not sitting down.\n");
    return 1;
  }
  write("You stand back up.");
  say(TPN+" gets out of "+TP->query_possessive()+" chair.\n");
  sitting_ppl -= ({TP->query_real_name()});
  return 1;
}
