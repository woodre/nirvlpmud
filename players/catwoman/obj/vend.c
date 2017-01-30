
inherit "obj/treasure";

id(str) { return str == "machine"; }

query_save_flag() { return 1; }
reset(arg)
{
  name = "machine";
}

short() { return "A portable vending machine"; }

long()
{
  write("This is a portable vending machine.\n"+
        "listshop and buyshop are the commands you can do.\n");

}

init()
{
  add_action("list1", "listshop");
  add_action("buy1", "buyshop");
}

list1(str)
{

    call_other("/players/catwoman/gift.c", "list", 0);
    return(1);

}


buy1(str)
{
  call_other("/players/catwoman/gift.c", "buy", str);
  return(1);
}
query_value() {
	return 0;
}

