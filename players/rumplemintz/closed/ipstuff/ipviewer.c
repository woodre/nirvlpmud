inherit "/players/rumplemintz/closed/ipstuff/ipfuns.c";

#include <ansi.h>

#define IPSTORE "/players/rumplemintz/closed/ipstuff/ip_store.c"
#define IPLIST "players/rumplemintz/closed/ipstuff/iplist"

string *names;    /* Array of names */
string *ips;      /* Array of IP Addresses */

void reset(status arg) {
  if (arg)
    return;
}

string short() {
  return "MASTER IP Collector";
}

void long() {
  write("\n"+short()+"\n");
}

int id(string str) {
  return str == "IPS" || str == "screen";
}

int query_weight() { return 10000; }
int query_value()  { return 0; }
int get()          { return 0; }

status update_iplist() {
  int x, pos;
  mapping current_map;
  mixed *current_array;

  names = ({ });
  ips   = ({ });
  restore_object(IPLIST);
  current_map = ([ ]);
  current_map = IPSTORE->query_map();
  current_array = ({ });
  current_array = deconstruct_mapping(current_map);

  for (x=1; x<sizeof(current_array); x = x+2) {
    pos = check_ip(current_array[x], ips);
    if (pos > -1 && pos < 100) {
      if (names[pos] != current_array[x-1] && ips[pos] != current_array[x]) {
        names = update_array(pos, current_array[x-1], names);
        ips = update_array(pos, current_array[x], ips);
        save_object("/players/rumplemintz/closed/ipstuff/iplist");
      }
    }
  }
  call_out("update_iplist", 10800);
  return 1;
}

void init() {
  add_action("view", "view");
  add_action("allips", "allips");
}

void display_map(mapping m) {
  int x, y, asize, *values;
  string *indices, *s_names;

  indices = keys(m);
  values = m_values(m);
  values = sort_array(values);
  s_names = allocate(sizeof(indices));
  for (x=0; x<sizeof(indices); x++) {
    y=0;
    while((y<sizeof(values)) && (m[indices[x]] != values[y])) y++;
    s_names[y] = indices[x];
    values[y] = -1;
  }
  values = m_values(m);
  values = sort_array(values);
  if (sizeof(s_names) < 100)
    asize = sizeof(s_names);
  else asize = 15;
  for (x=0; x<asize; x++)
    write("\t"+pad(s_names[x],16)+values[x]+"\n");
}
int view(string str) {
  int x;
  mapping current_map;
  if (str)
    return 0;
  say(this_player()->query_name() + " looks at the display.\n");
  write("\n"+HIR+"------------------------------\n");
  write("  "+YEL+"IP List"+NORM+"\n");
  write(HIR+"------------------------------"+NORM+"\n");
  write(BOLD+"\tPLAYER\t\tIP"+NORM+"\n");
  current_map = ([ ]);
  current_map = IPSTORE->query_map();
  display_map(current_map);
  write(HIR+"------------------------------"+NORM+"\n");
  return 1;
}


status allips(string str) {
  if (str == "update") {
    update_iplist();
    write("Update complete.. all ip addresses saves.\n");
    return 1;
  }
  if (str == "reset") {
    names = ({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p",
              "q","r","s","t","u","v","w","x","y","z","a","b","c","d","e","f",
              "g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v",
              "w","x","y","z","a","b","c","d","e","f","g","h","i","j","k","l",
              "m","n","o","p","q","r","s","t","u","v","w","x","y","z","a","b",
              "c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r",
              "s","t","u","v","w"});
ne
nw
    scores = ({ 100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,
                80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,
                59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,
                38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,
                17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 });
    save_object("/players/rumplemintz/closed/ipstuff/iplist");
    write("IP List reset.\n");
    return 1;
  }
  if (str == "backup") {
    command("cp /players/rumplemintz/closed/ipstuff/iplist.o
                /players/rumplemintz/closed/ipstuff/iplist.bak");
    write("Backup complete.\n");
    return 1;
  }
  else {
    write("<allips update/reset/backup>\n");
    return 1;
}

void remove_object(object prev) {
  update_alltime();
}
