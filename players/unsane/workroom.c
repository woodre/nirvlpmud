inherit "room/room";

reset(arg) {
	if(!arg) {
	  set_light(1);
          short_desc = "The Ninth Circle of Hell";
               long_desc =
"    You cannot hear your own thoughts in this room.  You think that this\n"+
"is mainly due to the fact that a multitude of souls are crying out in anguish.\n"+
"From where you stand, you can see another 8 cirlces rising through the chaos\n"+
"above you.  Any one of them looks thousands of times better than where you\n"+
"are.  The heat here is exasperating, and you feel your lungs burning inside\n"+
"of your chest.  You begin to weap for all the crimes you have committed.\n"+
"As you begin to accept your fate here, you notice a throne that wasn't here\n"+
"before.  It is made of the capricaces of many living, writhing insects.  You\n"+
"feel a little quesy looking directly at it, or at the man atop of it.......\n"+
"The man cries out:  I am Unsane the Ruler of the Ninth cirlcle of Hell!\n";
	  dest_dir = ( {
		"room/shop",         "shop",
		"room/church",       "church",
	        "room/adv_guild",    "advguild",
		"room/post",         "post",
		} );
	  items = ({
                "throne","The throne squirms as you look at it.",
		} );
	}
}

init() {
  ::init();
add_action("wizzes","wizzes");
    add_action("Shout_invis",       "Shout");
}

is_wiz(obj) {return obj->query_level()>19; }
wizzes(){
object us;
int i,l,x;
string name,ed;
us = filter_array(users(),"is_wiz",this_object());
write("\nName\t\tLevel\tInvis\tEditing\n");
write("----------------------------------------------\n");
for(x=0;x<sizeof(us);x++){
name=capitalize(us[x]->query_real_name());
if(strlen(name)<8)name += "\t";
name += "\t";
l = us[x]->query_level();
i = us[x]->query_invis();
if(in_editor(us[x])) ed= "   Yes";
else ed  = "   No";
write(name+l+"\t"+i+"\t"+ed+"\n");
}
write("------------------------------------------------\n");
write("Done\n");
return 1;
}



Shout_invis(str) {
	if(!str) {
	  write("Usage: Shout <str>\n");
	  return 1;
	}
     shout("Someone shouts: "+str+".\n");
     write("You just shouted: "+str+".\n");
     return 1;
}
