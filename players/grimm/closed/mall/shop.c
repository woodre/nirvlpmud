#include "/players/grimm/header"
inherit "room/room";
object type;

reset(arg) {
  if(arg) return;
  short_desc="Mongo's Custom Armor Shop";
  long_desc=
  "You have entered Mongo's Custom Armor Shop.\n"+
   "If you would like to purchase an item you may type buy 'item'.  If you \n"+
   "wish to see a list of the availiable items you may type 'list'.\n"+
   "------------------------------------------------------------------------\n"+
   "To set the SHORT DESCRIPTION of the armor, you have to type the command\n"+
 "name+ the armor type.  example-->nameboots<-no space) 'your string here'.\n"+
 "So if i say        --- nameshield dragon shield ---        the name of the\n"+
  "shield when people see your inventory will be Dragon shield.  The armor\n"+
   "will retain the armor type such as cloak or gloves so that you may say\n"+
   "wear gloves or wear helmet.  To prevent the other shops from having an\n"+
   "enormous amount of strangely named armors, this will be the only shop to\n"+
   "buy back the armor.\n"+
   "------------------------------------------------------------------------\n"+
  "\n";
  dest_dir=({ "/players/grimm/closed/mall/hall4", "west", });
  set_light(1);
}
init() {
  add_action("buy","buy");
  add_action("sell","sell");
  add_action("list","list");
  add_action("west","west");
  add_action("west","w",1);
}
buy (item) {
   if(!item) return 0;
   if ((item != "shield")&&(item != "helmet")&&(item != "cloak")&&
      (item != "gloves")&&(item !="boots")) {
      write("I am sorry, all we sell are shields, boots, gloves, helmets, and cloaks.\n");
   return 1; }
   if(this_player()->query_money() < 250) {
      write("You don't have enough cash dude.\n");
   return 1; }
   type = clone_object(DIR4(cust)+item);
  if(transfer(type,this_player())==1) {
      write("You can't carry anymore!  Drop something!\n");
   return 1; }
   if(!present(type,this_player())) { 
      write("Your weight has problems, please call a wizard.\n");
   return 1; }
   this_player()->add_money(-250);
   write("Ok.\n");
return 1; }

sell(str) {
string item;
object armor;
item = "custom "+str;
   if(!str) return 1;
   if(!present(str,this_player())) {
      write("You don't have that!\n");
   return 1; }
   if(!present(item,this_player())) {
      write("We only buy back our things..Sorry\n");
   return 1; }
      armor = (present(item,this_player()));
      destruct(armor);
      this_player()->add_money(100);
      write("The shop gives you 100 coins.\n");
return 1; }
list () {
   write("             Sacred Blood Custom Armor Shop\n");
   write("            --------------------------------\n");
   write("                250 : Custom Cloak\n");
   write("                250 : Custom Helmet\n");
   write("                250 : Custom Shield\n");
   write("                250 : Custom Boots\n");
   write("                250 : Custom Gloves\n");
   write("            --------------------------------\n");
return 1; }

/*
north() {
this_player()->move_player("north#/players/grimm/guild");
return 1;
}
*/

west() {
this_player()->move_player("west#/players/grimm/closed/mall/hall4");
return 1;
}

/*
south() {
this_player()->move_player("south#/players/grimm/street6");
return 1;
}
*/
