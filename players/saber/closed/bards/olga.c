/* creted olga to bring back bardswords and such - mythos <8-10-1998> */
#define TPM this_player()->query_money()
#define tp this_player()->query_name()

object ob,ob2,ob3,ob4,ob5;


id(str) {return str == "olga";}
query_weight() {return 1000000;}
query_value() {return 0;}

  short() { return "  * Olga the Plow-woman"; }
long(){
  write("Olga the Plow-woman\nShe has been put here on this world to pull the plows and shovel the dirt.\n"+
     "One of the ugliest women you have ever seen, she however\n"+
     "does look like the buffest woman as well.\n"+
    "Dont mess with her!!!\n"+
   "She also will allow you to <buy> things from a <list> she has\n");
    write("Olga is carring:\n\tA list\n\tA plow\n\t10000 coins\n\n");
        }

list()  {
write("Olga will let you <buy> the following:\n"+
 pad("",10)+" "+pad("1) A leather jacket",25)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("2) Studded leather armor",25)+" : 300 golden coins\n"+
 pad("",10)+" "+pad("3) Elven chainmail",25)+" :1000 golden coins\n"+
 pad("",10)+" "+pad("4) Black leather boots",25)+" : 100 golden coins\n"+
 pad("",10)+" "+pad("5) A crystal dagger",25)+" : 100 golden coins\n"+
 pad("",10)+" "+pad("6) A bardsword <fire>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("7) A bardsword <opera>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("8) A bardsword <rock>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("9) A bardsword <R&B>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("10) A bardsword <DarkFire>",25)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("11) A bardsword <Xmas>",25)+" :10000 golden coins\n"+
 "\n");
     return 1;
}

init() {
  add_action("buy","buy");
  add_action("list","list");
  add_action("kill","kill");
  add_action("kill","fireball",2);
  add_action("kill","shock",2);
   add_action("kill","sonic",2);
   add_action("kill","missle",2);
}

kill(str)  {
if(str == "olga")  {
write("Olga catches your weapon and slaps you across the face!\n"+
   "OUCH!\n");
say(tp+" attacks Olga.\n"+
  "Olga catches "+tp+"'s weapon and takes slaps "+tp+" across the face.\n");
   this_player()->hit_player(100);
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
  write("You buy a crystal bardsword <opera>\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardsword2.c"),this_player());
}
else if(str == "8")  {
  write("You buy a crystal bardsword <rock>\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardsword3.c"),this_player());
}
else if (str == "9")  {
  write("You buy a bardsword <r&b>.\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardsword4.c"),this_player());
}
else if (str == "10")  {
  write("You buy a bardsword <DarkFire>.\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardswordb.c"),this_player());
}
else if (str == "11")  {
  write("You buy a bardsword <Xmas>.\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/saber/closed/bards/bardswordxs.c"),this_player());
}
else {
write("Olga says 'What do you want to buy?'\n");
 return 1;
}

if (call_other(this_player(), "query_money", 0) < value) {
  write("That costs "+value+" gold coins, which you don't have.\n");
  return 1;
}

cost = value;
 write("You pay "+cost+" coins for a number "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
  call_other(this_player(), "add_money", - cost);
 return 1;
}
