#include "../x.h"

inherit N_EFUN;
inherit CLEAN;

status dug;
string creator;
string location;

string *exits;

void reset(status x)
{
 if(x) return;
 exits = ({ });
 set_no_clean(1);
}

status id(string str)
{
 return (str == "hole" || str == HOLE_ID || str == "dark hole");
}

string short()
{
 string x;
 if(query_verb() == "peek")
  return 0;
 if(TP)
 {
  if(ENVTP == ENVTO)
  {
   if(!dug) return 0;
   x = "A dark hole has been dug in the ground here";
   if(MASTER->is_rat(TP))
    x += ".\nType '"+HIB+"hole"+NORM+"' to enter";
  }
  else
   x = "An earthen tunnel";
 }
 else
  x = "Error, contact X";
 return x;
}

void long()
{
 string x;
 if(TP)
 {
  if(ENVTP == ENVTO)
  {
   if(!dug) return 0;
   x = "\
A dark hole has been dug into the ground here.\n"+
"Occasionally, a "+HIB+"blue light"+NORM+" glimmers faintly above it.\n";
   if(MASTER->is_rat(TP))
    x += "Type '"+HIB+"hole"+NORM+"' to enter.\n";
  }
  else if(ENVTO)
   x = "\
An earthen tunnel dug by "+CAP(creator)+", one of the "+HIK+"Rats of NIMH"+NORM+".\n"+
"Above, you see "+(string)ENVTO->short()+".\n";
  if(sizeof(exits))
  {
   int y, z;
   string *nms, c;
   z = sizeof(exits);
   nms = ({ });
   for(y = 0; y < z; y += 2)
    nms += ({ shorten_exit(exits[y]) });
   c = implode(nms, ",");
   x += HIB+"Hole Exits: ["+NORM+c+HIB+"]\n"+NORM;
  }
 }
 if(!x) 
  x = "\
An earthen tunnel dug by "+CAP(creator)+
", one of the "+HIK+"Rats of NIMH"+NORM+".\n"+
"This tunnel's surface exit has been destroyed.\n";
 
 tell_object(TP, x);
}

void init()
{

 if(ENVTP == TO)
 {
  add_action("cmd_peek", "peek");
  add_action("cmd_climb","climb");
   add_action("cmd_exit"); add_xverb("");
 }

 else
  add_action("cmd_hole", "hole");
}

int cmd_hole(string str)
{
 if(str) return 0;

 if(!MASTER->is_rat(TP))
 {
  write(
   HIB+"Blue light flashes!\n"+NORM+
       "Some kind of magical shield prevents your entry.\n");
  return 1;
 }
 write("\n\t\
You hop down into the hole.\n\n");
 say((string)TP->QN+" hops down into the hole.\n");
 MO(TP, TO);
 command("look", TP);
 return 1;
}

int cmd_peek(string str)
{
 if(str) return 0;

 if(!location || catch(location->load_me()))
 {
  write("Bad location.\nYou cannot climb out.\n");
  return 1;
 }
 write("\n");
 if(!dug)
 {
  write("\tYou tunnel to the surface.\n");
  say((string)TP->QN+" digs a quick little hole above "+possessive(TP)+" head.\n");
  TR(location, "A hole suddenly appears in the ground.\n");
  dug = 1;
 }

 write("\tYou peek out of the hole...\n\n");

 say((string)TP->QN+" pokes "+possessive(TP)+" head out of the hole.\n");
 MO(TP, location);
 command("look", TP);
 say((string)TP->QN+" pokes "+possessive(TP)+" head out of the hole.\n");
 say((string)TP->QN+" disappears beneath the hole.\n");
 MO(TP, TO);
 say((string)TP->QN+" hops back inside the hole.\n");
 return 1;
}


int cmd_climb(string str)
{
 if(str) return 0;

 if(!location || catch(location->load_me()))
 {
  write("Bad location.\nYou cannot climb out.\n");
  return 1;
 }
 write("\n");
 if(!dug)
 {
  write("\tYou tunnel to the surface.\n");
  say((string)TP->QN+" digs a quick little hole above "+possessive(TP)+" head.\n");
  TR(location, "A hole suddenly appears in the ground.\n");
  dug = 1;
 }
 write("\tYou climb out of the hole...\n\n");
 say((string)TP->QN+" scrambles out of the hole.\n");
 MO(TP, location);
 command("look", TP);
 say((string)TP->QN+" scrambles out of the hole.\n");
 return 1;
}

void set_creator(string x) { creator = x; }
string query_creator() { return creator; }
void set_location(string x){ location = x; }
string query_location() { return location; }

status query_nimh_hole()
{
 return 1;
}

void set_dug(int x) { dug = x; }
int query_dug() { return dug; }

int cmd_exit(string str)
{
 int x;
 if(!str) return 0;
 x = member_array(elongate_exit(str), exits);
 if(x == -1)
  x = member_array(shorten_exit(str), exits);
 if(x > -1)
 {
  TP->MP(str+"#"+exits[x+1]);
 return 1;
 }
 return 0;
}

void add_exit(string dir, string file)
{
 int x;
 if((x=member_array(dir,exits)) > -1)
 exits[x+1] = file;
 else exits += ({ dir, file });
}

string query_exit(string dir)
{
 int x;
 if((x=member_array(dir, exits)) > -1)
  return exits[x+1];
}



