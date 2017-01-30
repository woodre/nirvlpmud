
inherit "/room/room";
#include "/room/clean.c"
string *dest_dir;
string short_desc;
string long_desc;
string *items;
string property;
int no_castle_flag;
int no_exits;
int indoors;
int is_pk;
int no_fight;
int no_magic;
int no_teleport;

reset(arg) {

}

init() {
    int i;
    if (!dest_dir)
        return;
    i = 1;
    while(i < sizeof(dest_dir)) {
        add_action("cmd_move", dest_dir[i]);
        i += 2;
    }

    if(is_pk && (int)this_player()->query_level() > 10) this_player()->set_fight_area();
    
    add_action("cmd_report","typo");
    add_action("cmd_report","bug");
    add_action("cmd_report","idea");
    add_action("search","search");
    add_action("cmd_listen","listen");
    add_action("cmd_smell","smell");
}

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

int set_pk(int x) {
  is_pk=x;
  return 1;
}
query_pk() {
  return is_pk;
}


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


/* Atmosphere commands */
int search(string str) {
  notify_fail("You find nothing special.\n");
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
  say(this_player()->query_name()+" sniffs in an attempt to smell something.\n");
  return 1;
}


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
