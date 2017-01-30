/* ***************************************************************************
 * File:           /players/earwax/housing/house_object.c
 * Function:       Player housing object.  It's the entrance.
 * Author:         Earwax
 * Copyright:      Copyright (c) 2004 Earwax.  All rights reserved.
 * Source:         5/22/04
 * Notes:          A text file will explain this.
 * Change History:
 * **************************************************************************/

#include "defs.h"
#define OVERRIDE 1

/* Global Variables */
mapping  Prices;
mapping  Commands;            /* ([ Command : ({ priv_level, cost }) ])     */
string  *Forbidden;

void
twax(string msg)
{
  object wax;
  
  wax = find_player("earwax");
  
  if (wax)
    tell_object(wax, HIG+"house_DAEMON: "+msg+NORM+NORM);
  else
    write_file("/players/earwax/housing/TWAX", 
      (string)WAXFUNS->date_time()+": "+"house_object: "+msg);
}

void 
reset(status arg) 
{ 
  int i;
  string *t;
  int *q;

  if (arg)
    return;
        
  i = sizeof(t = get_dir(BIN+"*.c"));
  Commands = ([ ]);
  
  while(i--)
  {
    q = (int *)(BIN+t[i])->priv_cost();    
    sscanf(t[i], "%s.c", t[i]);
twax("T[i] is: "+t[i]+"\n");
    Commands += ([ t[i] : (sizeof(q) == 2 ? q : ({ 1, 0 })) ]);
  }

  /* 
   * These need to get defines.
   * Or not, this isn't too bad?
   */      
  Prices = ([ "shack"   :  250000, 
              "hut"     :  500000, 
              "trailer" :  750000, 
              "house"   : 1000000, 
              "mansion" : 2000000, 
              "palace"  : 4000000,
              
              "add_room" : 500000
           ]); 
           
  Forbidden = ({ "quit", "get", "put", "kill" 
              }); /* more to surely be added later. */
}

status forbidden_verb(string arg) { return (member_array(arg, Forbidden) > -1); }

status 
can_do_command(string verb, object player, object master)
{
  string name;
  int i, priv;

    name = (string)this_player()->query_real_name();
    
/* To make future debugging easier. */    
#ifdef OVERRIDE
  if (name == "earwax")
  {
    twax("can_do_command override: "+verb+"\n");
    return 1;
  }
#endif
    
  if (!verb || !strlen(verb) || !player || !master) /* Shouldn't happen. */
  {
    notify_fail("No command, playerob or masterob passed.\nContact Earwax with what you did.\n");
    return 0;
  }
      
  if (!member(Commands, verb)) /* This shouldn't happen. */
  {
    notify_fail("Not a valid command: "+verb+".\nNotify Earwax if you get this message.\n");
    return 0;
  }
  
  priv = (int)master->query_privs(name);
  
  if (priv < 0) /* They are banned */
  {
    notify_fail("You are not allowed to do actions with this building.\n");
    return 0;
  }

  if (!sizeof(Commands[verb]))
    return 1; /* No cost, no min permission level, but shouldn't happen anyways */
      
  if (priv < Commands[verb][0]) /* Their permissions are too low. */
  {
    notify_fail("Your permissions are too low for that action.\n"
      + "Your permissions are currently set at level: "+priv+"\n");
    return 0;
  }

  if (!Commands[verb][1])
    return 1; /* No associated cost. */
    
  /* Check for clan balance. */
  if ((status)master->query_is_clanhall())
  {
    write("This is where we do the check if it's a clan.\n");
    return 0;
  }
    
  priv = (int)this_player()->query_bank_balance();
  
  if (priv < Commands[verb][1])
  {
    notify_fail("You do not have enough money in the bank to cover the cost of this.\n"
      +"Cost: "+(string)UTILITYD->comma_number(Commands[verb][1])
      +"\nYour bank balance: "+(string)UTILITYD->comma_number(priv)+".\n");
    return 0;
  }
  
  return Commands[verb][1]; /* Return cost so it can deduct it later. */
}

string *get_commands(string arg) { return m_indices(Commands); }
mapping get_command_info() { return Commands; }

mapping 
get_valid_commands(object master)
{
  int priv;
  string *t;
  int i;
  mapping temp;
  
  temp = ([ ]);
  priv = (int)master->query_privs((string)this_player()->query_real_name());
  i = sizeof(t = m_indices(Commands));
  
  while(i--)
    if (Commands[t[i]][0] <= priv)
      temp += ([ t[i] : Commands[t[i]] ]);

  return temp;
}
/* ***************************************************************************
 * Function Name:  
 * Description:    
 * Arguments:      
 * Returns:        
 * **************************************************************************/
string
get_base_filename(object room)
{
  string *stuff;
  int i;
  
  stuff = explode((string)room->query_filename(), "_");
  i = sizeof(stuff) - 2;
  return implode(stuff[0..i], "_");
}
 
string
dump_privs(object master)
{
  int i, j, siz;
  string output;
  string *owners;
  int *privs;
  
  output = "";
  owners = (string *)master->query_owners();
  privs = (int *)master->query_all_privs();
  
  siz = sizeof(owners);

  while(siz--)
  {
    if (!siz && (!owners[siz] ||!strlen(owners[siz])))
      owners[0] = (string)master->query_owner();
      
    output += privs[siz] + " - "+capitalize(owners[siz]) + " (";
    
    switch(privs[siz])
    {
      case 0  : output += "None"; break;
      case 1  : output += "Can enter, view settings, walk around"; break;
      case 2  : output += "Can add enhancements, change descriptions, edit"; break;
      case 3  : output += "Full privileges"; break;
      default : output += "Banned-No privileges"; break;
    }
    
    output += ").\n";
  }
  
  return output;
}

string
dump_items(object room)
{
  string output, *items;  
  int i, siz; i = 0; 
  
  siz = sizeof(items = (string *)room->query_items());
  output = "";
  
  while(i+1 < siz)
  {
    output += HIK+pad(items[i]+": ",20)+NORM+NORM+items[i+1]+"\n";      
    i += 2;
  }
  
  return output;
}

string 
dump_upgrades(object master) 
{ 
  return implode((string *)master->query_upgrades(), "\n")+"\n"; 
}

string 
dump_invited(object master) 
{ 
  return implode((string *)master->query_invited(), "\n")+"\n";
}
  
string
dump_exits(object room)
{ 
  string output, *exits, entrance; 
  int i, siz, baselen; status t;
  
  baselen = strlen(get_base_filename(room)) + 1;
  siz = sizeof(exits = (string *)room->query_exits());  
  entrance = (string)room->query_entrance();
  i = 0; output = ""; t = 0;
  
  while(i+1 < siz)
  {
    if (exits[i] == entrance)
      t = 1; 
    else 
      sscanf(exits[i], "%s.c", exits[i]);
    output += pad(exits[i+1]+": ", 10) 
      + (t 
        ? "EXIT:  "+(string)entrance->short() 
        : "Room#: " + exits[i][baselen..(strlen(exits[i]) -1)])
      + "\n";
    i += 2; t = 0;
  }
  
  return output;
}
string
dump_properties(object room, object master)
{
  string *t, *t2, output;
  int i, j;

  output = "";
  t = (string *)room->query_properties();
  output = HIK+"Properties set:\n"+NORM+NORM
         + (sizeof(t) ? implode(t, "\n")+"\n" : "None set.\n")+"\n"
         + HIK+"Available properties: \n"+NORM+NORM;
  i = sizeof(t2 = (string *)master->query_upgrades());
  j = 0;
  
  if (!i)
  {
    output += "None.\n";
    return output;
  }
  
  while(i--)
    if (!sizeof(t) || member_array(t2[i], t) == -1)
      if (text_contains(t2[i], "property"))
      {
        j++;
        output+=" 100,000 "+t2[i]+"\n";
      }

  if (!j)
    output += "None available.\n";
      
  return output;
}
status
view_settings(object room, object master, int level)
{
  int i, siz;
  string t;
  
  i = (int)room->query_light_level();
  write(HIW+"==============================================================================\n"+NORM+NORM);
  write(HIK+"Settings for room: "+(string)room->query_room_number()+"\n"+NORM+NORM);
  write(HIK+"Light level currently set: "+(i ? HIY+"Light Level " : "Darkness Level ")+i+"\n");
  write(HIK+"Total number of rooms: "+(string)master->query_house_size()+"\n");
  write(HIW+"==============================================================================\n"+NORM+NORM);
  write(HIK+"Short and long descriptions:\n"+NORM+NORM);
  write((string)room->short()+"\n");
  write((string)room->query_long());
  write(HIW+"==============================================================================\n"+NORM+NORM);
  write(HIK+"Exits:\n"+NORM+NORM);
  t = dump_exits(room);
  write((strlen(t) ? t : "None defined.\n"));
  write(HIW+"==============================================================================\n"+NORM+NORM);  
  write(HIK+"Upgrades:\n"+NORM+NORM);
  t = dump_upgrades(master);
  write((strlen(t) ? t : "None"));
  write(HIW+"==============================================================================\n"+NORM+NORM);  
  write(dump_properties(room, master));  
  write(HIW+"==============================================================================\n"+NORM+NORM);  
  write(HIK+"Item Descriptions: \n"+NORM+NORM);
  t = dump_items(room);
  write((strlen(t) ? t : "None defined.\n"));
  write(HIW+"==============================================================================\n"+NORM+NORM);    
  write(HIK+"Privileges\n"+NORM+NORM);
  write(dump_privs(master));
  write(HIW+"==============================================================================\n"+NORM+NORM);    
  write(HIK+"Currently allowed to enter:\n"+NORM+NORM);
  write(dump_invited(master));
  write(HIW+"==============================================================================\n"+NORM+NORM);    
  return 1;
}
/* ***************************************************************************
 * Function Name:  build_house
 * Description:    Put a building on land - doing it linearly cuz there's no
 *                 reason other than neatness not to.
 * Arguments:      arg, house object
 * Returns:        status - 0 for failure, 1 for success
 * **************************************************************************/
status
build_house(string arg, object ob)
{
  int i, j, siz, lsize, msize;
  string fullpath, id, junk, junk2, name, rpath, filename;
  string template, entrance, first;
  object room;
  
  if (!arg || !ob) /* This should never happen. */
  {
    notify_fail("Something seriously f'd up just happened.\nMail earwax\n");
    return 0;
  }
  HROOM->reset(0);
  arg = lower_case(arg);
  lsize = (int)ob->query_lotsize();
  name = capitalize((string)ob->query_owner()) + "'s " +capitalize(arg);

  /*
   * Variable types have major issues with saving and passing and retaining 
   * their type integrity on here.  Hence all these damn checks.
   */
  if (stringp(lsize))
    sscanf(lsize+"", ""+"%d", lsize);
    
  if (lsize < 0) lsize = 999;
    
  /*
   * Figure out how many rooms for the requested building.
   */
  switch(arg)
  {
    case "shack"    : siz = 1; msize = 1; break;
    case "hut"      : siz = 2; msize = 2; break;
    case "trailer"  : siz = 3; msize = 3; break;
    case "house"    : siz = 4; msize = 6; break;
    case "mansion"  : siz = 7; msize = 9; break;
    case "palace"   : siz = 10; msize = 999; break;
    case "clanhall" : siz = 10; msize = 999; break; /* change name here to clan name */
    default         : notify_fail("Invalid choice.\n"); return 0;
  }
  
  /*
   * Make sure it's the right building type for the size of lot.
   */
  if (siz > lsize)
  {
    notify_fail("Your land is not big enough to support that size building.\n"+
      "See "+HIW+"hcommands"+NORM+NORM+" for valid building types.\n");
    return 0;
  }
  
  if ((siz < 10 && lsize >= 10) || (siz < 4 && lsize > 3))
  {
    notify_fail("That would be ludicrous.\nInappropriate size building for this size of lot.\n");
    return 0;
  }
  
  if ((int)this_player()->query_bank_balance() < Prices[arg])
  {
    notify_fail("You don't have the "+Prices[arg]+" coins in the bank it would cost.\n");
    return 0;
  }
  
  this_player()->add_bank_balance(-Prices[arg]);
  write("The cost of "+Prices[arg]+" coins has been deducted from your bank account.\n");
  
  /*
   * Figure out the correct path
   */
  fullpath = "/"+(string)ob->query_house_filename();
  entrance = "/"+file_name(environment(ob))+".c";
  
  if (sscanf(fullpath, DATA+"%s/%s", junk, id) != 2)
  {
    write_file(BUG, (string)WAXFUNS->date_time()+": "
      + "sscanf() issue on "+fullpath+" in house_daemon.c\n");
   write((string)WAXFUNS->date_time()+": "
      + "sscanf() issue on "+fullpath+" in house_daemon.c\n");
    return 0;
  }

  filename = DATA+junk+"/room/"+id+"_";
  room = find_object(HROOM);

  if (!room)
  {
    HROOM->reset(0);
    room = find_object(HROOM);
  }

  for (i = 0; i < siz; i++)
  {
    room->reset(0);
    room->set_short1(name);
    
    if (!i)
    {
      room->add_exit("/"+file_name(environment(ob))+".c", "out");
      first = filename+"0.c";
    }
    else
    {
      room->add_exit("/"+filename+"0.c", "back");  
      first->add_exit("/"+filename+i+".c", "room"+i+"");
    }
    
    room->set_filename(filename+i+".c");
    room->set_base_filename(filename);
    room->set_room_num(i);
    room->set_light_level(1);
    room->set_entrance(entrance);
    room->set_lastroom(i);
    room->save_info();
    ob->set_house_size(i+1);
    if (i == 0) ob->set_entrance(filename+i+".c");

    if (siz == 10) /* Woot, free upgrades involved :) */
    {
      ob->add_upgrade(UPGRADE_ANSI);
    }
    
    ob->set_max_rooms(msize);  
    ob->save_info();
    ob->set_short(capitalize(arg));
  }

  first->save_info();  
  sscanf(entrance, "%s.c", entrance);
  LANDD->set_developed(entrance, i);
  LANDD->save_info();
  move_object(ob, environment(ob));

  write(HIY+"Congratulations, you are now the proud owner of a "+arg+".\n"+NORM+NORM);
  return 1;
}
/* ***************************************************************************
 * Function Name:  Add room
 * Description:    Add a room to an existing building.
 * Arguments:      House object, room object it's called from.
 * Returns:        status - 0 for failure, 1 for success
 * **************************************************************************/
 
status
add_room(object house, object curr_room)
{
  int msize, lsize, hsize;
  string filename, entrance;
  object room;
  
  if (!house || !curr_room) /* This should never happen. */
  {
    notify_fail("Something seriously f'd up just happened.\nMail earwax\n");
    return 0;
  }
  
  lsize = (int)house->query_lotsize();
  hsize = (int)house->query_house_size();
  msize = (int)house->query_max_rooms();
  filename = (string)curr_room->query_base_filename();  
  entrance = (string)curr_room->query_entrance();

  /* Issues with type integrity here makes this a requirement */  
  sscanf(lsize+"", ""+"%d", lsize);
  sscanf(hsize+"", ""+"%d", hsize);
  sscanf(msize+"", ""+"%d", msize);
  if (lsize < 0) lsize = 999;
     
  /* Make sure they have room to expand. */
  if (hsize >= msize || hsize >= lsize)
  {
    notify_fail("You're already at the maximum number of rooms.\n"
      +"Maximum size is "+msize+".\n");
    return 0;
  }
  
  HROOM->reset(0);
  room = find_object(HROOM);
  room->reset(0);
  room->set_short1((string)curr_room->query_short1());
  room->add_exit(filename+"0.c", "back");
  (filename+"0.c")->add_exit("/"+filename+hsize+".c", "NEWROOM");
  (filename+"0.c")->save_info();
  room->set_filename(filename+hsize+".c");
  room->set_base_filename(filename);
  room->set_room_num(hsize);
  room->set_entrance(entrance);
  room->set_lastroom(hsize);
  room->set_light_level(1);
  room->save_info();
  house->set_house_size(hsize+1);  
  house->save_info();
  sscanf(entrance, "%s.c", entrance);
  LANDD->set_developed(entrance, hsize+1);
  LANDD->save_info();
  move_object(house, environment(house));
  write(HIY+"Room addition successful.\n"+NORM+NORM+"New room number is: "+hsize+".\n");
  return 1;
}  
/* ***************************************************************************
 * Function Name:  query/set funs
 * Description:    Etc
 * Arguments:      Various
 * Returns:        Various
 * **************************************************************************/
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
