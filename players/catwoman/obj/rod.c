
/* Raistlin's rod of room alteration */


#define SCREEN_WIDTH 70
#define TOPLINE  "/* This room uses Raistlin's interactive room maker */\n"
#define BASELINE "/* Place your own additions below this line */\n"

object ob;

reset(arg) {
    return;
}

id(str) {
    return str == "rod";
}

get() {
    if(!(this_player()->query_level() > 20)) return;
    log_file("rod_of_room",this_player()->query_real_name() + " gets a rod.\n");
    return 1;
}

drop() {
    return 1;
}

short() {
    return "The Rod of Room Alteration";
}

query_auto_load() {
    return "obj/rod_of_room:rod";
}

init() {
    if(!this_player()->query_level() > 20) return;
    add_action("create","create",0);
    add_action("edit","edit",0);
    add_action("dump","dump",0);

    add_action("abort","abort",0);
    add_action("set_short","short",0);
    add_action("set_long","long",0);
    add_action("light","light",0);
    add_action("outdoors","outdoors",0);
    add_action("add_desc","describe",0);
    add_action("rm_desc","rmdesc",0);
    add_action("add_realm","realm",0);
    add_action("rm_realm","rmrealm",0);
    add_action("add_exit","exit",0);
    add_action("rm_exit","rmexit",0);
    add_action("add_door","door",0);
    add_action("rm_door","rmdoor",0);
    add_action("auto_sequence1","auto",0);
}

long() {
    if(!this_player()->query_level() > 20) {
        write("Only a wizard might see something special about the rod.\n");
        return;
}       
    write("This is The Rod of Room Alteration.\n" +
          "Is is used to interactively create and edit rooms using the\n" +
          "standard room (room/room). The rod has the following command:\n" +
          "\n" +
          "create <file> : This will create a new room.\n" +
          "edit          : This will edit the room you currently occupy.\n" +
          "dump          : This will save the room you currently occupy.\n" +
          "abort         : This will cancel all changes.\n" +
          "auto          : This will automatically create a room.\n\n" +
          "short    <string>           : Set the short description.\n" +
          "long     <string>           : Set the long description.\n" +
          "light    <int>              : Set the number of light sources.\n" +
          "outdoors <int>              : Set the degree of outdoorness.\n" +
          "rmdesc   <item>             : Remove a description from room.\n" +
          "decribe  <item> as <string> : Add a description to room.\n" +
          "rmrealm  <realm>            : Remove a realm from room.\n" +
          "realm    <realm>            : Add a realm to room.\n" +
          "rmexit   <dir>              : Remove an exit from room.\n" +
          "exit     <dir> <file>       : Add an exit to room.\n" +
         "rmdoor   <dir>              : Remove a door from room.\n" +
          "door     <dir> <file> <\"name\"> <type> <key> <link> :\n" +
          "Add a door to room.\n" +
          "<type> : OPEN CLOSED LOCKED AUTO HIDDEN HIDLOCK HIDAUTO SMASHED\n" +
          "         or number.\n" +
          "<key>  : NONE, key-code or omitted.\n" +
          "<link> : ONEWAY TWOWAY number or omitted.\n");
}

static create(str) {
    string file;

    if(ob) {
                write("You are still editing : /"+file_name(ob)+".c\n");
        return 2;
    }
    if(!str) return 0;

/*    if(extract(str,0,0) != "/")
        file = this_player()->query_path() + "/" + str + ".c";
    else*/
        file = str + ".c";

    if(file_size(file) >= 0) {
        write(file + " exists already.\n");
        return 2;
    }

    if(file_size(file) == -2) {
        write(file + " is a directory.\n");
        return 2;
    }

    new_file(file);

    file->setup();
    move_object(this_player(),file);
    return 1;
}
                        
static edit() {
    if(ob) {
        write("You are still editing : /" + file_name(ob)+".c\n");
        return 2;
    }
    ob = environment(this_player());
   write("Editing : /" + file_name(ob) +".c\n");
    return 1;
}

static dump() {
    string line,rest,file;
    int n;

    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
        file = "/" + file_name(ob) + ".c";
    line = read_line(file,1);
    if(line != TOPLINE) {
        write("This file was NOT created by this rod. If you save anyway,\n" +
              "you old code will be placed in comments in the new file.\n" +
              "This way you may edit it by hand to fit the new format.\n");
        write("SAVE ANYWAY ? : ");
        input_to("query_save");
        return 1;
    }

    rest = "";
    if(line) {
        n = 2;
        while(line = read_line(file,n)) {
            n += 1;
            if(line == BASELINE) break;
        }
        if(line) {
            while(line = read_line(file,n)) {
                rest = rest + line;
                n += 1;
            }
        }
    }

    update_file(file,rest);
    update_room();
    return 1;
}

static abort() {
    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
        write("Aborted : /" + file_name(ob) + ".c\n");
    update_room();

    ob = 0;
    return 1;
}

set_short(str) {
    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
    ob->set_short(str);
    return 1;
}

set_long(str)  {
    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
    ob->set_longf(str);
    return 1;
}

light(str) {
    int i;

    if(str == "on" || str == "off") return 0;

    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
    if(!str) return 0;
    if(!sscanf(str,"%d",i)) return 0;

    ob->edit_light(i);
    return 1;
}

outdoors(str) {
    int o;
    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
    if(!sscanf(str,"%d",o)) return 0;
    if(o < 0 || o > 4) return 0;
    ob->set_outdoors(o);
    return 1;
}

add_desc(str) {
    string item,desc;
    int max,i,coloum,size;

    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }

    if(!parse_command(str,ob,"%s 'as' %s",item,desc)) return 0;
    if(!desc || desc == "") return 0;
    if(!item || item == "") return 0;
                       
    str = explode(desc," ");
    desc = "";
    max = sizeof(str);
    i = 0;
    coloum = 0;

    while(i < max) {
        size = strlen(str[i]);
        if((coloum + size) > SCREEN_WIDTH) {
            desc = desc + "\n";
            coloum = 0;
        }
        desc = desc + str[i] + " ";
        coloum = coloum + size + 1;
        i += 1;
    }
    desc = desc + "\n";

    ob->add_description(item,desc);
    return 1;
}

rm_desc(str) {
    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
    return ob->rm_description(str);
}

add_realm(str) {
    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
    if(!str || str == "") return 0;
    ob->add_realm(str);
    return 1;
}
                  
rm_realm(str) {
    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
    return ob->rm_realm(str);
}

add_exit(str) {
    string dir,file;

    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
    if(!parse_command(str,ob,"%w %s",dir,file)) return 0;
    if(!dir || dir == "") return 0;
    if(!file || file == "") return 0;
    ob->add_exit(file,dir);
    if(ob = environment(this_player())) move_object(this_player(),ob);
    return 1;
}

rm_exit(str) {
    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
    if(!(ob->rm_exit(str))) return 0;
    if(ob = environment(this_player())) move_object(this_player(),ob);
    return 1;
}

add_door(str) {
    string dir,file,type,key,link;

    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
   str = explode(str,"\"");
    if(!str) return 0;
    if(sizeof(str) != 3) return 0;
    if(!parse_command(str[0],ob,"%w %w %s",dir,file)) return 0;
    if(!parse_command(str[2],ob,"%w %w %w %s",type,key,link)) return 0;

    ob->add_door(file,dir,str[1],calc_type(type),calc_key(key),
                 0,calc_link(link));
    if(ob = environment(this_player())) move_object(this_player(),ob);
    return 1;
}

calc_type(str) {
    int i;

    if(str == "OPEN")    return 0;
    if(str == "CLOSED")  return 1;
    if(str == "LOCKED")  return 2;
    if(str == "AUTO")    return 3;
    if(str == "HIDDEN")  return 4;
    if(str == "HIDLOCK") return 5;
    if(str == "HIDAUTO") return 6;
    if(str == "SMASHED") return 7;
    if(sscanf(str,"%d",i)) return i;
    return 1;
}

calc_key(str) {
    int i;

    if(!str) return 0;
    if(str == "NONE") return 0;
    if(sscanf(str,"%d",i)) return i;
    return 0;
}

calc_link(str) {
    int i;

    if(!str) return 0;
    if(str == "ONEWAY") return -1;
    if(str == "TWOWAY") return 0;
    if(sscanf(str,"%d",i)) return i;
    return 0;
}

rm_door(str) {
    if(!ob) {
        write("You are not editing any room.\n");
        return 2;
    }
    if(!(ob->rm_door(str))) return 0;
    if(ob = environment(this_player())) move_object(this_player(),ob);
    return 1;
}

/* AUTOMATIC SEQUENCING */

auto_sequence1() {
    write("Automatic editing sequence initiated.\n");
    write("Name of file : ");
    input_to("auto_sequence2");
    return 1;
}

auto_sequence2(str) {
    if(create(str) != 1) {
        write("Automatic editing sequence aborted.\n");
        return 1;
    }
    edit(str);
    write("Short description : ");
    input_to("auto_sequence3");
    return 1;
}

auto_sequence3(str) {
    set_short(str);
    write("Long description : ");
    input_to("auto_sequence4");
   return 1;
}

auto_sequence4(str) {
    set_long(str);
    write("Degree of outdoorness : ");
    input_to("auto_sequence5");
    return 1;
}

auto_sequence5(str) {
    outdoors(str);
    write("Number of artificial light sources : ");
    input_to("auto_sequence6");
    return 1;
}

auto_sequence6(str) {
    light(str);
    write("Automatic editing sequence ended.\n");
    return 1;
}

/* FILE SUPPORT ROUTINES */

static update_room() {
    string str,x;
    object bag,thing,next_thing;

        str = file_name(ob);
    sscanf(str, "%s#%s", str,x);

    bag = clone_object("obj/container");
    thing = first_inventory(ob);
    while (thing) {
        next_thing = next_inventory(thing);
        move_object(thing, bag);
        thing = next_thing;
    }
    destruct(ob);

    move_object(bag,str);
    thing = first_inventory(bag);
    while (thing) {
        next_thing = next_inventory(thing);
        move_object(thing, str);
        thing = next_thing;
    }
    destruct(bag);
}

static new_file(file) {
    write("Creating file : " + file + "\n");
    write_file(file,TOPLINE + "\n");
    write_file(file,"inherit \"room/room\";\n\n");
    write_file(file,"setup() {\n");
    write_file(file,"    short_desc = \"An empty room\";\n");
    write_file(file,"    long_desc = \"This is an empty room \" +\n" +
               "        \"generated with The Rod of Room Alteration.\";\n");
   /* write_file(file,"    outdoorness = 0;\n");*/
    write_file(file,"    set_light(1);\n");
   /* write_file(file,"    artificial_light = 1;\n");*/
    write_file(file,"}\n\n");
    write_file(file,BASELINE);
}

static query_save(str) {
    string file,rest,line;
    int n;

    str = lower_case(str);
    if(str != "y" && str != "yes") return 1;

        file = "/" + file_name(ob) + ".c";
    rest = "/* ";
    n = 1;
    while(line = read_line(file,n)) {
        rest = rest + line;
        n += 1;
    }
    rest = rest + " */";
    update_file(file,rest);
    return 1;
}

static update_file(file,rest) {
    cp(file,file + "~");
    rm(file);
        write("Saving : /"+file_name(ob) + ".c\n");
    write_file(file,TOPLINE + "\n");
    write_file(file,"inherit \"room/room\";\n\n");
    write_file(file,"setup() {\n");
    ob->dump_room(file);
    write_file(file,"}\n\n");
    write_file(file,BASELINE);
    write_file(file,rest);
    rm(file + "~");
} 
