inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("DragonLord");
     set_short("A DragonLord");
     set_race("dragonlord");
     set_alias("lord");
     set_long(
  "\n  1000 meters long from nose to tail, this incredibly huge dragon\n"+
  "is staring straight at you. It does not appear to be angry, however.\n"+
  "The millenia of wisdom it has accumulated is apparent in its swirling,\n"+
  "iridescent eyes. It seems to be waiting for you to do something.\n");
     set_level(100);
     set_ac(80);
     set_wc(150);
     set_hp(10000);
     set_heal(100,1);
     set_al(0);
     set_aggressive(0);
   }
}
 
catch_tell(string str) {
  string msg;
  object ws;
  if(sscanf(str,"%sdestroy",msg) || sscanf(str,"%sdestroy%s",msg) ||
     sscanf(str,"destroy%s",msg) ) {
      ws = present("wyrmslayer",environment(this_object()));
      if(ws && present(this_player(),environment(this_object()))) {
        tell_object(this_player(),
          "The DragonLord speaks in your mind:\n"+
          "  'As you wish. Thank you.'\n");
        tell_object(this_player(),
          "\nThe DragonLord opens its mouth...\n\n");
        tell_object(this_player(),
          "   A stream of --ENERGY-- blasts forth!\n");
        destruct(ws);
        tell_object(this_player(),
          "Wyrmslayer is disintegrated!\n");
        this_player()->set_quest("archwizard");
move_object(clone_object("/players/fakir/closed/scar.c"), this_player());

         write_file("/players/snow/closed/q/complete",ctime(time())+" "+
               this_player()->query_real_name()+
               " completed the Archwizard Quest\n");
        tell_object(this_player(),
          "The Dragonlord gestures slightly.\n"+
          "  All goes dark.\n\n");
        move_object(this_player(),"/players/snow/gate.c");
        tell_object(this_player(),
          "You open your eyes...\n");
        command("look",this_player());
        return 1;
      }
    }
  if(sscanf(str,"%swaiting",msg) || sscanf(str,"%swaiting%s",msg) ||
     sscanf(str,"waiting%s",msg) || sscanf(str,"%sblade",msg) ||
     sscanf(str,"%sblade%s",msg) || sscanf(str,"blade%s",msg) ||
     sscanf(str,"%swyrmslayer",msg) || sscanf(str,"wyrmslayer%s",msg) ||
     sscanf(str,"%swyrmslayer%s",msg) || sscanf(str,"%swant",msg) ||
     sscanf(str,"%swant%s",msg) || sscanf(str,"want%s",msg) ||
     sscanf(str,"desire%s",msg) || sscanf(str,"%sdesire%s",msg) ||
    sscanf(str,"%stask",msg)||sscanf(str,"%stask%s",msg)||sscanf(str,"task%s",msg) ||
     sscanf(str,"%sdesire",msg) ) {
      tell_object(this_player(),
        "The DragonLord speaks in your mind:\n"+
        "  'Return to the sky the ancient foe of Dragonkind.\n");
      tell_object(this_player(),
        "   Tell me when you wish for me to destroy it.'\n");
      return 1;
    }
}
