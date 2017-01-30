/* First, you have to inherit the file you wish to set the functions to. */

inherit "room/room";

/*Next you need to declare any objects, strings, or integer's. such as */

object brutus, armor, weapon, money;

reset(arg) {               /* This is the reset, at a random point, the game sends out*/

  if(!arg) {                /* a signal to reset the rooms, to reset monsters and such*/

    set_light(1);                     /* This sets the light, 1 for light, 0 for dark */

  }

    if (!brutus || !living(brutus)) {
      brutus=clone_object("obj/monster.talk");
      call_other(brutus, "set_name", "brutus" );
      call_other(brutus,"set_short","Brutus");
      call_other(brutus,"set_long",
        "Brutus is an example of a talking monster.  If Rumplemintz\n"+
        "had cloned /obj/monster.c instead, he simply would not \n"+
        "have to code the load_chat and chat_chance functions.\n");
      call_other(brutus,"set_level",10);
      call_other(brutus,"set_hp",400);
      call_other(brutus,"set_ac",10);
      move_object(brutus,this_object());

      money=clone_object("obj/money");
      call_other(money,"set_money",random(2000));
      move_object(money,brutus);

      call_other(brutus,"set_chat_chance",20);
      call_other(brutus,"set_a_chat_chance",33);
      call_other(brutus,"load_chat","Brutus says: Good example huh\n");
      call_other(brutus,"load_a_chat","Brutus says: This is what I say when I'm attacked\n");

      armor=clone_object("obj/armor");
      call_other(armor,"set_name","shield");
      call_other(armor,"set_short","An Example shield");
      call_other(armor,"set_alias","shield");
      call_other(armor,"set_long","A truly well coded example shield.\n");
      call_other(armor,"set_value",250);
      call_other(armor,"set_ac",1);
      call_other(armor,"set_type","shield");
      transfer(armor,brutus);
      call_other(brutus,"init_command","wear shield");

      weapon=clone_object("obj/weapon");
      call_other(weapon,"set_name","example stick");
      call_other(weapon,"set_short","An example stick");
      call_other(weapon,"set_alias","stick");
      call_other(weapon,"set_long","A suprisingly strong stick!\n");
      call_other(weapon,"set_value",1000);
      call_other(weapon,"set_class",18);
      transfer(weapon,brutus);
      call_other(brutus,"init_command","wield stick");
      }

    short_desc = "An Example room";                          /* the short description */

    no_castle_flag = 0;                     /* means that you can't put a castle here */

    long_desc = "\n" +                             /* long descrip.  \n  means return */
      "     This is a nice example room, coded by Rumplemintz so that all\n"+
      "the new wizards would have some examples.\n";

/* The '+' means continue to the next line, the semi-colon signals the end of */
/* the description */

     dest_dir= ( {          /*  dest_dir is the direction and place it will take you  */

       "room/church", "north",
	"open/EXAMPLES/exampleroom2", "south",
       "room/shop", "east",

                });
}
