inherit "players/nightshade/new_room";
object ob;
reset(arg){
if(!present("guard"))
{
ob=clone_object("players/nightshade/mons/celeborn");
move_object(ob, this_object());
}
   if(arg) return;
        set_light(1);
short_desc = "Waiting Room";
     long_desc =
"The kings room is to the east. You cant get in there because a rather\n"+
"unusually large elf is guarding the way. If you want to see the king you\n"+
"have to get by him first.\n";
"another of the kings guards stands ready for aanything to happen. He\n"+
"looks bored.\n";
      dest_dir = 
({
"players/nightshade/room/tree3", "down",
      });
}
init()
{
::init();
add_action("do_east", "east");
}
do_east()
{
if(!present("celeborn"))
{
this_player()->move_player("leaves east to see the king#players/nightshade/room/king_room");
}
