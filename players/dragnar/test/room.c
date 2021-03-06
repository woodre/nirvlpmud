
query_light(){
  return set_light(0);
}
/*
 * Nirvana Room Inherit
 * Authored by Vertebraker@Nirvana
 * <tmieczkowski@gmail.com>
 * Started: 8-27-03
 *
 */ 

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
mixed property;

/* No castles are allowed to be dropped here */
int no_castle_flag;

/* No exits shown flag */
int no_exits;

/* Custom exits flag */
int custom_exits;

/* Handling number of exits */
string *numbers;

/* Call out Function */
string call_out_func;

/* Call out Interval */
int call_out_int;
int call_out_int_rand;

/* Keeping track of players in the room */
static int player_count;

#include "/room/lib/func.h"
#include "/room/lib/sensory.h"

void init()
{
 int i;
 object enteringPlayer;
 enteringPlayer = this_player();


 if(this_object()->query_property("fight_area") && enteringPlayer->is_player())
  enteringPlayer->set_fight_area();

 if(this_object()->query_property("spar_area") && enteringPlayer->is_player())
  enteringPlayer->set_spar();

 /* Increase player_count if entering player is not an npc */
 if( enteringPlayer->is_player() ) {
   player_count++;
   if( call_out_func && call_out_int && find_call_out( call_out_func ) == -1) 
     call_out( call_out_func, call_out_int + (call_out_int_rand ? random(call_out_int_rand) : 0) );
 }

 if(!dest_dir) return;
 i = 1;
 while(i < sizeof(dest_dir))
 {
  add_action("move", dest_dir[i]);
  i += 2;
 }
}

string convert_dir(string str) {
  switch(str) {
    case "n": return "north";
    case "e": return "east";
    case "s": return "south";
    case "w": return "west";
    case "sw": return "southwest";
    case "se": return "southeast";
    case "nw": return "northwest";
    case "ne": return "northeast";
    case "d": return "down";
    case "u": return "up";
  }
  return str;
}

status id(string str)
{
 return ((items && member_array(str, items) > -1) || 
     (dest_dir && member_array(convert_dir(str), dest_dir) > -1));
}

int check_light() {
  return set_light(0);
}

varargs void long(string str, int rec_check)
{
 int i;
 string item;
 
 if ((set_light(0) <= 0) && !present("dark_sight_object", this_player()))
 {
  write("It is dark.\n");
  return;
 }
 if (!str)
 {
  write(long_desc);
  if(custom_exits)
   return;
  if(!dest_dir || no_exits)
   write("    No obvious exits.\n");
  else
  {
   int s;
   i = 1;
   if ((s=sizeof(dest_dir))==2)
    write("\
    There is one obvious exit:");
   else
    write("\
    There are "+(string)this_object()->convert_number(s/2)+" obvious exits:");
   while(i < s)
   {
    write(" " + dest_dir[i]);
    i += 2;
    if (i == s-1)
     write(" and");
    else if (i < s)
     write(",");
   }
   write("\n");
  }
  return;
 }
  /***********************************************************
  * Updated by Gnar to include references to other items
  * "tree","Long tree description"
  * "trees","&tree&"
  * "forest","&tree&"
  ***********************************************************/
  if(items && (i = member_array(str, items)) > -1) {
    if(sscanf(items[i+1], "&%s&", item) == 1 && rec_check < 5) {
      return long(item , ++rec_check );
    }
    write(items[i+1]+".\n");
  }
 else { /* converted from Vertebraker's look <dir> code by Illarion */
  int a, x;
  object room;
  string file;
  string vb;
  object *inv;
  str=convert_dir(str);
  if(!str || (a = member_array(str, dest_dir)) == -1) {
    return 0;
  }
  room=find_object(dest_dir[a-1]);
  if(!room) {
    file=dest_dir[a-1];
    if(file[0..0]!="/") file="/"+file;
#ifndef __LDMUD__ /* Rumplemintz */
    if(file[-2..-1]!=".c")
#else
    if (file[<2..<1] != ".c")
#endif
     file = file + ".c";
   vb = catch(call_other(file,"???"));
   if((string)this_player()->query_real_name()=="vertebraker")
   {
     write("\n"+vb+"\n");
   }
  if(vb)
 {
      write("A warping of space prevents you from looking "+str+".\n");
      return;
    }
  }
  write("\t\t\tYou look "+str+"...\n\n");
  say((string)this_player()->query_name()+" looks to the "+str+"...\n");
  if(dest_dir[a-1]->check_light()+set_light(0) <= 0 &&
      !present("dark_sight_object",this_player())) {
    write("It is dark.\n");
    return;
  }
  dest_dir[a-1]->long();
  inv = all_inventory(find_object(dest_dir[a-1]));
  for(x = 0; x < sizeof( inv ); x ++)
    if(inv[x]->short()) write(inv[x]->short() + ".\n");
 }
}

/* add_item/exit and remove_item/exit by illarion may 2005 */
void add_item(string name,string desc) {
  int s;
  if(!name || !desc) return;
  if(!items) items=({name,desc});
  else if((s=member_array(name,items))!=-1)
    items[s+1]=desc;
  else
    items+=({name,desc});
}

status remove_item(string name) {
  int s,siz;
  if(!items || !name) return 0;
  if((s=member_array(name,items))==-1)
    return 0;
  siz=sizeof(items);
  items=(s==0?({}):items[0..s-1])+(s+2==siz?({}):items[s+2..siz-1]);
  return 1;
}
    
void add_exit(string path,string dir) {
  int s;
  if(!path || !dir) return;
  if(!dest_dir) dest_dir=({path,dir});
  else if((s=member_array(dir,dest_dir))!=-1)
    dest_dir[s-1]=path;
  else
    dest_dir+=({path,dir});
}

status remove_exit(string dir) {
  int s,siz;
  if(!dest_dir || !dir) return 0;
  if((s=member_array(dir,dest_dir))==-1)
    return 0;
  siz=sizeof(dest_dir);
  dest_dir=(s==1?({}):dest_dir[0..s-2])+(s+1==siz?({}):dest_dir[s+1..siz-1]);
  return 1;
}

/*
 * Does this room has a special property ?
 * The 'property' variable can be both a string and array of strings.
 * If no argument is given, return the 'property' variable.
 */

mixed query_property(string str)
{
 int i;

 if (!str)
  return property;
 if (!property)
  return 0;
 if (stringp(property))
  return str == property;

 if(pointerp(property))
 return (member_array(str, property) > -1);
}

void set_property(mixed str)
{
 property = str;
}

void add_property(mixed str)
{
 if(!str)
  return;
 if(!property)
  property=str;
 if(stringp(property))
  property=({ property, str });
 if(pointerp(property))
  property += ({ str });
}

void remove_property(mixed str)
{
 if(!str)
  return;
 if(stringp(property) && property==str)
  property=0;
 if(pointerp(property))
 {
  if(member_array(str, property) > -1)
   property -= ({ str });
  if(!sizeof(property))
   property = 0;
 }
}

status move(string str)
{
 int i;
 if((i = member_array(query_verb(), dest_dir)) > -1)
 {
  /* 08/07/07 Earwax: ghetto fix for mages doing hit/run tactic */
  if ((string)this_player()->query_guild_name() == "mage"
  && (int)present("spellbook", this_player())->query_cmd_count_max())
  {
   write("You are still recovering from spellcasting and can't move yet!\n");
   return 1;
  }
  this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
  return 1;
 }
}

string short()
{
 int i, s;
 string temp;
 /* <= conversion by verte 9.14.01 */
 if ((set_light(0) > 0) || (this_player() && environment(this_player()) == this_object() && present("dark_sight_object", this_player())))
 {
  temp = short_desc + " [";
  if (!dest_dir || no_exits) temp += "no exits";
  else if ((s=sizeof(dest_dir)) >= 12) temp += "many exits";
  else
   for (i=1;i<s;i+=2)
   {
    temp += (string)this_object()->translate_exit(dest_dir[i]);
    if (i < s-2)
     temp += ",";
   }
  temp += "]";
  return temp;
 }
 return "Dark room";
}

string translate_exit(string fullDirection)
{
 switch(fullDirection)
 {
  case "north":     return "n";
  case "south":     return "s";
  case "east":      return "e";
  case "west":      return "w";
  case "northeast": return "ne";
  case "northwest": return "nw";
  case "southeast": return "se";
  case "southwest": return "sw";
  case "up":        return "u";
  case "down":      return "d";
  default:          return fullDirection;
 }
  return 0; /* Rumplemintz */
}

status query_drop_castle() { return no_castle_flag; }
string query_short() { return short_desc; }
string * query_dest_dir() { return dest_dir; }
string * query_items() { return items; }
string query_long() { return long_desc; }

string convert_number(int inputNum)
{
 if (!pointerp(numbers))
  numbers = (string*)this_object()->query_numbers();
 if (inputNum > 9)
  return "lot of";
 return numbers[inputNum];
}

string * query_numbers()
{
 if (!numbers)
 {
#ifndef __LDMUD__ /* Rumplemintz */
  if (file_name(this_object()) == "room/room")
#else
  if (object_name(this_object()) == "room/room")
#endif
   numbers = ({"no", "one", "two", "three", "four", "five",
	         "six", "seven", "eight", "nine" });
  else
   numbers = (string*)"/room/room"->query_numbers();
 }
 return numbers;
}

string realm()
{
 if(query_property("no_teleport")) return "NT";
 if(query_property("no_follow")) return "LA";
 return 0; /* Rumplemintz */
}

status okay_follow()
{
 if(realm() == "NT" || query_property("no_follow")) return 0;
 return 1;
}

#ifndef __LDMUD__ /* Rumplemintz */
varargs status exit(object exitingPlayer)
#else
varargs void exit(object exitingPlayer)
#endif
{
 if(query_property("fight_area") && exitingPlayer)
  exitingPlayer->clear_fight_area();
 if(query_property("spar_area") && exitingPlayer)
  exitingPlayer->rm_spar();
 if (exitingPlayer) exitingPlayer->invs_counter();

 if(exitingPlayer && exitingPlayer->is_player()) {
   player_count--;
   if( player_count <= 0 && call_out_func )
      while(remove_call_out( call_out_func) != -1);
 }
}

status query_no_fight() { return query_property("no_fight"); }
status query_spar_area() { return query_property("spar_area"); }
status query_NM() { return query_property("no_magic"); }

reset() { }  /* left in for solidarity */



set_dest_dir(x) { dest_dir = x; }
set_items(x) { items = x; }

set_short(x) { short_desc = x; }
set_long(x) { long_desc = x; }

set_call_out( string co, int interval, int rand_interval ) {
  if( !co && (!interval || !rand_interval) )
    return;

  call_out_func = co;
  call_out_int = interval;
  call_out_int_rand = rand_interval; 
}
