/* bardswords value changed to 10k from 2.5k ... at sandman's request - mythos <3/30/96> */
/* took out the boots of sprinting.. they no longer exist - Mythos <3-31-96> */
#define TPM this_player()->query_money()
#define tp this_player()->query_name()

object ob,ob2,ob3,ob4,ob5;


id(str) {return str == "laura";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "Laura the Quarter Mistress of the Bards (paladin)";  }
long(){
write("Laura the Quarter Mistress of the Bards (paladin) (female).\n");
write("A lovely young lady wearing bardic blue and black.  She has long black hair\n"+
 "and a mischievous smile on her friendly face.  If you ask her, she will tell\n"+
 "you a <list> of what she carries.\n"+
 "Laura is in good shape.\n"+
 "        Laura is carrying:\n"+
 "A Bardic Instrument (Fiddle).\n"+
 "A jeweled arabian dagger.\n\n");
        }

list()  {
write("Laura will let you <buy> the following:\n"+
 pad("",10)+" "+pad("1) A leather jacket",25)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("2) Studded leather armor",25)+" : 300 golden coins\n"+
 pad("",10)+" "+pad("3) Elven chainmail",25)+" :1000 golden coins\n"+
 pad("",10)+" "+pad("4) Black leather boots",25)+" : 100 golden coins\n"+
 pad("",10)+" "+pad("5) A crystal dagger",25)+" : 100 golden coins\n"+
 pad("",10)+" "+pad("6) A bardsword <fire>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("7) A bardic pouch",25)+" : 300 golden coins\n"+
 pad("",10)+" "+pad("8) A potion of Atonement",25)+" : 300 golden coins\n"+
 pad("",10)+" "+pad("9) A bardsword <opera>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("10) A bardsword <rock>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("11) A blessed axe",25)+" :1250 golden coins\n"+
 pad("",10)+" "+pad("12) Boots of Sprinting",25)+" :1000 golden coins\n"+
 pad("",10)+" "+pad("13) A bardsword <R&B>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("14) A bardsword <DarkFire>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("15) A bardsword <Xmas>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("16) A Xmas Scoll",25)+" : 100 golden coins\n"+
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
int cost, value;

if (!str){
 write("Buy what?\n");
 return 1;
}
 if (str == "1")  {
   write("You buy an leather jacket.\n");
   value = 50;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
move_object(clone_object("/players/saber/armor/ljacket.c"),this_player());
}
else if (str == "3")  {
  write("You buy a suit of elven chainmail.\n");
   value = 1000;
if(TPM < value) {write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/elfchain.c"),this_player());
}
else if (str == "2")  {
  write("You buy a suit of studded leather armor.\n");
  value = 300;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/armor/stdleather.c"),this_player());
}
else if (str == "4")  {
  write("You buy a pair of black boots.\n");
  value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/boots.c"),this_player());
}
else if (str == "5")  {
  write("You buy a crystal dagger.\n");
  value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/dagger.c"),this_player());
}
else if (str == "6")  {
   write("You buy a crystal bardsword.\n");
   value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardsword.c"),this_player());
}
else if (str == "7")  {
  write("You buy a bardic pouch.\n");
  value = 300;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
ob = clone_object("/players/saber/closed/bards/pouch.c");
ob2 = clone_object("/players/saber/stuff/rose2.c");
ob3 = clone_object("/players/saber/closed/bards/ring.c");
ob4 = clone_object("/players/saber/closed/bards/cloak.c");
ob5 = clone_object("/players/saber/closed/bards/dagger.c");
move_object(ob2,ob);
move_object(ob3,ob);
move_object(ob4,ob);
move_object(ob5,ob);
move_object(ob,this_player());
}
else if (str == "8")  {
  write("You buy a potion of atonement.\n");
  value = 300;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/food/atone.c"),this_player());
}
else if (str == "9")  {
  write("You buy a crystal bardsword <opera>\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardsword2.c"),this_player());
}
else if(str == "10")  {
  write("You buy a crystal bardsword <rock>\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardsword3.c"),this_player());
}
else if(str == "11")  {
  write("You buy a blessed axe\n");
  value = 1250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/axe.c"),this_player());
}
else if (str == "12")  {
  write("Please buy a Speedster. 1s of Church, look at machine- The Management\n");
/*
  write("You buy Boots of Sprinting.\n");
  value = 1000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/sandman/paladin/obj/boots.c"),this_player()); 
*/
}
else if (str == "13")  {
  write("You buy a bardsword <r&b>.\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardsword4.c"),this_player());
}
else if (str == "14")  {
  write("You buy a bardsword <DarkFire>.\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardswordb.c"),this_player());
}
else if (str == "15")  {
  write("You buy a bardsword <Xmas>.\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardswordxs.c"),this_player());
}
else if (str == "16")  {
  write("You buy an Xmas scroll.\n");
  value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/stocking.c"),this_player());
}
else {
write("Laura says 'What do you want to buy?'\n");
 return 1;
}

if (call_other(this_player(), "query_money", 0) < value) {
  write("That costs "+value+" gold coins, which you don't have.\n");
  return 1;
}

cost = value;
 write("You play "+cost+" coins for a number "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
  call_other(this_player(), "add_money", - cost);
 return 1;
}
