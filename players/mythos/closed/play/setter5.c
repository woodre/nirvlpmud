#include "/players/mythos/closed/ansi.h"
#define person  "satan"

object wiz;
string names;

id(str) {return str == "setter"; }
drop() {return 1;}
reset(arg) {
  if(arg) return;
  wiz = ({});
  names = ({});
  call_out("hb",20);
  call_out("hb2",20);
}
query_prevent_shadow() { return 1; } 

hb() {
object bb, u;
int n, i, m, z, v, zz;
  if(!environment(this_object())) destruct(this_object());
  u = users();
  for(n=0;n<sizeof(u);n++) {
  if(u[n])
  if(u[n]->query_level())
  if(environment(u[n]))
    if(u[n]->query_level() > 19) {
      if(u[n]->query_real_name() != "mythos") {
        if(member_array(u[n],wiz) == -1) { wiz += ({u[n]});
        names += ({u[n]->query_real_name()});
        if(find_player("mythos")) { tell_object(find_player("mythos"),RED+"\t");
        if(u[n]->query_invis()) tell_object(find_player("mythos"),"** ");
        else tell_object(find_player("mythos"),"   ");
        tell_object(find_player("mythos"),
        u[n]->query_real_name()+" ["+u[n]->query_level()+"] has entered the game.\n"+NORM);
      }}
     }
  } }   
   /*
    if(find_player(person)) {
      if(!present("760624",find_player(person))) {
        bb = clone_object("/players/mythos/closed/play/shadow2.c");
        bb->set_owner(person);
        move_object(bb,environment(find_player(person)));
        move_object(clone_object("/players/mythos/closed/play/shadow4.c"),find_player(person));
        write_file("/players/mythos/closed/play/tell/"+this_player()->query_real_name(),
             RED+"\t"+ctime(time())+"\n"+NORM);
    } } */
    
    call_out("hb",3); return 1;
}

query_names() { 
  int g;
    for(g = 0; g<sizeof(wiz); g ++) {
      if(find_player("mythos")) {
      if(wiz[g]) {
        tell_object(find_player("mythos"),"\t"+wiz[g]+"\n"); }
      }
      if(find_player("meshitsukai")) {
        if(wiz[g]) {
        tell_object(find_player("meshitsukai"),"\t"+wiz[g]+"\n"); }
      }
    }
 return 1;}

hb2() {
object u; 
int n;
  u = users();
  for(n=0;n<sizeof(wiz);n++) {
    if(wiz[n]) {
      if(member_array(wiz[n],u) == -1) {
        if(find_player("mythos")) tell_object(find_player("mythos"),
        BLU+"\t"+names[n]+" has left the game.\n"+NORM);
        wiz -= ({wiz[n]});
        names -= ({names[n]});
      }
    }
  }
call_out("hb2",3);
return 1; }
