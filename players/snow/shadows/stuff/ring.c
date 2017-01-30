inherit "obj/armor";
reset(arg){
   ::reset(arg);
   /* 11/14/05 Earwax */
   if (arg)
     return;

   set_name("shadow ring");
   set_short("A dusky ring");
   set_alias("ring");
   set_long("A shimmering band of shadow metal.\n");
   set_type("ring");
   set_ac(1);
/* <illarion> */
   set_params("magical",1,0,0);
   set_params("other|dark",0,10,0);
   set_params("other|light",0,-10,0);
   set_weight(1);
   set_value(1000);
}
 
ring_heal() {
  while (remove_call_out("ring_heal") != -1);
  if(!environment(this_object())) return 1;
  if(worn) {
    if(random(100) < 5) {
      say("The ring infuses some shadow strength into you.\n");
     if(this_player())
      this_player()->heal_self(random(5)+1);
    }
  }
  if (living(environment(this_object())))
    call_out("ring_heal",random(100));
  return 1;
}

query_save_flag() { return 0; }

init() {
  ::init();
  while (remove_call_out("ring_heal") != -1);
  call_out("ring_heal",random(100));
}
