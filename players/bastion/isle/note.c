
#undefine EXTRA_RESET
#define EXTRA_RESET extra_reset()

extra_reset(arg) {
   object ob;
   if (!present("small note")) {
      ob = clone_object("obj/treasure");
      ob->set_id("small note");
      ob->set_alias("note");
      ob->set_short("a small note");
      ob->set_long("It has some writing on it.\n");

      ob->set_read("   /-\---------------------------\ \n"+ 
                   "  (   )                           )\n"+
                   "   \_/___________________________/ \n"+
                   "    |                           | \n"+
                   "    | Dear Adventurer,          | \n"+
                   "    |                           | \n"+
                   "    | I hope you enjoy your     | \n"+
                   "    | visit to my islands. If   | \n"+
                   "    | you are a mere beginner,  | \n"+
                   "    | than perhaps you might try| \n"+
                   "    | killing some seagulls.    | \n"+
                   "    |                           | \n"+
                   "    | Take care should you      | \n"+
                   "    | venture into one of the   | \n"+
                   "    | caves though. It has been | \n"+
                   "    | rumored that a terrible   | \n"+
                   "    | beast has mades it's lair | \n"+
                   "    | deep within one!          | \n"+
                   "    |                           | \n"+
                   "    | Enjoy!                    | \n"+
                   "    | Bastion the Archmage      | \n"+
                   "   /-\---------------------------\\n"+
                   "  (   )                           )\n"+
                   "   \_/___________________________/ \n" );
      move_object(ob, this_object());
   }
}


