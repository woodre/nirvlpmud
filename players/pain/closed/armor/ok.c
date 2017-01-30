inherit "obj/treasure";
reset(arg)
{
::reset(arg);
if(arg) return;
drop() { return 1 };
set_heart_beat(1);
set_name("rock");
set_short("A small rock");
set_alias("rock");
}
heart_beat(){
if( random(20) < this_player()->query_attrib("luc")){
this_player()->heal_self(random(100));
}
}
query_auto_load() { return "players/lew/closed/rocko.c:";}
