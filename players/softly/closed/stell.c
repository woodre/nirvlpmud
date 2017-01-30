/*
  Softly's Wiztell .. 
  (c)Softly/Nirvana January, 2000
  last updated March, 2000
  .. who remembers the small pillow 
  from the soft room
*/

#include "/players/softly/closed/ansi.h"


id(str) { return str == "teller" || str == "pillow" || str == "softell"; }

short() { 
  return MAG+"A small pillow"+NORM; 
}

long() { 
  write("A teller.\n"); 
}

init() {
  add_action("cmd_st", "st");
  add_action("cmd_ste", "ste");
  add_action("cmd_tell", "tell");
  add_action("cmd_farem", "farem");
  add_action("cmd_say","say");
  add_action("cmd_say"); add_xverb("'"); 
  add_action("cmd_emote","emote");
  add_action("cmd_emote"); add_xverb(":");
}

cmd_tell(str) {
  object plyr;
  string myname, who, what;  
  if(!str) { 
    write("Excuse me?\n"); 
    return 1; 
  }
  /* attempt to type fewer letters */

  if(sscanf(str,"%s %s",who,what) < 2) 
    {
      write("Tell <who> <what>.\n"); 
      return 1; 
    }
  if(who == "ml") who = "maledicta";
  if(who == "vb") who = "vertebraker";
  plyr = find_living(who);
  myname = capitalize(this_player()->query_real_name());
  if(!plyr) { write(capitalize(who)+" is not on now.\n");
  return 1; 
  }
  plyr->add_tellhistory(myname + " tells you: " + what);
  tell_object(plyr,BOLD+"Softly tells you: "+NORM+what+"\n");
  write("You tell "+capitalize(who)+": "+what+"\n");
  return 1;
}

cmd_farem(str) {
  object plyr;
  string myname, who, what;  
  if(!str) { 
    write("Excuse me?\n"); 
    return 1; 
  }
  /* attempt to type fewer letters */

  if(sscanf(str,"%s %s",who,what) < 2) 
    {
      write("ste <what>.\n"); 
      return 1; 
    }
  if(who == "ml") who = "maledicta";
  if(who == "vb") who = "vertebraker";
  plyr = find_living(who);
  myname = capitalize(this_player()->query_real_name());
  if(!plyr) { write(capitalize(who)+" is not on now.\n");
  return 1; 
  }
  tell_object(plyr, BOLD+"Softly, from afar, "+NORM+what+"\n");
  write(capitalize(who)+" "+what+"\n");
  return 1;
}

cmd_say(str) {
  if(!str) {
    notify_fail("Excuse me?\n");
    return 0; 
  }
  write("You say: "+str+"\n");
  say(BOLD+this_player()->query_name()+" says: "+NORM+str+"\n");
  return 1; 
}

cmd_emote(str) {
  if(!str) {
    notify_fail("Excuse me?\n");
    return 0; 
  }
  write(BOLD+"Softly "+NORM+str+"\n");
  say(BOLD+this_player()->query_name()+" "+NORM+str+"\n");
  return 1; 
}

drop(){
  write("You can't drop the pillow!\n");
  return 1; 
}

cmd_st(str) {
  object sob;
  string what;
  sob = find_player("softly");
  if(!sob) 
    {
      notify_fail(BOLD+"Softly isn't logged on.\n"+NORM);
      return 0; 
    }
  if(in_editor(sob)) {
    notify_fail(BOLD+"Softly is editing. Try again later.\n"+NORM);
    return 0; 
  }
  write(BOLD+"You tell Softly: "+NORM+str+"\n");
  what = BOLD+capitalize(this_player()->query_real_name())+" tells you: "+NORM+str;
  tell_object(sob,what+"\n");
  return 1; 
}

cmd_ste(str) {
  object sob;
  string what;
  sob = find_player("softly");
  if(!sob) 
    {
      notify_fail(BOLD+"Softly isn't logged on.\n"+NORM);
      return 0; 
    }
  if(in_editor(sob)) {
    notify_fail(BOLD+"Softly is editing. Try again later.\n"+NORM);
    return 0; 
  }
  write(BOLD+"You "+NORM+str+" Softly.\n");
  what = BOLD+capitalize(this_player()->query_real_name())+" "+NORM+str+"s you.";
  tell_object(sob,what+"\n");
  return 1; 
}

status get() { 
  return 1; 
}





