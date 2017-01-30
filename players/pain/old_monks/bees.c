 int x, bees;
    string owner;

long() {
 write("A Swarm of Killer Bees.\n");
}

reset(arg) {
 if(arg)
  return;
 bees = 2 + random(3);
 x = 0;
}

query_weight() {
    return 600;
}

short() {
 return "A Swarm of Killer Bees!";
}
id(str) {
 return str == "swarm" || str == "bees";
}

query_value() {
    return 0;
}
get() {
  return;
}
go() {
 set_heart_beat(1);
 }

set_owner(str) { owner = str; }

heart_beat() {
   object ob, obj, room, me;
   int which, hp;
     string it;
 ob = environment(this_object());
 room = environment(ob);
 me = find_player(owner);
  hp = ob->query_hp();
  it = ob->query_name();
  which = random(8);
if(!hp) {
 destruct(this_object());
 return 1;
  }
if(hp < 15) {
tell_room(room,
 capitalize(it)+" swats the last killer bee out of the air!\n");
 destruct(this_object());
 return 1;
   }
if(!(present(me, room))) {
 tell_room(room,
 "The Bees fly away.\n");
 destruct(this_object());
 return 1;
   }

if(which == 1) {
  tell_room(room,
 "A Killer Bee stings "+ob->query_name()+" in the ass!\n");
    ob->hit_player(random(25));
    return 1; }
if(which == 2) {
  tell_room(room,
 "A Killer Bee stings "+ob->query_name()+" in the face!\n");
    ob->hit_player(random(25));
     return 1; }
if(which == 3) {
  tell_room(room,
capitalize(ob->query_name())+" swats a Killer Bee out of the air.\n");
      x ++; }
 if(which > 7) { x ++; }

  if(x > bees) {
 tell_room(room,
"!! "+capitalize(ob->query_name())+" killed the last Killer Bee.\n");
  if(random(10) > 3) {
 tell_room(room, "An enraged "+capitalize(ob->query_name())+
  " goes after "+capitalize(me->query_name())+"!\n");
       ob->attack_object(me);
     destruct(this_object());
      return 1;
        }
   destruct(this_object());
     return 1; }
}
