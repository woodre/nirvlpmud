#include        "security.h"
 
#define VERSION "1.4"
#define MaxLongs 20
#define BackSlash extract("\\ ", 0, 0)
#define MaxProperties 10
#define MaxItems 10
#define MaxObjects 10
#define MaxItemDesc 5
 
string        CreateFn, FileName, Short, HomePath, OldTitle;
int nExits, Light, ExitID, nLongs;
int no_exits, HaveProperty, i, overwrite, home;
int HaveItem, itemline, HaveObject, HaveMonster, tMonObj;
string ItemName, ItemDesc, Monster, MonsterName, nMonsterObj, MonsterCommands;
string        ExitPs, ExitDs, Longs;
string property, Object, Commands, ObjectName;
 
reset(arg)
        {
        if (!arg)
                HomePath = "players/" +
                           lower_case(this_player()->query_real_name());
                  home = 1;
        }
 
id(str)
        {
        return (str == "generator") || (str == "room generator");
        }
 
short()
        {
        return ("Custom Room Generator");
        }
 
long(str)
        {
        if(this_player()->query_level() < CREATE) {
          write("It is a device beyond your mortal understanding...\n");
          return 1;
        }
        write("Custom room generator.  Version: "+VERSION+"\n");
        write("\n");
        write("Usage:\troom <name>    Make a room that inherits room/room.c\n");
        write("\tpath <name>    adds <name> to the default path -- path \n");
        write("\t               defaults to your home directory.  You may\n");
        write("\t               use the ~ key to sub for the path you set, example:\n");
        write("\t\t~/fubar translates as <pathname>/fubar when in room exits.\n");
        write("\tpath           will toggle between your home dir and 'clear'.\n");
        write("\twrite <name> generates a series of write statements only.\n");
        write("\nYou can also type: !<command>  at most prompts once making\n");
        write("  a room to get to normal game commands without aborting.\n");
        if (creator(this_object()) !=
            lower_case(call_other(this_player(), "query_real_name")))
                {
           write("\n   This object was not cloned from your directory.  \n");
           write("   You will only be able to write to 'public' directories\n");
                write("   (such as /open). If you want to write to\n");
                write("   your home directory, copy this file from /open to\n");
                write("   your directory, and then clone it from there.\n");
                }
}
 
init()
      {
        if(environment(this_object())==this_player()) {
        add_action("Room", "room");
        add_action("Write", "write");
        add_action("Path", "path");
        }
}
 
drop() { return 1; }
 
get()
        {
        if(this_player()->query_level() < CREATE)
                {
                write("It does not exist in this reality.\n");
                return 0;
                }
        return 1;
        }
 
Room(str)
        {
        CreateFn = "WriteRoom";
        ReadRoom(str);
        return 1;
}
 
Write(str)
        {
        CreateFn = "WriteWrite";
        ReadRoom(str);
        return 1;
}
 
ReadRoom(str)
        {
        OldTitle = this_player()->query_title();
        this_player()->set_title("is EDITING a room...  Shhh...");
        say(this_player()->query_name()+" is now editing a room.  Shhh...\n");
        ExitPs = ExitDs = Longs = 0;
        write("\n    Type $$ at any prompt to abort, "+
              "or ? at any prompt for help.\n\n");
        if (str)
                GetFileName(str);
        else
                {
                write("Please input filename : ");
                input_to("GetFileName");
                }
}
 
GetFileName(str)
        {
        int        l;
        string tmpstr, check;
        string name, temp;
        int num;
        if (str == "$$")
                {
                CleanUp();
                return;
                }
        FileName = str;
        l = strlen(FileName);
        if ((l < 3) || (extract(FileName, l - 2) != ".c"))
                FileName += ".c";
         name = this_player()->query_real_name();
         num = strlen(name);
         num+=8;
         if(home) {
           temp = extract(HomePath, (num+1));
           if(temp!="") {
             FileName = (temp+"/"+FileName);
           }
           HomePath = extract(HomePath, 0, (num-1));
         } else {
           temp = HomePath+"/";
           FileName = temp+FileName;
         }
        if(!home) write("Now writing to file: "+FileName+"\n");
        else write("Now writing to file: "+HomePath+"/"+FileName+"\n");
                tmpstr = read_file(FileName,1);
                if(tmpstr) {
                  write("This file already exists.  Over-write it?  (y/n) : ");
                  input_to("Overwrite");
                } else {
                      if(CreateFn == "WriteWrite") {
                        HaveShort();
                      } else {
                        Property();
                      }
                 }
}
 
Overwrite(str) {
  if(str=="y") {
   overwrite = 1;
    if(CreateFn == "WriteWrite") { HaveShort(); } else { Property(); }
  } else {
    write("Please enter new Filename: ");
    input_to("GetFileName");
  }
}
 
Property() {
  write("Do you wish this room to have special properties?  (y/n/?) : ");
  input_to("SetProperty");
}
 
SetProperty(str) {
  property = allocate(MaxProperties);
  if(str=="$$") { CleanUp(); return; }
  if(str=="?") {
     write("\tSpecial properties are no-teleport zones, no-fight zones, etc.\n");
     write("\tYou may have up to "+MaxProperties+" properties per room.\n");
     Property();
  } else {
    if(str!="y" && str!="n") {
      write("\t'y' or 'n' or '?' for help.\n");
      Property();
    } else {
      if(str=="n") {
        HaveFileName();
      } else {
        i = 0;
        GetProperty();
      }
    }
  }
}
 
GetProperty() {
  write("( ** to end Property input or ? for examples)  ");
  write("Input Property #"+(i+1)+" : ");
  input_to("AddProperty");
}
 
AddProperty(str) {
  if(str=="$$") { CleanUp(); return; }
  if(str=="**") {
    HaveFileName();
  } else {
    if(str=="?") {
      write("\tNT   no teleport in or out of room,\n");
      write("\tNF   no fighting allowed in the room,\n");
      write("\tNC   no castle dropping in the room,\n");
      write("\t     or you can make custom properties of course.\n");
      write("\t     You are allowed "+MaxProperties+" properties per room.\n");
      GetProperty();
    } else {
      HaveProperty = 1;
        property[i] = str;
        i+=1;
        if(i >= MaxProperties) {
          HaveFileName();
        } else {
          GetProperty();
        }
    }
  }
}
 
GetObvious() {
        write("Do you wish to have the exits hidden?  (y/n/?) : ");
        input_to("ObviousExits");
}
 
ObviousExits(str) {
        if(str=="$$") { CleanUp(); return; }
        if(str!="y" && str!="n") {
               write("\t'n' will leave the line 'There are # obvious exits:'\n");
               write("\tin the room description;  'y' will remove that line,\n");
               write("\tbut the exits will still exist as you set them.\n");
               GetObvious();
        } else {
          if(str=="n") no_exits=0;
          else no_exits=1;
          HavenExits();
        }
}
 
HaveFileName()
        {
                write("How many exits? Light code? : ");
                input_to("GetnExits");
}
 
GetnExits(str)
        {
        if (str == "$$")
                {
                CleanUp();
                return;
                }
        if (sscanf(str, "%d %d", nExits, Light) != 2)
                {
                write("\tExample: '3 1' for a lit room with 3 exits.\n");
                write("\t         '6 0' for a dark room with 6 exits.\n");
                write("Try again ('$$' to abort) : ");
                input_to("GetnExits");
                }
        else
                {
                GetObvious();
                }
}
 
HavenExits()
        {
        if (nExits <= 0)
                return;
        ExitPs = allocate(nExits);
        ExitDs = allocate(nExits);
        ExitID = 0;
        write("Enter direction & path for exit 1.\n: ");
        input_to("GetExit");
}
 
GetExit(str)
        {
        if (str == "$$")
                {
                CleanUp();
                return;
                }
        if (sscanf(str, "%s %s", ExitDs[ExitID], ExitPs[ExitID]) != 2)
                {
                write(" Examples: 'south room/church' or 'north ~/workroom'\n");
                write("     (The  ~  character translates to <name> set in "+
                          "the 'path' function of\n");
                write("     this room maker, the default setting is your home "+
                          "directory.)\n"+
                      "       The first word is the Exit name, the second is"+
                      "\n       the filename of the room the Exit leads to.\n");
                write("Try again ($$ to abort)\n: ");
                input_to("GetExit");
                return;
                }
        if (extract(ExitPs[ExitID], 0, 0) == "~")
                ExitPs[ExitID] = HomePath +
                                 extract(ExitPs[ExitID], 1);
        ExitID += 1;
        if (ExitID == nExits)
                {
                HaveExits();
                }
        else
                {
                write("Enter direction & path for exit " +
                      (ExitID + 1) + ".\n: ");
                input_to("GetExit");
                }
}
 
HaveExits()
        {
        write("Enter short description.  (seen only in 'brief' mode)\n: ");
        input_to("GetShort");
}
 
GetShort(str)
        {
        if (str == "$$")
                {
                CleanUp();
                return;
                }
        Short = str;
        Items();
}
 
Items() {
  write("Do you wish to have any 'invisible' items in this room?  (y/n/?) : ");
  input_to("SetItems");
}
 
SetItems(str) {
  ItemDesc = allocate(MaxItems);
  ItemName = allocate(MaxItems);
  if(str=="$$") { CleanUp(); return; }
  if(str=="?") {
    write("\tThese items are only simple 'props', they can be examined\n");
    write("\tbut not taken.  A sign is a good example of this type of item.\n");
    write("\tYou may have up to "+MaxItems+" items per room.\n");
    Items();
  } else {
    if(str!="y" && str!="n") {
      write("\t'y' or 'n' or '?' for help.\n");
      Items();
    } else {
      if(str=="n") {
        HaveShort();
      } else {
        i = 0;
        GetItems();
      }
    }
  }
}
 
GetItems() {
  if(i >= MaxItems) {
    HaveShort();
  } else {
    write("\t( ** to end Item input or ? for examples)\n");
    write("Name for Item #"+(i+1)+" : ");
    input_to("ItemName");
  }
}
ItemName(str) {
  if(str=="$$") { CleanUp(); return; }
  if(str=="**") {
    HaveShort();
  } else {
    if(str=="?") {
      write("\tThe item's Name allows it to be examined, for example,\n");
      write("\tif your item is named 'sign', a player could type\n");
      write("\t'examine sign' and get the long description of the item\n");
      write("\tcalled 'sign' in this room.  You might give a clear hint \n");
      write("\tin the room's long description that this item exists, as\n");
      write("\tit DOES NOT show up in the room in any way.\n");
      GetItems();
    } else {
      HaveItem = 1;
      itemline = 0;
      ItemName[i] = str;
      write("Input Item description, "+MaxItemDesc+" lines max., "+
            "** to terminate.\n");
      write("        NOTE:  Does NOT need a final period...\n");
      write(": ");
      input_to("ItemLook");
    }
  }
}
 
ItemLook(str) {
  string temp2, temp;
  if(str=="$$") { CleanUp(); return; }
  if(str=="**") {
    if(itemline==0) {
      write(" Item aborted...\n");
      GetItems();
    } else {
      i+=1;
      GetItems();
    }
  } else {
    if(itemline) {
     ItemDesc[i] = ItemDesc[i] + BackSlash + "n";
     ItemDesc[i] = ItemDesc[i] + str;
    } else {
     ItemDesc[i] = str;
    }
    itemline+=1;
    if(itemline >= MaxItemDesc) {
      i+=1;
      GetItems();
    } else {
      write(": ");
      input_to("ItemLook");
    }
  }
}
 
HaveShort()
        {
        Longs = allocate(MaxLongs);
        nLongs = 0;
        write("Enter the long description.   " +
              "( ** to terminate, " + MaxLongs + " lines max.)\n: ");
        input_to("GetLong");
}
 
GetLong(str)
        {
        if (str == "$$")
                {
                CleanUp();
                return;
                }
        if (str == "**")
                {
                Objects();
                }
        else
                {
                Longs[nLongs] = str;
                nLongs += 1;
                if (nLongs >= MaxLongs)
                        Objects();
                else
                        {
                        write(": ");
                        input_to("GetLong");
                        }
                }
}
 
Objects() {
   if(CreateFn == "WriteWrite") HaveLong();
  else {
  write("Any Objects or Monsters in this room?  (y/n/?) : ");
  input_to("SetObjects");
  }
}
 
SetObjects(str) {
  Object = allocate(MaxObjects);
  Commands = allocate(MaxObjects);
  ObjectName = allocate(MaxObjects);
  if(str=="$$") { CleanUp(); return; }
  if(str=="?") {
    write("\tAs is, this will add the object or monster to\n");
    write("\tthe room, but will NOT create that object or monster,\n");
    write("\tthe filename you input must already exist.  As long as\n");
    write("\tthe file exists, the room will load the object, otherwise\n");
    write("\tyou will get an error when try to load the room...\n");
    write("\tIf you need a monster or object, there are blank copies of\n");
    write("\tall sorts of objects in the /open directory.  Just copy them\n");
    write("\tto your dir, and edit them to your specifics, then use the\n");
    write("\tfilename you have given them when this room maker asks.\n");
    Objects();
  } else {
    if(str!="y" && str!="n") {
      write("\t'y' or 'n' or '?' for help.\n");
      Objects();
    } else {
      if(str=="n") {
        HaveLong();
      } else {
        i = 0;
        GetObjects();
      }
    }
  }
}
 
GetObjects() {
  write("( ** to end Object input or ? for examples)\n");
  write("What is the filename for Object #"+(i+1)+"\n: ");
  input_to("AddObjects");
}
 
AddObjects(str) {
  if(str=="$$") { CleanUp(); return; }
  if(str=="**") {
    HaveLong();
  } else {
    if(str=="?") {
      write("\tA few examples of filenames are as follows:\n");
      write("\t'players/lazarus/monster' or 'players/astaroth/weapon'\n");
      write("\tYou can use the  ~  key to subsitute in the path you have\n");
      write("\tset in the 'path' function of the room maker, like:\n");
      write("\t'~/monster' translates to '<pathname>/monster'\n");
      write("\tthe default setting for <pathname> is your home directory.\n");
      GetObjects();
    } else {
      Object[i] = str;
      if(extract(Object[i], 0, 0) == "~")
        Object[i] = HomePath + extract(Object[i], 1);
      write("Enter the Name or ID of this object: ");
      input_to("GetName");
    }
  }
}
 
GetName(str) {
  if(str=="$$") { CleanUp(); return; }
  if(!str) { write("Object aborted...\n"); GetObject(); }
  else {
  ObjectName[i] = str;
    i+=1;
    HaveObject = 1;
    if(i >= MaxObjects) {
      HaveLong();
    } else {
      GetObjects();
    }
  }
}
 
HaveLong()
        {
        call_other(this_object(), CreateFn);
        CleanUp();
}
 
WriteWrite()
        {
        int        i;
        if(overwrite) rm(FileName);
        if(!home) write("Saving files as: "+FileName+"\n");
        else write("Saving file as: "+HomePath+"/"+FileName+"\n");
        i = 0;
        while (i < nLongs)
                {
                write_file(FileName,
                           "\twrite(\"" + Longs[i] + 
                           BackSlash + "n\");\n");
                i += 1;
                }
}
 
WriteRoom()
        {
        int        i;
        if(overwrite) rm(FileName);
        if(!home) write("Saving room as: "+FileName+"\n");
        else write("Saving room as: "+HomePath+"/"+FileName+"\n");
        write_file(FileName,
                   "inherit\t\"room/room\";\n\n");
        write_file(FileName,
                   "reset(arg) { \n");
        if(HaveObject) {
          i = 0;
          while(i < sizeof(Object)) {
            if(!Object[i]) break;
              write_file(FileName, " if(!present(\""+ObjectName[i]+"\")) {\n");
              write_file(FileName, "   move_object(clone_object("+
                "\""+Object[i]+"\"), this_object());\n");
              write_file(FileName, " }\n");
              i+=1;
          }
        }
        write_file(FileName, "  if(!arg) {\n" +
                   "  set_light(" + Light + ");\n" +
                   "  short_desc = \"" + Short + "\";\n" +
                   "  long_desc = \n   ");
        i = 0;
        while (i < nLongs)
                {
                if (i > 0)
                        write_file(FileName,
                                   "+\n   ");
                write_file(FileName,
                           "\"" + Longs[i] + BackSlash + "n\"");
                i += 1;
                }
        write_file(FileName, ";\n");
        if(no_exits) write_file(FileName, "  no_exits = 1;\n");
        if(HaveProperty) {
          i = 0;
          write_file(FileName, "  property = ({\""+property[i]);
          i+=1;
          while(i < sizeof(property)) {
            if(!property[i]) break;
            write_file(FileName, "\", \""+property[i]);
            i+=1;
          }
          write_file(FileName, "\"});\n");
        }
        if(HaveItem) {
          string sp;
          sp = "            ";
          i = 0;
          write_file(FileName, "  items = ({\"" +
              ItemName[i]+"\",\n"+sp+"\""+ItemDesc[i]);
          i+=1;
          while(i < sizeof(ItemName)) {
            if(!ItemName[i]) break;
            write_file(FileName, "\",\n"+sp+"\""+ItemName[i]+"\",\n" +
                sp+"\""+ItemDesc[i]);
            i+=1;
          }
          write_file(FileName, "\"});\n");
        }
        write_file(FileName, "  dest_dir = ({");
        i = 0;
        while (i < nExits)
                {
                if (i > 0)
                        write_file(FileName,
                                   ",\n               ");
                write_file(FileName,
                           "\"" + ExitPs[i] + "\", \"" +
                           ExitDs[i] + "\"");
                i += 1;
                }
        write_file(FileName,
                   "});\n" +
                   "  }\n" +
                   "}\n");
}
CleanUp()
        {
        this_player()->set_title(OldTitle);
        write("Ok.\n");
        CreateFn = 0;
        ExitDs = 0;
        ExitPs = 0;
        Longs = 0;
        no_exits = 0;
        HaveItem = 0;
        HaveProperty = 0;
        overwrite = 0;
        say(this_player()->query_name()+
             " is no longer editing a room.\n");
}
 
Path(str) {
  if(!str) {
    if(HomePath=="players/"+lower_case(this_player()->query_real_name())) {
      HomePath=""; 
   } else {
     reset(0);
   }
  } else {
    if(extract(str, 0, 0)=="/") str = extract(str, 1);
    HomePath += ("/"+str);
  }
  if(HomePath=="") {
    write("Clearing path.  Typing `path' again will return "+
          "your home directory.\n");
    home = 0;
  } else {
  write("Path set to: "+HomePath+"\n");
  }
  return 1;
}
