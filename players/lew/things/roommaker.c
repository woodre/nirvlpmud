string short_string;
string long_text;
string old_long_text;
string room_light;
string out_file_name;
string out_file_name_c;
int dir_cnt;
object dir_array;
int in_edit;
static make(str)  {
	string temp1, temp2;
	if(!str) {
		write("usage:make filename\n");
		write("creates a file in your home dir that is a room\n");
		write("do \"help roommaker\" to get more info\n");
		return 1;
}
if(sscanf(str, "%s.%s",temp1,temp2)>0){
		write(".and..is not allowed in filenames!\n");
		return 1;
}
in_edit = 0;
	out_file_name ="/players/"+this_player()->query_real_name()+"/"+str;
out_file_name_c = out_file_name + ".c";
if(file_size(out_file_name_c)>=0) {
	write("Warning! Overwrite existing file " +out_file_name_c+"?");
		input_to("file_size_ok");
		return 1;
}
room_light=1;
short_string="A room";
write("Short name of room(" + short_string + "):");
input_to("set_short");
return 1;
}
static file_size_ok(str)
{
	object ob,temp_dir;
	int i;
	if(str) {
		str=lower_case(str);
}
	else {
			str="";
	}
	if(str=="y"||str=="yes") {
			call_other(out_file_name,"???");
			ob=find_object(out_file_name);
			if(ob) {
				if(ob->room_is_modified()) {
				write("This room is modified and may not be changed by the roommaker,\ninformation would be lost.\n");
		return 1;
		}
		short_string=ob->short();
		long_text=ob->query_long();
		temp_dir=ob->query_dest_dir();
		if(!long_text && !temp_dir) {
			write("This room is not roommkaer compatable\n");
			return 1;
			}
		if(!dir_array) {
			dir_cnt=0;
			dir_array=allocate(40);
		} else{
			i=0;
			while(i < sizeof(dir_array)) {
				dir_array[i]=0;
			i += 1;
			}
		}
			i=0;
			while(i < sizeof(temp_dir)) {
			dir_array[i]=temp_dir[i];
			if(dir_array[i]) {
				dir_cnt=i+1;
			}
			i+=1;
		}
		room_light=ob->query_light();
		in_edit=1;
		edit_room();
		return 1;
	} else {
		write("error: couldn't find "+out_file_name+"\n");
		}
		if(!short_string || short_string == "") {
			short_string = "A room";
	}
		write("short name of room("+short_string+"):");
		input_to("set_short");
		return 1;
	} else {
		if(str == "n" || str == "no") {
			write("aborted.\n");
			return 1;
		}
		write("Warning! overwrite existing file "+ out_file_name_c+"(y,n) ? ");
		input_to("file_size_ok");
		return 1;
	}
}
static set_short(str) {
	if(!str || str == "") {
		str=short_string;
	}
	if(str=="~q"){
		write("aborted.\n");
		return 1;
	}
	short_string=str;
	if(in_edit) {
		edit_room("");
		return 1;
	}
	long_text=0;
	write("long desc of " +short_string+": (** to end)\n");
		write("[");
	input_to("set_long");
	return 1;
}
static set_long(str)
{
	int long_ok;
	int i;
	if(!str) {
		str="**";
	}
	if(str=="~q") {
		write("aborted.\n");
		return 1;
	}
	if(in_edit && str=="**") {
		if(!long_text) {
			long_text = old_long_text;
		}
		edit_room("");
		return 1;
	}
	if(!long_text && str=="**"){
		long_text=short_string+".\n";
		long_ok=1;
}
	if(str=="**") {
		long_ok =1;
}
	if(!long_ok) {
		if(long_text) {
		long_text+=(str+"\n");
		} else {
			long_text=(str+"\n");
		}
		write("[");
		input_to("set_long");
		return 1;
	} else {
		if(!dir_array) {
			dir_cnt = 0;
			dir_array = allocate(40);
	} else {
			if(in_edit) {
				i = 0;
				while(i < sizeof(dir_array)) {
					dir_array[i] = 0;
					i+=1;
				}
				dir_cnt=0;
			}
		}
		write("direction "+(1+dir_cnt/2)+" command (end with **): ");
		input_to("set_dir_cmd");
	}
	return 1;
}

static set_dir_cmd(str) {
	if(str && str =="~q") {
		write("aborted.\n");
		return 1;
	}
	if(!str || str == "") {
		write("direction "+(1+dir_cnt/2)+" command (end with **): ");
		input_to("set_dir_cmd");
		return 1;
	} else {
		if(str == "**") {
			if(in_edit) {
				edit_dirs("");
				return 1;
			}
			write("Light level("+room_light+" ): ");
			input_to("set_light_level");
			return 1;
		}
		dir_array[dir_cnt+1]=str;
		write("roomfile for "+dir_array[dir_cnt +1]+" : ");
		input_to("set_dir_file");
		return 1;
	}
}
static set_dir_file(str) {
	if(str && str == "~q") {
		write("aborted.\n");
		return 1;
	}
        if(!str || str == "") {
		write("roomfile for"+dir_array[dir_cnt+1]+" : ");
		input_to("set_dir_file");
		return 1;
	} else {
		dir_array[dir_cnt]=str;
		dir_cnt += 2;
		if(dir_cnt >= (sizeof(dir_array)+2)) {
			write("Maximum number of exits reached!\n");
			if(in_edit) {
				edit_dirs("");
				return 1;
			}
			write("light level("+room_light+"): ");
			input_to("set_light_level");
			return 1;
		}
		if(in_edit) {
			edit_dirs("");
			return 1;
		}
		write("direction "+(1+dir_cnt/2)+" command (end with **): ");
		input_to("set_dir_cmd");
		return 1;
		}
}
static set_light_level(str) {
	int	level;

        if(str && str == "~q") {
		write("aborted.\n");
		return 1;
	}
	if(!str || str == "") {
		room_light=1;
	} else {
		if(sscanf(str, "%d", level) !=1) {
			write("light level(1): ");
			input_to("set_light_level");
			return 1;
		}
		room_light = level;
	}
	edit_room("");
	return 1;
}

static edit_room(str) {
	int	sel;
	int	match;

	in_edit = 1;
	if(!str) str = "";
	match = 1;
	if(strlen(str) >= 1) {
		sel=str[0];
		if(sel=='h'){
			show_help();
			match=1;
		}
		if(sel=='q') {
			write("aborted.\n");
			return 1;
		}
		if(sel=='e') {
			if(do_edit(extract(str,1))) {
				return 1;
			}
			str="";
			match=1;
		}
		if(sel=='w') {
			do_file();
			return 1;
		}
	}
	if(str == "" || !match) {
		show_room();
		write("w(rite),q(uit),e(dit) <cr> ? h(elp)\n");
		write("command: ");
	}
	input_to("edit_room");
	return 1;
}
static show_help()
{
	write("edit menu of roommaker\n");
	write("q	-exit from roommaker without making file\n");
	write("w	- write file and exit\n");
	write("es	-edit short comment of room\n");
	write("el	edit long comment of room\n");
	write("ed	-edit direction info\n");
	write("ev	-change light\n");
	write("<cr>	-show room again\n");
	write("?	-this help text\n");
	write("h	-this help text\n");
	return;
}
static do_edit(str) {
	int	sel;
	if(strlen(str)>=1) {
		sel=str[0];
		if(sel=='s') {
			write("short name of room(" + short_string + "):");
			input_to("set_short");
			return 1;
		}
		if(sel=='1') {
			old_long_text = long_text;
			long_text=0;
			write("long desc of " + short_string + ": (** to end, only ** keeps the old long desc)\n");
			write("[");
			input_to("set_long");
			return 1;
			}
		if(sel=='v') {
			write("light level("+room_light+"): ");
			input_to("set_light_level");
			return 1;
		}
		if(sel=='d') {
			edit_dirs("");
			return 1;
		}
	}
	write("unknown edit parameter: "+str+"\n");
	write("use the \"h\" to get help.\n");
	return 0;
}
int	edit_dir_num;
static edit_dirs(str) {
	int	num,sel;
        if(str && str !="") {
		sel=str[0];
		if(sel =='m') {
			edit_room("");
			return 1;
		}
		if(sel=='a') {
			if(dir_cnt >= (sizeof(dir_array)+2)) {
				write("maximum number of exist reached!\n");
			} else {
				write("direction "+(1+dir_cnt/2)+" command (end with **): ");
				input_to("set_dir_cmd");
				return 1;
			}
		}
		if(sel=='h' || sel == '?') {
				help_dirs();
				str="";
		}
		if(sel=='c'){
			if(dir_cnt <= 0) {
				dir_cnt=0;
				write("no exits to change!\n use \"a\" to add a new exit \n");
			} else{
				if(sscanf(str,"c%d",num) !=1) {
					write("usage: c#\n");
					write("where # is a number " + 1 + "-" + dir_cnt/2+1+"\n");
				} else {
					num -= 1;
					num *= 2;
					edit_dir_num=num;
					write("direction " + (1+edit_dir_num/2) + " command (" + dir_array[edit_dir_num +1 ] +"): ");
					return 1;
				}
				}
			}
		}
		if(sel=='d') {
			if(dir_cnt <=0) {
				dir_cnt=0;
				write("no exits to remove\n");
			} else {
				if(sscanf(str, "d%d", num) !=1) {
					write("usage: d#\n");
					write("where # is a number " +1+"-"+dir_cnt/2 + 1 + "\n");
				} else {
					if(num <1|| num >dir_cnt/2+1) {
						write("usage: d#\n");
						write("where # is a number "+1+"-" + dir_cnt/2 +1 + "\n");
					} else {
						num -=1;
						num*=2;
						while((num+2) < sizeof(dir_array) && dir_array[num+2]) {
							dir_array[num] = dir_array [num + 2];
							dir_array[num +1] = dir_array[num + 3];
							num += 2;
						}
						dir_cnt -= 2;
						dir_array[dir_cnt]=0;
						dir_array[dir_cnt+1]=0;
					}
				}
			}
		}
	write("---exits---\n");
	show_dirs(1);
	write("c(hange)#, d(elete)#, a(dd), ?, h(elp), m(ain menu)\n");
	write("command: ");
	input_to("edit_dirs");
	return 1;
}
static change_dir(str){
	if(str && str !="") {
		dir_array[edit_dir_num+1]=str;
	}
	write("roomfile for " + dir_array[edit_dir_num+1] + "(" +dir_array[edit_dir_num]+") : ");
	input_to("change_room");
	return 1;
}
static change_room(str) {
	if(str && str != "") {
		dir_array[edit_dir_num]=str;
	}
	edit_dirs("");
	return 1;
}
static help_dirs()
{
	write("direction editor\n");
	write("m	-return to main editor\n");
	write("c#	-change direction and room number #\n");
	write("d#	-delete directon number #\n");
	write("a	-add a new direction and room\n");
	write("h	-this help text\n");
	return;
}
static show_dirs(arg) {
	int i;
	i=0;
	while(i+1<sizeof(dir_array) && dir_array[i]) {
		if(arg) {
			write((i/2 +1) + ": ");
		}
		write(dir_array[i+1] + "-> " + dir_array[i] + "\n");
		i += 2;
	}
}
static show_room()
{
	write("\n---file name---\n");
	write(out_file_name_c + "\n");
	write("---short desc---\n");
	write(short_string + ".\n");
	write("---long desc---\n");
	write(long_text);
	write("---exits---\n");
	show_dirs(0);
	write("---other---\n");
	write("light: " + room_light + "\n");
	write("------------\n");
	return 1;
}
string file_text;
static do_file()
{
	int i;
	object longs,ob;
	string slask;
	int ret;
	file_text="";
	add_line("");
	add_line("");
	add_line("inherit \"room/room\";");
	add_line("");
	add_line("reset(arg) {");
	add_line("");
	add_line("	set_light(" + room_light +");");
	add_line("	short_desc = \"" + short_string + "\";");
	add_line("	no_castle_flag=0;");
	longs=explode(long_text,"\n");
	if(longs){
		i=0;
		slask="\\nx";
		add_line("	long_desc = ");
		while(i < sizeof(longs)) {
			add("		");
			if(i > 0) {
				add("+ ");
			}
			add("\"");
			add(longs[i]);
			add(extract(slask, 0, 0));
			add("n\"");
			if(i == sizeof(longs)-1) {
				add_line(";");
			} else {
				add_line("");
			}
			i+=1;
		}
	}
	add_line("	dest_dir = ");
	add_line("	    ({");
	i = 0;
	while(i+1 < sizeof(dir_array) && dir_array[i]) {
		add_line("	\""+dir_array[i]+"\", \""+dir_array[i+1] + "\",");
			i += 2;
	}
	add_line("	});");
	add_line("}");
	add_line("");
	add_line("query_light() {");
        add_line("    return "+room_light+";");
	add_line("}");
	add_line("query_room_maker() {");
	add_line("	return 1;");
	add_line("}");
	add_line("");
	add("/"); add_line("*");
	add_line("	remove the comments around the \"room is modified()\" code");
	add_line("	below to prevent changes you have done to this room to");
	add_line("	to be lost useing the roommaker");
	add("*"); add_line("/");
	add("/"); add_line("*");
	add_line("room_is_modified() {");
	add_line("	return 1;");
	add_line("}");
	add("*"); add_line("/");
        add("/"); add_line("*");
	add_line(" make your additions below this comment, do NOT remove this comment");
	add_line("--END-ROOM-MAKER-CODE--");
	add("*"); add_line("/");
	add_line("");

	if(file_size(out_file_name_c) > 0) {
		write("Removeing existing file "+out_file_name_c+"\n");
		ret=rm(out_file_name_c);
/*
		if(is_debug) {
			write("rm returned " + ret + "\n");
		}
*/
	}
	write("creating file " + out_file_name_c + ".\n");
	ret=write_file(out_file_name_c, file_text);
/*
	if(is_debug) {
		write("wrie_file returned " + ret + "\n");
	}
*/
	write("updating file " + out_file_name + ",\n");
        ob=find_object(out_file_name);
	if(ob) {
		destruct(ob);
	}
	write("teleporting to " + out_file_name + ".\n");
	this_player()->move_player("X#" + out_file_name);
	write("ok.\n");
}
static add_line(str) {
/*
	if(is_debug) {
		write("add_line(");		write(str);
		write(")\n");
	}
*/
	if(file_text==0) {
		file_text="";
	}
	file_text=file_text + str + "\n";
}
static add(str) {
/*
	if(is_debug) {
		write("add(");
		write(str);
		write(")\n");
	}
*/
	if(file_text==0) {
		file_text="";
	}
	file_text=file_text + str;
}
init()
{
	if(
		this_player()
		&&
		environment(this_object()) == this_player()
		&&
		(this_player()->query_level() > 19)
	) {
		add_action("make", "make");
		add_action("debug_toggle", "debug");
		add_action("version","ver");
		add_action("help","help");
        add_action("fix","reset");
	}
}
static help(arg) {
	if(!id(arg)) {
		return 0;
	}
	write("usage: make filename\n");
	write("creates a file in your dir that is a room,\n");
	write("you are teleported there.\n");
	write("do not add \".c\" to filename as this is done automatically.\n");
	write("the process can be aborted by typin ~q at the prompt.\n");
	write("more help can be found in the various editing menus with\n");
	write("the ? command.\n");
	write("example: make newroom\n");
	write("	wilol creat a file named /players/xxxx/newroom.c\n");
	write("	where xxxx is you rname\m");
	write("	example: make room/myplace\n");
	write(" 	will create a file named /players/xxxx/room/myplace.c\n");
	write("the rm can adit existing rooms if they were created by\n");
	write("the rm , just specify an existing room to edit it.\n");
	return 1;
}
get() {
	return 1;
}
query_name()
{
	return "room_maker";
}
id(str) {
	return (str=="roommaker");
}
short() {
	return "a room maker";
}
long()
{
	write("Mine Mine Mine leave it alone.\n");
	return 1;
}
query_info() {
	return "wiz use only!";
}
fix() {
move_object(clone_object("players/lew/things/roommaker"), this_player());
destruct(this_object());
return 1;
}
