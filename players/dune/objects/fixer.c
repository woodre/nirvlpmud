#define CO   call_other
#define MV   "move_player"
#define TEL  CO(TP, MV
#define R1   return 1
#define TP this_player()
id(str) { return str == "fixer"; }
short () { return "A fixer"; }

long() {
   write(
"_____________________________________________\n"+
"guild <who>            shows guild status\n"+
"unguild <who>          destroys guild status\n"+
"view <who>             look at someone's quicktyper\n"+
"setxlv <number>        change your xtra level\n"+
"setac <number>         change your ac\n"+
"setwc <number>         change your wc\n"+
"setatt <what> <num>    sets 'what' attrib to 'num'\n"+
"upload <file>          loads and then updates a file\n"+
"get_owner <objectStr>  gets owner of path or ob name\n"+
"_____________________________________________\n");
}

get() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

init() {
   if(TP->query_level() < 20) {
     destruct(this_object());
     return 1; }
   add_action("guild","guild");
   add_action("setatt","setatt");
   add_action("unguild","unguild");
   add_action("setac","setac");
   add_action("setwc","setwc");
   add_action("setxlv","setxlv");
   add_action("upload","upload");
   add_action("where","list");
   add_action("church","church");
   add_action("post","post");
   add_action("shop","shop");
   add_action("lockers","lockers");
   add_action("advance","advance");
   add_action("adv_inner","inner");
  add_action("upall","upall");
  add_action("gfile","gfile");
   add_action("castle","castle");
   add_action("monkguild","monkguild");
   add_action("shadowguild","shadowguild");
   add_action("paladinguild","paladinguild");
   add_action("undeadguild","undeadguild");
   add_action("vampguild","vampguild");
   add_action("catmini","catmini");
   add_action("kendermini","kendermini");
   add_action("larnmini","larnmini");
   add_action("necromini","necromini");
   add_action("succumini","succumini");
   add_action("gypsymini","gypsymini");
   add_action("pub","pub");
}

upall()  {
  /* command to update all cyberninja implants */
  int b;
  object ob;
  ob = users();
  write("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  for(b=0;b<sizeof(ob);b+=1)  {
    if(present("CyberNinja Implants",ob[b]))  {
      present("CyberNinja Implants", ob[b])->update_implants();
      write(pad(ob[b]->query_name(),15));
      write(" updated.\n");
      }
    }
    write("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 1;
}

upload(string file) {
 if(file_size(file) <= 0) return 0;
 command("load "+file, TP);
 command("update "+file, TP);
 return 1; }

where() {
  write("You may teleport to the following places.\n");
  write(
" _________________________________________\n"+
" General Locations:          Guilds:\n"+
"   church                      monkguild\n"+
"   post                        shadowguild\n"+
"   shop                        paladinguild\n"+
"   lockers                     undeadguild\n"+
"   advance                     vampguild\n"+
"   inner                       bardguild\n"+
"   castle\n"+
" \n"+
" Taverns/Healing:            Mini Guilds:\n"+
"   pub                         catmini\n"+
"                               kendermini\n"+
"                               larnmini\n"+
"                               necromini\n"+
"                               succumini\n"+
"                               gypsymini\n"+
" _________________________________________\n");
return 1;}

advance(){TEL, "advance#room/adv_guild.c"); R1;}
post(){TEL, "post#room/post.c"); R1;}
shop(){TEL, "shop#room/shop.c"); R1;}
lockers() {TEL, "lockers#players/catwoman/tl.c"); R1;}
adv_inner() {TEL, "adv_inner#room/adv_inner.c"); R1;}
church() {TEL, "church#room/church.c"); R1;}
castle() {TEL, "castle#room/plane8.c"); R1;}
shadowguild(){TEL, "shadowguild#room/plane2.c"); R1;}
monkguild() {TEL, "monkguild#players/hawkeye/closed/guild/join.c"); R1;}
undeadguild() {TEL, "undeadguild#players/hurtbrain/guildent.c"); R1;}
vampguild() {TEL, "vampguild#players/nooneelse/guildent.c"); R1;}
paladinguild() {TEL, "paladinguild#players/sandman/paladin/entry.c"); R1;}
gypsymini() {TEL, "gypsymini#players/saber/ryllian/gv3.c"); R1;}
catmini() {TEL, "catmini#players/saber/ryllian/ryll11.c"); R1;}
larnmini() {TEL, "larnmini#players/saber/ryllian/church.c"); R1;}
necromini() {TEL, "necromini#players/saber/ryllian/ryll9.c"); R1;}
succumini() {TEL, "succumini#players/saber/ryllian/ryll10.c"); R1;}
kendermini() {TEL, "kendermini#players/saber/ryllian/ms6.c"); R1;}
pub() {TEL, "pub2#room/pub2.c"); R1;}

guild (string who) {
   object pl;
   if (!who) { write("Usage: guild <who>\n"); return 1;}
   if(!find_player(who)) {
     write("No "+capitalize(who)+" logged on.\n");
     return 1;}
   pl = find_player(who);
   write(pl->query_guild_name()+"\n");
   write(pl->query_guild_rank()+"\n");
   write(pl->query_guild_exp()+"\n");
   write(pl->query_guild_file()+"\n");
   return 1; }

unguild(string who) {
   string type;
   int num, numer;
   object pl;
   if (!who) { write("Usage: unguild <who>\n"); return 1;}
   if(!find_player(who)) {
     write("No "+capitalize(who)+" logged on.\n");
     return 1;}
   pl = find_player(who);
   write(pl->query_guild_name()+"\n");
   write(pl->query_guild_rank()+"\n");
   write(pl->query_guild_exp()+"\n");
   write(pl->query_guild_file()+"\n");
   pl->set_guild_name(0);
   pl->set_guild_rank(0);
   pl->set_guild_exp(0);
   pl->set_guild_file(0);
   num = ((int)pl->query_guild_exp());
   numer = ((int)pl->query_guild_rank());
   pl->add_guild_exp(-num);
   write_file("/players/dune/log/UNGUILD",
              this_player()->query_real_name()+
              " unguilded "+capitalize(who)+
              " ("+ctime()+")\n");
   pl->add_guild_rank(-numer);
   return 1; }

setatt(string str) {
  string what;
  int num;
  if(!str) {
    write("Usage: setatt <what> <num>\n");
    write("Choices are: str, sta, wil, mag, pie, ste, luc, int\n");
    return 1; }
  if(!sscanf(str, "%s %d", what, num)) {
    write("Usage: setatt <what> <num>\n");
    write("Choices are: str, sta, wil, mag, pie, ste, luc, int\n");
    return 1; }
  this_player()->set_attrib(what, num);
  return 1; }

setac(int num) {
  if(!num) { write("Usage: setac <number>\n"); return 1; }
  this_player()->set_ac(num);
  return 1; }

setwc(int num) {
  if(!num) { write("Usage: setwc <number>\n"); return 1; }
  this_player()->set_wc(num);
  return 1; }

setxlv(int num) {
  if(!num) { write("Usage: setxlv <number>\n"); return 1; }
  this_player()->set_extra_level(num);
  return 1; }

view(string str) {
  string who, type;
  object ob;
  if(!str) {
    write("Usage: view <player> [a/h]\n");
    return 1; }
  if(!sscanf(str, "%s %s", who, type)) {
    write("Usage: view <player> [a/h]\n");
    return 1; }
  if(!find_player(who)) {
    write(capitalize(who)+" is not on.\n");
    return 1; }
  if(!present("qt", find_player(who))) {
    write(capitalize(who)+" does not have a qt.\n");
    return 1; }
  ob = present("qt", find_player(who));
  if(type == "a") {
    call_other(ob, "alias");
    }
  if(type == "h") {
    call_other(ob, "history");
    }
  else write("Usage: view <player> [a/h]\n");
  return 1;
}

gfile(string str) {
  object ob;
  if(!str) { return 0; }
  if(!find_player(str)) return 0;
  ob = find_player(str);
  write(capitalize(str)+"'s cyberninja guild file is set.\n");
  write_file("/players/dune/log/GFILE", this_player()->
             query_real_name()+
             " set "+ob->query_real_name()+
             "'s ninja guild file.\n");
  ob->set_guild_file("/players/dune/closed/guild/implants.c");
  return 1;
}

get_owner(string str)
{
  object ob;
  if (!str) { return 0; }

ob = find_player(str);
write("nohonor: " + (present("implants", ob))->query_nohonor() + "\n");
  if (ob = present(str, this_player()))
  {
    write("Owner of " + str + " is: " + creator(ob) + "\n");
    return 1;
  }
  else if (ob = find_object(str))
  {
    write("Owner of " + str + " is: " + creator(ob) + "\n");
  }
  else
    write("No such object can be recognized.\n");
  return 1;
}
