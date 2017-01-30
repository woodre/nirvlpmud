inherit "/obj/treasure";
int i;
string monster;
string owner;
reset(arg) {
  if(arg) return;
  owner = "Nobody";
  monster = "Nothing";
  i=0;
  set_weight(100000);
}

set_owner(str) { owner = str; }

set_monster(str) { monster = str; }

heart_beat() {
  i++;
  if(i==2) {
    tell_room(environment(this_object()),capitalize(monster)+" is reserved for "+capitalize(owner)+".\n");
    i=0;
  }
  if(!find_living(owner)) {
    tell_room(environment(this_object()),capitalize(monster)+" is no longer reserved.\n");
    destruct(this_object());
  }
  if(!present(monster,environment(this_object()))) {
    if(find_living(owner)) {
      tell_object(find_living(owner),capitalize(monster)+" has been killed.\n");
    }
    destruct(this_object());
  }
}

go() {
  set_heart_beat(1);
  call_out("go_boom",300);
  return 1;
}

go_boom() {
  tell_room(environment(this_object()),capitalize(monster)+" is no longer reserved.\n");
  if(find_living(owner)) {
    tell_object(find_living(owner),"Time up for reservation on "+capitalize(monster)+".\n");
  }
  destruct(this_object());
  return 1;
}
