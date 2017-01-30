/*
  zulu.c -- Adobted from Nooneelse's snooper_bat object
*/

#define TO this_object()
object owner;
 
id(str) { return (str=="zulu"); }

reset(arg) {
  if (arg) return;
  enable_commands();
  set_heart_beat(1);
}

set_owner(str) {
  owner = find_player(str);
  if(!owner) { destruct(TO); return 1; }
  set_heart_beat(1);
  return 1;
}

heart_beat() { if (!owner) { destruct(TO); return; } }  

catch_tell(str) {
  if(!owner) { destruct(TO); return; }
  tell_object(owner, "==>>> "+environment(TO)->short()+":\n"+"==>"+str);
  return;
}
