inherit "/players/saber/closed/evil/magi.c";

/*
 *      THE QUEST OBJECT FOR SABER'S QUEST
 *
 *      THE SILVER ANKH
 *
 */


#define CAP capitalize(str)
#define tp this_player()->query_name()
#define TP this_player()

static int BLADE_NUMBER, BLADE_PART, BLADE_WC;
static int DONE, Y_SWORD;
object CHECK;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
         }

id(str)  {
  return str == "ankh"  ||
         str == "saber_quest_object"  ||
         str == "Ankh";
          }

  drop()  { return 1; }
  get()   { return 1; }
  can_put_and_get()  { return 0; }


short()  { 
  return "An Ankh of worked black silver (worn)";
        }

long()  {
  write("\n"+
    "An ankh of worked black silver.\n"+
    "Type <ANKH> to see any current powers.\n");
         }


init()  {
  ::init();
   add_action("ANKH","ANKH");
   add_action("BLADE","BLADE");
   add_action("FORGE","FORGE");
        }

ANKH()  {
write(
  "\nCURRENT ANKH POWERS:\n\n"+
  "\n");
  return 1;
        }


FORGE()  {
object SWORD, REVENGE;
string BLADE_NAME;

if(BLADE_NUMBER == 0)  {
  if(!(SWORD = present("sword of fire", this_player())))  {
    write("You must have the Sword of Fire.\n");  return 1;  }
  if(SWORD->weapon_class() !=16)  {
    write("This is not the Sword of Fire.\n");  return 1;  }
  REVENGE = clone_object("/players/saber/closed/quest/revenge.c");
  move_object(REVENGE, this_player());
        }

  if(BLADE_NUMBER == 1)  {
  if(!(SWORD = present("stone cutter sword", this_player())))  {
    write("You must have the Sword of Stone.\n");  return 1;  }
  if(SWORD->weapon_class() !=16)  {
    write("This is not the Sword of Stone.\n");  return 1;  }
        }

  if(BLADE_NUMBER > 1 && BLADE_NUMBER < 6)  {
  DONE = 0;  Y_SWORD = 0;
  CHECK = first_inventory(this_player());
  while(CHECK)  {
    if(DONE == 0)  {
    if(CHECK->query_name() == "sword" || CHECK->query_name() == "blade" ||
     CHECK->query_alias() == "sword" || CHECK->query_alias() == "blade")  {
write("id check ok.\n");
  if(CHECK->query_name() != "sword of banishment"  &&
     CHECK->query_name() != "spirit sword"         &&
     CHECK->query_name() != "holysinger"           &&
     CHECK->query_name() != "sword of justice"     &&
     CHECK->query_name() != "revenge"              &&
     CHECK->query_name() != "coinspinner")  {
write("done not name.\n");
  if(CHECK->weapon_class() > 15)  {
      SWORD = CHECK;
      DONE = 1;  Y_SWORD = 1;
write("done yes.\n");
        }   }   }   }
  CHECK = next_inventory(CHECK);
        }
  if(Y_SWORD == 0)  {
    write("You do not have one of the Swords of Might.\n");  return 1;  }
        }

  if(BLADE_NUMBER == 6)  {
  if(!(SWORD = present("sword of justice", this_player())))  {
    write("You must have the Sword of Justice.\n");  return 1;  }
  if(SWORD->weapon_class() !=17)  {
    write("This is not the Sword of Justice.\n");  return 1;  }
        }

  if(BLADE_NUMBER == 7)  {
  if(!(SWORD = present("coinspinner", this_player())))  {
    write("You must have the Sword of Luck.\n");  return 1;  }
  if(SWORD->weapon_class() !=18)  {
    write("This is not the Sword of Luck.\n");  return 1;  }
        }
  if(BLADE_NUMBER == 8)  {
  if(!(SWORD = present("sword of banishment", this_player())))  {
    write("You must have the Cursed Sword.\n");  return 1;  }
  if(SWORD->weapon_class() !=19)  {
    write("This is not the Cursed Sword.\n");  return 1;  }
        }
  if(BLADE_NUMBER == 9)  {
  if(!(SWORD = present("orc slayer", this_player())))  {
    write("You must have the Sword of Orcs.\n");   return 1;  }
  if(SWORD->weapon_class() !=9)  {
    write("This is not the Sword of Orcs.\n");  return 1;  }
        }
  if(BLADE_NUMBER == 10)  {
  if(!(SWORD = present("holysinger", this_player())))  {
    write("You must have the Holysinger.\n");  return 1;  }
  if(SWORD->weapon_class() !=18)  {
    write("This is not the Holysinger.\n");  return 1;  }
        }
  if(BLADE_NUMBER == 11)  {
  if(!(SWORD = present("spirit sword", this_player())))  {
    write("You must have the Sword of the Spirits.\n");  return 1;  }
  if(SWORD->weapon_class() !=18)  {
    write("This is not the Sword of the Spirits.\n");  return 1;  }
        }
  if(BLADE_NUMBER == 12)  {
  if(!(SWORD = present("sword of frost", this_player())))  {
    write("You must have the Sword of Frost.\n");  return 1;  }
  if(SWORD->weapon_class() !=16)  {
    write("This is not the Sword of Frost.\n");  return 1;  }
        }

  REVENGE = present("revenge", this_player());
  if(!present("revenge", this_player()))  {
      write("You don't have the blade REVENGE.\n");
      return 1;        }
  BLADE_PART = REVENGE->query_part();
  BLADE_NAME = SWORD->query_name();
  BLADE_WC = REVENGE->weapon_class();
  BLADE_PART++;
  BLADE_WC++;
  BLADE_NUMBER++;
  REVENGE->set_class(BLADE_WC);
  REVENGE->set_part(BLADE_PART);
  command("drop "+BLADE_NAME);
  write("You drop part "+BLADE_NUMBER+" of the blade to the ground"+
  " and touch it with the silver ankh.\n"+
  "Part "+BLADE_NUMBER+" of REVENGE has been forged.\n");
  say(tp+" drops "+SWORD->short()+" to the ground and touches it with a\n"+
  "silver ankh.\n"+
  SWORD->short()+" disappears.\n");
  destruct(SWORD);
  if(BLADE_NUMBER == 13)  {
  write("\n\nREVENGE HAS NOW BEEN FORGED.\n\n");
  REVENGE->set_short("A blade named \"REVENGE\"");
        }
  return 1;

        }

BLADE(str)  {
  sscanf(str, "%d", BLADE_NUMBER);
  write("BLADE_NUMBER = "+str+".\n");
  return 1;
        }
