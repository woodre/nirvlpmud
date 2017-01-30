inherit "players/nightshade/new_room";
object ob;
reset(arg){
if(!present("cyclo"))
{
ob=clone_object("players/nightshade/mons/cyclo");
move_object(ob, this_object());
}
   if(arg) return;
        set_light(1);
        short_desc = "Inside Fountain";
     long_desc =
"You are inside the fountain.\n";
      dest_dir = 
({
"players/nightshade/room/in2", "south",
      });
}
