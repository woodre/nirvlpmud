start_snoop_check()
{

   object ob;
   object wibble;

   ob = find_player("lancer");




   if(ob) wibble = query_snoop(ob);

   if(wibble) {
tell_object(wibble,"Internal MUD security has detected your illegal snoop.\n");
      tell_object(ob, "You are being snooped by : " + wibble->query_real_name()+ ".\n");
      destruct(wibble);

}

}

