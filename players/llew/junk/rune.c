#include "/players/llew/closed/ansi.h"
#pragma strict_types
#define LEGAL ({"n","s","e","w","ne","nw","se","sw","u","d"})
#define tp this_player()

int *commands;
object owner;
int hb;

int stop();
int trash();
int list();
int rune_speed(string com);
static int check_legal(string mem);
void heart_beat();

int id(string str) {
   return str == "llew-rune-of-speed" || str == "rune";
}

string short() {
   return HIB+"Rune"+NORM;
}

void reset(status arg) {
   if(arg) return;
   commands=({});
}

void long() {
   write("\n"+
      "The Rune of Speed is commanded by rs <com1>,<com2>,<com3>,etc...\n"+
      "There is no maximum to how many commands may be entered in the\n"+
      "Rune.  Five commands will be carried out, the rest passed to the\n"+
      "next round.  For a list of available commands type rs-commands.\n"+
      "To kill your buffer of commands type rs-stop.  Unravel the Rune\n"+
      "by typing rs-destroy.\n\n"
   );
}

int drop() { return 1; }
int get() { return 0; }
string query_auto_load() {
   return "/players/llew/junk/rune.c:";
}

void init() {
   add_action("rune_speed","rs");
   add_action("list","rs-commands");
   add_action("stop","rs-stop");
   add_action("trash","rs-destroy");
}

int rune_speed(string com) {
   string do_com;
   if(!com) return 0;
   owner=this_player();
   while(sscanf(com,"%s,%s",do_com,com)==2) {
      if(check_legal(do_com)) return 1;
   }
   if(check_legal(com)) return 1;
   if(!hb) {
      heart_beat();
      set_heart_beat(1);
      hb = 1;
   }
   return 1;
}

static int check_legal(string mem) {
   int check;
   check = member_array(mem,LEGAL);
   if(check < 0) {
      write(HIB+"Rune: "+NORM+"\""+mem+"\" is illegal.\n");
      return stop();
   }
   commands += ({check});
   return 0;
}

void heart_beat() {
   int count;
   count=0;
   if(!sizeof(commands)) {
      set_heart_beat(0);
      hb = 0;
      return;
   }
   tell_object(owner,"The "+HIB+"Rune"+NORM+" glows.\n");
   while(count < 5 && sizeof(commands)) {
      command(LEGAL[commands[0]],owner);
      commands -= ({commands[0]});
      count++;
   }
   tell_object(owner,"The "+HIB+"Rune"+NORM+" fades.\n");
}

int trash() {
   write("The "+HIB+"Rune"+NORM+" fades to oblivion.\n");
   destruct(this_object());
   return 1;
}

int list() {
   write(HIB+"\nLegal commands are:\n"+NORM+implode(LEGAL,", ")+"\n\n");
   return 1;
}

int stop() {
   write("The "+HIB+"Rune"+NORM+" flashes.\n");
   commands=({});
   set_heart_beat(0);
   hb = 0;
   return 1;
}


