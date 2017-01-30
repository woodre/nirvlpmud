/* 
 *   This tool was made to restore wedding rings through jailings,     
 *     mistake desting, etc. I would like to thank those who helped.
 *
 *   Boltar......gave the code to start on this tool.
 *   
 *   Data........person who came up with the idea and put things together.
 *   
 *   Fred........Tester and debugger. 
 */


inherit "obj/treasure";

reset(arg) {
  if(arg) return;
    set_id("ring_fixer");
    set_alias("fixer");
    set_weight(0);
    set_value(0);

 	set_short("Fixer");
	set_long(
	" This is a Wedding Ring Restorer, incase someone loses a wedding ring\n"+
	" for some reason, like accidental desting, jailing, etc. \n"+
	" NOTE: Wocket and Bastion rings you need to specify a spouse, therefore\n"+
    " ask what their spouse is and use your best judgement so you dont give\n"+	
    " them a wedding ring to someone who isnt their spouse. Make sure to ask\n"+
    " what ring they had as well. Dreamspeakr's ring restores spouse on its own.\n"+
    " \n"+
    " \n"+
    " \n"+
    " Dreamspeakr's ring.....dreamspeakr_ring (player)\n"+
    " \n"+
    " Wocket's ring...............wocket_ring (player)(spouse)\n"+
    " \n"+
    " Bastion's ring.............bastion_ring (player)(spouse)\n");
	
}

drop() { return 1; } /* Non Droppable */

init(){
   ::init();
   add_action("dreamspeakr_ring", "dreamspeakr_ring");
   add_action("wocket_ring", "wocket_ring");
   add_action("bastion_ring", "bastion_ring");
   add_action("afk_str", "afk");

}


wocket_ring(str){
object who, barf;
string name1, name2;
  if(!str) return;
  if(sscanf(str, "%s %s", name1, name2) != 2){ write("Please try again.\n"); return 1; }
    who = find_player(name1);
  if(!who) { write("Target not in play.\n"); return 1; }
  barf = clone_object("players/wocket/wedding/ring");
  move_object(barf, who);
  barf->set_spouse(name2);
  tell_object(who, "A soft wind blows and something "+
                   "is dropped into your inventory\n"+
                   "     **   From: "+capitalize(this_player()->query_name())+
                   "    **\n");
  write("You have fixed "+name1+"'s ring.\n");
return 1; }

dreamspeakr_ring(str){
object who, barf;
  if(!str) return;
    who = find_player(str);
  if(!who) { write("Target not in play.\n"); return 1; }
  barf = clone_object("players/dreamspeakr/WEDDING/OBJ/wedding_ring");
  move_object(barf, who);
  barf->fix_ring(); 
  tell_object(who, "A soft wind blows and something "+
                  "is dropped into your inventory\n"+
                   "     **   From: "+capitalize(this_player()->query_name())+
                   "    **\n");
  write("You have fixed "+str+"'s ring.\n");
return 1; }


bastion_ring(str){
object who, barf;
string name1, name2;
  if(!str) return;
  if(sscanf(str, "%s %s", name1, name2) !=2){ write("Please try again.\n"); return 1; }
    who = find_player(name1);
  if(!who){ write("Target not in play.\n"); return 1; }
  barf = clone_object("players/bastion/closed/ring");
  move_object(barf, who);
  barf->set_spouse(name2); barf->set_owner(name1);
 
  tell_object(who, "A soft wind blows and something "+
                   "is dropped into your inventory\n"+
                   "     **   From: "+capitalize(this_player()->query_name())+
                   "    **\n");
  write("You have fixed "+name1+"'s ring.\n");
return 1; }
