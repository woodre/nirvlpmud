object targ;
string shortmeow;

start_shadow_haven(object a) {
  if(!a) return 1; 
  targ = a;
  shadow(targ,1);
  return 1;
}

stop_shadow_haven() {
  shadow(targ,0);
  destruct(this_object());
  return 1;
}

short() { return "(HAVEN) "+shortmeow; }

old_short(str) { shortmeow = str; }

realm() { return "NT"; }

query_no_fight() { return 1; }
