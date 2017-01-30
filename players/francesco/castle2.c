#define NAME "Francesco"
#define DEST "room/forest11"
#define tp this_player()
#define tpn this_player()->query_name()

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
    return "The University";
}

long() {
    write("This is where you can enroll in order to increase your knowledge.\n");
}

init() {
    add_action("enroll","enroll");
}

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
if(!present("id",this_player())) move_object(item,this_player());
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

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
