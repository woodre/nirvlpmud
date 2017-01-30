short() { return "The Spanky Club"; }
reset(arg) { if(arg) return; set_light(1); }
init() { add_action("fuck_em"); add_xverb(""); }
fuck_em()
{
   if(this_player()->query_real_name() == "sado") return 0;
   write("Sado spanks you for even trying that!");
   init();
   return 1;
}
exit()
{
   if(find_player("sado"))
   tell_object(find_player("sado"), this_player()->query_name()+" has got out of jail!\n");
}
