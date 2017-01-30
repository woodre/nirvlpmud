/*
 * basic/id - Give an id to an object
 *            Rumplemintz
 */

#pragma strict_types

static string *Id;

/* Compatibility */
static string name, alias, alt_name;

/* Prototypes */
void set_id(string *str);
void add_id(string str);
void remove_id(string str);

/* Compatibilty prototypes */
void set_name(string str);
void set_alias(string str);
void set_alt_name(string str);

/* id Parsing */
int id(string str) {
  if (!Id)
    Id = ({ });
  return (member_array(str, Id) >= 0);
}

void set_id(string *str) {
  Id = str;
}

void add_id(string str) {
  Id += ({ str });
}

void remove_id(string str) {
  Id -= ({ str });
}

string* query_Id() {
  return Id;
}

/* Compatibility functions */
void set_name(string str) {
  add_id(str);
  name = str;
}

void set_alias(string str) {
  add_id(str);
  alias = str;
}

void set_alt_name(string str) {
  add_id(str);
  alt_name = str;
}

mixed query_name() {
  if (name)
    return name;
  else return Id[0];
}
