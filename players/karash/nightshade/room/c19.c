inherit "players/nightshade/new_room";
object ob;
reset(arg){
monster();
   if(arg) return;
        set_light(1);
        short_desc = " Dark Cave";
     long_desc =
"The cave is damp and slightly dark. The walls are slimy and covered with an odd species of fungi which glows a faint gold color.\n";
      dest_dir = 
({
"players/nightshade/room/c18", "north",
      "players/nightshade/room/c20", "west",
      });
}
monster()
{
object x;
if(!present("horror"))
{
x=clone_object("players/nightshade/mons/hook_horror");
move_object(x, this_object());
}
}
