/*
 *  An object to make inspecting a realm easier. 
 *  V 1.0 by Saber / Geoffrey Z. on 3.6.97          
 *
 */

#define TP this_player()
#define TARGET find_player(target)
#define CAP capitalize(str)

#include "/obj/clean.c"
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

string ATTUNED;

id(str) { return str == "shades" || str == "looker"; }

short() {  return "Cool Shades";  }

long()  {
     write( "Looker: Version 1.0.\nBy Saber / Geoffrey Z. - saber@ryllian.com\n\n"+
            "Commands: (case sensetive)\n\n"+
            "\t< Attune > < name >\tTells the looker who to send code to.\n"+
            "\t< Z > < command >\tUse with a movement or look command.\n"+
            "\t\t\t\tUse < Z Look > for room desc.\n\n"+
            "For optimal use, < Attune > to a test character (or vice versa) or use\n"+
            "a split screen.\n");
         }


drop()  { return 1; }


init()  {

   add_action("attune","Attune");
   add_action("looker_command","Z");

   }



/* Attune the looker to a person */

attune(str)  {
string newtitle, target;
object ob;

  if(!str)  {
     write("Syntax: < Attune > < player name >.\n");
     return 1;     
   }
   
   target = lower_case(str);
   
   if(!(TARGET))  {
     write("You can not find "+CAP+".\n");
     return 1;        
   }
     
  if(TP->query_level() < 20 && TARGET->query_level() < 20)  {
     write("You must be a wizard to use this object.\n");
     destruct(this_object());
     return 1;
   }
  
  ATTUNED = lower_case(str);
    
  tell_object(TARGET, "You feel dizzy.\n");

  write("You attune the looker to "+CAP+".\n");
  return 1;
  
   }



/* File reading made easy */

looker_command(str)  {
string COMMAND, TEMP, TEMP2, FILE;
object target, obj, *remote;
int i;


  if(!(target = find_player(ATTUNED)))  {
    write("You must < Attune > the looker to use it.\n");
    return 1;
    }

  if(!str)  {
    write("Syntax: < Z > < command >\n"+
          "Commands: look, Look and movement commands.\n");
    return 1;
    }

  if(sscanf(str, "%s %s %s", COMMAND, TEMP, TEMP2) < 3)  { 
  if(sscanf(str, "%s %s %s", COMMAND, TEMP) < 2)  { 
     sscanf(str, "%s", COMMAND); 
     }
     }
  

/* Look at code following movement */

  if(COMMAND == "n"   || COMMAND == "north"       ||
     COMMAND == "e"   || COMMAND == "east"        ||
     COMMAND == "s"   || COMMAND == "south"       ||
     COMMAND == "w"   || COMMAND == "west"        ||
     COMMAND == "ne"  || COMMAND == "northeast"   ||
     COMMAND == "nw"  || COMMAND == "northwest"   ||
     COMMAND == "se"  || COMMAND == "southeast"   ||
     COMMAND == "sw"  || COMMAND == "southwest"   ||
     COMMAND == "u"   || COMMAND == "up"          ||
     COMMAND == "d"   || COMMAND == "down"        ||
     COMMAND == "in"  || COMMAND == "enter"       ||
     COMMAND == "out" || COMMAND == "step"        ) {
     
  command(COMMAND, TP);
  
  FILE = file_name(environment(TP));
  
  tell_object(target, "\n"+cat(FILE)+"\n"+BOLD+
                      environment(TP)->short()+NORM+" * "+FILE+"\n");
  return 1;
  
  }
  
  
/* Look at file paths in environment */

  if(COMMAND == "Look" || COMMAND == "L")  {
  
    command("look", TP);

    remote = all_inventory(environment(TP));
    
    tell_object(target, "\n"+BOLD+"In the area:"+NORM+"\n");
    
    for(i = 0;i<sizeof(remote);i++)  {
    tell_object(target, i+" * "+remote[i]->short()+"\n");
    }
  
    tell_object(target, "\n"+BOLD+environment(TP)->short()+NORM+"\n");
    return 1;
  
  }
  
  
/* Look at code of room */

  if(COMMAND == "look" || COMMAND == "l")  {
  
    if(!TEMP && !TEMP2)  {
  
      command(COMMAND, TP);
  
      FILE = file_name(environment(TP));
  
      tell_object(target, "\n"+cat(FILE)+"\n"+BOLD+
                          environment(TP)->short()+NORM+" * "+FILE+"\n");
      return 1;
  
  }
  
  
/* Look at code of object */

    if(!(obj = present(TEMP2), environment(TP)))  {
    if(obj = present(TEMP2), TP)  {
  
    FILE = file_name(obj);
  
    tell_object(target, "\n"+cat(FILE)+"\n"+
                        obj->short()+" * "+FILE+"\n");
  
  }
  }
  }

  }
  
