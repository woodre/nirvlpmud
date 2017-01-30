#include "/players/pathfinder/closed/shadow/esc.h"
#define BOLD ESC+"[1m"
#define NOSTYLE ESC+"[0m"
#define NAME "Pathfinder"
#define DEST "players/pathfinder/detroit/rooms/entrance"
#define GUILD "/players/pathfinder/closed/shadow/shadow.c"
#define TP this_player()
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */
 
id(str) { return str == "pool" || str == "darkness"; }
 
short() {
  return ""+BOLD+"Pool of Darkness"+NOSTYLE;
}
 
long() {
  write("This in the Entrance to the Shadow Guild.  If you are not a member\n");
  write("and wish to become one, please ask another Shadow on how to join.\n");
  write("To enter the pool of Darkness type "+BOLD+"enter pool"+NOSTYLE+"\n");
}
 
init() {
    add_action("enter"); add_verb("enter");
    add_action("register_me", "register");
}
 
reset(arg) {
    if (arg)
        return;
    move_object(this_object(), DEST);
}
 
is_castle(){return 1;}
 

register_me()
{
  if(present("shadow-mark",this_player())) {
    tell_object(this_player(),"You already have a shadow mark!\n");
    return 1;
    }
  if(this_player()->query_guild_name() == "shadow" && !present("shadow-mark", this_player())) {
    move_object(clone_object("/players/pathfinder/closed/shadow/shadow.c"), TP);
    tell_object(TP,"You have your shadow mark returned to you!\n");
    return 1;
    }
    else
    {
      tell_object(TP,"You are not a shadow!\n");
    return 1;
    }
}
enter(str) {
  if(!id(str)) return 1;
  if(TP->query_guild_name() != "shadow") return 1;
    tell_object(TP,"You let your shadow take control of you as you enter the pool.\n");
    tell_room(DEST,"You see "+capitalize(TP->query_real_name())+" take on a shadowy form and enter the pool.\n");
    call_other(this_player(),"move_player", "enter#players/pathfinder/closed/shadow/rooms/guild_enter");
    return 1;
}

