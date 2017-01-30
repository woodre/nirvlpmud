/* 
 *  The equipment chamber of the Bards Guild of Ryllian
 *  v3.0 by Geoffrey Z. / Saber
 *
 */

#define tp this_player()->query_name()
#define TP this_player()

inherit "room/room";

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg) {  

 if(!present("laura"))  {
 move_object(clone_object("/players/saber/closed/bard/mon/laura.c"), this_object());  }
 
  if(!arg){

  set_light(1);
  short_desc="Chamber of Tools";
 
  long_desc=
 BOLD+"Chamber of Tools"+NORM+"\n"+
 "The Chamber of Tools is a large room of mahogany construct, filled with row\n"+
 "upon row of shelves, racks and tables.  Instruments of all shapes and sizes\n"+
 "rest upon the racks and tables, while Bardic swords, daggers and armor fill\n"+
 "the remaining racks and shelves.  Lockers are set up against the far wall.\n";

items=({
 "floor","The floor is smooth and dark, and constructed from beautiful mahogany wood",
 "chamber","You are in the "+BOLD+"Chamber of Tools"+NORM+"",
 "room","You are in the "+BOLD+"Chamber of Tools"+NORM+"",
 "wood","The chamber is constructed entirely from polished mahogany wood",
 "mahogany","The chamber is constructed entirely from polished mahogany wood",
 "shelves","The shelves are filled with weapons and armor",
 "shelf","The shelves are filled with weapons and armor",
 "racks","The racks are filled with instruments and weapons",
 "rack","The racks are filled with instruments and weapons",
 "tables","The tables are filled with instruments and armor",
 "table","The tables are filled with instruments and armor",
 "swords","Many Bardswords hang from the racks",
 "sword","Many Bardswords hang from the racks",
 "daggers","Many daggers hang from the racks",
 "dagger","Many daggers hang from the racks",
 "armor","Many suits of bardic chainmail rest upon the tables",
 "instruments","Many Bardic instruments rest upon the raks and tables",
 "instrument","Many Bardic instruments rest upon the raks and tables",
 "lockers","Bardic weapons and armor lockers.  You can store and withdraw:\n"+
           "\tBardswords\tStorm Daggers\tChainmail\n"+
           "within Bardic lockers.  You can < store > and < retrieve > items.\n"+
           "You can also < check > what you have stored",
 "locker","Bardic weapons and armor lockers.  You can store and withdraw:\n"+
          "\tBardswords\tStorm Daggers\tChainmail\n"+
          "within Bardic lockers.  You can < store > and < retrieve > items.\n"+
          "You can also < check > what you have stored",
 });

  dest_dir=({
 "/players/saber/closed/bard/r/ward.c","north",
 "/players/saber/closed/bard/r/word.c","east",
           });
  }   }
  
  
init()  {
 ::init();

 if(!present("laura"))  {
 move_object(clone_object("/players/saber/closed/bard/mon/laura.c"), this_object());  }

if(!present("instrument",this_player()) && this_player()->is_player())  {
  
  write("You get the brief image of a "+BLU+"blue circle"+NORM+" before\n\n"+
        BOLD+" * * * * *  B O O M  * * * * *"+NORM+"\n\n"+
        "Your body flies through space.\n\nYou find yourself somewhere new.\n");
  say(tp+" bounces off the "+BLU+"Circle of Warding"+NORM+".\n");
  move_object(this_player(),"/room/void");
  tell_room(environment(this_player()), tp+" falls screaming from the sky.\nTHUD.\n");
  return 1;
        }

  add_action("search","search");
  add_action("check","check");
  add_action("store","store");
  add_action("retrieve","retrieve");
       }


search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1; 
       }


check()  {
object ob;

  ob = present("instrument", this_player());

  say(tp+" scans the weapons racks.\n");
  write("You have "+BOLD+ob->query_sword()+NORM+" Bardswords stored.\n"+
        "You have "+BOLD+ob->query_dagger()+NORM+" Storm Daggers stored.\n"+
        "You have "+BOLD+ob->query_armor()+NORM+" chainmail suits stored.\n");
  
  return 1;
       }
       
       
retrieve(str)  {
object ob;
int number;

  ob = present("instrument", this_player());

  if(str != "sword" && str != "dagger" && str != "armor")  {
    write("You can only retrieve < sword > < dagger > or < armor >\n");
    return 1;
        }

  if(str == "sword" && ob->query_sword() < 1)    { no(str);  return 1; }
  if(str == "dagger" && ob->query_dagger() < 1)  { no(str);  return 1; }
  if(str == "armor" && ob->query_armor() < 1)    { no(str);  return 1; }
  
  if(str == "sword")  {
    write("You withdraw a Bardsword from your locker.\n");
    say(tp+" withdraws a Bardsword from "+this_player()->query_possessive()+" locker.\n");
    move_object(clone_object("/players/saber/closed/bard/itm/w/bsword.c"), 
                environment(this_player()));
    command("get sword", TP);
    number = ob->query_sword() - 1;
    ob->set_sword(number);
    return 1;
       }
  
  if(str == "dagger")  {
    write("You withdraw a Storm Dagger from your locker.\n");
    say(tp+" withdraws a Storm Dagger from "+this_player()->query_possessive()+" locker.\n");
    move_object(clone_object("/players/saber/closed/bard/itm/w/sdagger.c"), 
                environment(this_player()));
    command("get dagger", TP);
    number = ob->query_dagger() - 1;
    ob->set_dagger(number);
    return 1;
       }
       
  if(str == "armor")  {
    write("You withdraw a suit of chainmail from your locker.\n");
    say(tp+" withdraws a suit of chainmail from "+this_player()->query_possessive()+" locker.\n");
    move_object(clone_object("/players/saber/closed/bard/itm/a/elfchain.c"), 
                environment(this_player()));
    command("get armor", TP);
    number = ob->query_armor() - 1;
    ob->set_armor(number);
    return 1;
       }
       }


store(str)  {
object ob, ob2;
int number;

  ob = present("instrument", TP);

  if(str != "sword" && str != "dagger" && str != "armor")  {
    write("You can only store < sword > < dagger > or < armor >\n");
    return 1;
        }

  if(str == "sword" && !(ob2 = present("bardsword", TP)))     { nope(str);  return 1; }
  if(str == "dagger" && !(ob2 = present("storm dagger", TP))) { nope(str);  return 1; }
  if(str == "armor" && !(ob2 = present("chainmail", TP)))     { nope(str);  return 1; }
  
  if(str == "sword")  {
    write("You put a Bardsword in your locker.\n");
    say(tp+" puts a Bardsword in "+TP->query_possessive()+" locker.\n");
    command("drop bardsword", TP);
    number = ob->query_sword() + 1;
    ob->set_sword(number);
    destruct(ob2);
    return 1;
       }
  
  if(str == "dagger")  {
    write("You put a Storm Dagger in your locker.\n");
    say(tp+" puts a Storm Dagger in "+TP->query_possessive()+" locker.\n");
    move_object(clone_object("/players/saber/closed/bard/itm/w/sdagger.c"), 
                environment(this_player()));
    command("drop storm dagger", TP);
    number = ob->query_dagger() + 1;
    ob->set_dagger(number);
    destruct(ob2);
    return 1;
       }
       
  if(str == "armor")  {
    write("You put a suit of chainmail in your locker.\n");
    say(tp+" put a suit of chainmail in "+TP->query_possessive()+" locker.\n");
    move_object(clone_object("/players/saber/closed/bard/itm/a/elfchain.c"), 
                environment(this_player()));
    command("drop chainmail", TP);
    number = ob->query_armor() + 1;
    ob->set_armor(number);
    destruct(ob2);
    return 1;
       }
       }
       

no(str)  {

  write("Your "+str+" locker is empty.\n");
  return 1;
        }

nope(str)  {

  write("Your "+str+" does not fit in the locker.\n");
  return 1;
        }
