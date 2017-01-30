/* Player channel - basic bin tool with a channel
* 1/6/2007 - Rumplemintz@Nirvana
* Wizards - please stay off this channel - as players believe that
* it is only used by non-wizards.  You may clone and listen, but
* do not speak - as such, I have disabled the transmitals for all
* wizards - Rumplemintz
*/

#define BINPATH "/players/rumplemintz/PC/bin/"

int shushed;

string query_auto_load(){ return "/players/rumplemintz/PC/pc.c:0"; }

void set_shush(int i){ shushed = i; }

int query_shush(){ return shushed; }
string query_filename(){ return file_name(this_object()); }

void reset(int arg){
   if(arg) return;
   shushed = 0;
}

int id(string str){
   return str=="pc"
   || str=="channel"
   || str=="player_channel"
   || str=="player channel";
}

string extra_look(){
  if(!environment(this_object())->query_level() > 20)
   return environment(this_object())->query_name()+" is on the Player Channel";
}

int get(){ return 1; }
int drop(){ return 1; }

int command_hook(string str){
   return (int)call_other(BINPATH+query_verb(), query_verb(), str);
}

void init(){
   int i;
   string *t;
   if(!environment() || environment(this_object()) != this_player()) return;
   i = sizeof(t = get_dir(BINPATH+"*.c"));
   while(i--)
#ifndef __LDMUD__
      add_action("command_hook", t[i][0..-3]);
#else
      add_action("command_hook", t[i][0..<3]);
#endif
}
