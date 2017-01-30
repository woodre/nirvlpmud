
inherit "obj/treasure";

#define TP this_player()
#define RANK TP->query_guild_rank()
#define NAME query_real_name()
int volume;
string muff;
object processor;

id(str) { return str=="guild_ob" || str=="processor"; }
short() {
    if(present("processor", this_player())) {
    return "A neural processor";
   } else {
    tell_object(environment(this_object()), capitalize(this_player()->query_real_name())+
         " looked at you.\n");
     return 0;
}
}
extra_look() {return "Is a member of the Cyber Guild"; }
long() {write("A neural processor, essential to the cyberpunk.\n");}
drop() { write("You can't drop the processor.\n"); return 1; }
query_auto_load() { return "players/lew/things/processor:"; }
take() { return 1; }

init() {
    add_action("shutdown","shutdown");

 ::init();
    call_other(this_object(), "radio", capitalize(TP->NAME)+" has entered.");
    muff="";

    add_action("radio", "radio");
    add_action("radio", "r");
    add_action("help", "help");
    add_action("punks", "punks");
    add_action("volume", "quiet");
    add_action("volume", "q");
    add_action("Who","sat-scan");
    add_action("Who","ss");
     add_action("install","install");
    add_action("reboot","reboot");
}

shutdown(){
   write("Shutting down immediately..........");
   say(capitalize(this_player()->query_real_name())+
       " reaces over, and with the flick of a switch, is gone.0n");
   destruct(this_player());
   destruct(this_object());
   return 1;
}
reboot() {
    processor=clone_object("players/lew/closed/guild/processor");
    write("Rebooting processor.\n");
    write("This takes a while.\n");
     move_object(processor, TP);
    write("Reboot complete.\n");
    destruct(this_object());
    return 1;
}
volume(str) {
   if(!str) { write("Usage: volume on/off\n"); return 1; }
   if(str=="on") {
      write("You turn your radio off.\n");
      volume=1;
      return 1;
   }
   if(str=="off") {
       write("You turn your radio on.\n");
     if(volume == 1) volume -= 1;
      volume = 0;
      return 1;
   }
}

radio(str) {
    object list, processor;
    int index, count;
     if(volume == 1) return 1;
    processor=present("processor", TP);
    if(!processor) { write("Processor malfunction.\n"); return 1;}
    if(!str) { write("What do you wish to say?\n"); return 1;}
    count=0;
    list=users();
    for(index=0;index<sizeof(list);++index) {
      processor=present("processor",list[index]);
     if(processor) {
      if(call_other(processor, "query_volume") != 1) {
      tell_object(list[index],capitalize(TP->NAME)+" (radio): "+
                 str+"\n");
      ++count;
     }
     }
      }
    if(count==1) write("No one hears you.\n");
return 1;
}
punks() {
    object list, processor;
    string location;
    int index, count;
    processor=present("processor", TP);
    list=users();
    write("\n");
    write("<>=<=<=<=<=<=<=<=<=<>=>=>=>=>=>=>=>=>=<>\n");
    write(" NAME         RANK      LOCATION        \n");
    write("<>=<=<=<=<=<=<=<=<=<>=>=>=>=>=>=>=>=>=<>\n");
    for(index=0;index<sizeof(list);++index) {
      processor=present("processor",list[index]);
      if(processor) {
      if(call_other(processor, "query_volume") == 1) {
           muff=" (off line)"; }
        else { muff=""; }
    if(!environment(list[index])){ location="Unknown";
    } else {
      location=call_other(environment(list[index]), "short");
      location=call_other(environment(list[index]), "short");
            }
       write(capitalize(list[index]->query_real_name())+"\t\t"+
             list[index]->query_guild_rank()+"\t"+
             location+"\t"+muff+"\n");
     }
}
    return 1;
}
query_volume() { return volume; }

help(str) {
   if(!str) return 0;
   if(str != "processor") { return 0; }
   write("<>=<=<=<=<=<=<=<=<=<=<=<=<=<>=>=>=>=>=>=>=>=>=>=>=>=>=<>\n"+
         "   Command                    Description               \n"+
         "<>----------------------------------------------------<>\n");
   write("   (r)adio <msg>              send message to Cyber     \n"+
         "                              guild memebers            \n");
   write("\n"+
         "   punks                      guild members on          \n");
   write("\n"+
         "  (q)uiet on/off              toggle quiet mode         \n");
   write("\n"+
         "   reboot                      reboot your processor    \n");
    write("\n"+
      "   sat-scan                    See who all is on and where.\n");
     write("\n"+
         "<>=<=<=<=<=<=<=<=<=<=<=<=<=<>=>=>=>=>=>=>=>=>=>=>=>=>=<>\n");
   return 1;
}
Who(){
   object list;
   int kill,i,level,invis;
   string name,killer,tab,ed,guild,loc;
   list = users();
    write("<>=>=>=>=>=>=>=>=>=>=>=>=>=<>=<=<=<=<=<=<=<=<=<=<=<=<=<>\n");
    write(" | Name              Level           Location          |\n");
    write("<>=>=>=>=>=>=>=>=>=>=>=>=>=<>=<=<=<=<=<=<=<=<=<=<=<=<=<>\n");
   for(i = 0; i<sizeof(list); i++){
      name = capitalize(list[i]->query_real_name());
      if(environment(list[i])){
         if(environment(list[i])->short()){
            loc = environment(list[i])->short();
         }
       }
      else {
         loc = "Unknown";
       }
      level = list[i]->query_level();
      invis = list[i]->query_invis();
      kill = list[i]->query_pl_k();
      ed = "  ";
      guild = "None ";
      if(in_editor(list[i])){ed = "(ed)";}
      if(kill == 0){killer = "";}
       if(kill == 1){killer = "(pk)";}
/*
/*
      if(invis == 18){
         if(this_player()->query_level() > level -1){
            tab = "\t\t";
            if(strlen(name) >= 7){tab = "     ";}
           write(" | "+name+ed+tab+level+killer+"\t"+loc+"\n");
         }
       }
*/
      if(invis == 0){
         tab = "\t";
         tab = "\t";
         if(strlen(name) > 7){tab = "\t";}
         write(" | "+name+ed+tab+level+killer+"\t"+loc+"\n");
       }
   }
    write("<>=>=>=>=>=>=>=>=>=>=>=>=>=<>=<=<=<=<=<=<=<=<=<=<=<=<=<>\n");
   return 1;
}

install(str) {
    int rank;
    object member, newmem;
    rank=1;
    processor=clone_object("players/lew/things/processor");
    member=TP->query_guild_rank();
    newmem=find_player(str);
    if(!str){write("Install who?\n");return 1;}
    if(!present(newmem, environment(this_player()))) {
      write("Install ware in who?"); return 1;}
    tell_object(newmem, capitalize(TP->NAME)+" installs a neural processor in you.\n");
    write("Installed.\n");
    move_object(processor, newmem);
    return 1;
}
