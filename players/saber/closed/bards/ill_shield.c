inherit "/players/saber/armor/armor3.c";
reset(arg){
   ::reset(arg);
   set_name("illusion_cloak");
   set_short();
   set_long("A cloak of illusion.\n");
   set_type("magic");
   set_ac(2);
   set_weight(0);
   set_value(0);
call_out("count_down", random(500) + 500);
}
drop() {return 1;}
get() {return 1;}

count_down()  {
object ob;
  ob = environment(this_object());
tell_room(environment(ob),
   "Something has changed.\n");
say("Your cloak of illusion fades away.\n");
command("remove illusion_cloak", ob);
remove_call_out("count_down");
destruct(this_object());
  return 1;
        }
