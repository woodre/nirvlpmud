inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
        short_desc = "Deep Forest";
     long_desc =
"Phost trees grow in abundance here and many are dead so it is\n"+
"well lit. A few Hornwoods are mixed in as well as Sablewood  \n"+
"trees. They are short and have thick trunks. Their bark is a \n"+
"lustrous black and is a favorite meal of the sable grub. The \n"+
"branches are straight and would make excellent arrows.\n";
      dest_dir = 
({
    "players/nightshade/room/forest21", "east",
 "players/nightshade/room/forest14", "north",
"players/nightshade/room/forest19", "west",
      });
}
monster()
{
object mon;
if(!present("lizard"))
{
mon=clone_object("players/nightshade/mons/gtliz.c");
move_object(mon, this_object());
}
}
