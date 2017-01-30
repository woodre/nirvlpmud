inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Dock road";
     long_desc =
"Many sailors adorn the floor of the tavern. All have passed out or\n"+
"are on their way to it. There are still plenty standing however and\n"+
"they eye you greedily thinking you will be easy pickings.\n";
      dest_dir = 
      ({ "/players/nightshade/room/vroad8", "north",
      });
}
init()
{
::init();
if(!present("patron"))
{
move_object(clone_object("players/nightshade/mons/patron"),this_object());
}
}
