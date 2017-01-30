/* exp tracking object for the Bone Marketeers. 
Thanks to verte for the help with this  */

id(str) {return str == "kill_check_object"; }
kill_check(ob) {
   object mar_ob;
   int this_kill;
   mar_ob = present("market_ob", environment(this_object()));
   
/* AHAHAHA VERTE IS GOD *?
 */
   this_kill = (int)ob->calculate_evaluated_worth(environment());
    tell_object(environment(), "THIS_KILL: " + this_kill + "\n");
      if(this_kill > (mar_ob->query_bigkill())) {
      mar_ob->set_bigkill(this_kill);
      mar_ob->market_save();
   }
}

