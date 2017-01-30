/*  FLOWER_GIRL.C - Loads into DMAIN.C  Sells flowers, RROSE.C AND YROSE.C
    Changes as of 5-30-96:
    Paths changed to fit new directory structure.
*/
#include "/players/traff/closed/ansi.h"
#define tp this_player()->query_name()
inherit "obj/monster";
int cost;

reset(arg){
  object coins;
  ::reset(arg);
  if(arg) return;
  set_name("rose");
  set_race("human");
  set_short(HIR+"Rose"+GRN+", the flower girl"+NORM);
  set_long(
"Rose comes here every day to sell her flowers.  She has "+HIR+"RED"+NORM+"and\n"+
HIY+"YELLOW"+NORM+" roses for sale.  They cost a mere 100 coins.  If you\n"+
"would like to buy a rose just enter: 'buy red' or 'buy yellow'.\n");
  set_level(7);
  set_hp(105);
  set_al(940);
  set_wc(12);
  set_ac(14);
  set_chance(30);
  set_spell_dam(13);
  set_spell_mess1("Rose lashes you with a long thorny switch.\nOUCH!\n");
  set_spell_mess2("Rose chants a Gypsy curse at you!\n");
  set_chat_chance(5);
  load_chat("Rose sings: Flowers. Who will buy my flowers today?\n");
  load_chat("Rose looks at you and smiles.\n");
  coins=clone_object("obj/money");
  coins->set_money(random(50)+260);
  move_object(coins,this_object());
}

init() {
  add_action("buy_item","buy");
  ::init();
}


  buy_item(str) {
  object flower;
  if(!str) { return 0; }
  if(str != "red" && str != "yellow" ) {
  write("Rose tells you:  I only have red or yellow roses.\n");
  return 1;
  }
  cost=100;
  if((this_player()->query_money()) < cost )  {
  write("Flower girl says:  You don't have enough coins.\n");
  return 1;
    }
  this_player()->add_money(-cost);
  flower=clone_object("/players/traff/delnoch/obj/"+str+"rose.c");
  if(!this_player()->add_weight(flower->query_weight())) {
    write("Flower girl says: You can't carry any more.  Oh dear!\n");
    move_object(flower, environment(this_object()));
    return 1;
    }
    else move_object(flower, this_player());
    write("You give your coins to the girl and she hands you a beautiful rose.\n");
    say((this_player()->query_name())+" buys a rose from the flower girl.\n");
    return 1;
  }

