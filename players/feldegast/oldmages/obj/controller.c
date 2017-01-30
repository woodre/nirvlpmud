#define MAX_PETS 5
#include "/players/feldegast/defines.h"

object *pets;

int id(string str) { return str=="pet_controller"; }

int get() { return 1; }
int drop() { return 0; }

void reset(int arg) {
  if(!arg)
    pets=({ });
}

void init() {
  add_action("cmd_call","call");
  add_action("cmd_servants","servants");
}
int query_total() {
  int total;
  int i;
  for(i=0; i < sizeof(pets); i++) {
    if(!pets[i]) pets-=({ pets[i--] });
    else total+=(int)pets[i]->query_value();
  }
  return total;
}

int add_pet(object pet) {
  if(query_total()+(int)pet->query_value() < MAX_PETS) {
    pets+=({ pet });
    return 1;
  }
  return 0;
}
int remove_pet(object pet) {
  if(member_array(pet,pets)!=-1) {
    pets-=({ pet });
    return 1;
  }
  return 0;
}

int cmd_call(string str) {
  int i;
  if(!str) {
    notify_fail("Call what?\n");
    return 0;
  }
  for(i=0; i < sizeof(pets); i++) {
    if(pets[i]->id(str)) {
      if(environment(pets[i])==environment(this_player())) {
        notify_fail(pets[i]->query_name()+" is already here.\n");
        return 0;
      }
       tell_room(environment(pets[i]),pets[i]->query_name()+" leaves.\n");
       move_object(pets[i],environment(this_player()));
       write(pets[i]->query_name()+" arrives at your command.\n");
       say(pets[i]->query_name()+" arrives.\n");
       return 1;
      }
  }
}
int cmd_servants(string str) {
  int i;
  write("Servants\n--------\n");
  if(sizeof(pets) <= 0) {
    write("None\n");
    return 1;
  }
  for(i=0; i < sizeof(pets); i++) {
    write(pad((string)pets[i]->query_name(),20));
    write( ((int)pets[i]->query_hp() * 100) / ((int)pets[i]->query_mhp()) );
    write("%\n");
  }
  return 1;
}
