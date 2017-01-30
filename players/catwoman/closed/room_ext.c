inherit "room/room";

string entrance_message, exit_message;

set_long(str) {
   long_desc=str+"\n";
}

set_short(str) {
   short_desc=str;
}

set_entrance_message(str) {
   entrance_message=str;
}

set_exit_message(str) {
   exit_message=str;
}

add_exit(dest,dir) {
   if(dest_dir) dest_dir+=({dest,dir});
   else dest_dir=({dest,dir});   
}

nix_exits() {
   dest_dir=0;
}

add_item(item,desc) {
   if(items) items+=({item,desc});
   else items=({item,desc});
}

long(str) {
    int i;
    if (set_light(0) == 0){
       write("It is dark.\n");
       return;
    }
    if (!str) {
	write(long_desc);
if(!dest_dir || no_exits)
	    write("-- No obvious exits.\n");
	else {
	    i = 1;
	    if (sizeof(dest_dir) == 2)
		write("-- There is one obvious exit:");
	    else
		write("-- There are " + convert_number(sizeof(dest_dir)/2) +
		      " obvious exits:");
	    while(i < sizeof(dest_dir)) {
		write(" " + dest_dir[i]);
		i += 2;
		if (i == sizeof(dest_dir) - 1)
		    write(" and");
		else if (i < sizeof(dest_dir))
		    write(",");
	    }
	    write("\n");
	}
	return;
    }
    if (!items)
	return;
    i = 0;
    while(i < sizeof(items)) {
	if (items[i] == str) {
	    write(items[i+1] + "\n");
	    return;
	}
	i += 2;
    }
}

move(str) {
    int i;
    object ob;

    if(exit_message) write(exit_message+"\n");
    i = 1;
    while(i < sizeof(dest_dir)) {
	if (query_verb() == dest_dir[i]) {
	    say(capitalize(this_player()->query_name())+" "+this_player()->query_msgout()+
	    " "+dest_dir[i]+".\n");
	    move_object(this_player(),dest_dir[i-1]);
	    say(capitalize(this_player()->query_name())+" "+this_player()->query_msgin()+
	    ".\n");
            if (call_other(this_player(), "query_level")>20) 
               write(file_name(environment(this_player()))+"\n");
            if (call_other(this_player(), "query_brief")) {
               write(environment(this_player())->short()); write("\n"); }
	    else {
    	       environment(this_player())->long();
	    }
	    ob = first_inventory(environment(this_player()));
	    while(ob) {
	       if (ob != this_player()) {
	          string short_str;
	          short_str = call_other(ob, "short");
	          if (short_str)
	          write(short_str + ".\n");
	       }
	       ob = next_inventory(ob);
	    }
	    return 1;
	}
	i += 2;
    }
}

reset(arg) {
   if(arg) return;
}

init() {
   ::init();
   if(entrance_message) write(entrance_message+"\n");
}
