object *people;

void check_people();

void add_people(object me){
  people += ({ me });
}

status is_people(object me){
  return member_array(me, people) > -1;
}

object * query_people() {
  check_people();
  return people;
}

void broadcast(string msg) {
  int s;
  s = sizeof(people);
  check_people();
  while(s--) {
    if(people[s]) {
      tell_object(people[s], msg);
    }
  }
}

void check_people() {
  int s, *positions;
  positions=({});
  s = sizeof(people);
  while(s--){
    if(!people[s]) {
      positions += ({s});
    }
  }
  s = sizeof(positions);
  while(s--){
    people -= ({people[positions[s]]});
  }
}