#include "../defs.h"
#define NAME(x) capitalize(x->query_real_name() || "someone")
#define ROOM(x) tell_room(environment(USER), x)
#define DAM random(25)


object          enemy;  /* Remember who we first cast the spell on */
string          EnemyName;


status id(string str) { return str == "crushspell"; }
status get()   { return 1;}    /* can get */
status drop()  { return 1;}    /* can't drop */

void init() {
  call_out("grip1", 6 );
}

void set_enemy(object ob) {
  enemy = ob;
  EnemyName = (string) enemy->query_name();
  ROOM("Enemy is now: "+EnemyName+".\n");
}

void GRIP1();
void GRIP2();
void GRIP3();

void grip1() {
    string str;
    str = catch(GRIP1());
    if (str && USER) tell_object(USER, str);
    call_out("grip2", 6);
}

void grip2() {
    string str;
    str = catch(GRIP2());
    if (str && USER) tell_object(USER, str);
    call_out("grip3", 6);
}

void grip3() {
    string str;
    str = catch(GRIP3());
    if (str && USER) tell_object(USER, str);
    call_out("end", 5);
}

void end() {
  if(enemy && attack) {
    ROOM(NAME(enemy)+" catches their breath with a large sigh of relief.\n");
  }
  destruct(this_object());
}

void GRIP1() {

  if(!attack || !enemy) {
    enemy = 0;
        end();
        return;
    }
  enemy = (object) attack;
    if (enemy->is_player() && !present("jedi_object", enemy))
        tell_object(USER, "This power cannot effect other players, except Jedi.\n");
    else {
        ROOM(NAME(enemy)+" cluches at "+enemy->query_possessive()+" throat.\n");
        environment()->spell_object(enemy, "crush", DAM, 0);
    }
}

void
GRIP2() {

  if(!attack || !enemy) {
    enemy = 0;
        end();
        return;
    }
    if (enemy->is_player() && !present("jedi_object", enemy))
        tell_object(USER, "This power cannot effect other players, except Jedi.\n");
    else {
        ROOM(NAME(enemy)+" digs at "+enemy->query_possessive()+" throat, trying to get air.\n");
        environment()->spell_object(enemy, "crush", DAM, 0);
    }
}

void
GRIP3() {

  if(!attack || !enemy) {
    enemy = 0;
        end();
        return;
    }
    if (enemy->is_player())
        tell_object(USER, "This power cannot effect other players, except Jedi.\n");
    else {
        ROOM(NAME(enemy)+" falls to the ground, "+enemy->query_possessive()+" face turning blue"+
        " from lack of oxygen.\n");
        environment()->spell_object(enemy, "crush", DAM, 0);
    }
}

int
clean_up(int refcount)
{
    if (refcount)
        return 1;
    destruct(this_object());
}
