/*  Playbill in Hotel Casino  */

#include <ansi.h>
reset(arg) {
     if(!arg) return;
}

/* Identifying the object. */                               
id(str)  {
     return str == "playbill";                              
     }                                       


long(){
     write("The free-stanning playbill displays garish photos and vivid\n"+
      "descriptions of various performers who will be appearing in\n"+
      "the hotel theater adjoining the Restaurant, as well as a schedule\n"+
      "of events.  Perhaps you could 'read playbill' to see what is\n"+
      "currently showing.\n");
     }

short(){
      write("A garish, free-standing playbill\n");                 
     }

get(){
     write("The Playbill is securely attached to the floor.");
     return 0;
     }

/* I've set this so that you need to read the schedule to see what is playing. */

init() {
     add_action("read_playbill","read");
}


read_playbill(str) {
string show;
  if(!str || str !="playbill") return 0;
  call_other("players/aingeal/casino/rooms/theater","blee",0);
  show=call_other("players/aingeal/casino/rooms/theater","query_show",0);
  if(show=="none") {
     write("Tonight's show has been CANCELED.\n");
     write("The Casa de Nirvana Hotel and Casino apoligizes for this \n"+
           "unforseen event.\n");
     return 1;
  }
	if (show=="elvis") {                                   
               write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                        "The ONE....the ONLY.....THE KING! \n"+
           "Don't Forget Your Blue Suede Shoes as you find yourself\n"+
                       "All Shook Up With The Legendary ELVIS PRESLEY! \n"+
                        "-- Limited Time Appearance ! -- \n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }

           if (show=="newton") {                                   
               write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                   "Treat yourself to an amazing evening of pop, rhythm and blues, ballads, \n"+
                   "country, rock, and instrumental music with America's number one \n"+
                   "entertainer, Mr. Las Vegas himself - the incomparable WAYNE NEWTON! \n" );
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }
           if (show=="siegfried") {                                   
               write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                        "The Magical   The Mystical   SIEGFRIED & ROY! \n"+
           "The Show of the Century, featuring 88 cast members   plus  \n"+
        "the Royal White Tigers of Nevada and the Magical White Lions,\n"+
                        "will keep you on the edge of your seat, begging for more! \n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }
           if (show=="miller") {                                   
               write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                        "The strikingly funny Emmy Award Winner DENNIS MILLER!  \n"+
           "Star of the Dennis Miller Show, and former cast member of \n"+
                        "Saturday Night Live, Dennis Miller will keep you laughing all evening \n"+
                        "with his piercing rants about real life in all of its irony.  \n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }
           if (show=="carey") {                                   
               write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                        "DREW CAREY Hosting a Special Episode of\n"+
           "WHO'S LINE IS IT ANYWAY? \n"+
                      "Special Guest Appearances by Ryan Stiles,\n"+
                      "Colin Mochrie, and Wayne Brady!\n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }
           if (show=="manilow") {                                   
              write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                 "Rolling Stone Magazine has dubbed him\n"+
                 "Our Generation's Greatest Entertainer...\n"+
                  "The timeless BARRY MANILOW kicks off his World Tour, \n"+
                  "featuring his newest hits from his Broadway Musical, -HARMONY-! \n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }
           if (show=="knight") {                                   
             write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                 "A Knight To Remember........GLADYS KNIGHT! \n"+
                 "The whole family will enjoy this musical tribute\n"+
                 "to her life, her spirit, and her legacy.\n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }
           if (show=="williams") {                                   
             write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                 "One of the most gifted comedians and actors of our time, \n"+
                 "ROBIN WILLIAMS opens his Robin Williams Live Tour with\n"+
                 "an evening of unforgettable comedy sure to keep you laughing\n"+
                 "long into the night!  A must-see show, at Casa de Nirvana\n"+
                 "for a limited time only!\n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }
           if (show=="liberace") {                                   
              write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                 "The One and Only.........Mr. Showmanship........LIBERACE! \n"+
                 "Don't miss this spectacular show filled with the best of Liberace's \n"+
                 "seemingly endless musical repertoire, including a unique mix of classical,\n"+
                 "boogie woogie, movie themes, cocktail jazz, and sentimental ballads.\n"+
                 "You'll laugh....you'll cry....you'll beg for more of the musical magic\n"+
                  "of the LEGENDARY LIBERACE!\n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }
           if (show=="carlin") {                                  
               write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                    "The sardonic and irrepressible comedy of GEORGE CARLIN! \n"+
                    "After poking fun at mainstream society for forty years, \n"+
                    "George Carlin still keeps audiences on their toes, living up\n"+
                    "to his reputation as the comedic genius that has made him one of \n"+
                    "the most respected and best loved comedians of all time.\n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }
           if (show=="penn") {                                  
               write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                     "--More Than Magicians -- More Than Comedians --\n"+
                     "The Amazing PENN and TELLER!\n"+
                     "Penn and Teller are master showmen who will captivate\n"+
                     "your imagination and sense of humor and won't let it go\n"+
                     "until the final curtain.  Don't miss this opportunity to see the \n"+
                      "undisputed kings of the lost art of Vaudville! \n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }
           if (show=="cirque") {                                  
               write("NOW PLAYING on the Casa de Nirvana Hotel and Casino Main Stage! \n"+
                   "MYSTERE by CIRQUE du SOLEIL!\n"+
                   "Even if you've seen a Cirque du Soleil production,\n"+
                   "very little can prepare you for this grand and glorious experience.\n"+
                  "Part circus, part theater, this Canadian based troupe puts on a show\n"+
                  "filled with heart-stopping acrobatics and astounding feats of human\n"+
                  "Strength, all wrapped up in a package that is at artistic and interesting.\n"+
                  "Mystere is thrilling, funny, erotic, frightening, awe-inspiring, and \n"+
                  "ultimately uplifting....only the best at Casa de Nirvana!\n");
               say(this_player()->query_name()+"studies the playbill.\n");
     return 1;
           }

     }

