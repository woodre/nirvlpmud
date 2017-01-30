inherit "room/room";
#include "../DEFS.h"

#define SAVR ALTDUNEPATH+"/holodeck"
#define SAVE DUNEPATH+"/holodeck"
#define RN   TP->query_real_name()
#define HOLO ALTDUNEPATH + "/holodeck/holodeck_object.c"



static int locked;
string holosetting, item1, item2, item3, item4, writing;


init()
{
  ::init();
  add_action("get_commands_from_say","say");
  player_check();
  if(locked)
  {
    write("Holodeck is locked and sealed.\n");
    move_object(TP, ROOMDIR + "/hallway1.c");
    return 1; 
  }
}


player_check()
{
  object x;
  if(locked)
  {
    locked = 0;
    x = first_inventory(this_object());
    while(x)
    {
      if (x->is_player() && x != this_player()) locked = 1;
      x = next_inventory(x);
    }
  }
}


reset(arg)
{
  locked = 0;
  if(item1) clone_holo_object("object 1");
  if(item2) clone_holo_object("object 2");
  if(item3) clone_holo_object("object 3");
  if(item4) clone_holo_object("object 4");

  if(!arg)
  {
    set_light(1);
    short_desc="HOLODECK";
    if(!holosetting)
    {
      long_desc=
"     You are in a square black void checkered with\n"+
"bright yellow gridlines.  You are in the "+FUNKYNAME+" Holodeck.\n";
    }
    else long_desc= holosetting;

    items=({});

    dest_dir=({
      ROOMDIR + "/hallway1.c","out",
    });
  }
}


save_me()
{
  string file;
  file = SAVR+"/"+RN;
  if(!save_object(file))
  {
    tell_room(environment(TP),"Computer: Unable to save program.\n");
    return 0;
  }
  tell_room(environment(TP),"Computer: Program saved.\n");
  return 1;
}


restore_me(string name)
{
  string file;
  file = SAVR+"/"+name;
  if(!restore_object(file))
  {
    tell_room(environment(TP),"Computer: Unable to execute program.\n");
    return 0;
  }
  tell_room(environment(TP),"Computer: Program executed.\n");
  return 1;
}


string get_item(int num)
{
  switch(num)
  {
    case 1: return item1;
    case 2: return item2;
    case 3: return item3;
    case 4: return item4;
  }
  return item1;
}


void check_for_vacancy(object ob)
{
  if(!present(ob, this_object()))
  {
    tell_room(this_object(), "The doors unseal and unlock.\n");
    tell_room(ROOMDIR + "/hallway1.c",
              "The doors to Holodeck unlock and unseal.\n");
    locked = 0;
    return;
  }
  call_out("check_for_vacancy", 5, ob);
}


void clone_holo_object(string str)
{
  string type, name, short, item;
  int num;
  object ob;
  sscanf(str, "%s %d", type, num);
  if(type == "object")
  {
    item = get_item(num);
    if(!item)
    {
      tell_room(environment(TP),"Computer: Object program not loaded.\n");
      return;
    }
    sscanf(item, "%s %s", name, short);
    ob = clone_object(HOLO);
    ob->set_alias(name);
    ob->set_race(lower_case(name));
    ob->set_short(short);
    move_object(ob, this_object());
    tell_room(environment(TP),
      "The Computer chimes electronically in response.\n");
    return;
  }
  else
  {
    tell_room(environment(TP),
      "Computer: Invalid type.  Should be object.\n");
    return; 
  }
  return;
}


void get_description(string str)
{
  if (str == "~q")
  {
    write("aborted.\n");
    return;
  }
  if (str=="**")
  {
    write("Ok.\n");
    holosetting = writing;
    return;
  }
  writing = writing + str + "\n";
  input_to("get_description");
}


void holodeck_enviro()
{
  write("Enter Holodeck description.\n");
  write("End with '**', abort with '~q'.\n");
  write("__________________________________________________________\n");
  writing = "";
  input_to("get_description");
  return;
}


int commands(string str)
{
  string pname, type, name, short, item, file;
  string *tmp, nameJumble;
  int num, i;
  object * inv;
  object ob;

  if(str == "show program")
  {
    tell_room(environment(TP),
      "The Computer chimes electronically in response.\n");
    tell_object(TP,"A small visual display appears in mid-air.\n"+
          "__________________________________________\n"+
          holosetting);
    tell_object(TP, pad("\nObject 1: "+item1, 25));
    tell_object(TP, pad("\nObject 2: "+item2, 25));
    tell_object(TP, pad("\nObject 3: "+item3, 25));
    tell_object(TP, pad("\nObject 4: "+item4, 25));
    tell_object(TP,"\n__________________________________________\n");
    return 1;
  }

  if(sscanf(str, "make %s %d", type, num))
  {
    if(num <= 0 || num >= 5)
    {
      tell_room(environment(TP),
        "Computer: Enumeration out of range, should be 1 to 4.\n");
      return 1;
    }
    clone_holo_object(type+" "+num);
    return 1;
  }

  if(sscanf(str, "remove %s %d", type, num))
  {
    if(num <= 0 || num >= 5)
    {
      tell_room(environment(TP),
        "Computer: Enumeration out of range, should be 1 to 4.\n");
      return 1;
    }
    if (type == "object")
    {
      item = get_item(num);
      if (!item)
      {
        tell_room(environment(TP),
          "Computer: Object program not loaded.\n");
        return 1;
      }
      sscanf(item, "%s %s", name, short);
      if (name && present(name, this_object()))
      {
        destruct(present(name, this_object()));
        tell_room(environment(TP),
          "The Computer chimes electronically in response.\n");
        return 1;
      }
      return 1;
    }
    else
    {
      tell_room(environment(TP),
        "Computer: Invalid type.  Should be object.\n");
      return 1;
    }
    return 1;
  }

  if(sscanf(str, "set object %d %s", num, nameJumble))
  {
    if (!nameJumble)
    {
      tell_room(environment(TP),
        "Computer: Try again, specify a name and short description.\n");
      return 1;
    }
    tmp=explode(nameJumble, " ");
    if (sizeof(tmp) >= 4 && tmp[0]=="name" && tmp[2]=="short")
    {
      name=tmp[1];
      short=tmp[3];
      if (sizeof(tmp) > 4)
      {
        for (i=4; i < sizeof(tmp); i++)
        {
          short+=" " + tmp[i];
        }
      }
      if(num == 1) item1 = name+" "+short;
      if(num == 2) item2 = name+" "+short;
      if(num == 3) item3 = name+" "+short;
      if(num == 4) item4 = name+" "+short;
      tell_room(environment(TP),
        "The Computer chimes electronically in response.\n");
      return 1;
    }
    else
    {
      tell_room(environment(TP),
        "Computer: See 'cyber holodeck' for usage.\n");
      return 1;
    }
  }

  if(sscanf(str, "clear %s %d", type, num))
  {
    if(num <= 0 || num >= 5) {
      tell_room(environment(TP),
        "Computer: Enumeration out of range, should be 1 to 4.\n");
      return 1; }
    if(type == "object") {
      if(num == 1) item1 = "";
      if(num == 2) item2 = "";
      if(num == 3) item3 = "";
      if(num == 4) item4 = "";
      tell_room(environment(TP),
        "The Computer chimes electronically in response.\n");
      return 1; }
    else {
      tell_room(environment(TP),
        "Computer: Invalid type.  Should be object.\n");
      return 1; }
    return 1;
  }

  if(str == "terminate program")
  {
    item1 = 0; item2 = 0; item3 = 0; item4 = 0; holosetting = 0;
    locked = 0;
    inv = all_inventory(this_object());
    for(i = 0; i < sizeof(inv); i++) {
      if(inv[i]) {
        if(inv[i]->is_player() || inv[i]->is_pet()) {}
        else destruct(inv[i]);
        }
      }
    reset();
    tell_room(environment(TP),
      "The Computer chimes electronically in response.\n");
    return 1;
  }

  if(sscanf(str, "execute program %s", pname))
  {
    pname = lower_case(pname);
    file = SAVE+"/"+pname+".o";
    if(file_size(file) >= 0) {
      restore_me(pname);
      reset();
      tell_room(environment(TP),
        "The Computer chimes electronically in response.\n");
      return 1; }
    else {
      tell_room(environment(TP),"Computer: No such program.\n");
      return 1; }
    return 1;
  }

  if(str == "save program")
  {
    save_me();
    tell_room(environment(TP),
      "The Computer chimes electronically in response.\n");
    return 1;
  }

  if(str == "allow me to change environment")
  {
    tell_room(environment(TP),
      "The Computer chimes electronically in response.\n");
    holodeck_enviro();
    return 1;
  }

  if(str == "lock doors" || str == "lock door")
  {
    locked = 1;
    check_for_vacancy(this_player());
    tell_room(environment(TP), "Computer: Doors locked.\n");
    return 1;
  }

  if(str == "unlock doors" || str == "unlock door")
  {
    locked = 0;
    tell_room(environment(TP), "Computer: Doors unlocked.\n");
    return 1;
  }
  return 1;
}


int get_commands_from_say(string str)
{
  string verbose;
  if(!str) { }
  else if(sscanf(str, "computer, %s", verbose)) commands(verbose);
  if(verbose == "allow me to change environment") return 1;
}


realm() { return "NT"; }
feel() { return "no"; }
