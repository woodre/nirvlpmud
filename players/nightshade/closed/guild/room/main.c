inherit "room/room";

reset(arg) {
if(arg) return;
  set_light(1);
  short_desc = "The main guild room";
  long_desc = 
  "     This is the main guild room. If you are having trouble\n"
+ "     with your symbol, just type <symbol> and it will clone\n"
+ "     a new one for you. To the west is the real guild to\n"
+ "     raise your real level and stats. Here you may <pray> to\n"
+ "	advance your cleric level if possible.\n";
  dest_dir = ({
 "/players/nightshade/closed/guild/room/adv", "west",
  });
  
}

init() {
::init();
  add_action("new_symbol", "symbol");
  add_action("advance","pray");
  add_action("stop","up");
}

stop() {
object ob, badge;
int glevel;
  ob = this_player();
if(this_player()->query_guild_name() != "clerics") {
    write("You are not a member!\n");
    return 1;
  }
  badge = present("cleric_guild", ob);
  if(!badge) {
    write("First, you must get a badge.\n");
    return 1;
  }
  glevel = badge->query_guild_level();
  if(glevel < 5) {
    write("You are not high enough guild level.\n");
    return 1;
  }
}

advance() {
int ep, need;
int glev, man;
int nl;
object badge;
string name;
/*
if(this_player()->query_guild_name() != "clerics") {
    write("You do not belong to this guild.\n");
   this_player()->move_player("X#players/nightshade/closed/guild/adv");
    return 1;
  }
*/
52
a
  badge = present("cleric_guild", this_player());
  if(!badge) {
    write("You must first get the holy symbol of faith.\n");
    return 1;
  }
  ep = badge->query_guild_exp();
  need = badge->query_exp_needed();
  if(ep < need) {
    write("Matry says: You do not possess enough experience to advance.\n");
    return 1;
  }
  glev = badge->query_guild_level();
  if(glev > 15 ) {
    write("You can not advance any higher.\n");
    return 1;
  }
  man = badge->query_max_mana();
  name = this_player()->query_name();
  write("Matry says: You are now enlightened and stronger.\n");
  badge->set_guild_level(glev+1);
  badge->set_max_mana(man + 10);
  nl = badge->query_guild_level() + 1;
  write_file("/players/nightshade/notes/CLERIC",
    ctime(time())+": "+name+" advanced to level [" +
        nl+"]  EXP["+ep+"]\n");
  badge->guild_shout(name+" has been enlightened by Matry.\n");
  badge->guild_save();
  return 1;
}

new_symbol() {
object badge;
   if(this_player()->query_guild_name() != "clerics") {
   write("You dont belong to this guild.\n");
   return 1;
}
  badge = present("cleric_guild", this_player());
  if(!badge) {
    write("Somehow you lost your symbol, Here is a new one.\n");
   move_object(clone_object("players/nightshade/closed/guild/symbol"),
        this_player());
    return 1;
  }
  write("The old one is now gone, and here is a new one.\n");
  badge->guildsave();
  destruct(badge);
   move_object(clone_object("players/nightshade/closed/guild/symbol"),
        this_player());
   return 1;
}

