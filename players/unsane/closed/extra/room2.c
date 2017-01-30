inherit "room/room";

#define tp this_player()->query_name()
int i;

reset (arg){
   if (!arg){
      set_light(1);
   }
   if (!present("dancer")){
      move_object(clone_object("/players/unsane/closed/extra/girl.c"),this_object());
      if (!present("keep"))move_object(clone_object("/players/unsane/closed/extra/keep.c"),this_object());
      if (!present("bundy"))move_object(clone_object("/players/unsane/closed/extra/bundy.c"),this_object());
      short_desc="The Nudie Bar";
      long_desc=
      "This is the back of the nudie bar.  It is particularly unsavory, not for the\n"+
      "atmosphere, but rather for the company.  For you see, this is the permanent\n"+
      "bar area residence of one Al Bundy!  Hopefully you will get lucky and the\n"+
      "great unwashed one will not be present at the moment.  Don't bet on\n"+
      "it though.  He seems to really dig this particular dancer.  It's odd, the\n"+
      "bar in this area is exactly the same... and this dancer seems to look the same\n"+
      "as well too?\n";
      items=({
            "booth","These booths are covered with a sticky substance that you'd rather leave alone",
            "boothes","Yes you know, the plural of booth",
            "table","This particular table is covered with Al's drool",
            "tables","Plenty of tables open here, who would want to sit by Al?",
            "butts","Lucky Strike cigarette butts, only the best in this bar",
            "bottles","Hmmmm, pabst genuine draft... Fuck heineken",
            "butt","Your eyes wander towards the dancer's butt and Al growls",
            "bottle","There are a few sips left in this one... Nothing like stale beer",
            "bar","Where the Bundy's kick ass",});
      dest_dir=({
            "/players/unsane/closed/extra/titti.c","west",});
   }
}
init(){
   ::init();
add_action("enter","enter");
   add_action("list","list");
   add_action("buy","buy");
   add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
this_player()->set_fight_area();
}
list(){
   write("*-------------------------------------------------------------------------*\n"+
      "     (1)   Coffee         520 coins\n"+
      "     (2)   Fuzzy Navel    280 coins\n"+
      "     (3)   Vodka          340 coins\n"+
      "     (4)   Whiskey        420 coins\n"+
      "     (5)   Beer           490 coins\n"+
      "\n           Please buy by the numbers.\n"+
      "*-------------------------------------------------------------------------*\n");
   return 1;}
realm(){ return "NT";}
buy(str){
   if (!str) {write("Bartender says: Look bub, what do you want to buy?\n");
      return 1;}
   if (!this_player()->add_weight(1)){write("You can't carry all of this.\n"); return 1;}
   if (str=="1") {
      if (this_player()->query_money() < 520) {
         write("You don't have enough money for coffee.\n");
         return 1;}
      move_object(clone_object("/players/unsane/closed/extra/sober.c"),this_player());
      this_player()->add_money(-520);
      write("You buy a coffee.\n");
say(this_player()->query_name()+" buys a coffee.\n");
      return 1;
   }
   if (str=="2") {
      if (this_player()->query_money() < 280) {
         write("Bartender says: You don't have the cash, bub\n");
         return 1;}
      move_object(clone_object("/players/unsane/closed/extra/fruit.c"),this_player());
      this_player()->add_money(-280);
      write("You buy a Fuzzy Navel.\n");
say(this_player()->query_name()+" buys a Fuzzy Navel.\n");
      return 1;
   }
   if (str=="3") {
      if (this_player()->query_money() < 340){
         write("Bartender says: You don't have the money, man.\n");
         return 1;}
      move_object(clone_object("/players/unsane/closed/extra/fagan.c"),this_player());
      this_player()->add_money(-340);
      write("You buy some Popov's Vodka.\n");
say(this_player()->query_name()+" buys some Vodka.\n");
      return 1;
   }
   if (str=="4") {
      if (this_player()->query_money() < 420){
         write("Bartender says: Nice try cheapskate.. you need more cash.\n");
         return 1;}
      move_object(clone_object("/players/unsane/closed/extra/paul.c"),this_player());
      this_player()->add_money(-420);
      write("You buy some Old Crow.\n");
say(this_player()->query_name()+" buys some Old Crow Whiskey.\n");
      return 1;
   }
   if (str == "5") {
      if (this_player()->query_money() < 490){
         write("Bartender says:  Ahh Ahh Ahh, What were you going to pay with??\n");
         return 1;}
      move_object(clone_object("/players/unsane/closed/extra/beer.c"),this_player());
      this_player()->add_money(-490);
      write("You buy some beer.\n");
say(this_player()->query_name()+" buys some Pub Beer.\n");
      return 1;}
   write("Bartender says: What do you want????\n");
   return 1;}

search(){
write("You find a gaping hole under one of the tables, a foul stench emanates\n"+
"from it.  Perhaps you could enter the hole?\n");
   
   say(tp+" searches about the room.\n");
   return 1;
}
enter(str){
if (str=="hole" || str=="pit"){
write("Sorry, it's not open yet.\n");
return 1;
  write("You enter into the pit of dispair underneath the bar.\n");
say(this_player()->query_name()+" drop through a hole in the floor.\n");
move_object(this_player(),"/players/unsane/closed/extra/pit.c");
say(this_player()->query_name()+" arrives through the hole.\n");
command("look",this_player());
return 1;}
write("Enter what??\n");
return 1;}
smell(){
   write("This place smells of stale smoke, beer and stale jokes.\n");
   say(tp + " takes a deep breath of the air here.\n");
   return 1;
}
listen(){
   if (!present("girl")) {
      write("All you can hear is lame bar chatter.\n");
   }
   if (present("girl")) {
      write("You hear the dancer's tassles swooshing through the air.\n");
   }
   say(tp + " perks up their ears.\n");
   return 1;
}

