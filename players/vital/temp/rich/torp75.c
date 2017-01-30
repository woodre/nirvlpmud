id(str)
{
   if ( str == "75" || str == "photon torpedo key" || str == "key" ) return 1;
   return 0;
}

short()
{
   return "A photon torpedo key";
}

long()
{
   write( "This is a photon torpedo key,it is a VERY powerful object.\n");
   write( "Aren't you lucky!\n" );
   write( "To use the torpedo key type `target player name'\n");
}

query_value() { return 5000; }


get() { return 1; }

query_weight() { return 3; }

init() {
   add_action("tar", "target");
}

target(str) {
   string me,target;
   int hp,dam,damage;
   object ob;
   
   /*
   sscanf( str, "%s %s", me,target );
   if ( !id( me ) ) return 0;
   */
   /*
   if ( onword != "on" )
      {
      write( "target torpedo on something.\n" );
      return 0;
   }
   */
   if ( str == 0 )
      {
      write ( "You must target SOMETHING.\n" );
      return 0;
   }
   ob = find_living( str );
   if (ob== 0){
      write("Nothing by that name is functioning at this time.\n");
      return 1;
   }
   /*
   write( call_other( ob, "query_name", 0 ) + "\n");
   write("Level:\t" + call_other( ob, "query_level", 0) + "\n");
   write("MAX HP:\t" + call_other( ob, "query_max_hp", 0) + "\n");
   write( "AC:\t" + call_other(  ob, "query_ac", 0  ) + "\n");
   write("WC:\t" + call_other(  ob, "query_wc", 0 ) + "\n");
   */
   if (ob->query_level() >= 21) {
      write("You cannot target wizards!\n");
      return 1;
   }
   if (present("ttoy",ob)) {
      write("That player has a torpedo shield and your torpedo bounced off.\n");
      tell_object(ob,"Your torpedo shield has protected you from being hit by ");
      tell_object(ob,this_player()->query_name());
      tell_object(ob,"\nHowever, your torpedo shield was destroyed in the process.\n");
      destruct(present("ttoy",ob));
      destruct(this_object());
      return 1;
   }
   if ((ob->query_pl_k())==1) {
      if(this_player()->query_pl_k() == 1){
         hp=call_other(ob,"query_hp",0);
         damage = dam/4;
         write("The torpedo locks on its target,your key glows brightly,\n");
         write("You hear the torpedo begin its launch sequence\n");
         tell_object(ob,"You get the feeling that something has locked onto you.\n");
         call_out("timeout",3);
         tell_object(ob,"You hear a boom from the direction of the Enterprise.\n");
         tell_object(ob,"You get a feeling of dread at this sound like if you`re fighting\n");
         tell_object(ob,"you had better get out of battle QUICK!!!!\n");
         call_out("timeout",7);
         tell_object(ob,"You see a torpedo fly ver your had.\n");
         tell_object(ob,"But you see the torpedo loop back and head in your direction.\n");
         call_out("timeout",7);
         tell_object(ob,"You see a cloud of debris fly into the air as the photon torpedo...\n");
         tell_object(ob,"EXPLODES on its target!!!!\n");
         tell_object(ob,"unfortunately that target was you,you might want to check your score.\n");
         call_other(ob,"add_hit_point",0-damage);
         destruct(this_object());
         
         return 1;
       }
   }
   if(this_player()->query_pl_k() == 0){
      write("You must set you player killing first.\n");
      return 1;
   }
   if ((ob->query_pl_k())==0) {
      write("That player cannot be killed by other players choose another target.\n");
      return 1;
   }
}

reset(arg) {}
