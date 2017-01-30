reset_target(str) {
object ob;
if (!str) {
write ("Syntax: reset <item> or <here>\n");
return 1;
          }

if (str == "here") {
ob = environment(this_player());
write ("Resetting "+object_name(environment(this_player()))+".\n");
ob->reset(1);
return 1;
                   }
ob = present(str,this_player());
if (!ob) ob = present(str,environment(this_player()));
write ("Resetting "+ob->short()+" : ( "+object_name(ob)+" )\n");
ob->reset(1);
return 1;
}
