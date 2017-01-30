/* 03/20/06 Earwax: moved call_out() to only respawn if there's a
 * user - 2 callouts for something that should only be calling out
 * if it's on a player anyways is a bit wasteful :)
 */

#include "/players/mythos/closed/ansi.h"
#define user environment(this_object())

query_auto_load() {
    return "/players/mythos/amisc/dark.c:"; }
id(str) {return str == "darkness"; }
short() {
    write(BOLD+"Aura of Darkness"+NORM+"\n"); }
long() {
    write(BOLD+"DARKNESS"+NORM+"\nIt seems to drain away your essence, and it will never let go.\n");
    write("You need a priest to 'eradicate' its traces.\n");
}
drop() {return 1;}
reset(arg) {
  if(arg) return;
 /* LD don't like this here, moving it to init -Bp
  call_out("hb",3);
*/
}

init() {
  add_action("eradicate","eradicate");
  blah_fix();
}
blah_fix() {
  while(remove_call_out("hb") != -1);
  call_out("hb",3);
}

hb() {
    if (environment() && user) {
    call_other(user,"add_spell_point",-5);
    call_other(user,"add_hit_point",-2);
    tell_object(user,"You feel the "+BOLD+"DARKNESS"+NORM+
				               " tug at your soul...\n");
	user->save_me();
    call_out("hb",3);
    }
return 1;
}

eradicate() {
  if(this_player()->query_current_room()=="players/mythos/aroom/shrinear5.c") {
  object ob;
  ob=first_inventory(environment(this_player()));
  while(ob) {
  if(ob->query_name()=="priest") {
  write("The Priest softly incants....\n"+
      "You feel a great weight fall from you....You are free from darkness!\n");
    say("The Priest incants....\n");
    destruct(this_object());
}
ob=next_inventory(ob);
ob;
}
return 1;}
return 1;}
