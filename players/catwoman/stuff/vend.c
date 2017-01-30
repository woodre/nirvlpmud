
inherit "obj/treasure";

id(str) { return str == "shop"; }
/*query_auto_load(){
return("players/catwoman/stuff/vend:");
}*/
reset(arg)
{
  name = "vendomatic";
}

short() { return "A portable gift SHOP(w/ menu)"; }

long()
{

  write("This is a gift shop menu \n"+
        " <read shop> and <order!> are the commands.\n");
}

init()
{
/*
        if(!present("thief guild",environment(this_object()))) {
        write("you are not a thief!!\n");
        destruct(this_object());
        return 1;
        }

  add_action("list1", "listshop");
  add_action("buy1", "buyshop");
  add_action("sell1", "sellshop");*/
  add_action("read1", "read");
add_action("order", "order!");
}

read1(str)
{
if (id(str)) {
        call_other("/players/catwoman/gift.c", "list", 0);
        return(1);
        }
}
order(str)
{
        call_other("/players/catwoman/gift.c", "buy", str);
        return(1);
}
/*
list1(str)
{

    call_other("/players/catwoman/tshop.c", "list", 0);
    return(1);

}
buy1(str)
{
  call_other("/players/catwoman/tshop.c", "buy", str);
  return(1);
}
sell1(str)
{
call_other("/players/catwoman/tshop.c", "sell", str);
return(1);
}
drop() {
return 1;
}
*/
query_weight() { return 3000; }

