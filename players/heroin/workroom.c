inherit "room/room";

reset(arg) {
	if(!arg) {
	  set_light(1);
          short_desc = "The Trophy room";
               long_desc =
"You find yourself unable to move. You cant even feel your body.\n"+
"you manage to look around. You find yourself miles above the\n"+
"ground. The reaon you couldnt feel your body is because head is\n"+
"no longer attached to it\n"+
"You feel confused and scared and find your head hanging\n"+
"from the wall\n"+
"you find yourself among many heads, limbs and other various body parts\n"+
"You are a trophy now..BUT why? Who would do this..\n"+
"As you scramble for an answer; you see a foul creature snickering\n"+
"You pray this is only a dream: a cruel joke\n"+
"Who would do such a thing...the creature laughs louder and exclaims\n"+
"WHO you ask vile human..I, Heroin destroyer of man would! \n"+
"Your heart sinks..your soul lost..hell is only a wet-dream\n"+
"You better pray you dont look good in his collection!\n";


	  dest_dir = ( {
        "room/shop",         "shop",
		"room/church",       "church",
"/players/heroin/hunting_grounds/hunt1.c", "hunt",
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
add_action("set_login_location","pstart");
    add_action("trans",             "trans");
add_action("my_clone",      "create");
    add_action("Shout_invis",       "Shout");
add_action("wizzes",     "wizzes");
    add_action("force",             "force");
}

my_clone(str){
move_object(clone_object(str),this_player());
say("Heroin whines and screams and pouts till someone brings him what he wants\n");
write("ok-here crybaby\n");
return 1;
}

trans(str) {
  object ob;
  string bye, there;
    if(!str)
	return 0;
  ob=find_player(str);
  if(!ob) ob=find_living(str);
  if(!ob) {
	write (capitalize(str) + " isn't logged on you dimwit.\n");
	return 1;
        }
  there=environment(ob);
  tell_object(ob,"You have been summoned by a greater force!\n");
  move_object(ob, environment(this_player()));
  write(capitalize(str)+" has arrived from your summoning.\n");
  return 1;
}

force(str) {
  object whoo;
  string who,what;
  if (!str) return;
  if (sscanf(str, "%s %s", who, what) !=2)
    return;
  whoo = find_player(who);
  if (!whoo)
    {
      write("Can't find "+who+"\n");
      return;
    }
  command(what,whoo);
  return 1;
}

set_login_location(str) {
string who, where;
object target;
if(!str) return 0;
if(sscanf(str,"%s %s",who,where) !=2) return 0;
target = find_player(who);
if(!target) {
write("Oh go to hell, "+capitalize(who)+" isnt around!\n");
return 1;
}
if(where == "none") {
target ->set_home(0);
write("home has beeen reset\n");
return 1;
}
if(!find_object(where)) {
write("no such place, dickwad.\n");
return 1;
}
write("The new home is "+where+"\n");
target->set_home(where);
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
