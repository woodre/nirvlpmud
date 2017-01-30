inherit "players/mythos/dmon/splitmon";

reset(arg) { 
  ::reset(arg);
  if(arg) return;
  set_name("test");
  set_alias("split");
  set_race("demon");
  set_short("Split Tester");
  set_hp(1000);
  set_level(10);
  set_al(-500);
  set_gender("male");
  set_parts(4);
  set_line(40);
  set_percent(90);
}

do_function() { 
  tell_object(find_player("mythos"),"FUNCTION DONE\n"); 
  once = 0; 
return 1; }
