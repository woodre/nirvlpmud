id(str) { return str == "book"; }
reset() {}
   long() {write("	Welcome Newbie to the World of Nirvana.\n"+
                 "There are a number of commands and places that\n"+
                 "are important to know about.  Type `help' to see\n"+
                 "a list of commands that you can learn about by\n"+
                 "typing `help command', where command is the \n"+
                 "command you would like to learn about.\n"+
                 "	In addition to this are a listing of places\n"+
                 "that every newbie should know about.\n"+
                 "To learn about these places and some newbie areas\n"+
                 "please type `read index'.\n");}
   short() {return "A brand spanking NEW newbie book";}
init() {
   add_action("Readbook","read");
   add_action("drop_object","drop");
}
Readbook(arg) {
   if(arg=="book"){
      return long();
      return 1;
   }
   if(arg=="index"){
      write("	  This is the index of the newbie book.  Contained\n"+
            "  here is a listing of pages of information to help you\n"+
            "  on your way.\n"+
            "<<<<<<<<<<<<<<<<<<<<-----INDEX----->>>>>>>>>>>>>>>>>>>>\n"+
            "DESCRIPTION                                      PAGE #\n"+
            "-------------------------------------------------------\n"+
            "Listing of Basic Places(ie. pub)                    1\n"+
            "Map (Basic Skeleton)                                2\n"+
            "Guilds (Info on diff Guilds)                        3\n"+
            "Newbie Areas (Most popular)                         4\n"+
            "Newbie Areas (Less popular)                         5\n"+
            "Hints on play                                       6\n"+
            "-------------------------------------------------------\n"+
            "	To get the above mentioned information merely\n"+
            "type `read page #' where # is the page number you\n"+
            "want to read.  Hope you enjoy!\n"+
            "                                        -Dersharp\n");
      return 1;
   }
   if(arg=="page 6"){
      write("	  Welcome newbie to the wonderful world of Nirvana.\n"+
            "  In order to get you started I have listed a number of\n"+
            "  good things to know before you start your adventures.\n"+
            "  They are listed below.\n"+
            "\n"+
            "(1):  First of all is to get some newbie equipment from\n"+
            "        the newbie dispenser south of the church.  This\n"+
            "        available to newbies of a certain level.\n"+
            "(2):  Second, is to get you quicktyper and emotions\n"+
            "        enhancer from the room one west of the shop.\n"+
            "        these two devices help you get the hang of \n"+
            "        adventuring here.\n"+
            "(3):  Read all the documentation in the help files.\n"+
            "        There is a lot there that will help you very\n"+
            "        much in your travels.\n"+
            "(4):  Perhaps the best thing to do at the beginning\n"+
            "        is to ask for help.  Many players are willing\n"+
            "        to help a newbie and it won't cost more than\n"+
            "        twice what you have(Just Kidding! :)).\n"+
            "(5):  Some other things include setting your wimpy\n"+
            "        percent so you can run away from monsters.\n"+
            "        Also party up with other people to increase\n"+
            "        your fighting effectiveness.\n"+
            "(6):  The most important thing you should do is to\n"+
            "        explore the different areas.  You never know\n"+
            "        when a new place will open up, giving you \n"+
            "        greater chances for riches and experince.\n"+
            "\n"+
            "	  In addition I would like you all to tell us ideas\n"+
            "  of things you would like to see here.  You never know,\n"+
            "  one of us may know how to code it! :)\n"+
            "\n");
      return 1;
   } 
   if(arg=="page 5"){
      write("	  The areas listed here are some of the little less\n"+
            "  known areas.  However this usually means that when\n"+
            "  other places are being sacked, these are still very\n"+
            "  well stocked with armors, weapons, and money!\n"+
            "  Enjoy!\n"+
            "\n"+
            "Creator--------------Name------Locale from 1s of Church--\n"+
            "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"+
            "\n"+
            "Dersharp        Pillars of Peril         6w,3s,5w,s\n"+
            "Rumplemintz     Orcs of Kor             4w,6n,2u,e,ride,e\n"+
            "Mathiast        Elve's                  2w,enter rift,s,e\n"+
            "Heroin          Hunting Grounds         4w,2n,1w,enter grounds\n"+
            "                                        enter,newbie\n"+
            "Pavlik          Thief Cellar  5e,2n,climb trail,u,enter,d\n"+
            "Blue            ??????       4w,2n,enter castle,read sign\n"+
            "Saber           Hades Rift          5e,3n,w,enter rift,2w\n"+
            "Sandman         Daydreams           2e,s,d,lay on bed,s,e\n"+
            "Boltar          Santa's                           6w,n...\n"+
            "Static          NEWBIE                         4w,5n,2d,s\n"+
            "Persephone      ??????                   w,enter portal,n\n"+
            "\n"+
            "---------------------------------------------------------\n"+
            "	  These are only some of the other newbie areas.  I am\n"+
            "certain there are more to be found.  If you find one and \n"+
            "want it to be listed just mail me. :)\n"+
            "                                  -Dersharp\n");
      return 1;
   }
   if(arg=="page 4"){
      write("	  Here are some of the more popular newbie areas\n"+
            "  that grace this mudd with their presence.  Although\n"+
            "  these are the most popular do not forget to look at\n"+
            "  the other areas listed on page 5.\n"+
            "\n"+
            "Creator--------------Name------Locale from 1s of Church--\n"+
            "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"+
            "\n"+
            "Demoder              ?????                       8e,u,n,e\n"+
            "Scathe               DoppleKillingGrounds        9e,s,d,s\n"+
            "Hawkeye              M*A*S*H            5e,s,enter portal\n"+
            "\n"+
            "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"+
            "	  Please take the time to look over the other areas.\n");
      return 1;
   }
   if(arg=="page 3"){
      write("	  Listed below are a listing of the guilds up at\n"+
            "  the time this was created....ummm 10/18/93.  In\n"+
            "parenthesis is the name of the creator of.  There\n"+
            "will probably be more in time.  I hope so. :) \n"+
            "\n"+
            "--GUILD--------------------Information-------------------\n"+
            "\n"+
            "Masons(Sandman,Molasar)Basic Guild, Low enrollment\n"+
            "                         Guild is e then n of Adv Guild\n"+
            "Vampires(Nooneelse)    Powerful Guild, Pets, good spells \n"+
            "                         Very social, hard to get in.  \n"+
            "Bards                  New Guild. Emphasis on the social\n"+
            "                          element of muds.  No pkers.\n"+
            "                         Powers in lore and illusion!\n"+
            "Shadow Guild(Blue)     New guild.  Servants and good\n"+
            "                         spells.  Other things also.\n"+
            "                         locale 4w,2n, enter pool from.\n"+
            "                         from s of church.\n"+
            "Monks(Hawkeye,Pavlik)  Another new guild.  Interesting\n"+
            "                         guild abilities including:\n"+
            "                         aut-setting ac and wc, pets\n"+
            "                         social.  Found 5e,s,w from \n"+
            "                         church.\n"+
            "---------------------------------------------------------\n");
      return 1;
   } 
   if(arg=="page 2"){
      write("	  Below is a map of the mudd, a VERY rough one!\n"+
            "=========================================================\n"+
            "                    ^\n"+ 
            "                    *\n"+
            "                    |\n"+
            "                *-*-*-*\n"+
            "                  | | |\n"+
            "                  *-*-*\n"+
            "                  | | |\n"+
            "               <*-*-*-*-*\n"+
            "                  | | |\n"+
            "                  *-*-*             *\n"+
            "                    |               |\n"+
            "                    *       C   *   * ^     ^\n"+
            "                    |       |   |   | |     |\n"+
            "               <*-*-*-*-*-*-*-*-*-*-*-*-*-*-*>\n"+
            "                |               |   |\n"+
            "                *               *   *\n"+
            "                |               |   |\n"+
            "                *               *   *\n"+
            "================================================\n"+
            "	  Once again this is a rough map.  Please take the\n"+
            "  time to explore all the areas.  Thanks!!\n");
      return 1;
   }                                       
                                                                     
   if(arg=="page 1"){
      write("	  The first things a newbie should be aware of when\n"+
            "  starting fresh on a new mudd is the basic layout.  In\n"+
            "  other words...Where stuff is!  Listed below are the \n"+
            "  most frequented places a newbie needs to know about.\n"+
            "\n"+
            "Place----------------------------Locale from 1s of church\n"+
            "---------------------------------------------------------\n"+
            "Adventurer's Guild                        3e,s\n"+
            "Main Shop                                 3e,n\n"+
            "Main Pub                                  2e,n,e\n"+
            "\n"+
            "---------------------------------------------------------\n"+
            "	  The Adventurer's guild is an important place to know\n"+
            "  about since important things are posted there from time\n"+
            "  to time.  You also can learn about the rules there.\n");
      return 1;
   }
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 0; }
drop_object(str) {
    if (str == "all") {
        destruct(this_object());
        return 1;
    }
    if (!str || !id(str))
        return 0;
write("The book for newbies is taken away and saved for another newbie.\n");
   say(capitalize(this_player()->query_real_name())+" drops a newbie book!\n");
   destruct(this_object());
   return 1;
}
