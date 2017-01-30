/*
 * Battlefield Daemon - to track and destroy rooms.
*/

#include "/players/languilen/battle/paths.h"
#include "../../langdefs.h"
#define FIELD AREA+"bfield.c"
#define FROOMS ({"3_3", AREA+"hilltop.c", "5_5", AREA+"clear.c" })
#define X_MAX 5
#define Y_MAX 5
#define X_MIN 1
#define Y_MIN 1

mapping field;

id(str) { return str == "machine" || str == "controller"; }

short() {
    return "A Battlefield controll unit";
}

long() { write(
"    This very strange machine should not be messed with unless you\n\
know exactly what you're doing.\n");
}

init() {
    add_action("nuke_field"); add_verb("nuke_field");
    add_action("show_field"); add_verb("show_field");
    add_action("clean_field"); add_verb("clean_field");
}

nuke_field(str) {
    destroy_fields();
    write("The fields have been destroyed.\n");
    return 1;
}

show_field() {
     int i;
     string *rooms;

     i=sizeof(rooms=keys(field));
     while(i--){
          write( "Room : " + rooms[i] + "   " + field[rooms[i]]);
     }
     write("Done...\n");
     return;

}

clean_field() {
     int i;
     string *rooms;

     i=sizeof(rooms=keys(field));
     while(i--){
          if(!field[rooms[i]]->is_full()){
             destruct(field[rooms[i]]);
             field[rooms[i]] = 0;
          }
     }
     write("Field cleaned.\n");
     return;

}

reset(arg) {
     if(arg) return;
     start_cleaner();
     field = ([]);
     move_object(this_object(), AREA+"hilltop.c");
}

string get_room(string str){
     int i;
     string new;
     string *h_rooms;

     h_rooms = FROOMS;
     i = member_array(str, h_rooms);
     if( i > -1) return h_rooms[i+1];
     if(sizeof(field)) if(field[str]) return field[str];
     new = object_name(clone_object(AREA+"bfield.c"));
     h_rooms = keys(field);
     if( member_array(str, h_rooms) < 0 ) {
        field += ([ str:new ]);
     } else { field[str] = new; }
     find_object(new)->set_tfield(str);
     return new;
}

string validate_r(string str){
     int x,y;
     string s;

     sscanf(str,"%d_%d", x, y);
     if(x>X_MAX) x=X_MIN;
     if(y>Y_MAX) y=Y_MIN;
     if(x<X_MIN) x=X_MAX;
     if(y<Y_MIN) y=Y_MAX;
     s=x+"_"+y;
     return s;
}

start_cleaner(){
     call_out("clean_fields", 50);
     return;
}

clean_fields(){
     int i;
     string *rooms;

     remove_call_out("clean_fields");

     i=sizeof(rooms=keys(field));
     while(i--){
          if(!field[rooms[i]]->is_full()){
             destruct(field[rooms[i]]);
             field[rooms[i]] = 0;
          }
     }
     call_out("clean_fields", 50);
     return;
}

destroy_fields(){
     int i;
     string *rooms;

     i = sizeof(rooms=keys(field));
     while(i--){
          if( field[rooms[i]] ) {
             destruct( find_object(field[rooms[i]]) );
          }
          field[rooms[i]] = 0;
     }
     return;
}

mapping query_fields(){ return field; }

