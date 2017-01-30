inherit "room/room";

reset(arg) {
   object whip,hand,coins;
   int i;

   if(!arg) {
   set_light(1);
   short_desc = "A stable";
   long_desc = 
"This appears to be a stable, although it has been years since any horses we"+
"re\nkept in it.  The six stalls are in ruin, and cobwebs litter the ceiling"+
".\nYou think that you sense something evil, far worse then what you might\n"+
"normally find in a stable.\n";

dest_dir = ({
   "players/blue/castle/courtyard2","south"
   });

   if(!present("hand", this_object())) {
   i=0;
   while(i<3)
     {
   hand = clone_object("obj/monster");
   hand->set_level(10);
   hand->set_ac(19);
   hand->set_name("hand");
   hand->set_short("An evil stable hand");
   hand->set_long(
     "After hundreds of years all alone, the stable hands have lost all sens"+
     "e of reality!\nThey think you must be a dangerous horse!\n");
   hand->set_aggressive(1);
   hand->set_gender(1);
   hand->set_hp(600);
   coins = clone_object("obj/money");
   coins->set_money(500);
   move_object(coins, hand);
   move_object( hand, this_object());

   whip = clone_object("obj/weapon");
   
   whip->set_name("whip");
   whip->set_short("A horse whip");
   whip->set_class(15);
   whip->set_long(
     "A really nasty old horse whip.\n");
   whip->set_value(2000);
   whip->set_weight(2);
   move_object(whip,hand);
   command("wield whip",hand);
  hand->set_wc(30);
   i += 1;
   }
}
}
}
