inherit "players/nightshade/new_room";
object ob1, ob2, ob3, ob4, ob5, ob6;
reset(arg){
if(!present("alkane"))
{
ob1=clone_object("players/nightshade/mons/alkane");
move_object(ob1, this_object());
}
if(!present("alkene"))
{
ob2=clone_object("players/nightshade/mons/alkene");
move_object(ob2, this_object());
}
if(!present("alkyne"))
{
ob3=clone_object("players/nightshade/mons/alkyne");
move_object(ob3, this_object());
}
if(!present("arene"))
{
ob4=clone_object("players/nightshade/mons/arene");
move_object(ob4, this_object());
}
if(!present("halide"))
{
ob5=clone_object("players/nightshade/mons/halide");
move_object(ob5, this_object());
}
if(!present("alcohol"))
{
ob6=clone_object("players/nightshade/mons/alcohol");
move_object(ob6, this_object());
}
   if(arg) return;
        set_light(1);
        short_desc = "Inside Fountain";
     long_desc =
"You are inside the fountain.\n";
      dest_dir = 
({
"players/nightshade/room/in2", "west",
      });
}
