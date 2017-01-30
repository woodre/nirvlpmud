inherit "players/nightshade/new_room";
object ob;
reset(arg){
if(!present("celeborn"))
{
ob=clone_object("players/nightshade/mons/celeborn");
move_object(ob, this_object());
}
   if(arg) return;
        set_light(1);
short_desc = "Waiting Room";
     long_desc =
"This is the room where you will have to wait to see the king. His room\n"+
"is to the east but a rather unusually large elf blocks your way.\n";
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
if(present("celeborn"))
{
write("Celeborn laughs at your inferiority.\n");
return 1;
}
write("You walk past the dead corpse of celeborn.\n");
this_player()->move_player("leaves east#players/nightshade/room/king_room");
return 1;
}
