/*
 *  Protect.h
 *  Mob Graft Ability
 */

protect_cmd(string str){
     object ob;

     if(!str){
        notify_fail("Protect who?\n");
        return 0;
     }
     ob=find_player(str);
     if(!ob){
        notify_fail("You may only protect a player!\n");
        return 0;
     }
     if(!find_graft(ob)){ return 0; }
     move_object(clone_object("/players/languilen/guild/mob/obj/protect.c"), ob);
     write(capitalize(str)+" is now under your protection.\n");
     present("mob_protect", ob)->protect_timer(10);
     return 1;
}
