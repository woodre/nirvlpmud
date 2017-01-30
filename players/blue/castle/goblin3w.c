inherit "room/room";

int wep, lead;

reset(arg) {
   if(!arg) {
     set_light(1);
     short_desc = "Goblins west";
     long_desc = 
"Finally, through all this wreckage you come upon a moderatly furnished \n"+
"Sitting on a couch across the room is a goblin chieftan, easily the \n"+
"biggest goblin you've ever seen.  Well, he's still pretty small, but he \n"+
"doesn't look happy.\n";
dest_dir = ({
     "players/blue/castle/entry3","east"
     });
   }

if(!lead) {
   lead = clone_object("obj/monster");
   lead->set_name("chieftan");
   lead->set_race("goblin"); /* by verte */
   lead->set_level(6);
   lead->set_male();
   lead->set_ac(6);
   lead->set_aggressive(1);
   lead->set_hp(100);
   lead->set_short("A goblin chieftan");
   lead->set_long(" A really nasty looking goblin.  He looks like he is"+
                   " either annoyed or REALLY hungry.\n");
   move_object(lead, this_object());

wep = clone_object("obj/weapon");
   wep->set_name("axe");
   wep->set_class(15);
   wep->set_short("An ugly goblin axe");
   wep->set_value(1000);
   wep->set_weight(4);
   move_object(wep, lead);
   command("wield axe", lead);
  }
}
