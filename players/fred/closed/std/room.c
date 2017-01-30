/* (c) 2000 */

#include "/obj/security.h"  /* For PLAYER_ID define - Rumplemintz */
#include "/players/vertebraker/define.h"

inherit "/room/room";

mapping ExitMsgs;
string *smells, *listens, *tastes, *touchs, *msgs, *objects;
int msg_count, hb, search_count, no_teleport, pk, spar, no_magic, no_fight;
int no_follow;
int playing, num, guys;

init()
{
   ::init();
   if(TP && TP->is_player() && pk && TP->query_guild_name() != "polymorph")
      TP->set_fight_area();
   if(TP && TP->is_player()) guys ++;
   if(!playing)
      { 
      while(find_call_out("room_msg") != -1) remove_call_out("room_msg");
      call_out("room_msg",1); 
      playing = 1; 
   }
   add_action("cmd_look","l");
   add_action("cmd_smell","smell");
   add_action("cmd_listen","listen"); 
   add_action("cmd_taste","taste"); 
   add_action("cmd_touch","touch");
   add_action("cmd_search","search"); 
   add_action("cmd_look","look");
   add_action("cmd_look","glance");
}

int exit(mixed ob) 
{
   if(ob->is_player()) guys--;
   if(!guys) while(find_call_out("room_msg") != -1) remove_call_out("room_msg");
   if(pk) ob->clear_fight_area();
   if(spar) ob->rm_spar();
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
   if(hb > random(100)) 
      tell_room(this_object(), msgs[x]+"\n");
   while(find_call_out("room_msg") != -1) remove_call_out("room_msg");
   if(present(PLAYER_ID, this_object()))   /* Rumplemintz - 10/26/07 */
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
    if(!dest_dir) return 0;
    if((i = member_array(direction, dest_dir)) != -1)
      dest_dir -= ({ dest_dir[i-1], dest_dir[i + 1] });
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
   for(x = 0; x < sizeof(tmp); x++) 
   items += ({ tmp[x], desc });
}

int add_smell(string what, string mess)
{
   int z;
   if(!smells) smells = ({ });
   z = strlen(what);
   if(what[z-1] == 10)
      what = what[0..(z-2)];
   smells += ({ what, mess, }); 
}

int add_listen(string what, string mess)
{
   if(!listens) listens = ({ });
   listens += ({ what, mess, });
}

int add_touch(string what, string mess)
{
   if(!touchs) touchs = ({ });
   touchs += ({ what, mess, }); 
}

int add_taste(string what, string mess)
{
   if(!tastes) tastes = ({ });
   tastes += ({ what, mess, }); 
}

int cmd_search(string str) 
{
   if(!str) write("You search generally, but find nothing.\n");
   else write("You search the "+str+", but find nothing.\n");
   say(TPN+" searches the area.\n");
   return 1;
}

int cmd_taste(string str) 
{
   int x;
   if(!str)
      {
      write("Taste what?\n");
      return 1;
   }
   if(!tastes) tastes = ({ });
   if((x = member_array(str,tastes)) != -1)
      write(tastes[x+1]+"\n");
   else write("You taste "+str+", but detect nothing out of the ordinary.\n");
   return 1; 
}

int cmd_listen(string str) 
{
   int x;
   
   if(!listens) listens = ({ });
   if(!str)
      {
      if((x = member_array("main",listens)) == -1)
         write("You don't hear anything.\n");
      else
         write(listens[x+1]+"\n");
   }
   
   else
      {
      str = LOWER(str);
      if((x = member_array(str,listens)) == -1)
         write("You listen intently to "+str+", but don't hear anything.\n");
      else
         write(listens[x+1]+"\n");
   }
   say(TPN+"'s ears perk up.\n");
   return 1;
}

int cmd_smell(string str) 
{
   int x;
   
   if(!smells) smells = ({ });
   if(!str)
      {
      if((x = member_array("main",smells)) == -1)
         write("You don't smell anything.\n");
      else
         write(smells[x+1]+"\n");
   }
   
   else
      {
      str = LOWER(str);
      if((x = member_array(str,smells)) == -1)
         write("You don't detect any unusual odours from "+str+".\n");
      else 
         write(smells[x+1]+"\n");
   }
   say(TPN+"'s nostrils flare.\n");
   return 1;
}

int cmd_touch(string str) 
{
   int x;
   
   if(!touchs) touchs = ({ });
   if(!str)
      {
      write("Touch what?\n");
      return 1;
   }
   if((x = member_array(str,touchs)) != -1)
      write(touchs[x+1]+"\n");
   else write("You touch "+str+", but don't feel anything strange.\n");
   return 1; 
}

void set_long(string str) 
{ 
   long_desc = str; 
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
   if(str == "LA") no_follow = 1;
}

void remove_property(string str) 
{
   if(str == "PK") pk = 0;
   if(str == "SPAR") spar = 0;
   if(str == "NM") no_magic = 0;
   if(str == "NT") no_teleport = 0;
   if(str == "NF") no_fight = 0; 
   if(str == "LA") no_follow = 0;
}

string realm() 
{
   if(no_teleport) return "NT"; 
   if(no_follow) return "LA";
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


void long(string str) 
{
   int      i, v, z;
   string   p, c;
   if(set_light(0) == 0)
      {
      write("It is dark.\n");
      return;
   }
   if(!str) 
      {
      write(long_desc);
      if(!dest_dir || no_exits)
         write("    No obvious exits.\n");
      else {
         i = 1;
         if(sizeof(dest_dir) == 2)
            write("    There is one obvious exit:");
         else
            write("    There are " + convert_number(sizeof(dest_dir)/2) +
            " obvious exits:");
         while(i < sizeof(dest_dir)) 
         {
            write(" " + dest_dir[i]);
            i += 2;
            if(i == sizeof(dest_dir) - 1)
               write(" and");
            else if(i < sizeof(dest_dir))
               write(",");
         }
         write("\n");
      }
      return;
   }

   if(!items)
      return;
   i = 0;
   str = lower_case(str);
   if((i = member_array(str,items)) != -1)
      {
      z = strlen(items[i+1]);
      if(items[i+1][z-1] == 10)    /* yay ascii code */
         {
         items[i+1] = items[i+1][0..(z-2)];
         z = strlen(items[i+1]);
      }
      if(items[i+1][z-1] != '.' &&
            items[i+1][z-1] != '?' &&
         items[i+1][z-1] != '!')
      items[i+1] += ".";
      write(items[i+1]+"\n");
      return;
   }
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
