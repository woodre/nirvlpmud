#define BIN "/players/rumplemintz/closed/bin/"

void reset(int arg){ if(arg) return; }

int id(string str){ return str=="rumpstick" || str=="tool" || str=="stick"; }

void short2(){
  if((string)this_player()->query_real_name() == 
     (string)environment()->query_real_name())
    return;
  tell_object(environment(this_object()),
              capitalize((string)this_player()->query_real_name()) +
              " is checking you out!\n");
}

string short(){
  short2();
  return "Rumplemintz's Walking Stick";
}

void long() {
  write("\
This is Rumplemintz's Walking Stick.\n\
It has been specifically designed for old married men with some coding\n\
skills.  It looks as though you can do some wizard type shit with it.\n");
}

int get(){ return 1; }
int drop(){ return 1; }

int command_hook(string str){
  return (int)BIN + query_verb()->query_verb(str);
}

void init(){
  int i;
  string *t;

  if (!environment() || environment(this_object()) != this_player())
    return;
  if ((string)this_player()->query_real_name() != "rumplemintz" &&
      (string)this_player()->query_real_name() != "rumpsen")
    return;
  i = sizeof(t = get_dir(BIN+"*.c"));
  while(i--)
#ifndef __LDMUD__
    add_action("command_hook", t[i][0..-3]);
#else
    add_action("command_hook", t[i][0..<3]);
#endif
}
