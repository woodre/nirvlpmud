#include "/players/languilen/closed/ansi.h"
#include "../guilddefs.h"
#define TP this_player()
#define BASIC_DIRS ({ "/room/church.c","church","players/languilen/areas/inside.c","north","players/languilen/workroom.c","work", })
#define travob present("TRAV_OB", this_player())

inherit "room/room";

static string owner_name;
string mod_long;
string *extra_exits_data;

int restore_module();
void save_module();

reset(arg) {
     if(arg) return;

     set_light(1);

     if(!restore_module()){
        write("Could not load module.\n");
     }
     if(!owner_name) {
        write("Initializing new module.\n");
        owner_name = TP->query_real_name();
     }
     if(!short_desc) short_desc = capitalize(owner_name)+"'s module";
     if(!mod_long) mod_long="An undecorated module.\n";
     if(!long_desc){
        long_desc = (string)query_mod_long();
        if( !long_desc || long_desc=="" ) long_desc = "    A dull undecorated module.\n";
     }
     if(!extra_exits_data) extra_exits_data = ({});
     if(!dest_dir){
        dest_dir=BASIC_DIRS;
        if(query_extra_exits()){
           dest_dir+=query_extra_exits();
        }
     }
}

init(){
     ::init();
     if(TP->query_real_name()==owner_name){
        add_action("describe_module"); add_verb("describe_module");
     }
}

set_owner(str){
     owner_name = str;
}

string query_mod_long(){ return mod_long; }

save_mod_long(str){ long_desc = mod_long = str; }

add_extra_exit(str1, str2){
     string *temp;
     temp = ({ str1, str2 });
     extra_exits_data+=temp;
     dest_dir+=temp;
}

remove_extra_exit(str){
     int i;
     i=member_array(str, extra_exits_data);
     if(i<0){ return; }
     extra_exits_data -= ({ extra_exits_data[i-1], str });
     dest_dir -= ({ dest_dir[i-1], str });
}
string *query_extra_exits(){ return extra_exits_data; }


describe_module(){
     write("\nWrite your description now.  When you finish end with ** at the\n\
beginning of the line.  Lines may only be 75 characters long.\n");
     long_desc="";
     write(": ");
     input_to("input_long");
     return 1;
}

input_long(str){
     if(str=="**"){
        save_mod_long(long_desc);
        write("Description entered.\n");
        return;
     }
     if(strlen(str)>75){
        write("Line too long!  Please rewrite the line with less than 75 characters.\n");
     } else { long_desc += str+"\n"; }
     write(": ");
     input_to("input_long");
}

void save_module(){
     string mod_file;

     mod_file = GUILDSAVE+(string)TP->query_real_name()+"MOD";
     save_object(mod_file);
}

int restore_module(){
     string mod_file;

     mod_file = GUILDSAVE+(string)TP->query_real_name()+"MOD";
     return restore_object(mod_file);
}

