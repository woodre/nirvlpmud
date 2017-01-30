#include "defs.h"

int blessing;

int id(string str) {
  return str=="gods_blessing";
}

string short() {
  if(this_player() && (int)this_player()->query_level() > 20)
    return "(Invis Blessing: "+blessing+")";
}

int get() { return 1; }

void add_blessing(int i) {
  blessing+=i;
}

int query_blessing() {
  return blessing;
}

void reset(int arg) {
  if(arg) return;
  call_out("bless",5);
}

void bless() {
  object env;
  int q;
  env=environment();
  if(env && (int)env->is_player()) {
    if((object)env->query_attack()) {
      q=random(5);
      blessing-=q;
      if(blessing <= 0) {
        destruct(this_object());
        return;
      }
      env->heal_self(q);
      if(random(25))
        tell_object(env,HIY+"The gods smile upon you.\n"+NORM);

      call_out("bless",1);
      return;
    }
    call_out("bless",5);
  }
}

