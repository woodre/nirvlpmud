#include "/room/clean.c"
#define CONTROLLER "/players/illarion/poke/room/vroomcon.c"
#define NUMBERS ({"zero","one","two","three","four","five","six","seven","eight","nine"})

/* variables */
string *dest_dir;
string short_desc;
string long_desc;
string spec_dir,spec_dest;   /* used for exiting the virtual grid */
mapping items;
string *property;
int no_exits;
int column,row;      /* where the room is */



void init() {
  int i,size;
  if (!dest_dir)
    return;
  size=sizeof(dest_dir);
  for(i=0; i<size; i++)
    add_action("move", dest_dir[i]);
  if(spec_dir)
    add_action("special_move",spec_dir);
}
int id(string str) {
  string temp;
  if (!items)
    return 0;
  if(items[str]) return 1;
}
mixed convert_number(int n) {
    if (n > 9)
        return "many";
    return NUMBERS[n];
}

string exit_string() {
  int x,size;
  string ret, *exits;
  exits=dest_dir;
  if(spec_dir) exits+=({spec_dir});
  size=sizeof(exits);
  if(size==1) return "There is one obvious exit: "+exits[0]+"\n";
  ret="There are "+(string)this_object()->convert_number(size)+" obvious exits: ";
  for(x=0;x<size-1;x++) ret+= exits[x]+", ";
  ret+="and "+exits[size-1]+"\n";
  return ret;
}
  
void long(string str) {
  string desc;
  if (set_light(0) == 0){
    write("It is dark.\n");
    return;
  }
  if (!str) {
    write(format(long_desc,75));
    if(!dest_dir || no_exits)
      write("    No obvious exits.\n");
    else {
      write(exit_string());
      return;
    }
  }
  if (!items)
    return;
  if(desc=items[str]) {
    write(format(desc,75));
    return;
  }
}
void set_long(string str) { long_desc=str; }
void set_short(string str) { short_desc=str; }
void create(int c, int r, string *exits) {
  dest_dir=exits;
  column=c;
  row=r;
  set_light(1);
}
void set_special_exit(string dir,string dest) {
  spec_dir=dir;
  spec_dest=dest;
}
int add_item(string item,string desc) {
  if(!items) items= ([]);
  if(items[item]) items[item]=desc;
  else items+= ([item:desc]);
  return 1;
}
int remove_item(string item) {
  if(items[item]) {
    deletem(items,item);
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

int move() {
  CONTROLLER->move_me(this_player(),column,row,query_verb());
  return 1;
}
special_move() {
  this_player()->move_player(spec_dir+"#"+spec_dest);
  return 1;
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

string short() {
  int i,size;
  string temp;
  string *exits;
  exits=dest_dir;
  if(spec_dir) exits+=({spec_dir});
    if (set_light(0))
        {
          temp = short_desc + " [";
          if (!dest_dir || no_exits) temp += "no exits";
          else {
            size=sizeof(exits);
            for (i=0;i<size-1;i++)
                  temp += translate_exit(exits[i])+",";
            temp+=translate_exit(exits[size-1]);
          }
          temp += "]";
          return temp;
        }
    return "Dark room";
}


mixed query_dest_dir() {
    return dest_dir;
}

string query_long() {
    return long_desc;
}

