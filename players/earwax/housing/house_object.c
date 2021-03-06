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

/* Global Variables */

       string  FileName;    /* Used for restore/save                        */
       
       string  Short;       /* Object Setup Stuffs                          */
       string  LongDesc;    /* Long description of house                    */
       string  ShortDesc;   /* Object Setup Stuffs                          */
       string *Ids;         /* Object Setup Stuffs                          */
       int     WrapPref;    /* Linewrap preference.                         */       
       string *Upgrades;    /* Player-purchased upgrades                    */
              
       string  Owner;       /* Object Setup Stuffs                          */
       string *Owners;      /* List of 'owners' (for clans, privs)          */
       int    *Privs;       /* Priveleges for Owners                        */
       string  ClanName;    /* Clan name - dunno if i'll even use it        */       
       
       string  Entrance;    /* Room to go to when players enter house.      */
       int     LotSize;     /* Object Setup Stuffs 3/9/-num                 */
       int     HouseSize;   /* Object Setup Stuffs                          */
       int     Cost;        /* Object Setup Stuffs                          */
       int     LastRoom;    /* Last room number (or size)                   */
       status  IsClanhall;  /* If it's a clanhall                           */       
       int     MaxRooms;    /* Maximum number of rooms for housing type     */
       
static object  Here;        /* Fuckit, I got vars for everything else       */
static string *Invited;     /* Players who are invited to enter the castle  */

/* 
 * For debugging.
 */
void twax(string msg) {
  object wax; 
  
  if ((wax = find_player("earwax"))) tell_object(wax, HIG+"house_object: "+msg+NORM+NORM+"\n");
}
/* ***************************************************************************
 * Function Name: File save and restore functions 
 * Description:   Called by room on room loading.
 * Arguments:     Filename
 * Returns:       void
 * **************************************************************************/
void save_info() { save_object(FileName); }

void load_info(string filename) {
  int i;

  if (!filename || !strlen(filename))
  {
	  twax("NO FILENAME");
    return;
  }
  
  ShortDesc = Owner = Short = LongDesc = Entrance = "";
  HouseSize = LastRoom = IsClanhall = 0;
  LotSize = Cost = 0; Privs = ({ ({ }) });
  Upgrades = ({ });

  if (environment(this_object()))
    LotSize = (int)environment(this_object())->query_lot_size();
    
  Ids = ({ HOUSING_OBJECT_ID });

  if ((int)this_player()->query_level() > 39) 
  {  
twax("Checking file: "+filename+".o");
    if (file_size(filename+".o") < 0)
    {
      if (filename[0] == '/')
        filename = filename[1..(strlen(filename)-1)];
      
      FileName = filename;
      twax("BEFORE save_info(), FileName = "+FileName);
      save_info();
    }
  }
/* Debugging
  else
  {
*/
    if (filename[0] == '/')
      filename = filename[1..(strlen(filename)-1)];

    if (!restore_object(filename))
    {
	    twax("BUG LOG: House object did not restore: "+filename);
      LANDD->log_this(BUG, "House Object: Did not restore: "+filename+"\n");
    }
    else
      twax("HOUSE OBJECT RESTORED: "+filename);
/*
  }
*/

  if (IsClanhall)
    Short = "Clanhall";   
  else switch(HouseSize)
  {
    case 0    : Short = "Land"; ShortDesc = ""; break;
    case 1    : Short = "Shack"; break;
    case 2    : Short = "Hut"; break;
    case 3    : Short = "Trailer"; break;
    case 4..6 : Short = "House"; break;
    case 7..9 : Short = "Mansion"; break;
    default   : Short = "Palace"; break;
  }
  
  if (!sizeof(Owners) || sizeof(Privs) != sizeof(Owners))
  {
    Owners = ({ Owner });
    Privs = ({ 3 });
  }
  
  Owner = lower_case(Owner);
  Owners[0] = Owner; 
  FileName = filename;
}
status
save_all()
{
  int i; string j, *t, j2;
  
  sscanf("/"+FileName, DATA+"%s/%s", j, j2);
  j = DATA+j+"/room/";
  i = sizeof(t = get_dir(j+j2+"_*"));
  
  while(i--)
    (j+t[i])->save_info();
   
  write("... General housing information ");  
  save_info();
  write("... Saving Complete.\n");
  return 1;
}  
/* ***************************************************************************
 * Function Name: Ownership/privelege funs
 * Description:   Manipulate ownership/priveleges
 * Arguments:     Various
 * Returns:       Various
 * **************************************************************************/
string query_owner() { return Owner; } 
void clear_owners() { Owners = ({ Owner }); Privs = ({ 3 }); }
string *query_owners() { return Owners; }
mixed *query_all_privs() { return Privs; }
mixed *query_shit() { return Owners + Privs; }
string *query_owners_arr() { return Owners; }
/* ===================== */ 
void
new_ownership(string arg) 
{
  string j,j2, *t;
  int i;
  
  sscanf("/"+FileName, DATA+"%s/%s", j, j2);
  j = DATA+j+"/room/";
  i = sizeof(t = get_dir(j+j2+"_*"));
  Owner = lower_case(arg);
  Owners = ({ Owner }); 
  Privs = ({ 3 });
  
  while(i--)
  {
    (j+t[i])->set_short1(capitalize(Owner) + "'s "+Short);
    (j+t[i])->save_info();
  }
  save_info();
}

void set_owner(string arg) { new_ownership(lower_case(arg)); /* Owner = arg;*/ }

void add_owner(string arg) 
{ 
  if (arg && sizeof(Owners) && member_array(arg, Owners) >= 0)
  {
    Owners += ({ lower_case(arg) }); 
    Privs += ({ 1 });
  } 
}

void 
remove_owner(string arg) 
{
  int i; i = -2;
  
  if (!arg || !strlen(arg) || !sizeof(Owners)) 
    return;
    
  arg = lower_case(arg);  
  i = member_array(arg, Owners);

  if (i < 0) 
    return;
    
  Owners -= ({ arg }); 
  Privs[i] = -999;         /* Not sure if these necessary but... */
  Privs -= ({ Privs[i] }); /* can't be too careful here.         */
}

status
set_privs(string who, int level) 
{ 
  int i, t;
  object ob;
	  
  who = lower_case(who);  
  ob = find_player(who);
  i = member_array(who, Owners);
  
  if (i < 0)
  {
	  Owners += ({ who });
    Privs += ({ level });
    write("Privileges added to: "+who+"\nPrivilege set: "+level+"\n");
    
    if (ob)
      tell_object(ob, "Your privileges are now set to level: "+level+"\n");
      
    save_info();
    return 1;
  }
  
  if (who == lower_case(Owner))
  {
    notify_fail("Their privileges cannot be changed.\n");
    return 0;
  }
  
  t = Privs[i];
  Privs[i] = level;
    
  if (!IsClanhall && member_array(3, Privs) < 0)
  {
    Privs[i] = t;
    notify_fail("At least one person must have privileges of 3.\nSet_privs aborted.\n");
    return 0;
  }
  
  
  write("Privilege set for "+who+" "+(level > t ? "raised to " : "lowered to ")+level+".\n");
  
  if (ob)
    tell_object(ob, "Your privileges are now set to level: "+level+"\n");
      
  save_info();
  return 1;
}

int
query_privs(string arg)
{
  int i;
  object ob;
    
  /*
   * Mostly in case things get hosed somehow.
   */
  if (sizeof(Owners) != sizeof(Privs))
  {
    Owners = ({ Owner }); Privs = ({ 3 });
  }
  
  if (Owners[0] != Owner)
  {
    Owners = ({ Owner }); Privs = ({ 3 });
  }
  
  if (!arg || !strlen(arg) || !sizeof(Owners))
    return 0;
    
  arg = lower_case(arg);
  i = member_array(arg, Owners);

  if (i >= 0) 
    return Privs[i];  
    
  /*
   * Failed checks, see if it's a clanhall 
   */
  if (!IsClanhall || !((ob = present("clan_object", this_player()))))
    return 0; 

  /*
   * Verte's shit heh -
   * Vertebraker tells you: i'll make it work somehow
   * GET OFF MY SHEEP VERTE!@#%@#$%@#$
   */   
  return 0;      
  return (int)ob->query_privs();
}

/* ***************************************************************************
 * Function Name: build_residence
 * Description:   Puts a home on the land.
 * Arguments:     string arg - type of building
 * Returns:       status - 0 if it's not an id, 1 if it is
 * **************************************************************************/
status
do_build(string arg)
{
  status flag; int i;
  
  if (HouseSize)
  {
    notify_fail("This land has already has been built upon.\n");
    return 0;
  }
  
  if (!arg || !strlen(arg))
  {
    notify_fail("Build what?\n");
    return 0;
  }

  if (!find_object(HOUSED))
    HOUSED->reset(0);

  i = query_privs((string)this_player()->query_real_name());
  if (!sizeof(Owners) || !strlen(Owners[0]))
  {
    Owners = ({ Owner }); Privs = ({ 3 });
  }  
    
  i = member_array((string)this_player()->query_real_name(), Owners);
  
  if (i < 0 || Privs[i] < 3)
  {
    notify_fail("You are not the owner, nor do you have authorization by the owner to build here.\n");
    return 0;
  }
      
  if ((int)this_player()->query_level() < 19)
  {
    write("You may not build upon land until you reach level 19.\n");
    return 0;
  }  

  i = (int)this_player()->query_extra_level();
  
  if (  (arg == "hut"     && i < 10)
     || (arg == "trailer" && i < 20)
     || (arg == "house"   && i < 30)
     || (arg == "mansion" && i < 50)
     || (arg == "palace"  && i < 75) )
  {
    notify_fail("You lack the extra-levels to build a "+arg+".\n");
    return 0;
  }
  
  /*
   * So init() retriggers for everyone in room (to allow entrance)
   */      
  flag = (status)HOUSED->build_house(lower_case(arg), this_object());  
  
  if (flag)
    move_object(this_object(), environment(this_object()));
    
  return flag;
}

status
do_enter(string arg)
{
  string name; int i;
  
  if (!((status)this_object()->id(arg)))
  {
    notify_fail("You can't enter that.\nYou may enter the "+HIK+Short+NORM+NORM+".\n");
    return 0;
  }

  name = (string)this_player()->query_real_name();

  if (!sizeof(Owners) || !strlen(Owners[0]))
  {

    Owners = ({ Owner }); Privs = ({ 3 });
  }
  
  i = member_array(name, Owners);

  if (i > -1 && Privs[i] < 0)
  {
    notify_fail("You are not allowed to enter this property.  Begone!\n");
    return 0;
  }
      
  if (!sizeof(Invited) || member_array(name, Invited) < 0)
  {
    if (i < 0)
    {
      notify_fail("You are not an owner of this property, nor have you been invited to enter.\n");
      return 0;
    }
    
    if (!Privs[i])
    {
      notify_fail("You need an invitation to enter.\n");
      return 0;
    }
  }
      
  this_player()->move_player("into the "+arg+"#"+Entrance);
  return 1;
}
/* ***************************************************************************
 * Function Name: init
 * Description:   Stuff to do when a player enters the environment
 * Arguments:     none
 * Returns:       Void
 * **************************************************************************/
void
init()
{
  int i;
  string *dir;
 
  /*
   * Make sure everything loads up properly.
       return;
   */
  if ((!Owner || Owner == "") && environment(this_object()))
  {
    Owner = lower_case(capitalize((string)environment()->query_owner()));
    Cost = (int)environment()->query_cost();
    LotSize = (int)environment()->query_lot_size();
    Owners = ({ Owner }); Privs = ({ 3 });
  }
  
  if (!HouseSize)
    add_action("do_build", "build");
  else
    add_action("do_enter", "enter");
}
/* ***************************************************************************
 * Function Name: Various query/set funs for calling by outside objects
 * Description:   Housing object setup
 * Arguments:     Various
 * Returns:       Various
 * **************************************************************************/
    void set_long(string arg) { LongDesc = arg + NORM+NORM; }
string query_long() { return LongDesc; }

    void set_short(string arg) { Short = arg; }
string query_short() { return Short; }

    void set_cost(int arg) { Cost = arg; }
   int query_cost() { return Cost; }

    void set_max_rooms(int arg) { MaxRooms = arg; }
   int query_max_rooms() { return MaxRooms; }      

int query_house_size() { return HouseSize; }
int query_lotsize() { return (LotSize ? LotSize : (int)environment(this_object())->query_lot_size()); }
string query_house_filename() { return FileName; }
void set_entrance(string arg) { Entrance = arg; }

void set_lastroom(int arg) { LastRoom = arg; }
int query_lastroom() { return LastRoom; }

void set_is_clanhall(int arg) { IsClanhall = (arg ? 1 : 0); }
status query_is_clanhall() { return IsClanhall; }

void set_clan_name(string arg) { ClanName = arg; }
string query_clan_name() { return ClanName; }

void set_house_size(int arg) { HouseSize = arg; }
/* Add clanhall support */
string get_inside_short() { return capitalize(Owner) + "'s "+Short; }

void set_wrap_pref(int arg) { WrapPref = arg; }
int query_wrap_pref() { return (WrapPref ? WrapPref : 70); }
/* ***************************************************************************
 * Function Name: add_invited, remove_invited, query_invited
 * Description:   Players can invite other players to enter their houses.
 * Arguments:     Various
 * Returns:       Various
 * **************************************************************************/
string *query_invited() { return Invited; }

status 
add_invited(string arg) 
{ 
  int i;
  
  if (!arg) 
    return 0;

  arg = lower_case(arg);  
  i = member_array(arg, Owners);
  
  if (i > 0)
  {
    if (Privs[i] < 0) /* They are banned from entry */
    {
      notify_fail("They are banned from here.  Reset their priveleges to allow entry.\n");
      return 0;
    }
    
    notify_fail("They already have priveleges set and don't need an invitation.\n");
    return 0;
  }
  
  if (sizeof(Invited) && member_array(arg, Invited) >= 0)
  {
    notify_fail(capitalize(arg)+" is already on the list.\n");
    return 0;
  }
    
  Invited = (sizeof(Invited) ? Invited + ({ arg }) : ({ arg }) );
  return 1;
}

status
remove_invited(string arg)
{
  if (!arg)
    return 0;
    
  arg = lower_case(arg);
  
  if (member_array(arg, Invited) < 0)
  {
    notify_fail("They are not on the list of invitees.\n");
    return 0;
  }
    
  Invited -= ({ arg });
  return 1;
}
/* ***************************************************************************
 * Function Name: add_upgrade, remove_upgrade, query_upgrades
 * Description:   Housing upgrades
 * Arguments:     Various
 * Returns:       Various
 * **************************************************************************/
string *query_upgrades() { return Upgrades; }

status 
query_upgrade(string arg) 
{ 
  arg = lower_case(arg);
  return (sizeof(Upgrades) && member_array(arg, Upgrades) > -1); 
}

status 
add_upgrade(string arg) 
{ 
  int i;
  
  if (!arg) 
    return 0;

  arg = lower_case(arg);  
  i = member_array(arg, Upgrades);
  
  if (i > -1)
  {
    notify_fail("Upgrade already in.\n");
    return 0;
  }
    
  Upgrades = (sizeof(Upgrades) ? Upgrades + ({ arg }) : ({ arg }) );
  return 1;
}

status
remove_upgrade(string arg)
{
  if (!arg)
    return 0;
    
  arg = lower_case(arg);
  
  if (!sizeof(Upgrades) || member_array(arg, Upgrades) < 0)
  {
    notify_fail("That is not on the list of upgrades.\n");
    return 0;
  }
    
  Upgrades -= ({ arg });
  return 1;
}


/* ***************************************************************************
 *                                                                           *
 *           BASE OBJECT SETUP FUNS: long/short/id/reset                     *
 *                                                                           *
 * **************************************************************************/
 
 
 
 
/* ***************************************************************************
 * Function Name: id
 * Description:   Returns whether a given arguement refers to this object
 * Arguments:     string arg
 * Returns:       status - 0 if it's not an id, 1 if it is
 * **************************************************************************/
status
id(string arg)
{
  return (arg == lower_case(Short+"") ||
         (sizeof(Ids) && member_array(arg, Ids) > -1));
}
/* ***************************************************************************
 * Function Name: short
 * Description:   Short description
 * Arguments:     None
 * Returns:       String
 * **************************************************************************/
string
short()
{
  string t; t = HIY;
  
  if (!Short || !strlen(Short) || Short == 0 || Short == "")
    switch(HouseSize)
    {
      case 0    : Short = "Land"; ShortDesc = ""; break;
      case 1    : Short = "Shack"; break;
      case 2    : Short = "Hut"; break;
      case 3    : Short = "Trailer"; break;
      case 4..6 : Short = "House"; break;
      case 7..9 : Short = "Mansion"; break;
      default   : Short = "Palace"; break;
    }
    
  if (IsClanhall) 
    Short = "Clanhall";
          
  t += capitalize(Owner)+"'s " + Short+NORM+NORM  
    + (Cost ? ": For sale for "+Cost : (strlen(ShortDesc) ? ": "+ShortDesc : ""));
  return t + NORM + NORM;
}
/* ***************************************************************************
 * Function Name: long
 * Description:   long description
 * Arguments:     None
 * Returns:       Void
 * **************************************************************************/
void
long()
{
  string text, name, sht;
  int flag, i; 

      
  if (!set_light(0) && (environment(this_player()) != environment(this_object()) 
    || !present("dark_sight_object", this_player())))
  {
    write("It is too dark.\n");
    return;
  }

  sht = lower_case(Short);
  name = (string)this_player()->query_real_name();
  flag = 0; i = query_privs(name);
  
  if ((sizeof(Invited) && member_array(name, Invited) > -1) || i)
    flag = 1;
  
  write(short()+"\n");
  
  if (HouseSize)
  {
    if (Owner == name)
    {
      write("This is your "+sht+".  You may "+HIW+"enter"+NORM+NORM+" it.\n");
      return;
    }
    else
      write("This is a "+sht+" belonging to "+capitalize(Owner)+".\n");

    if (flag)
      write("You may "+HIW+"enter"+NORM+NORM+" the "+HIK+sht+NORM+NORM+".\n");
    else
      write("You can buy land at any realtor's office.\n");
    
    return;
  }

  flag = (i >= 3 ? 1 : 0);
  
  if (!flag)
  {
    write("This is undeveloped land belonging to "+capitalize(Owner)+".\n");
    write("For information about housing and land see the realty e,2s,w from green.\n");
    return; 
  }
    
  write(HIR+"You may build on this land.  Following are the valid building types:\n"+NORM+NORM);
  write(              "Type     Rooms  Level Req    Cost\n");
  
  if (stringp(LotSize))
    sscanf(LotSize+"", ""+"%d", LotSize);

  flag = (LotSize < 0 ? 10 : LotSize);

  if (flag <= 3) 
    write("Shack:     1      19        250,000\n");
  if (flag <= 3 && flag > 1)
    write("Hut:       2      19+10     500,000\n");
  if (flag <= 3 && flag > 2)
    write("Trailer:   3      19+20     750,000\n");
  if (flag <= 9 && flag > 3)
    write("House:    4-6     19+30   1,000,000\n");
  if (flag <= 9 && flag > 6)
    write("Mansion:  7-9     19+50   2,000,000\n");
  if (flag > 9)
    write((IsClanhall ? "Clanhall: 10+     -----   5" 
    : "Palace:   10+     19+75   4")
    + ",000,000\n");

  write("\nHouses start at 4 rooms, Mansions at 7, Palaces at 10.\n");
  write("To have a residence built type: "+HIW+"build "+HIK+"<type>"+NORM+NORM+"\n");
}
/* ***************************************************************************
 * Function Name: reset
 * Description:   Called on creation, resets
 * Arguments:     arg - 0 for creation, 1 for reset
 * Returns:       Void
 * **************************************************************************/
void
reset(status arg) 
{
  if (arg && FileName) 
    save_info();
 
  if (arg)
    return;

  Invited = ({ });
  Ids = ({ HOUSING_OBJECT_ID });
}  
