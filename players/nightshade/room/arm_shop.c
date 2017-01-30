inherit "players/nightshade/new_room";
object duh, fart, blah;
int x;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Magical Armor Shop";
     long_desc =
"This is a magical armor shop. There is only one type you can buy\n"+
"because it can be turned into almost any type of armor that you \n"+
"need. Buy some and try it out!\n"+
"\n"+
"      Typeless armor   :   500 coins\n"+
"\n"+
"Thanks and explore the hidden depths of my area!\n";
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
if(str == "typeless")
{
i="players/nightshade/armor/typeless";
cost=500;
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
