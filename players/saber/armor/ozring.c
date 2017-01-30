inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("wedding ring");
   set_short("Ozymandias' wedding ring <Winnie>");
   set_alias("ring");
   set_type("ring");
   set_ac(1);
   set_weight(1);
   set_value(100);
  call_out("dest_corpse",1);
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

dest_corpse()  {
object corpse;
  if(!environment(this_object())) return 1;
say("\nTwo rings fall to the ground.\n");
corpse = present("corpse", environment(this_object()));
if(corpse)
destruct(corpse);
  return 1;
       }
