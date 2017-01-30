inherit "players/nightshade/new_room";
object ob1, ob2, ob3, ob4, ob5, ob6;
reset(arg){
if(!present("ether"))
{
ob1=clone_object("players/nightshade/mons/ether");
move_object(ob1, this_object());
}
if(!present("amine"))
{
ob2=clone_object("players/nightshade/mons/amine");
move_object(ob2, this_object());
}
if(!present("nitrile"))
{
ob3=clone_object("players/nightshade/mons/nitrile");
move_object(ob3, this_object());
}
if(!present("nitro"))
{
ob4=clone_object("players/nightshade/mons/nitro");
move_object(ob4, this_object());
}
if(!present("sulfide"))
{
ob5=clone_object("players/nightshade/mons/sulfide");
move_object(ob5, this_object());
}
if(!present("sulfoxide"))
{
ob6=clone_object("players/nightshade/mons/sulfoxide");
move_object(ob6, this_object());
}
   if(arg) return;
        set_light(1);
        short_desc = "Inside Fountain";
     long_desc =
"You are inside the fountain.\n";
      dest_dir = 
({
"players/nightshade/room/in2", "east",
      });
}
