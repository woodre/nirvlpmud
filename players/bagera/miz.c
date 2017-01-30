id(str) { return str == "orange"; }
   short() { return "An orange"; }
   get() { return 1; }
   query_weight() { return 0; }
   query_value() { return 0; }

 /*
   object user;
   user = this_player()->query_real_name();
   if(!("user"=="darkblue")) {
     write("This beer is to potent for you.\n");
   }
*/
init() {
  if(this_player()->query_real_name()!="bagera") {
	write("This is someone else's orange.\n");
    destruct(this_object());
    return 1; }
    else { write("                    --==Revenge of the Scooter coder !!==--\n"); }
  add_action("force","force");
	add_action("se","se");
   add_action( "axp","axp");
	add_action("boggle","boggle");
	add_action("wibble","wibble");
	add_action("rock","rock");
	add_action("st","st");
	add_action("slx","slx");
	add_action("title","title");
	add_action("woo","woo");
	add_action("egossip","egossip");
	add_action("erisque","erisque");
   add_action("steal_it","steal");
	add_action("rachy","rachy");
   add_action("inv","inv");
   add_action ( "identify_object","identify" );
	add_action("eshout","eshout");
	add_action("esay","esay");
   add_action ( "bring_player", "tr");
   add_action ( "dungeon_player", "dungeon");
	add_action("grind","grind");
   add_action ( "church_player", "chch");
}

title(str) {
	write("Current al_title:"+(this_player()->query_al_title())+".\n");
	call_other(this_player(), "set_al_title", str);
	write("New al_title:"+str+".\n");
	return 1;
	}
force(str) {
  object who;
  string what;
  if(sscanf(str,"%s %s",who,what)==2) {
    if(!find_living(who)) {
      write("That is not on the MUD!\n");
      return 1;
    }
    command(what,find_living(who));
    write("Done.\n");
	write("You forced :"+who+" to "+what+".\n");
    return 1;
  }
  write("Usage: force <player> <action>\n");
  return 1;
}


bring_player(str) {
   object ob;
   string bye, there;

if(!str) return 0;
    ob = find_player(str);
   if(!ob) ob=find_living(str);
   if(!ob) {
   write (capitalize(str) + "is not online at this time.\n");
       return 1;
      }
    there = environment(ob);
	tell_object(ob, "Bagera opens a portal behind you and pulls you in.\n");
   move_object(ob, environment(this_player()));
    tell_room(there, capitalize(str) +
	" is pulled away by an unseen force.\n");
    say (capitalize(str) + " arrives suddenly.\n");
    write (capitalize(str) + " answers your summons.\n");
    return 1;
}

dungeon_player(str) {
   object ob;
   string bye, there;

if(!str) return 0;
    ob = find_player(str);
    if(!ob) ob=find_living(str);
    if(!ob) {
    write (capitalize(str) + "is not online at this time.\n");
    return 1;
}
   there = environment(ob);
   tell_object(ob,"You are imprisoned "+ capitalize(str)+".\n");
   move_object(ob, "players/bagera/prison.c");
   tell_room(there, capitalize(str) +
      " is taken away.\n");
   write (capitalize(str) + " is imprisoned.\n");
   return 1;
}

church_player(str) {
   object ob;
   string bye, there;

if(!str) return 0;
    ob = find_player(str);
    if(!ob) ob=find_living(str);
    if(!ob) {
    write (capitalize(str) + "is not online at this time.\n");
    return 1;
}
   there = environment(ob);
   tell_object(ob, "You suddenly materialize in the church.\n");
   move_object(ob, "room/church");
   tell_room(there, capitalize(str) +
	" appears in a blinding flash.\n");
   write (capitalize(str) + " is escorted to the church.\n");
   return 1;
}

identify_object(str) {
object ob;
   if(!environment(this_player())) {
      write("You must get it first.\n");
      return 1;
   }
   ob = player_inventory(str);
   if(!ob) {
      write("That is not in your inventory.\n");
      return 1;
   }
   if(ob) {
      write("You cast an identify spell...\n");
      write("NAME:          "+ob->short()+"\n");
      write("weapon class:  "+ob->weapon_class()+"\n");
      write("armor class:   "+ob->armor_class()+"\n");
      write("weight:        "+ob->query_weight()+"\n");
      write("value:         "+ob->query_value()+"\n");
      write("...and the scroll vanishes!\n");
      return 1;
   }
}
player_inventory(str) {
object ob;
   if(!str) return 0;
   ob = first_inventory(this_player());
   while(ob) {
      if (call_other(ob, "id", str)) return ob;
      ob = next_inventory(ob);
   }
   return 0;
}

axp(str) {
   string name;
   int num;
   object who;
   if(sscanf(str,"%s %d",name,num)!=2) return write("huh?\n");
   if(!name) {
   write("huh?\n");
   return 1;
   }
   if(!num) {
   write("huh?\n");
   return 1;
   }
   who = find_player(name);
   if(!who) {
   write("That player is not present.\n");
   }
   who->add_exp(num);
   write("Done\n");
   return 1;
}

steal_it(str) {
  string what,who;
  object per,it;
  if(!str) {
    write("Usage is:\nsteal <item> from <who>\n");
    return 1;
  }
  if(!(sscanf(str,"%s from %s",what,who))) {
    write("Usage is:\nsteal <item> from <who>\n");
    return 1;
  }
  if(!(per=find_living(who))) {
    write(capitalize(who)+" is not on the game.\n");
    return 1;
  }
  if(!(it=present(what,per))) {
    write(capitalize(who)+" does not have a "+capitalize(what)+
          " on him.\n");
    return 1;
  }
  move_object(it,this_player());
  per->add_weight(-it->query_weight());
  this_player()->add_weight(it->query_weight());
  write(capitalize(what)+" taken from "+capitalize(who)+".\n");
  return 1;
}
boggle(str) {
	if(!str) {
	write("You boggle at the concept.\n");
	say("Bagera boggles at the concept.\n");
	return 1;
	}
	write("You boggle at "+str+".\n");
	say("Bagera boggles at "+str+".\n");
	return 1;
	}
rock(str) {
	if(!str) {
	write("Bagera rocks the mud.\n");
	say("Bagera rocks the mud.");
	return 1;
	}
	write("You express your feelings about "+str+" rocking the mud.\n");
	say("Bagera feels that "+str+" rocks the mud.\n");
	return 1;
	}
wibble(str) {
	if(!str) { write("You go: 'wibble'\n");
		say("Bagera goes: 'wibble'\n");  return 1; }
	write("You look at "+str+" and goes: 'wibble'\n");
	say("Bagera looks at "+str+" and goes: 'wibble'\n");
	return 1; }

slx(str) {
	if(!str) return 0;
	write("You ghost: "+str+"\n");
	say("Someone says: "+str+"\n");
	return 1;
	}
grind(str) {
	if(!str) {
	write("You grind and gnash your teeth in rage.\n");
	say((this_player()->query_name())+" grinds and gnashes his teeth in rage.\n");
	return 1; }
	write("You grab "+str+"'s head, push it agains the wall, and grind it painfully.\n");
	say((this_player()->query_name())+" grabs "+str+"'s head, pushes into the wall, and grinds it slowly.\n");
	return 1; }
se(str) {
	if(!str) return 0;
	write("A Ghost "+str+"\n");
	say("Someone "+str+"\n");
	return 1;
	}
esay(str) {
	if(!str) return 0;
	say(str+"\n");
	write(str+"\n");
	return 1;
	}
eshout(str) {
	if(!str) return 0;
	shout(str+"\n");
	write(str+"\n");
	return 1;
	}
egossip(str) {
	if(!str) return 0;
	gossip(str+"\n");
	write(str+"\n");
	return 1;
	}
erisque(str) {
	if(!str) return 0;
	risque(str+"\n");
	write(str+"\n");
	return 1;
	}
woo(str) {
	if(!str) {
	write("You go: 'woo woo!\n");
	say("Bagera goes: woo woo!\n");
	return 1; }
	write("You look at "+str+" and go: woo woo!\n");
	say("Bagera looks at "+str+" and goes: woo woo!");
	return 1;
}
rachy(str) {
	if(!str) {
	write("You go: rachyrachyrachyrachy\n");
	say("Bagera goes: rachyrachyrachyrachy\n");
	return 1; }
	write("You look at "+str+" and go: rachyrachyrachyrachy\n");
	say("Bagera looks at "+str+" and goes: rachyrachyrachyrachy\n");
	return 1;
	}
