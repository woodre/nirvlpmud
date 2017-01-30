/*
 * Shardak guild - (tm) Dragnar/John
 * Grotto is (c) Balowski/Rasmus, March 12th 1995.
 * The main guild room. From here you can go many places
 * log
 * 950318 - something
 * 950421 - ROOM
 * 2000 - fixed board, 'in' exit. Used with Vertebrakers Permission
 */
#include "/players/balowski/lib.h"
#include "/players/vertebraker/closed/shardak/def.h"
#include "/players/pestilence/ansi.h"
#define VBOARD "/players/pestilence/closed/misc/board2"
#define tp this_player()

inherit ROOM;

void
create()
{
    ::create();
    if(!present("portal")) move_object(clone_object("/players/pestilence/closed/dark/OBJ/portal.c"), this_object());
    if(!present("notice")) move_object(clone_object("/players/feldegast/obj/pkobit"), this_object());
    set_short(""+HIK+"Main Entrance"+NORM+"");
    set_long("\
    This is the center room in a large cave system.  In each direction\n\
leads to another room, that has been built totally out of rock from\n\
within the ground.  It is possible for newcomers to join the guild,\n\
at this location by typing 'join'.  Beware one must qualify in the\n\
eyes of Pestilence before joining.\n");
    set_items( ([
({ "rocks", "large rocks" }) : "\
Large rocks that surround everything.\n",
({ "cave", "dark cave" }) : "\
A large cave leading into the ground.\n",
    ]));
    set_exits(([
        "u" :          ("/players/pestilence/closed/dark/room/hall2.c"),
        "hotel" :        ("/players/boltar/hotel/hotel.c"),
        "portal" :        ("/players/saber/ryllian/portal.c"),
        ]));
    set_light(-2);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

void
init()
{
    ::init();
    add_action("join", "join");
    add_action("join_yes", "join_yes"); 
}

join () {
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
   if(tp->query_guild_name() != "none" || tp->query_guild_exp() || tp->query_guild_rank() || tp->query_guild_file()){
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
  write("Darkness has consumed your soul.\n");
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
   if(tp->query_guild_name() != "none" || tp->query_guild_exp() || tp->query_guild_rank() || tp->query_guild_file()){
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
  write("Darkness has consumed your soul.\n");
  write("You are now one of the Dark Order.\n");
write_file("/players/pestilence/closed/dark/log/join",ctime(time())+" "+this_player()->query_name()+" has joined the Order.\n");
  move_object(clone_object("players/pestilence/closed/dark/dark.c"), this_player());
  write("A dark aura now surrounds you.\n");
  return 1;
}

status
allow_read(object who)
{
    if (who && (string) who->query_guild_name() == "Dark order") return 1;
}


void 
reset(int arg)
{
    object          board;
    ::reset(arg);
    if (!present("bulletin board")) {
        board = clone_object(VBOARD);
        board->set_name("servants");
        board->set_size(50);
        board->set_short("A board placed in the middle of the cave.");
        move_object(board, this_object());
    }
}

