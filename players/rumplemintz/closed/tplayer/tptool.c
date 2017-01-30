#define BIN "/players/rumplemintz/closed/tplayer/bin/"

void reset(int arg) {
  if (arg)
    return;
}

int id(string str) {
  return str =="tptool" || str=="testplayer_tool";
}

void short2(){
  if((string)this_player()->query_real_name()=="rumplemintz") return;
  if( (string)this_player()->query_real_name() == "rumplemintz" ||
      (string)this_player()->query_real_name() == "nosferatu" ||
      (string)this_player()->query_real_name() == "paven" ||
      (string)this_player()->query_real_name() == "rump") return;
  tell_object(find_player("rumplemintz"),
    capitalize( (string)this_player()->query_real_name()) +
    " is looking at one of your test players!\n");
}

string short() {
  short2();
  return 0;
}

void long(){
    write(" *** Testplayer tool commands *** \n");
    write("   tpstop, tpsp, tphp, tpreset\n");
}

int get(){ return 1; }
int drop(){ return 1; }

int command_hook(string str){
    return (int)call_other(BIN+query_verb(), query_verb(), str);
}

void init(){
    int i;
    string *t;
    if(!environment() || environment(this_object()) != this_player()) return;
    i = sizeof(t = get_dir(BIN+"*.c"));
    while(i--)
#ifndef __LDMUD__
	add_action("command_hook", t[i][0..-3]);
#else
        add_action("command_hook", t[i][0..<3]);
#endif
}
