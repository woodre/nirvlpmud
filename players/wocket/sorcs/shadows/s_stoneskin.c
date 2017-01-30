#include "/players/wocket/closed/ansi.h"

object book;
object mage;

id(str){ return str == "w_stoneskin"; }

start_stoneshadow(object obj){
  book = obj;
  mage = environment(book);
  shadow(book,1);  
  init();
}

stop_stoneshadow(){
  tell_room(environment(mage),HIB+"The blue aura surrounding "+mage->query_name()+" begins to fade.\n"+NORM);
  tell_room(environment(mage),HIB+mage->query_name()+"'s skin changes from stone to flesh.\n"+NORM);
  shadow(book,0);
  destruct(this_object());
  return 1;
}

init(){
  add_action("stopaction");add_xverb("");
  add_action("de","de");
  book->init();
}

stopaction(str){
  if(random(10)<9){
    write("You are concentrating to deeply on your stoneskin to do anything else.\n");
    return 0;
}
  write("You manage to move slightly.\n");
  return 0;
}

de(str){
if(str != "stone"){
  notify_fail("What spell are you trying to cancel?\n");
  return 0;
}
write("You command your skin to return to normal.\n");
stop_stoneshadow();
return 1;
}

extra_look(){
string blah;
blah = HIB+"\t[ skin as hard as stone ]"+NORM;
return blah;
}
