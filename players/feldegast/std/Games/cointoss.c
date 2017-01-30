/*********************************************************
A generic coin toss game
Path: /players/feldegast/std/Games/
File: cointoss.c
Author: Feldegast/Chris
*********************************************************/
inherit "/obj/treasure";

object bank;

void coin_game(string arg);
void coin_toss(string arg);
void coin_call(string arg);

void reset(int arg)
{
  if(arg) return;
  set_id("coin");
  set_short("A copper coin");
  set_long(0);
  set_weight(0);
  set_value(0);
}

void init()
{
  coin_game("");
}

void coin_game(string arg)
{
  if(!bank)
  {
    write("Error: No bank!\n");
    destruct(this_object());
    return;
  }
  write("Coins: "+(int)this_player()->query_money()+
        " Bank: "+(int)bank->query_money()+"\n");
  if((int)this_player()->query_money() < 5)
  {
    write("You do not have enough money to play this game.\n");
    return;
  }
  if((int)bank->query_money() < 5)
  {
    write("There's no money left in the bank!\n");
    return;
  }
  write("Would you like to toss a coin again? (y/n)");
  input_to("coin_toss");
}

void coin_toss(string arg)
{
  if(arg=="y" || arg=="Y" || arg=="yes" || arg=="Yes" || arg=="sure" || arg=="okay")
  {
    write("The coin twirls in the air...Which side do you call? (heads/tails)");
    input_to("coin_call");
  }
  else
    destruct(this_object());
}

void coin_call(string arg)
{
  int call;
  int toss;
  if(arg=="h" || arg=="H" || arg=="heads" || arg=="head")
    call=1;
  else
    if(arg=="t" || arg=="T" || arg=="tails" || arg=="tail")
      call=0;
  else
  {
    write("The coin falls on the floor with a clatter.  You failed to call it.\n");
    this_player()->add_money(-5);
    bank->add_money(5);
  }
    toss=random(2);
  write("The coin comes up "+(toss?"heads":"tails"));
  if(toss==call)
  {
    write("!  You win!!!\n");
    this_player()->add_money(5);
    bank->add_money(-5);
  }
  else
  {
    write(".  You lose.\n");
    this_player()->add_money(-5);
    bank->add_money(5);
  }
  coin_game("");
}  

void set_bank(object ob)
{
  bank=ob;
}
