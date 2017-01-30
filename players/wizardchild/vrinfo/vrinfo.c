/* vrinfo.c: virtual reality information machine */
#define ROOT "/players/wizardchild/vrinfo/"
#define SAVE "players/wizardchild/vrinfo/current"
string *realms;  /* these arrays hold short descriptions + names */
string *guilds;
 
string *realmf;
string *guildf;
 
short() {
  return "A VR headset ("+sizeof(realmf)+" realms, "+sizeof(guildf)+" guilds)";
}
long()  {
  write("A large bulky headset. It appears that wearing it would cover most of\n");
  write("your head. From what you can tell, it is programmed to give information\n");
  write("on guilds and on various realms.\n");
  write("Type \"view guilds\" or \"view realms\" to see a list of options.\n");
  if(this_player()->query_level() >= 30) {
    write("Type \"new_info <guild/realm> <short_desc>\" if you have submitted an info\n");
    write("sheet that is not on this list.\n");
  }
  return 1;
}
get() {
  return 0;
}
id(str) { 
  return str == "headset" || str == "vr headset" || str == "VR headset"; 
}
reset(arg) {
  if(arg) return 0;
  if(!restore_object(SAVE) && file_size(ROOT+"current") > 0) {
    write_file(ROOT+"FAILED", ctime(time())+": failed to restore.\n");
    destruct(this_object());
  } 
}
init() {
  add_action("view_info", "view");
  add_action("load_doc", "load");
  if(this_player()->query_level() >= 30)
    add_action("new_info", "new_info");
}
view_info(str) {
  int i;
  write("You place the headset over your head.\n");
  write("In front of you, 3 dimensional letters show the following messages.\n");
  if(str == "guilds") {
    write("There are "+sizeof(guilds)+" documents on guilds.\n");
    for(i = 0; i < sizeof(guilds); i++)
      write((i+1)+": "+guilds[i]+"\n");      
  } else if(str == "realms") {
    write("There are "+sizeof(realms)+" documents on realms.\n");
    for(i = 0; i < sizeof(realms); i++)
      write((i+1)+": "+realms[i]+"\n");
  } else 
    write("There are no documents on "+str+"\n");
  if(i) {
    write("\nType \"load guild<num>\" or \"load realm<num>\" to display a specific\n");
    write("document.\n");
  }
  return 1;
}  
load_doc(str) {
  int i;
  string doc;
  if(sscanf(str, "guild%d", i) && str == "guild"+i) {
    if(i > sizeof(guilds)) 
      write("There are not that many simulations.\n");
    else {
      write("The display flickers momentarily, and you feel slightly disoriented.\n");
      write("An imitation environment forms around you...\n");
      doc = read_file(ROOT+"guilds/"+guildf[(i-1)]);
      if(!doc) {
        write("!!! Internal Error !!!\n");
        write("!!! Recording now. !!!\n");
        write_file(ROOT+"FAILED", ctime(time())+"Failed to load guildfile "+(i-1)+"\n");
        write("!!! Done! Exiting! !!!\n");
      } else {
        write(doc);
        write("The display flickers again, and the environment is gone.\n");
      }
    }
  } else if(sscanf(str, "realm%d", i) && str == "realm"+i) {
    if(i > sizeof(realms))
      write("There are not that many simulations.\n");
    else {
      write("The display flickers momentarily, and you feel slightly disoriented.\n");
      write("You see...\n");
      doc = read_file(ROOT+"realms/"+realmf[(i-1)]);
      if(!doc) {
        write("!!! Internal Error !!!\n");
        write("!!! Recording now. !!!\n");
        write_file(ROOT+"FAILED", ctime(time())+"Failed to load realmfile "+(i-1)+"\n");
        write("!!! Done! Exiting! !!!\n");
      } else {
        write(doc);
        write("The display flickers again, and the image fades away.\n");
      }
    }
  } else 
    write("Nothing happens.\n");
  return 1;
}
new_info(str) {
  int i;
  string type, short;
  if(this_player()->query_level() < 30) 
    return 0;
  if(sscanf(str, "%s %s", type, short) != 2) {
    write("Example:  new_info realm The land of the Wizardbeastlies\n");
    return 1;
  }
  if(type == "guild") {
    for(i = 0; i < sizeof(guildf); i++) 
      if(guildf[i] == this_player()->query_real_name()) 
        break;  
    if(i != sizeof(guildf))
      write("You are already recorded.\n");
    else {
      write("Checking for existence of description file...\n");
      if(file_size(ROOT+"guilds/"+this_player()->query_real_name()+".vr") < 1) 
        write("You do not have a valid description file. Please create one.\n");
      else {
        write("Found. Recording your name and description.\n");
        if(sizeof(guildf)) {
          guildf += ({this_player()->query_real_name()+".vr"});
          guilds += ({short+" ("+capitalize(this_player()->query_real_name())+")"});
        } else {
          guildf = ({this_player()->query_real_name()+".vr"});
          guilds = ({short+" ("+capitalize(this_player()->query_real_name())+")"});
        }
        write("Done. Have a nice day.\n");
      }
    }
  } else if(type == "realm") {
    for(i = 0; i < sizeof(realmf); i++)
      if(realmf[i] == this_player()->query_real_name())
        break;    
    if(i != sizeof(realmf))
      write("You are already recorded.\n");
    else {
      write("Checking for existence of description file...\n");
      if(file_size(ROOT+"realms/"+this_player()->query_real_name()+".vr") < 1) 
        write("You do not have a valid description file. Please create one.\n");
      else {
        write("Found. Recording your name and description.\n");
        if(sizeof(realmf)) {
          realmf += ({this_player()->query_real_name()+".vr"});
          realms += ({short+" ("+capitalize(this_player()->query_real_name())+")"});
        } else {
          realmf = ({this_player()->query_real_name()+".vr"});
          realms = ({short+" ("+capitalize(this_player()->query_real_name())+")"});
        }
        write("Done. Have a nice day.\n");
      }
    }
  } else 
    write("You can only describe a guild or a realm.\n");
  if(!save_object(SAVE))
    write_file(ROOT+"FAILED", ctime(time())+": failed to save object.\n");
  return 1;
}
patched_load(str) {
  string who, what, desc;
  if(this_player()->query_real_name() != "wizardchild")
    return 0;
  if(sscanf(str, "%s %s %s", who, what, desc) != 3)
    return 0;
  if(what == "realm") {
    realmf += ({who+".vr"});
    realms += ({desc+" ("+capitalize(who)+")"});
  } else {
    guildf += ({who+".vr"});
    guilds += ({desc+" ("+capitalize(who)+")"});
  }
  save_object(SAVE);
  write("Done: "+what+"\n");
  return 1;  
}
