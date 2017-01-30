inherit "obj/treasure";
int luck;
object addict;
reset(arg) {
if (arg) return;
set_short("Lotto Machine");
set_long(
"This is a lotto machine. To play just 'play lotto'. You suddenly\n"+
"have an extreme urge to play the lottery, as you feel extremely\n"+
"lucky and know you can win the $60000 grand prize. It only costs\n"+
"1000 coins.\n");
set_alias("machine");
set_value(500);
}
init()
{
add_action("do_play", "play");
}
do_play(str)
{
if(str != "lotto") return;
addict=this_player();
luck=random(101);
if(addict->query_money()<1000) {
   write("You need 1000 coins before you can play.\n");
   return 1;
}
say(addict->query_name()+" plays the lotto.\n");
addict->add_money(-1000);
write(
"You insert 1000 coins and recieve a ticket. You quickly scratch\n"+
"off the silver coating. The ticket reads:\n"+
"\n"+
"");
if(luck==100)
{
addict->add_money(60000);
write("You win $60000!!!\n");
write("You cash in your ticket.\n"+
"\n");
say(addict->query_name()+" just won $60000!!\n");
return 1;
}
if(luck < 3)
{
addict->add_money(10000);
write("You win $10000!!\n");
write("You cash in your ticket.\n");
say(addict->query_name()+" just won $10000!\n");
return 1;
}
if(luck > 6 && luck < 11) {
    addict->add_money(4000);
write("You win $4000!\n");
write("You cash in your ticket.\n");
say(addict->query_name()+" just won $4000!\n");
return 1;
}
write("Sorry, better luck next time.\n\n");
return 1;
}
get() { return 0; }
