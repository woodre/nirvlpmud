#define TPM this_player()->query_money()
#define tp this_player()->query_name()

object ob,ob2,ob3,ob4,ob5;


id(str) {return str == "laura";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "Laura the Quarter Mistress (paladin)";  }
long(){
write("Laura the Quarter Mistress (paladin) (female).\n");
write("A lovely young lady wearing bardic blue and black.  She has long black hair\n"+
      "and a mischievous smile on her friendly face.  If you ask her, she will tell\n"+
      "you a <list> of what she carries.\n"+
      "Laura is in good shape.\n"+
      "        Laura is carrying:\n"+
      "A Bardic Instrument (Fiddle).\n"+
      "A jeweled arabian dagger.\n");
        }

list()  {
write("Laura will let you <buy> the following:\n\n"+
 pad("",10)+" "+pad("1) A Bardsword",26)           +" :1000 golden coins\n"+
 pad("",10)+" "+pad("2) A Storm Dagger*",26)       +" : 100 golden coins\n\n"+

 pad("",10)+" "+pad("4) Storm Steel Chainmail",26) +" : 500 golden coins\n"+
 pad("",10)+" "+pad("5) A Shimmer Cloak*",26)      +" :  50 golden coins\n"+
 pad("",10)+" "+pad("6) A Signet Ring*",26)        +" :  50 golden coins\n"+
 pad("",10)+" "+pad("7) Black Leather boots",26)   +" : 100 golden coins\n"+
 pad("",10)+" "+pad("8) A Parrying Dagger",26)     +" :  50 golden coins\n\n"+

 pad("",10)+" "+pad("11) A Bardic Pouch",26)       +" : 350 golden coins\n"+
 pad("",10)+" "+pad("12) A Potion of Atonement",26)+" : 500 golden coins\n\n"+
 pad("",10)+" * These items are found within the Bardic Pouch.\n"+
 "\n");
     return 1;
}

init() {
 add_action("buy","buy");
 add_action("list","list");
 add_action("kill","kill");
}

kill(str)  {
if(str == "laura")  {
write("Laura catches your weapon and slaps you across the face!\n"+
      "OUCH!\n");
say(tp+" attacks Laura.\n"+
  "Laura catches "+tp+"'s weapon and takes slaps "+tp+" across the face.\n");
  return 1;
        }
        }


buy(str) {
int cost, value, weight, msg;
string STRING;

if (!str) {  write("Buy what?\n");  return 1;  }

 if (str == "1")  {
   msg = "a Bardsword";
   value = 1000;
   weight = 2;
   STRING = "/players/saber/closed/bard/itm/w/bsword.c";
        }

 else if (str == "2")  {
   msg = "a Storm Dagger";
   value = 100;
   weight = 0;
   STRING = "/players/saber/closed/bard/itm/w/sdagger.c";
        }

 else if (str == "4")  {
   msg = "a suit of Chainmail";
   value = 500;
   weight = 3;
   STRING = "/players/saber/closed/bard/itm/a/elfchain.c";
        }

 else if (str == "5")  {
   msg = "a Shimmer Cloak";
   value = 50;
   weight = 1;
   STRING = "/players/saber/closed/bard/itm/a/shimmer.c";
        }

 else if (str == "6")  {
   msg = "a Signet Ring";
   value = 50;
   weight = 1;
   STRING = "/players/saber/closed/bard/itm/a/ring.c";
        }

 else if (str == "7")  {
   msg = "a pair of boots";
   value = 100;
   weight = 1;
   STRING = "/players/saber/closed/bard/itm/a/boots.c";
        }

 else if (str == "8")  {
   msg = "a parrying dagger";
   value = 50;
   weight = 1;
   STRING = "/players/saber/closed/bard/itm/a/pdagger.c";
        }

 else if (str == "11")  {
   msg = "a Bard Pouch";
   value = 350;
   weight = 1;
   STRING = "/players/saber/closed/bard/itm/pouch.c";
        }

 else if (str == "12")  {
   msg = "a Potion of Atonement";
   value = 500;
   weight = 1;
   STRING = "/players/saber/food/atone.c";
        }
        
  else {
  write("Laura says 'What do you want to buy?'\n");
  return 1;
        }


if (call_other(this_player(), "query_money", 0) < value) {
  write("That costs "+value+" gold coins, which you don't have.\n");
  return 1;
        }

if (!(this_player()->add_weight(weight)))  {
	write("You can not carry more.\n");
	return 1;
	    }

 ob = clone_object(STRING);
 
 if(str == "11")  {
   ob2 = clone_object("/players/saber/closed/bard/itm/srose.c"); 
   ob3 = clone_object("/players/saber/closed/bard/itm/a/ring.c");
   ob4 = clone_object("/players/saber/closed/bard/itm/a/shimmer.c");
   ob5 = clone_object("/players/saber/closed/bard/itm/w/sdagger.c");
  move_object(ob2, ob);
  move_object(ob3, ob);
  move_object(ob4, ob);
  move_object(ob5, ob);
         }
 
 move_object(ob, this_player());
 write("You play "+value+" coins for "+msg+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys "+msg+".\n");
 call_other(this_player(), "add_money", - value);
 return 1;
        }
