inherit "players/nightshade/new_room";
object ob;
int i;
reset(arg){
if(!present("sentry"))
{
while(i<3)
{
ob=clone_object("players/nightshade/mons/sentry");
move_object(ob, this_object());
i++;
}
i=0;
}
   if(arg) return;
        set_light(1);
        short_desc = "Dock road";
     long_desc =
"This road leads east to the docks of Ledsville. It, like all docks\n"+
"is known for its seedy characters. Best be careful. The cool ocean\n"+
"breeze does feel good as it blows across your face. The office belonging to the town's sentry men is to the north\n";
      dest_dir = 
      ({ "/players/nightshade/room/vroad3", "west",
      "players/nightshade/room/vroad6", "east",
   "players/nightshade/room/capt_room", "north",
      });
}
