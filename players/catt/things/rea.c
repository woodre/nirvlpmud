inherit "obj/monster";
object owner, soul;
reset(arg) {
   set_name("rea");
   set_short("Rea the legendary warrior (black knight)");
   set_long("Rea the legendary warrior (black knight) (female) \n"+
            "Rea is dressed entirely in black. She is of lithe and supple form.\n"+
        "Rea is a human, 5 feet 4 inches tall and 115 lbs.\n"+
            "Rea is carrying:\n"+
            "Rea's quicktyper.\n"+
            "Black Hakama of the Night (worn)\n"+
            "Book of Contracts\n"+
            "Bag of Tricks\n"+
            "Ring of the Asp (worn)\n"+
            "Boots of Speed (worn) \n"+
            "Elder Assassins Dagger (wielded)\n");
   set_level(19);
   set_hp(10000);
   set_wc(18);
   enable_commands();
}

set_owner(str) {
   if(!str) return;
   owner = str->query_real_name();
   tell_object(find_player(owner), "You are Rea's Master now.\n");
   return 1;
}

init() {
   add_action("soul_finger","finger");
   add_action("dest","destruct");
   add_action("dest","dest");
   add_action("dest","update");
}
dest() {
   write("Rea says: I cannot allow you to destroy me.\n");
   say("Rea dodges your feeble attempt to destroy her.\n");
   tell_object(find_living(owner), "-->Rea tells you: There has been an attempt on my life!!\n");
   return 1;
}
fry() {
   say("Rea crumples to dust before your eyes.\n");
   destruct(this_object());
   return 1;
}
soulemote(str) {
   say("Rea "+str+"\n");
   tell_object(find_living(owner), "-->Rea emoted: "+str+"\n");
   return 1;
}
soulecho(str) {
   say(str+"\n");
   tell_object(find_living(owner), "-->Rea echoed: "+str+"\n");
   return 1;
}
west() {
   command("west", this_object());
   this_object()->slook();
   return 1;
}
east() {
   command("east", this_object());
   this_object()->slook();
   return 1;
}
south() {
   command("south", this_object());
   this_object()->slook();
   return 1;
}
north() {
   command("north", this_object());
   this_object()->slook();
   return 1;
}
down() {
   command("down", this_object());
   this_object()->slook();
   return 1;
}
up() {
   command("up", this_object());
   this_object()->slook();
   return 1;
}
soulto(str) {
   object target;
   target = find_player(str);
   say("Rea gets something from her bag of tricks.\n");
   say("Rea throws a smoke ball and disappears during the confusion.\n");
   move_object(this_object(), environment(target));
   tell_object(find_living(owner), "-->Rea teleports to "+str+"\n");
   slook();
   return 1;
}
ssay(str) {
   say("Rea says: "+str+"\n");
   tell_object(find_living(owner), "-->Rea says: "+str+"\n");
   return 1;
}
stell(str) {
   string who, what;
   object who1;
   if(sscanf(str, "%s %s", who, what) == 2) {
      who1 = find_player(who);
      tell_object(who1, "Rea tells you: "+what+"\n");
      tell_object(find_living(owner), "-->Rea tells "+who+": "+what+"\n");
      return 1;
   }
}
slook() {
   object home;
   home = environment(find_living(owner));
   move_object(find_living(owner), environment(this_object()));
   command("look", find_living(owner));
   move_object(find_living(owner), home);
   return 1;
}
catch_tell(str2) {
   string s1;
   tell_object(find_living(owner), "--> "+str2+"\n");
   return 1;
}
soul_finger(str) {
   if(!str) return 0;
   if(str != "rea") return 0;
   if(str == "rea") {
      tell_object(this_player(),
         "Rea the legendary warrior (black knight)\n"+
         "Level:        19+6\n"+
         "Guild name: assassins\n"+
         "Guild Rank: grand elder\n"+
         "Player Killer:   Yes\n"+
         "Last called at: Not logged off.\n"+
         "Age: 13 days 22 hours 4 minutes 43 seconds.\n");
      tell_object(find_living(owner),
         "-->Rea tells you: I have been fingered by "+this_player()->query_real_name()+"\n");
      return 1;
   }
   return 0;
}
