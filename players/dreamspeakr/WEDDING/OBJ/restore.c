#include "/players/dreamspeakr/closed/ansi.h"
#define tp this_player()
#define tpn tp->query_real_name()
#define eo environment(this_object())
#define PATH "players/dreamspeakr/WEDDING/OBJ"
string asker;
int accept_ring();
int deny_ring();

void set_asker(string str);

int id ( string str ) { return str == "restore_ob"; }

reset(arg) { if(arg) return;
      call_out("timer",200);
}

void init () {
  add_action("accept_ring","accept");
  add_action("deny_ring","deny");
}

set_asker(str){
   asker = str;
}

accept_ring(){
   object new;
   new = clone_object("/players/dreamspeakr/WEDDING/OBJ/wedding_ring.c");
   new->set_spouse(asker);
   move_object(new, this_player());
   write("Your ring has been restored!\n");
   new->ring_save();
   write("Your ring has been saved!\n");
   destruct (this_object());
   remove_call_out("timer");
   return 1;
}

deny_ring(){
   write("Your denial has been noted.\n");
   tell_object(find_player(asker), "Your request has been denied, please throw your ring!\n");
   destruct (this_object());
   remove_call_out("timer");
   return 1;
}

timer(){
   write("Your time to respond has expired.\n");
  if(asker) if(find_player(asker))
   tell_object(find_player(asker), "Your request went unanswered!\n");
   destruct(this_object());
}
