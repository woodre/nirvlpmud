#define PLAYERNAME "gaston"

reset()
 {
    do_lockdown();
 }

do_lockdown()
{
    object ob;
    ob=find_player(PLAYERNAME);

    if(ob)
      {
        ob->save_me();
        destruct(ob);
      }  
    remove_call_out("do_lockdown");
    call_out("do_lockdown",1);
}
