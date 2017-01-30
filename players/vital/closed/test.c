inherit "/players/vital/closed/std/monster.c";

reset(arg){
   if(arg) return;
   set_living_name("beck");
    set_name("beck");
   set_race("human");
   set_alias("test mob");
  long_desc=("This is a test mob\n");
  ::reset(arg);
   set_level(1000);
}

catch_tell(string str) {
    object me;
    me = find_player("vital");
    tell_object(me,str);
}

is_player() {
    return 1;
}

query_npc() { return 0; }

query_real_name() { return "beck"; }

