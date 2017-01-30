inherit "room/room";

reset(arg) {

   int i,n;

   object wep, orc;

   if(!arg) {

     set_light(1);
     short_desc = "Orcs entrance";
     long_desc = 
"The stench of evil fills this place.  It looks as though you have entered\n"+
"an orc lair!\n";

   dest_dir = ({ "players/blue/castle/entry1","down",
                 "players/blue/castle/orcs2e","east",
                 "players/blue/castle/orcs2w","west",
                 "players/blue/castle/entry3","up"
     });

if(!present("orc",this_object())) {
   i=0;
while (i<5)
{

orc=clone_object("players/blue/monster/orc");
move_object(orc, this_object());
   i +=1;
   }
}
}
}
