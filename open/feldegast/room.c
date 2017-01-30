/*
 * Standard Room Object (file: /players/feldegast/std/room.c")
 * By Feldegast/Christopher Smith
 * Last updated 9-14-98
 * Modified from Nirvana's standard room object
 */

/* This causes the room to delete itself after a certain ammount of time */
#include "/room/clean.c"

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

/* Blanks the exit descriptions 'No obvious exits' */
int no_exits;

/* Is this an indoor or outdoor room? */
int indoors;

/* Is this room pk? */
int is_pk;

/* Can players fight here? */
int no_fight;

/* Can spells be cast here? */
int no_magic;

/* Can players teleport from here? */
int no_teleport;

reset(arg) {

}

/* Called when player enters room */
init() {
    int i;
    if (!dest_dir)
	return;
    i = 1;
    while(i < sizeof(dest_dir)) {
	add_action("cmd_move", dest_dir[i]);
	i += 2;
    }

    if(is_pk && (int)this_player()->query_level() > 6) this_player()->set_fight_area();
    
    add_action("cmd_report","typo");
    add_action("cmd_report","bug");
    add_action("cmd_report","idea");
    add_action("search","search");
    add_action("cmd_listen","listen");
    add_action("cmd_smell","smell");
}

/* Called when player leaves room */
exit() {
  if(this_player() && this_player()->is_player())
  this_player()->clear_fight_area();
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

long(str) {
    int i;
    if (set_light(0) == 0){
       write("It is dark.\n");
       return;
    }
    if (!str) {
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
    if(!items) return;
    i = 0;
    while(i < sizeof(items)) {
	if (items[i] == str) {
        if(items[i+1]=="reflexive")
          long(0);
        else
          write(items[i+1] + ".\n");
	    return;
	}
	i += 2;
    }
}

/* Basic attributes */
string query_short() {
  return short_desc;
}
string query_long() {
  return long_desc;
}
query_dest_dir() {
    return dest_dir;
}
query_items() {
  return items;
}
query_indoors() {
  return indoors;
}
int query_drop_castle() {
    return no_castle_flag;
}

/* Sets */
void set_short(string str) {
  short_desc=str;
}
void set_long(string str) {
  long_desc=str;
}
void set_dest_dir(string *x) {
  dest_dir=x;
}
void set_items(string *x) {
  items=x;  
}
void set_indoors(int x) {
  indoors=x;
}
/* Properties */

/* Is this room pk? */
int set_pk(int x) {
  is_pk=x;
  return 1;
}
query_pk() {
  return is_pk;
}

/* Can you fight in this room? */
int set_no_fight(int x) {
  no_fight=x;
  return 1;
}
query_no_fight() {
  return no_fight;
}

int set_no_magic(int x) {
  no_magic=x;
  return 1;
}
int query_NM() {
  return no_magic;
}

int set_no_teleport(int x) {
  no_teleport=x;
  return 1;
}
realm() {
  if(no_teleport) return "NT";
  if(no_magic) return "NM";
}

/*
 * Does this room have a special property ?
 * The 'property' variable can be both a string and array of strings.
 * If no argument is given, return the 'property' variable.
 * Note: I've never seen this used, so I might remove it... -Feld
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

/* Commands */
cmd_move(str) {
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

/* Logging functions for reporting bugs-typos-idea. */

int cmd_report(string str) {
  write_file("/players/feldegast/log/feedback.log",
    ctime(time())+" "+capitalize((string)this_player()->query_real_name())+
    " reported a "+query_verb()+" from\n"+
   object_name(this_object())+":\n"+
    str+"\n");
  write("Your suggestion has been forwarded to Feldegast.\n"+
	"Thank you for helping to make this a better area.\n");
  return 1;
}

/* Atmosphere commands */
int search(string str) {
  notify_fail("You find nothing.\n");
  say(this_player()->query_name()+" searches around the room.\n");
  return 0;
}

int cmd_listen(string str) {
  write("You listen carefully.\n");
  say(this_player()->query_name()+" stops and listens carefully.\n");
  return 1;
}

int cmd_smell(string str) {
  write("You sniff.\n");
  say(this_player()->query_name()+" sniffs.\n");
  return 1;
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
	if (object_name(this_object()) == "room/room")
	    numbers = ({"no", "one", "two", "three", "four", "five",
			    "six", "seven", "eight", "nine" });
	else
	    numbers = call_other("room/room", "query_numbers");
    }
    return numbers;
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

