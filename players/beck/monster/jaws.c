inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
set_short("A Huge Great White Shark");
set_long("This is the legendary Jaws\n");
set_name("jaws");
set_alias("shark");
set_level(23);
set_hp(1100);
set_wc(32);
set_ac(19);
set_chance(25);
set_spell_dam(16);
set_spell_mess2("Jaws takes a huge bite out of your mid section.\n");
call_out("random_move", 25);
enable_commands();
}
random_move(){
  if(random(2)==0) command("swim back", this_object());
  else command("swim around", this_object());
  call_out("random_move", 25);
  return 1;
}

/*
random_move(){
int n;
if(this_object()->query_attack()){
call_out("random_move", 10);
return 1;
}
n=random(2)
switch(n) {
case 0 : command("swim around"); break;
case 1 : command("swim back"); break;
}
call_out("random_move", 10);
return 1;
}
*/
