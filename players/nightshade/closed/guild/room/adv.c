

inherit "room/room";

int EXP;
int LeV;
int LOST;
int GLEV, START;
#define GET(x) move_object(clone_object(x),this_object());

reset(arg) {
if(arg) return;
    set_light(1);
    dest_dir = ({
"/players/nightshade/closed/guild/room/main", "east",
        });
  short_desc = "The cleric's guild";
  long_desc =
        "You have come to the Cleric's guild. Here, the guild members\n" +
         "can advance their real levels and stats. The non-members\n" +
         "can join the Cleric's guild if they wish. <join cleric>.\n" +
         "You can also unjoin the cleric's guild. All your guild\n" +
        "info will be erased when you unjoin. <unjoin clerics> \n" +
        "And lose 1/4 exp that you gained while in this guild.\n" +
 "";
        
}

init() {
    ::init();
    add_action("east","east");
    add_action("join","join");
    add_action("unjoin","unjoin");
}

south() {
    if (call_other(this_player(), "query_level", 0) < 50) {
        write("A strong magic force stops you.\n");
        say(call_other(this_player(), "query_name", 0) +
            " tries to go through the field, but fails.\n");
        return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "south#room/adv_inner");
    return 1;
}
east() {
  if(this_player()->query_guild_name() != "clerics") {
    write("Sorry, only guild members may go east.\n");
    say(this_player()->query_name()+ " tried to go east.\n");
    return 1;
  }
   this_player()->move_player("east#players/nightshade/closed/guild/main");
  return 1;
}

join(str) {
object badge;
  if(!str) {
    write("Would you like to join the Cleric's guild?\n");
    return 1;
  }
  if(this_player()->query_level()<5) {
    write("You cannot join a guild until you reach 5th level.\n");
    return 1;
  }
  if(str == "cleric") {
    if(this_player()->query_guild_name() == "clerics") {
        write("You are already a member to this guild.\n");
        return 1;
    }
   if(this_player()->query_guild_name()) {
        write("You already belong to a different guild.\n");
        return 1;
    }
    EXP = this_player()->query_exp();
    LeV = this_player()->query_level();
    write("Welcome to the cleric's guild.\n");
    say(this_player()->query_name()+ " has joined the cleric's guild.\n");
    this_player()->set_guild_name("clerics");
   badge = clone_object("players/nightshade/closed/guild/symbol");
    move_object(badge, this_player());
    badge->set_start_exp(EXP);
    badge->guild_shout(this_player()->query_name() +
        " has just joined the Cleric's guild!\n");
   write_file("/players/nightshade/notes/CJOIN",
    ctime(time())+": "+this_player()->query_real_name()+" ("+
        EXP+") Level("+LeV+")\n");
    return 1;
  }
  write("Type: join cleric \n");
  return 1;
}

unjoin(str) {
object badge;
  if(!str) {
    write("To unjoin type: unjoin cleric \n");
    return 1;
  }
  if(str == "cleric") {
    if(this_player()->query_guild_name() != "clerics") {
      write("You do not belong to this guild.\n");
      return 1;
    }
    write("You leave the cleric's guild. All the guild info will be deleted.\n");
    say(this_player()->query_name()+" leaves the guild.\n");
    badge = present("cleric_guild", this_player());
    if(!badge) {
        write("Please get the symbol first.\n");
        return 1;
    }
    EXP = this_player()->query_exp();
    LeV = this_player()->query_level();
    START = badge->query_start_exp();
    LOST = (EXP - START) / 4;
    if(LOST < 0) LOST = 0;
    else LOST = LOST;
    GLEV = badge->query_guild_name_level();
      write_file("/players/nightshade/notes/CUNJOIN",
        ctime(time())+": "+this_player()->query_real_name()+
        " ("+EXP+") Level("+LeV+") Glevel("+GLEV+") Lost("+LOST+")\n");
      this_player()->add_exp(-LOST);
    badge->guild_shout(this_player()->query_name() +
        " has left the Cleric's guild.\n");
   this_player()->set_guild_name();

rm("/players/nightshade/closed/guild/clericsave/"+this_player()->query_real_name()+".o");
    destruct(badge);
    return 1;
    }
  write("To unjoin type: unjoin cleric\n");
  return 1;
}

