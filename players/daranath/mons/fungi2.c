inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

     set_name("shrieker");
     set_short("Shrieker");
     set_race("fungus");
     set_gender("creature");
     set_long("The Shrieker is a large, organish toadstool with redish\n"+
              "spots along the crest of its top. An organic 'foot' allows\n"+
              "it to move along the tunnels of the UnderDark at a surprising\n"+
              "pace, given that its a mushroom and all....\n");
     set_level(5);
     set_ac(5);
     set_wc(9);
     set_hp(90 + random(40));
     set_al(50);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(30);
     load_chat("The shrieker moves around the chamber at random.\n");
     load_a_chat("The shrieker launches a cloud of spores at you.\n");
       load_a_chat("\n\n   S  H  R  I  E  K!!!!!\n\n");
     call_out("shriek",random(100));
    /* oks  about callout...
         callout is like the goto in basic... except the sytax is different
         call_out(function name,# of seconds to wait before calling the function);
         so in this case in random(100) secs the function shriek() will be called */
   }
}

shriek() {
int hh,kk; 
object obt;
if(query_attack()) {
hh = kk = 0;
  obt = all_inventory(environment(this_object()));
    while(kk<sizeof(obt) && !hh) {
      if(obt[kk]->is_player()) hh = 1; 
      kk++; }
  if(hh) {
  tell_room(environment(this_object()),"\n\n   S H R I E K !!!!!!\n\n");
   /* tell_room will tell all living objects in the object that is indicated
        in this case environment(this_object()) */
  tell_room(environment(this_object()),"A Monster comes in alarmed by the noise.\n");
   move_object(clone_object("/players/daranath/mons/fungi0.c"),
       environment(this_object())); 
  } 
  call_out("shriek",random(100) + 100); }
  else call_out("shriek",20);
   /* to do a callout loop you must refer back to original function */
return 1; }
