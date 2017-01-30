strip(str) {
             object ob, target;
             if (!str) return 0;
             target = find_living(str);
             if (str == "me") target = this_player();
             if (str == "here") target = environment(this_player());
             if (!target) {
                            write ("There is no such living creature.\n");
                            return 1;
                          }
             write ("Inventory of ");
             if (str == "here") write (target->short()+" : ");
             if (str != "here") write (capitalize(target->query_real_name())+" : ");
             write ("( "+object_name(target)+" )\n");
             write ("\n");
             ob = first_inventory(target);
    while(ob) {
                if (ob->short())
                write (ob->short()+" : ("+object_name(ob)+")\n");
  else
write ("Invisible Object : ("+object_name(ob)+")\n");
  ob = next_inventory(ob);
    }
return 1;
}
