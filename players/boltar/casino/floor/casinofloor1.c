#define CASINO "players/boltar/casino/"

string *gamblers;

reset(arg) 
{
  if( (sizeof(gamblers) > 0))
  {
    if(arg) return 0;
  }
  else
  {

    gamblers = ({ });

    if (arg) return;
    set_light(1);
  }
}

init() {
    add_action("east","east");
    add_action("west","west");
    add_action("buy","buy");
    add_action("cashout","cashout");
}

east() {
  call_other(this_player(),"move_player","east#"+CASINO+"hall1w1");
  return 1;
}
west() { 
  call_other(this_player(),"move_player","west#"+CASINO+"floor/casinofloor2");
  return 1;
}

short() {
    return "Casa de Nirvana, Cashier";
}

long(str) {
if(str=="sign")
   write("A sizeable brass sign, polished to a mirror sheen, hangs above the\n"+
        "doorway to the east.  It is engraved with the word 'L O B B Y'.\n");
if(str=="glass")
   write("The frosted glass of the east door blurs the view\n"+
        "of the room beyond.\n");
if(str=="doorway" || str=="door")
   write("The huge door to the east is inset with thick frosted glass that\n"+
        "blurs the view of the room beyond.  A large brass sign \n"+
        "over the doorway reads 'L O B B Y'.\n");
if(str=="machine" || str=="machines" || str =="line of machines")
   write("With these machines you may 'buy' chips by specifying the amount\n"+
         "you wish to purchase in coins. 'buy 100' will purchase 100 coins\n"+
         "worth of casino chips.\n");
if(str=="windows" || str=="cashier"|| str=="cashiers" || str=="bared windows")
   write("These well protected cashiers will exchange your casino chips for\n"+
         "for the coins of the realm. 'cashout chips' will cash out your chips\n"+
         "and return you their value in coins.\n");

if(str) return 0;
write("This open hall shapped room has a line of machines along the north\n"+
      "wall that appear to take coins and dispense chips. Along the south\n"+ 
      "wall there are cashiers behind bared windows who exchange chips for coins.\n"+
      "The cool marble of the floor dully reflects the light from\n"+
        "the elaborate chandelier that hangs overhead. The white panels\n"+
        "of the ceiling, each decorated by a raised plaster flower in \n"+
        "various pastel shades in its center and gilding along its edges, \n"+
        "provide a simple contrast to the complicated frescoes in the \n"+
        "adjoining lobby to the east. There is an oversized frosted\n"+
        "glass doorway to the west, above which hangs a large brass sign \n"+
        "engraved with the word 'L O B B Y'.\n");

}

id(str) {
return
str=="sign"|| str=="glass"|| str=="doorway" || str=="door" ||
str=="panel"|| str=="windows" || str=="cashier"|| str=="cashiers" || str=="bared windows" ||
str=="machine" || str=="machines" || str =="line of machines"; 
}

buy(arg) {
 int value;
 object chips;
 if(!arg || sscanf(arg,"%d",value)!=1) {
   write("Usage: buy <value in coins>\n");
   return 1;
 }
 if(member_array(this_player()->query_real_name(), gamblers) > -1)
 {
   write("You have already bought chips today.\n");
   return 1;
 }
 if(value > this_player()->query_money()) {
   write("You don't have that much money.!\n");
   return 1;
 }
 if(value < 1) {
   write("You must buy at least one chip!\n");
   return 1;
 }
 chips = present("casino chips",this_player());
 if(!chips) 
 chips = clone_object("/players/boltar/casino/floor/chips");
 chips->add_chip_value(value);
 this_player()->add_money(0-value);
 move_object(chips,this_player());
 gamblers += ({ this_player()->query_real_name() });
 write("The cashier hands you "+value+" in chips.\n");
 return 1;
}

cashout(str) {
 int value;
 object chips;
 if(str != "chips") return 0;
 chips = present("casino chips",this_player());
 if(!chips) {
   write("You have no chips to turn in.\n");
   return 1;
 }
 value = chips->query_chip_value();
 this_player()->add_money(value);
 destruct(chips);
 write("You turn in your chips and get "+value+" coins.\n");
 return 1;
}
