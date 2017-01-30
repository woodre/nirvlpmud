/* Marble gun - loaded version w/ 30 marbles */
inherit "/obj/weapon.c";
int val;
int left;
int hit;
object attack_ob, ob;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        if(!val) val = 1000;
        attack_ob = this_player()->query_attack();
        if(left == 0) left = 30;
        set_name("gun");
        set_alias("marble gun");
        set_long("A long steel menace. It looks powerful enough to seriously\n"
                +"injure anyone to experience its power. Luckily, you have it.\n");
        set_value(val);
        set_class(13);
        set_weight(6);
        set_hit_func(this_object());        
/* Now for the action */
}
weapon_hit(attacker) {
        if(random(120) <= 10) {
                if(left == 0) {
                        ob = clone_object("/players/wizardchild/objects/mgun.c");
                        move_object(ob, this_player());
                        destruct(this_object());
                        return 1;
                }
                write("You aim your gun at your foe and pull the trigger!\n");
                say(this_player()->query_name()+" shoots the heck outta ");
                say("his foe with a marble gun!\n");
                left -= 1;
                hit = random(15) + 5;
                return hit;
        } else {
                if(random(60) <= 6) {
                        if(left == 0) {
                                ob = clone_object("/players/wizardchild/objects/mgun.c");
                                move_object(ob, this_player());
                                destruct(this_object());
                                return 1;
                        }
                        write("You aim your gun at your foe and pull the trigger!\n");
                        write("The marble shatters under the pressure and get hit\n");
                        write("with flying glass!!\n");
                        say(this_player()->query_name() + "'s marble gun backfires!\n");
                        hit = random(12) + 8;
                        return hit;
                }
        }               
}
id(str) { return str == "gun" || str == "marble gun" || str == "a marble gun ("+left+")"; }
init() {
        left = 30;
        ::init();
}
short() { return "A marble gun ("+left+")"; }
