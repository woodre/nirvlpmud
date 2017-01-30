string messages, new_hd, new_body;
int num_messages;
object who;

query_auto_load() { return "/players/mizan/etheriel/items/guide2.c:"; }

id(str) { return str == "guide" || str == "Mizan-Guide" || str == "computer"; }

short() { return ("A copy of the HitchHiker's Guide to Galaxy"); }

get() { return 1; }
drop() { return 1; }
query_value() { return 0; }

long() {
 write("This is small, hand-held computer in a sturdy plastic case.\n");
 write("There is a sticker on the back that reads: Don't Panic!\n");
 write("Could this be a copy of the HitchHiker's Guide to the Galaxy?\n");
 write("For Zark's sake... it is!\n\n");
 write("Usage : 'edit <headline>' to make an entry into the guide.\n");
 write("        'view <message number>' to read an entry.\n");
 write("        'files' to see a listing of all the files.\n");
      write("        'delete <num>' to delete a note.\n");
 write("	'# <message>' to relay a message to anyone with a guide.\n");
 write("        '## <emote>' to relay an emote to anyone with a guide.\n");
 write("	'gw' to see who has a copy of the guide.\n");
 write("        'download' to update your copy of the guide.\n");
 write("        'chuck guide' to drop the guide.\n");
 write("        'enrich <playername>' to give someone a copy of the guide.\n");
 write("        'smash guide' to get rid of the guide.\n\n");
 write("Mail Mizan if you encounter any bugs, have any suggestions,\n"+
	"fan mail, or if you just feel like chewing him off *grin* \n");
}

display_files() {
  call_other(MASTER_R, "display_files");
return 1;
}

init() {
    add_action("new", "edit");
    add_action("read", "view");
    add_action("display_files", "files");
  if(this_player()->query_level() > 20) {
    add_action("remove", "delete");
  }
    add_action("guide_tell", "#");
    add_action("guide_who", "gw");
    add_action("guide_emote", "##");
    add_action("enrich", "enrich");
    add_action("drop_the_guide", "chuck");
    add_action("destroy_guide", "smash");
    add_action("update_guide", "download");
}

reset(arg) {
}

headers() {
  call_other(MASTER_R, "headers");
  return 1;
}

new(hd) {
    if (!hd)
        return 0;
    if (who && environment(who) == environment(this_object())) {
        write(call_other(who, "query_name") + " is busy typing.\n");
        return 1;
    }
    if (num_messages == 100) {
        write("Disk Full. You have to delete an old file first.\n");
        return 1;
    }
    if (strlen(hd) > 50) {
        write("Too long header to fit the directory.\n");
        return 1;
    }
    new_hd = hd;
    input_to("get_body");
    write("Give message, and terminate with '**'.\n");
    write("]");
    new_body = "";
    return 1;
}

get_body(str) {
    if (str == "**") {
        new_hd = new_hd + "(" + call_other(this_player(), "query_real_name") +
  ", " + extract(ctime(time()), 4, 9) +
  ", " + this_player()->query_guild_name() +
  ", " + this_player()->query_level() + ")";
        messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
        num_messages += 1;
        new_body = 0;
        new_hd = 0;
        save_object("players/mizan/etheriel/items/GUIDE_TXT");
        write("Ok.\n");
        who = 0;
        return;
    }
    new_body = new_body + str + "\n";
    write("]");
    input_to("get_body");
}

read(str) {
    string hd, body, rest;
    int i, tmp;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
                     sscanf(str, "note %d", i) != 1))
        return 0;
    if (i > num_messages) {
        write("Not that number of files.\n");
        return 1;
    }
    rest = messages;
    while(rest != 0 && rest != "") {
        i -= 1;
        tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
        if (tmp != 2 && tmp != 3) {
            write("Corrupt.\n");
            return;
        }
        if (i == 0) {
            say(call_other(this_player(), "query_name") +
                  " views a file titled '" + hd + "'.\n");
            write("The file is titled '" + hd + "':\n\n");
            write(body);
            return 1;
        }
    }
    write("[] CRC Error.\n");
}

remove(str) {
    string hd, body, rest;
    int i, tmp;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
                     sscanf(str, "note %d", i) != 1))
        return 0;
    if (i > num_messages) {
        write("Not that number of files.\n");
        return 1;
    }
    rest = messages;
    messages = "";
    while(rest != 0 && rest != "") {
        i -= 1;
        tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
        if (tmp != 2 && tmp != 3) {
            write("Corrupt.\n");
            return;
        }
        if (i == 0) {
            say(call_other(this_player(), "query_name") +
                  " deleted a file titled '" + hd + "'.\n");
            write("Ok.\n");
            messages = messages + rest;
            num_messages -= 1;
            save_object("players/mizan/etheriel/items/GUIDE_TXT");
            return 1;
        }
        messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("[] CRC Error.\n");
}

guide_tell(str) {
  object ob;
  int v;
    if(!str) {
      write("What do you want to say to your froody brothers and sisters?\n");
      return 1; }
    ob=users();
      for(v=0; v<sizeof(ob); v++) {
	if(present("Mizan-Guide", ob[v])) {
	  tell_object(ob[v], ">> "+(this_player()->query_name())+" <<: "+str+"\n");
	  }
	}
      return 1;
}

guide_emote(str) {
  object ob;
  int v;
    if(!str) {
      write("What do you want to emote to your froody brothers and sisters?\n");
      return 1; }
    ob=users();
      for(v=0; v<sizeof(ob); v++) {
	if(present("Mizan-Guide", ob[v])) {
	  tell_object(ob[v], ">> "+(this_player()->query_name())+" "+str+"\n");
	  }
	}
      return 1;
}

guide_who() {
  object ob;
  int v;
  string name;
write("    Name\tSex\tGuild\t\tCurrent Room\n\n");
  ob=users();
    for(v=0; v<sizeof(ob); v++) {
      if(present("Mizan-Guide", ob[v])) {
	name=ob[v]->query_name();
	  if(strlen(name) <8) name=name+"\t";
  if(!ob[v]->query_invis()) {
	write(name+"\t"+(ob[v]->query_gender())+"\t"+(ob[v]->query_guild_name())+"\t"+
    ((environment(ob[v]))->short())+"\n");
  }
	  }
	}
     return 1;
}

enrich(arg) {
  object ob,guide,box;
    if(!arg) {
      write("You must specify a player.\n");
      return 1; }
  ob=find_player(arg);
    if(!ob) {
      write("That player is not logged in.\n");
      return 1; }
    if(ob->query_level() > 20) {
      write("Wizards can clone guides for themselves.\n");
      return 1; }
    if(present("Mizan-Guide", ob)) {
      write((ob->query_name())+" already has a copy of the Guide.\n");
      return 1; }
    tell_object(ob, "A UPS man arrives and says: A package for you from "+(this_player()->query_name())+".\n"+
	"He hands you a box and drives away.\n");
    write("You enrich the life and soul of "+(ob->query_name())+" with a copy of the Guide.\n");
/*
    box=clone_object("/players/mizan/closed/package.c");
    guide=clone_object("/players/mizan/closed/spuck/guide2.c");
    move_object(guide, box);
*/
  box=clone_object("players/mizan/etheriel/items/guide2.c");
    move_object(box, ob);
    return 1;
}

update_guide() {
  object ob;
  ob=clone_object("players/mizan/etheriel/items/guide2.c");
move_object(ob, this_player());
  write("Your guide has been reset.\n");
  destruct(this_object());
return 1;
}

drop_the_guide() {
  write("You drop the guide.\n");
  say((this_player()->query_name())+" drops a HitchHiker's Guide to the Galaxy.\n");
  move_object(this_object(), environment(this_player()));
  this_player()->add_weight(-1);
  return 1;
}

destroy_guide() {
  write("You stomp on your Guide and it gets smashed into tiny little bits...\n");
  say((this_player()->query_name())+" smashes the hell out of a HitchHiker's Guide to the Galaxy.\n");
  destruct(this_object());
  return 1;
}
