#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "guy" || str == "pilgrim";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A guy wearing a Pilgrim outfit"; }
long(){
write("A guy wearing a Pilgrim outfit.  He has several sacks \n"+
        "of leftover food slung over his shoulder.\n"+
        "\nPilgrim says: Pssst.  Want to <buy> some <leftovers>?\n\n");
        }

init() {
    add_action("buy","buy");
    add_action("kill","kill");
}

kill(str)  {
if(str == "pilgrim" || str == "guy")  {
  write("The city guard will not let you.\n");
say(tp+" tries to attack the Pilgrim, but is stopped by the city guard.\n");
  return 1;
        }
        }

buy(str) {
int cost, value;

  if (!str){
   write("The Pilgrim says \"\What would you like to buy?\n");
   return 1;
        }
        
 if (str == "leftovers" || str == "sack" || str == "leftover")  {
    write("You buy a sack of leftovers.\n");
    value = 1250;
    if(TPM < value) {
      write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
    move_object(clone_object("/players/saber/food/leftovers.c"),
      environment(this_player()));
        }

  else {
  write("The Pilgrim says: What do you want to buy?\n");
   return 1;
        }

  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs "+value+" gold coins, which you don't have.\n");
    return 1;
        }

  cost = value;
  write("You play "+cost+" coins for a "+str+".\n");
  say(call_other(this_player(), "query_name", 0) + " buys a sack of leftovers.\n");
  call_other(this_player(), "add_money", - cost);
  command("get leftovers", this_player());
  return 1;
        }
