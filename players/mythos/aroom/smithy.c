#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("smith")) {
    move_object(clone_object("/players/mythos/amon/smith.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Smithy";
    long_desc =
    "You have entered the Smithy.  Here blades are made.\n"+
    "The Smith is here to give you what you wish.\n"+
    "There is a sign telling what is there to purchase.\n";
  items = ({
    "north","You see the road going through the village",
    "sign","\tThe Following may be purchased:\n\n\t\tBackbiter (sword) (80k)\n\t\tKatana (Sword) (10k)\n\t\tWakizashi (Short Sword) (2.5k)\n\t\tTanto (Dagger) (1k)\n\t\tDaikyu (Great Bow)  (10k)\n\t\tQuiver (20 arrows)  (2k)\n\t\t1 Arrow (100)\n",
  });

  dest_dir = ({
    "/players/mythos/aroom/vil1.c","north",
  });
} }

init() {
  ::init();
  add_action("buy","buy");
}

buy(str){
  if(!present("smith")) {
    write("Without a Smith, swords may not be sold.\n");
  return 1; }
  else {
    if(str == "backbiter") {
      if(this_player()->query_money() < 80000) {
        write("You do not have enough to purchase Backbiter!\n");
      return 1; }
      else {
        write("The Smith nods and goes to the backroom.\n"+
               "He comes out with a sword wrapped in a cloth \n"+
               "and hands the blade to you\n");
        say(tp+" purchases Backbiter.\n");
        this_player()->add_money(-80000);
        move_object(clone_object("/players/mythos/awep/backbite.c"),this_player());
      return 1; }
    return 1; }
    if(str == "katana") {
      if(this_player()->query_money() < 10000) {
        write("You do not have enough to purchase a katana!\n");
      return 1; }
      else {
        write("The Smith nods in reply and gives you a Katana.\n");
      say("The Smith nods and hands "+tp+" a Katana.\n");
      call_other(this_player(),"add_money",-10000);
      move_object(clone_object("/players/mythos/awep/katana.c"),this_player());
      return 1;}
    return 1;}
    if(str == "wakizashi") {
      if(this_player()->query_money() < 2500) {
        write("You do not have enough money to purchase a wakizashi!\n");
      return 1;}
      else {
        write("The Smith nods and hands you a Wakizashi.\n");
        say("The Smith nods and hands "+tp+" a Wakizashi.\n");
      call_other(this_player(),"add_money",-2500);
      move_object(clone_object("/players/mythos/awep/wakizashi.c"),this_player());
      return 1;}
    return 1;}
    if(str == "daikyu") {
      if(this_player()->query_money() < 10000) {
        write("You do not have enough to purchase a Daikyu!\n");
      return 1; }
    else {
      write("The Smith nods and takes a Daikyu from the wall and hands it to you.\n");
      say("The Smith takes a Daikyu from the wall and hands it to "+tp+".\n");
      call_other(this_player(),"add_money",-10000);
      move_object(clone_object("/players/mythos/awep/daikyu.c"),this_player());
      return 1; }
    return 1;}
    if(str == "tanto") {
      if(this_player()->query_money() < 1000) {
      write("You do not have enough money!\n");
    return 1; }
    else {
      write("The Smith nods and hands you a Tanto.\n");
      say("The Smith hands "+tp+" a Tanto.\n");
      call_other(this_player(),"add_money",-1000);
      move_object(clone_object("/players/mythos/awep/tanto.c"),this_player());
    return 1; }
  return 1; }
    if(str == "arrow") {
      if(this_player()->query_money() < 100) {
        write("You do not have enough money for an arrow!\n");
    return 1; }
    else{
      write("The Smith hands you an arrow.\n");
      say("You see "+tp+" purchase an arrow.\n");
      call_other(this_player(),"add_money",-100);
      move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
    return 1;}
    return 1;}
    if(str == "quiver") {
      if(this_player()->query_money() < 2000) {
        write("You do not have 200 coins for a quiver of arrows!\n");
    return 1;}
    else {
      write("The Smith hands you a quiver of 20 arrows.\n");
      say("You see the Smith hand "+tp+" a quiver of arrows.\n");
      call_other(this_player(),"add_money",-2000);
      move_object(clone_object("/players/mythos/awep/quiver.c"),this_player());
    return 1;}
    return 1;}
return 1; }
return 1;}
