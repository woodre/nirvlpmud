
/* 
 *  Bastian's Wedding Ring 
 *  Originally written for Nirvana
 *  
 *  Last modifed 041095
 */

string my_name, spouse_name, spouse;
int loaded;
int married;

id ( string str ) { return str == "ring" || str == "wedding ring"; }

/* added by Mythos <8-12-97> to prevent more than one ring */
reset(arg) {
  if(arg) return;
  call_out("check",3);
}

check() {
  object ep;
  object epi;
  int h;
  ep = environment(this_object());
  if(ep) {
    epi = all_inventory(ep);
    for(h=0; h<sizeof(epi); h++)
      if(epi[h] != this_object() && epi[h]->id("wedding ring"))
        destruct(epi[h]);
  }
return 1; }

/* end of mythos add */

long() { 
  if(this_player()->query_gender() == "female" ) {
     write(format("You see a delicately wrought band of platinum set with" +
      " a large, blue-white diamond.\n\n"));
  }
  else {
    write(format("You see a wide band of pure platinum, simple and " +
     "elegant.\n\n"));
  }
  write("Type \"help ring.\"\n");
}

short () { 
object bbb;
bbb=environment(this_object());
if(bbb)
  return my_name + "'s wedding ring (" + spouse_name + ")";
}

extra_look () {
  return my_name + " is wearing a wedding band";
}

query_auto_load () {
  return "players/bastion/closed/ring:" + spouse_name;
}

init () {
  if(environment(this_object())) if(environment(this_object()) == this_player() && this_player()->query_real_name() == "guest") { destruct(this_object()); return; }
   add_action("help", "help");
   add_action("restore","restore");
   add_action("throw", "throw");
   add_action("ring_chat", "ring");
   add_action("bring", "bring");
   add_action("go", "go");
   add_action("quit", "quit");
   if (this_player()->query_real_name() == "bastion" )
      add_action("renew_all_rings", "renew");
   
   if ( !my_name ) {
      my_name = this_player()->query_real_name();
      my_name = capitalize(my_name);
   }
   if ( !spouse_name ) {
      spouse_name = "None";
      spouse = "none";
   }
 if(!loaded) {
   if ( spouse_name && find_player(spouse) ) {
      tell_object(find_player(spouse), "(ring) " + my_name + " joins you " +
        "in the game.\n");
      write("(ring) " + spouse_name + " IS logged in!\n");
   }
   else
      write("(ring) " + spouse_name + " is not logged in.\n");
  loaded = 1; }
}

init_arg ( string str ) { 
  spouse_name = str;
  spouse = lower_case(str);
}

help ( string str ) {
   if ( !str || str != "ring" )
      return 0;
   write(format("Now that you are married, you can:\n\n" +
    "ring <mess> \t\tTalk to your spouse\n" +
    "ring :<emote> \t\tEmote through the ring\n" +
    "ring @<echo> \t\tEcho through the ring\n" + 
    "bring <spouse> \t\tTransport your spouse (70 sp's)\n" +
    "go <spouse> \t\tGo to your spouse (70 sp's)\n" +
    "throw ring \t\tDestroy your ring\n" +
    "restore ring \t\tRestore your spouse's ring\n"+
    "help ring \t\tSee this message\n"));
   return 1;
}

ring_chat ( string str ) {
   string mess;
   object *rings;
   int i;
   if ( !str ) {
      notify_fail("ring <mess> or ring :<mess>.\n");
      return 0;
   }
   mess = str;
   if ( mess[0]==58 ) {
      mess = "(ring) " + my_name + " " + mess[1..strlen(mess)] + "\n";
   }
   else if ( mess[0] == '@' ) 
      mess = "(ring) " + mess[1..strlen(mess)] + "\n";
   else {
      mess = my_name + " (ring): " + mess + "\n";
   }
   write(format(mess));
   if( spouse && find_player(spouse) )
      tell_object(find_player(spouse), format(mess));
#ifndef __LDMUD__
   rings = filter_objects(all_inventory(this_player()), "filter_rings",
#else
   rings = filter(all_inventory(this_player()), "filter_rings",
#endif
            this_object());
   for( i = 0; i < sizeof(rings); i++ )
      rings[i]->aux_ring_chat(mess);
   return 1;
}

aux_ring_chat ( string str ) {
  if(spouse && find_player(spouse))
    tell_object(find_player(spouse), format(str));
}

filter_rings ( object ob ) {
  return ( ob->id("wedding ring") && ob != this_object() );
}

bring ( string str ) {
   string here, there;
   string wheree;
   if ( !str ) {
      notify_fail("Bring <spouse>.\n");
      return 0;
   }
   if( (str = lower_case(str)) != spouse ) {
      notify_fail("That person is not your spouse.\n");
      return 0;
   }
   if ( !find_player(spouse) ) {
      notify_fail(capitalize(str) + " is not logged in.\n");
      return 0;
   }
   if ( this_player()->query_sp() < 70 ) {
      notify_fail("You need at least 70 spell points.\n");
      return 0;
   }
   here = environment(this_player())->realm();
   there = environment(find_player(str))->realm();
   if( here == "NT" || there == "NT" ) {
      notify_fail("A warping of space prevents you.\n");
      return 0;
   }
   this_player()->add_spell_point(-70);
   if(wheree = call_other("obj/base_tele","teleport")) {
      find_player(str)->move_player("with an astonished look#"+wheree); 
      tell_object(this_player(),"Something has gone wrong!\n"); }
  else {
   tell_object(find_player(str), "You appear before your beloved.\n");
   write("You summon your beloved.\n");
   tell_room(environment(this_player()),capitalize(str) + " materializes.\n");
   move_object(find_player(str), environment(this_player())); }
   return 1;
}

go ( string str ) {
   string here, there;
   string wheree;
   if ( !str ) {
      notify_fail("Go <spouse>.\n");
      return 0;
   }
   if ( lower_case(str) != spouse ) {
      notify_fail("That person is not your spouse.\n");
      return 0;
   }
   if ( !find_player(str) ) {
      notify_fail(capitalize(str) + " is not logged in.\n");
      return 0;
   }
   if(this_player()->query_sp() < 70) {
      notify_fail("You need at least 70 spell points.\n");
      return 0;
   }
   here = environment(this_player())->realm();
   there = environment(find_player(str))->realm();
   if( here == "NT" || there == "NT" ) {
      notify_fail("A warping of space prevents you.\n");
      return 0;
   }
   this_player()->add_spell_point(-70);
   if(wheree = call_other("obj/base_tele","teleport")) {
      this_player()->move_player("with an astonished look#"+wheree); }
  else {
   write("You appear before your beloved.\n");
   tell_room(environment(find_player(str)), my_name + " materializes.\n");
   move_object(this_player(), environment(find_player(str))); }
   return 1;
}

set_spouse ( string str ) {
  spouse_name = capitalize(str);
  spouse = lower_case(str);
  if ( spouse_name ) married = 1;
  else married=0;
}

set_owner ( string str ) {
  my_name = capitalize(str);
}

get () { return 1; }
drop () { return 1; }

quit () {
  ring_chat(":leaves you all alone.\n");
}

query_spouse () { return spouse; }

throw ( string str ) {
   if ( !str || str != "ring" ) return 0;
   write("You toss your wedding ring high into the air never to be seen " +
    "again.\n");
   say(this_player()->query_name() + " throws a ring into the air and it " +
    "vanishes.\n");
   destruct(this_object());
   return 1;
}

restore ( string str ) {
   object new;
   if ( !str || str != "ring" ) return 0;
   if ( !spouse_name || !find_player(spouse) ) {
      notify_fail(spouse_name +" is not on.\n");
      return 0;
   }
   new = clone_object("/players/bastion/closed/ring.c");
   new->set_spouse(this_player()->query_real_name());
   new->set_owner(spouse);
   write(spouse_name + "'s wedding ring has been restored.\n");
   move_object(new, find_player(spouse));
   tell_object(find_player(spouse), "Your ring has been restored.\n");
   return 1;
}
 
renew_my_ring () {
   object ob;
   ob = clone_object("/players/bastion/closed/ring.c");
   ob->set_owner(my_name);
   ob->set_spouse(spouse);
   move_object(ob, environment(this_object()));
   tell_object(environment(this_object()), this_player()->query_name() + 
    " replaced your wedding ring.\n");
   destruct(this_object());
   return 1;
}

renew_all_rings ( string str ) {
   object *all, *rings, *inv;
   int i;
   if ( !str || str != "rings" ) {
      notify_fail("Renew what?\n");
      return 0;
   }
   all = users();
   rings = ({ });
   for ( i = 0; i < sizeof(all); i++ ) {
      inv = all_inventory(all[i]);
#ifndef __LDMUD__ /* Rumplemintz */
      rings += filter_objects(inv, "filter_rings", this_object());
#else
      rings += filter(inv, "filter_rings", this_object());
#endif
   }
   for ( i = 0; i < sizeof(rings); i++ ) {
      rings[i]->renew_my_ring();
   }
   renew_my_ring();
   write("Done.\n");
   return 1;
}
