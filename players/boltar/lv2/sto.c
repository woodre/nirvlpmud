store(item)
{
    object ob;
     string hold, pl_nam, hold2;
     pl_nam = call_other(this_player(), "query_name",0);
  hold = pl_nam+"holder";

     hold2 = present(hold);
     move_object(item, hold2);
	    return;
  }
