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
    "players/nightshade/room/forest20", "east",
 "players/nightshade/room/forest13", "north",
      });
}
monster() {
object x;
if(!present("bugbear")) 
{
x=clone_object("players/nightshade/mons/bugbear");
move_object(x, this_object());
}
}
