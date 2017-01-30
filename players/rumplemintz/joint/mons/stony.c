inherit "obj/monster";
#define me              this_object()
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("stony");
   set_race("human");
   set_short("Stony");
   set_long(
   "    Stony (Pauly Shore) loves cruisin the gig and weasin the\n"+
   "ju------uice bu--ddy.  But, if he had the whole brady bunch\n"+
   "thing kickin' over at his pad, then he'd munch over there\n"+
   "so don't tax his gig so hard core cruster!\n");
   set_level(19);
   set_hp(470);
   set_ac(19);
   set_wc(28);
   set_al(250);
   set_dead_ob(me);
   call_out("qt",10);
}

monster_died(){
  move_object(clone_object("/players/rumplemintz/joint/obj/scooter"),me);
  return 0;
}

qt() {
  object ob;
   say("Stony says: Cashmere, Rashnish, is it, how many minutes for the\n"+
        "burrito again?\n");
   if(present("cashmere", environment(me))){
     call_out("qt_2",2);
     return 1;
   }
   else {
     say("Stony says: No one's tendin' cash! let's steal some shit!\n");
     return 1;
   }
}

qt_2() {
  object ob;
   say("Cashmere says: Two minutes.\n");
   if(present("rashnish", environment(me))){
     call_out("qt_3",2);
     return 1;
   }
   else {
     say("Cashmere says: Rashnish!  Get in here, it's him!\n");
     return 1;
   }
}

qt_3() {
   say("Rashnish says: One minute.\n");
   call_out("qt_4",2);
   return 1;
}

qt_4() {
   say("Cashmere says: Two minutes.\n");
   call_out("qt_5",2);
   return 1;
}

qt_5() {
   say("Rashnish says: One and a half minute.\n");
   call_out("qt_6",1);
   return 1;
}

qt_6() {
   say("Stony says: Ahhhhh, make up your melons.\n");
   if(present("link", environment(me))){
     call_out("qt_7",0);
     return 1;
   }
   else {
     say("Stony says: Where's Link?!\n");
     return 1;
   }
}

qt_7() {
   say("Link says: Ahhhhh.\n");
   call_out("qt_8",2);
   return 1;
}

qt_8() {
   say("Stony says: Is it one, or two.\n");
   call_out("qt_9",3);
   return 1;
}

qt_9() {
   say("Rashnish says: One and a half minute.\n");
   call_out("qt_10",1);
   return 1;
}

qt_10() {
   say("Stony says: k, ok my friend, try and experience what I'm about to\n"+
       "chirp on your lobes, ok cool?\n");
   call_out("qt_11",1);
   return 1;
}

qt_11() {
   say("Link says: Uh.\n");
   call_out("qt_12",2);
   return 1;
}

qt_12() {
   say("Stony says: Today buddy, we're gonna discuss grindage.\n");
   call_out("qt_13",1);
   return 1;
}

qt_13() {
   say("Stony says: How to fill the furnace, pack the cheeks, and stuff the gills.\n");
   call_out("qt_14",1);
   return 1;
}

qt_14() {
   say("Link says: Uh.\n");
   call_out("qt_15",1);
   return 1;
}

qt_15() {
   say("Stony says: K?\n");
   call_out("qt_16",1);
   return 1;
}

qt_16() {
   say("Stony says: You're probably used to eatin' twigs, right?\n");
   call_out("qt_17",1);
   return 1;
}

qt_17() {
   say("Link says: Uh.\n");
   call_out("qt_18",1);
   return 1;
}

qt_18() {
   say("Stony says: But out here in the U-S-of A-age buddy, we got somethin called\n"+
       "the four basic food groups, And Link, this is not one of emmm.\n");
   call_out("qt_19",1);
   return 1;
}

qt_19() {
   say("Link says: Oh.\n");
   call_out("qt_20",2);
   return 1;
}

qt_20() {
   say("Stony says: Look at what we have here.\n");
   call_out("qt_21",1);
   return 1;
}

qt_21() {
   say("Stony says: Dairy group.\n");
   call_out("qt_22", 1);
   return 1;
}

qt_22() {
   say("Link says: Dairy grooo.\n");
   call_out("qt_23",1);
   return 1;
}

qt_23() {
   say("Stony says: Milk duds.\n");
   call_out("qt_24",1);
   return 1;
}

qt_24() {
   say("Stony says: You hide these under your pillow bro so you mom doesn't\n"+
       "find em, if she does, you're tweeded buddy.\n");
   call_out("qt_25",1);
   return 1;
}

qt_25() {
   say("Link says: Uh.\n");
   call_out("qt_26",2);
   return 1;
}

qt_26() {
   say("Stony says: Keep on cruisin,\n");
   call_out("qt_27",1);
   return 1;
}

qt_27() {
   say("Stony says: Fruit group.\n");
   call_out("qt_28",1);
   return 1;
}

qt_28() {
   say("Stony says: Sweet-tarts.\n");
   call_out("qt_29",1);
   return 1;
}

qt_29() {
   say("Link says: Uh.\n");
   call_out("qt_30",1);
   return 1;
}

qt_30() {
   say("Stony says: These are killer buddy, so citrusy dude, you'll freak.\n");
   call_out("qt_31",1);
   return 1;
}

qt_31() {
   say("Stony says: Keep on cruisin,\n");
   call_out("qt_32",1);
   return 1;
}

qt_32() {
   say("Stony says: Uh huh, allright, this is the vegetable group.\n");
   call_out("qt_33",1);
   return 1;
}

qt_33() {
   say("Stony says: Vegetable group.\n");
   call_out("qt_34",1);
   return 1;
}

qt_34() {
   say("Stony says: Ohhhh, cornuts, oohhh, put em on a pedestal bro.\n");
   call_out("qt_35",1);
   return 1;
}

qt_35() {
   say("Stony says: Look at that, oohh ya, those are kill huh?\n"+
       "\n"+
       "\n"+
       "                         ***  DING!!!   ***\n");
   call_out("qt_36",1);
   return 1;
}

qt_36() {
   say("Stony says: MEAT GROUP!\n");
   call_out("qt_37",1);
   return 1;
}

qt_37() {
   say("Stony says: These are my favorite.  Ahhhh\n");
   call_out("qt_38",1);
   return 1;
}

qt_38() {
   say("Link goes ummmmmmmmm\n");
   call_out("qt_39",1);
   return 1;
}

qt_39() {
   say("Stony says:  heyy, he--eeyyyy, don't, ya gotta be equal, equals.\n");
   call_out("qt_40",1);
   return 1;
}

qt_40() {
   say("Link says: Uh?\n");
   call_out("qt_41",1);
   return 1;
}

qt_41() {
   say("Stony says: Fifty-fifty, here.\n");
   call_out("qt_42",1);
   return 1;
}

qt_42() {
   say("Stony spits on the ground.\n");
   say("Link spits on the ground.\n");
   call_out("qt_43",1);
   return 1;
}

qt_43() {
   say("Stony says: eewwww, figures, hot on the outside, icy cold in the middle.\n");
   call_out("qt_44",1);
   return 1;
}

qt_44() {
   say("Cashmere says: Two minutes.\nCashmere laughs.\n");
   call_out("qt_45",1);
   return 1;
}

qt_45() {
   say("Stony says: But you like that right, cause you're a caveman...cool.\n");
   call_out("qt_46",3);
   return 1;
}

qt_46() {
   say("Stony says: The beverage!\n");
   call_out("qt_47",1);
   return 1;
}

qt_47() {
   say("Stony says: The icee bro, this is what put this place on the map.\n");
   call_out("qt_48",1);
   return 1;
}

qt_48() {
   say("Stony puts his head under the icee machine and weases!\n");
   call_out("qt_49",1);
   return 1;
}

qt_49() {
   say("Cashmere says: What are you doing Mr. Stony, no, you can't do that,\n"+
       "Cashmere says: You can't do this here!\n");
   call_out("qt_50",1);
   return 1;
}

qt_50() {
   say("Rashnish says: Leave now, now, you must leave now, please.\n");
   call_out("qt_51",1);
   return 1;
}

qt_51() {
   say("Stony says: Look, Cashmere, Rashnish, why doncha just chill buds.\n");
   call_out("qt_52",1);
   return 1;
}

qt_52() {
   say("Rashnish says: No buds chill!\n");
   call_out("qt_53",1);
   return 1;
}

qt_53() {
   say("Stony says: Link and I are cruisin the mountain bro, and we figured\n"+
       "we'd wease a little jui------------ice.\n");
   call_out("qt_54",1);
   return 1;
}

qt_54() {
   say("Cashmere says: No weasing the jui--ice.\n");
   call_out("qt_55",1);
   return 1;
}

qt_55() {
   say("Link says: Wease the juice.\nLink places his head under the icee machine.\n");
   call_out("qt_56",1);
   return 1;
}

qt_56() {
   say("Cashmere says: No, no, no weasing the juice!\n");
   call_out("qt_57",1);
   return 1;
}

qt_57() {
   say("Rashnish says: No weasing the juice.\n");
   call_out("qt_58",1);
   return 1;
}

qt_58() {
   say("Stony says: Chill bud.   Just chill.\n");
   call_out("qt_59",4);
   return 1;
}

qt_59() {
   say("Link says: I'll be back.\n");
   call_out("qt",30);
   return 1;
}
