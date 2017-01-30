inherit "obj/treasure.c";
#include "/players/jaraxle/closed/kdefine.h"
int price, tox, no, x;
reset(arg) {
tox = "UnSet";
no=0;
price = 0;
if(arg) return; }
id(str) { return str == "pack" || str == "pack of heals" || str == "heals" || str == "heal pack";  }
short() { return ""+YEL+"-Pack of Heals-"+NORM+""; }
long() { price();
write("This is a small little computer box.  It has several differen't\n"+
      "buttons and options.  The viewscreen in the middle displays:\n"+
      ""+no+" heals with these attributes:\n"+
      "[ "+tox+" ] Tox Rate.\n"+
      "[ "+no+" ] Number of heals.\n"+
      "[ "+price+" ] Price to expand.\n"+
      ""+HIR+"Type 'customize' to begin!"+NORM+"\n");
}
void init(){ 
::init(); 
add_action("makeheals","customize"); 
add_action("tox","tox"); 
add_action("healno","healnumber"); 
add_action("expand","expand"); 
}
makeheals(arg) {
write("You may set the following attributes:\n"+
      "1. Tox <Low, Medium, High>\n"+
      "2. Healnumber <Up to 15>\n"+
      "3. Expand Heals\n"+
      "Type 'tox', 'healnumber' or 'expand' for more info on each.\n");
return 1; }

tox(arg) {
if(!arg) {
write("You may choose for your heals to be low, medium, or high\n"+
      "toxing.  This will affect the price of your heals.\n"+
      "Simply type tox <low/medium/high>.  You may set it at any time\n"+
      "until you expand the healing pack.  Current [ "+tox+" ]\n"); return 1; }
if(arg != "low" && arg != "medium" && arg != "high") { write("That is not a valid choice.\n"); return 1; }
if(arg == "low") { tox="Low"; }
if(arg == "medium") { tox="Medium"; }
if(arg == "high") { tox="High"; }
write("Your heals will now expand to be "+tox+" toxing.\n"); 
return 1; }

healno(arg) {
if(!arg) { write("The pack may be expanded into a maximum of 15 heals.\n"+
                 "Choose how many heals you would like using this\n"+
                 "command:\n"+
                 "Healnumber <Up to 15>\n");
return 1; 
}
if(arg != "1" && arg != "2" && arg != "3" && arg != "4" && arg != "5" && arg != "6"
              && arg != "7" && arg != "8" && arg != "9" && arg != "10" && arg != "11"
              && arg != "11" && arg != "13" && arg != "14" && arg != "15") {
write("That is not a valid choice.\n"); return 1; }
if(arg == "1") { no=1; }
if(arg == "2") { no=2; }
if(arg == "3") { no=3; }
if(arg == "4") { no=4; }
if(arg == "5") { no=5; }
if(arg == "6") { no=6; }
if(arg == "7") { no=7; }
if(arg == "8") { no=8; }
if(arg == "9") { no=9; }
if(arg == "10") { no=10; }
if(arg == "11") { no=11; }
if(arg == "12") { no=12; }
if(arg == "13") { no=13; }
if(arg == "14") { no=14; }
if(arg == "15") { no=15; }

write("The pack will now expand into "+no+" heal(s).\n"); 
return 1; }

price() { 
if(tox == "Low") { price=2400*no; }
if(tox == "Medium") { price=1800*no; }
if(tox == "High") { price=1200*no; }
}

expand(arg) { price();
if(!arg) {
write("It will cost you "+price+" coins to expand this pack currently.\nIf you are ready you may 'expand heals'.\n");
return 1; }
if(arg != "heals") { write("Expand what?\n"); return 1; }
if(TP->query_money() < price) { write("You can't afford to expand the pack!\n"); return 1; }
if(!call_other(TP,"add_weight",no)) { write("You can't carry the expanded heals!\nExpansion terminated.\n"); return 1; }
if(no == 0 || tox == "UnSet" || price == 0) { write("The pack is not ready to expand yet.\n"); return 1; }
write("You press the expand button on the pack and it vaporizes into "+no+" heals!\n");
TP->add_money(-price);
ex();
return 1;
}

ex() { object heal;
x=x+1;
if(no + 1 == x) { destruct(TO); return 1; }
write(""+no+" heals pop into your inventory.\n");
MOCO("/players/jaraxle/closed/heal.c"),TP);
heal = present("customheal",TP);
if(tox == "Low") { heal->set_no(5); }
if(tox == "Medium") { heal->set_no(7); }
if(tox == "High") { heal->set_no(10); }
ex();
return 1;
}


/*

Low Tox Version:
30 / 150 = .20
CostPerPoint = 16
Final Cost= 2400

Medium Tox Version
42 / 150 = .28
CostPerPoint = 12
Final Cost= 1800

High Tox Version
60 / 150 = .40
CostPerPoint = 8
Final Cost= 1200

*/

query_save_flag() { return 1; }
query_value(){ return 0; }
get() { return 1; }
query_weight() { if(no > 0) return no * 1; else return 1; }

