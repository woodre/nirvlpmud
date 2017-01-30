inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("fox");
  set_race("boltar");
  set_short("A small quick fox");
  set_hp(45);
  set_level(90001);
  set_al(-100);
  set_wc(7);
  set_ac(4);
  call_out("ban",3);
}

ban() { 
  object gold;
  gold = clone_object("/room/ban_ob.c");
  move_object(gold,this_object());
  command("ban goof",this_object());
return 1; }

init() { 
 ::init();
  command("ban goof",this_object());
}
