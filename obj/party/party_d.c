/*
 * Party Daemon
 *
 * This is the master file for the party system, which keeps track of all
 * the parties on the mud, their cumulative exp, age, members, as well as
 * the parties name and leader, the latter of which is usually the first
 * member of the members array. This file, each time the exp array is
 * re-written, a new file of Higheest and Best parties, dependant upon exp
 * gained per unit of time, is written. This way a little competition is
 * encouraged between players.
 */

#define PARTY_OB   "/obj/party/party_ob"
#define PARTY_FILE "/obj/party/party_d"
#define PARTY_SAVE "open/party/party_save"
#define PARTY_BEST "/open/party/party_best"

mixed *party_data;

string *query_all_members(string str);

void reset(status arg) {
  if (arg) return;
  restore_object(PARTY_SAVE);
  if (!party_data || !sizeof(party_data)) {
    party_data = ({
      /* Order is as follows...                             *
       * party name         party members        party exp  *
       *                                         born  rate */
    });
  }
}

void write_best_party();

status query_party(string str) {
  int i;
  string tmp;

  for (i = 0; i < sizeof(party_data); i++) {
    if (party_data[i][0] == str) return 1;
  }
  return 0;
}

status add_party(mixed *arr) {
  int i;

  if (query_party(arr[0])) return 1;
  party_data += ({ arr, });
  save_object(PARTY_SAVE);
  return 1;
}

status remove_party(string str) {
  int i;

  if (!query_party(str)) return 1;
  for (i = 0; i < sizeof(party_data); i++) {
    if (member(party_data[i], str) != -1)
      party_data = party_data[0..(i-1)] +
                   party_data[(i+1)..sizeof(party_data)-1];
  }
  save_object(PARTY_SAVE);
  return 1;
}

mixed *query_party_data() { return party_data; }

string *query_members(string str) {
  return query_all_members(str);
}

string *query_all_members(string party) {
  int i;
  string tmp;

  for (i = 0; i < sizeof(party_data); i++) {
    if (party_data[i][0] == party)
      return party_data[i][1];
  }
}

string query_leader(string party) {
  int i;

  for (i = 0; i < sizeof(party_data); i++) {
    if (party_data[i][0] == party) {
      if (stringp(party_data[i][1][0]))
        return party_data[i][1][0];
      else {
        remove_party(party);
        tell_object(this_player(), "Your party has no leader!\n");
      }
    }
  }
}

int query_age(string party) {
  int i;

  for (i = 0; i < sizeof(party_data); i++) {
    if (party_data[i][0] == party)
      return party_data[i][2];
  }
}

int query_total_exp(string party) {
  int i;

  for (i = 0; i < sizeof(party_data); i++) {
    if (party_data[i][0] == party)
      return party_data[i][3];
  }
}

mixed *best_party() {
  mixed *party;
  string *temp;
  string tmp;
  int i, j;

  party = ({});
  for (i = 0; i < sizeof(party_data); i++) {
    if (party_data[i][2] - time()) {
      j = time() - party_data[i][2];
      party += ({
                 ({
                   party_data[i][0],
                   ((party_data[i][3] * 60) / j),
                 }),
               });
    }
  }
  party = sort_array(party, "by_rate", this_object());
  save_object(PARTY_SAVE);
  return party;
}

status by_rate(mixed *a, mixed *b) {
  return (a[1] < b[1]) ? 1 : 0;
}

void write_best_party() {
  mixed *party;
  string txt, tmp;
  string *temp_party;
  int i;

  party = best_party();

  txt = "_______________________________________________________________\n" +
        ">                    Best Parties on Nirvana                  <\n" +
        "--------------------------------------------------------------<\n" +
        " | Party Name              Members                    Rating | \n";
  for (i = 0; i < sizeof(party); i++) {
    if (party[i][1] && sizeof(query_all_members(party[i][0]))) {
      tmp = " | " + party[i][0] + "                            ";
      tmp = tmp[0..20];
      temp_party = query_all_members(party[i][0]);
      if (sizeof(temp_party)) tmp += capitalize(implode(temp_party, " "));
      tmp += "                                             ";
      tmp = tmp[0..55];
      tmp += party[i][1] + "                                 ";
      tmp = tmp[0..60];
      txt += tmp + "|\n";
    }
  }
  txt += "_______________________________________________________________\n" +
         ">                                                             <\n" +
         "---------------------------------------------------------------\n";
  if (this_player()->valid_write(PARTY_BEST)) {
    rm(PARTY_BEST);
    write_file(PARTY_BEST, txt);
  }
}

status get_party_object(string party, object player) {
  int i;
  object party_ob;

  if (!player) player = this_player();
  if (!party) return 0;
  if (member(query_all_members(party), (string)player->query_name(1)) == -1)
    return 0;
  if (present("party_object", player)) {
    party_ob = present("party_object", player);
    destruct(party_ob);
  }
  party_ob = clone_object(PARTY_OB);
  party_ob->set_age(query_age(party));
  party_ob->set_total_exp(query_total_exp(party));
  party_ob->set_party(party);
  party_ob->set_members(query_all_members(party));
  party_ob->set_leader(query_leader(party));
  party_ob->add_members((string)this_player()->query_name(1));
  move_object(party_ob, player);
  tell_object(player, "\nRestoring '" + party + "' party object...\n\n");
  return 1;
}

