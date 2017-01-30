inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("button");
  set_short("A button");
  set_long(
  "  A large button that you can wear.  There is\n"+
  "som writing on it.  Maybe you could <read_button>.\n");
  set_type("button");
  set_ac(0);
  set_weight(0);
  set_value(0);
}

init(){
 ::init();
   add_action("readem", "read_button");
 }

readem(str){
  write("Proud member of the Anti-Hoyle Fan Club.\n"); return 1; }

extra_look(){
  if(this_player()->query_name() != environment()->query_name()){
   write(environment()->query_name()+" is a member of the Anti-Hoyle Fan Club.\n");
   return 1; }
  write("You are a member of the Anti-Hoyle Fan Club.\n");
  return 1;
}