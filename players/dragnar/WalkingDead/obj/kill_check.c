#include "../defs.h"

int level, ex_level, height_ft, height_in, player_weight, player_killing;
string gender, title, pretitle, race, player_name, clan_name, description, al_title;
string *extra_look;

id(string str) {
   return str == "kill_check" || str == "kill_check_object";
}

short() { 
  if( !this_player() || this_player()->query_level() < 20 )
    return 0;
  
  return "kill_check"; 
}

init() {
  level = 0;
}

reset(arg){
  if(arg) return;
}

long() {
   write("Temporary long.\n");
}

save_stats(object ob) {
  string file;

  if(!ob) 
    return 0;
  file = SAVE_PATH + ob->query_real_name();
  if (!save_object(file)) {
     tell_room(environment(environment(this_object())), "Error in saving death stats!\n");
     return 0;
  } else return 1;
}

kill_check(object ob){
  int i, size;
  string extra;
  object corpse;
  object *inv;
  if(ob && ob->is_player() ) {
    player_name = ob->query_real_name();
    level = ob->query_level();
    ex_level = ob->query_extra_level();
    gender = ob->query_gender();
    height_ft = ob->query_phys_at( 1 );
    height_in = ob->query_phys_at( 2 );
    player_weight = ob->query_phys_at( 3 );
    title = ob->query_title();
    pretitle = ob->query_pretitle();
    race = ob->query_race();
    clan_name = ob->query_clan_name();
    player_killing = ob->query_pl_k();
    description = ob->query_description();
    al_title = ob->query_al_title();
    /* Check inventory */
    inv = all_inventory( ob );
    for( i=0, size = sizeof(inv); i < size; i++ ) {
      extra = inv[i]->extra_look();
      if( extra )
        extra_look += ({ extra });
    }
  }
  else
    return 1;
  save_stats( ob );
  return 1;
}

get() { return 1; }

drop() { 
  destruct( this_object() );
  return 1; 
}

query_value() { return 0; }
