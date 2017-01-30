#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "man";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "An old man";  }
long(){
write("An old man who might sell you a starglow.\n"+
  "If you are going in, you want one.  Really.  Honest.\n"+
  "In fact, the old man tells you that you don't want\n"+
  "to go in there.  You really don't.  It just not\n"+
  "worth it.  Really.  Would I lie?\n"+
  "You may <buy> a <starglow>.\n");
        }

init() {
#ifndef __LDMUD__ /* Rumplemintz */
 add_action("buy");
   add_verb("buy");
   add_action("kill");
   add_verb("kill");
#else
  add_action("buy", "buy");
  add_action("kill", "kill");
#endif
}

kill(str)  {
if(str == "man")  {
write("The man ducks.\n");
say(tp+" swings at the old man, who ducks the blow.\n");
  return 1;
        }
        }

buy(str) {
int cost, value;

if (!str){
 write("Buy what?\n");
 return 1;
}
 if (str == "starglow")  {
  write("You buy a starglow.\n");
   value = 500;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
move_object(clone_object("/players/saber/closed/quest/items/starglow.c"),this_player());
}
else {
write("The old man says: I don't sell those.\n");
 return 1;
}

if (call_other(this_player(), "query_money", 0) < value) {
  write("That costs "+value+" gold coins, which you don't have.\n");
  return 1;
}

cost = value;
 write("You play "+cost+" coins for a "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
  call_other(this_player(), "add_money", - cost);
 return 1;
}
