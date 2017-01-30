inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;
set_name("talker");
set_alias("phone");
set_short("A crystal phone talker");
set_long(
  "This crystal phone is for talking to others.\n");
set_class(1);
set_weight(0);
set_value(0);
}

drop() { return 1; }
query_save_flag() { return 1; }

init() {
  ::init();
  add_action("talk","talk");
}

talk(str) {
string ob, who, msg;
  if(lower_case(this_player()->query_real_name()) != "torture") return 0;
  if(!str || sscanf(str,"%s %s",who,msg) != 2) {
  write("Use:  talk <who> <msg> \n"); return 1; }
  ob = find_living(lower_case(who));
  if(!ob) { write("not here.... \n"); return 1; }
  if(!this_player()->query_invis() < 1) {
  tell_object(ob,"Torture giggles: "+msg+"\n");
  write("You giggle to "+capitalize(who)+": "+msg+"\n");
  return 1; }
  tell_object(ob,"Torture gurgles to you: "+msg+"\n");
  write("You gurgle to "+capitalize(who)+": "+msg+"\n");
return 1;
}
