/*  *** Inheritable guildob *** */

#pragma strong_types
#pragma save_types

#define ON_SCREEN 20    /* Used for more function */

string guild_name;      /* Name of the guild */
string guild_id;        /* Id for the guild object (this_object) */
string guild_alt_id;    /* Alternate id for the guild object */
string short_desc;      /* Short description for guild object */
string long_desc;       /* Long description for guild object */
string bin_path;        /* Path for guild bin files */
string admin_path;      /* Path for guild admin files */
string drop_message;    /* Message received on drop() */
string guild_file;      /* Filename for guild object */
string info_path;       /* Path for guild info (help) files */
string more_file;       /* Stores filename for info files */
int more_index;         /* Used for reading info files */
mapping commands;       /* Mapping of all the guild commands */
mapping guild_info;     /* Mapping to store guild variables */

/* Set basic parameters */
void set_guild_name(string arg){ guild_name = arg; }
void set_guild_id(string arg){ guild_id = arg; }
void set_guild_alt_id(string arg){ guild_alt_id = arg; }
void set_guild_file(string arg){ guild_file = arg; }

/* Set decriptions - leave blank for invis object! */
void set_short(string arg){ short_desc = arg; }
string short(){ return short_desc; }
void set_long(string arg){ long_desc = arg; }
string long(){
    if((!long_desc) && (short_desc))
        write(short_desc+".\n");
    else
        write(long_desc);
}

string *get_coms(string p){
    string *tmp;
    tmp = get_dir(p+"/*");
    if(!tmp) return ({});
    return map_array(tmp-({".",".."}),
      lambda(({'x}), ({#'[, ({#'explode, 'x, ".c"}), 0})));
}

void set_bin_path(string arg){ bin_path = arg; }
void set_admin_path(string arg){ admin_path = arg; }

void guild_commands(){
    int i, t, z;
    string *com;
    commands = ([]);
    com = get_coms(bin_path);
    for(t=0; t<sizeof(com); t++){
	commands[com[t]]=bin_path+"/"+com[t];
	add_action("guild_command", com[t]);
    }
    if(environment(this_object())->query_level() > 20){
	com = get_coms(admin_path);
	for(t=0; t<sizeof(com); t++){
	    commands[com[t]]=admin_path+"/"+com[t];
	    add_action("guild_command", com[t]);
	}
    }
}

int guild_command(string str){
    if(!commands[query_verb()]) return 0;
    return call_other(commands[query_verb()], query_verb(), str);
}

/* *** Define the info command *** */
/* Put files in format 'subject.info' - set dir with info_path */

void set_info_path(string arg){ info_path = arg; }

int info(string arg){
    string path;            /* path for files */
    string *list;           /* list of file */
    int i, j;               /* indicies for arrays */
    if(!arg){
	path = info_path;
	list = get_dir(path);
        write("Available info files:\n\n");
	j=0;
	for (i=0; i<sizeof(list); i++)
	    if(sscanf(list[i], "%s.info", list[i])){
		if(j<4)
                    printf("%-18s", list[i]);
		else {
                    printf("\n%-18s", list[i]);
		    j=0;
		}
		j++;
	    }
        write("\n");
	return 1;
    }
    sscanf(arg, "%s ", arg);
    more_file = info_path+arg+".info";
    if(file_size(more_file) == -1){
        write("Sorry, there is nothing on that subject.\n");
	return 1;
    }
    if(cat(more_file, 0, ON_SCREEN) < ON_SCREEN) return 1;
    more_index = ON_SCREEN +1;
    write("< More? 'q' to quit >  ");
    input_to("even_more");
    return 1;
}

int even_more(string arg){
    if(arg == "q") return 1;
    if(cat(more_file, more_index, ON_SCREEN) < ON_SCREEN) return 1;
    write("< More? 'q' to quit >  ");
    more_index += ON_SCREEN;
    input_to("even_more");
    return 1;
}

/* Redirect help since help levels and help spells no longer apply (in a guild!) */
int help(string arg){
    if(arg=="levels" || arg=="spells"){
	return info(arg);
    }
    return 0;
}

/* *** fixme() function *** */

int fixme(){
    string file, extra;
    object new;
    file = file_name(this_object());
    sscanf(file,"%s#%s", file, extra);
    new = clone_object(file);
    write("Updating your powers......\n");
    move_object(new, this_player());
    new->guild_commands();
    write("Done.\n");
    destruct(this_object());
    return 1;
}
void set_guild_info(string what, mixed info){
    if(!guild_info) guild_info=([]);
    guild_info[what]=info;
}

mixed query_guild_info(string what){
    if(!guild_info) guild_info=([]);
    return guild_info[what];
}

void remove_guild_info(string what){
    if(!guild_info) guild_info=([]);
    guild_info=m_delete(guild_info, what);
}

mixed query_guild_commands(){ return commands; }

void reset(status arg){}

void init(){
    object PLAYER;
    if(environment(this_object())) PLAYER = environment(this_object());
    else return;
    if(PLAYER->query_interactive() && PLAYER->query_guild_name() != guild_name){
        write("You cannot use the powers of the "+capitalize(guild_name)+"!\n");
	return;
    }
    PLAYER->set_guild_file(guild_file);
    add_action("info", "info");
    add_action("help", "help");
    add_action("fixme", "fixme");
    guild_commands();
}

int id(string str){
    return str == guild_id || str == guild_alt_id || str == "object_guild" ||
    str == "GI";
}

int drop(){ if(drop_message) print("%s", drop_message); return 1; }
int get(){ return 1; }
