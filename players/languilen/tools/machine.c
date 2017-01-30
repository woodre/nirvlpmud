/*
 *
 *
*/

#include "../langdefs.h"

mapping mymap;

int id(string str) {
  return str == "machine";
}

string short() {
     return "A machine";
}

void long() {
     write("This strange machine is almost indescribable.  Many parts in many\n\
shapes and sizes stick out from it in all sorts of directions.\n");
}

int get() {
  return 0;
}

void init() {
     add_action("nuke_map"); add_verb("nuke_map");
     add_action("show_map"); add_verb("show_map");
     add_action("add_key"); add_verb("add_key");
     add_action("rm_key"); add_verb("rm_key");
     add_action("add_val"); add_verb("add_val");
     add_action("rm_val"); add_verb("rm_val");
     add_action("filter_key"); add_verb("filter_key");
}

nuke_map() {
     mymap = ([]);
     write("Map nuked...\n");
     return 1;
}

show_map() {
     int i;
     string *mykeys;

     i=sizeof(mykeys=keys(mymap));
     while(i--){
          write( "Key : " + mykeys[i] + "     Val : " + mymap[mykeys[i]] + "\n" );
     }
     write("Done...\n");
     return 1;
}

add_key(str) {
     int i;
     string *mykeys;

     i=sizeof(mykeys=keys(mymap));
     if( member_array(str, mykeys) > -1){
        write("This key already exists!\n");
        return 1;
     }
     mymap += ([ str : 0 ]);
     write("Done...\n");
     return 1;
}
rm_key(str) {
     int i;
     string *mykeys;

     i=sizeof(mykeys=keys(mymap));
     if( member_array(str, mykeys) < 0 ){
        write("That key does not exist!\n");
        return 1;
     }
     mymap -= ([ str : mymap[str] ]);
     write("Done...\n");
     return 1;
}
add_val(str) {
     int i;
     string *mykeys;
     string k,v;

     if(sscanf(str,"%s %s", k, v) != 2){
        write("You must supply <key map> data!\n");
        return 1;
     }
     i=sizeof(mykeys=keys(mymap));
     if( member_array( k, mykeys) < 0 ){
        write("That key does not exist!\n");
        return 1;
     }
     mymap[k] = v;
     write("Done...\n");
     return 1;
}
rm_val(str) {
     int i;
     string *mykeys;

     i=sizeof(mykeys=keys(mymap));
     if( member_array(str, mykeys) < 0){
        write("This key does not exist!\n");
        return 1;
     }
     mymap[str] = 0;
     write("Done...\n");
     return 1;
}

filter_key(){
     mapping newmap;
     string *mykeys;
     int i;

     newmap = ([]);
     i = sizeof(mykeys = keys(mymap));
     while(i--){
          if( mymap[mykeys[i]] ){
              newmap += ([ mykeys[i] : mymap[mykeys[i]] ]);
          }
     }
     mymap = newmap;
     write("Done.\n");
     return 1;
}

int clean_key( string mapval, string str ){
     if( str = mapval ) return 0;
     if(mapval) return 1;
     return 0;
}

reset(arg) {
     if(arg) return;
     mymap = ([]);
}

