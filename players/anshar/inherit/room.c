#include "/room/clean.c"
/*
 * This is a proposal of a replacement to std.h. It is used with
 * 'inherit "room/room";'.
 * All global variables below are supposed to be setup by the reset()
 * in the function that inherits this file.
   Added set_room_type()  - see the variable below.
         read_mess = ({})  so you can set up a read command that works
                           like the items setup.  "sign", "Test sign.\n"....

 */

/* An array with destinations and directions: "room/church", "north" ... */
string *dest_dir;

/* Short description of the room */
string short_desc;

/* Long description of the room */
string long_desc;

/* Special items in the room. "table", "A nice table", "window", "A window" */
string *items;

/* Fact about this room. ex: "no_fight", "no_steal" */
string property;

/* No castles are allowed to be dropped here */
int no_castle_flag;
int no_exits;

/* What type of room is this: Plain, Forest, Cave, City, Mountain, Hill, Water, Desert 
added by Maledicta*/
string room_type;

/* A setup for reading objects in the room. 
added by Maledicta*/
string *read_mess;

/* A setup for searching objects in the room. 
added by Anshar*/
string *search_items;
string search_room;
int room_search;

/* A setup for listening to objects in the room. 
added by Anshar*/
string *listen_items;
string listen_room;
int room_listen;

/* A setup for smelling objects in the room. 
added by Anshar*/
string *smell_items;
string smell_room;
int room_smell;

init() {
   int i; 
   if (read_mess) {
        add_action("read","read");
    }
   if (room_search) {
        add_action("search","search");
    }
   if (room_listen) {
        add_action("listen","listen");
    }
   if (room_smell) {
        add_action("smell","smell");
    }
    if (!dest_dir)
	return;
    i = 1;
    while(i < sizeof(dest_dir)) {
	add_action("move", dest_dir[i]);
	i += 2;
    }
}

read(string str){
int i;
while(i < sizeof(read_mess)) {
    if(read_mess[i] == str){
	    write(read_mess[i+1]+"\n");
	    return 1;  }
    i += 2;
    }	    
}

search(string str){
int i;
if(!str) {
    if(search_room) {
      write(search_room+"\n");
      return 1;  }
    write("What do you want to search?\n");
    return 1; }
while(i < sizeof(search_items)) {
    if(read_mess[i] == str){
	    write(search_items[i+1]+"\n");
	    return 1;  }
    i += 2;
    }	    
}

listen(string str){
int i;
if(!str) {
    if(listen_room) {
      write(listen_room+"\n");
      return 1;  }
    write("To what do you want to listen?\n");
    return 1; }
while(i < sizeof(listen_items)) {
    if(read_mess[i] == str){
	    write(listen_items[i+1]+"\n");
	    return 1;  }
    i += 2;
    }	    
}

smell(string str){
int i;
if(!str) {
    if(smell_room) {
      write(smell_room+"\n");
      return 1;  }
    write("What do you want to smell?\n");
    return 1; }
while(i < sizeof(smell_items)) {
    if(read_mess[i] == str){
	    write(smell_items[i+1]+"\n");
	    return 1;  }
    i += 2;
    }	    
}

id(str) {
    int i;
    if (!items)
	return;
    while(i < sizeof(items)) {
	if (items[i] == str)
	    return 1;
	i += 2;
    }
    return 0;
}

long(str) {
    int i;
    if (set_light(0) == 0){
       write("It is dark.\n");
       return;
    }
    if (!str) {
        if(short_desc)
        write(short_desc+"\n");
	write(long_desc);
if(!dest_dir || no_exits)
	    write("    No obvious exits.\n");
	else {
	    i = 1;
	    if (sizeof(dest_dir) == 2)
		write("    There is one obvious exit:");
	    else
		write("    There are " + convert_number(sizeof(dest_dir)/2) +
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
	    write(items[i+1] + ".\n");
	    return;
	}
	i += 2;
    }
}

/*
 * Does this room has a special property ?
 * The 'property' variable can be both a string and array of strings.
 * If no argument is given, return the 'property' variable.
 */
query_property(str) {
    int i;
    if (str == 0)
	return property;
    if (!property)
	return 0;
    if (stringp(property))
	return str == property;
    while(i < sizeof(property)) {
	if (property[i] == str)
	    return 1;
	i += 1;
    }
    return 0;
}

move(str) {
    int i;

    i = 1;
    while(i < sizeof(dest_dir)) {
	if (query_verb() == dest_dir[i]) {
	    this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
	    return 1;
	}
	i += 2;
    }
}

short() {
  int i;
  string temp;
    if (set_light(0))
	{
	  temp = short_desc + " [";
	  if (!dest_dir || no_exits) temp += "no exits";
	  else
	    for (i=1;i<sizeof(dest_dir);i+=2)
                {
	          temp += translate_exit(dest_dir[i]);
                  if (i < sizeof(dest_dir)-2) temp += ",";
		}
	  temp += "]";
          return temp;
	}
    return "Dark room";
}

translate_exit(str) {
  if (str == "north") return "n";
  if (str == "south") return "s";
  if (str == "east") return "e";
  if (str == "west") return "w";
  if (str == "northeast") return "ne";
  if (str == "northwest") return "nw";
  if (str == "southeast") return "se";
  if (str == "southwest") return "sw";
  if (str == "up") return "u";
  if (str == "down") return "d";
  return str;
}

query_dest_dir() {
    return dest_dir;
}

query_long() {
    return long_desc;
}

/*
 * Convert a number to a word. The array is being created by the
 * standard room/room, and shared by all rooms.
 */
string numbers;

convert_number(n) {
    if (!pointerp(numbers))
	numbers = query_numbers();
    if (n > 9)
	return "lot of";
    return numbers[n];
}

query_numbers() {
    if (!numbers) {
	if (file_name(this_object()) == "room/room")
	    numbers = ({"no", "one", "two", "three", "four", "five",
			    "six", "seven", "eight", "nine" });
	else
	    numbers = call_other("room/room", "query_numbers");
    }
    return numbers;
}

query_drop_castle() {
    return no_castle_flag;
}


set_room_type(string str){ room_type = str; }

query_room_type(){
string str;
if(!room_type) return str == "none"; 
return room_type;
}
