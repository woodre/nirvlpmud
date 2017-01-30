inherit "room/room";

reset(arg) {
	if(!arg) {
	  set_light(1);
     short_desc = "Pathfinders Workroom";
     long_desc = "This is Pathfinder's workroom.  You notice alot \n"+
           "of C manuals laying over the place.\n";
           "force <who> <what>.\n";
	  dest_dir = ( {
		"room/shop",         "shop",
		"room/church",       "church",
		"room/post",         "post",
           "players/blue/closed/shadow/rooms/meeting", "shadow",
		} );
	  items = ({
		"workroom","It's not much to look at right now...",
		} );
	}
}

init() {
  ::init();
    add_action("wizzes",            "wizzes");
    add_action("trans",             "trans");
    add_action("Shout_invis",       "Shout");
    add_action("force",             "force");
}

wizzes() {
  object list;
  int i, level, invis;
  string name, ed, tab;
  list = users();
  write("Name"+"\t\t"+"Level"+"\t"+"Invis"+"\t"+"Edit\n");
  write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  for(i = 0; i <sizeof(list); i++)
	{
	  name = capitalize(call_other(list[i],"query_real_name"));
	  level = list[i]->query_level();
	  invis = list[i]->query_invis();
	  if(invis>999){invis=999;
		}
	  ed = "  ";
	  if(in_editor(list[i]))
	    {
	       ed = "Ed";
	    }
	  tab = "\t";
	  if(strlen(name) < 8){tab = "\t\t";
			}
	  if(level > 19)
	    {
		write(name+tab+level+"\t"+invis+"\t"+ed+"\n");
	    }
	}
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

Shout_invis(str) {
	if(!str) {
	  write("Usage: Shout <str>\n");
	  return 1;
	}
     shout("Someone shouts: "+str+".\n");
     write("You just shouted: "+str+".\n");
     return 1;
}
