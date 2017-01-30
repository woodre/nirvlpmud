/*------------MONK STAT OBJECT------------------------*/
#define DIR "players/hawkeye/closed/monk/PLAYERS/"+this_player()->query_real_name()
int mkick,chop,blast,flame,hurl,cash,lightning,tornado,staff;

reset() {
mkick = 0;
chop = 0;
flame = 0;
hurl = 0;
tornado = 0;
lightning = 0;
cash = 0;
blast = 0;
staff = 0;
}
id(str) { return str == "becca";}
query_tornado() { return tornado; }
query_hurl() { return hurl; }
query_cash() { return cash; }
query_mkick() { return mkick;}
query_lightning() { return lightning;}
query_chop() { return chop;}
query_staff() {return staff;}
query_blast() {return blast;}
query_flame() { return flame; }

query_stat(str) {
 if(str == "mkick") 
   return mkick;
if(str == "lightning") 
    return lightning;
if(str == "chop") 
    return chop;
if(str == "staff") 
    return staff;
if(str == "blast") 
    return blast;
if(str == "flame")
    return flame;
if(str == "tornado")
    return tornado;
if(str == "hurl")
    return hurl;
if(str == "cash")
    return cash;
else return 0;
}
init_arg(arg) {
    restore_object(DIR);
write("Restoring Guild Stats....\n");
}
save_stats() {
save_object(DIR);
write("Guild Stats Saving.......\n");
write("Done.\n");
return 1;
}
save_stats();

