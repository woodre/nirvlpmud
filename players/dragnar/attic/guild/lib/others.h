#include "/players/dragnar/guild/defs/def.h"
darken() {
	object scar;
	write("You darken your mark of shardak with a knife.\n");
	destruct(present("shardak_mark",this_player()));
	scar=clone_object("/players/dragnar/guild/slave.c");
	move_object(scar, this_player());
	return 1; }
others() {
	int i;
	object list;
	list = users();
	write("\n");
	write("   Name:\tLevel:\tGuild:\tGender:\tLocation:\n");
	write("[------------------------------------------------------------------------------]\n");
	for(i=1; i < sizeof(list); i++) {
	if(this_player()->query_level() > list[i]->query_invis()) {
	if(i < 10) write(" "+i+". ");
	if(i > 9) write(""+i+". ");
	write(capitalize(list[i]->query_real_name()));
	if(strlen(list[i]->query_real_name())>3 && i < 10)
	write("\t");
	if(strlen(list[i]->query_real_name()) < 4 && i < 10)
	write("\t\t");
	if(strlen(list[i]->query_real_name())>3 && i > 9)
	write("\t");
	if(strlen(list[i]->query_real_name()) < 4 && i > 9)
	write("\t\t");
	if(list[i]->query_pl_k()) write(list[i]->query_level() + "*\t");
	else write(list[i]->query_level()+"\t");
	if(!list[i]->query_guild_name()) write("None\t");
	else write(list[i]->query_guild_name() + "\t");
	if(list[i]->query_gender() == "male") write("   M\t");
	if(list[i]->query_gender() == "female") write("   F\t");
	if(list[i]->query_gender() == "creature") write("   C\t");
	if(!environment(list[i])) write("Logging In");
	else write(environment(list[i])->short());
	write("\n");
	}
	}
	write("[------------------------------------------------------------------------------]\n");
	return 1;
}
