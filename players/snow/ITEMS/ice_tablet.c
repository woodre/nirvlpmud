inherit "obj/treasure";
 
reset(arg)  {
  if(arg) return;
 
   set_id("tablet");
   set_short("A SPARKLING ice tablet");
   set_long(
   "An ice tablet with inscriptions you can read.\n");
   set_weight(500);
   set_value(0);
}
 
init() {
  if(this_player()->query_real_name() == "garbageman" &&
      this_player()->query_npc()) destruct(this_player());
  add_action("read_tablet","read");
}
 
read_tablet(str)  {
if(str == "tablet")  {
  write(
"The inscriptions read:\n"+"\n"+
"Snow's Interdimensional Gate is now open. The Fortress is complete and\n"+
"is filled with incredibly dangerous monsters. If you are looking for\n"+
"challenging fights with great rewards, this is the place for you.\n"+"\n"+
"Adventurers should be at least 14th level to attempt battling the \n"+
"vicious creatures that thrive on Snow Mountain. Bring heals and a party.\n"+
"\n"+
"For mid-level players, the Nexus provides the beach and Shadowgate.\n"+
"Shadowgate is not as dangerous as the mountain but heals and a party\n"+
"are still recommended. New weapons, armor, and treasure abound.\n"+
"\n"+
"The Nexus also offers transport to a newbie area. Level 6 and under should\n"+
"enjoy it immensely.\n"+"\n"+
"To get to either of these venues, the directions from the church are:\n"+
"s,4w,4n,w - then 'enter gate'.\n"+
"Good luck!\n");
  say(this_player()->query_name()+" reads an ice tablet.\n");
 
    return 1;   }
        }
