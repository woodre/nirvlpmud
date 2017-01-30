inherit "room/room";
int i;

reset(arg) {
   object gob , wep;
   if(!arg) {
     set_light(1);
     short_desc = "Goblin entrance";
     long_desc = 
"Old furniture and garbage litter the floor of this small dark room. A faint\n"+
"light rises up from the hole in the floor, casting eerie reflections on\n"+
"the ceiling. This seems to be some creatures home.\n";

dest_dir = ({
   "players/blue/castle/goblin3e","east",
   "players/blue/castle/goblin3w","west",
   "players/blue/castle/entry2","down"
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
   gob->set_ac(3);
   gob->set_al(-20);
   gob->set_hp(25);
   gob->set_aggressive(1);
   gob->set_long("This is a little goblin.  He looks mean.\n");
   move_object(gob, this_object());

wep=clone_object("obj/weapon");
   wep->set_name("sword");
   wep->set_value(50);
   wep->set_class(6);
   wep->set_weight(4);
   wep->set_short("A short sword");
   move_object(wep, gob);
   command("wield sword", gob);
   i += 1;
   }
}
}
