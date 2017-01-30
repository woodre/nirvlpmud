inherit "players/nightshade/new_room";
object ob1, ob2, ob3, ob4, ob5, ob6;
reset(arg){
if(!present("amide"))
{
ob1=clone_object("players/nightshade/mons/amide");
move_object(ob1, this_object());
}
if(!present("chloride"))
{
ob2=clone_object("players/nightshade/mons/carbo_cl");
move_object(ob2, this_object());
}
if(!present("anhydride"))
{
ob3=clone_object("players/nightshade/mons/carbo_an");
move_object(ob3, this_object());
}
if(!present("ketone"))
{
ob4=clone_object("players/nightshade/mons/ketone");
move_object(ob4, this_object());
}
if(!present("acid"))
{
ob5=clone_object("players/nightshade/mons/carbo_acid");
move_object(ob5, this_object());
}
if(!present("ester"))
{
ob6=clone_object("players/nightshade/mons/ester");
move_object(ob6, this_object());
}
   if(arg) return;
        set_light(1);
        short_desc = "Inside Fountain";
     long_desc =
"You are inside the fountain.\n";
      dest_dir = 
({
"players/nightshade/room/in1", "west",
      });
}
