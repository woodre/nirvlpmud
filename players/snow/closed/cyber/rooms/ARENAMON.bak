inherit "obj/monster";

reset(arg){
   if(arg) return 0;
   ::reset(arg);
   set_alias("__statue__");
   set_long("This is what allows observation from arena lounge.\n");
   set_level(100);
   enable_commands();
   set_can_kill(0);
   set_aggressive(0);
}

catch_tell(string str) {
"/players/snow/closed/cyber/rooms/arenalounge.c"->incoming(str);
return 1;
}
