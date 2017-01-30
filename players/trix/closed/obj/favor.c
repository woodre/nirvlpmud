inherit"obj/treasure";
reset(arg) {
if(arg) return;
set_id("favor");
set_alias("party favor");
set_short("A party favor");
set_long(
"This is a party favor. Type 'blow favor' to play it.\n");
set_value(0);
set_weight(0);
}
init()
{ 
  add_action("blow","blow");
}
blow(arg)
{ if(arg!="favor") return;
  say(this_player()->query_name()+" blows in a party favor... BAAAAAAAAAAAAAAAAHH\n");
  write("You blow in your party favor...\nBAAAAAAAAAAAAAAAAHH\n");
  return 1;
}
