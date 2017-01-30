#include "/room/clean.c"

/* variables */
string *dest_dir;
string short_desc;
string long_desc;
mapping items;
string *property;
string *room_emotes;
int etime_const; /* number of seconds definately between every emote */ 
int etime_rand;  /* random number of seconds added to time_const */
int time_to_next_emote; /* number of seconds until next emote */
int no_castle_flag;
int no_exits;

/* function declarations */
string exit_string(int n);
string translate_exit(string str);
mixed query_numbers();


string trans_desc(string str) {
  string str1,str2,str3;
  while(sscanf(str,"%s$&%s$&%s",str1,str2,str3) && str2) {
    str=(str1?str1:"")+
    (stringp(str2=(mixed)call_other(this_object(),str2))?str2:"")+
    (str3?str3:"");
  }
  return str;
}
void init() {
  int i,size;
  if(etime_const && room_emotes && sizeof(room_emotes))
    set_heart_beat(1);
  if (!dest_dir)
    return;
  size=sizeof(dest_dir);
  for(i=1; i<size; i+=2)
    add_action("move", dest_dir[i]);
}
int id(string str) {
  string temp;
  if (!items)
    return 0;
  if(items[str]) return 1;
}
void long(string str) {
  string desc;
  if(set_light(0) <= 0 && !present("dark_sight_object", this_player())) {
    write("It is dark.\n");
    return;
  }
  if (!str) {
    write(format(trans_desc(long_desc),75));
    if(!dest_dir || no_exits)
      write("    No obvious exits.\n");
    else {
      write(exit_string(sizeof(dest_dir)/2));
      write("\n");
      return;
    }
  }
  if (!items)
    return;
  if(desc=items[str]) {
    string alt_desc;
    if(sscanf(desc,"@%s",alt_desc)==1)
       long(alt_desc);
    else
       write(format(trans_desc(desc),75));
    return;
  }
}
void set_long(string str) { long_desc=str; }
void set_short(string str) { short_desc=str; }
void add_exit(string str1,string str2) {
  if(!dest_dir) dest_dir=({});
  dest_dir += ({str2,str1});
}
void remove_exit(string dir) {
  int n;
  string dest;
  n=member_array(dir,dest_dir);
  if(n=-1) return;
  dest=dest_dir[n-1];
  dest_dir-=({dir});
  dest_dir-=({dest});
}
void set_exits(mixed narf) { dest_dir=narf; }
int add_item(string item,string desc) {
  if(!items) items= ([]);
  if(items[item]) items[item]=desc;
  else items+= ([item:desc]);
  return 1;
}
int remove_item(string item) {
  if(items[item]) {
#ifdef __LDMUD__
    m_delete(items, item);
#else
    deletem(items,item);
#endif
    return 1;
  }
  return 0;
}

/*
 * Does this room has a special property ?
 * The 'property' variable can be both a string and array of strings.
 * If no argument is given, return the 'property' variable.
 */
mixed query_property(string str) {
    if (str == 0)
        return property;
    if (!property)
        return 0;
    return (member_array(str,property) != -1);
}
int move(string str) {
  int i;
  if((i = member_array(query_verb(),dest_dir)) != -1) {
    this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
    return 1;
  }
  return 0;
}

string short() {
  int i;
  string temp;
    if(set_light(0) > 0 || ( this_player() && environment(this_player()) == this_object() && present("dark_sight_object",this_player() ) ) )
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

mixed query_dest_dir() {
    return dest_dir;
}

string query_long() {
    return long_desc;
}

/* uses number code from /room/room */
string numbers;

mixed convert_number(int n) {
    if (!pointerp(numbers))
        numbers = query_numbers();
    if (n > 9)
        return "many";
    return numbers[n];
}

mixed query_numbers() {
  return call_other("room/room", "query_numbers");
}

int query_drop_castle() {
    return no_castle_flag;
}
string exit_string(int n) {
  string str;
  int size,i;
  if(n==1)
    return "    There is one obvious exit: "+dest_dir[1];
  else {
    size=sizeof(dest_dir);
    str="    There are " + convert_number(n) + " obvious exits:";
    for(i=1;i<size-2;i+=2)
      str+=(" "+ dest_dir[i]+",");
    str+=" and "+dest_dir[size-1];
  }
  return str;
}
/* Room emote functions.  Eliminates the need for an invisible monster to
 * make emotes display in the room, and shuts down when the room is empty
 * of PCs, just like a monster's heartbeat based emotes
 */

void set_etime_const(int t) {
  etime_const=t;
}
void set_etime_rand(int t) {
  etime_rand=t;
}
void add_room_emote(string emote) {
  if(!room_emotes) room_emotes = ({});
  room_emotes+=({emote});
  set_heart_beat(1);
}
void remove_room_emote(string emote) {
   if(!room_emotes) return;
   room_emotes-=({emote});
   if(sizeof(room_emotes) == 0) set_heart_beat(0);
}
status test_any_here() {
  object *inv;
  int i,x;
  inv=all_inventory(this_object());
  i=sizeof(inv);
  for(x=0;x<i;x++)
     if(inv[x]->is_player())
        return 1;
  return 0;
}
void heart_beat() {
  if(!test_any_here() || !etime_const || !room_emotes) {
     set_heart_beat(0);
     return;
  }
  if(time_to_next_emote <= 0) {
     time_to_next_emote = etime_const+random(etime_rand);
     tell_room(this_object(),format(room_emotes[random(sizeof(room_emotes))]));
  } else {
     time_to_next_emote-=3;
  }
}
