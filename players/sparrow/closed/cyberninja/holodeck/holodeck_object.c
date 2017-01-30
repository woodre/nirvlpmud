inherit "obj/monster";

reset(arg){
   if(arg) return 0;
   ::reset(arg);
   set_alias("illusion");
   set_short("An Illusion");
   set_long("This is just an illusion.\n");
   set_level(100);
   enable_commands();
   set_no_exp_value();
   set_can_kill(0);
   set_aggressive(0);
}
