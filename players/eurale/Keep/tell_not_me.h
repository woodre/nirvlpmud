tell_not_me(str) {
object ob;
  ob = first_inventory(this_object());
    while(ob) {
      if(ob->is_player() && ob != this_player())
        tell_object(ob,str);
    ob = next_inventory(ob); }
return 1; }
