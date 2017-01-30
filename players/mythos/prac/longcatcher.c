inherit "obj/monster";
string log;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("longcatcher");
  set_level(1);
  log = 0;
}

catch_tell(str) {
 log = str; 
}

string catch_long(object ob,object back,string str) {
  log = 0;
  move_object(ob,this_object());
  init_command("look at "+str);
  move_object(ob,back);
return log; }