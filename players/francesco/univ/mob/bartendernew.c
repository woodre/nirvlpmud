

#define TP this_player()

inherit "obj/monster";

reset(arg){
  
object gold;
object nug;
object buyer;

 ::reset(arg);
   if (arg) return;
   set_name("hope");
   set_race("human");
   set_alias("bartender");
      set_short("Hope, the bartender");
     set_long("The bartender is a woman of strong frame, long black hair and\n"+
              "deep violet eyes, standing about 5'9\".  She is of poor origins\n"+
              "and wanted to achieve high level of knowledge until she got her\n"+
              "computer sciences degree.  Now she enjoyes managing her own bar\n"+ 
              "and continuously meeting with professors and students.  She is\n"+
              "of bubbly temperment.  Thus, if you 'ask' she could tell you\n"+
              "what items are available to 'purchase' in order to make your\n"+
              "stay here safer and more enjoyable.  Also, she has been appointed\n"+
              "to give you what you ask to 'obtain' from the certificates.\n");

   set_level(20);
   set_hp(956);
   set_al(0);
   set_wc(31);
   set_ac(22);
   set_heal(10,2);
 gold = clone_object("obj/money");
 gold->set_money(600+random(50));
 move_object(gold,this_object());
 set_aggressive(0);
}

init() {
add_action("ask","ask");
add_action("purchase","purchase");
}

ask(str) {
     if(str!="hope") {return 0;}
  write("\nHope takes a menu list, opens it and says.... \n"+
	"I can sell you four types of items: \n"+
	"   Barbera wine         (alcoholic, 13 degrees)              1800 coins \n"+
        "   White bread          (food, 290 kcal)                     1650 coins\n"+
        "   Iced tea             (beverage, very cold)                1650 coins\n"+
        "   Frappe'              (hypercaloric alcoholic beverage)    1650 coins\n"+
	"purchase what you'd like.... \n"+
	"\nThen she grabs you for your neck, pulls you closer and whispers:\n"+
        "For the very brave mudders we have also a particular item......\n"+
        "and, just for you, my friend, we can make a special price......\n"+
        "   Special of the house (no description given)               1200 coins\n"+
        "\nI can also sell you the ticket for the cinema                 100 coins\n"+
        "And if you want to play some games, just type it.\n"); 
  return 1; }

purchase(str) {
object item;
int value, m, heavey;
m = 0;

if(str == "wine") {
  item = clone_object("players/francesco/univ/items/barbera.c");
  value = 1800;
  m = 1; }
if(str == "bread") {
  item = clone_object("players/francesco/univ/items/panino.c");
  value = 1650;
  m = 1; }
if(str == "tea") {
  item = clone_object("players/francesco/univ/items/tea.c");
  value = 1650;
  m = 1; }
if(str == "frappe'") {
  item = clone_object("players/francesco/univ/items/frappe.c");
  value = 1650;
  m = 1; }
if(str == "special") {
  item = clone_object("players/francesco/univ/items/special.c");
  value = 1200;
  m = 1; }
if(str == "ticket") {
  item = clone_object("players/francesco/2001/items/ticket.c");
  value = 100;
  m = 1; }


if(m) {
if(this_player()->query_money() <value) {
  write("You do not have enough to purchase this item! \n");
return 1; }

if(!call_other(TP,"add_weight",call_other(item,"query_weight"))) {
write("You better lighten your inventory before buying anything else.\n");
return 1; }

/*  take the coins from the player  */
this_player()->add_money(-value);

move_object(item,this_player());
say(capitalize(this_player()->query_real_name())+" purchases a "+str+".\n"); }
else {
  write("That item cannot be purchased here. \n"); }
return 1;
}
