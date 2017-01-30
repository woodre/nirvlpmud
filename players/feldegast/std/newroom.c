#include "/room/clean.c"
#pragma strict_types
#pragma save_types
/* Feldegast's room object
 * This is a modified version of /room/room.c
 * The important thing to remember about this code is that the
 * really complicated and confusing stuff with mappings is probably
 * borrowed, and the lazy but simple stuff is probably mine.
 */

/* An array with destinations and directions: "room/church", "north" ... */
string *dest_dir;

/* Short description of the room */
string short_desc;

/* Long description of the room */
string long_desc;

/* Special items in the room. "table", "A nice table", "window", "A window" */
mapping items;

/* Fact about this room. ex: "no_fight", "no_steal" */
mixed property;

/* No castles are allowed to be dropped here */
int no_castle_flag;
int no_exits;

/* Is this room pk? */
int is_pk;

/* Can I teleport from here? */
int no_tp;

/* Can I cast spells from here? */
int no_magic;

void reset(int arg) {
  items=([ ]);
}

void init() {
    int i;
    if (!dest_dir)
	return;
    i = 1;
    while(i < sizeof(dest_dir)) {
	add_action("move", dest_dir[i]);
	i += 2;
    }

    if(is_pk) this_player()->set_fight_area();
    /* These commands are for reporting bugs, etc. */
    add_action("cmd_report","typo");
    add_action("cmd_report","bug");
    add_action("cmd_report","idea");

    /* Atmospheric commands */
    add_action("search","search");
    add_action("cmd_listen","listen");
    add_action("cmd_smell","smell");
}

int exit() {
  if(is_pk) 
    this_player()->clear_fight_area();
}

void id(string str) {
  return items[str];
}

string short() {
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

void long(string str) {
    int i;
    if (set_light(0) == 0){
       write("It is dark.\n");
       return;
    }
    else {
      if(str) {
        string s;
        if(s=items[str]) {
          if(closurep(s)) s=funcall(s,str);
          if(stringp(s)) write(s);
        }
      }
      else {
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
    
}

}

int move(string str) {
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


string translate_exit(string str) {
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

/*
 * Queries
 */

string *query_dest_dir() {
    return dest_dir;
}

/*
 * Does this room has a special property ?
 * The 'property' variable can be both a string and array of strings.
 * If no argument is given, return the 'property' variable.
 */

mixed query_property(string str) {
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

string query_long() {
    return long_desc;
}
int query_pk() {
  return is_pk;
}

int query_drop_castle() {
    return no_castle_flag;
}


/*
 * Sets
 */
void set_short(string str) {
  short_desc=str;
}
void set_long(string str) {
  long_desc=str;
}

void set_pk(int num) {
  is_pk=num;
}

void set_items(mapping m)
{
    int         i, j;
    mixed       *ks;

    i = sizeof(ks = m_indices(m));
    while (i--) add_item(ks[i], m[ks[i]]);
}

void add_item(mixed id, string desc)
{
  int j;

  if (pointerp(id)) {
    j = sizeof(id);
    while (j--) items[id[j]] = desc;
  }
  else items[id] = desc;
}

void remove_item(mixed id)
{
    int         j;

    if (pointerp(id)) {
	j = sizeof(id);
	while (j--) m_delete(Items, id[j]);
    }
    else m_delete(Items, id);
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


/* Logging functions for reporting bugs-typos-idea. */

cmd_report(str) {
  write_file("/players/feldegast/log/feedback.log",
    ctime(time())+" "+capitalize(this_player()->query_real_name())+
    " reported a "+query_verb()+" from\n"+
   file_name(this_object())+":\n"+
    str+"\n");
  write("Your suggestion has been forwarded to Feldegast.\n"+
        "Thank you for helping to make this a better area.\n");
  return 1;
}

search(str) {
  write("You find nothing.\n");
  say(this_player()->query_name()+" searches around the room.\n");
  return 1;
}

cmd_listen(str) {
  write("You listen carefully.\n");
  say(this_player()->query_name()+" stops and listens carefully.\n");
  return 1;
}

cmd_smell(str) {
  write("You sniff.\n");
  say(this_player()->query_name()+" sniffs.\n");
  return 1;
}

