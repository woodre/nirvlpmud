#include "/players/dragnar/guild/defs/def.h"
drag(str) {
     int DN;
     object bringobj, who;
     string bgr;
	  if(!str && guildobj->query_drag() == 0) {
     write("Who do you want to drag?\n");
     return 1; }
	  if(!str && guildobj->query_drag() == 1) {
     write("You are no longer dragging anyone.\n");
     DN = 0;
     guildobj->set_drag(DN);
	  return 1; }
     who = find_player(str);
	  if(!present(str, environment(this_player()))) {
     write(capitalize(str)+" is not here.\n");
     return 1; }
	  if(!present(find_player(str), environment(this_player()))) {
	  write(capitalize(str)+" is not here.\n");
	  return 1; }
     if(usp < 40) {
     write("You do not have enough spell points to sacrifice.\n");
     return 1; }
     bgr = this_player()->query_real_name();
     write("Attempting to drag "+str+", waiting for acceptance.\n");
	  tell_object(who, capname+" wishes to drag you.  This will allow you to follow them.\n"+
	  "Type 'accept' to start following, or 'decline' to cancel.\n");
     bringobj=clone_object("/players/dragnar/guild/items/bringob");
     move_object(bringobj, who);
     bringobj->set_bringer(bgr);
     return 1; }
