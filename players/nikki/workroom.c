/*   This is a generic wiz workroom.  It has a number of examples
	that should help you get started. Before you get too far along,
	you should change 'your_name' to your real name. (i.e I would
	change 'your_name' to "eurale")  I've tried to include things
	that most people want to add so look through and if you still
	have questions, contact someone for help.  Enjoy  -Eurale
*/

#include "/players/nikki/ansi.h"
#define TP this_player()
#define NAME "nikki"
inherit "room/room";
int shield;

reset(arg) {
  if(arg) return;

short_desc = HIY+"A Cardboard Box"+NORM;
      
long_desc = 
"               "+HIY+" _..._                            "+HIY+" _..._\n"+
"              "+HIY+".~     `~.                       "+HIY+".~`     ~.\n"+
"      "+HIW+",_     "+HIY+"/          }"+HIW+"       Welcome       "+HIY+"{          \\"+HIW+"     _,\n"+
"     "+HIW+",_\\'--, "+HIY+"\\   _.'`~~"+NORM+"/ "+HIW+"To the Cardboard Box"+NORM+"  \\"+HIY+"~~`'._   /"+HIW+" ,--'/_,\n"+
"      "+HIW+"\\'--,_`"+HIY+"{_,}"+NORM+"    -(                         )-    "+HIY+"{,_}"+HIW+"`_,--'/\n"+
"       "+HIW+"'.`-.`\\"+HIC+";--,"+NORM+"___.'"+HIR+"_                       "+HIR+"_"+NORM+"'.___,"+HIC+"--;/"+HIW+"`.-`.'\n"+
"         "+HIW+"'._`"+HIC+"/    |_ "+NORM+"_"+HIR+"{@}                     "+HIR+"{@}"+NORM+"_ _"+HIC+"|    \\"+HIW+"`_.'\n"+
"            "+HIC+"/     ` |"+NORM+"-'"+HIG+";/            "+HIM+"_        "+HIG+"\\;"+NORM+"'-"+HIC+"| `     \\\n"+
"           "+HIC+"/   \\    /  "+HIG+"|        "+HIM+"_   "+HIM+"{@}"+HIY+"_      "+HIG+" |  "+HIC+"\\    /   \\\n"+
"          "+HIC+"/     '--;_        "+HIY+"_ "+HIM+"{@} "+HIR+" _"+HIG+"Y"+HIY+"{@}         "+HIC+"_;--'     \\\n"+
"         "+HIB+"_"+HIC+"\\          `\\     "+HIY+"{@}"+HIG+"\\Y/"+HIY+"_"+HIR+"{@} "+HIG+"Y/       "+HIC+"/`          /"+HIB+"_\n"+
"        "+HIB+"/ "+HIC+"|`-.___.    /     "+HIG+"\\Y/\\|"+HIY+"{@}"+HIG+"Y/"+HIG+"\\|//      "+HIC+"\\    .___,-'"+HIB+"| \\\n"+
"  "+HIG+"^^^^^"+HIB+"`--"+HIC+"`------'`--`"+HIG+"^^^^^^^^^^^^^^^^^^^^^^^^^^^"+HIC+"`--`'------"+HIB+"`--`"+HIG+"^^^^^\n"+
HIC+
"   You have entered a large shadowy room.  A pungent sweet smell of\n"+
"incense dances upon the air.  The music of INXS is singing thru the\n"+
"room.  As you glance around the room you notice an intricate black\n"+
"ink mural drawn with such skill, like spiderwebs on the white plaster\n"+
"walls.  The ceiling is a molded frieze of prancing demons and hags\n"+
"on broomsticks circling around the moon.  Towards the rightside of\n"+
"the room you notice two large pillars made of black marble and\n"+
"between the pillars stands a coffin made of mahogany. Many large\n"+
"embroidered feather pillows are laying in the center of marble floor.\n"+
GRY+"A set of large double doors (closed)\n\n"+NORM;
set_light(1);

items = ({
  "mural","The mural depicts a ruined castle on a cliff, dark and towering above\n"+
          "a graveyard with a circle of beings in black robes dancing to the\n"+
          "violin music of the devil, who is sitting on the moon",
  "walls","Covered with intricate black ink murals",
  "castle","The castle seems to be from the early first century",
  "ceiling","Several molds of hags on broomsticks and prancing demons are\n"+
            "encircling the moon",
  "broomsticks","Typical wooden handled brooms with tattered straw tied to the ends",
  "demons","Ghoulish dark beings",
  "hags","Old crones sitting upon broomsticks",
  "moon","It looms above the scene below as if it is the creator and lover of\n"+
         "all that is benevolent",
  "pillars","Black smoky marble pillars stand guardian for the large coffin",
  "marble","It is one of the hardest and most beautiful stones known to mankind",
  "coffin","The large mahogany coffin has pictures carved into it, depicting one\n"+
           "tales of the Great Dracul.  A great banquet table brimming with food\n"+
           "and drink is placed in the middle of a forest.  Prince Dracul is\n"+
           "sitting at the head of the table with his beautiful daughter at his\n"+
           "side.",
  "pillows","Embroidered, tapestry material covers the large, goose down, filled pillows",
  "floor","The marble on the floor is polished to a high shine",
  "doors","Large teak wood double doors",
  "graveyard","Many headstones are scattered among the yard",
  "beings","Cloaked in black robes, it is impossible to see what exactly they are",
  "devil","He sits upon the moon playing fiendishly for the parade below",
  "forest","When looking closer at the forest you notice they are the impaled bodies\n"+
           "of Prince Dracul's enemies",
  "table","A feast of food and drink lay sprawled across the table",
  "food","Many varieties of meats, cheeses and breads",
  "drink","Dark liquid fill the pitchers and glasses",
  "dracul","A brooding man who imminates great power",
  "daughter","She is breath-takingly beautiful with her alabaster skin and long raven hair\n"+
             "sits proudly next to her father",
});

dest_dir = ({
  "players/nikki/workroom.c","sidewalk",
  "players/nikki/workroom.c","starve",
});
}

init() {
  ::init();
  add_action("north","north");
  add_action("on"); add_verb("on");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
  add_action("west"); add_verb("west");
if(this_player()->query_real_name() != NAME && shield == 1) {
  write(HIG+"You feel an intense pressure in your brain as a single thought\n");
  write("enters your mind. 'I wouldn't suggest doing that again.'\n"+NORM);
  this_player()->move_player("Mystified#room/police");
  return 1; }
 }

north() {
  TP->move_player("north#room/vill_green");
  return 1; }

static on() {
  write(HIG+"The Mist has formed...\n"+NORM);
  shield = 1;
  return 1; }

static off() {
if(TP->query_real_name() != NAME) {
  write(CLR+"\n\n\n\n\n\t\t\t"+BLINK+HBRED+HIW+"LEAVE MY MIST ALONE!"+NORM+"\n\n\n\n\n\n"+NORM);
  return 1; }
  write(HIW+"The Mist has dissipated...\n"+NORM);
  shield = 0;
  return 1; }

post(){
  TP->move_player("to the post office#room/post");
  return 1; }

west() {
  TP->move_player("west#/players/nikki/Tintagel/Rooms/entrance");
  return 1; }
