#pragma strong_types

#include <kernel.h>
#include <limits.h>
#include <closures.h>

virtual inherit ACCESS;

private mapping index;
private int *left_offset;
private int *right_offset;
private int fileend;
static private mixed db_priv, db_read_priv, db_set_priv;
static private string db_file;

static mixed query_set_privilege() { return db_set_priv; }
static mixed query_read_privilege() { return db_read_priv; }

private void check_database_for_inconsistencies();

static void load_database(string file,mixed priv,mixed set_priv,
                          mixed read_priv) {
  if (!check_previous_privilege(priv))
    raise_error("Illegal call of load_database()\n");
  set_privilege(priv);
  db_priv = get_privilege(this_object());
  index = 0;
  unguarded(db_priv, #'write_file, ({file+".d", ""}));
  unguarded(db_priv, #'restore_object, ({file}));
  if (!index) {
    index = m_allocate(10, 3);
    left_offset = ({});
    right_offset = ({});
    fileend = 0;
  }
  db_priv = get_privilege(this_object());
  db_read_priv = read_priv;
  db_set_priv = set_priv;
  db_file = file;
  check_database_for_inconsistencies();
}

string query_database_file() {
  return db_file;
}

void save_database() {
  if (!check_previous_privilege(db_priv))
    raise_error("Illegal call of save_database()\n");
  unguarded(db_priv, #'save_object, db_file);
}

void close_database() {
  if (!check_previous_privilege(db_priv))
    raise_error("Illegal call of close_database()\n");
  index = 0;
  left_offset = ({});
  right_offset = ({});
  fileend = 0;
  db_read_priv = 0;
  db_priv = 0;
  db_set_priv = 0;
  db_file = 0;
  set_privilege(0);
}

static void delete(mixed key);

static void store(mixed key,string data,mixed info) {
  int i, size, where;
  if (get_eval_cost() < 5000)
    while (1);
  if (!check_previous_privilege(db_set_priv))
    raise_error("Illegal call of store()\n");
  size = strlen(data);
  delete(key);
  // search for a free block of sufficient size
  for (i=0; i<sizeof(left_offset); i++) {
    if (right_offset[i]-left_offset[i] >= size)
      break;
  }
  // not enough eval-cost => abort
  if (get_eval_cost() < 200)
    for (;;);
  // did we find no big enough free block?
  if (i==sizeof(left_offset)) {
    where = fileend;
    fileend += size;
  }
  else {
    where = left_offset[i];
    // is the free block exactly of the needed size => remove it from
    // the fee block list
    if (right_offset[i]-left_offset[i] == size) {
      left_offset[i..i] = ({});
      right_offset[i..i] = ({});
    }
    else // reduce the found free block in size
      left_offset[i] += size;
  }
  index[key] = where;
  index[key,1] = where + size;
  index[key,2] = info;
  unguarded(db_priv,#'save_object,db_file);
#if 0  // Alfe 1996-Sep-27
  unguarded(db_priv,#'write_bytes,({ db_file+".d", where, data }) );
#else
  while (strlen(data) > MAX_READ) {
    unguarded(db_priv,#'write_bytes,({ db_file+".d", where,
                                       data[0..MAX_READ-1] }) );
    data = data[MAX_READ..];
    where += MAX_READ;
  }
  unguarded(db_priv,#'write_bytes,({ db_file+".d", where, data }) );
#endif
}

static void delete(mixed key) {
  int begin, end, i;
  if (get_eval_cost() < 5000)
    while (1);
  if (!check_previous_privilege(db_set_priv))
    raise_error("Illegal call of delete()\n");
  if (!member(index,key))
    return;
  begin = index[key];
  end = index[key,1];
  m_delete(index, key);
  if (!sizeof(left_offset)) {
    if (get_eval_cost() < 200)
      while (1);
    left_offset = ({begin});
    right_offset = ({end});
    return;
  }
  else {
    if (begin < left_offset[0]) {
      if (end == left_offset[0]) {
        left_offset[0] = begin;
        return;
      }
      left_offset = ({begin}) + left_offset;
      right_offset = ({end}) + right_offset;
      return;
    }
    for (i = 1; i < sizeof(left_offset); i++) {
      if (begin > left_offset[i])
        continue;
      if (begin == right_offset[i-1]) {
        if (end == left_offset[i]) {
          right_offset[i-1] = right_offset[i];
          right_offset = exclude_element(right_offset, i);
          left_offset = exclude_element(left_offset, i);
          return;
        }
        else {
          right_offset[i-1] = end;
          return;
        }
      }
      else {
        if (end == left_offset[i]) {
          left_offset[i] = begin;
          return;
        }
        else {
          left_offset = left_offset[0..i-1] + ({begin}) + left_offset[i..];
          right_offset = right_offset[0..i-1] + ({end}) + right_offset[i..];
          return;
        }
      }
    }
  }
  if (begin == right_offset[<1])
    right_offset[<1] = end;
  else {
    left_offset += ({begin});
    right_offset += ({end});
  }
  if (sizeof(right_offset) && right_offset[<1] == fileend) {
    fileend = left_offset[<1];
    right_offset = right_offset[0..<2];
    left_offset = left_offset[0..<2];
  }
}

static mixed retrieve(string key) {
  string result;
  int begin, size;
  if (!check_previous_privilege(db_read_priv))
    raise_error("Illegal call of retrieve()\n");
  begin = index[key];
  size = index[key,1] - begin;
#if 0  // Alfe 1996-Sep-27
  return unguarded(db_priv, #'read_bytes, ({db_file+".d", begin, size}));
#else
  result = "";
  while (1)
    if (size > MAX_READ) {
      result += unguarded(db_priv, #'read_bytes, ({db_file+".d", begin,
                                                   MAX_READ}));
      begin += MAX_READ;
      size -= MAX_READ;
    }
    else
      return result + unguarded(db_priv, #'read_bytes, ({db_file+".d", begin,
                                                         size}));
#endif
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

static mixed get_info(string key) {
  if (!check_previous_privilege(db_read_priv))
    raise_error("Illegal call of get_info()\n");
  return index[key,2];
}

varargs static void change_info(mixed key, closure changes, mixed extra) {
  mixed info;
  if (!(check_previous_privilege(db_set_priv) && 
        check_previous_privilege(db_read_priv) &&
        index && member(index, key)))
    raise_error("Illegal call of change_info()\n");
  info = get_info(key);
  index[key,2] = apply(changes, info, extra);
  unguarded(db_priv,#'save_database);  // added unguarded Alfe 1996-Sep-29
}

int exists(mixed key) {
  if (!check_previous_privilege(db_read_priv))
    raise_error("Illegal call of exists()\n");
  return member(index,key);
}

static void defragmentate() {
  mixed tmp, info;
  int begin;
  string data;
  // no privilege check because this function should not change anything.
  // while there are free blocks
  if (sizeof(right_offset) && right_offset[<1] == fileend) {
    log_file("DATABASE",(ctime()+": called unnecessary code in defragmentate()"
                         " in " + object_name(this_object()) + " / " +
                         db_file + "\n"));
    fileend = left_offset[<1];
    right_offset = right_offset[0..<2];
    left_offset = left_offset[0..<2];
  }
  while (sizeof(right_offset) && get_eval_cost() > MAX_COST-100000) {
    begin = right_offset[0];
    tmp = m_indices(filter_indices(index,
                                   lambda(({ 'key }),
                                          ({ (#'==),
                                             ({ CL_INDEX,index,'key }),
                                             begin }))));
    if (!sizeof(tmp))  // huh? we have a right offset and no entry for it???
      raise_error("No entry for right offset in database\n");
    if (sizeof(tmp) > 1)  // huh? more than one entry for this right offset???
      raise_error("More than one entry for right offset in database\n");
    data = unguarded(db_priv,#'retrieve,tmp[0]);
    info = unguarded(db_priv,#'get_info,tmp[0]);
    unguarded(db_priv,#'store,({ tmp[0], data, info }));
  }
  if (sizeof(right_offset)) 
    call_out(#'defragmentate,1);  // 0->1, Coogan, 03-Nov-2009
  else {
    unguarded(db_priv,#'truncate_file,({ db_file+".d",fileend }));
    unguarded(db_priv,#'save_database);
  }
}

#define FAKE_MESSAGE ("ERROR: MESSAGE CONTENTS LOST." \
                      "  ERROR: MESSAGE CONTENTS LOST.\n")

private void check_database_for_inconsistencies() {
  int to_be_filled,physical_file_end;
  string fake_message;
  physical_file_end = file_size(db_file+".d");
  if (physical_file_end == -1) {  // does not exist yet?
    unguarded(db_priv,#'write_file,({ db_file+".d","" }));
    physical_file_end = 0;
  }
  else if (physical_file_end == -2) {  // directory?
    db_priv = db_read_priv = db_set_priv = db_file = 0;
    raise_error("Data file is a directory\n");  // do you have a better idea?
  }
  to_be_filled = fileend - physical_file_end;
  if (to_be_filled > MAX_READ)
    fake_message = implode(map(allocate(MAX_READ /
                                              strlen(FAKE_MESSAGE) + 1),
                                     lambda(0,({ #'return,FAKE_MESSAGE }))),
                           "")[0..MAX_READ-2] + "\n";
  while (to_be_filled > MAX_READ) {
    unguarded(db_priv,#'write_bytes,({ db_file+".d",physical_file_end,
                                       fake_message[0..MAX_READ-2] + "\n" }));
    to_be_filled -= MAX_READ;
    physical_file_end += MAX_READ;
  }
  if (to_be_filled > 0) {
    fake_message = (fake_message ||
                    implode(map(allocate(to_be_filled /
                                               strlen(FAKE_MESSAGE) + 1),
                                      lambda(0,({ #'return,FAKE_MESSAGE }))),
                            ""));
    unguarded(db_priv,#'write_bytes,({ db_file+".d",physical_file_end,
                                       (fake_message[0..to_be_filled-2] +
                                        "\n") }));
  }
}
