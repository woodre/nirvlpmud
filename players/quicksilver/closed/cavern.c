inherit "players/quicksilver/666/include/room_ext";
#include "/players/quicksilver/666/include/std.h"
#include "/players/quicksilver/closed/color.h"


int i=0;
string *allowed;

static string *tempallow;

no_clean() { return 1; }

aura_status() {
   switch(i) {
      case 1 : return BOLD+BLA+"A faint grey aura covers the cavern's entrance."+NOSTYLE; break;
      case 2 : return RED+"A faint crimson aura covers the cavern's entrance."+NOSTYLE; break;
      case 3 : return BOLD+WHI+"A brilliant white aura covers the cavern's entrance."+NOSTYLE; break;
   }
}

short() {
  return "A dark cavern";
}

long() {
  ::long();
  if(i) write(aura_status(i)+"\n");
}

reset(arg) {
     ::reset(arg);
     if(!arg) {
        set_light(1);
        set_long("   As you glance around the room, a gust of cold air envelops you.  The cavern\n"+
        "is eerily dark--the only illumination coming from two red candles burning\n"+
        "calmly on either side of a large black velvet sofa.\n"+
        "   You turn to look at the wall opposite the sofa and are overwhelmed by a\n"+
        "towering bookshelf.  Gazing at the spines of the tomes, you realize that none\n"+
        "of them bear any title of any sort.\n"+
        "   You shiver slightly as you attempt to allay your fears.");
        tempallow = ({});
        restore_object("players/quicksilver/closed/etc/workroom");  
/*
        move_object(clone_object("players/quicksilver/666/r/forest_daemon"),this_object());
*/
     }
     remove_call_out("scan");
     scan();
     return 1;
}

init() {
  object od;
  ::init();
  od=find_player("quicksilver");
  if(!check()) {
     tell_room(this_object(), "The aura flickers brightly and prevents "+capitalize(this_player()->query_real_name())+" from entering the room.\n");
     return;
  }
  if(od&&this_player()->query_real_name()!="quicksilver")
     tell_object(od, RED+"You sense "+capitalize(this_player()->query_real_name())+"'s presence in the cavern."+NOSTYLE+"\n");
  else {
     add_action("list","access");
     add_action("aura","aura");
     add_action("addex","addexit");
     add_action("clearex","clearexit");
     add_action("delex","delexit");
     add_action("add","addperm");
     add_action("clear","clear");
     add_action("del","delperm");
     add_action("add2","add");
     add_action("del2","del");
     add_action("scan","sca");
     add_action("trans","trans");
     add_action("wizzes","wizzes");
      add_action("set_light_level","rlight");
  }
}

check() {
  object od;
  od=find_player("quicksilver");
  if((this_player()->query_real_name()=="quicksilver")||!i) return 1;
  switch(i) {  
     default : if(!od) { 
              write("You are not allowed here when Quicksilver is not logged in.\n");
              write_file("/players/quicksilver/closed/log/ENTRY", ctime()+"  workroom.c:\n  "+this_player()->query_real_name()+" ["+this_player()->query_level()+
              "] tried to enter main workroom.\n");
              move_object(this_player(), "room/church");
              return 0;
              } else return 1;
              break;
     case 2 : if((member_array((this_player()->query_real_name()),allowed)==-1)&&(member_array((this_player()->query_real_name()),tempallow)==-1)) {
                 write("Quicksilver tells you: I am not currently accepting visitors.\n");
                 move_object(this_player(), "room/church");
                 return 0;
              } else {
                 write("You pass through the crimson aura with ease.\n");
                 return 1;
              } break;
     case 3 : write("Quicksilver tells you: I am not currently accepting visitors.\n");
              move_object(this_player(), "room/church");
              return 0;
              break;
  }
}
  
trans(arg) {
  object ob,rm;
  ob=find_player(arg);
  if(!ob) return 0;
  rm=environment(ob);
  tell_object(ob, "Darkness envelops you.  Your environment fades...\nYou arrive elsewhere.\n");
  move_object(ob, this_object());
  tell_room(rm, capitalize(ob->query_name())+" disappears as "+ob->query_pronoun()+" is enveloped in a shroud of darkness.\n");
  write("Ok.\n");
  return 1;
}

aura(str) {
  switch(str) {
     case "off" :	tell_room(this_object(), "The aura fades away.\n");
     			i=0;
     			break; 
     case "grey" :	tell_room(this_object(), "A faint grey aura leaps up at the entryway.\n");
     			i=1;
     			break;
     case "red" :	tell_room(this_object(), "A faint crimson aura leaps up at the entryway.\n");
     			i=2;
     			break; 
     case "white" :	tell_room(this_object(), "A brilliant white aura leaps up at the entryway.\n");
     			i=3;
     			break; 
  } 
  save_object("players/quicksilver/closed/etc/workroom");  
  return 1;
}

add(str) {
  allowed += ({ str });
  write(capitalize(str)+" has been allowed access.\n");
  save_object("players/quicksilver/closed/etc/workroom");  
  return 1;
}

clear(str) {
  switch(str) {
     case "all" :  allowed = ({});  tempallow = ({});
                   write("Both the temporary and perminant access lists have been cleared.\n");
                   save_object("players/quicksilver/closed/etc/workroom");
                   break;  
     case "temp" : tempallow = ({});
                   write("The temporary access list has been cleared.\n");
                   break;  
     case "perm" : allowed = ({});
                   write("The perminant access list has been cleared.\n");
                   save_object("players/quicksilver/closed/etc/workroom");
                   break;
     default:      notify_fail("Clear which list?  usage: clear [all|temp|perm]\n");
                   return 0;
                   break;
  }
  return 1;
}

del(str) {
  if(member_array(str,allowed)==-1) return write(capitalize(str)+" was not on the allowed list.\n");
  allowed -= ({ str });
  write(capitalize(str)+" has been removed from the allowed list.\n");
  save_object("players/quicksilver/closed/etc/workroom");  
  return 1;
}

add2(str) {
  tempallow += ({ str });
  write(capitalize(str)+" has been allowed temporary access.\n");
  return 1;
}

del2(str) {
  if(member_array(str,tempallow)==-1) return write(capitalize(str)+" was not on the allowed list.\n");
  tempallow -= ({ str });
  write(capitalize(str)+" has been removed from the allowed list.\n");
  return 1;
}

clearex() {
  dest_dir = 0;
  write("Exits cleared.\n");
  save_object("players/quicksilver/closed/etc/workroom");  
  return 1;
}

addex(str) {
  string dest, dir;
  
  if(sscanf(str,"%s %s", dir, dest)!=2) return 1;
  add_exit(dest, dir);
  write("Exit "+dir+" added, and leads to "+dest+".\n");
  save_object("players/quicksilver/closed/etc/workroom");  
  return 1;
}

delex(str) {
  string dest;
  
  if(!str) return 1;
  if(member_array(str,dest_dir)==-1) return write("Invalid exit.\n");
  dest=dest_dir[member_array(str,dest_dir)-1];
  dest_dir -= ({ str });
  write("Exit "+str+" removed.\n");
  save_object("players/quicksilver/closed/etc/workroom");  
  return 1;
}

wizzes() {
  object list;
  int i, level, invis;
  string name, ed, tab;
 
  list = users();
  write("Name"+"\t\t"+"Level"+"\t"+"Invis"+"\t"+"Edit\n");
  write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" +
        "-=-=\n");
  for(i = 0; i <sizeof(list); i++)
        {
          name = capitalize(call_other(list[i],"query_real_name"));
          level = list[i]->query_level();
          invis = list[i]->query_invis();
          if(invis>999) invis=999;
          ed = "  ";
          if(in_editor(list[i])) ed = "Ed";
          tab = "\t";
          if(strlen(name) < 8) tab = "\t\t";
          if(level > 19) write(name+tab+level+"\t"+invis+"\t"+ed+"\n");
        }
    return 1;
}

list() {
  int i;
  string name, name2;

  write("    Perm            Temp\n");
  write("=-=-=-=-=-=-=   =-=-=-=-=-=-=\n");
  for(i = 0; (i < sizeof(allowed))||(i < sizeof(tempallow)); i++)
        {
          name=(i < sizeof(allowed)) ? allowed[i] : "";
          name2=(i < sizeof(tempallow)) ? tempallow[i] : "";
          write((name ? capitalize(name) : "") + ((strlen(name) < 8) ? "\t\t" : "\t") + 
                (name2 ? capitalize(name2) : "") + "\n");
        }
    return 1;
}

scan() {
  object stuff;
  int i;
 
/* I am adding a return because something is autoloading this
    workroom.  There is no reason to keep this running constantly.
    -Feldegast 5-17-00 */
  return;
  stuff=all_inventory(this_object());
  for(i = 0; i <sizeof(stuff); i++)
        {
           if((!stuff[i]->short())&&(sscanf("/players/%s/", file_name(stuff[i]))!="quicksilver")&&(!find_player(stuff[i]->query_real_name()))) {
              write_file("/players/quicksilver/closed/log/OBJECT", ctime()+" workroom.c:\n  unknown invis object: "+file_name(stuff[i])+" destructed.\n");
              tell_room(this_object(), RED+"You see a bright flash as an invisible object disappears."+NOSTYLE+"\n");
              destruct(stuff[i]);
           }
        }
   call_out("scan",5);
   return 1;
}

set_light_level(arg) {
   int level;
   level=arg;

   set_light(level);
   write("The light of the room has been set to: "+level+"\n");
   return 1;
}
