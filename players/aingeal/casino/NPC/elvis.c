/* Elvis Presley */


inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold, guitar;
  gold = clone_object("obj/money");
  gold->set_money(random(151) + 1000);
  move_object(gold,this_object());

  guitar = clone_object("/players/aingeal/casino/weapons/guitar.c");
move_object(guitar,this_object());
   
     set_name("elvis");
     set_alias("Elvis");
     set_alt_name("entertainer");
     set_short("Elvis Presley");
     set_race("human");
     set_long("The King is resplendent, perhaps even a little gaudy, in his\n"+
              "notorious Blue Swirl jumpsuit.  Skin-tight, cut low to expose\n"+
              "his chest, and criss-crossed with looping rhinestone patterns\n"+
              "culimating in a wide, glittering belt, the jumpsuit flashes\n"+
              "blindingly at you with each gyration of the King's body as he\n"+
              "belts out yet another heart-stopping hit with his golden voice.\n");
     set_level(17);
     set_ac(12 + random(2));
     set_wc(22 + random(2));
     set_hp(300 + random(50));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(12);
     set_a_chat_chance(25);
     /* Regular chats */
     load_chat("Elvis says: Thank you....thank you very much.\n");
     /* From 'All Shook Up' */
     load_chat("Elvis gyrates around the stage as he sings: I'm in love....I'm ALL SHOOK UP!\n");
     /* From 'Blue Suede Shoes' */
     load_chat("Elvis struts around the stage as he sings: You can do anything but lay off of my Blue Suede Shoes!\n");
     /* From 'Jailhouse Rock' */
     load_chat("Elvis rocks: Everybody in the whole cell block\n"+
		     "was dancin' to the Jailhouse Rock!\n");
     /* From 'Shake, Rattle & Roll' */
     load_chat("Elvis sings: I said Shake, Rattle and Roll!\n");
     /* From 'Return to Sender' */
     load_chat("Elvis sings: Return to sender.....address unknown....\n");
     /* From 'Teddy Bear' */
     load_chat("Elvis leans close as he croons: Just wanna be your Teddy Bear....\n");
     /* From 'Suspicious Minds' */
     load_chat("Elvis sheds a tear as he croons: We can't go on together with suspicious minds...\n");

     /* Combat chats */
     /* Direct quote from Elvis */
     load_a_chat("Elvis insists: I ain't no saint...!\n");
     /* From 'All Shook Up' */
     load_a_chat("Elvis cowers before you as he sings: My hands are shaky and my knees are weak...\n"+
		     "I can't seem to stand on my own two feet!\n");
     /* From 'Don't Be Cruel' */
     load_a_chat("Elvis sings: Don't be cruel to a heart that's true.\n");
     /* From 'Shake, Rattle & Roll' */
     load_a_chat("Elvis draws back a menacing fist as he thunders: I believe it to my soul you're the devil in nylon hose!\n");
     /* From 'Only The Strong Survive' */
     load_a_chat("Elvis warns: Only the strong survive!\n");
     /* From 'Playing For Keeps' */
     load_a_chat("Elvis sings: Oh, don't make me sorry that I fell in love with you!\n");
     /* From 'Release Me' */
     load_a_chat("Elvis begs in song: Please release me, let me go...\n");

     }
}

