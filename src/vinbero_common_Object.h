#ifndef _VINBERO_COMMON_OBJECT_H
#define _VINBERO_COMMON_OBJECT_H

#include <jansson.h>
#include <string.h>
#include <libgenc/genc_Tree.h>
#include <libgenc/genc_Mtree.h>

enum vinbero_common_Object_Type {
    VINBERO_COMMON_OBJECT_TYPE_NULL,
    VINBERO_COMMON_OBJECT_TYPE_BOOLEAN,
    VINBERO_COMMON_OBJECT_TYPE_INTEGER,
    VINBERO_COMMON_OBJECT_TYPE_REAL,
    VINBERO_COMMON_OBJECT_TYPE_STRING,
    VINBERO_COMMON_OBJECT_TYPE_CONSTRING,
    VINBERO_COMMON_OBJECT_TYPE_ARRAY,
    VINBERO_COMMON_OBJECT_TYPE_MAP
};

struct vinbero_common_Object {
    enum vinbero_common_Object_Type type;
    union {
       bool boolean;
       int integer;
       double real;
       char* string;
       const char* constring;
    };
    GENC_TREE_NODE(struct vinbero_common_Object, struct vinbero_common_Object*);
    GENC_MTREE_NODE(struct vinbero_common_Object, struct vinbero_common_Object*);
};

void vinbero_common_Object_destroy(struct vinbero_common_Object* object);
struct vinbero_common_Object* vinbero_common_Object_fromJson(json_t* json);

#define VINBERO_COMMON_OBJECT_INIT(object, _type) { \
    memset(object, 0, sizeof(struct vinbero_common_Object)); \
    (object)->type = _type; \
    if(VINBERO_COMMON_OBJECT_IS_ARRAY(object)) { \
        GENC_TREE_NODE_INIT(object); \
    } else if(VINBERO_COMMON_OBJECT_IS_MAP(object)) { \
        GENC_MTREE_NODE_INIT(object); \
    } \
}

#define VINBERO_COMMON_OBJECT_TYPE(object) \
(object)->type

#define VINBERO_COMMON_OBJECT_IS_BOOLEAN(object) \
(object)->type == VINBERO_COMMON_OBJECT_TYPE_BOOLEAN

#define VINBERO_COMMON_OBJECT_IS_INTEGER(object) \
(object)->type == VINBERO_COMMON_OBJECT_TYPE_INTEGER

#define VINBERO_COMMON_OBJECT_IS_REAL(object) \
(object)->type == VINBERO_COMMON_OBJECT_TYPE_REAL

#define VINBERO_COMMON_OBJECT_IS_STRING(object) \
(object)->type == VINBERO_COMMON_OBJECT_TYPE_STRING

#define VINBERO_COMMON_OBJECT_IS_CONSTRING(object) \
(object)->type == VINBERO_COMMON_OBJECT_TYPE_CONSTRING

#define VINBERO_COMMON_OBJECT_IS_ARRAY(object) \
(object)->type == VINBERO_COMMON_OBJECT_TYPE_ARRAY

#define VINBERO_COMMON_OBJECT_IS_MAP(object) \
(object)->type == VINBERO_COMMON_OBJECT_TYPE_MAP

#define VINBERO_COMMON_OBJECT_BOOLEAN(object) \
(object)->boolean

#define VINBERO_COMMON_OBJECT_INTEGER(object) \
(object)->integer

#define VINBERO_COMMON_OBJECT_REAL(object) \
(object)->real

#define VINBERO_COMMON_OBJECT_STRING(object) \
(object)->string

#define VINBERO_COMMON_OBJECT_CONSTRING(object) \
(object)->constring

#endif