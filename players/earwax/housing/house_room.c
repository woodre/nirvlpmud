/* ***************************************************************************
 * File:           /players/earwax/housing/house_room.c
 * Function:       House room inherit
 * Author:         Earwax
 * Copyright:      Copyright (c) 2004 Earwax.  All rights reserved.
 * Source:         5/22/04
 * Notes:          Don't read this if you don't like ugly ass code.
 * Change History:
 * **************************************************************************/

#include "defs.h"

#define DEBUG 1

inherit "/room/room.c";

/* Global Variables */
static status  Changes;
       string  Short1, Short2;
       string  FileName, Entrance;
       string *CloneIds, *CloneFiles, *CloneSettings;
       int     Light;
       object  Master;
       int     RoomNum;
       string  BaseFilename;
       status  LightToggle;
       string *Properties;
       
void
twax(string msg)
{
  object wax;
  
  wax = find_player("earwax");
  
  if (wax)
    tell_object(wax, HIG+"house_ROOM: "+msg+NORM+NORM);
  else
    write_file("/players/earwax/housing/TWAX", 
      (string)WAXFUNS->date_time()+": "+"house_object: "+msg);
}
/* ***************************************************************************
 * Function Name:  get_master
 * Description:    Get the house object
 * Arguments:      None
 * Returns:        None
 * **************************************************************************/
void
get_master()
{
  object ent;

  if (!Entrance || !strlen(Entrance))
    return;
    
  ent = find_object(Entrance);
  
  if (!ent)   /* CYA - Cover Yo Ass. */
  {
    Entrance->reset(0);
    ent = find_object(Entrance);
  }
  
  Master = present(HOUSING_OBJECT_ID, ent); 
}
/* ***************************************************************************
 * Function Name:  reset
 * Description:    Called on creation and resets
 * Arguments:      arg (0 for create, 1 for reset)
 * Returns:        void
 * **************************************************************************/
void
reset(status arg)
{
  ::reset(arg);
  
  if (arg)
    return;
    
  /* Initialize everything - just to be safe */
  Short1 = "Earwaxian House: "; Short2 = "";
  long_desc = "This room hasn't been described yet.\nType "+HIW+"hcommands"+NORM+NORM+" to see available commands.\n";
  dest_dir = ({ }); items = ({ });
  Properties = ({ });
  Entrance = FileName = "";
  CloneIds = ({ }); CloneFiles = ({ }); CloneSettings = ({ });
  Changes = 0;
  LightToggle = Light;
}
/* ***************************************************************************
 * Function Name:  command_hook
 * Description:    Route commands to the bin, do core checks
 * Arguments:      various
 * Returns:        status (0 for failure, 1 for success)
 * **************************************************************************/
status
command_hook(string arg)
{
  object master, ent;
  string verb, name;
  int cost;
  
  verb = query_verb();
  name = (string)this_player()->query_real_name();
  
  if (!Master)
    get_master();

  cost = (int)HOUSED->can_do_command(verb, this_player(), Master);      
  
  if (cost < 1)
  {
    if (name == "earwax")
      twax("Command hook override.\n");
    else
      return 0;
  }
    
  if ((status)(BIN+verb)->main(arg, this_object(), Master))
  {
    if (cost > 1)
    {
      write(cost+" gold has been deducted from your bank account.\n");
      this_player()->add_bank_balance(-cost);
      return 1;
    }
    
    return 1;
  }
  
  return 0;
}
/* ***************************************************************************
 * Function Name:  init
 * Description:    Actions to do on living entering
 * Arguments:      None
 * Returns:        Void
 * **************************************************************************/
void 
init()
{
  int i;
  string *commands;
  object ob;

  ::init(); 

  /*
   * Fear the necessary error checking.
   */
  if (!this_player() || !environment(this_player()) 
  || environment(this_player()) != this_object()
  || !strlen(Entrance))
    return;

  ob = find_object(Entrance);
  
  if (!ob)
  {
    Entrance->reset(0);
    ob = find_object(Entrance);
  }
  
  if (!ob)
  {
    twax("MAJOR PROBLEM IN HOUSE_ROOM init(): no Entrance found.\n");   
    return;
  }
  
  ob = present(HOUSING_OBJECT_ID, ob);

  if (!ob)
  {
    Entrance->reset(0);
    ob = present(HOUSING_OBJECT_ID, find_object(Entrance));
  }
/*  
  if (!((status)HOUSED->can_do_command(verb, this_player(), ob)))
  {
    if ((string)this_player()->query_real_name() == "earwax")
      twax("Init override\n");
    else
      return;
  }
*/
  i = sizeof(commands = (string *)HOUSED->get_commands());
  
  while(i--)
    add_action("command_hook", commands[i]);

}
/* ***************************************************************************
 * Function Name:  Room query/set functions
 * Description:    Player settable options
 * Arguments:      Various
 * Returns:        Various
 * **************************************************************************/
void set_short1(string arg) { Short1 = arg + NORM+NORM; }
void set_short(string arg) { Short2 = arg + NORM+NORM; }
string query_short1() { return Short1; }
string query_short2() { return Short2; }

void set_long(string arg) { long_desc = arg + NORM+NORM+"\n"; }
string query_long() { return long_desc; }

void set_filename(string arg) { FileName = arg; }
string query_filename() { return FileName; }

void set_entrance(string arg) { Entrance = arg; }
string query_entrance() { return Entrance; }

object query_master() { if (!Master) get_master(); return Master; }
string *query_exits() { return dest_dir; }
string *query_items() { return items; }

int set_light_level(int arg) { Light = arg; return set_light(Light-set_light(0)); }
int query_light_level() { return set_light(0); }
int query_light() { return Light; }

void set_room_num(int arg) { RoomNum = arg; }
void set_base_filename(string arg) { BaseFilename = arg; }
int query_room_num() { return RoomNum; }

status 
toggle_lights()
{
  if (Light)
  {
    set_light(-1);
    LightToggle = 0;
    Light = 0;
    return 0;
  }
  
  set_light(1);
  LightToggle = 1;
  Light = 1;
  return 1;
}

status query_lights() { return (Light ? 1 : 0); }

int 
query_room_number() /* This is way ghetto - wouldn't work otherwise */
{ 
  string t, *t2; int i;

  if (BaseFilename && strlen(BaseFilename))
    return RoomNum;
      
  sscanf(FileName, "%s.c", t); 
  i = (sizeof(t2 = explode(t, "_")) - 1);
  sscanf(t2[i]+"", ""+"%d", i);
  return i;
}

string
query_base_filename()
{
  int i; 

  if (BaseFilename && strlen(BaseFilename))  
    return BaseFilename;
    
  i = strlen(FileName);
  
  while(i--)
    if (FileName[i] == '_')
      return FileName[0..(i)];
}  
  
string *get_all_rooms() {
  int i; string pattern, *t;
  
  sscanf(FileName, "%s.c", pattern);
  i = (sizeof(t = explode(pattern, "_")) - 2);
  pattern = implode(t[0..i], "_")+"_";
  return get_dir(pattern+"*.c");
}

void
reset_owner() 
{ 
  if (!Master) 
    get_master();
    
  Short1 = (string)Master->get_inside_short();
}

string short() { short_desc = (HIY+Short1+NORM+NORM+Short2); return ::short(); }
/* ***************************************************************************
 * Function Name:  long
 * Description:    Override long desc so items show up properly
 * Arguments:      string arg (item desc to look at)
 * Returns:        Void
 * **************************************************************************/
void
long(string arg)
{
  if (arg)
  {
    int i;
    
    if (sizeof(items))
    {
      i = member_array(arg, items) + 1;  
      
      if (i > 0 && (i < sizeof(items)))
      {
        write(items[i]+NORM+NORM+"\n");
        say((string)this_player()->query_name()+" looks at the "+arg+".\n");
        return;
      }
    }
  }

  if (!arg || arg == "" && (this_player() && (int)this_player()->query_brief() != 2))
      write(short()+"\n");
    
  ::long(arg);
}
/* ***************************************************************************
 * Function Name:  exit adding/removing/listing
 * Description:    Heh
 * Arguments:      Various
 * Returns:        status - 0 for failure, 1 for success
 * **************************************************************************/
int
add_exit(string dest, string dir)
{
  if (sizeof(dest_dir) && member_array(dir, dest_dir) > -1)
  {
    notify_fail("Exit already exists: "+dir+"\nRemove exit first to change.\n");
    return 0;
  }
  
  if (dest[0..1] == "//")
    sscanf(dest, "/%s", dest);
    
  dest_dir += ({ dest, dir });
  
  if (environment(this_player()) == this_object())
    init();

  return 1;
}

status
remove_exit(string dir)
{
  int i;

  if (!sizeof(dest_dir))
  {
    notify_fail("No exits defined.\n");
    return 0;
  }
    
  i = member_array(dir, dest_dir);
  
  if ( i <= 0)
  {
    notify_fail("Exit does not exist: "+dir+"\n");
    return 0;
  }

  if (query_room_number() == 0 && dir == "out")
  {
    notify_fail("The central 'out' exit may not be removed.\n");
    return 0;
  }
    
  dest_dir -= ({ dir, dest_dir[i - 1] });
  init();
  return 1;
}  
/* ***************************************************************************
 * Function Name:  Noun description adding/removing/listing
 * Description:    Self Explanatory
 * Arguments:      Various
 * Returns:        status - 0 for failure, 1 for success
 * **************************************************************************/
int
add_item(string item, string desc)
{
  if (sizeof(items) && member_array(item, items) > -1)
  {
    notify_fail("Item desc already exists: "+item+"\nRemove item first to change.\n");
    return 0;
  }
  
  items += ({ item, desc });
  init();
  return 1;
}

status
remove_item(string item)
{
  int i;
  
  i = member_array(item, items);
  
  if (sizeof(items) && i <= -1)
  {
    notify_fail("Item does not exist: "+item+"\n");
    return 0;
  }
  
  items -= ({ item, items[i+1] });
  init();
  return 1;
}
/* ***************************************************************************
 * Function Name:  add_prop, remove_prop, list_props
 * Description:    Add/remove/list properties of rooms.
 * Arguments:      Various
 * Returns:        status - 0 for failure, 1 for success
 * **************************************************************************/
varargs
void
activate_properties(string *t)
{
  int i;
  
  if (!t || !sizeof(t))
    t = Properties;
    
  i = sizeof(t);
  
  while(i--)
  {
    switch(lower_case(t[i]))
    {
      case "safe room property"      : add_property("no_fight"); break;
      case "no-follow property"      : add_property("no_follow"); break;
      case "no-teleport property"    : add_property("no_teleport"); break;
      case "pk room property"        : add_property("fight_area"); break;
      case "anti-magic property"     : add_property("no_magic"); break;
      case "spar-area property"      : add_property("spar_area"); break;
      case "prevent resets property" : set_no_clean(1);
    }
  }
}
void
deactivate_property(string arg)
{
  switch(lower_case(arg))
  {
    case "safe room property"      : remove_property("no_fight"); break;
    case "no-follow property"      : remove_property("no_follow"); break;
    case "no-teleport property"    : remove_property("no_teleport"); break;
    case "pk room property"        : remove_property("fight_area"); break;
    case "anti-magic property"     : remove_property("no_magic"); break;
    case "spar-area property"      : remove_property("spar_area"); break;
    case "prevent resets property" : set_no_clean(0);
  }
}  

status
add_prop(string what)
{
  if (!sizeof(Properties))
  {
    Properties = ({ what });
    return 1;
  }
  
  if (member_array(what, Properties) > -1)
  {
    notify_fail("That property already set.\n");
    return 0;
  }
  
  Properties += ({ what });
  activate_properties(({ what }));
  return 1;
}
status  
remove_prop(string what)
{
  if (!sizeof(Properties) || member_array(what, Properties) < 0)
  {
    notify_fail("That property is not set in this room.\n");
    return 0;
  }
  
  Properties -= ({ what });
  deactivate_property(what);
  return 1;
}
status 
query_prop(string what)
{
  return ((sizeof(Properties) && member_array(what, Properties) > -1) ? 1 : 0);
}
string *query_properties() { return Properties; }
/* ***************************************************************************
 * Function Name:  add_clone, remove_clone, list_clone
 * Description:    Add the cloning of an item to a room
 * Arguments:      Various
 * Returns:        status - 0 for failure, 1 for success
 * **************************************************************************/
status
add_clone(string id, string filename, string text)
{
  if (!text || !strlen(text))
    text = "";  

  if (!sizeof(CloneIds))
  {
    CloneIds = ({ }); CloneFiles = ({ }); CloneSettings = ({ });
  }
  
  if (!id || !filename || !strlen(id) || !strlen(filename))
  {
    notify_fail("You "+HIR+"must"+NORM+NORM
      +" specify an object id and filename to clone here.\n");
    return 0;
  }

#ifdef DEBUG
write("Sizeof Clone Arrays (Ids/Files/Settings): "
  +sizeof(CloneIds)+"/"+sizeof(CloneFiles)+"/"+sizeof(CloneSettings)+".\n");
write("ID: "+id+"\nFilename: "+filename+"\nSettings: "+text+"\n");
#endif

  CloneIds += ({ id });
  CloneFiles += ({ filename });
  CloneSettings += ({ ((text || strlen(text)) ? text : "") });
  
#ifdef DEBUG
write("Sizeof Clone Arrays (Ids/Files/Settings): "
  +sizeof(CloneIds)+"/"+sizeof(CloneFiles)+"/"+sizeof(CloneSettings)+".\n");
#endif
  
  return 1;
}

status
remove_clone(string arg)
{
  int i;
  
  if (!arg || !strlen(arg))
  {
    notify_fail("For remove_clone() to work, an id or filename "
      +HIR+"must"+NORM+NORM+" be given.\n");
    return 0;
  }
  
  if (!sizeof(CloneIds))
  {
    notify_fail("There are no objects currently on the clone list here.\n");
    return 0;
  }
  
  i = member_array(arg, CloneFiles);
  
  if (i < 0)
    i = member_array(arg, CloneIds);
    
  if (i < 0)
  {
    notify_fail("There isn't anything by that ID or filename on the clone list here.\n");
    return 0;
  }
#ifdef DEBUG
write("Sizeof Clone Arrays (Ids/Files/Settings): "
  +sizeof(CloneIds)+"/"+sizeof(CloneFiles)+"/"+sizeof(CloneSettings)+".\n");
#endif
  
  CloneIds -= ({ CloneIds[i] });
  CloneFiles -= ({ CloneFiles[i] });
  CloneSettings -= ({ CloneSettings[i] });
  
#ifdef DEBUG
write("Sizeof Clone Arrays (Ids/Files/Settings): "
  +sizeof(CloneIds)+"/"+sizeof(CloneFiles)+"/"+sizeof(CloneSettings)+".\n");
#endif

  return 1;
}

status
list_clones()
{
  int i, flag;
  
  i = sizeof(CloneIds);
  
  if (!i)
  {
    write("There isn't anything on the clone list.\n");
    return 1;
  }
  
  flag = ((int)this_player()->query_level() > 19);
  
  while(i--)
    write(pad(CloneIds[i], 20)+(flag ? CloneFiles[i]+"\n" : "\n"));
    
  return 1;
}
/* ***************************************************************************
 * Function Name:  save_info
 * Description:    Remove old room file, rewrite it.
 * Arguments:      none
 * Returns:        status - 0 for failure, 1 for success
 * **************************************************************************/
status
save_info()
{
  string text, *lines;
  int i, siz;
  
  write("... Saving Room Number: "+pad(RoomNum+" ", 3));
  
  /*
   * Remove the file.
   * Read Template in.
   * Write Template.
   */
  catch(rm(FileName)); /* Catch just in case of permission problems */

  /*
   * Write in the template info.
   * Then write in any special cloning that needs to go on.
   * This can potentially be some nasty shit.
   */
  write_file(FileName,
      "#include \"/players/earwax/housing/defs.h\"\n"
    + "\n"
    + "inherit HROOM;\n"
    + "void reset(status arg) {\n"
    + "::reset(arg);\n");
     
  siz = sizeof(CloneIds); /* 3 clone arrays had better stay synced */

  if (siz)
    write_file(FileName,
        "  CloneIds = ({ });\n"
      + "  CloneFiles = ({ });\n"
      + "  CloneSettings = ({ });\n\n");
      
  for (i = 0; i < siz; i++) 
  {   
    write_file(FileName, 
        "  CloneIds += ({ \""+CloneIds[i]+"\" });"
      + " CloneFiles += ({ \""+CloneFiles[i]+"\" });"  
      + " CloneSettings += ({ \""
      +    ((CloneSettings[i] || strlen(CloneSettings[i])) ? CloneSettings[i] : "")+"\" });\n"
      + "                                        \n"
      + "  if (!present(\""+CloneIds[i]+"\", this_object()))\n"
      + "  {\n"
      + "    object ob;\n\n"
      + "    ob = clone_object(\""+CloneFiles[i]+"\");\n"
      + "    if (ob)\n"
      + "    {\n"
      + "      move_object(ob, this_object());\n");
      
    if (strlen(CloneSettings[i]))
      write_file(FileName, CloneSettings[i]+"\n");
      
    write_file(FileName, "    }\n  }\n\n");
  }
  
  /*
   * Now for the standard setup shit
   */
  write_file(FileName, 
     "  if (arg) return;\n\n"
    +"  Light = "+Light+";\n"
    +"  LightToggle = (Light ? 1 : 0);\n"
    +"  set_light(Light);\n"
    +"  Short1 = \""+Short1+"\";\n"
    +"  Short2 = \""+Short2+"\";\n"
    +"  long_desc = \""+implode(explode(long_desc, "\n"), "\\n")+"\\n\";\n"
    +"  FileName = \""+FileName+"\";\n"
    +"  RoomNum = "+RoomNum+";\n"
    +"  BaseFilename = \""+BaseFilename+"\";\n"
    +"  Entrance = \""+Entrance+"\";\n"
    +"  get_master();\n");

  /*
   * Now add the properties of the room.
   */
  siz = sizeof(Properties);
  
  if (siz)
  {
    write_file(FileName, "  Properties = ({ ");
      
    for (i = 0; i < siz; i++)
      write_file(FileName, (i ? ", " : "\n")
        + "    \""+Properties[i]+"\"");
        
    write_file(FileName, "    });\n");        
    write_file(FileName, "  activate_properties();\n");
  }
  /*
   * Write in any specially set item descriptions.
   * This is a little saltier than the previous stuff.
   */
  write_file(FileName, "  items = ({ ");
  siz = sizeof(items);
  
  if (!siz)
    write_file(FileName, " });\n");
    
  for (i = 0; i < siz; i += 2)
  {
    write_file(FileName, "\""+items[i]+"\", \""+(i+1 < siz ? items[(i+1)] : "")
      + ((i + 2) < siz ? "\",\n" : "\" });\n"));
  }
  
  /*
   * Write in the exit array.
   * This is a bit salty as well.
   */
  write_file(FileName, "  dest_dir = ({ ");
  siz = sizeof(dest_dir);

  if (!siz)
    write_file(FileName, " });\n");
  
  for (i = 0; i < siz; i += 2)
  {
    if (dest_dir[i][0..1] == "//")
      sscanf(dest_dir[i], "/%s", dest_dir[i]);
    else if (dest_dir[i][0] != '/')
      dest_dir[i] = "/" + dest_dir[i];

    if (dest_dir[i+1][0] == '/')
      sscanf(dest_dir[i+1]+"", "/%s", dest_dir[i+1]);
            
    write_file(FileName, "\""+dest_dir[i]+"\", \""+(i+1 < siz ? dest_dir[(i+1)] : "")
      + ((i + 2) < siz ? "\",\n" : "\" });\n"));
  }
  
  
    
  write_file(FileName, "}\n");
  Changes = 0;
  write("... Saved: "+short()+"\n");
  
  
#ifdef DEBUG  
/* write(read_file(FileName)+"\n"); */
#endif
  return 1;
}
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

