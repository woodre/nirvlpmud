inherit "players/nightshade/new_room";
object duh, fart, blah;
int x;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Magic Shop";
     long_desc =
"This is a survival shop. Right now the only items available are:   \n"+
"                                                                   \n"+
"      Leather backpack      :   200 coins                         \n"+
"      Forever lantern       :   200 coins                         \n"+
"      Monster stater        :   300 coins  \n"+
"      Talisman of Health    :   1000 coins       \n"+
"      Nifty magical purse   :   2000 coins  \n"+
"								\n";
      dest_dir = 
({
      "players/nightshade/room/vroad4", "west",
      });
}
init()
{
::init();
add_action("do_buy", "buy");
}
do_buy(str)
{
string i;
int cost;
object ob;
if(str == "stater")
{
i="players/nightshade/misc/stater";
cost=300;
}
if(str == "pack" || str == "backpack")
{
i="players/nightshade/misc/pack";
cost=200;
}
if(str == "lantern")
{
i="players/nightshade/misc/lantern";
cost=200;
}
if(str == "talisman")
{
i="players/nightshade/misc/talisman";
cost=1000;
}
if(str == "purse")
{
i="players/nightshade/misc/purse";
cost=2000;
}
if(!cost && !i)
{
write("We dont sell that here.\n");
return 1;
}
if(this_player()->query_money() < cost)
{
write("Get out of here moocher!\n");
return 1;
}
ob=clone_object(i);
if(transfer(ob, this_player()))
{
write("You cant carry it!\n");
destruct(ob);
return 1;
}
this_player()->add_money(-cost);
write("You bought "+ob->short()+" for "+cost+" coins.\n");
return 1;
}
