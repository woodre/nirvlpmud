

int plugged, banished, guild_rank, guild_exp, level,monitor;
int rank, start_time, stalk, count, battle, guild_quest;
int ok_harm, ok_backstab;
string me, gender, guild_name, stalkee_name;

object stalkee;

reset(arg) {
      if(!guild_quest)
       guild_quest = 1;
        set_guild_name();
      if(arg)
     if(!arg)
        return;
}




set_guild_exp(a) { guild_exp = a; }

query_guild_exp() { return guild_exp; }


set_guild_quest(q) {guild_quest = q;}
query_guild_quest() {return guild_quest;}
set_plugged(pl) { plugged = pl; }

query_ok_backstab(){ return ok_backstab; }
set_ok_backstab(i){ ok_backstab = i; }
set_guild_name(){
     if(guild_quest == 1){
       guild_name = "apprentice assassin";
     }
     if(guild_quest == 2){
    guild_name = "journeyman assassin";
     }
     if(guild_quest == 3){
    guild_name = "master assassin";
     }
     if(guild_quest == 4){
   guild_name = "Godfather of assassins";
     }
     if(guild_quest == 5){
       guild_name = "Grand Elder Assassin";
     }
     if(this_player()->query_real_name() == "deathmonger"){
      guild_name = "Grand Master Adept (Assassin from hell!)";
       guild_quest = 7;
     }
   if(this_player()->query_real_name() == "turk") {
    guild_name = "bastard assassin";
        guild_quest = 6;
           }
}

query_guild_name(){ return guild_name; }
query_plugged() { return plugged; }
query_stalkee() { return stalkee; }



id(str) { return str == "license"; }


query_auto_load() {
  return "players/catt/ASSASSIN/object:"+guild_quest+"#"+
       guild_exp;
}

drop() {
    return 1;
}

short() {return 0;}

long() {
       write("This license gives you the right to kill players deemed un-\n");
       write("worthy of living by the vote of the guild.  It is your official\n");
       write("badge of membership in the Guild of Assassins.\n");
       write("Type 'license' for your guild commands.\n");
}

get() {
   return 1;
}

init_arg(arg) {
     sscanf(arg, "%d#%d", guild_quest, guild_exp);
     cat("/players/deathmonger/ASSASSIN/news");
     return;
}

init() {
    if(this_player()->query_real_name() == "deathmonger"){
       guild_quest = 5;
     }
    if(this_player()->query_name() != "Deathmonger" &&
    !this_player()->query_level() > 30 && this_player()->query_level() > 20){
       write("Make your own wiztoys.  The guild is for players.\n");
     destruct(this_object());
     return 1;
     }
     add_action("adjust_myself","adjust_myself");
    if(this_player()->query_pl_k() == 0){
       write("You must set your player killing to rejoin.\n");
     return 1;
     }

    ok_harm = 1;
    me = this_player()->query_real_name();
    add_action("harm","harm");
    add_action("backstab", "backstab");
     add_action("stalk","stalk");
    add_action("plugs","earplugs");
    add_action("monitor","o");
    add_action("rank","rank");
    add_action("al_title", "alignment");
    add_action("decolor", "decolor");
    add_action("sneak","sneak");
    add_action("mason","mason");
    add_action("echo","echo");
    add_action("levels","levels");
     add_action("leaveguild","leaveguild");
     add_action("fear","fear");
     add_action("contract","contract");
    add_action("code","code");
     add_action("list_quest","quest");
    add_action("escape","escape");
     add_action("peer","preview");
    add_action("hitlist","hitlist");
    /* add_action("wizards", "wizards"); */
    add_action("recruit","recruit");
    add_action("news","news");
    add_action("consider","consider");
    add_action("assassin_cant","ac");
    add_action("logged_on","assassins");
    add_action("help_license","license");
    add_action("help_license1","license1");
    add_action("punish","punish");
    add_action("spy", "spy");
    add_action("disguise","disguise");
   add_action("guild_title","gtitle");
}

monitor(){
     if(monitor == 0){
        monitor = 1;
        set_heart_beat(1);
      write("Health monitor toggled on.\n");
         return 1;
     }
     if(monitor == 1){
     monitor = 0;
    write("Health monitor toggled off.\n");
     return 1;
     }
}
static expell(){
     write("You have been expelled from the guild.  Now you're really \n");
     write("in big trouble, as the assassins come after you...\n");
     destruct(this_object());
     return 1;
}

levels(){
    cat("/players/deathmonger/ASSASSIN/levels");
     return 1;
}

leaveguild(){
     this_player()->add_guild_exp(-1);
     destruct(this_object());
     write("You have left the Guild of Assassins.\n");
     return 1;
}

adjust_myself() {
     object ob, new_license;
     int quest, exp, backstab;

     new_license = clone_object("players/deathmonger/ASSASSIN/license");
     quest = this_object()->query_guild_quest();
     guild_name = this_object()->query_guild_name();
     exp = this_object()->query_guild_exp();
     plugged = this_object()->query_plugged();
     battle = this_object()->query_battle();
     backstab = this_object()->query_ok_backstab();
     new_license->set_plugged(plugged);
     new_license->set_battle(battle);
     new_license->set_guild_quest(quest);
     new_license->set_guild_name();
     new_license->set_guild_exp(exp);
     new_license->set_ok_backstab(backstab);
     move_object(new_license, this_player());
     destruct(this_object());
     write("Your License to Kill has been reset.\n");
     return 1;
}


fear(str){
     object who;
     who = present(str, environment(this_player()));
     if(who->query_level() > 20){
      this_player()->run_away();
      write("You make a scary face. He makes an even scarier one!\n");
     return 1;
}
     if(!who){
       write("That player is not here.\n");
       return 1;
     }
       if(!who->query_interactive()){
       write("This monster is scarier than any face you can make.\n");
        return 1;
      }
      if(!who->query_wimpy()) {
        write("The monster withstands your fear.\n");
        return 1;
      }
      if(this_player()->query_spell_point() < 25) {
   write("You do not have enough spell pts.\n");
   return 1;
   }
     who->run_away();
     this_player()->add_spell_point(-25);
     write("You scare "+str+" right out of the room.\n");
     tell_object(who,
     capitalize(this_player()->query_name())+" makes such a scary face"+
     " that you run out of the room in fright.\n");
      return 1;
}

backstab(str){
     object victim;
     int damage;
     victim = present(str, environment(this_player()));
     if(!victim){
     write("That is not here.\n");
     return 1;
     }
     if(random(20) > this_player()->query_attrib("ste")){
     write("You clumsily fail in your attempt to backstab.\n");
     this_player()->hit_player(40);
     write("You stab yourself instead.\n");
     write("Guess you weren't stealthy enough.\n");
     tell_object(victim, capitalize(this_player()->query_name())+
     "tries to backstab you, but you catch it in the nick of time.\n");
     say(capitalize(this_player()->query_name())+" tried to backstab "+
     capitalize(str)+" but failed.\n");
     return 1;
     }
   if(!victim->query_npc()) {
   write(capitalize(str)+" can't be attacked by assassin spells.\n");
     return 1;
     }
     damage = this_player()->query_wc() * 2;
     if(this_player()->query_attack() == 0 && this_player()->query_hunted()
       == 0){
       this_player()->spell_object(victim, "backstab", damage, 0);
       write("You stab "+capitalize(str)+" in the back!\n");
       tell_object(victim, capitalize(this_player()->query_name())+
        " stabs you in the back!\n");
       tell_room(environment(this_player()),
      capitalize(this_player()->query_name())+ " stabs "+capitalize(str)+" in the back!\n");
       return 1;
     }
     write("You cannot get behind someone you're already fighting.\n");
      return 1;
}

punish(str){
     string who;
     object victim;
     if(!str){ write("Usage: punish <player>\n");   return 1; }
     victim = present(str, environment(this_player()));
     if(!victim){
       write("That is not here.\n");
       return 1;
     }
     if(!victim->query_interactive()){
       write("That is not a player.\n");
       return 1;
     }
     if(!this_player()->valid_attack(victim)){
       write("You can't attack "+str+".\n");
       return 1;
     }
     victim->add_spell_point(-victim->query_spell_point());
     this_player()->add_spell_point(-this_player()->query_spell_point());
     write("You punish "+str+" severely for his deeds!\n");
     say(this_player()->query_name()+" punishes "+victim->query_name()+" severely!\n");
     return 1;
}

harm(str) {
     object victim;
     if(!str){
     write("Usage: harm <monster>\n");
       return 1;
     }
     if(ok_harm == 0){
       write("You need to rest your finger before casting another harm.\n");
       return 1;
     }
     if(this_player()->query_spell_point() < 50){
        write("You are too weak to harm anyone.\n");
       return 1;
        }
     victim = present(str, environment(this_player()));
     if(!victim){
       write("That player/creature is not here.\n");
       return 1;
     }
     if(guild_quest < 2){
       write("You must be a journeyman assassin to use harm.\n");
       return 1;
     }
     if(this_player()->query_spell_point() < 50){
       write("You are too weak to harm anyone.\n");
       return 1;
     }
   if(victim->query_npc() == 0) {
    write(capitalize(str)+" can't be attacked by assassin spells.\n");
       return 1;
     }
      this_player()->spell_object(victim, "harm", random(60), 30);
     write("You raise the Finger of Death and harm "+capitalize(str)+".\n");
     tell_object(victim, 
       this_player()->query_name()+" raises the Finger of Death against you!\n");
     tell_room(environment(this_player()),
     this_player()->query_name()+" raises the Finger of Death against "+
     capitalize(str)+"!\n");
     ok_harm = 0;
     set_heart_beat(1);
     return 1;
}


rank() {
     write(this_player()->short()+" ("+this_player()->query_level()+")\n");
     write("Hit points: "+this_player()->query_hp()+"\n");
     write("Spell points:  "+this_player()->query_spell_point()+"\n");
     write("Experience: "+this_player()->query_exp()+"\n");
     write("Gold coins: "+this_player()->query_money()+"\n");
     write("Assassin level:  "+query_guild_name()+"\n");
     write("Assassin experience: "+guild_exp+"\n");
     if(plugged == 1) {
     write("Earplugs are in.\n");
     } else
     write("Earplugs are out.\n");
     return 1;
}





spy(str) {
     string who;

     if(guild_quest < 3) {
       write("You must be an master assassin to spy.\n");
       return 1;
     }
     if(!str || sscanf(str, "%s", who) != 1) {
       write("Useage:  spy <player>\n");
       return 1;
     }
     if(this_player()->query_spell_point() < 10) {
       write("You are too low on power.\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     if(find_player(who)->query_invis() > 0) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     if(find_player(who)->query_level() > 20) {
       write("You cannot spy on wizards.\n");
       return 1;
     }
     call_other(this_player(), "add_spell_point", -10);
     write(capitalize(who)+"'s location:\n");
     write(call_other(find_player(who), "look")+"\n");
     return 1;
}

plugs(str) {

     if(!str) {
       write("Usage: earplugs <in/out>\n");
       return 1;
     }
     if(str == "in") {
       if(plugged == 1) {
         write("You already have your plugs in.\n");
         return 1;
       } else
       plugged = 1;
       write("You are now plugged.\n");
       return 1;
     }
     if(str == "out") {
       if(plugged == 0) {
         write("Your earplugs are not in.\n");
         return 1;
       } else
       plugged = 0;
       write("Your earplugs are now out.\n");
       return 1;
     }
}




recruit(str) {
     string who, recruitee;
     int level, level2;
     object ob;

     if(guild_quest < 4) {
       write("You must be a Godfather to recruit.\n");
       return 1;
     }
     if(!str || sscanf(str, "%s", who) != 1) {
       write("Useage:  recruit <player>\n");
       return 1;
     }
     if(!present(find_player(who), environment(this_player()))) {
       write(capitalize(who)+" is not here.\n");
       return 1;
     }
     ob = find_player(who);
     if(ob->query_pl_k() == 0){
     write(capitalize(str)+" must have player killing set to join.\n");
     write("To set player killing, type 'kill_players'...remember that\n");
     write("once it is set, you can't reset it.\n");
     return 1;
     }
  if(ob->query_level() < 4) {
    write("You are not of strong enough stature yet. gain some levels.\n");
  return 1;
     }
if(present("seal", find_player(who)) || present("fangs", find_player(who)) || present("pentagram", find_player(who)) || present("thief guild", find_player(who)) || present("badge", find_player(who))) {
       write(capitalize(who)+" is a already a member of the another guild.\n");
       write("You cannot belong to both guilds at once.  The person you are\n");
       write("Trying to recruit must go to the guild and type 'leave' before\n");
       write("he/she can be recruited.\n");
       return 1;
     }
     recruitee = find_player(who)->query_real_name();
     if(restore_object("players/deathmonger/ASSASSIN/banished"+recruitee)) {
       write("That person has been banished from the Guild of Assassins.\n");
       write("To re-enter the person must petition the Grand Master of Assassins.\n");
       return 1;
     }
     level = this_player()->query_level();
     level2 = find_player(who)->query_level();
     move_object(clone_object("players/deathmonger/ASSASSIN/license"),
       find_player(who));
     find_player(who)->set_guild_exp(1);
     write("You have recruited "+capitalize(who)+" into the Guild of Assassins.\n");
     tell_object(find_player(who), "You have been recruited into the Guild of Assassins!\n");
     tell_object(find_player(who), "Type 'license' for a list of abilities.\n");
     write_file("/players/deathmonger/ASSASSIN/RECRUIT",
          capitalize(this_player()->query_real_name())+"("+
          this_player()->query_level()+") recruited "+
          capitalize(who)+"("+level2+") -> "+ctime(time())+"\n");
     return 1;
}

news() {
     cat("/players/deathmonger/ASSASSIN/news");
     return 1;
}

wizards(){
     cat("/players/deathmonger/ASSASSIN/wizards");
     return 1;
}


list_quest(){
     if(guild_quest == 1){
     write("Bring the greatest weapon of death to the guild, that known as fear!\n");
       return 1;
     }
     if(guild_quest == 2){
       write("Go forth and bring back the horn of the tarrasque.\n");
       return 1;
     }
     if(guild_quest == 3){
   write("Return the mighty sword thorn to the guild. It was rumored\n"+
         "to have been lost in the northern reaches.\n");
   write("This and your donations will get your godfathership.\n");
       return 1;
     }
     if(guild_quest > 3){
       write("You have solved all of the guild quests, mighty one.\n");
       return 1;
     }
}

code(){
     cat("/players/deathmonger/ASSASSIN/code");
     return 1;
}
hitlist() {
     cat("/players/deathmonger/ASSASSIN/hitlist");
     return 1;
}

help_license() {
       cat("/players/deathmonger/ASSASSIN/HELP");
       return 1;
     }
help_license1(){
       cat("/players/deathmonger/ASSASSIN/HELP1");
       return 1;
}


justify(str, len) { return extract(str + "                       ",0,len-1); }
logged_on() {
     object list, guild;
     int i;
     string guild_name, name;
     list = users();
     write("Assassins currently logged on:\n");
write("<########################################################################>\n");
     for (i = 0; i < sizeof(list); i++) {
         guild = present("license",list[i]);
         if(guild) {
            if(list[i]->query_invis() > 0) {
              write("");
            } else {
            guild_name = guild->query_guild_name();
      name = "  "+justify(list[i]->query_level(), 7)+
                 capitalize(list[i]->query_name())+
      " ("+guild_name+")";
    if(guild->query_plugged())
      name += " (earplugged)\n";
    else { name += "\n"; }
     write(name);
            }
          }
     }
write("<########################################################################>\n");
     return 1;
}



escape(){
     string here_realm;
     object here;
     if(this_player()->query_spell_point() < 40){
       write("You are too weak to escape!\n");
       return 1;
     }
     here=environment(this_player());
     here_realm=here->realm();
     if(here_realm == "NT") {
       write("This room is teleport protected.\nYou fail.\n");
       return 1;
     }
     this_player()->add_spell_point(-40);
say(this_player()->query_name()+
    " throws a small black globe and a large\n"+
  "cloud as dark as night fills the area, blinding you!!!\n");
write("You throw a smoke ball and disappear into the darkness\n");
move_object(this_player(),
    "players/deathmonger/ASSASSIN/cenguild");
     return 1;
}

consider(str){
     object target;
     int strength, power;
     string rating;
     target = present(str, environment(this_player()));
     if(!target){
       write("No "+str+" here.\n");
     return 1;
     }
     if(!living(target)){
       write(capitalize(str)+" is not a living thing.\n");
       return 1;
     }
     if(target->query_name() == this_player()->query_name()){
       write("You can't consider yourself.\n");
       return 1;
     }
     write(capitalize(target->query_name())+"\n");
     write("Level: "+target->query_level()+"\n");
     write("Hit points: "+target->query_hp()+"\n");
     if(target->query_interactive())
     write("Money: "+target->query_money()+"\n");
      if(target->query_pl_k())
      write("This player has his player killing set! (Yeah!)\n");
       if(target->query_interactive() && !target->query_pl_k())
      write("This player does not have his player killing set.\n");
      if(present("seal", target))
      write("Member of Mason guild\n");
        if(present("fangs", target))
      write("Member of Vampire guild\n");
      if(present("license", target))
      write("A fellow assassin (friend)\n");
      if(present("robes", target))
       write("Member of the Clerics guild\n");
      if(present("pentagram", target))
         write("Member of the alchemists guild\n");
      if(present("thief guild", target))
          write("A THIEF!!! BEWARE!!!!\n");
      if(present("badge", target)) 
          write("A doppleganger member, weird!@#$%$#\n");
     this_player()->add_spell_point(-40);
     return 1;
}
assassin_cant(str) {
     object ob, guild, assassin;
     int i;
     string me;

     me = this_player();
     assassin = this_object();
     if(!str) {
       write("Tell assassins what?\n");
       return 1;
     }
     ob = users();
     for(i = 0; i < sizeof(ob); i++) {
        guild = present("license", ob[i]);
        if(guild && guild->query_plugged() == 0){
          if(guild->query_plugged() == 1) { return 1; }
           tell_object(ob[i], me->query_name()+")))> "+str+"\n");
        }
     }
     return 1;
}


contract(str){
     object contractor, victim, contract, license;
     string who1, who2;
     me = this_player();

     license = present("license", this_player());
     if(license->query_guild_quest() < 2){
       write("You must be a journeyman assassin to contract for assassination.\n");
       return 1;
     }
     if(sscanf(str, "%s %s", who1, who2) == 2){
       contract = clone_object("players/deathmonger/ASSASSIN/contract");
       contractor = find_player(who1);
       victim = find_player(who2);
       tell_object(contractor, "A demon arrives bearing a contract from a\n");
       tell_object(contractor, "certain assassin willing to take up your\n");
     tell_object(contractor, "request.  The demon gives you the contract,\n");
       tell_object(contractor, "and awaits your response.\n");
       write("A demon flies away carrying your contract to the contractor.\n");
       contract->set_victim_level(victim->query_level());
       contract->set_assassin(this_player()->query_name());
       contract->set_victim(capitalize(who2));
       contract->set_contractor(capitalize(who1));
       move_object(contract, contractor);
       return 1;
}
}

disguise(str){
     int level;
     string title;
     if(sscanf(str, "%d", level) == 1){
     if(!str){
       write("You can't have that title.\n");
       return 1;
     }
     gender = this_player()->query_gender();
     if(gender == "male" || gender == "creature"){
     if(level == 1) {title = "the utter novice"; }
     if(level == 2) {title = "the simple wanderer";}
     if(level == 3) {title = "the lowrank ranger";}
     if(level == 4){title = "the master ranger";}
     if(level == 5){title = "the small fighter";}
     if(level == 6){title = "the experienced fighter";}
     if(level == 7){title = "the small adventurer";}
     if(level == 8){title = "the experienced adventurer";}
     if(level == 9){title = "the great adventurer";}
     if(level == 10){title = "the warrior";}
     if(level == 11){title = "the champion";}
     if(level == 12){title = "the conjuror";}
     if(level == 13){title = "the apprentice magician";}
     if(level == 14){title = "the magician";}
     if(level == 15){title = "the enchanter";}
     if(level == 16){title = "the warlock";}
     if(level == 17){title = "the apprentice sorcerer";}
     if(level == 18){title = "the master sorcerer";}
     if(level == 19){title = "the grand master sorcerer";}
}
     if(gender == "female"){
     if(level == 1){title = "the utter novice";}
     if(level == 2){title = "the simple wanderer";}
     if(level == 3){title = "the lowrank ranger";}
     if(level == 4){title = "the master ranger";}
     if(level == 5){title = "the siren";}
     if(level == 6){title = "the charming siren";}
     if(level == 7){title = "the small adventuress";}
     if(level == 8){title = "the experience adventuress";}
     if(level == 9){title = "the great adventuress";}
     if(level == 10){title = "the amazon";}
     if(level == 11){title = "the deadly amazon";}
     if(level == 12){title = "the conjuress";}
     if(level == 13){title = "the apprentice magicienne";}
     if(level == 14){title = "the magicienne";}
     if(level == 15){title = "the enchantress";}
     if(level == 16){title = "the witch";}
     if(level == 17){title = "the apprentice sorceress";}
     if(level == 18){title = "the master sorceress";}
     if(level == 19){title = "the grand master sorceress";}
}
    call_other(this_player(), "set_title", title);
     write("You are now: "+title+".\n");
}
return 1;
}

guild_title() {
  call_other(this_player(), "set_title", guild_name);
  write("Your guild title is now out there for everyone to see.\n");
              }
echo(str){
     say(str+"\n");
     write("You echoed: "+str+"\n");
     this_player()->add_spell_point(-7);
     return 1;
}

stalk(str){
     object assassin, victim;
     assassin = present("license", this_player());
   if(assassin->query_guild_quest() < 2) {
     write("you cannot stalk someone until you are a journeyman\n");
     return 1;
                       }
     if(str == "off"){
       write("You are no longer stalking "+stalkee->query_name()+".\n");
       set_heart_beat(0);
       stalk = 0;
       return 1;
     }
     stalkee = find_player(str);
       if(!present(str, environment(this_player()))){
         write("That is not here.\n");
         return 1;
         }
     if(stalkee->query_level() > 20){
       write("You can't stalk wizards.\n");
       return 1;
     }
     if(!str){
       write("Stalk who?\n");
       return 1;
     }
     if(this_player()->query_spell_point() < 15){
       write("You are too low on power to stalk.\n");
       return 1;
     }
     if(!str){
       write("Usage: stalk <who> or stalk off\n");
       return 1;
     }
     if(stalk == 1){
       write("You are already stalking someone.\n");
       return 1;
     }
     else {
     write("You begin stalking "+stalkee->query_name()+".\n");
     stalk = 1;
     this_player()->add_spell_point(-15);
     set_heart_beat(1);
     return 1;
}
}

heart_beat(){
     object bro;
     ok_harm = 1;
     if(monitor == 1){
     bro = environment(this_object());
       tell_object(bro, "HP["+bro->query_hp()+"]/("+bro->query_mhp()+")  SP["+
     bro->query_spell_point()+"]/("+bro->query_msp()+")\n");
     }
     if(stalk == 1){
      if(environment(stalkee) != environment(environment(this_object()))){
      move_object(environment(this_object()), environment(stalkee));
    tell_object(environment(this_object()),
     "You continue stalking "+stalkee->query_name()+".\n");
         command("look", environment(this_object()));
         }
      return 1;
      }
    else write("Arrgh!\n");
     return 1;
}


peer(str){
     object lame;
   if(this_player()->query_spell_point() < 15) {
      write("You do not have enough spell points for this task.\n");
      return 1;
   }
      lame = clone_object("players/deathmonger/ASSASSIN/lame");
     move_object(lame, environment(this_player()));
     command(str, this_player());
     command("look", this_player());
     move_object(this_player(), environment(lame));
     destruct(lame);
     this_player()->add_spell_point(-15);
     return 1;
}
sneak(str) {
     object here, dest, ob;
     string here_realm, dest_realm;
     if(!str) {
       write("Usage: sneak <player>\n");
       return 1;
     }

     if(guild_quest < 2){
       write("You must be a journeyman assassin to sneak.\n");
       return 1;
     }
     dest=environment(find_player(str));
     here=environment(this_player());
     ob=find_player(str);
   if(!ob) {
      write("That person is not playing right now.\n");
      return 1;
           }
     if(this_player()->query_spell_point() < 75){
       write("You are too low on power.\n");
       return 1;
      }
     if(ob->query_level() > 20){
       write("You can never sneak up on a wizard.\n");
      return 1;
     }
     here_realm=here->realm();
     dest_realm=dest->realm();
     if(dest_realm == "NT" || here_realm == "NT") {
       write("Your destination or the room you are in is teleport\n");
       write("protected.\nYou fail.\n");
       return 1;
     }
     this_player()->add_spell_point(-75);
     move_object(this_player(), dest);
     write("ok\n");
     return 1;
}
