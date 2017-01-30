#include "/players/jenny/define.h"
main(string name) {
    object ob;
    if(TPL < 40) {write("Fuck you.  You're not a wiz.\n"); return 1; }
if(!name) {notify_fail("huh?\n"); return 0; }
    ob = find_living(name);
        if (!ob) {
        write("They are not here.\n");
        return 1; }
      ob->set_guild_name(0);
      ob->add_guild_exp(-ob->query_guild_exp());
ob->set_home("/room/church.c");
      ob->add_guild_rank(-ob->query_guild_rank());
   ob->set_guild_file(0);
          ob->reset(1);
          command("save",ob);
          write("Ok, he should be out.\n");
   tell_object(ob,BOLD+BLU+"\t\t...you have been deguilded by "+TPN+"\n"+NORM);
return 1; }
