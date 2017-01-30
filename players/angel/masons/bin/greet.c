#include "defs.h"

status main(string str, int glevel) {
  object dest1;
  string me;
  string who;
   
    dest1=environment(this_player());
    me=(string)this_player()->query_name();
    
    if(!str) {
      write("You must specify someone to greet.\n");
      return 1;
    }
    if(sscanf(str,"%s",who) != 1) {
      write("Useage:  greet <member>\n");
      return 1;
    }
    if(!find_player(who)) {
      write("That player is not on.\n");
      return 1;
    }
    if(!present(MGOB_ID,find_player(who))) {
      write(capitalize(who)+" is not a guildmember.\n");
      return 1;
    }
    if(!present(find_player(who),dest1)) {
       write("That player is not here.\n");
       return 1;
    }
    tell_room(dest1,capitalize(me)+" and "+capitalize(who)+" clasp hands and join thumbnails.\n");
    tell_room(dest1,capitalize(me)+" says:  Greetings on all three points of the triangle.\n");
    tell_room(dest1,"\n");
    tell_room(dest1,capitalize(who)+" lifts his hands and makes a squared-U sign.\n");
    tell_room(dest1,capitalize(me)+" says:  Oh Lord my God is there no hope for the widow's son?\n");
    tell_room(dest1,"\n");
    tell_room(dest1,capitalize(who)+" says:  Will you spell it or triangle it?\n");
    tell_room(dest1,capitalize(me)+" says:  I will triangle it.  Ba.\n");
    tell_room(dest1,capitalize(who)+" says:  Ra.\n");
    tell_room(dest1,capitalize(me)+" says: Ka.\n");
    return 1;
}
