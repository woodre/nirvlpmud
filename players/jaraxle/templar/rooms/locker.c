/*
 * Shardak guild is (tm) Dragnar/John
 * Change log:
 * 960704 - created
 * 960830 - changed to take who by name and not who the-object as input
 *          added some type checks
 * 2000 - disallows cloned objects from /obj :)
 */
#pragma strict_types
#include "/players/balowski/lib.h"

#define qhp(OB) ((int) OB->query_hp())
#define qmhp(OB) ((int) OB->query_mhp())
#define uhp qhp(this_player())
#define umhp qmhp(this_player())
#define qsp(OB) ((int) OB->query_sp())
#define qmsp(OB) ((int) OB->query_msp())
#define usp qsp(this_player())
#define umsp qmsp(this_player())
#define inwizible(OB) ((int) OB->query_invis() > 18)
#define wizardp(OB) ((int) OB->query_level() >= 20)
#define capname ((string) this_player()->query_name())
#define STORE_PATH "players/jaraxle/templar/rooms/store/"

inherit BASE;
inherit CLEANUP;

static string Name;/* name of person who last accessed this daemon */
mixed *Items;

static void
restore(string nom)
{
    if (!stringp(nom))
      Name = Items = 0;
    else if (nom != Name) {
        Name = nom;
        Items = 0;
        restore_object(STORE_PATH + nom);
    }
}

static void
save(string nom)
{
    if (stringp(Name))
      save_object(STORE_PATH + Name);
}

status
store_item(string nom, object what)
{
    string file, sh;
    mixed args, hits, misses;
    int flag;
    
    if (!stringp(nom) || !objectp(what)) return 0;
    /* save flag: 1 = no save, 2 = only hotel save */
    flag = (int) what->query_save_flag();
    if (flag == 1 || flag == 2) return 0;
    /* root objects I just don't save, cuz I clone em later--no risk :^) */
    if (root(what)) return 0;
    file = basename(what);
    if(file[0..2] == "obj") return 0;  /* disallow cloned obj stuff */
    sh = (string) what->short();
    args = (mixed) what->locker_arg(1);
    hits = (mixed) what->query_hits();
    misses = (mixed)what->query_misses();
    restore(nom);
    
    if (Items)
      Items += ({ sh, file, args, hits, misses, });
    else
      Items = ({ sh, file, args, hits, misses, });
    
    /* save now? */
    save(nom);
    return 1;
}

object
retrieve_item(string nom, string str)
{
    object ob;
    string err;
    int i;
    
    if (!stringp(nom) || !stringp(str)) return 0;
    restore(nom);
    if (!Items || !sizeof(Items)) return 0;
    
    i = atoi(str);
    if (i < 1) return 0;
    i = 5*(i - 1);
    if (i >= sizeof(Items)) return 0;
    
    err = catch(ob = clone_object(Items[i + 1]));
    if (err) {
        if (this_player() && wizardp(this_player()))
          write(err);
        return 0;
    }
    
    ob->locker_init(Items[i + 2]);
    ob->set_hits(Items[i + 3]);
    ob->set_misses(Items[i + 4]);
    Items = deletea(Items, i, i + 4);
    save(nom);

    return ob;
}

string
list_items(string nom)
{
    string tmp;
    int i, j, z;
    
    if (!stringp(nom)) return 0;
    restore(nom);
    if(!Items || !sizeof(Items)) return 0;
    j = 1;
    tmp = "";
    while(i < sizeof(Items)) {
    if (Items[i]) tmp += (j ++) + ".\t" + Items[i] + ".\n";
      i += 5; }
    if (tmp == "") return 0;
    return tmp;
}

int
items_stored(string nom)
{
    if (!stringp(nom)) return 0;
    restore(nom);
    if (!Items) return 0;/* 3.1.2-DR comp */
    return sizeof(Items)/5;
}

status
remove_item(string nom, string str)
{
    int i;
    
    if (!stringp(nom) || !stringp(str)) return 0;
    restore(nom);
    if (!Items) return 0;
    
    i = atoi(str);
    if (i < 1) return 0;
    i = 5*(i - 1);
    if (i >= sizeof(Items)) return 0;
    
    Items = deletea(Items, i, i + 4);
    save(nom);
    return 1;
}
