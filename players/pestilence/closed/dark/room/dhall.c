#include "/players/pestilence/define.h"
#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";
int OPEN;

reset(arg) {
  if(arg) return;

long_desc =
"    This is a lower room in the large cave system.  To the west leads\n"+
"to the main guild board, a cave that has been built totally out of rock from\n"+
"within the ground.\n";
set_light(-2);
set_no_clean(1);

items = ({
"rock","Large rocks that surround everything",
"rocks","Large rocks that surround everything",
"cave","A large cave leading into the ground",
"tunnel","A dark tunnel leading to the north and south",
});

dest_dir = ({
  "/players/pestilence/closed/dark/room/hall2.c","up",
  "/players/pestilence/closed/dark/room/dhall2.c","west",
});
} 
short() {
    return ""+HIK+"Dark Cave"+NORM+"";
}

realm() { return "NT"; }

init() {
  ::init();
/*
   add_action("join", "join");
   add_action("join_yes","join_yes");

        this_player()->set_fight_area();
*/
}

join() {
object spbrd;
int myexp;
object wgob;
int wok;
  if (this_player()->query_guild_name() == "Dark Order") {
    write("You have already joined this guild :)\n");
    return 1;
  }
  if (this_player()->query_guild_exp() >= 1) {
        write("You are already in a guild.\n");
        return 1;
        }
  if(present("dknight_ob", tp)){
   write("You are already a member of this guild.\n");
   return 1;
   }
if(!wok){
   if(tp->query_guild_name() != 0 || tp->query_guild_exp() || tp->query_guild_rank() || tp->query_guild_file()){
      write("You are already in another guild.\n");
      return 1; 
      }
   if(this_player()->query_level() < 10 || this_player()->query_level() > 10) {
      write("You must be level 10 to join the Dark Order.\nIf you are greater than level 10 you may have your level set\nto 10 and join, by typing join_yes.\n");
      return 1;
      }
  }

  myexp = this_player()->query_exp();
  this_player()->add_exp(-myexp);
  this_player()->add_exp(90000);
  this_player()->add_guild_rank(-this_player()->query_guild_rank());
  this_player()->add_guild_rank(1);
  this_player()->add_guild_exp(1);
  if(this_player()->query_attrib("mag") > 20) this_player()->set_attrib("mag",20);
  call_other(this_player(),"reset",1);
  call_other(this_player(),"save_me",0);
  write(""+HIK+"Darkness has consumed your soul"+NORM+".\n");
  write("You are now one of the Dark Order.\n");
  write_file("/players/pestilence/closed/dark/log/join",ctime(time())+" "+this_player()->query_name()+" has joined the Order.\n");
  move_object(clone_object("players/pestilence/closed/dark/dark.c"), this_player());
  write("A dark aura now surrounds you.\n");
  return 1;
}

join_yes() {
object spbrd;
object wgob;
int myexp;
int wok;
  if (this_player()->query_guild_name() == "Dark Order") {
    write("You have already joined this guild :)\n");
    return 1;
  }
   if(this_player()->query_level() < 10 ) {
      write("You must be atleast level 10 to join the Dark Order.\n");
      return 1;
      }
  if (this_player()->query_guild_exp() >= 1) {
        write("You are already in a guild.\n");
        return 1;
        }
  if(present("dknight_ob", tp)){
   write("You are already a member of this guild.\n");
   return 1;
   }
if(!wok){
   if(tp->query_guild_name() != 0 || tp->query_guild_exp() || tp->query_guild_rank() || tp->query_guild_file()){
      write("You are already in another guild.\n");
      return 1; 
      }
  }

  this_player()->add_guild_rank(-this_player()->query_guild_rank());
  this_player()->add_guild_rank(1);
  this_player()->add_guild_exp(1);
  myexp = this_player()->query_exp();
  this_player()->add_exp(-myexp);
  this_player()->add_exp(90000);
  this_player()->set_level(10);
  this_player()->set_extra_level(0);
  if(this_player()->query_attrib("mag") > 20) this_player()->set_attrib("mag",20);
  call_other(this_player(),"reset",1);
  call_other(this_player(),"save_me",0);
  write(""+HIK+"Darkness has consumed your soul"+NORM+".\n");
  write("You are now one of the Dark Order.\n");
write_file("/players/pestilence/closed/dark/log/join",ctime(time())+" "+this_player()->query_name()+" has joined the Order.\n");
  move_object(clone_object("players/pestilence/closed/dark/dark.c"), this_player());
  write("A dark aura now surrounds you.\n");
  return 1;
}
