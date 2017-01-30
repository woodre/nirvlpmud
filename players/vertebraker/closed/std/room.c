/* (c) 2000 */

#include "/players/vertebraker/define.h"

int no_exit_display;

inherit "/room/room";

mapping ExitMsgs;
string *smells, *listens, *tastes, *touchs, *msgs, *objects;
int msg_count, hb, search_count, no_teleport, pk, spar, no_magic, no_fight;
static int playing, num, guys;

init()
{
   ::init();
   if(TP && TP->is_player() && pk && TP->query_guild_name() != "polymorph")
      TP->set_fight_area();
   if(TP && TP->is_player()) guys ++;
   if(!playing)
      { 
      while(remove_call_out("room_msg") != -1);
      call_out("room_msg",1); 
      playing = 1; 
   }
}

mixed exit(mixed ob)
{
   if(ob && ob->is_player()) guys--;
   if(!guys) {
     while(remove_call_out("room_msg") != -1);
     playing = 0;
   }
   if(pk) ob->clear_fight_area();
   if(spar) ob->rm_spar();
  return ::exit(ob);
}

void
set_exits(string * e)
{
    dest_dir = e;
}

void
set_items(string *i)
{
    items = i;
}


void room_msg()
{
   int x;
   x = random(msg_count);
   if(!hb) return;
   if(hb > random(100)) 
   {
     object *inv;
     int y;
     y = sizeof(inv = all_inventory(this_object()));
     while(y --)
       tell_object(inv[y], msgs[x]+"\n");
  }
   while(remove_call_out("room_msg") != -1);
     call_out("room_msg", 1);
}

mixed
move(string str)
{
    string dir, *m;

    if(!ExitMsgs) ExitMsgs = ([ ]);
    if((m = ExitMsgs[(dir = query_verb())]) && sizeof(m))
      write(m[0]);
      if(sizeof(m) > 1) 
        say((string)this_player()->query_name() + " " + m[1]);
    
    return ::move(str);
}

void
add_exit_msg(string where, mixed arg)
{
    string *d, e;
    if(!ExitMsgs) ExitMsgs = ([ ]);
    if(pointerp(arg))
      d = arg;
    else if(stringp(arg))
      e = arg;

    if(d) ExitMsgs[where] = d;
    else if(e)
    {
      if(!(ExitMsgs[where])) ExitMsgs[where] = ({ });
      ExitMsgs[where] += ({ e });
    }
}

void
set_exit_msgs(mapping Msgs)
{
    ExitMsgs = Msgs;
}

add_object(str, times)
{ 
   int x;
   if(times)
      for(x = 0; x < times; x++)
   move_object(clone_object(str), this_object());
   if(!times) move_object(clone_object(str), this_object());
   else move_object(clone_object(str), this_object());
}

void add_msg(string tmp) 
{
  if(tmp && tmp != "") {
   if(tmp[strlen(tmp)-1] == '\n')
     tmp = tmp[0..strlen(tmp)-2];
  }
  tmp = strip_prepending_spaces(tmp, 0, 1);
   if(!msgs) 
      msgs = ({ });
   msgs += ({ tmp, }); 
   msg_count += 1; 
}

void add_exit(string destination, mixed direction) 
{
   if(!dest_dir) dest_dir = ({ });
   dest_dir += ({ destination, direction, }); 
}

int
remove_exit(string direction)
{
    int i;
    if(!dest_dir) return 1;
    if((i = member_array(direction, dest_dir)) != -1)
      dest_dir -= ({ dest_dir[i-1], dest_dir[i + 1] });
return 1;
}

void add_item(mixed info, string desc) 
{
   int x;
   string *tmp;
   if(!items) items = ({ });
   tmp = ({ });
   if(stringp(info)) 
      tmp = ({ info });
   else tmp = info;
  if(creator(this_object()) == "stardream") {
  }
   for(x = 0; x < sizeof(tmp); x++) 
     items += ({ tmp[x], strip_prepending_spaces(desc,0,1) });
}

void set_long(string str) 
{ 
   long_desc = strip_prepending_spaces(str, 1);
}

void set_short(string str) 
{ 
   short_desc = str; 
}

void set_chance(int ch) 
{ 
   hb = ch; 
}

void add_property(string str) 
{
   if(str == "PK") pk = 1;
   if(str == "SPAR") spar = 1;
   if(str == "NM") no_magic = 1;
   if(str == "NT") no_teleport = 1;
   if(str == "NF") no_fight = 1; 
   ::add_property(str);
}

void remove_property(string str) 
{
   if(str == "PK") pk = 0;
   if(str == "SPAR") spar = 0;
   if(str == "NM") no_magic = 0;
   if(str == "NT") no_teleport = 0;
   if(str == "NF") no_fight = 0; 
   ::remove_property(str);
}

string realm() 
{
   if(no_teleport) return "NT"; 
}

int query_no_fight() 
{
   return no_fight; 
}

int query_spar_area() 
{
   return spar; 
}

int query_NM() 
{
   return no_magic; 
}

varargs void long(string str)
{
    if(!str && no_exit_display) return write(long_desc);
    else if(str)
    {
      int i;
      if(pointerp(items) && (i = member_array(str,items)) > -1)
      {
        int z;
        mixed punc;
        string temp;

        /* 05/24/06 Earwax: added this at Linus' behest. */
        if (items[i+1][0..0] == "@")
        {
          temp = items[i+1][1..(strlen(items[i+1])-1)];
          i = member_array(temp, items);
        }
        z = strlen(items[i+1]);
        if(items[i+1][z-1] == 10)    /* yay ascii code */
        {
          items[i+1] = items[i+1][0..(z-2)];
          z = strlen(items[i+1]);
        }
        if((punc = items[i+1][z-1]) != '.' &&
           punc != '?' &&
           punc != '!')
         {
          items[i+1] += ".";
         }

        return write(items[i+1]+"\n");
      }
    }
    return ::long(str);
}

status
cmd_look(string str)
{
    int x, a;
    object *inv, Room;

    if(!dest_dir || !str || !sizeof(dest_dir)) return 0;
    switch(str)
    {
      case "ne": str = "northeast"; break;
      case "nw": str = "northwest"; break;
      case "sw": str = "southwest"; break;
      case "se": str = "southeast"; break;
      case "s": str = "south"; break;
      case "n": str = "north"; break;
      case "e": str = "east"; break;
      case "w": str = "west"; break;
      case "d": str = "down"; break;
      case "u": str = "up"; break;
    }
    if((a = member_array(str, dest_dir)) != -1)
    {
      write("You look to the " + dest_dir[a] + "...\n");
      say((string)this_player()->query_name() + "\
 looks to the " + dest_dir[a] + "...\n");
      Room = find_object(dest_dir[a--]);
      if(!Room) dest_dir[a]->load_file();
      Room = find_object(dest_dir[a]);
      Room->long();
      inv = all_inventory(Room);
      for(x = 0; x < sizeof( inv ); x ++)
        if(inv[x]->short()) write(inv[x]->short() + ".\n");
      return 1;
    }
}

string
query_long()
{
    return long_desc;
}

status silent_leave(string dest)
{
  if(!ExitMsgs) return 0;
  return (member_array(dest,keys(ExitMsgs)) > -1);
}
