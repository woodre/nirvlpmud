#include "/players/mythos/closed/guild/def.h"
string asker, recieve,p;
id(str) { return str == "con_ask"; }

drop() { return 1; }
get() { return 0; }

set_asker(str) { asker = str; }
set_recieve(str) { recieve = str;}

init() {
  if(!(ep->query_npc())) {
    tell_object(ep,capitalize(asker)+" wishes for a mind meld with you.\n"+
          "Will you allow it? <y/n>  ");
    input_to("aanswer");
    }
}

aanswer(p) {
object mindmeld, baselink;
  if(p == "y") {
  tell_object(find_player(asker),"You have mind melded with "+recieve+"!\n");
  tell_object(ep, "You have mind melded with "+asker+"!\n"); 
  mindmeld = clone_object("/players/mythos/closed/guild/spells/mind.c");
  mindmeld->set_base(asker);
  mindmeld->set_from(recieve);
  mindmeld->set_num(ep->query_exp());
  move_object(mindmeld,ep);
  if(!present("base_link",find_player(asker))) {
  baselink = clone_object("/players/mythos/closed/guild/spells/baselink.c");
  baselink->set_base(asker);
  baselink->set_num(find_player(asker)->query_exp());
  move_object(baselink,find_player(asker)); }
  }
  else {
  tell_object(find_player(asker),"The mind meld was turned down by "+recieve+"!\n");
  tell_object(ep,"You turn down the mind meld...\n"); }
  destruct(this_object());
return 1;}
