short() {
        return "A kooky yo-yo";
}
long() {
        if(this_player()->query_level() < 21) {
                write("You don't deserve this item!\n");
                destruct(this_object());
                return 1;                
        } else {
                write("A kooky yo-yo. It has a long string, and looks like it\n");
                write("is full of tricks. Type 'tricks' to see what it can do.\n");
                return 1;
        }
}
id(str) {
        return str == "yoyo" || str == "kooky yoyo" || str == "yo-yo";
}
get() {
        return 1;
}
drop() {
        return 0;
}
init() {
        if(this_player()->query_level() > 20) {
	  add_action("mirror", "mirror");
	  add_action("obstat", "obstat");
		add_action("tel", "tel");
                add_action("bring", "bring");
                add_action("reloc", "reloc");
                add_action("force", "force");
                add_action("pecho", "pecho");
                add_action("tricks", "tricks");
        }
}
tel(st) {
        string who;
        string name;
        string what;
        name = this_player()->query_name();
        if(sscanf(st, "%s %s", who, what) == 2) {
                if(in_editor(find_player(who))) {
                        write("That player is editing.\n");
                        return 1;
                } else {
                     tell_object(find_player(who), name+" tells");
                     tell_object(find_player(who), "you: " + what);
                     tell_object(find_player(who), "\n");
                     return 1;
                }
        } else {
                write("Too few arguments to tel.\n");
                return 1;
        }
}
mirror(obj) {
	int junk;
        object ob, new;
        string file;
        ob = present(obj, this_player());
        if(!ob) ob = present(obj, environment(this_player()));
        if(!ob) {
                write("That is not here.\n");
                return 1;
        }
        file = file_name(ob);
	if(sscanf(file, "%s#%d", file, junk) == 2) { 
        new = clone_object(file);
        } else { write("This is fuckoed...\n");  return 1; }
        if(present(obj, this_player())) {
                move_object(new, this_player());
        } else {
                move_object(new, environment(this_player()));
        }
        write("Object mirrored.\n");
        say(this_player()->query_name() + " mirrors an object.\n");               
        return 1;
}
 
obstat(stat_obj) {
        string file, creator, empty;
	int size, num;
        object ob;
        ob = present(stat_obj, this_player());
        if(!ob) ob = present(stat_obj, environment(this_player()));
        if(!ob) {
                write("Object not here.\n");
                return 1;
        }
        file = file_name(ob);
        size = file_size(file);
        write("Report on "+stat_obj+":\n");
        write("Filename: "+file+"\n");
        write("Filesize: "+size+"\n");
        if(sscanf(file, "/players/%s/%s#%d", creator, empty, num) == 3) {
                write("Creator:  "+creator+"\n");
                return 1;
        } else {
                if(sscanf(file, "/%s/%s#%d", creator, empty, num) == 2) {
                        write("Creator:  "+creator+" (root)\n");
                        return 1;
                } else {
                        write("Creator unknown.\n");
                        return 1;
                }
        }
        if(sscanf(file, "/players/%s/%s", creator, empty) == 2) {
                write("Creator:  "+creator+"\n");
                return 1;
        } else {
                if(sscanf(file, "/%s/%s", creator, empty) == 2) {
                        write("Creator:  "+creator+" (root)\n");
                        return 1;
                } else {
                        write("Creator unknown.\n");
                        return 1;
                }
        }
}
tricks() {
        write("This yo-yo is equiped with the following:\n");
        write("bring <player>   reloc <player> <newroom>\n");
        write("force <player> <action>  pecho <env> <str>\n");
        write("pecho <env> needs a specific word, i.e.: here,\n");
        write("playername, or all.\n");
        return 1;
}
pecho(st) {
        string env;
        string blah;
        if(sscanf(st, "%s %s", env, blah) == 2) {
                if(env != "here" && env != "all") {
                        if(in_editor(find_player(env))) {
                             write("That player is editing.\n");
                             return 1;
                        } else {
                             tell_object(find_living(env), blah + "\n");
                             write("Done.\n");
                             return 1;
                        }                        
                        if(!find_player(env)) {
                                write("Player does not exist.\n");
                                return 1;
                        }
                }
                if(env == "here") {
                        say(blah + "\n");
                        write("Done.\n");
                        return 1;
                }
                if(env == "all") {
                        shout(blah + "\n");
                        write("Done.\n");
                        return 1;
                }
        } else {
                write("Too few arguments to pecho.\n");
                return 1;
        }
}
force(com) {
        string player;
        string comm;
        if(sscanf(com, "%s %s", player, comm) == 2) {        
                if(!find_player(player)) {
                        write("Player does not exist.\n");
                        return 1;
                }
                command(comm, find_player(player));
                write("Done.\n");
                return 1;
        } else {
                write("Not enough arguments to force.\n");
                return 1;                        
        }
}
                        
reloc(st) {
        string play;
        string first;
        string new;
        if(sscanf(st, "%s %s", play, first) == 2) {
                if(sscanf(first, "castle/%s", new) == 1) {               
                        new = "suddenly#/players/wizardchild/castle/"+new+".c";
                } else {
                        new = "suddenly#"+first+".c";
                }                
                if(find_player(play)) {
                        tell_object(find_player(play), "A small cloud breezes past. When it is gone.\n");
                        tell_object(environment(find_player(play)), "A small cloud breezes past.\n");
                        tell_object(find_player(play), "you find yourself in a new place.\n");
			call_other(find_player(play), "move_player", new);
                        write("Done.\n");
                        return 1;
                } else {
                        write("Player not found on the mud.\n");
                        return 1;
                }
        } else {
                write("Too few arguments to reloc.\n");
                return 1;
        }
}
bring(pl) {
        if(!find_player(pl)) {
                write("No player with that name.\n");
                return 1;
        }
        if(present(find_player(pl), environment(this_player()))) {
                write("Player allready here!!\n");
                return 1;
        }
        tell_object(find_player(pl), "A small cloud breezes past. When it is gone,\n");
        tell_object(environment(find_player(pl)), "A small cloud breezes past.\n");
        tell_object(find_player(pl), "you find yourself in a new place.\n");
        move_object(find_player(pl), environment(this_player()));
        write("Done.\n");
        return 1;
}
