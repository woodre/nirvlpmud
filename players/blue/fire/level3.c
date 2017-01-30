/* [5.25.01] Verte edited the long desc so it wasn't like, 125 chars per line ;) */
inherit"room/room";

reset(arg) {

   object heat, hot, blister, boil, fever, bic;

   if(!arg) {

   set_light(1);
   short_desc = "The Third level of Fire";
   long_desc = 
"  The soles of your boots begin sticking to the floor as you enter this\n"+
"hellishly hot room.  Waves of heat rise from the floor and\n\
blur your vision.  Sounds of sudden explosions ring in your\n\
ears, coming from up above.  You feel weak from the heat,\n\
but still have the urge to press on.\n\
   There is a stairway that leads up and down.\n";

dest_dir = ({
   "players/blue/fire/level4.c","up",
   "players/blue/fire/level2.c","down"
   });

heat=clone_object("players/blue/monster/lesser_fire");
   heat->set_name("heat");
   heat->set_short("Heat, a hyperthermo demon");
   move_object(heat, this_object());
bic=clone_object("players/blue/weapons/bic");
   bic->set_short("Heat's bic lighter");
   move_object( bic, heat);
   command("wield bic",heat);

blister=clone_object("players/blue/monster/lesser_fire");
   blister->set_name("blister");
   blister->set_short("Blister, a hyperthermo demon");
   move_object(blister, this_object());
bic=clone_object("players/blue/weapons/bic");
   bic->set_short("Blister's bic lighter");
   move_object( bic, blister);
   command("wield bic",blister);

fever=clone_object("players/blue/monster/lesser_fire");
   fever->set_name("fever");
   fever->set_short("Fever, a hyperthermo demon");
   move_object(fever, this_object());
bic=clone_object("players/blue/weapons/bic");
   bic->set_short("Fever's bic lighter");
   move_object( bic, fever);
   command("wield bic",fever);

boil=clone_object("players/blue/monster/lesser_fire");
   boil->set_name("boil");
   boil->set_short("Boil, a hyperthermo demon");
   move_object(boil, this_object());
bic=clone_object("players/blue/weapons/bic");
   bic->set_short("Boil's bic lighter");
   move_object( bic, boil);
   command("wield bic",boil);

hot=clone_object("players/blue/monster/lesser_fire");
   hot->set_name("hot");
   hot->set_short("Hot, a hyperthermo demon");
   move_object(hot, this_object());
bic=clone_object("players/blue/weapons/bic");
   bic->set_short("Hot's bic lighter");
   move_object( bic, hot);
   command("wield bic",hot);

   }
}
