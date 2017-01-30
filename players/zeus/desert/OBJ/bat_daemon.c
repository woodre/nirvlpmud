
int num;  /*  number of bonus bats */

reset(arg) {
  if(arg) return;
  num = 8+random(4);

call_out("scheck",1);
}

scheck() {
  if(environment(this_object())) destruct(this_object());
return 1; }

make_bat(object z){
  object bat;
  if(!z) return 0;
  if(!environment(z)) return 0;
  if(!num) return 0;
  num--;
  bat = clone_object("/players/zeus/desert/NPC/desert_bat.c");
  tell_room(environment(z),
    "A desert bat flies into the room.\n");
  move_object(bat, environment(z));
  return 1;
}
