/*
 *  Shoot.h
 *  Mob G-Wep Ability
 */

shoot(str){
     int    dam;
     object ob;

     dam = (random(20) + 5);
     if (!str && !ATT) {
        write("Who do you want to shoot at?\n");
        return 1;
     }
     if (!str && ATT) {
        str = ATT->query_real_name();
     }
     ob = present(str, ENVTP);
     if (!ob) {
        write(capitalize(str) + "is not here.\n");
        return 1;
     }
     if (!living(ob)) {
        write("That would be a waste of a good bullet!\n");
        return 1;
     }
     write("You take aim and squeeze off a shot at " + ob->query_real_name() + ".\n");
     say(capitalize(TPN) + " shoots at " + capitalize(ob->query_real_name()) + ".\n");
     this_player()->spell_object(ob, "shoot", dam, 0);
     if (ob && !ob->query_attack()) {
        ob->attacked_by(TP);
     }
     return 1;
}
