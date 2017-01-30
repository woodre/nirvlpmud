#include "/room/clean.c"
#include "/players/maledicta/ansi.h"
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

/* Mob or no Mob */
int mobbed;


int outside;

/* No castles are allowed to be dropped here */
int no_castle_flag;
int no_exits;

/* Day and Night 0= night 1= day */
int day;

/* What type of room is this: Plain, Forest, Cave, City, Mountain, Hill, Water, Desert */
string room_type;

/* A setup for reading objects in the room. */
string *read_mess;

init() {
   int i;
   add_action("shadow_peer", "peer");
   add_action("leave_here", "leave");
   add_action("shadow_help","shadow_help");
   
   if (read_mess) {
add_action("read", "read");
    }
    
    if (!dest_dir)
	return;
    i = 1;
    while(i < sizeof(dest_dir)) {
	add_action("move", dest_dir[i]);
	i += 2;
    }
}



shadow_peer(string str){
string place;
if(!str) return 0;
if(str == "outward"){
if(this_player()->query_attack()){
write("You are too distracted to do that!\n");
return 1;
}
place = find_dest();
tell_object(this_player(),
"    ---=====[You Peer Outward Through the Shadows]=====---\n\n");
tell_object(this_player(),
			place+"\n");
move_object(this_player(), "players/maledicta/cont/rooms/"+place+".c");
command("look", this_player());
move_object(this_player(), this_object());
tell_object(this_player(), 
""+HIR+"You grimace in pain as the Shadow plane and Prime Material pull at you!"+NORM+"\n");
this_player()->hit_player(10);
return 1; }
return 0;
}

shadow_help(){
write(
         "\t"+BOLD+""+BLK+"________________________ ["+HIR+"Shadow Realm"+BOLD+""+BLK+"] _______________________\n");
write(
BOLD+BLK+"\t The Realm of Shadows holds many mysteries, some of great power\n"+
         "\tand some of even greater danger. As you travel through this\n"+
         "\trealm know that your body is one with the prime material plane,\n"+
         "\tthis meaning that when in this realm movement of any kind can\n"+
         "\tcause you pain as the two realms vie for control of your very\n"+
         "\texistence.\n"+
         "\t When looking around and searching the plane of shadows, the\n"+
         "\tfirst thing to remember is that although you can see something\n"+
         "\tmost of the time it isn't really there. Items, buildings, roads,\n"+
         "\tetc. are nothing more than illusions of what you know. Looking\n"+
         "\tat them will only show their true nature, illusions. When\n"+
         "\tyou do finally encounter something substantial, then beware.\n"+
         "\tWhat you can feel can kill you.\n"+
         "\t When in the Shadow Realm know that you will have a certain\n"+
         "\tamount of control over the area you exist in. The following\n"+
         "\tare powers available for you to call upon:\n\n"+
         "\t "+HIB+"peer outward "+BOLD+""+BLK+"- Will allow you to see out of the shadow realm\n"+
         "\t                and into the room that it mimics in the prime\n"+
         "\t                material plane.\n"+
         "\t "+HIB+"leave shadows"+BOLD+""+BLK+" - When used this power will allow you to step\n"+
         "\t                 from the Shadow Plane, on a one way trip, to\n"+
         "\t                 the Prime Material. Such a movement and shock\n"+
         "\t                 to the system can leave a person with a con-\n"+
         "\t                 siderable amount of damage, so beware.\n"+
         "\tOther noteworthy items: \n"+
         "\tFollowing another player is impossible unless you use\n"+
         "\t'feelfollow'.\n"+
         "\tWhen in the Shadowplane you will be able to attack and be attacked\n"+
         "\tby other players("+HIR+"Pk Area"+NORM+""+BOLD+""+BLK+").\n");
write(   "\t_______________________________________________________________"+NORM+"\n");
return 1;
}         
          
leave_here(string str){
string place;
place = find_dest();
if(!str){ return 0; }
if(this_player()->query_attack()){
write("You are too distracted to do that!\n");
return 1;
}
if(str == "shadows"){
write("You concentrate and step from the shadow plane and into the Prime-material.\n");
move_object(this_player(), "players/maledicta/cont/rooms/"+place+".c");
command("look", this_player());
this_player()->hit_player(random(50));
tell_object(this_player(),
HIR+"You cry out in agony as you step from the Shadow plane back to your own reality!"+NORM+"\n");
return 1;
   }
return 0;
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
        write(""+BOLD+short_desc+"\n");
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
	    write("\n"+NORM+"");
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
