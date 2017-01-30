inherit "room/room";

reset(arg) {
   object orc, wep;
   int n,i;

   if(!arg) {

     set_light(1);
     short_desc = "West orc room";
     long_desc =
"Garbage litters the ground and an odor reaches your nose that is not very\n"+
"pleasent.  In fact, you have stepped in orc droppings....\n";

dest_dir = ({
   "players/blue/castle/orcs2wb","north",
   "players/blue/castle/entry2","east"
     });
   }

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
