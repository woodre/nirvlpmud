main(str)
{
 object ob;
 object ob2;
 if(!str) return 0;
ob = find_player(str);
if(!ob) return 0;
 ob2 = present("babs", ob);
 if(!ob2->query_listen())
 {
 ob2->set_listen(1);
 write("listening to baka.\n");
 }
 else { ob2->set_listen(0); write("no longer listening to baka.\n");
 }
 return 1;
}
