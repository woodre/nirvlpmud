#include "defs.h"

object *soldiers;
int *actions;

int teleport;

void reset(int arg) {
  if(!arg)
    teleport=1;
}

void set_teleport(int x) {
  teleport=x;
}

int query_teleport() {
  return teleport;
}

void register(object ob)
{
  if(!soldiers)
  {
    soldiers=({ });
    actions=({ });
  }
  soldiers+=({ ob });
  actions+=({ 0 });
}

int call_help()
{
  object env;
  string course;
  int m;
  if(!sizeof(soldiers)) return 0;
  m=random(sizeof(soldiers));
  if(soldiers[m] && !actions[m])
  {
    env=environment(soldiers[m]);
    if(!env) return 0;
    course=(string)env->plot_path("queen_room");
    soldiers[m]->directive(course);
    actions[m]=1;
    return 1;
  }
  return 0;
}
