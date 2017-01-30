inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("wedding ring");
   set_short("Winnie's wedding ring <Ozymandias>");
   set_alias("ring");
   set_type("ring");
   set_ac(1);
   set_weight(1);
   set_value(100);
}

get()  { return 0; }

init()  {
  ::init();
  add_action("get_ring","get");
        }

get_ring(str)  {
  if(str == "ring")  {
  write("You hand passes through the ring.\n");
  return 1;
        }
        }

