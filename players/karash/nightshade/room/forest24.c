inherit "players/nightshade/new_room";
object mon;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Deep Forest";
     long_desc =
"Phost trees grow in abundance here and many are dead so it is\n"+
"well lit. A few Hornwoods are mixed in as well as Sablewood  \n"+
"trees. They are short and have thick trunks. Their bark is a \n"+
"lustrous black and is a favorite meal of the sable grub. The \n"+
"branches are straight and would make excellent arrows.\n"+
"There is a small shack to your west that you might enter.\n";
      dest_dir = 
({
    "players/nightshade/room/forest23", "west",
 "players/nightshade/room/forest18", "north",
      });
}
init()
{
::init();
add_action("enter", "enter");
add_action("search", "search");
}
enter(str)
{
if(str == "shack")
{
write("You enter the shack cautiously.\n");
this_player()->move_player("into the shack#/players/nightshade/room/shack1");
return 1;
}
}
