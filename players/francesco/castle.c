#include "/players/francesco/univ/ansi.h"
#define NAME "Francesco"
#define DEST "room/forest11"
#define tp this_player()
#define tpn this_player()->query_name()

object qob;
object ob1;

/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "university"; }

short() {
    return "The University.\n"+
    ""+HIR+"C"+NORM+YEL+"o"+HIY+"l"+HIG+"o"+HIB+"r"+HIM+"s"+NORM+"" ;
}

long() {
    write("This is where you can enroll in order to increase your knowledge.\n");
}

init() {
#if 0 /* Rumplemintz */
    add_action("enroll"); add_verb("enroll");
    add_action("enter"); add_verb("enter");
#else
  add_action("enroll", "enroll");
  add_action("enter", "enter");
#endif
    add_action("kale","look");
    add_action("kale","l");
    add_action("kale","examine");
    add_action("kale","exa");
}
kale(arg) {
if(!arg) {return 0;}
if(arg == "colors" || arg == "at colors" ) {
write("An iridiscent pattern of colors, like a rainbow.  It can be entered.\n");
return 1;}}

enroll(str) {
object item;
    if (str!="into university")
	{
        write("Enroll into what?\n"); 
        return 1;
        }
 /**********   init changes for cloning the id   *****/
item = clone_object("players/francesco/univ/items/id.c");
if(!call_other(this_player(),"add_weight",call_other(item,"query_weight")))
 {
write("It is not possible to enroll students carrying their max capacity.\n");
return 1; }
/* changed from id to student id 5.1.06 verte */
if(!present("student id",this_player())) move_object(item,this_player());
/***** end changes for cloning the id  *****/
 write("You apply for the enrollment into University,  and a recorded\n"+
   "voice says:  Welcome, "+call_other(this_player(),"query_name")+".  Now you have the possibility of\n"+
    "improving your knowledge and your mind which are the true power\n"+
    "of the human being.  Take this ID and be proud of wearing it.\n\n");
 this_player()->move_player("into the University#players/francesco/univ/rooms/outside.c");
 write_file("/players/francesco/log/enter_univ",
             ctime(time())+"  "+tpn+
             "    [Level  "+tp->query_level()+"+"+tp->query_extra_level()+"]\n");    
 
 return 1;    

write("It is not an open castle.\n");
    return 1;
}

/******** modified 02.02.02 to add the kaleidoscope area ********/
enter(str){
  if(!str) {notify_fail("Enter what?\n"); return 0;}
  if(str=="colors"){
 this_player()->move_player("into the kaleidoscope#players/francesco/kale/rooms/entrance.c");
 write_file("/players/francesco/log/enter_kale",
             ctime(time())+"  "+tpn+
             "    [Level  "+tp->query_level()+"+"+tp->query_extra_level()+"]\n");    
 return 1;}
 notify_fail("You cannot enter the "+str+".\n"); return 0;}    
   

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
/****** adding the autoloads, 04.04.2001 ******/
"/players/francesco/quest/items/finaldegree.c"->hope_it_works();
/* ob1 = clone_object("players/francesco/quest/items/finaldegree.c");
move_object(ob1,this_object());
destruct(ob1);
clone_object("players/francesco/games/items/mastermindprize.c"));*/
/******          end autoloads           ******/

/******          quest addition          ******/
	if(!present("mastermind",find_object("room/quest_room.c"))) {
	qob = clone_object("obj/quest_obj");
	call_other(qob,"set_name","mastermind");
	call_other(qob,"set_hint","Login into Fran's computer and steal his data.\n");
	move_object(qob,"room/quest_room");}

	if(!present("graduation",find_object("room/quest_room.c"))) {
	qob = clone_object("obj/quest_obj");
	call_other(qob,"set_name","graduation");
	call_other(qob,"set_hint","Graduate in Mechanical Engineering at Nirvana University.\n"+
                                  "Miss Marian could give you more information.\n");
	move_object(qob,"room/quest_room");}
/******            end quests             ******/
}
is_castle(){return 1;}
