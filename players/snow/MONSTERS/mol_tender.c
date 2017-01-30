#define TP this_player()
#define TPM TP->query_money()
#define TPN TP->query_name()
#define TPL TP->query_level()
#define STUFF TP->query_stuffed()
#define SOAK TP->query_soaked()
#define INTOX TP->query_intoxination()
#define MAX TPL*8
#define MAXI TPL+3
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(2000) + 1000);
  move_object(gold,this_object());
 
     set_name("bartender");
     set_short("Bartender");
     set_race("man");
     set_alias("grok");
     set_long(
"This is Grok, the bartender for the Molehill Bar & \n"+
"Grill. He stands behind the bar scrubbing the interior\n"+
"of a mug with a filthy-looking cloth. If he is happy,\n"+
"he will get you whatever you order.\n");
     set_level(15);
     set_ac(10);
     set_wc(18);
     set_hp(400);
     set_heal(3,2);
     set_al(0);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat(
"Grok grumbles: Can I getcha anythin mate?\n");
     load_chat(
"Grok spits into a mug and scrubs it out.\n");
     load_a_chat(
"Grok yells: Now who's gonna serve my customers?\n");
   }
}
 
init() {
  add_action("get_food","order");
 }
 
get_food(str) {
    string nomoney,nodrink,nofood,noalco;
 
nomoney = "Grok growls: You don't have enough money, bub.\n";
nodrink = "Grok growls: You're too full to drink any more.\n";
nofood = "Grok growls: You're too full to eat any more.\n";
noalco = "Grok growls: You're too drunk to drink any more.\n";
 
  if(!str) {write("Grok growls: Order what?\n"); return 1;}
  if(str == "BrownWater" || str == "brownwater") {
    if(TPM < 5) {write(nomoney); return 1;}
write("Grok hands you a glass of dirty brown water.\n");
write("You grimace as you chug it down.\n");
say(TPN+" orders a brownwater.\n");
call_other(TP,"drink_alcohol",-1);
call_other(TP,"add_money",-5);
return 1;
    }
  if(str == "OJ" || str == "oj") {
    if(TPM < 35) {write(nomoney); return 1;}
      if(SOAK +4 > MAX) {write(nodrink); return 1;}
write("Grok hands you a glass of OJ from under the counter.\n");
write("It tastes a little sour...\n");
say(TPN+" orders an OJ.\n");
call_other(TP,"drink_soft",4);
call_other(TP,"heal_self",6);
call_other(TP,"add_money",-35);
return 1;
    }
  if(str == "Milk" || str == "milk") {
    if(TPM < 50) {write(nomoney); return 1;}
      if(SOAK +6 > MAX) {write(nodrink); return 1;}
write("Grok hands you a glass of milk from under the counter.\n");
write("The curds tickle your throat...\n");
say(TPN+" orders a milk.\n");
call_other(TP,"drink_soft",6);
call_other(TP,"heal_self",10);
call_other(TP,"add_money",-50);
return 1;
    }
  if(str == "EggNog" || str == "eggnog") {
    if(TPM < 60) {write(nomoney); return 1;}
      if(INTOX +2 > MAXI) {write(noalco); return 1;}
write("Grok hands you a glass of eggnog from under the counter.\n");
write("It's not too great...\n");
say(TPN+" orders an eggnog.\n");
call_other(TP,"drink_alcohol",2);
call_other(TP,"heal_self",10);
call_other(TP,"add_money",-60);
return 1;
    }
  if(str == "Screwdriver" || str == "screwdriver") {
    if(TPM < 80) {write(nomoney); return 1;}
      if(INTOX +4 > MAXI) {write(noalco); return 1;}
write("Grok mixes you a screwdriver.\n");
write("You feel a small rush as you chug it down.\n");
say(TPN+" orders a screwdriver.\n");
call_other(TP,"drink_alcohol",4);
call_other(TP,"heal_self",15);
call_other(TP,"add_money",-80);
return 1;
    }
  if(str == "SparkleWater" || str == "sparklewater") {
    if(TPM < 500) {write(nomoney); return 1;}
      if(SOAK +8 > MAX) {write(nodrink); return 1;}
write("Grok hands you a bottle of sparkling water.\n");
write("You chug it down and feel refreshed.\n");
say(TPN+" orders a sparklewater.\n");
call_other(TP,"drink_soft",8);
call_other(TP,"heal_self",20);
call_other(TP,"add_money",-500);
return 1;
    }
  if(str == "Pretzels" || str == "pretzels") {
    if(TPM < 5) {write(nomoney); return 1;}
write("Grok gives you a bowl of pretzels.\n");
write("The pretzels make you more thirsty.\n");
say(TPN+" orders some pretzels.\n");
call_other(TP,"drink_soft",-1);
call_other(TP,"heal_self",1);
call_other(TP,"add_money",-5);
return 1;
    }
  if(str == "Fries" || str == "fries") {
    if(TPM < 100) {write(nomoney); return 1;}
      if(STUFF +5 > MAX) {write(nofood); return 1;}
write("Grok hands you a plate of cold fries.\n");
write("The fries taste pretty bad...\n");
say(TPN+" orders some fries.\n");
call_other(TP,"eat_food",5);
call_other(TP,"heal_self",10);
call_other(TP,"add_money",-100);
return 1;
    }
  if(str == "Burger" || str == "burger") {
    if(TPM < 250) {write(nomoney); return 1;}
      if(STUFF +10 > MAX) {write(nofood); return 1;}
write("Grok hands you a warm burger from the grill.\n");
write("The burger tastes pretty good!\n");
say(TPN+" orders a burger.\n");
call_other(TP,"eat_food",10);
call_other(TP,"heal_self",25);
call_other(TP,"add_money",-250);
return 1;
    }
  if(str == "Chicken" || str == "chicken") {
    if(TPM < 500) {write(nomoney); return 1;}
      if(STUFF +30 > MAX) {write(nofood); return 1;}
write("Grok hands you a roast chicken from the oven.\n");
write("You hungrily devour the chicken\n");
say(TPN+" orders a milk.\n");
call_other(TP,"eat_food",30);
call_other(TP,"heal_self",50);
call_other(TP,"add_money",-400);
return 1;
    }
  if(str == "Ribs" || str == "ribs") {
    if(TPM < 1000) {write(nomoney); return 1;}
      if(STUFF +50 > MAX) {write(nofood); return 1;}
write("Grok hands you a huge mound of ribs from the grill.\n");
write("You hungrily devour the ribs. They taste great!\n");
say(TPN+" orders the ribs.\n");
say(TPN+" looks very satisfied.\n");
call_other(TP,"eat_food",50);
call_other(TP,"heal_self",150);
call_other(TP,"add_money",-1000);
return 1;
    }
}
