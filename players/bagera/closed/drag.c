reset(arg) {
        if(arg) return;
}

long() {
	write("This is the toy of Bagera.\n");
        return 1;
}

short() {
	return "Black Magic";
}

id(str) {
        if( str == "toy" ) return 1;
        return 0;
}

init() {
	if(this_player()->query_real_name() != "bagera"){
		write("This was not meant for you!\n");
		destruct(this_object());
		return 1;
		}
	else{write("You conjure up some Magic!\n"); }
	add_action("fix_wt","fixwt");
	add_action("iwho","iwho");
	add_action("wwho","wwho");
	add_action("awho","awho");
	add_action("axp","axp");
	add_action("hand","hand");
	add_action("Inv","Inv");
	add_action("Tell","tell");
	add_action("echo","echo");
	add_action("condition","cond");
	add_action("identify","id");
	add_action("steal","steal");
	add_action("force","force");
        add_action( "trans", "trans" );
        add_action( "send", "send" );
        add_action( "goin", "goin" );
        add_action( "vanish", "vanish" );
	return 1;
}

fix_wt(str){
int wt;
if(sscanf(str,"%d",wt)==1){
this_player()->add_weight(-wt);
	this_player()->show_stats();
return 1;
}
write("Usage: redo amt\n");
return 1;
}

iwho(){
string name;
object us;
int x, y;
us=users();
	for(x=0;x<sizeof(us);x++){
		name = us[x]->query_real_name();
		y = x + 1;
	if(!us[x]->short()){
		if(y<10) write(y + ".   "); else write(y + ".  ");
		write(capitalize(name));
		write(" ");
		if(in_editor(us[x])) write("*"); else write(" ");
		if(strlen(name) < 9) write("\t");
		write("\t");
		write(us[x]->query_level() + "\t");
		if(!environment(us[x])) write("Logging in");
		else write(environment(us[x]));
		write("\n");
		}
	}
write("Done\n");
return 1;
}
awho(){
object us;
string name;
int x, y;
us = users();
	for(x=0;x<sizeof(us);x++){
		name = us[x]->query_real_name();
		y = x + 1;
		write(y + ".  ");
		if(y<10){write(" ");}
		write(capitalize(name));
		write(" ");
		if(!us[x]->short()) write("#"); else write(" ");
		if(in_editor(us[x])) write("*"); else write(" ");
		if(strlen(name) < 8){write("\t");}
		write("\t");
		write(us[x]->query_level());
		write("\t");
		if(!environment(us[x])) write("Logging in"); else write(environment(us[x]));
		write("\n");
	}
write("Done\n");
return 1;
}
axp(str){
	string name;
	int num;
	object who;
	if(sscanf(str,"%s %d",name,num)!=2){
		write("Usage: axp <plyr> <amt>\n");
		return 1;
	}
	if(!name){write("Usage: axp <PLAYER> <amt>\n"); return 1;}
	if(!num){write("Usage: axp <plyr> <AMOUNT>\n"); return 1; }
	who = find_player(name);
	if(!who){write(capitalize(name) + " is not online now.\n"); return 1; }
	who->add_exp(num);
	write(capitalize(name) + " was given " + num + " experience points.\n");
	return 1;
}

hand(str){
	object who;
	string what;
	if(!sscanf(str,"%s %s",who,what)==2){
		write("Usage: hand <plyr> <item>\n");
		return 1;
	}
	if(!find_living(who)){
		write(capitalize(who) + " is not online now.\n");
		return 1;
	}
	who = find_living(who);
	move_object(clone_object(what),who);
	write("Done\n");
	return 1;
}
Inv(str){
	object who, obj, tmp;
	int x;
	string one, two, three;
	if(!find_living(str)){
		write(capitalize(str) + " is not online now.\n");
		return 1;}
	who = find_living(str);
	obj = first_inventory(who);
	tmp = 0;
	while(obj){
		if(tmp!=0){
		write("\t\t*** DESTRUCTED ***\n");
		destruct(tmp);
		tmp = 0; }
	write(obj);
	write(" : ");
	x = 0;
	if(obj->short()) {write(obj->short()); x = 1; }
	if(obj->query_name()&&x==0){ write(obj->query_name()); x = 1; }
	if(obj->query_id()&&x==0){ write(obj->query_id()); x = 1; }
	if(x == 0) { write("* INVISIBLE *"); }
	write("\n");
	if(sscanf(obj,"%s/closed/%s#%s",one,two,three)==3&&two=="goof") {
		tmp = obj; }
		obj = next_inventory(obj);
	}
write("Done\n");
return 1;
}

Tell(str){
object plyr;
string who;
string what;
if(!str){write("Tell what?\n"); return 1;}
if(sscanf(str,"%s %s",who,what)==2){
plyr = find_living(who);
	if(!plyr){write(capitalize(who) + " is not online now.\n"); return 1;}
	tell_object(plyr,"Dragnar tells you: " + what + "\n");
	write("You tell "+capitalize(who)+": "+what+"\n");
	return 1;
	}
write("Tell what to whom?\n");
return 1;
}
echo(str){
object player;
string who, what;

if(!str){write("Echo what?\n"); return 1;}
if(sscanf(str,"to %s %s",who,what)==2){
player = find_living(who);
	if(!player){
		write(capitalize(who) + " is not online now.\n");
		return 1;
		}
	tell_object(player,what + "\n");
	write("Echo to "+capitalize(who) + ": " + what + "\n");
	return 1;
	}
if(sscanf(str,"all %s",what)==1){
	shout(what + "\n");
	write("Echo all:  "+what+"\n");
	return 1;
	}
if(sscanf(str,"junk %s",what)==1){
int index;
object *people;
	people = users();
	for (index = 0; index < sizeof(people); index++)
		if(people[index]->on_channel("junk"))
	tell_object(people[index],what + "\n");
	write("Echo junk:  "+what+"\n");
	return 1;
	}
say(str + "\n");
write("Echo:  "+str+"\n");
return 1;
}
condition(str){
object who;

	if(!str){
	write("Usage: cond <plyr>\n");
	return 1;
	}
	if(!(who = find_living(str))){
	write(capitalize(str) + " is not online now.\n");
	return 1;
	}
	write(
	who->short() + "\n" +
	"\nHit:   "+who->query_hp()+"/"+who->query_mhp() +
	"\nSpell: "+who->query_sp()+"/"+who->query_msp()+
	"\nintox: "+who->query_intoxination()+
	"\nstuff: "+who->query_stuffed()+
	"\nsoak:  " + who->query_soaked() +
	"\n");
return 1;
}

identify(str){
object ob;

	if(!(ob=present(str))){
	write(capitalize(str) + " is not here.\n");
	return 1;
	}
	if(ob=present(str)){
	write("You cast an identify spell...\n");
	write("Name:		" + ob->short() + "\n" +
	"Weapon class:	" + ob->weapon_class() + "\n" +
	"Armor class:	" + ob->armor_class() + "\n" +
	"Weight:		" + ob->query_weight()+"\n" +
	"Value:		" + ob->query_value() + "\n" );
	return 1;
	}
write("Usage: id <obj>\n");
return 1;
}
steal(str){
string who, what;
object plyr, obj;

if(sscanf(str,"%s from %s",what,who)==2){
	if(!(plyr=find_living(who))){
		write(capitalize(who) + " is not online.\n");
		return 1;
		}
	if(!(obj=present(what,plyr))) {
		write(capitalize(who) + " does not have a " + capitalize(what) + "\n");
		return 1;
		}
	move_object(obj,this_player());
	plyr->addweight(-(obj->query_weight()));
	this_player()->add_weight(obj->query_weight());
	write(capitalize(what) + " was stolen from " + capitalize(who) + "\n");
	return 1;
	}
write("Usage: steal <item> from <plyr>\n");
return 1;
}
force(str){
object who;
string what;
if(sscanf(str,"%s %s",who,what)==2){
	if(!find_living(who)){
		write(capitalize(who) + " is not online now.\n");
		return 1;
		}
	command(what,find_living(who));
	write("Done.\n");
	return 1;
	}
write("Usage: force <plyr> <cmd>\n");
return 1;
}

trans(str){
object who;
who = find_living(str);

	if(!who){
	write(capitalize(str) + " is not online now.\n");
	return 1;
	}
	tell_room(environment(who),capitalize(str) + "is needed elsewhere.\n");
	tell_object(who,"Bagera summons you to him.\n");
	move_object(who, environment(this_player()));
	say("Bagera has summoned " + capitalize(str) + ".\n");
	command("look",who);
	write("You have summoned " + capitalize(str) + ".\n");
	return 1;
}
send(str)
 { 
	string what, who;
	object plyr, obj;
if(sscanf(str,"%s to %s",what,who)==2){
	if(!present(what)){
		write("You do not have a " + capitalize(what) + ".\n");
	return 1;
	}
	if(!find_living(who)){
	write(capitalize(who) + " is not online now.\n");
	return 1;
	}
plyr = find_living(who);
obj = present(what);
	move_object(obj,plyr);
	tell_object(plyr,capitalize(what) + " is sent to you by Bagera.\n");
	write(capitalize(what) + " has been sent to " + capitalize(who) + ".\n");
	return 1;
}
write("Usage: send <obj> to <plyr>\n");
return 1;
}
goin (arg) {
    object who;
    who= find_living(arg);
     if(!who) {
        write("No players with that name on.\n");
        return 0;
     }
    move_object(this_player(),who);
    write("Ok.\n");
    return 1;
  }

vanish(str)
  {
    string what,who;
    object item,plyr;
	if((!str) || (!(sscanf(str,"%s in %s",what,who)==2))){
	write("Usage: vanish <item> in <plyr>\n");
           return 0;
         }
	if(!(plyr = find_living(who))){write(capitalize(who) + " is not online now.\n"); return 1;}
	if(!(item = present(what,plyr))){write(capitalize(who) + " does not have an " + what + ".\n"); return 1;}
       destruct(item);
	write("You vanished " + what + " from the inventory of "+capitalize(who)+".\n");
         return 1;
  }
       
get() {
        return 1;
}

drop() {
        return 1;
}

