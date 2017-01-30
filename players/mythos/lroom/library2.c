#include "/players/mythos/closed/guild/def.h"
inherit "room/room";

reset(arg) {
if(!present("guard")) { 
  move_object(clone_object("/players/mythos/lmon/guard.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Library: ** 2 **";
    long_desc =
    "You stand in a large dark hall connected to rooms filled with books.\n"+
    "People move silently back and forth, to and fro, room to room, as they\n"+
    "search for the knowledge they seek- lands, guilds, people, history, magic,\n"+
    "meaning, life, etc.  This is a place of peace- remember this.\n\n";
  items = ({
    "south","You see the Library's entrance area",
    "north","Goes back to the rest of the library",
    "people","Want to know about the famous and infamous?  Here you go",
    "history","You wish to know about the history of Nirvana?  Enter",
  });

  dest_dir = ({
    "/players/mythos/lroom/library.c","south",
    "/players/mythos/lroom/ppl.c","people",
    "/players/mythos/lroom/h.c","history",
    "/players/mythos/lroom/library3.c","north",
  });
} }
realm() {return "NT"; }
init() {
  ::init();
  if( read_file("/players/mythos/lroom/enforcement/"+lower_case(this_player()->query_name())) == "12") {
  write("A Big Buff Guard grabs you by the neck and tosses you out of the Library!\n"+
        "\nYou have disturbed the peace far too much here!\n");
  say("A Big Buff Guard grabs "+this_player()->query_name()+" by the neck and tosses "+
        this_player()->query_objective()+"out of the Library! \n");
  move_object(this_player(),"/players/mythos/lroom/pun.c"); return 1;}
  
  if(this_player()->query_real_name() != "mythos") {
    this_player()->stop_hunter();}
    
  if(present(fear,this_player())) {
   present(fear,this_player())->set_defence(0);} 
  
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
}

ssay() {
  write("The Guard tells you that talking is not allowed here!\n");
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
  

