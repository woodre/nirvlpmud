status main(string str, object PO, object User)
{
	save_object("players/shinshi/weapon/save/"+User->query_real_name());
    return 1;
}