inherit "obj/treasure";
string latest;

reset(arg)
{
   if (arg) return;
   set_id("orb");
   set_weight(0);
}

init()
{
   object a;
   a = users();
   
   latest = a[0]->query_real_name();
   set_heart_beat(1);
}

heart_beat() {
   check_for_new();
}


check_for_new() {
   
   object plyr, church, a;
   
   church = find_object("room/church");
   a = users();
   if (latest == a[0]->query_real_name()) return 1;
   
   plyr = first_inventory(church);
   
   while(plyr) {
      if(plyr->query_real_name() == a[0]->query_real_name()) new_player(plyr);
      plyr = next_inventory(plyr);
   }
   
   return 1;
}

new_player(newpl) {
   string who;
   
   who = newpl->query_real_name();
   latest = who;
   
   tell_object(environment(this_object()),
      capitalize(who)+
      " enters the game.\n");
   
   return 1;
}
