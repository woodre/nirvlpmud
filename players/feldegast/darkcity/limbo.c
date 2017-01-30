#include "def.h"
inherit MYROOM;
reset(arg) {
  if(!present("emma"))
    move_object(clone_object(PATH+"Npc/emma"));
  if (arg) return;
  set_light(1);
  short_desc=YEL+"The Limbo Room"+NORM;
  long_desc=
"     Jazz filters through the hazy air of this dimly lit club.  Up\n\
on the stage a small band plays a slow, sad ballad to the night.  In\n\
the back is a long bar with a sign listing prices behind it.\n";
  items=({
    "sign","A sign listing prices which you can 'read'",
    "band","An ubiquitous three man band that seems to blend in to\n"+
           "the woodwork",
    "bar","A polished black bar with stools around it",
    "stage", "A raised platform where the band plays",
    "air", "It looks hazy",
  });
  dest_dir=({
    PATH+"street3","north"
  });
}   
init() {
  ::init();
  add_action("cmd_read","read");
  add_action("cmd_buy","buy");
  add_action("cmd_buy","order");
}
cmd_read(string str) {
  notify_fail("Read what?\n");
  if(!str || str!="sign") return 0;
  write(
"=====================================================\n"+
"=                    The Limbo Room                 =\n"+
"=                                                   =\n"+
"=                Wine.................90            =\n"+
"=                Beer................150            =\n"+
"=                Entropy Special.....250            =\n"+
"=                Martini.............260            =\n"+
"=                Whiskey.............300            =\n"+
"=                                                   =\n"+
"=====================================================\n");
  say(TPN+" looks at the sign behind the bar.\n");
  return 1;
}
cmd_buy(str) {
  int heal;
  int intox;
  int cost;

  if(!str) {
    write("What would you like to order?\n");
    return 1;
  }
  switch(str) {
    case "wine":
      heal=5; intox=7; cost=90; break;
    case "beer":
      heal=10; intox=9; cost=150; break;
    case "special":
      heal=25; intox=14; cost=250; break;
    case "martini":
      heal=20; intox=11; cost=260; break;
    case "whiskey":
      heal=30; intox=14; cost=300; break;
    default: write("That isn't on the menu.\n");
             return 1;
  }
  if( TP->query_money() < cost) {
    write("You don't have enough money to buy that.\n");
    say(TPN+" brushes some lint out of "+TP->query_possessive()+" pockets.\n");
    return 1;
  }
  if( TP->drink_alcohol(intox) ) {
    write("You pay "+cost+" for a "+str+" which you drink right away.\n");
    say(TPN+" orders a "+str+".\n");
    TP->add_money(-cost);
    TP->heal_self(heal);
    return 1;
  }
}

