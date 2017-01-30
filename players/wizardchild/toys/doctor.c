inherit "/obj/monster";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("doctor");
  set_alias("old doctor");
  set_short("An old-looking doctor");
  set_long("An old-looking doctor, carrying a small bag of some sort. He appears\n"
          +"to be selling medical equipment of some sort. Type \"list\" for a list\n"
          +"of items.\n"
          +"    Doctor is carrying:\n"
          +"A small bag of some sort.\n");
  load_chat("The doctor says: Those forests can be lethal!\n");
  load_chat("The doctor says: My innoculation guns will prevent disease!\n");
  set_chat_chance(10);
  set_level(100);
  set_wc(100);
  set_ac(50);
  set_hp(4000);
  add_spell("poison","\
The doctor pulls a needle out his bag and plunges it into your neck!\n\
It feels like ACID in your veins!","\
The doctor pulls a needle out his bag and plunges it into #TN#'s neck!\n",
20, "30-60", "other|poison");
  add_spell("scalpel","\
The doctor pulls a scalpel out of his bag and swipes at you.  For a \
moment, you think he missed, and then the blood starts to flow...\n","\
The doctor pulls a scalpel out of his bag and swipes at #TN#.  For a \
moment, you think he missed, and then the blood starts to flow...\n",
  15, "49-50", "magical"); /* magical damage to simulate armor penetration */

}
id(str) { 
  return str == "doctor" || str == "old looking doctor" || str == "old doctor"; 
}  
init() {
  add_action("list", "list");
  add_action("buy", "buy");
  ::init();
}
list() {
  write("The doctor says: What do you think I sell, sonny?\n");
  write("The doctor says: The only thing I can sell around here is the innoculation\n");
  write("gun.\n");
  return 1;
}
buy(str) {
  object ob;
  if(str == "gun" || str == "innoculation gun") {
    if(this_player()->query_money() < 250) {
      write("The doctor says: These things cost 250, son.\n");
      return 1;
    }
    write("The doctor says: Here you go, sonny.\n");
    ob = clone_object("/players/wizardchild/toys/innoc");
    move_object(ob, this_player());
    this_player()->add_money(-250);
  } else 
    write("The doctor says: I don't sell those!\n");
  return 1;
}
