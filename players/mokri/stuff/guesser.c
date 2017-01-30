inherit "/obj/treasure.c";
int last_time;

reset(int arg) {
   if(arg) return;
   set_id("machine");
   set_alias("guessing machine");
   set_short("Number Guessing Machine");
   set_long("A huge machine with a slot for some coins.\n"+
      "To play, type 'pick x', where 'x' is a number between 1 and 10.\n"+
      "If you guess correctly, win money!\n"+
      "Cost is 100 coins.\n");
   set_weight(100);
}

get() { return 0; }

init()
{
   ::init();
   add_action("pick","pick");
}

int pick(string arg)
{
   int guess, this_num;
   
   if(this_player()->query_money() < 100)
      {
      write("You are too poor to play (and thats REALLY poor).\n");
      return 1;
   }
   
   if(last_time+3 > time())
      {
      write("The machine is resetting.\nPlease wait.\n");
      return 1;
   }
   
   if(!arg || sscanf(arg,"%d",guess) != 1)
      {
      write("Please type 'pick x', where 'x' is a number between 1 and 10.\n");
      return 1;
   }
   
   if(guess < 1 || guess > 10)
      {
      write("Your guess must be between 1 and 10.\n");
      return 1;
   }
   
   this_player()->add_money(-100);
   last_time = time();
   this_num = random(10) + 1;
   write("The number is " + this_num +"\n");
   if(this_num != guess) write("You lose!\n");
   
   if(this_num == guess)
      {
      write("We have a winner!\nYou win 900 coins.\n");
      this_player()->add_money(900);
   }
   
   return 1;
}
