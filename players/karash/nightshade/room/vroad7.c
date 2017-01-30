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
"You can now see the large ships that export the gems from Ledsville.\n"+
"All the ships are out at sea, so you will have to wait if you want to\n"+
"board one. A beach lies north of you but right now it is closed off  \n"+
"due to a renegade mages wild experiments. You can see the island w where\n"+
"he lives to the east. You can swim there probably. Watch out for s\n"+
"sharks and other predators.\n";
      dest_dir = 
      ({ "/players/nightshade/room/vroad6", "west",
      "players/nightshade/room/vroad8", "east",
      });
}
