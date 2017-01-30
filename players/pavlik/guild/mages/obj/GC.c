int exp, level, guild_rank, guild_exp;
int donation, balance, divd;
int conjuration, enchantment, evocation;
int illusion, necromancy;
string title;

reset(arg){
  if(arg)
   return;
}

id(str){ return str == "GC Object"; }
short(){ return "GC Object"; }
long(){ write("GC Object.\n"); }
get(){ return 1; }
drop(){ return 1; }

mage_check(str){
  if(!restore_object("/pfiles/"+str)){
    write(capitalize(str)+" does not exist.\n");
    return 1;
    }
  if(!restore_object("/players/pavlik/mages/players/bakup/"+str)){
    write(capitalize(str)+" is not registered with the Guild.\n");
    return 1;
    }
  write(capitalize(str)+" "+title+" : \n");
  write("Level: "+level+"     Exp: "+exp+"\n");
  write("Guild Rank: "+guild_rank+"    Guild Exp: "+guild_exp+"\n");
  write("Donations: "+donation+"\n");
  write("Conj: "+conjuration+"  Ench: "+enchantment+"  Evoc:"+evocation+"\n");
  write("Ills: "+illusion+"  Necr: "+necromancy+"\n");
  write("\n");
  return 1;
}
