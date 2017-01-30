/*
 *
 */
#include "../paths.h"
#include "../mob.h"
/*  #include "/players/languilen/langdefs.h"  */
#include "/players/languilen/closed/ansi.h"

#define SAVEPATH GUILDSAVE+"/resturant1"

inherit "room/room";

static void save_resturant();

reset(arg) {
     if(arg) return;
     set_light(1);

     restore_object(SAVEPATH);

     if(!short_desc){
        short_desc = "An Empty Resturant";
     }
     if(!long_desc){
        long_desc =
"    A long table streches through the middle of this\n\
room.  Though presantly it looks abandoned this place\n\
could make a fine resturant.\n";
     }

     items = ({
     "book","An impressive volume bound in white leather, read it",
     });

     dest_dir = ({
     ROOM + "street1","south",
});

}

init(){
     ::init();
     add_action("describe_room", "decorate");
     add_action("resturant_name", "name_place");
}

describe_room(){
     write("\nWrite your description now.  When you finish end with ** at the\n\
beginning of the line.  Lines may only be 75 characters long.\n");
     long_desc="";
     write(": ");
     input_to("input_long");
     return 1;
}

input_long(str){
     if(str=="**"){
        save_resturant();
        write("Description entered.\n");
        return;
     }
     if(strlen(str)>75){
        write("Line too long!  Please rewrite the line with less than 75 characters.\n");
     } else { long_desc += str+"\n"; }
     write(": ");
     input_to("input_long");
}


resturant_name(str){
     if(!str){
        write("You must supply a name!\n");
        return 1;
     }
     short_desc = str;
     save_resturant();
     return 1;
}

save_resturant(){
     save_object(SAVEPATH);
     write("Resturant info saved.\n");
}

