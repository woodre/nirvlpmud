#include "/players/mythos/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Library: ** Misc Stacks **";
    long_desc =
    "You are in a room filled with books.  Here are the books\n"+
    "which cover topics that the other rooms did not: Treatises on\n"+
    "magic, books on war and warfare, poems, diaries, etc.  'Search'\n"+
    "the stacks to see what exists and 'read' to your heart's content!\n";
  items = ({
    "back","Leads to the rest of the library",
  });

  dest_dir = ({
    "/players/mythos/lroom/library3.c","back",
  });
} }

init() {
  ::init();
    
  add_action("ssay","say");
  add_action("ssay",";");
#ifndef __LDMUD__
  add_action("ssay");add_xverb("'");
#else
  add_action("ssay", "'", 3);
#endif
  add_action("ssay","gossip");
  add_action("ssay","farsong");
  add_action("ssay","farsonge");
  add_action("ssay","risque");
  add_action("ssay","babble"); 
  add_action("ssay","junk");
  add_action("zap","kill");
  add_action("zap","magic missle");
  add_action("zap","missle");
  add_action("zap","mi");
  add_action("zap","fireball");
  add_action("zap","fire ball");
  add_action("zap","fi");
  add_action("zap","shock");
  add_action("zap","sh");
  add_action("zap","sonic");
  add_action("zap","so");
  add_action("search","search");
  add_action("read","read");
}

ssay() {
  write("The Librarian tells you that talking is not allowed here!\n");
return 1;}

zap() {
  if( read_file("/players/mythos/lroom/enforcement/"+ lower_case(this_player()->query_name())) == "1") {
  write_file("/players/mythos/lroom/enforcement/"+ lower_case(this_player()->query_name()),"2");}
  if(!read_file("/players/mythos/lroom/enforcement/"+ lower_case(this_player()->query_name()))) {
    write_file("/players/mythos/lroom/enforcement/"+ lower_case(this_player()->query_name()),"1");}
  write(BOLD+"\n\tNO FIGHTING OR DISTURBANCES HERE!\n\n"+NORM);
  write("A Big Buff Guard grabs you by the neck and tosses you\n"+
        "out of the Library!  Remember, three strikes and you are out!\n");
  say("A Big Buff Guard grabs "+this_player()->query_name()+" by the neck and tosses "+
        this_player()->query_objective()+"out of the Library! \n");
  this_player()->set_crime();
  move_object(this_player(),"/players/mythos/lroom/hall.c"); 
  return 1;}

search() {
  write("The following books are here to be read:\n\n"+
        "\t\n");
  return 1;}

read(str) {
  if(!str) {write("What do you wish to read?\n"); return 1;}
  return 1;}
