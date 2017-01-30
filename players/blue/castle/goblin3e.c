inherit "room/room";

reset(arg) {
   int i;
   object gob,wep;
   if(!arg) {
     set_light(1);
     short_desc = "Goblins east";
     long_desc =
"Through the faint light of a torch attached to the wall, you can make out\n"+ 
"some sort of movement. You realize that you've interupted a goblin tribal\n"+
"dance!\n";

dest_dir = ({
     "players/blue/castle/entry3","west"
     });
   }

if(!present("goblin",this_object())) {
   i = 0;
  while (i < 5)
  {
   gob = clone_object("obj/monster");
   gob->set_name("goblin");
   gob->set_level(2);
   gob->set_male();
   gob->set_aggressive(1);
   gob->set_ac(3);
   gob->set_al(-20);
   gob->set_hp(25);
   gob->set_long("This is a little goblin.  He looks mean.\n");
   move_object(gob, this_object());

wep=clone_object("obj/weapon");
   wep->set_name("sword");
   wep->set_class(7);
   wep->set_value(50);
   wep->set_weight(4);
   wep->set_short("A short sword");
   move_object(wep, gob);
   i += 1;
   }
}
}
