#include <ansi.h>

#define BIN "/players/rumplemintz/closed/bin/"

int shadowed;

void reset(int arg){ if(arg) return; }

int id(string str){ return str=="rumpstick" || str=="tool" || str=="stick"; }

string short() {
  string *s;
  int ar;
  object pl;

  s = ({
    HIW + "Rumplemintz's boxer shorts" + NORM,
    HIR + "Rumplemintz's death staff" + NORM,
    HIG + "Rumplemintz's Druid Leaf" + NORM,
    HIB + "Rumplemintz's cloud " + NORM,
    HIY + "Rumplemintz's Thunderbolt" + NORM,
    HIM + "Rumplemintz's kissing lips" + NORM,
  });
  
  ar = sizeof(s);

  if ((string)this_player()->query_real_name() == "rumplemintz" ||
      (string)this_player()->query_real_name() == "rumpsen")
    return "Rumplemintz's Walking Stick";
  else
    if (find_player("rumplemintz"))
      pl = find_player("rumplemintz");
    else
      pl = find_player("rumpsen");
    if (pl)
      tell_object(find_player("rumplemintz"),
                  capitalize((string)this_player()->query_real_name()) +
                  " is checking you out!\n");
    return s[random(ar)];
}

void long(){
    write("\
This is Rumplemintz's Walking Stick. \n\
It has been specifically designed for old married men with some coding\n\
skills.  It looks as though you can do some wizard type shit with it.\n");
}

int get(){ return 1; }
int drop(){ return 1; }

int command_hook(string str){
    return (int)call_other(BIN+query_verb(), query_verb(), str);
}

void init(){
  int i;
  string *t;

  if (!environment() || environment(this_object()) != this_player())
    return;
  if ((string)this_player()->query_real_name() != "rumplemintz")
    return;

  i = sizeof(t = get_dir(BIN+"*.c"));
  while(i--)
#ifndef __LDMUD__
    add_action("command_hook", t[i][0..-3]);
#else
    add_action("command_hook", t[i][0..<3]);
#endif
}

int query_shadowed() { return shadowed; }

