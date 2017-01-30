#define PAD 30
do_hsc() {
  string pkstr;
  write("\n"+"[--------------------------------------------------------------------------]\n");
  write(TP->short()+"\n\n");
  write(pad("Level: "+TP->query_level()+"+"+TP->query_extra_level(),PAD));
  write("Stamina: "+TP->query_attrib("str")+"\n");

  write(pad("Experience: "+TP->query_exp(),PAD));
  write("Magic: "+TP->query_attrib("mag")+"\n");

  write(pad("Rank: "+present(GUILD_ID,TP)->query_rank(),PAD));
  write("Strength: "+TP->query_attrib("str")+"\n");

  write(pad("Guild XP: "+TP->query_guild_exp(),PAD));
  write("Intel: "+TP->query_attrib("int")+"\n");

  write(pad("HP: "+TP->query_hp()+"/"+TP->query_mhp(),PAD));
  write("Will: "+TP->query_attrib("wil")+"\n");

  write(pad("SP: "+TP->query_spell_point()+"/"+TP->query_msp(),PAD));
  write("Piety: "+TP->query_attrib("pie")+"\n");

  write(pad("Coins: "+TP->query_money(),PAD));
  write("Stealth: "+TP->query_attrib("ste")+"\n");

  switch(this_player()->query_pl_k()) 
  {
    case 0: pkstr="No";break;
    case 1: pkstr="Yes";break;
    case 2: pkstr="Spar";break;
    case 3: pkstr="Pk/Spar";break;
    default: pkstr="Other";break;
  }

  write(pad("Pk: "+pkstr,PAD));
  write("Luck: "+TP->query_attrib("luc")+"\n");

  write("Karma: "+(string)MYOB->query_karma_string()+"\n");

  write("\n");

  write("Intox: "+(this_player()->query_intoxination() * 100 / (this_player()->query_level()+3 )) );
  write("\tStuffed: "+ (this_player()->query_stuffed() * 100 / (this_player()->query_level() * 8)) );
  write("\tSoaked: "+(this_player()->query_soaked() * 100 / (this_player()->query_level() * 8))+"\n");
  write("[--------------------------------------------------------------------------]\n");
  return 1;
}

