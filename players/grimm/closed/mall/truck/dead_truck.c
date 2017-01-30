inherit "/obj/treasure";
string nme;
id(str) { return str=="remains" || str=="truck"; }
reset(arg) {
  if(arg) return;
  set_weight(10000000);
  call_out("boom",600);
}
set_nme(str) { nme=str; }
short() { return nme; }
long() {
  write(nme+"\n");
  return 1;
}

boom() {
  say(nme+" explodes.\n");
  destruct(this_object());
  return 1;
}
