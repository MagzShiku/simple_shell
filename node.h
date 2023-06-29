#ifndef NODE_H
#define NODE_H

enum node_type_e
{
    NODE_COMMAND,           /* simple command */
    NODE_VAR               /* variable name (or simply, a word) */
};

enum val_type_e
{
    VAL_SINT = 1,       /* signed int */
    VAL_UINT,           /* unsigned int */
    VAL_SLONG,          /* signed long */
    VAL_ULONG,          /* unsigned long */
    VAL_FLOAT,          /* floating point */
    VAL_LDOUBLE,        /* long double */
    VAL_CHR,            /* char */
    VAL_STR             /* str (char pointer) */
};

union symval_u
{
    long               sint;
    unsigned long      uint;
    long               slong;
    unsigned long      ulong;
    double             sfloat;
    long double        ldouble;
    char               chr;
    char*              str;
};

struct node_s
{
    enum node_type_e type;         /* type of this node */
    enum val_type_e  val_type;     /* type of this node's val field */
    union symval_u   val;          /* value of this node */
    int              children;     /* number of child nodes */
    struct node_s*   first_child;  /* first child node */
    struct node_s*   next_sibling; /* next sibling node */
    struct node_s*   prev_sibling; /* previous sibling node */
};

struct node_s* new_node(enum node_type_e type);
void add_child_node(struct node_s* parent, struct node_s* child);
void free_node_tree(struct node_s* node);
void set_node_val_str(struct node_s* node, char* val);

#endif /* NODE_H */
