inherit "/players/data/toys/gname.c";
inherit "/players/data/toys/dsay.c";
#include "/players/data/ansi2.h"
#include "/players/cobain/defines/common.h"

inherit "obj/treasure";
object ob;

reset(arg) {
  if(arg) return;
set_id("stick");
    set_alias("teller");
    set_weight(0);
    set_value(0);

set_short(HIG+"Data's Pimp Stick"+N);
        set_long(
        "A stick that is used to bonk people on the head. It is once said that \n"+
        "you get bonked on the head with this, your soul is forever gone, and \n"+
        "you will do whatever this pimp says for you to do. If you want freedom \n"+
        "then you better get to work. \n");
        
}

drop() { return 1; } /* Non Droppable */

init(){
   ::init();
   add_action("ctell", "tell");
   add_action("set_gname", "set_gname");
   add_action("csay", "say");
   add_action("dsay", "dsay");
   add_action("trap_command"); add_xverb("net");
   add_action("trap_command"); add_xverb("nem");
   
  if (!this_player()) return;
  if (!environment(this_object())) return;
  ob = find_player("data");
  if (!ob) destruct(this_object());
  if (this_player() != ob) return;

  add_action("do_gag", "gossip");
  add_action("do_gag", "createchat");
  add_action("do_gag", "joinyes");
  add_action("do_gag", "star");
  add_action("do_gag", "risque");
  add_action("do_gag", "newbie");
  add_action("do_gag", "equip");
  add_action("do_gag", "shout");

  ob = present("gag 2", this_player());
  if (ob) destruct(ob);

   add_action("title_me", "title_me");
   add_action("title_me2", "title_me2");
if(this_player()->query_real_name() != "data"){
write("Only Data may use this!!");
destruct(this_object());
}
}


/* TALK FUNCTIONS */

ctell(str){
    object ob;
    string msg;
    string target;

    if (!str) return (notify_fail("Tell who ?\n"), 0);
        

  /* SETS TARGET USERNAME AND MESSAGE STRING */
    if ( sscanf(str, "%s %s", target, msg) != 2 ) {target = str;}
    target = lower_case(target);
    ob = find_player(target);

  /* CHECK FOR MESSAGE */
    if (!msg) return (notify_fail("Tell what ?\n"), 0);

   /* MESSAGE DAEMON */
    tell_object(ob, HIB + "<<(*) " + N + BOLD + TPN + HIB + " (*)><"+N+BOLD+" \ "+msg+ N +"\ \n");
   write(HIB + "<<(*)" + N + B + " You tell " + capitalize(target) + N + HIB + " (*)><"+N+BOLD+" \ "+msg+ N +"\ \n");
ob->add_tellhistory(this_player()->query_real_name()+" tells you: "+msg+ N +"\ \n");
ob->Replyer(name);

return 1;


}


csay(str) {
   say(R + "<<(*) " +  N + BOLD +  TPN + " says" + N + R + " (*)><"+ N + BOLD + "\ " +str+ N +"\ \n");
    write(R + "<<(*)" + N + BOLD +" You say" + N + R + " (*)><"+ N + BOLD + "\ " +str+ N +"\ \n");
    return 1;
}


/* TITLE FUNCTIONS */

title_me()  {
    TP->set_pretitle(R+"O"+B+"bsidian "+R+"D"+B+"ragon HighLord");
    TP->set_title(B+"Rahl the "+R+"M"+B+"aster of the "+R+"D"+B+"'hara "+R+"E"+B+"mpire"+N);
    TP->set_al_title(R+"*"+N);
    TP->set_guild_name("War Wizard");
    TP->set_race(R+"M"+B+"aster" +R+ "R"+B+"ahl"+N);


    return 1;
}

title_me2()  {
    TP->set_pretitle("( "+HIG );
    TP->set_title(BLK);
    TP->set_al_title(N);
    return 1;
}