clean(str) {
object ob, shit;
if (str == "here") {
ob = first_inventory(environment(USER));
while(ob) {
shit = next_inventory(ob);
if (!ob->is_player()) {
tell_room(environment(ob),ob->short()+" explodes into tiny bits!\n");
destruct(ob);
        }
ob = shit;
      }
return 1;
}
}
