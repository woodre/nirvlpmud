/* Help with efun and such from the Great Dragnar  */
#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";
#include "/players/pestilence/define.h"

static object   owner;  
reset(arg){
  if(arg) return;
  set_id("blood");
  set_alias("blood");
  set_short("Daragor's blood");
set_long(
"This is the blood handed down from the fallen angel, Daragor.  One might be able to drink it.\n");
  set_value(500);
  set_weight(2);
}
init () {
   ::init() ;
     add_action ("Advance","drink");
   }



set_owner( object ob)
{
owner = ob;
}

object
query_owner()
{
   return owner;
}

Advance(string str) {
if(!id(str)) { notify_fail("Drink what?\n");
 return 0; }
  write("Do you really wish to join the Dark Order?!?\n\
Your level will be reset to 10, and some stats may be changed\n\
to meet the requirements of the guild.\n\
\nDo you still wish to proceed?  Y/N: ");
  input_to( "Advance_To" );
  return 1;
}

Advance_To( string str ) {
object spbrd;
object wgob;
int myexp;
int wok;
  if( !str || lower_case(str) != "y" ) {
    write("I guess you are too scared and weak to join the Dark Order.\n");
    destruct(this_object());
    return 1;
  }
  if (this_player()->query_guild_name() == "Dark Order") {
    write("You have already joined this guild :)\n");
   destruct(this_object());
    return 1;
  }
   if(this_player()->query_level() < 10 ) {
      write("You must be atleast level 10 to join the Dark Order.\n");
      return 1;
   destruct(this_object());
      }

   if(this_player()->query_level() > 20 ) {
      write("You must find other ways to see the guild.\n");
   destruct(this_object());
      return 1;
      }

  if (this_player()->query_guild_exp() >= 1) {
        write("You are already in a guild.\n");
   destruct(this_object());
        return 1;
        }
  if(present("dknight_ob", tp)){
   write("You are already a member of this guild.\n");
   destruct(this_object());
   return 1;
   }
if(!wok){
   if(tp->query_guild_name() != 0 || tp->query_guild_exp() || tp->query_guild_rank() || tp->query_guild_file()){
      write("You are already in another guild.\n");
   destruct(this_object());
      return 1; 
      }
  }

  this_player()->add_guild_rank(-this_player()->query_guild_rank());
  this_player()->add_guild_rank(1);
  this_player()->add_guild_exp(1);
  this_player()->set_guild_file(0);
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
  move_object(clone_object("players/pestilence/closed/dark/dark.c"), this_player());
    write_file("/players/pestilence/closed/dark/log/join2",ctime(time())+" "+this_player()->query_name()+" drank "+query_owner()+"'s blood and joined the "+HIK+"ORDER"+NORM+".\n");
write_file("/players/pestilence/closed/dark/log/join",ctime(time())+" "+this_player()->query_name()+" has joined the Order.\n");
    destruct(this_object());
  write("A dark aura now surrounds you.\n");
  return 1;
}
