inherit "players/nightshade/new_room";
object dork, penis;
reset(arg){
if(!present("rock"))
{
dork=clone_object("players/nightshade/misc/rock");
move_object(dork, this_object());
}
if(!present("imp"))
{
penis=clone_object("players/nightshade/mons/imp_master");
move_object(penis, this_object());
}
   if(arg) return;
        set_light(1);
short_desc="Imp Land";
     long_desc =
"Welcome to Imp land. These doods arent very hard to kill so it\n"+
"is a place for newbies. There is a small boulder right here with\n"+
"a dagger sticking out of it. Maybe you could release the dagger.\n"+
"The Imp Master prevents high levels from going north into Imp land.\n"+
"Have fun and be kool!!\n";
      dest_dir = 
({
"players/nightshade/room/forest6", "west",
      });
}
init()
{
::init();
add_action("do_pull", "extricate");
add_action("do_north", "north");
}
do_pull(str)
{
object duh;
int ob;
ob=this_player()->query_level();
if(!str) return;
if(present("dagger", this_player()))
{
write("Ya already have one. You dont need another.\n");
return 1;
}
if(str == "dagger" && ob < 8 && this_player()->is_player())
{
write("You slide the dagger from the stone! Another one suddenly shimmers into view in its place.\n");
say(this_player()->query_name()+" releases the dagger from the stone!\n");
duh=clone_object("players/nightshade/weap/imp_slayer");
move_object(duh, this_player());
return 1;
}
write("I dont think a high level like you needs this.\n");
return 1;
}
do_north()
{
int x;
x=this_player()->query_level();
if(x >= 8)
{
write("You are to high level to go in here.\n");
return 1;
}
write("You walk cautiously past the guard.\n");
this_player()->move_player("past the guard#players/nightshade/room/imp2");
return 1;
}
