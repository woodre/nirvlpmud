#include <ansi.h>
#include <strings.h>
#include <regexp.h>
#include "/sys/guilds.h"

string *my_key;

id(string str) {
#if 0
  tell_object(environment(), "Test ID called for: "+str+"\n");
#endif
   return str == "test" || str == "tester";
}

void
init() {
  add_action("test", "test");
  add_action("tst", "tst");
}
reset(arg){
  if(arg) return;
}

short() { 
  return "Tester";
}

long() {
  cat("/players/angel/area/stargate/obj/gate");
}

test(string str) {
  string path;
  int i;

  path = implode( explode(basename(this_object()), "/"), "/" );
  restore_object( path );
  i = sizeof( my_key );
  while( i-- )
    write("["+i+"] :" +my_key[i]+"\n"); 

  if( !my_key )
    my_key = ({ "a", "b", "c", "d", "|\\" });

  save_object( path );
  write("Saved...\n");
  return 1;
}

int tst( string str ) {
  return 1;
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

