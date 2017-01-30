inherit "obj/treasure";
string src,dst;
object ob;
int x;

reset(arg)
{
   if (arg) return;
}

id(str) { return str == "ring" || str == "signet ring" || str == "signet_ring_object"; }

extra_look() {
   return environment()->query_name() + " is a member of the Succubus Club";
}

short() { return "Signet Ring"; }

long() {
   write("This is a signet ring of the Succubus Club.\n");
   write("Use the command 'stell' to talk to all other members,\n");
   write("and the command 'swho' to see what members are on.   \n");
   write("-----------------------------------------------------\n");
   write("    Code by Merlyn, Additions by Rumplemintz.        \n");
}

init()
{
   add_action("stell", "stell");
   add_action("swho", "swho");
}

drop() { return 1; }

stell(str)
{
  int x;
  object ob;
  if(!str) return;
  ob=users();
   for (x = 0; x < sizeof(ob); x++) {
      if (present("signet_ring_object",ob[x])) {
         tell_object(ob[x],"<" + this_player()->query_name() + "> " + str + "\n");
        }
   }
    return(1);
}
swho()
{
   object list,guild;
   string loc,name,tab,muff;
   int invis,i,level;
   list = users();
   write("      ________________________________________________________________________\n");
   write("     '`                                                                       `\n");
   write("    |  |                       --== The Succubi ==--                           |\n");
   write("    |`'_______________________________________________________________________'\n");
   write("    |                                                                        |\n");
   for(i=0;i<sizeof(list);i++){
      if(present("signet_ring_object",list[i])){
         guild = present("signet_ring_object",list[i]);
         if(guild->query_muff() == 1){muff = "  muff";}
         else{muff ="  ";}
         name = capitalize(list[i]->query_real_name());
         if(environment(list[i])){
            loc=environment(list[i])->short();
         }
         else{
            loc = "Unknown";
         }
         level = list[i]->query_level();
         invis = list[i]->query_invis();
         if(invis == 18){
            if(this_player()->query_level() > level -1){
              tab = "\t\t";
	       if(strlen(name)>0) tab="\t\t\t";
	       if(strlen(name)>7) tab="\t";
	       write("    | "+name+tab+level+"\t"+muff+"\t"+loc+"\n");
            }
         }
         if(invis == 0){
            tab = "\t\t";
            if(strlen(name) > 7){tab = "\t";}
	    write("    | "+name+tab+level+"\t"+muff+"\t"+loc+tab+"\n");
          }
       }
    }
   write("  '`|                                                                        |\n");
   write(" |  |                     Coded by Merlyn and Rumplemintz                    |\n");
   write("  `'-------------------------------------------------------------------------'\n");
   return 1;
}

query_auto_load() { return"/players/rumplemintz/closed/signet.c:0"; }
