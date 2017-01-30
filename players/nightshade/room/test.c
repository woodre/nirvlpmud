inherit "players/nightshade/new_room";
object duh, fart, blah;
int x;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Survival Shop";
     long_desc =
"This is a survival shop. Right now the only items available are:   \n"+
"                                                                   \n"+
"      Leather backpack   :   200 coins                         \n"+
"      Forever lantern    :   200 coins                         \n"+
"      Monster Stater     :   300 coins  \n"+
"      Amulet of Health   :   2000 coins       \n"+
"      Nifty magical purse:   2000 coins  \n"+
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
int x;
object duh;
x = this_player()->query_money();
if(!str) return;
if(str != "pack" || str != "backpack" || str != "lantern" ||
  str != "amulet")
{
write("Buy what?\n");
return 1;
}
if(str == "pack" || str == "backpack" && x>=200)
{
if(!this_player()->add_weight(3))
{
write("Its to heavy.\n");
return 1;
}
write("You purchase a backpack.\n");
duh=clone_object("players/nightshade/misc/pack");
move_object(duh, this_player());
this_player()->add_money(-100);
return 1;
}
if(str == "lantern" && x>=200)
{
write("You just bout a forever lantern.\n");
fart=clone_object("players/nightshade/misc/lantern");
move_object(fart, this_player());
return 1;
}
if(str == "amulet" && x>=200)
{
write("You purchased an Amulet of Health.\n");
blah=clone_object("players/nightshade/misc/talisman");
move_object(blah, this_player());
return 1;
}
write("You dont have enough cash for that.\n");
return 1;
}
