inherit"room/room";

reset(arg) {
   object statue,plate,coins;

   if(!arg) {
   set_light(1);
   short_desc= "The Courtyard West";
   long_desc = 
"Standing in this otherwise empty corner of the courtyard is a red granite\n"+
"statue of an ancient warrior.  He wears a light suit of deep red granite\n"+
"armor, and looks poised and light footed.  He stares at you with a cold\n"+
"calm that chills you.\n";

dest_dir = ({
   "players/blue/castle/tree1","south",
   "players/blue/castle/courtyard2","east"
   });

statue=clone_object("obj/monster");
   statue->set_name("statue");
   statue->set_alias("stone statue");
   statue->set_level(20);
   statue->set_hp(600);
   statue->set_ac(25);
   statue->set_wc(20);
   statue->set_short("A granite statue");
   statue->set_long("Staring coldly at you is this living statue!!\n"+
             "He is covered in stone armor, yet seems to be agile.  He "+
      "stares coldly\nat you and then raises\na huge granite fist!\n");
   statue->set_gender(1);
   statue->set_aggressive(1);
   move_object(statue, this_object());

plate=clone_object("obj/armor");
   plate->set_name("plate");
   plate->set_short("stone platemail");
   plate->set_alias("plate");
   plate->set_alt_name("stone plate");
   plate->set_ac(4);
   plate->set_weight(10);
   plate->set_value(4000);
   plate->set_long("A strange suit of armor....it looks and feels like grani"+
           "te, but is light\nand comfortable.  It must be enchanted.\n");
   move_object(plate,statue);

coins=clone_object("obj/money");
   coins->set_money(1000 + random(750));
   move_object(coins, statue);
   }
}

