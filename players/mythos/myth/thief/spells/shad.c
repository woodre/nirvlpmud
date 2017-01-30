#include "/players/mythos/myth/thief/def.h"
int mp,chance;
id(str) { return str == "shad" || str == "mshad" || str == "shadow" ||
                 str == "shadows"; }

short() { if(etp == ep) return ""; else return "Shadows"; }

long() { object obs; int k;
         if(etp == this_object()) {
         write("You peek at the world from inside the shadows:\n\n");
         ep->long();
         obs = all_inventory(ep);
         for(k=0;k<sizeof(obs);k++) if(obs[k]->short()) 
                                    write(obs[k]->short()+"\n"); }
         else write("You peer into the shadows....\n");
        }

drop() { return 1;}
get() { return 0; }
query_weight() { return 0; }
query_save_flag() { return 1; }

reset(arg) {
  if(arg) return;
  mp = 0;
  chance = 0;
}

set_chance(n) { chance = n; }
set_mp(n) { mp = n; }

init() {
  if(etp != this_object()) {
    if(!mp) {
      if(tp->query_invis() < chance/10)
      tell_room(this_object(),capitalize(tpn)+" enters the room.\n"); }
    if(chance < random(100)) {
        if(find_player(tpn) == tp) {
          if(tp->query_attrib("int") > random(100) ||
             tp->query_attrib("luc") > random(500)) 
             write("Someone is hidden in the shadows.\n"); }
        else 
          if(tp->query_aggressive() && !random(3)) {
            tell_room(this_object(),capitalize(tpn)+
            " growls at you and realizing that hiding is futile.\n"+
            "You come out of hiding.\n");
            move_all();
         }
   } } else {
     add_action("move_all","out");
     add_action("shhelp","shad_help");
}

shhelp() { write("To move around you must use the 'sneak' command.\n"+
                 "To come out of the shadows use 'out'\n"+
                 "This help is 'shad_help'\n"); }

realm() { return "NT"; }

move_all() {
object os;
int z;
  os = all_inventory(this_object());
  for(z=0;z<sizeof(os);z++) {
    move_object(os[z],ep);
    if(os[z]->short()) 
      tell_room(ep,os[z]->query_name()+" slinks out of the shadows.\n");
  }
  destruct(this_object());
return 1; }