inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_level(1);
  set_name("cat");
  set_short("cat");
  set_long("cat\n");
}
