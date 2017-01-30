int cmd_move(string str) {
  string loc;
  switch(random(3)) {
    case 0: loc="/dest/blah1.c";
            break;
    case 1: loc="/dest/blah2.c";
            break;
    case 2: loc="/dest/blah3.c";
            break;
   default: write("This should not happen, I'm just demontrating a feature of the switch statement.\n");
  }
  say(TPN+" leaves blah...\n");
  move_object(TP,loc);
  command("look",TP);
  say(TPN+" arrives blah...\n");
  return 1;
}
