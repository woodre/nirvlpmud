short() { return "The Landing Lounge"; }
long() {
  write("This is the entry way to the Druid guild.\n"+
        "The guild isn't open yet, but it's comin along\n"+
        "quicker than I thought. If you'd like to see me\n"+
        "get my ass in gear, tell me about it on the board.\n"+
        "       ----Rumplemintz (Tha Shiznit)\n"+
        "Obvious Exits: northeast and southwest.\n");
  return 1;
}
reset(arg) {
  if (arg) return;
  set_light(1);
}
northeast() {
  this_player()->move_player("northeast#/players/rumplemintz/room/glanding");
  return 1;
}
southwest() {
  if(!this_player()->query_guild_name()=="druid"){
    if(!this_player()->query_npc()) {
      write("You are not a member of the Druid's guild. You cannot enter that room.\n");
      return 1;
    }
  }
  this_player()->move_player("southwest#/players/rumplemintz/guild/guild_hall");
  return 1;
}
init() {
  if(!present("board"))
    move_object(clone_object("players/rumplemintz/guild/DruidBoard"), this_object());
  add_action("southwest","southwest");
  add_action("southwest","sw",1);
  add_action("unjoin","unjoin");
  add_action("join","join");
  add_action("advance","advance");
  add_action("list","list");
  add_action("swap","swap");
  add_action("register","register");
  add_action("northeast","northeast");
  add_action("northeast","ne",1);
  add_action("rejoin","rejoin");
  add_action("cost","cost");
}

list () {
  write("          Commands you can do:\n"+
      "          -----------------------------------------------------\n"+
      "          Cost ..... Check the costs in coins of advancing\n"+
      "          Join ..... Join the guild\n"+
      "          List ..... This menu\n"+
      "          Register . Register your name with the guild\n"+
      "          Rejoin ... Rejoin the guild, if mistletoe is screwed\n"+
      "          Swap ..... Swap <x> experience for <x> guild experience\n"+
      "          Unjoin ... Unjoin the guild (loosing all guild rank!)\n"+
      "          ------------------------------------------------\n\n");

return 1; }
join() {
   object mist;
   if(this_player()->query_npc()) {
    write("You are not a player! Bugger off!\n");
    return 1;
  }
   if(present("mrobe", this_player()) ||
      present("fangs", this_player()) ||
      present("life", this_player()) ||
      present("medal", this_player()) ||
      (this_player()->query_guild_exp() > 0) ||
      present("books", this_player())){
      write("You have already joined a Guild.\n");
      return 1;
    }
    if(present("Dguild", this_player())){
      write("You are already a member.\n");
      return 1;
    }
    if(this_player()->query_level() < 3) {
       write("You must be level 3 to join a guild.\n");
       return 1;
    }
  write("You have just joined the Druid guild!!\n");
  mist = clone_object("/players/rumplemintz/guild/mistletoe");
  move_object(mist,this_player());
  write_file("/players/rumplemintz/guild/joined",capitalize(this_player()->query_real_name())+" just joined the guild.\nThe time is: "+ctime(time())+".\n-------------------\n");
  this_player()->add_guild_exp(1);
  this_player()->set_guild_name("druid");
  this_player()->add_guild_rank(1);
  tell_em("joined");
  return 1; 
}

scrap(str) {
  string ln,it,what;
  int j,i;
  if(!str) what="unjoined";
  else what=str;
  i=0;
  j=1;
  ln=read_file("/players/rumplemintz/guild/register",j);
  while(ln) {
    if(ln==this_player()->query_real_name()+"\n") {
      i=1;
     
write_file("/players/rumplemintz/guild/reg.tmp",this_player()->query_real_name()+"  ->  "+what+"\n");
    } else write_file("/players/rumplemintz/guild/reg.tmp",ln);
    j++;
    ln=read_file("/players/rumplemintz/guild/register",j);
  }
  if(i) {
    rm("/players/rumplemintz/guild/register");
    cp("/players/rumplemintz/guild/reg.tmp",
       "/players/rumplemintz/guild/register");
    rm("/players/rumplemintz/guild/reg.tmp");
  } else
    write_file("/players/rumplemintz/guild/register",
               this_player()->query_real_name()+"  ->  "+what+"---FRIED!\n");
  return 1;
}

unjoin() {
  object mist;
  int exp,minus;
  if(!present("Dguild", this_player())) {
    write("You have to be a Druid to unjoin the guild.\n");
    return 1;
  }
  tell_em("unjoined");
  write_file("/players/rumplemintz/guild/unguild",capitalize(this_player()->query_real_name())+" had "+this_player()->query_guild_exp()+" guild exp when he unjoined.\nThe time is: "+ctime(time())+"\n------------------------------\n");
  exp = this_player()->query_exp();
  minus = exp/6;
  this_player()->add_exp(-minus);
  mist = present("Dguild",this_player());
  destruct(mist);
  this_player()->set_title("Druid Backstaber!");
  this_player()->set_al_title("Watch You Back!!");
  this_player()->set_guild_name(0);
  this_player()->add_guild_exp(-this_player()->query_guild_exp());
  this_player()->add_guild_rank(-this_player()->query_guild_rank());
  write("You have just left the Druid guild.\n");
  return 1;
}

tell_em(str) {
  string people;
  int n;
  people = users();
  for(n=0;n<sizeof(people);n++) {
    if(present("Dguild",people[n])) {
      tell_object(people[n],"[Guild Master Druid]: "+capitalize(this_player()->query_real_name())+" just "+str+" the guild!\n");
    }
  }
}

cost() {
  if(!present("Dguild",this_player())) {
    write("You are not a member of the guild yet...type \"join\"\n");
    return 1;
  }
write(
"           Costs to advance in the guild (in exp)\n"+
"---------------------------------------------------------------\n"+
"Level 1 ..................................................Free\n"+
"Level 2 ............... First Task ...................... 5000\n"+
"Level 3 ............... Second Task .................... 15000\n"+
"Level 4 ............... Third Task ..................... 30000\n"+
"Level 5 ............... Fourth Task .................... 50000\n"+
"Level 6 ............... Fifth Task ..................... 75000\n"+
"Level 7 ............... Sixth Task .................... 105000\n"+
"Level 8 ............... Seventh Task .................. 140000\n"+
"Level 9 ............... Eigth Task .................... 180000\n"+
"Level 10 .............. Ninth Task .................... 215000\n"+
"Level 11 .............. Tenth Task .................... 265000\n"+
"Level 12 .............. Eleventh Task ................. 320000\n"+
"Level 13 .............. Twelvth Task .................. 380000\n"+
"Level 14 .............. Thirteenth Task ............... 450000\n"+
"Level 15 & up ......... Challenge the Existing Druid at that lvl\n"+
"----------------------------------------------------------------\n"+
"  You currently have:     "+this_player()->query_guild_exp()+" exp.\n\n"+"\n");
  return 1;
}

swap(str) {
  int a,x,y,z;
  if(!present("Dguild",this_player())) {
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
  write_file("/players/rumplemintz/guild/swaps",capitalize(this_player()->query_real_name())+" just swapped "+x+" exp.\nThe time is: "+ctime(time())+"\n------------------------------\n");
  this_player()->add_exp(-x);
  this_player()->add_guild_exp(x);
  write("You Exchange some Xp for some Guild Xp.\n");
  return 1;
}

rejoin() {
  object per;
  string ln;
  int i,j;
  per=this_player();
  if(present("Dguild",per)) {
    write("You do not need to rejoin.\n");
    return 1;
  }
/*
  i=0;
  j=1;
  ln=read_file("/players/rumplemintz/guild/register",j);
  while(ln && !i) {
    j++;
    ln=read_file("/players/rumplemintz/guild/register",j);
    if(ln==per->query_real_name()+"\n") i=1;
  }
*/
  if(!(this_player()->query_guild_name()=="druid")) {
    write("You were not found in the guild's register.\n");
  } else
  { write("Your name was found in the register. Management stresses its\n");
    write("appologies.\n");
    move_object(clone_object("/players/rumplemintz/guild/mistletoe"),per);
    tell_em("rejoined");
  }
  return 1;
}


advance() {
int x, y, z;
  if(!present("Dguild",this_player())) {
    write("You are not a member...type \"join\"\n");
  return 1;
}
x = this_player()->query_guild_exp();
y = this_player()->query_guild_rank();
if(y==1) z = 4999;
else if(y==2) z = 14999;
else if(y==3) z = 29999;
else if(y==4) z = 49999;
else if(y==5) z = 74999;
else if(y==6) z = 104999;
else if(y==7) z = 139999;
else if(y==8) z = 179999;
else if(y==9) z = 214999;
else if(y==10) z = 264999;
else if(y==11) z = 319999;
else if(y==12) z = 379999;
else if(y==13) z = 449999;
if(x>z) {
  if(y<14) {
    write("You are now level "+(y+1)+" in the guild!\n");
      write_file("/playres/rumplemintz/closed/LOGS/advanced",capitalize(this_player()->query_real_name())+" just made level "+(y+1)+" in the guild.\nThe time is: "+ctime(time())+"\n----------------------------------\n");
    tell_em("advanced in");
    this_player()->add_guild_rank(1);
    } else {
    write("You need to challenge for those levels in the guild.\n");
   }
  } else {
    write("You do not have enough guild exp on account to advance yet.\n");
  }
  return 1;
}
register() {
  int i,j;
  string ln;
  if(!present("Dguild",this_player())) {
    write("You must first join the guild.\n");
    return 1;
  }
  i=0;
  j=1;
  ln=read_file("/players/rumplemintz/guild/register",j);
  while(ln && i==0) {
    j++;
    ln=read_file("/players/rumplemintz/guild/register",j);
    if(ln==this_player()->query_real_name()+"\n") i=1;
  }
  if(!i) {
    write_file("/players/rumplemintz/guild/register",this_player()->query_real_name()+"\n");
    write("You name has been added to the register.\n");
  }
  else {
    write("Your name was already in the register.\n");
  }
  return 1;
}
