inherit "players/nightshade/new_room";
object ob;
reset(arg){
if(!present("guard"))
{
ob=clone_object("players/nightshade/mons/elven_guard");
move_object(ob, this_object());
}
   if(arg) return;
        set_light(1);
short_desc = "Level 3";
     long_desc =
"This is level three of the tree city. You see elves milling about and\n"+
"another of the kings guards stands ready for aanything to happen. He\n"+
"looks bored.\n";
      dest_dir = 
({
"players/nightshade/room/wait_room", "up",
"players/nightshade/room/tree2", "down",
      });
}
