short() { return "The Doppleganger Barbarian's Faction"; }
 
long() {
  write("You have entered the Doppleganger Barbarian's Faction.\n"+
          "Type 'list' for a list of commands.\n"+
          "  You can exit to the east or west.\n");
  return 1;
}
 
reset(arg) {
  if (arg) return;
  set_light(1);
}
 
east() {
  this_player()->move_player("east#/players/grimm/rooms/haphaz_a13");
  return 1;
}
 
west() {
  if(!(present("Dopple-Barbarian",this_player()))) {
    write("You are not a member of the Barbarian's Faction. You cannot enter that room.\n");
    return 1;
  }
  this_player()->move_player("west#/players/grimm/closed/obj/badge_stuff/b_pr");
  return 1;
}
 
init() {
  add_action("west","west");
  add_action("west","w",1);
  add_action("unjoin","unjoin");
  add_action("join","join");
  add_action("list","list");
  add_action("swap","swap");
  add_action("east","east");
  add_action("east","e",1);
  add_action("cost","cost");
  add_action("advance","advance");
}
 
list () {
  write("          Commands you can do:\n"+
        "          -----------------------------------------------------\n"+
        "          Advance .. Advance your level in the faction\n"+
        "          Cost ..... Check the costs in coins of advancing\n"+
        "          Join ..... Join the faction\n"+
        "          List ..... This menu\n"+
        "          Swap ..... Swap <x> experience for <x> faction experience\n"+
        "          Unjoin ... Unjoin the faction (loosing all faction rank!)\n"+
        "          -----------------------------------------------------\n\n");
return 1; }
 
join() {
  object badge;

  if (this_player()->query_npc()) {
    write("You are not a player! Bugger off!\n");
    return 1;
  }
  if (present("Dopple-Barbarian", this_player())) {
    write("You are already in the faction.\n");
    return 1;
  }
  if (!this_player()->query_guild_name()=="doppleganger" &&
      this_player()->query_guild_rank() < 9) {
    write("You must be guild level 9 in the Doppleganger's Guild to join.\n");
    return 1;
  }
  if (present("Dopple-Faction", this_player())) {
    write("You are already a member of a faction.\n");
    return 1;
  }
  if (this_player()->query_guild_exp() < 20000) {
    write("You must first prove yourself worthy.\n" +
          "You must ask the Sage of Reeseport for help by typing:\n"+
          "\"judge me worthy\"\nIn the Sage's house.\n");
    return 1;
  }
  write("You have just joined the Barbarian Faction!!!\n");
  if (this_player()->query_guild_rank() < 10)
    this_player()->add_guild_rank(1);
  badge = clone_object("/players/grimm/closed/obj/barb");
  move_object(badge, this_player());
   write_file("/players/grimm/closed/LOGS/barb",capitalize(this_player()->query_real_name())+" just joined the guild.\nThe time is: "+ctime(time())+".\n-------------------\n");
  tell_em("joined");
return 1; 
}
 
unjoin() {
object badge;
int exp,minus;
if(!present("Dopple-Barbarian", this_player())) {
  write("You have to be a member of the faction to unjoin it.\n");
  return 1;
}
tell_em("unjoined");
write_file("/players/grimm/closed/LOGS/unbarb",capitalize(this_player()->query_real_name())+" had "+this_player()->query_guild_exp()+" guild exp when he unjoined.\nThe time is: "+ctime(time())+"\n------------------------------\n");
badge = present("Dopple-Barbarian",this_player());
destruct(badge);
this_player()->add_guild_exp(-this_player()->query_guild_exp());
this_player()->add_guild_exp(180000);
this_player()->add_guild_rank(-this_player()->query_guild_rank());
this_player()->add_guild_rank(9);
write("You have just unjoined the Barbarian's Faction.\n");
return 1;
}
 
tell_em(str) {
string people;
int n;
people = users();
for(n=0;n<sizeof(people);n++) {
  if(present("Dopple-Barbarian",people[n])) {
    tell_object(people[n],"{Grimm's Assistant}: "+capitalize(this_player()->query_real_name())+" just "+str+" the faction!\n");
  }
}
}
 
cost() {
if(!present("Dopple-Barbarian",this_player())) {
  write("You are not a member of the faction yet...type \"join\"\n");
  return 1;
}
write(
"                        Costs to advance in the faction (in exp)\n"+
"                        ----------------------------------------\n"+
"                        Level 10 ......................... Given\n"+
"                        Level 11 ........................ 240000\n"+
"                        Level 12 ........................ 280000\n"+
"                        Level 13 ........................ 320000\n"+
"                        Level 14 ........................ 360000\n"+
"                        Level 15 ........................ 400000\n"+
"                        ----------------------------------------\n"+
"                        You currently have:       "+
                         this_player()->query_guild_exp()+" exp.\n\n"+"\n");
return 1;
}
 
swap(str) {
int a,x,y,z;
if(!present("Dopple-Barbarian",this_player())) {
  write("You are not a member...type \"join\"\n");
  return 1;
}
if(!str) {
  write("How much do you want to swap?\n");
  return 1;
}
sscanf(str,"%d",x);
y=this_player()->query_exp();
z=this_player()->query_level();
if(z==1) a=0;
else if(z==2) a=1014;
else if(z==3) a=1771;
else if(z==4) a=2332;
else if(z==5) a=5885;
else if(z==6) a=12812;
else if(z==7) a=26662;
else if(z==8) a=39993;
else if(z==9) a=59995;
else if(z==10) a=90000;
else if(z==11) a=134998;
else if(z==12) a=195591;
else if(z==13) a=295592;
else if(z==14) a=492294;
else if(z==15) a=620026;
else if(z==16) a=820028;
else if(z==17) a=1040028;
else if(z==18) a=1367106;
else if(z==19) a=2000000;
else a=0;
if(y-x<a) {
  write("You do not have enough exp to swap that much.\n"+
        "You may swap a total of "+(y-a)+".\n");
  return 1;
}
if (x < 1) {
   write("You may not sway negative exp.\n");
   return 1;
}
write_file("/players/grimm/closed/LOGS/barbswaps",capitalize(this_player()->query_real_name())+" just swapped "+x+" exp.\nThe time is: "+ctime(time())+"\n-----------------------\n");
this_player()->add_exp(-x);
this_player()->add_guild_exp(x);
write("Thank you for using Dopplerz 'R Us Franchised Swapping Credit Union.\n");
return 1;
}
 
advance() {
int x, y, z;
if(!present("Dopple-Barbarian",this_player())) {
  write("You are not a member...type \"join\"\n");
  return 1;
}
x = this_player()->query_guild_exp();
y = this_player()->query_guild_rank();
if(y==10) z = 239999;
else if(y==11) z = 279999;
else if(y==12) z = 319999;
else if(y==13) z = 359999;
else if(y==14) z = 399999;
if(x>z) {
  if(y<15) {
    write("You are now level "+(y+1)+" in the faction!\n");
     write_file("/players/grimm/closed/LOGS/barbadvanced",capitalize(this_player()->query_real_name())+" just made level "+(y+1)+" in the faction.\nThe time is: "+ctime(time())+"\n--------------------------------------\n");
    tell_em("advanced in");
    this_player()->add_guild_rank(1);
  } else {
    write("You are the highest level possible in the faction.\n");
  }
} else {
  write("You do not have enough exp on account to advance yet.\n");
}
return 1;
}
