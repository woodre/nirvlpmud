fix_guild(str){
object fool;
int hh,jj;
fool = find_player(str);
/*
jj=0-fool->query_guild_exp();
call_other(fool,"add_guild_exp",jj);
hh=0-fool->query_guild_rank();
fool->add_guild_rank(hh);
fool->set_guild_name(0);
fool->set_guild_file(0);
*/
fool->add_guild_rank(10);
return 1;
}
init(){
add_action("fix_guild","guildless");
}
id(str){return str=="guilder";}