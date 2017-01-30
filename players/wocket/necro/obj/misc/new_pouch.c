#include "/players/daranath/closed/ansi.h"
#define tp this_player()->query_name()

id(str) {
  return str == "pouch" || str == "necro_pouch";
}

reset(arg) { 
  if(arg) return;
}

query_auto_load() {return "/players/daranath/guild/obj/misc/com_pouch.c:"; }
short() {return "Component pouch"; }
long() {
write("Darkened leather stained with many unknown substances makes\n"+
      "up the component pouch that is used primarily to store\n"+
      "spell components. A very useful tool for a mage.\n"+
      ""+HIY+"<"+NORM+"plist"+HIY+">"+NORM+" for a list of commands.\n"); 
}
get() { return 1; }
query_weight() { return 0; }
drop() { return 1; }
query_value() { return 0; }

init() {
add_action("commands","plist");
add_action("pouch_help","phelp");
add_action("contents","contents");
add_action("add_comp","store");
add_action("sub_comp","remove");
}

commands() {
write("The component pouch has the following abilities:\n");
write("\n< contents > gives you a list of the components you have\n");
write("< store > adds a component to the pouch\n");
write("< remove > takes a component from the pouch\n");
write("< plist > this listing\n");
write("< phelp > gives you further information on each command\n\n");
write("The darkness comes from deep within the corpse\n\n");
return 1;
}

pouch_help(str) {
  if(!str) {
write("Which pouch command do you want help with?\n");
return 1; }
  if(str == "contents") {
write("< contents > shows you how many of each and every component that\n"+
      "you have left in your inventory within the pouch. Very\n"+
      "useful for keeping track of your spells.\n");
return 1; }
  if(str == "store") {
write("< store > takes a material component and adds it to your\n"+
     "component pouch. This allows you to keep your inventory free\n"+
      "of the various components. A spell component must be within\n"+
      "the component pouch to be used for a spell.\n");
return 1; }
  if(str == "remove") {
write("< remove > takes a component from your component pouch and\n"+
      "puts it back within your inventory. The component cannot be\n"+
      "used for a spell until it is placed back within the pouch.\n");
return 1; }
  if(str == "plist") {
write("< plist > shows you the various commands you can do with the\n"+
      "component pouch.\n");
return 1; }
  else {
write("There is no help for that command.\n");
return 1; }
}

contents() {
object ob;
  if(ob = present("necro_ob",this_player())) {
write("\nYour component pouch currently contains:\n"+
      "---------------------------------------------\n"+
      "Parts Blood: "+ob->query_blood()+"\n"+
      "Parts Skin : "+ob->query_skin()+"\n"+
      "Parts Eye  : "+ob->query_eye()+"\n"+
      "Parts Spine: "+ob->query_spine()+"\n"+
      "Parts Heart: "+ob->query_heart()+"\n"+
      "Parts Soul : "+ob->query_soul()+"\n"+
      "---------------------------------------------\n"+
      "The darkness comes from deep within the corpse.\n\n");
say(tp+" searches through "+environment()->query_possessive()+" component pouch for a moment.\n");
this_player()->add_spell_points(-2);
return 1; }
  else {
write("You have no necromantic spell components at all.\n");
destruct(this_object()); return 1; }
}

add_comp(str) {
object ob, comp;
  if(!str) {write("Which component would you like to store within the pouch?\n");
return 1; }
  if(ob = present("necro_ob",this_player())) {
  if(str == "all") {
}
    if(str != "blood" && str != "skin" && str != "eye" && str != "spine" &&
       str != "soul" && str != "heart") {
    	 write("That is not a valid component, there is not room for it.\n");
    return 1; }
	if(comp = present("necro_"+str,this_player())) {
	  write("You store the "+str+" within your component pouch.\n");
	  call_other(ob,"add_"+str,1);
	  ob->save_me();
	  destruct(comp);
	  return 1;
	} else {
	  write("You have no harvested "+str+" available for storage.\n");
	return 1; }
  } else {
write("You cannot add a component to the pouch.\n");
destruct(this_object());
return 1; }
}

sub_comp(str) {
object ob;
  if(!str) {write("Which component would you like to remove from the pouch?\n");
return 1; }
  if(ob = present("necro_ob",this_player())) {
    if(str != "blood" && str != "skin" && str != "eye" && str != "spine" &&
	       str != "soul" && str != "heart") {
	    	 write("There is none of that item within the component pouch.\n");
    return 1; }
	if(call_other(ob,"query_"+str) > 0) {
	  write("You remove some "+str+" from the component pouch.\n");
      say(tp +" removes some harvested "+str+" from the component pouch.\n");
	  call_other(ob,"add_"+str,-1);
	  ob->save_me();
move_object(clone_object("/players/daranath/guild/obj/misc/"+str+".c"),this_player());
     return 1;
	} else {
	write("You have no harvested "+str+" within the component pouch.\n");
	return 1; }
  } else {
write("You cannot remove any components from the pouch.\n");
destruct(this_object()); return 1; }
}

