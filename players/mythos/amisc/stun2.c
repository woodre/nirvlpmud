#define tp this_player()->query_name()
#define tg this_player()->query_possessive()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("tsolin");
  set_short("The stunned body of Tsolin");
  set_long("The stunned body of Tsolin....You may wish to 'bond' yourself to it\n"+
    "before it revives and disappears......\n");
  set_weight(5);
  set_value(500);
  call_out("vanish",60);
}
init() {
  add_action("bond","bond");
}

bond() {
  object mon;
  write("You take a knife out and cut the symbol Om into your palm.\n"+
    "Placing your hand upon the creature's head you intone:\n"+
    "\n\n\n\n\n\n\n\n"+
    "\tIn the name of POWER...  I claim you....My name is "+tp+"!\n"+
    "\n\n\n\n"+
    "\n\n\n\nThe head of the creatures heats up and then the creature disappears.....\n");
  say("You see "+tp+" cut a symbol into "+tg+" palm...\n"+
    "Places "+tg+" hand upon the creature's head and intones:\n\n\n\n\n"+
    "\n\n\n\n"+
    "\tIn The name of POWER....  I claim you.... My name is "+tp+"!\n"+
    "\n\n\n\n"+
    "\n\n\n\nThe creature disappears...\n");
  mon=clone_object("/players/mythos/amisc/tsolin.c");
  move_object(mon,this_player());
  write_file("/players/mythos/prac/ob",ctime(time())+"\t"+
  this_player()->query_real_name()+"\t\t"+this_player()->query_level()+"\ttso\n");
  destruct(this_object());   
  return 1;  }

vanish() {
  write("The body flickers and vanishes.\n");
  say("The stunned body of Tsolin flickers and vanishes.\n");
  destruct(this_object());
return 1;
}
