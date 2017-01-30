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
   if(dest_dir) {
      if(member_array(dir,dest_dir)!=-1) {
         del_exit(dir);
         add_exit(dest,dir);
         return 1;
      }      
      dest_dir+=({dest,dir});
   } else dest_dir=({dest,dir});   
}

nix_exits() {
   dest_dir=0;
}

add_item(item,desc) {
   if(items) {
      if(member_array(item,items)!=-1) {
         del_item(item);
         add_item(item,desc);
         return 1;
      }      
      items+=({item,desc});
   } else items=({item,desc});
}

del_item(item) {
   int i;
   string temp;
   
   i=member_array(item,items);
   if(i==-1) return;
   if(!i) {
      temp=items[2..sizeof(items)];
      items=temp;
      if(sizeof(items)<1) items=0;
      return 1;
   }
   temp=items[0..(i-1)]+items[(i+2)..sizeof(items)];
   items=temp;
   return 1;
}

del_exit(exit) {
   int i;
   string temp;
   
   i=member_array(exit,dest_dir);
   if(i==-1) return;
   if(i==1) {
      temp=dest_dir[2..sizeof(dest_dir)];
      dest_dir=temp;
      if(sizeof(dest_dir)<1) dest_dir=0;
      return 1;
   }
   temp=dest_dir[0..(i-2)]+dest_dir[(i+1)..sizeof(dest_dir)];
   dest_dir=temp;
   return 1;
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

/* Some of this is in ::move(), but it needed to be modified. */
move(str) {
    int i;
    object ob;

    if(!dest_dir || ((i = member_array(str, dest_dir)) == -1)) return;
    if(exit_message) write(exit_message+"\n");
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

reset(arg) {
   if(arg) return;
}

init() {
   if(entrance_message) write(entrance_message+"\n");
#ifndef __LDMUD__ /* Rumplemintz */
   add_action("move"); add_xverb("");
#else
  add_action("move", "", 3);
#endif
}
