inherit "players/nightshade/new_room";
object duh, fart, blah;
int x;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Blood Bank";
     long_desc =
"This is the local blood bank. They sell bags of blood as healing\n"+
"elements. To buy something type buy <number>. The types of blood\n"+
"available are:\n"+
"                                                                   \n"+
"      1  Tissue sample              :   300 coins\n"+
"      2  Bag of tissue samples      :   3000 coins\n"+
"      3  Bag of human blood         :   2000 coins                         \n"+
"      4  Bag of god's blood         :   10000 coins                         \n"+
"      5  Wyvern's poison(sobering)  :   300 coins\n"+
"								\n";
      dest_dir = 
({
      "players/nightshade/room/vroad2", "west",
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
write("Sorry we no longer have that in stock.\n");
return 1;
if(str=="2")
{
i="players/nightshade/misc/bag_tissue";
cost=3000;
}
if(str=="1")
{
i="players/nightshade/misc/tissue";
cost=300;
}
if(str=="5")
{
i="players/nightshade/misc/wyv_poison";
cost=300;
}
if(str=="3")
{
i="players/nightshade/misc/human_blood";
cost=2000;
}
if(str=="4")
{
i="players/nightshade/misc/gods_blood";
cost=10000;
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
