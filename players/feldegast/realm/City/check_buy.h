check_buy(string filename, int weight, int value) {
  if(this_player()->query_money()<value) {
    write("You cannot afford that.\n");
    return 1;
  }
  if(this_player()->query_weight()<weight) {
    write("That is too heavy for you.\n");
    return 1;
  }
  {
    object ob;
    ob=clone_object(filename);
    write("You purchase a "+ob->query_name()+" for "+value+" coins.\n");
    this_player()->add_money(-value);
    move_object(ob,this_player());
    this_player()->recalc_weight();
    return 1;
  }
}
