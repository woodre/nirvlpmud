int main() {
   write("nwho - List Newbie Helpers.\n");
   write("nsummon - Summon a newbie.\n");
   write("nteleport - Teleport to a newbie.\n");
   write("nrepair - Repair a newbie's weapon.\n");
   write("nsharpen - Sharpen a newbie's weapon.\n");
   write("npeace - Calm a room a newbie is in.\n");
   write("nresurrect - Resurrect a newbie.\n");
   write("nidea - Send an idea to the Developers about newbie related issues.\n");
   write("\n");
   write("nupdate refreshes your newbie helper object.\n");
   write("\n");
   if((string)this_player()->query_real_name()=="lacar") {
      write("You may also \"nadd\" someone as a Newbie helper.\n"+
         "or \"nkick\" someone out.\n");
   }
   else write("You may \"nleave\" and quit as a Newbie helper.\n");
   write("nt to talk on the guild line.\n");
   return 1;
}
