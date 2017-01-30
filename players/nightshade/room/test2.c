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
"      1  Leather backpack      :   200 coins                         \n"+
"      2  Forever lantern       :   200 coins                         \n"+
"      3  Teleporting Bag       :   500 coins  \n"+
"      4  Talisman of Health    :   1000 coins       \n"+
"								\n";
      dest_dir = 
({
      "players/nightshade/room/vroad4", "east",
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
if(str == "bag" || str == "3")
{
i="players/nightshade/misc/bag";
cost = 500; }
if(str == "pack" || str == "1" || str == "backpack")
{
i="players/nightshade/misc/pack";
cost=200;
}
if(str == "lantern" || str == "2")
{
i="players/nightshade/misc/lantern";
cost=200;
}
if(str == "talisman" || str == "4")
{
i="players/nightshade/misc/talisman";
cost=1000;
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
