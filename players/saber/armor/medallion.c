inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("drow medallion");
   set_short("An adamantite medallion");
   set_alias("medallion");
   set_long("A beautiful adamantite medallion.\n"+
            "It is covered with spidery runes.\n");
   set_type("necklace");
   set_ac(1);
   set_weight(1);
   set_value(500);
}

init()  {
  ::init();
  add_action("read_medallion","read");
         }

read_medallion(str)  {
  if(str == "drow medallion" || str == "medallion")  {
  say(this_player()->query_name()+" reads an adamantite medallion.\n");
  write(
  "\nUlu z'hin maglust dal Qu'ellar lueth Valsharess zhah ulu z'hin wund lil phalar.\n\n");
  return 1;
          }
          }
