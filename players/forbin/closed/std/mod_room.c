/* 
 *  This is a modified /room/room.c that converts the long() to color
 *  -Forbin
 */

#include "/room/clean.c"
#include "/players/forbin/define.h"
/*
 * This is a proposal of a replacement to std.h. It is used with
 * 'inherit "room/room";'.
 * All global variables below are supposed to be setup by the reset()
 * in the function that inherits this file.
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


init() {
    int i;
    object ob;
    if (!dest_dir)
	return;
    if(query_property("fight_area"))
      if((ob=this_player()) && (ob->is_player()))
        ob->set_fight_area();
    if(query_property("spar_area"))
      if((ob=this_player()) && (ob->is_player()))
        ob->set_spar();
    i = 1;
    while(i < sizeof(dest_dir)) {
	add_action("move", dest_dir[i]);
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

/*
 *  long() has been modified to make everything HIK -Forbin 
 */

long(str) {
    int i;
    if ((set_light(0) <= 0) && !present("dark_sight_object", this_player())) {
       write(HIK+"It is dark.\n"+NORM);
       return;
    }
    if (!str) {
	write(HIK+long_desc+NORM);
if(!dest_dir || no_exits)
	    write(HIK+"    No obvious exits.\n"+NORM);
	else {
	    i = 1;
	    if (sizeof(dest_dir) == 2)
		write(HIK+"    There is one obvious exit:");
	    else
		write(HIK+"    There are " + convert_number(sizeof(dest_dir)/2) +
		      " obvious exits:");
	    while(i < sizeof(dest_dir)) {
		write(HIK+" " + dest_dir[i]+NORM);
		i += 2;
		if (i == sizeof(dest_dir) - 1)
		    write(HIK+" and");
		else if (i < sizeof(dest_dir))
		    write(",");
	    }
	    write("\n"+NORM);
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
    if(member_array(str, property) > -1)
      return 1;
    return 0;
}

set_property(str) { property=str; }

add_property(str)
{
    if(!str) return;
    if(!property)
      property=str;
    if(stringp(property))
      property=({ property, str });
    if(pointerp(property))
      property += ({ str });
}

remove_property(str)
{
    if(!str) return;
    if(stringp(property) && (property==str))
      property=0;
    if(pointerp(property))
    {
      if(member_array(str, property) > -1)
        property -= ({ str });
      if(!sizeof(property))
        property = 0;
    }
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
    /* <= conversion by verte 9.14.01 */
    if (set_light(0) > 0)
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

query_short() { return short_desc; }

realm()
{
    if(query_property("no_teleport")) return "NT";
    if(query_property("no_follow")) return "LA";
}

okay_follow()
{
    if(realm() == "NT" || query_property("no_follow")) return 0;
    return 1;
}

exit(ob)
{
    if(query_property("fight_area") && ob)
      ob->clear_fight_area();
    if(query_property("spar_area") && ob)
      ob->rm_spar();
}

query_no_fight()
{
    return query_property("no_fight");
}

query_spar_area()
{
    return query_property("spar_area");
}

query_NM()
{
    return query_property("no_magic");
}
