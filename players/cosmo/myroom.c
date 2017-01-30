/*
This is my standard room that inherits /room/room
and adds some additional features to it.
*/

#include "/players/cosmo/closed/dfns.h"
inherit "room/room";

/* Search object filename */
string search_fn;

/* Item in the room to be searched */
string search_item;

/* Search counter */
int search_count;

/* Smell message */
string smell_msg;

/* Item in the room with a smell */
string smell_item;

/* Sound message */
string sound_msg;

/* Item in the room with sound */
string sound_item;

set_search(str) { search_fn = str; }
set_smell(str) { smell_msg = str; }
set_sound(str) { sound_msg = str; }

query_light() {
string day, month, rest;
int blah, date, hour;
  blah=sscanf(ctime(time()),"%s %s %d %d:%s",day,month,date,hour,rest);
  if(hour>7 && hour<19) return 1; else return 0;
}

init() {
  ::init();
  add_action("search","search");
  add_action("smell","smell");
  add_action("listen","listen");
}

search(str) {
object ob;
   if (!search_count && search_fn)  {
      if (!search_item || search_item == str) {
         search_count = 1;
         ob = clone_object(search_fn);
         write("You find "+ lower_case(ob->short()) +".\n");
         move_object(ob,this_player());
         say (capitalize(TPQN) +" searches the area.\n");
         return 1;  }
      else {
         write("You vigorously search the "+str+" but find nothing.\n");
         say(capitalize(TPQN)+" searches the "+str+".\n");
         return 1;  }
   }
   write("You find nothing.\n");
   say(capitalize(TPQN)+" searches the area.\n");
return 1;  }

smell(str) {
  if (smell_item)  {
    if (str == smell_item) {
      write(smell_msg+"\n");
      say(capitalize(TPQN)+" smells the "+smell_item+".\n");
    }
    else if (str) {
      write("You curiously smell the "+str+" with no apparent effect.\n");
      say(capitalize(TPQN)+" smells the "+str+".\n");
    }
    else {
      write(smell_msg+"\n");
      say(capitalize(TPQN) +" takes in a deep breath.\n");
    }
  }
  else if (str) {
    write("You curiously smell the "+str+" with no apparent effect.\n");
    say(capitalize(TPQN)+" smells the "+str+".\n");
  }
  else {
    write(smell_msg+"\n");
    say(capitalize(TPQN) +" takes in a deep breath.\n");
  }
  return 1;
}

listen(str) {
  if (sound_item)  {
    if (str == sound_item) {
      write(sound_msg+"\n");
      say(capitalize(TPQN)+" listens to the "+sound_item+".\n");
    }
    else if (str) {
      write("You listen intently to the "+str+" but hear no sound.\n");
      say(capitalize(TPQN)+" listens to the "+str+".\n");
    }
    else {
      write(sound_msg+"\n");
      say(capitalize(TPQN)+" pauses suddenly as if startled by a sound.\n");
    }
  }
  else if (str) {
    write("You listen intently to the "+str+" but hear no sound.\n");
    say(capitalize(TPQN)+" listens to the "+str+".\n");
  }
  else {
    write(sound_msg+"\n");
    say(capitalize(TPQN)+" pauses suddenly as if startled by a sound.\n");
  }
  return 1;
}
