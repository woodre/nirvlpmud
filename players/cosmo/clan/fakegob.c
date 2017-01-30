/* Fake Symbiote Guild Object for Testing Clans */

#define CLANMASTER "/players/cosmo/clan/clanmaster.c"

id(str){ return str == "fake_object" || str == "object"; }
short(){ return "NOT a Venom object"; }
long(){
  write("This is a fake Symbiote guild object for testing the Clans.\n"+
        "The function in this object should be incorporated into the\n"+
        "the actual guild object, once the clans are finished and approved.\n"+
        "A Symbiote guild member would use 'make_clan <name>' to initiate\n"+
        "a new clan.\n\n");
  return 1;
}

init(){
  if(!environment()) return;
  if(this_player()->query_level() > 9) add_action("StartClan","make_clan");
}

/*  Should add some checks to make sure str is valid */
StartClan(str){ return CLANMASTER->ClanStart(str); }
